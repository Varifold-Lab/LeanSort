# Adaptive sorting experiment result

决策树未超过训练集选出的最佳固定策略；本次端到端点估计更慢。

Training-selected best fixed: `hybrid-24`.
Test inputs: 80. Times include feature extraction and inference for adaptive policies, sorting, and output consumption.

| Strategy | Sum of per-case medians (ms) | Mean per case (µs) | Median per case (µs) | P90 (µs) |
|---|---:|---:|---:|---:|
| merge | 30.569 | 382.12 | 224.48 | 936.73 |
| insertion | 162.050 | 2025.63 | 88.10 | 8411.22 |
| hybrid-1 | 30.117 | 376.46 | 215.44 | 917.56 |
| hybrid-8 | 21.063 | 263.28 | 152.54 | 662.93 |
| hybrid-24 | 19.137 | 239.21 | 149.33 | 687.33 |
| hybrid-64 | 21.092 | 263.65 | 150.67 | 755.81 |
| best_fixed | 19.003 | 237.54 | 143.85 | 682.62 |
| manual_rule | 21.032 | 262.90 | 170.04 | 799.74 |
| decision_tree | 20.528 | 256.60 | 123.31 | 758.13 |
| tree_plan_only | 17.193 | 214.91 | 79.98 | 655.20 |
| oracle | 16.480 | 206.00 | 79.04 | 650.23 |

Primary ratio (tree / best fixed; lower is better): 1.080; paired case-bootstrap 95% interval [1.037, 1.116].
This is one local session, not evidence across hardware or independent reruns. No timing outliers were removed.

`oracle` is a hindsight minimum of candidate medians, with free per-input choice; it is optimistic and not a deployable policy.
`tree_plan_only` runs the tree's selected plan with feature/decision work removed. It is a diagnostic, not a learned end-to-end baseline.

Sum of feature-extraction medians: 3.044 ms. Measured tree minus plan-only: 3.335 ms (includes decision/dispatch and measurement noise).

## By input family

| Family | Tree (ms) | Best fixed (ms) | Manual (ms) | Oracle (ms) |
|---|---:|---:|---:|---:|
| duplicates | 2.898 | 2.446 | 2.858 | 2.489 |
| nearly_sorted | 1.386 | 1.365 | 1.437 | 0.359 |
| organ_pipe | 2.811 | 2.438 | 2.799 | 2.380 |
| random | 3.532 | 3.075 | 3.534 | 3.071 |
| reverse | 2.819 | 2.866 | 3.303 | 2.360 |
| runs | 2.883 | 2.462 | 2.932 | 2.447 |
| skewed | 3.449 | 2.985 | 3.418 | 3.019 |
| sorted | 0.750 | 1.366 | 0.750 | 0.356 |

## Frozen decision tree

```text
if ascending_runs <= 5:
  if descent_permille <= 32:
    return insertion
  else:
    return hybrid-24
else:
  if descent_permille <= 548:
    return hybrid-24
  else:
    return hybrid-8
```

## Interpretation and limits

The tree is fitted from measured training costs, not hand-written labels. Two training snapshots show refitting as observations accumulate; only the final frozen snapshot is evaluated on held-out data.

If plan-only improves while end-to-end does not, feature/decision overhead consumes the gain. If plan-only is also poor, training noise, limited features, the restricted candidate set, or the unseen length distribution may contribute. These are hypotheses, not causal diagnoses from one run.

The benchmark uses Lean's `--run` backend and the repository's concrete List implementations, including their instrumentation. It does not establish native-code performance, stability, worst-case complexity, or optimality. Startup/model loading and JSON transport are separately recorded, not charged per in-process sort call.

Lean proves sortedness and permutation for every typed plan and arbitrary finite lists, including nested splits and rejected-plan merge fallback. Measurements and Python/Lean agreement are finite checks; neither the learner nor benchmark timing is formally verified.
