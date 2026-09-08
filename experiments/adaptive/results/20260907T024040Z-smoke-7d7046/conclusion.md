# Adaptive sorting experiment result

SMOKE RUN: checks the pipeline, not a performance conclusion.

Training-selected best fixed: `hybrid-24`.
Test inputs: 16. Times include feature extraction and inference for adaptive policies, sorting, and output consumption.

| Strategy | Sum of per-case medians (ms) | Mean per case (µs) | Median per case (µs) | P90 (µs) |
|---|---:|---:|---:|---:|
| merge | 1.312 | 81.98 | 77.39 | 122.69 |
| insertion | 0.759 | 47.44 | 31.77 | 81.83 |
| hybrid-1 | 1.329 | 83.07 | 73.02 | 125.92 |
| hybrid-8 | 0.848 | 53.01 | 42.53 | 89.92 |
| hybrid-24 | 0.657 | 41.09 | 32.18 | 66.01 |
| hybrid-64 | 0.747 | 46.71 | 30.49 | 82.15 |
| best_fixed | 0.666 | 41.61 | 31.24 | 67.46 |
| manual_rule | 0.876 | 54.73 | 43.15 | 84.72 |
| decision_tree | 0.831 | 51.95 | 42.96 | 84.22 |
| tree_plan_only | 0.597 | 37.31 | 31.19 | 66.01 |
| oracle | 0.589 | 36.80 | 30.49 | 65.51 |

Primary ratio (tree / best fixed; lower is better): 1.249; paired case-bootstrap 95% interval [1.212, 1.293].
This is one local session, not evidence across hardware or independent reruns. No timing outliers were removed.

`oracle` is a hindsight minimum of candidate medians, with free per-input choice; it is optimistic and not a deployable policy.
`tree_plan_only` runs the tree's selected plan with feature/decision work removed. It is a diagnostic, not a learned end-to-end baseline.

Sum of feature-extraction medians: 0.007 ms. Measured tree minus plan-only: 0.234 ms (includes decision/dispatch and measurement noise).

## By input family

| Family | Tree (ms) | Best fixed (ms) | Manual (ms) | Oracle (ms) |
|---|---:|---:|---:|---:|
| duplicates | 0.107 | 0.082 | 0.105 | 0.087 |
| nearly_sorted | 0.049 | 0.032 | 0.049 | 0.021 |
| organ_pipe | 0.122 | 0.100 | 0.125 | 0.093 |
| random | 0.140 | 0.091 | 0.121 | 0.092 |
| reverse | 0.128 | 0.146 | 0.186 | 0.098 |
| runs | 0.120 | 0.090 | 0.122 | 0.086 |
| skewed | 0.117 | 0.092 | 0.120 | 0.092 |
| sorted | 0.047 | 0.033 | 0.047 | 0.021 |

## Frozen decision tree

```text
if descent_permille <= 580:
  if prefix_duplicate_permille <= 62:
    return hybrid-64
  else:
    return hybrid-24
else:
  return hybrid-8
```

## Interpretation and limits

The tree is fitted from measured training costs, not hand-written labels. Two training snapshots show refitting as observations accumulate; only the final frozen snapshot is evaluated on held-out data.

If plan-only improves while end-to-end does not, feature/decision overhead consumes the gain. If plan-only is also poor, training noise, limited features, the restricted candidate set, or the unseen length distribution may contribute. These are hypotheses, not causal diagnoses from one run.

The benchmark uses Lean's `--run` backend and the repository's concrete List implementations, including their instrumentation. It does not establish native-code performance, stability, worst-case complexity, or optimality. Startup/model loading and JSON transport are separately recorded, not charged per in-process sort call.

Lean proves sortedness and permutation for every typed plan and arbitrary finite lists, including nested splits and rejected-plan merge fallback. Measurements and Python/Lean agreement are finite checks; neither the learner nor benchmark timing is formally verified.
