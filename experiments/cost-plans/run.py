#!/usr/bin/env python3
"""Search -> emit algorithms/proofs -> Lean check -> freeze -> execute -> report.
Only the standard library and the repository's pinned Lean toolchain are used.
"""
import argparse
import csv
import datetime
import hashlib
import json
import os
from pathlib import Path
import platform
import re
import statistics
import subprocess
import sys
import time
import uuid

from catalogue import enumerate_catalogue, emit_sources, formula, log_weight, premise, ready_depth, shortlist, upper
from data import generate
from reference import evaluate, ready
from audit_codegen import audit

HERE = Path(__file__).resolve().parent
ROOT = HERE.parent.parent


def save(path, obj):
    path.write_text(json.dumps(obj, indent=2, sort_keys=True) + "\n")


def command(args, log, env=None):
    start = time.perf_counter_ns()
    result = subprocess.run(args, cwd=ROOT, env=env, text=True,
                            stdout=subprocess.PIPE, stderr=subprocess.STDOUT)
    log.write_text(result.stdout)
    if result.returncode:
        raise RuntimeError(f"Command failed: {args}; inspect {log}\n{result.stdout[-5000:]}")
    return time.perf_counter_ns() - start


def output(*args):
    return subprocess.check_output(args, cwd=ROOT, text=True).strip()


def source_hashes():
    paths = list((ROOT / "LeanSort").rglob("*.lean"))
    paths += [p for p in HERE.iterdir() if p.suffix in (".py", ".lean", ".md")]
    paths += [ROOT / p for p in ("lean-toolchain", "lakefile.toml", "lake-manifest.json", "LeanSort.lean")]
    return {str(p.relative_to(ROOT)): hashlib.sha256(p.read_bytes()).hexdigest() for p in sorted(paths)}


def audit_axioms(log):
    text = log.read_text()
    if re.search(r"\b(sorryAx|native_decide|Lean\.ofReduceBool)\b", text):
        raise RuntimeError("unacceptable axiom in generated certificates")
    groups = re.findall(r"depends on axioms:\s*\[([^]]*)\]", text)
    if not groups:
        raise RuntimeError("missing axiom audit output")
    allowed = {"propext", "Classical.choice", "Quot.sound"}
    found = set()
    for group in groups:
        found.update(x.strip() for x in group.split(",") if x.strip())
    if not found <= allowed:
        raise RuntimeError(f"unexpected axioms: {found - allowed}")
    return sorted(found)


def catalogue_records(entries):
    records = []
    for entry in entries:
        p, name = entry["plan"], entry["id"]
        prefix = "CostPlanGenerated." + name
        records.append(dict(entry, verified=True, status="proved",
            input_domain="All finite List alpha with a lawful LinearOrder; arbitrary length",
            input_precondition="True", conditional_precondition=prefix + ".Ready xs",
            conditional_precondition_display=premise(p),
            executable=prefix + "_algorithm", lean_cost_formula=prefix + "_costFormula",
            cost_formula_display=formula(p), conditional_formula_display=formula(p, ready=True),
            correctness_theorem=prefix + "_correct", cost_theorem=prefix + "_cost",
            operational_theorem=prefix + "_operational", conditional_theorem=prefix + "_conditional",
            certificate=prefix + "_certificate", quadratic_theorem=prefix + "_quadratic",
            nlog_status="proved" if log_weight(p) is not None else "unknown_by_this_rule",
            nlog_theorem=prefix + "_nlog" if log_weight(p) is not None else None,
            conditional_linear_theorem=prefix + "_conditional_linear" if ready_depth(p) is not None else None,
            conditional_depth=ready_depth(p),
            reference_bounds={str(n): {"unconditional": upper(p, n), "conditional": upper(p, n, True)}
                              for n in (0, 1, 8, 16, 32, 64, 128)},
            proof_file="Generated/Certificates.lean", algorithm_file="Generated/Algorithms.lean"))
    return records


