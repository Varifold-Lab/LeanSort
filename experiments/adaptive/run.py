#!/usr/bin/env python3
"""Reproducible local loop: collect -> fit -> freeze -> held-out evaluation.
All result directories are new, all observations are flushed as they arrive.
Only explicitly supplied compatible TRAINING logs can be reused.
"""

import argparse
import csv
import datetime
import hashlib
import json
import os
from pathlib import Path
import platform
import select
import subprocess
import sys
import time
import uuid

from audit_codegen import audit
from data import CANDIDATES, FEATURE_NAMES, digest, generate, plan, plan_name, reference_features
from learning import describe, fit, predict
from report import latencies, markdown, summarize

HERE = Path(__file__).resolve().parent
ROOT = HERE.parent.parent


def write_json(path, value):
    with path.open("x") as out:
        json.dump(value, out, indent=2, sort_keys=True)
        out.write("\n")


def read_jsonl(path):
    with path.open() as source:
        return [json.loads(line) for line in source if line.strip()]


def save_dataset(path, rows):
    with path.open("x") as out:
        for row in rows:
            out.write(json.dumps(row, separators=(",", ":")) + "\n")


def command_text(args):
    return subprocess.check_output(args, cwd=ROOT, text=True).strip()


def fingerprint(config):
    paths = sorted(list((ROOT / "LeanSort").rglob("*.lean")) +
                   list(HERE.glob("*.py")) + list(HERE.glob("*.lean")) +
                   [ROOT / "lean-toolchain", ROOT / "lake-manifest.json"])
    hashes = {str(p.relative_to(ROOT)): hashlib.sha256(p.read_bytes()).hexdigest() for p in paths}
    machine = {"platform": platform.platform(), "processor": platform.processor(),
               "machine": platform.machine(), "python": platform.python_version(),
               "hostname": platform.node(), "backend": "lean--run"}
    if sys.platform == "darwin":
        machine["cpu"] = command_text(["sysctl", "-n", "machdep.cpu.brand_string"])
    return {"code_sha256": hashes, "machine": machine,
            "compatibility": digest({"code": hashes, "machine": machine, "config": config})}


class Worker:
    def __init__(self, log_path):
        self.log = log_path.open("x")
        started = time.perf_counter_ns()
        self.process = subprocess.Popen(
            ["lake", "env", "lean", "--run", "experiments/adaptive/Worker.lean"],
            cwd=ROOT, stdin=subprocess.PIPE, stdout=subprocess.PIPE, stderr=self.log,
            text=True, bufsize=1)
        try:
            if not self._read().get("ready"):
                raise RuntimeError("worker did not become ready")
        except BaseException:
            self.close()
            raise
        self.startup_ns = time.perf_counter_ns() - started

    def _read(self):
        if not select.select([self.process.stdout], [], [], 180)[0]:
            raise TimeoutError("Lean worker timed out; partial artifacts are retained")
        line = self.process.stdout.readline()
        if not line:
            raise RuntimeError("Lean worker exited; inspect worker.stderr.log")
        try:
            result = json.loads(line)
        except ValueError as error:
            raise RuntimeError("unexpected Lean worker output: " + line) from error
        if "error" in result:
            raise RuntimeError(result["error"])
        return result

    def request(self, value):
        self.process.stdin.write(json.dumps(value, separators=(",", ":")) + "\n")
        self.process.stdin.flush()
        return self._read()

    def close(self):
        if self.process.poll() is None:
            self.process.stdin.close()
            try:
                self.process.wait(timeout=5)
            except subprocess.TimeoutExpired:
                self.process.terminate()
                self.process.wait(timeout=5)
        self.process.stdout.close()
        self.log.close()


