"""Paired, descriptive evaluation. Held-out values are never sent to the fitter."""

import collections
import random
import statistics
from data import CANDIDATES, plan_name


def percentile(xs, fraction):
    ys = sorted(xs)
    pos = fraction * (len(ys) - 1)
    left = int(pos)
    right = min(left + 1, len(ys) - 1)
    return ys[left] + (pos - left) * (ys[right] - ys[left])


def latencies(row):
    result = {m["strategy"]: statistics.median(m["samples_ns"]) for m in row["measurements"]}
    result["oracle"] = min(result[p] for p in CANDIDATES)
    return result


def summarize(rows, best_fixed, config):
    if not rows or any(r["split"] != "test" for r in rows):
        raise ValueError("evaluation requires held-out rows only")
    values = [latencies(r) for r in rows]
    summary = {}
    for name in values[0]:
        ns = [r[name] for r in values]
        summary[name] = {"sum_median_ns": sum(ns), "mean_case_ns": statistics.mean(ns),
                         "median_case_ns": statistics.median(ns), "p90_case_ns": percentile(ns, 0.9)}
    ratio = summary["decision_tree"]["sum_median_ns"] / summary["best_fixed"]["sum_median_ns"]
    # Stratified paired bootstrap over input cases, NOT over repeated timings.
    # Preserves the benchmark's family weights; does not model new machines/runs.
    strata = collections.defaultdict(list)
    for row, costs in zip(rows, values):
        strata[row["family"]].append(costs)
    rng = random.Random(734921)
    ratios = []
    for _ in range(config["bootstrap_resamples"]):
        sample = [rng.choice(group) for group in strata.values() for _ in group]
        ratios.append(sum(x["decision_tree"] for x in sample) / sum(x["best_fixed"] for x in sample))
    ci = [percentile(ratios, 0.025), percentile(ratios, 0.975)]
    if ratio >= 1:
        conclusion = "决策树未超过训练集选出的最佳固定策略；本次端到端点估计更慢。"
    elif ci[1] >= 1:
        conclusion = "决策树点估计更快，但配对区间包含 1，不能据此声称稳定提升。"
    else:
        conclusion = "本次未见数据上决策树更快；这是当前数据混合与运行环境内的证据，不是普遍加速保证。"
    families = {family: {name: sum(v[name] for v in group) for name in values[0]}
                for family, group in sorted(strata.items())}
    wins = collections.Counter(plan_name(r["tree_plan"]) for r in rows)
    oracle_choices = collections.Counter(min(CANDIDATES, key=v.get) for v in values)
    feature_cost = sum(statistics.median(r["feature_samples_ns"]) for r in rows)
    return {"best_fixed_selected_on_train": best_fixed, "test_inputs": len(rows),
            "strategies": summary, "tree_to_best_fixed_ratio": ratio,
            "paired_bootstrap_95pct_ratio": ci, "conclusion": conclusion,
            "families_sum_median_ns": families, "tree_choices": dict(wins),
            "oracle_choices": dict(oracle_choices), "sum_median_feature_ns": feature_cost,
            "tree_extra_vs_plan_only_ns": summary["decision_tree"]["sum_median_ns"] -
                                           summary["tree_plan_only"]["sum_median_ns"],
            "oracle_caveat": "post-hoc minimum among six measured candidates; free choice and selection bias, not executable",
            "uncertainty_caveat": "case bootstrap, not independent machine/session replications; no outliers removed"}


def markdown(summary, model_text, smoke=False):
    s = summary
    lines = ["# Adaptive sorting experiment result", "",
             "SMOKE RUN: checks the pipeline, not a performance conclusion." if smoke else s["conclusion"], "",
             "Training-selected best fixed: `" + s["best_fixed_selected_on_train"] + "`.",
             "Test inputs: " + str(s["test_inputs"]) + ". Times include feature extraction and inference for adaptive policies, sorting, and output consumption.", "",
             "| Strategy | Sum of per-case medians (ms) | Mean per case (µs) | Median per case (µs) | P90 (µs) |",
             "|---|---:|---:|---:|---:|"]
    for name, v in s["strategies"].items():
        lines.append(f"| {name} | {v['sum_median_ns']/1e6:.3f} | {v['mean_case_ns']/1e3:.2f} | {v['median_case_ns']/1e3:.2f} | {v['p90_case_ns']/1e3:.2f} |")
    lo, hi = s["paired_bootstrap_95pct_ratio"]
    lines += ["", f"Primary ratio (tree / best fixed; lower is better): {s['tree_to_best_fixed_ratio']:.3f}; paired case-bootstrap 95% interval [{lo:.3f}, {hi:.3f}].",
              "This is one local session, not evidence across hardware or independent reruns. No timing outliers were removed.", "",
              "`oracle` is a hindsight minimum of candidate medians, with free per-input choice; it is optimistic and not a deployable policy.",
              "`tree_plan_only` runs the tree's selected plan with feature/decision work removed. It is a diagnostic, not a learned end-to-end baseline.", "",
              f"Sum of feature-extraction medians: {s['sum_median_feature_ns']/1e6:.3f} ms. Measured tree minus plan-only: {s['tree_extra_vs_plan_only_ns']/1e6:.3f} ms (includes decision/dispatch and measurement noise).", "",
              "## By input family", "", "| Family | Tree (ms) | Best fixed (ms) | Manual (ms) | Oracle (ms) |", "|---|---:|---:|---:|---:|"]
    for family, v in s["families_sum_median_ns"].items():
        lines.append(f"| {family} | {v['decision_tree']/1e6:.3f} | {v['best_fixed']/1e6:.3f} | {v['manual_rule']/1e6:.3f} | {v['oracle']/1e6:.3f} |")
    lines += ["", "## Frozen decision tree", "", "```text", model_text, "```", "",
              "## Interpretation and limits", "",
              "The tree is fitted from measured training costs, not hand-written labels. Two training snapshots show refitting as observations accumulate; only the final frozen snapshot is evaluated on held-out data.", "",
              "If plan-only improves while end-to-end does not, feature/decision overhead consumes the gain. If plan-only is also poor, training noise, limited features, the restricted candidate set, or the unseen length distribution may contribute. These are hypotheses, not causal diagnoses from one run.", "",
              "The benchmark uses Lean's `--run` backend and the repository's concrete List implementations, including their instrumentation. It does not establish native-code performance, stability, worst-case complexity, or optimality. Startup/model loading and JSON transport are separately recorded, not charged per in-process sort call.", "",
              "Lean proves sortedness and permutation for every typed plan and arbitrary finite lists, including nested splits and rejected-plan merge fallback. Measurements and Python/Lean agreement are finite checks; neither the learner nor benchmark timing is formally verified.", ""]
    return "\n".join(lines)