def measure(run_dir, lean_binary, env, selected, plans, cases, rounds):
    start = time.perf_counter_ns()
    stderr = (run_dir / "worker.stderr.log").open("w")
    worker = subprocess.Popen([lean_binary, "--run", str(HERE / "Worker.lean")],
                              cwd=ROOT, env=env, text=True, bufsize=1,
                              stdin=subprocess.PIPE, stdout=subprocess.PIPE, stderr=stderr)
    rows = []
    try:
        line = worker.stdout.readline()
        if not line:
            raise RuntimeError("worker did not start; inspect worker.stderr.log")
        greeting = json.loads(line)
        if not greeting.get("ready"):
            raise RuntimeError(f"worker failed: {greeting}")
        startup_ns = time.perf_counter_ns() - start
        with (run_dir / "observations.jsonl").open("w") as saved:
            for index, case in enumerate(cases):
                request = dict(input=case["input"], expected=case["expected"],
                               strategies=selected, rounds=rounds, order_seed=index)
                worker.stdin.write(json.dumps(request) + "\n")
                worker.stdin.flush()
                response = json.loads(worker.stdout.readline())
                if "error" in response or not response.get("all_outputs_correct"):
                    raise RuntimeError(f"worker rejected {case['id']}: {response}")
                saved.write(json.dumps(dict(case_id=case["id"], response=response)) + "\n")
                saved.flush()
                profiles = {p["profile"]["strategy"]: p for p in response["profiles"]}
                for measured in response["measurements"]:
                    pr = profiles[measured["strategy"]]
                    p = plans[measured["strategy"]]
                    expected_output, expected_checks, expected_sorting = evaluate(p, case["input"])
                    record = pr["profile"]
                    if (expected_output != case["expected"] or record["check_comparisons"] != expected_checks
                            or record["sorting_comparisons"] != expected_sorting
                            or record["upper"] != upper(p, len(case["input"]))
                            or record["conditional_upper"] != upper(p, len(case["input"]), True)
                            or record["ready"] != ready(p, case["input"])):
                        raise RuntimeError("Lean/Python independent semantics regression mismatch")
                    rows.append(dict(case_id=case["id"], shape=case["shape"], n=len(case["input"]),
                        **pr["profile"], offline_profile_ns=pr["offline_profile_ns"],
                        median_e2e_ns=statistics.median(measured["e2e_samples_ns"]),
                        min_e2e_ns=min(measured["e2e_samples_ns"]),
                        max_e2e_ns=max(measured["e2e_samples_ns"]),
                        median_check_replay_ns=statistics.median(measured["check_replay_samples_ns"])))
                print(f"evaluated {index+1}/{len(cases)}: {case['id']}", flush=True)
        worker.stdin.close()
        if worker.wait(timeout=30):
            raise RuntimeError("worker terminated with failure")
        return rows, startup_ns, time.perf_counter_ns() - start
    finally:
        if worker.poll() is None:
            worker.terminate()
            worker.wait(timeout=30)
        stderr.close()