def protocol_checks(worker):
    checks = 0
    leaf = {"schema_version": 1, "feature_names": FEATURE_NAMES,
            "tree": {"kind": "leaf", "plan": plan("hybrid-24")}}
    malformed = [None, {}, {**leaf, "schema_version": 99},
                 {**leaf, "feature_names": list(reversed(FEATURE_NAMES))},
                 {**leaf, "tree": {"kind": "leaf", "plan": {"kind": "bogus"}}},
                 {**leaf, "tree": {"kind": "branch", "feature": 999, "threshold": 2,
                                   "left": leaf["tree"], "right": leaf["tree"]}}]
    for model in malformed:
        response = worker.request({"cmd": "configure", "model": model})
        assert response["fallback"] and not response["accepted"]
        response = worker.request({"cmd": "predict", "input": [3, 1, 2, 1]})
        assert response["fallback"] and response["output"] == [1, 1, 2, 3]
        checks += 1
    assert worker.request({"cmd": "configure", "model": leaf})["accepted"]
    for xs in [[], [0], [2, 1, 2], list(range(40)), list(reversed(range(65))), [7] * 50]:
        response = worker.request({"cmd": "predict", "input": xs})
        assert response["features"] == reference_features(xs)
        assert response["output"] == sorted(xs) and not response["fallback"]
        checks += 1
    nested = {"kind": "split", "cut": 2, "left": plan("insertion"), "right":
              {"kind": "split", "cut": 1, "left": plan("hybrid-8"), "right": plan("merge")}}
    for p in [nested, {**nested, "cut": 0}, {**nested, "cut": 999},
              {"kind": "hybrid", "threshold": 999}, {"kind": "bogus"}]:
        response = worker.request({"cmd": "execute", "plan": p, "input": [4, 2, 3, 2, 0]})
        assert response["output"] == [0, 2, 2, 3, 4]
        checks += 1
    return checks


def collect(worker, dataset, path, config, model=None, model_hash=None):
    rows = []
    with path.open("x") as out:
        for index, case in enumerate(dataset):
            started = time.perf_counter_ns()
            response = worker.request({"cmd": "measure", "stage": case["split"],
                                       "input": case["input"], "expected": sorted(case["input"]),
                                       "rounds": config["rounds"], "inner": config["inner"],
                                       "order_seed": case["seed"]})
            request_ns = time.perf_counter_ns() - started
            assert response["all_outputs_correct"]
            assert response["features"] == reference_features(case["input"])
            if model is not None:
                assert plan_name(response["tree_plan"]) == predict(model, response["features"])
            row = {k: v for k, v in case.items() if k != "input"}
            row.update(response)
            row.update(request_wall_ns=request_ns, frozen_model_sha256=model_hash)
            out.write(json.dumps(row, separators=(",", ":")) + "\n")
            out.flush()
            rows.append(row)
            if (index + 1) % 10 == 0 or index + 1 == len(dataset):
                print(f"{case['split']}: {index + 1}/{len(dataset)} inputs saved", flush=True)
    return rows


def load_history(paths, metadata, config):
    rows = []
    for directory in paths:
        source = Path(directory).resolve()
        previous = json.loads((source / "metadata.json").read_text())
        if previous["compatibility"] != metadata["compatibility"]:
            raise ValueError("incompatible historical costs (code/config/backend/machine): " + str(source))
        inputs = {r["input_sha256"] for r in read_jsonl(source / "dataset-train.jsonl")}
        observations = read_jsonl(source / "observations-train.jsonl")
        for row in observations:
            if row["split"] != "train" or row["length"] not in config["train_lengths"] or row["input_sha256"] not in inputs:
                raise ValueError("invalid training provenance")
        rows.extend(observations)
    return rows


