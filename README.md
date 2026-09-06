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

Ten implemented algorithms; the table distinguishes full and partial verification.

| Algorithm | Sorting correctness | Trace |
| --- | --- | --- |
| Insertion sort | proved | adjacent transpositions |
| Bubble sort | proved | adjacent transpositions |
| Selection sort | proved | transpositions |
| Merge sort | proved | comparison choices |
| Pancake sort | proved | prefix reversals |
| Quick sort | proved | not instrumented |
| Heap sort | regression checks only | not instrumented |
| Shell sort | permutation proved; sortedness pending | not instrumented |
| Counting sort | sortedness proved; permutation pending | not instrumented |
| Radix sort | permutation proved; sortedness pending | not instrumented |

Quick sort uses a deterministic first pivot and a single partition pass.
Heap sort reuses Batteries' array-backed binary heap, with a separate output
array. Its sortedness and permutation proofs remain to be added.
Quick and heap sort have edge-case checks and exhaustive checks of the
243 length-five lists over `{0, 1, 2}`.

Shell sort uses halving gaps and gapped insertion on arrays. Counting sort
uses a histogram; radix sort uses stable binary digit passes from least to
most significant. Counting and radix sort currently accept natural-number
keys only. Counting sort allocates space proportional to the maximum key,
so it is intended for small key ranges.

Shell, counting, and radix sort each have edge-case checks and exhaustive
checks of all 364 lists of length at most five over `{0, 1, 2}`.
These checks supplement, but do not replace, the missing universal proofs.

## Formalized complexity

| Algorithm | Cost model | Result |
| --- | --- | --- |
| Insertion sort | adjacent swaps, worst case | `Θ(n²)` |
| Bubble sort | adjacent swaps, worst case | `Θ(n²)` |
| Selection sort | arbitrary-position swaps | `O(n)` |
| Merge sort | comparisons | `O(n log n)` |
| Pancake sort | prefix reversals | `O(n)` |

Each statement concerns the indicated trace events, not an implicit machine-time model.
Quick, heap, shell, counting, and radix sort do not yet have formalized cost
or complexity results.

## Dependencies

- **mathlib** supplies list/order theory and formal asymptotic notation.
- **CSlib** supplies merge sort, its `TimeM` comparison counter, correctness,
  and the bound `n * Nat.clog 2 n`. Merge's main result and cost use it directly.
- **Batteries** supplies binary heap sort through the existing dependency graph.
- Local proofs cover our additional traces and express Merge's bound as `O(n log n)`.
  Insertion, bubble, selection, pancake, quick, shell, counting, and radix sort
  remain local implementations.

The CSlib revision is pinned in `lakefile.toml`. Its merge sort works with
`α : Type` and `LinearOrder α` (including `Nat` and `Int`); our Merge and
Heap APIs use those types. Counting and radix sort use `Nat`; the remaining
algorithms accept `α : Type*` with `LinearOrder α`.

No space-complexity result is claimed. CSlib's Turing-machine space model
does not directly describe allocation in these Lean list implementations.

## Layout

```text
LeanSort/
  Model/                 # shared definitions
  Algorithm/             # one file per sorting algorithm
  Verification/
    Shared/              # shared lemmas
    <Algorithm>/
      Equations.lean     # defining equations
      Checks.lean        # executable examples and regression checks
      Correctness.lean   # full sorting specification
      Sortedness.lean    # output order, when proved separately
      Permutation.lean   # preservation of elements and multiplicities
      Trace.lean         # trace semantics and agreement with the algorithm
      Cost.lean          # operation counts and concrete bounds
      Complexity.lean    # asymptotic statements
```

Only files with implemented content are present; the layout above lists the
available verification categories, not mandatory empty placeholders.

## Build

```sh
lake build
```