def write_report(run_dir, entries, baselines, selected, rows, phases, axioms):
    with (run_dir / "evaluation.csv").open("w", newline="") as f:
        w = csv.DictWriter(f, fieldnames=list(rows[0]))
        w.writeheader()
        w.writerows(rows)
    by_key = {(r["case_id"], r["strategy"]): r for r in rows}
    aggregates = []
    for name in selected:
        rs = [r for r in rows if r["strategy"] == name]
        aggregates.append(dict(strategy=name, cases=len(rs),
            comparisons=sum(r["comparisons"] for r in rs), checks=sum(r["check_comparisons"] for r in rs),
            sum_case_median_e2e_ns=sum(r["median_e2e_ns"] for r in rs),
            ready_cases=sum(r["ready"] for r in rs)))
    contrasts = []
    for name in selected:
        if name.startswith("single_"):
            continue
        for baseline in (b["id"] for b in baselines):
            for domain in ("all", "ready"):
                rs = [r for r in rows if r["strategy"] == name and (domain == "all" or r["ready"])]
                bs = [by_key[(r["case_id"], baseline)] for r in rs]
                contrasts.append(dict(strategy=name, baseline=baseline, domain=domain, cases=len(rs),
                    smaller_proved_envelope_cases=sum((r["conditional_upper"] if domain == "ready" else r["upper"]) < b["upper"] for r, b in zip(rs, bs)),
                    fewer_actual_comparison_cases=sum(r["comparisons"] < b["comparisons"] for r, b in zip(rs, bs)),
                    lower_median_time_cases=sum(r["median_e2e_ns"] < b["median_e2e_ns"] for r, b in zip(rs, bs)),
                    sum_actual_comparisons=sum(r["comparisons"] for r in rs),
                    baseline_sum_actual_comparisons=sum(b["comparisons"] for b in bs),
                    sum_case_median_e2e_ns=sum(r["median_e2e_ns"] for r in rs),
                    baseline_sum_case_median_e2e_ns=sum(b["median_e2e_ns"] for b in bs)))
    with (run_dir / "contrasts.csv").open("w", newline="") as f:
        w = csv.DictWriter(f, fieldnames=list(contrasts[0]))
        w.writeheader()
        w.writerows(contrasts)
    summary = dict(composite_certificates=len(entries), baseline_certificates=len(baselines),
        structurally_unique=len({e["structural_sha256"] for e in entries}),
        unconditional_nlog_composites=sum(log_weight(e["plan"]) is not None for e in entries),
        conditional_linear_composites=sum(ready_depth(e["plan"]) is not None for e in entries),
        measured_algorithms=len(selected), cases=len({r["case_id"] for r in rows}),
        all_outputs_checked=True, phases_ns=phases, axioms=axioms,
        aggregates=aggregates, comparison_model="key comparisons, including runtime guards",
        conclusion_scope="No pointwise cost dominance, optimality, or native-machine speedup claim.")
    save(run_dir / "summary.json", summary)
    lines = ["# Certified cost-plan experiment", "",
        f"Lean checked {len(entries)} structurally distinct composites and {len(baselines)} single-algorithm baselines, each for arbitrary finite lists over a linear order.",
        f"The structural n-log-n rule covers {summary['unconditional_nlog_composites']} composites; the conditional linear rule covers {summary['conditional_linear_composites']}.",
        f"Only the offline-frozen shortlist ({len(selected)} algorithms) was measured on {summary['cases']} inputs. All outputs and cost inequalities passed finite regression checks.", "",
        "## Three different claims", "",
        "- Proved: for n >= 8, two insertion-sorted halves have a smaller sufficient comparison envelope than insertion on the whole list.",
        "- Proved: if both halves are sorted, two guarded halves have a smaller envelope than the general merge-sort envelope for n >= 8. Guards are charged; fixed block depth gives O(n). This compares available envelopes, not tight worst-case costs under the same restricted domain.",
        "- Proved counterexample: on range(8), the envelopes are 20 < 28 but actual comparisons are 10 > 7. Hence envelope ordering alone does not imply pointwise dominance.",
        "- Proved no novelty: merge-halves executes the same comparison program as merge-sort for lengths >= 2. Structural deduplication does not remove all semantic duplicates.", "",
        "## Descriptive measurements (same inputs, same interpreter)", "",
        "| Algorithm | Total comparisons | Guard comparisons | Sum of per-input median time (ms) |",
        "|---|---:|---:|---:|"]
    for a in aggregates:
        lines.append(f"| {a['strategy']} | {a['comparisons']} | {a['checks']} | {a['sum_case_median_e2e_ns']/1e6:.3f} |")
    lines += ["", "Raw repetitions are in observations.jsonl; per-case comparisons and guard applicability are in evaluation.csv. contrasts.csv separates envelope, operation-count and time comparisons, on identical inputs for each pair.", "",
        "The conditional column is applicable only where ready=true. The baseline is evaluated on those same inputs, but its displayed envelope remains a general-input bound; no tight lower bound for that restricted domain was proved.", "",
        "## Accounting and limitations", "",
        "The uniform unit is one key <= comparison, tagged as sorting or runtime checking. Split traversal, allocation, length arithmetic, interpreter overhead and output consumption are outside that operation count but inside measured deployment time.",
        "End-to-end timing starts from an in-memory input list, includes schema interpretation/splitting/guards/sorting and forced output consumption. Dataset generation, JSON transport, offline proof work and post-timing output equality checks are excluded. No model inference is deployed in this phase.",
        "check_replay timing is an isolated replay of the same guard comparisons, proved to have the same check count. It is NOT an additive wall-time decomposition and is not added again to end-to-end time. Offline profiling executes extra diagnostics and is logged separately.",
        "Backend: lean --run, with the same comparison-program interpreter for singles and composites. These timings describe this research representation, not an optimized/native sorting implementation. Repetition medians are descriptive; there is no significance, universal speedup or hardware-independent performance claim.",
        "The generator enumerates a finite schema grammar and instantiates previously proved structural rules; it neither discovers new theorems nor claims globally optimal synthesis. The general certificate covers every finite schema in the grammar, beyond these 100 examples; it does not cover arbitrary Lean programs.",
        "Thresholds and schema depth are fixed in the n-log-n/linear theorems. Concrete formulas expose their parameters. Allowing those parameters to grow with n requires using the parameter-dependent bound, not silently reusing the fixed-parameter asymptotic theorem.",
        "Previous adaptive decision-tree data and its negative result are preserved unchanged. This experiment does not retrain or tune on those data.", "",
        "## Separately recorded offline costs", ""]
    lines += [f"- {k}: {v / 1e9:.6f} s" for k, v in phases.items()]
    (run_dir / "conclusion.md").write_text("\n".join(lines) + "\n")
    return summary


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument("--smoke", action="store_true", help="smaller input suite; still certify all 100 composites")
    parser.add_argument("--rounds", type=int, default=5)
    args = parser.parse_args()
    if not 1 <= args.rounds <= 21:
        parser.error("rounds must be in [1,21]")
    stamp = datetime.datetime.now(datetime.timezone.utc).strftime("%Y%m%dT%H%M%SZ")
    run_dir = HERE / "results" / (stamp + ("-smoke-" if args.smoke else "-full-") + uuid.uuid4().hex[:6])
    run_dir.mkdir(parents=True)
    print(f"results={run_dir.relative_to(ROOT)}", flush=True)
    phases, sources = {}, source_hashes()
    save(run_dir / "source-hashes.json", sources)
    metadata = dict(branch=output("git", "branch", "--show-current"), head=output("git", "rev-parse", "HEAD"),
        main=output("git", "rev-parse", "main"), platform=platform.platform(), python=sys.version,
        lean=output("lake", "env", "lean", "--version"), cpu=platform.processor(),
        smoke=args.smoke, rounds=args.rounds, reference_n=64,
        selection="first 8 named mathematical examples plus top 5 unconditional envelopes at n=64; structural dedup; before execution",
        phase1_preserved="experiments/adaptive/results/20260907T024833Z-full-b5f2e8")
    save(run_dir / "metadata.json", metadata)
    phases["python_regression_tests"] = command([sys.executable, "-m", "unittest", "discover", "-s", str(HERE), "-p", "test_*.py", "-v"], run_dir / "python-tests.log")
    print("checking existing build and general structural proofs", flush=True)
    phases["existing_lake_build"] = command(["lake", "build"], run_dir / "build.log")
    phases["general_proof_build"] = command(["lake", "build", "LeanSort.Verification.CostedPlan.Examples", "LeanSort.Verification.Adaptive.Correctness"], run_dir / "proof-build.log")
    start = time.perf_counter_ns()
    entries, baselines = enumerate_catalogue()
    selected = [e["id"] for e in baselines] + shortlist(entries)
    phases["offline_search_and_selection"] = time.perf_counter_ns() - start
    save(run_dir / "shortlist-frozen.json", dict(strategies=selected, reference_n=64,
         criteria=metadata["selection"], frozen_before_any_candidate_execution=True))
    start = time.perf_counter_ns()
    emit_sources(entries + baselines, run_dir / "Generated")
    phases["algorithm_and_proof_source_generation"] = time.perf_counter_ns() - start
    env = os.environ.copy()
    env["LEAN_PATH"] = str(run_dir) + os.pathsep + output("lake", "env", "printenv", "LEAN_PATH")
    lean_binary = output("lake", "env", "which", "lean")
    print("checking 105 parameterized algorithm/cost certificates", flush=True)
    for module in ("Algorithms", "Certificates"):
        source = run_dir / "Generated" / (module + ".lean")
        phases["lean_check_" + module.lower()] = command([lean_binary, "-R", str(run_dir), "-o", str(source.with_suffix(".olean")), str(source)], run_dir / (module.lower() + ".log"), env)
    axioms = audit_axioms(run_dir / "certificates.log")
    # Only publish the proved status after the whole generated file passed.
    save(run_dir / "catalogue.json", catalogue_records(entries + baselines))
    phases["worker_typecheck_and_codegen"] = command([lean_binary, "-c", str(run_dir / "Worker.audit.c"), str(HERE / "Worker.lean")], run_dir / "worker-check.log", env)
    save(run_dir / "codegen-audit.json", audit((run_dir / "Worker.audit.c").read_text()))
    cases = generate(args.smoke)
    with (run_dir / "dataset.jsonl").open("w") as f:
        for case in cases:
            f.write(json.dumps(case) + "\n")
    rows, startup, elapsed = measure(run_dir, lean_binary, env, selected, {e['id']: e['plan'] for e in entries + baselines}, cases, args.rounds)
    phases["worker_startup"] = startup
    phases["evaluation_wall_including_transport_and_diagnostics"] = elapsed
    phases["offline_profile_diagnostics"] = sum(r["offline_profile_ns"] for r in rows)
    if sources != source_hashes() or metadata["main"] != output("git", "rev-parse", "main"):
        raise RuntimeError("source/main changed during experiment; run is not reproducibly frozen")
    summary = write_report(run_dir, entries, baselines, selected, rows, phases, axioms)
    save(run_dir / "completed.json", dict(success=True, source_hashes_unchanged=True,
        main_unchanged=True, all_certificates_checked=True, all_outputs_checked=True))
    print(json.dumps({k: v for k, v in summary.items() if k != "aggregates"}, indent=2), flush=True)
    print(f"report={run_dir / 'conclusion.md'}", flush=True)


if __name__ == "__main__":
    main()