def build_checks(destination):
    commands = [["lake", "build"],
                ["lake", "build", "LeanSort.Verification.HybridMerge.Checks", "LeanSort.Verification.Adaptive.Checks"],
                [sys.executable, "-m", "unittest", "discover", "-s", "experiments/adaptive", "-p", "test_*.py"],
                ["lake", "env", "lean", "-c", str(destination / "Worker.audit.c"), "experiments/adaptive/Worker.lean"]]
    with (destination / "build.log").open("x") as log:
        for command in commands:
            print("check:", " ".join(command), flush=True)
            log.write("$ " + " ".join(command) + "\n")
            log.flush()
            subprocess.run(command, cwd=ROOT, stdout=log, stderr=subprocess.STDOUT, check=True)
        write_json(destination / "codegen-audit.json", audit((destination / "Worker.audit.c").read_text()))
        log.write("$ axiom audit\n")
        log.flush()
        subprocess.run(["lake", "env", "lean", "--stdin"], cwd=ROOT, text=True,
                       input="import LeanSort.Verification.Adaptive.Correctness\n#print axioms LeanSort.Adaptive.Plan.run_spec\n#print axioms LeanSort.Adaptive.selectAndRun_spec\n",
                       stdout=log, stderr=subprocess.STDOUT, check=True)


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--smoke", action="store_true")
    parser.add_argument("--seed", type=int, default=20260906)
    parser.add_argument("--output", type=Path)
    parser.add_argument("--training-from", action="append", default=[], metavar="RUN_DIRECTORY")
    args = parser.parse_args()
    config = json.loads((HERE / "config.json").read_text())
    if args.smoke:
        config.update(train_lengths=[16, 32], test_lengths=[23, 39], train_seeds_per_shape=2,
                      test_seeds_per_shape=1, rounds=2, inner=1, tree_min_leaf=2, bootstrap_resamples=200)
    stamp = datetime.datetime.now(datetime.timezone.utc).strftime("%Y%m%dT%H%M%SZ")
    destination = args.output or HERE / "results" / (stamp + "-" + ("smoke-" if args.smoke else "full-") + uuid.uuid4().hex[:6])
    destination = destination.resolve()
    destination.mkdir(parents=True, exist_ok=False)  # Never overwrite a prior run.
    started = time.perf_counter_ns()
    metadata = fingerprint(config)
    metadata.update(schema_version=1, instrumentation_version=2, created_utc=stamp, config=config, seed=args.seed,
                    smoke=args.smoke, git_commit=command_text(["git", "rev-parse", "HEAD"]),
                    branch=command_text(["git", "branch", "--show-current"]),
                    training_from=[str(Path(p).resolve()) for p in args.training_from])
    write_json(destination / "metadata.json", metadata)  # Protocol frozen before any measurements.
    print("Results:", destination, flush=True)
    history = load_history(args.training_from, metadata, config)
    build_checks(destination)
    worker = Worker(destination / "worker.stderr.log")
    try:
        checks = protocol_checks(worker)
        train = generate(config, "train", args.seed)
        save_dataset(destination / "dataset-train.jsonl", train)
        # Collect/refit twice, demonstrating accumulation without touching test data.
        midpoint = len(train) // 2
        first = collect(worker, train[:midpoint], destination / "observations-train-part1.jsonl", config)
        fit_start = time.perf_counter_ns()
        model1, _, learning1 = fit(history + first, config)
        learning1["fit_ns"] = time.perf_counter_ns() - fit_start
        write_json(destination / "model-round1.json", model1)
        second = collect(worker, train[midpoint:], destination / "observations-train-part2.jsonl", config)
        observed = first + second
        save_dataset(destination / "observations-train.jsonl", observed)
        fit_start = time.perf_counter_ns()
        model, fixed, learning2 = fit(history + observed, config)
        learning2["fit_ns"] = time.perf_counter_ns() - fit_start
        write_json(destination / "learning-curve.json", [learning1, learning2])
        write_json(destination / "model.json", model)
        frozen_hash = hashlib.sha256((destination / "model.json").read_bytes()).hexdigest()
        write_json(destination / "model-frozen.json", {"model_sha256": frozen_hash,
                   "best_fixed": fixed, "frozen_at_ns": time.perf_counter_ns(),
                   "test_observations_so_far": 0})
        print("Frozen best fixed:", fixed, "\n" + describe(model), flush=True)
        load_start = time.perf_counter_ns()
        assert worker.request({"cmd": "configure", "model": model, "best_fixed": plan(fixed)})["accepted"]
        load_ns = time.perf_counter_ns() - load_start
        test = generate(config, "test", args.seed)  # Not generated/inspected until the model is frozen.
        training_hashes = {r["input_sha256"] for r in history + observed}
        assert not training_hashes.intersection(r["input_sha256"] for r in test)
        save_dataset(destination / "dataset-test.jsonl", test)
        evaluated = collect(worker, test, destination / "observations-test.jsonl", config, model, frozen_hash)
        assert frozen_hash == hashlib.sha256((destination / "model.json").read_bytes()).hexdigest()
        summary = summarize(evaluated, fixed, config)
        write_json(destination / "summary.json", summary)
        (destination / "conclusion.md").write_text(markdown(summary, describe(model), args.smoke))
        with (destination / "evaluation.csv").open("x", newline="") as out:
            writer = csv.writer(out)
            writer.writerow(["case_id", "family", "length", "strategy", "median_ns"])
            for row in evaluated:
                for name, ns in latencies(row).items():
                    writer.writerow([row["case_id"], row["family"], row["length"], name, ns])
        write_json(destination / "completed.json", {"all_outputs_correct": True,
                   "protocol_checks": checks, "build_checks_passed": True,
                   "worker_startup_ns": worker.startup_ns, "model_load_roundtrip_ns": load_ns,
                   "experiment_wall_ns": time.perf_counter_ns() - started,
                   "timed_outputs_checked": sum(len(m["samples_ns"]) for r in observed + evaluated for m in r["measurements"]),
                   "training_rows_reused": len(history), "test_leakage_detected": False,
                   "model_sha256_unchanged": frozen_hash})
        print(summary["conclusion"], flush=True)
        print("tree / best fixed:", round(summary["tree_to_best_fixed_ratio"], 3), flush=True)
        print("Report:", destination / "conclusion.md", flush=True)
    finally:
        worker.close()


if __name__ == "__main__":
    main()
