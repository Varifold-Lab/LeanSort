# LeanSort

Mathematics of sorting algorithms, formalized in Lean 4.

## Separation of concerns

- `Model/` contains only shared mathematical definitions.
- `Algorithm/` contains only executable sorting definitions.
- `Verification/` contains statements, proofs, checks, cost models, and trace checkers.
- `Verification/Shared/` contains proofs reused by more than one algorithm.

## Mathematical model

```lean
IsSortingResult r input output :=
  output.Pairwise r ∧ output.Perm input
```

Rearrangement traces are words in elementary generators. Merge sort instead records
comparison choices, which are not state-changing moves.

## Algorithms

| Algorithm | Trace |
| --- | --- |
| Insertion sort | adjacent transpositions |
| Bubble sort | adjacent transpositions |
| Selection sort | transpositions |
| Merge sort | comparison choices |
| Pancake sort | prefix reversals |

## Formalized complexity

| Algorithm | Cost model | Result |
| --- | --- | --- |
| Insertion sort | adjacent swaps, worst case | `Θ(n²)` |
| Bubble sort | adjacent swaps, worst case | `Θ(n²)` |
| Selection sort | arbitrary-position swaps | `O(n)` |
| Merge sort | comparisons | `O(n log n)` |
| Pancake sort | prefix reversals | `O(n)` |

Each statement concerns the indicated trace events, not an implicit machine-time model.

## Dependencies

- **mathlib** supplies list/order theory and formal asymptotic notation.
- **CSlib** supplies merge sort, its `TimeM` comparison counter, correctness,
  and the bound `n * Nat.clog 2 n`. Merge's main result and cost use it directly.
- Local proofs cover our additional traces and express the bound as `O(n log n)`.
  The other four algorithms remain local implementations.

The CSlib revision is pinned in `lakefile.toml`. Its merge sort works with
`α : Type` and `LinearOrder α` (including `Nat` and `Int`); our Merge API
uses the same types.

No space-complexity result is claimed. CSlib's Turing-machine space model
does not directly describe allocation in these Lean list implementations.

## Layout

```text
LeanSort/
  Model/                 # shared definitions
  Algorithm/             # Insertion, Bubble, Selection, Merge, Pancake
  Verification/
    Shared/              # shared lemmas
    <Algorithm>/
      Equations.lean     # defining equations
      Checks.lean        # executable examples and regression checks
      Correctness.lean   # sorted output and permutation
      Trace.lean         # trace semantics and agreement with the algorithm
      Cost.lean          # operation counts and concrete bounds
      Complexity.lean    # asymptotic statements
```

## Build

```sh
lake build
```
