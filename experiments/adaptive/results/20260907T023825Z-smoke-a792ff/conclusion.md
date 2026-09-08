# Adaptive sorting experiment result

SMOKE RUN: checks the pipeline, not a performance conclusion.

Training-selected best fixed: `hybrid-24`.
Test inputs: 16. Times include feature extraction and inference for adaptive policies, sorting, and output consumption.

| Strategy | Sum of per-case medians (ms) | Mean per case (µs) | Median per case (µs) | P90 (µs) |
|---|---:|---:|---:|---:|
| merge | 1.342 | 83.89 | 75.47 | 126.50 |
| insertion | 0.832 | 51.99 | 32.73 | 100.10 |
| hybrid-1 | 1.336 | 83.53 | 78.66 | 119.86 |
| hybrid-8 | 0.848 | 53.00 | 45.74 | 86.04 |
| hybrid-24 | 0.697 | 43.56 | 34.29 | 72.12 |
| hybrid-64 | 0.827 | 51.68 | 33.10 | 95.46 |
| best_fixed | 0.714 | 44.65 | 33.18 | 78.59 |
| manual_rule | 0.901 | 56.33 | 44.58 | 90.01 |
| decision_tree | 0.864 | 54.03 | 43.18 | 87.29 |
| tree_plan_only | 0.619 | 38.69 | 30.74 | 68.20 |
| oracle | 0.623 | 38.92 | 32.40 | 69.78 |

Primary ratio (tree / best fixed; lower is better): 1.210; paired case-bootstrap 95% interval [1.174, 1.259].
This is one local session, not evidence across hardware or independent reruns. No timing outliers were removed.

`oracle` is a hindsight minimum of candidate medians, with free per-input choice; it is optimistic and not a deployable policy.
`tree_plan_only` runs the tree's selected plan with feature/decision work removed. It is a diagnostic, not a learned end-to-end baseline.

Sum of feature-extraction medians: 0.006 ms. Measured tree minus plan-only: 0.245 ms (includes decision/dispatch and measurement noise).

## By input family

| Family | Tree (ms) | Best fixed (ms) | Manual (ms) | Oracle (ms) |
|---|---:|---:|---:|---:|
| duplicates | 0.125 | 0.094 | 0.119 | 0.094 |
| nearly_sorted | 0.050 | 0.035 | 0.051 | 0.022 |
| organ_pipe | 0.129 | 0.098 | 0.124 | 0.100 |
| random | 0.132 | 0.103 | 0.131 | 0.104 |
| reverse | 0.123 | 0.148 | 0.173 | 0.098 |
| runs | 0.113 | 0.086 | 0.113 | 0.080 |
| skewed | 0.139 | 0.118 | 0.136 | 0.105 |
| sorted | 0.054 | 0.034 | 0.054 | 0.021 |

## Frozen decision tree

```text
if ascending_runs <= 15:
  if prefix_duplicate_permille <= 62:
    return hybrid-64
  else:
    return hybrid-24
else:
  if descent_permille <= 580:
    return hybrid-24
  else:
    return hybrid-8
```

## Interpretation and limits

The tree is fitted from measured training costs, not hand-written labels. Two training snapshots show refitting as observations accumulate; only the final frozen snapshot is evaluated on held-out data.

If plan-only improves while end-to-end does not, feature/decision overhead consumes the gain. If plan-only is also poor, training noise, limited features, the restricted candidate set, or the unseen length distribution may contribute. These are hypotheses, not causal diagnoses from one run.

The benchmark uses Lean's `--run` backend and the repository's concrete List implementations, including their instrumentation. It does not establish native-code performance, stability, worst-case complexity, or optimality. Startup/model loading and JSON transport are separately recorded, not charged per in-process sort call.

Lean proves sortedness and permutation for every typed plan and arbitrary finite lists, including nested splits and rejected-plan merge fallback. Measurements and Python/Lean agreement are finite checks; neither the learner nor benchmark timing is formally verified.
