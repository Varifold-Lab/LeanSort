# Hybrid threshold experiment

A small, opt-in experiment on arbitrary finite `List α`: split and recursively
merge large subproblems, use insertion sort below a tunable threshold. Threshold
zero means one. This branch adds files without changing existing algorithms,
dependencies, root imports, or the default build.

From the repository root:

```sh
lake build LeanSort.Verification.HybridMerge.Checks
lake env lean --run experiments/hybrid-threshold/Main.lean --smoke
lake env lean --run experiments/hybrid-threshold/Main.lean
```

## What is proved

[`sort_spec`](../../LeanSort/Verification/HybridMerge/Correctness.lean) proves
sortedness and permutation for every threshold and every finite list over a
linear order. It composes the existing insertion correctness theorem, recursive
subproblem proofs, and CSlib's merge theorems. Lean checks termination as well.
`selected_sort_spec` also covers any total, input-dependent threshold selector.
Neither theorem assumes that the selector makes good performance predictions.

Stability, trace consistency, comparisons, allocations, and asymptotic costs of
this new hybrid have **not** yet been proved. Existing component cost theorems do
not automatically establish costs for their composition.

## What is measured

The executable tests thresholds `1, 8, 24, 64` on sorted, reverse, nearly sorted,
two-run, pseudorandom, and duplicate-heavy lists. It selects one global threshold
by the median duration of the whole training batch. Existing merge and insertion
implementations are fixed baselines, not threshold candidates.

Training uses lengths 32 and 96 with seeds 17 and 29; held-out evaluation uses
lengths 48 and 128 with seeds 41 and 53. The selected threshold is frozen before
held-out measurements. This is a small controlled split, not evidence of
generalization to arbitrary distributions. Smoke mode uses smaller lengths and
one timing round; it checks the harness, not performance.

Normal mode warms up each candidate, alternates order, and reports median/min/max
batch nanoseconds across five rounds. Data generation and output validation are
outside timing; traversal/checksum of every output and IO overhead are inside.
Measurements describe these concrete implementations under `lean --run`,
including existing insertion trace and merge cost instrumentation. They are not
native-code benchmarks or comparisons of abstract algorithms independent of
implementation. Noise or overhead can outweigh any threshold effect; there is no
promised speedup, statistical significance, or global optimality.

## Scope and checks

This is a **manually proved algorithm composition plus offline parameter tuning**,
not genuine synthesis, automated property discovery, or a learned per-input
selector. No UI, service, model framework, output files, or new dependencies.

[`Checks.lean`](../../LeanSort/Verification/HybridMerge/Checks.lean) covers empty,
singleton, odd/even length, negative and duplicate values, and thresholds at zero
and beyond input length. It also enumerates all 364 lists of length 0–5 over
`{0,1,2}` at five thresholds. These and the executable's output comparisons are
finite checks, distinct from the universal proof. Run `lake build` separately to
check the unchanged default library; it does not import this opt-in experiment.

Before learning a data-dependent policy, the next mathematical step is to define
the hybrid's measured operational cost and prove how split, recursive calls,
insertion, and merge costs compose. Any claimed worst-case bound must also account for the allowed thresholds and the selector's own work.
