# Adaptive sorting experiment result

决策树未超过训练集选出的最佳固定策略；本次端到端点估计更慢。

Training-selected best fixed: `hybrid-24`.
Test inputs: 80. Times include feature extraction and inference for adaptive policies, sorting, and output consumption.

| Strategy | Sum of per-case medians (ms) | Mean per case (µs) | Median per case (µs) | P90 (µs) |
|---|---:|---:|---:|---:|
| merge | 30.308 | 378.85 | 225.58 | 931.82 |
| insertion | 153.283 | 1916.04 | 90.35 | 7812.34 |
| hybrid-1 | 29.784 | 372.30 | 218.46 | 904.98 |
| hybrid-8 | 21.068 | 263.35 | 156.23 | 669.35 |
| hybrid-24 | 19.107 | 238.84 | 149.65 | 676.12 |
| hybrid-64 | 21.297 | 266.21 | 159.23 | 791.49 |
| best_fixed | 19.034 | 237.93 | 149.79 | 670.45 |
| manual_rule | 21.135 | 264.19 | 171.94 | 773.72 |
| decision_tree | 20.743 | 259.29 | 171.52 | 753.48 |
| tree_plan_only | 17.429 | 217.86 | 111.21 | 656.41 |
| oracle | 16.558 | 206.97 | 78.08 | 654.60 |

Primary ratio (tree / best fixed; lower is better): 1.090; paired case-bootstrap 95% interval [1.054, 1.123].
This is one local session, not evidence across hardware or independent reruns. No timing outliers were removed.

`oracle` is a hindsight minimum of candidate medians, with free per-input choice; it is optimistic and not a deployable policy.
`tree_plan_only` runs the tree's selected plan with feature/decision work removed. It is a diagnostic, not a learned end-to-end baseline.

Sum of feature-extraction medians: 0.016 ms. Measured tree minus plan-only: 3.314 ms (includes decision/dispatch and measurement noise).

## By input family

| Family | Tree (ms) | Best fixed (ms) | Manual (ms) | Oracle (ms) |
|---|---:|---:|---:|---:|
| duplicates | 3.135 | 2.730 | 3.135 | 2.711 |
| nearly_sorted | 1.619 | 1.329 | 1.424 | 0.360 |
| organ_pipe | 2.822 | 2.396 | 2.836 | 2.388 |
| random | 3.457 | 3.062 | 3.464 | 3.046 |
| reverse | 2.808 | 2.848 | 3.310 | 2.393 |
| runs | 2.736 | 2.339 | 2.843 | 2.337 |
| skewed | 3.428 | 3.001 | 3.387 | 2.977 |
| sorted | 0.738 | 1.330 | 0.736 | 0.346 |

## Frozen decision tree

```text
if ascending_runs <= 3:
  return insertion
else:
  if descent_permille <= 600:
    return hybrid-24
  else:
    return hybrid-8
```

## Interpretation and limits

The tree is fitted from measured training costs, not hand-written labels. Two training snapshots show refitting as observations accumulate; only the final frozen snapshot is evaluated on held-out data.

If plan-only improves while end-to-end does not, feature/decision overhead consumes the gain. If plan-only is also poor, training noise, limited features, the restricted candidate set, or the unseen length distribution may contribute. These are hypotheses, not causal diagnoses from one run.

The benchmark uses Lean's `--run` backend and the repository's concrete List implementations, including their instrumentation. It does not establish native-code performance, stability, worst-case complexity, or optimality. Startup/model loading and JSON transport are separately recorded, not charged per in-process sort call.

Lean proves sortedness and permutation for every typed plan and arbitrary finite lists, including nested splits and rejected-plan merge fallback. Measurements and Python/Lean agreement are finite checks; neither the learner nor benchmark timing is formally verified.
