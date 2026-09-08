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
| Heap sort | permutation proved; sortedness pending | root extractions; checked replay |
| Shell sort | proved | gapped transpositions |
| Counting sort | proved | histogram updates; checked replay |
| Radix sort | proved | binary partition choices |

Quick sort uses a deterministic first pivot and a single partition pass.
Heap sort reuses Batteries' array-backed binary heap, with a separate output
array. Its permutation theorem proves preservation of elements and their
multiplicities; length and membership preservation follow directly. The proof
covers sifting, heap construction, root removal, and the extraction loop.
Sortedness remains to be proved: the heap-order invariant and its preservation
are not yet formalized.
Heap's optional trace records each extracted value and the remaining heap size.
Its output is proved equal to Batteries' output; replay accepts exactly the
complete generated trace, rejecting missing, extra, or altered steps. Replay
re-executes heap operations and does not independently certify sortedness.
Quick and heap sort have edge-case checks and exhaustive checks of the
243 length-five lists over `{0, 1, 2}`.
Heap additionally checks traced execution, replay, and extraction cost on all
364 lists of length at most five over the same alphabet.

Shell sort uses halving gaps and gapped insertion on arrays. Counting sort
uses a histogram; radix sort uses stable binary digit passes from least to
most significant. Counting and radix sort currently accept natural-number
keys only. Counting sort allocates space proportional to the maximum key,
so it is intended for small key ranges.

Shell, counting, and radix sort each have edge-case checks and exhaustive
checks of all 364 lists of length at most five over `{0, 1, 2}`.
Shell, Counting, and Radix have full sortedness and permutation proofs.
Their exhaustive checks supplement these universal proofs and exercise trace
behavior and cost bounds.

Shell sort additionally proves that each positive-gap pass orders its columns,
and that the final gap of one produces a sorted permutation. Its instrumented
implementation agrees with the original result, and replaying its generated
transpositions reconstructs that result. Exhaustive checks also cover trace
agreement and the swap bound.

Counting's verification follows the same six-module layout as the established
algorithms: `Equations`, `Correctness`, `Trace`, `Cost`, `Complexity`, and `Checks`.
Its correctness proof establishes that every histogram bucket equals the input
multiplicity. Each trace event records a key and its updated counter value;
replay checks the input order and counter updates before expanding the histogram.
Both generated-trace acceptance and arbitrary accepted-trace correctness are
proved. These are histogram events, not position swaps.

Radix sort proves that each pass orders the processed low bits, yielding a sorted
permutation after all passes. Its instrumented implementation agrees with the
original result; trace replay validates bit order and every bucket choice,
rejecting missing, extra, or incorrect decisions and rounds. Every accepted trace
reconstructs a sorted permutation of its input.

## Complexity

The time bounds below are algorithmic reference bounds under a unit-cost model:
key comparisons, array access, and digit extraction cost constant time. They
exclude trace construction, runtime memory-management overhead, and the bit cost
of arithmetic on unbounded natural numbers. The last two columns report only
results already proved in this repository.

| Algorithm | Reference worst-case time | Formalized cost model | Proved result |
| --- | --- | --- | --- |
| Insertion sort | `O(n²)` | adjacent swaps, worst case | `Θ(n²)` |
| Bubble sort | `O(n²)` | adjacent swaps, worst case | `Θ(n²)` |
| Selection sort | `O(n²)` | arbitrary-position swaps | `O(n)` |
| Merge sort | `O(n log n)` | comparisons | `O(n log n)` |
| Pancake sort | `O(n²)` | prefix reversals | `O(n)` |
| Quick sort | `O(n²)` | pending | not yet proved |
| Heap sort | `O(n log n)` | root extractions | exact `n`; `Θ(n)` |
| Shell sort | `O(n²)` for halving gaps | gapped swaps | `≤ 2n²`; `O(n²)` |
| Counting sort | `O(n + k)` | input visits, bucket initialization/enumeration, output entries | `Θ(n + k)` |
| Radix sort | `O(n b)` for binary passes | digit tests; scan/partition/append work | exact tests `n * b`; work `Θ(n b)` |

Parameters:

- `n`: number of input elements.
- `k = max(input, default 0) + 1`: counting sort's allocated key range.
- `b = Nat.log2(max(input, default 0)) + 1`: radix sort's number of binary passes.
  This implementation uses one pass even when all keys are zero.

These parameters describe different aspects of the input: a short list can have
a large `k` or `b`. Counting sort is `O(n)` when `k = O(n)`;
radix sort is `O(n)` when `b = O(1)` in this model. See
[MIT's counting and radix sort notes](https://ocw.mit.edu/courses/6-006-introduction-to-algorithms-fall-2011/resources/mit6_006f11_lec07/)
for the parameter-dependent analysis.

Implementation-specific details:

- **Quick sort:** the pivot is always the first element. Sorted, reverse-sorted,
  and all-equal inputs can produce quadratic work. The usual expected
  `O(n log n)` comparison bound assumes a uniformly random ordering of distinct
  keys or randomized pivots; this implementation does not randomize its pivot.
- **Heap sort:** the reference bound includes building the heap and extracting
  all elements. Batteries collects the result in a separate array, so the usual
  in-place heapsort space claim does not apply to this implementation.
  The formal counter charges one unit per root extraction, exactly `n` units.
  It excludes heap construction, comparisons, internal swaps, and trace work;
  its `Θ(n)` bound is not a total-runtime bound. A formal `O(n log n)` bound on
  comparison work remains to be added.
- **Shell sort:** the bound is for the implemented `n/2, n/4, ..., 1` gaps.
  The formal counter is the number of transpositions in the generated trace.
  Each insertion at index `i` makes at most `i / gap` swaps; summing over the
  halving gaps gives at most `2n²` swaps and a formal `O(n²)` bound. This counts
  swaps, excluding comparisons, array copying, and trace construction/replay.
  Bounds for other increment sequences do not automatically apply here.
- **Counting sort:** finding the maximum and counting take `O(n)` logical work;
  initializing/enumerating buckets takes `O(k)`, and producing the output takes
  `O(n)`. The formal model charges one unit per input visit, initialized bucket,
  histogram update, enumerated bucket, and emitted entry: exactly `3*n + 2*k`.
  Its `Θ(n + k)` theorem allows either length or key range to grow. Trace storage,
  runtime allocation/copying, and arbitrary-precision arithmetic are excluded.
  A large maximum key can therefore dominate the cost.
- **Radix sort:** the digit-test counter is exactly `n * b`. A separate
  algorithm-level work model charges one unit per maximum-scan visit, partition
  visit (digit test and bucket placement), and node copied by list append.
  The proved bound is `n*b ≤ W ≤ n + 2*n*b ≤ 3*n*b`, hence `Θ(n b)`.
  The costed execution is proved to return the original algorithm's output.
  Bit arithmetic, pass-index construction, runtime allocation overhead, and
  instrumentation are outside this model.

The proved swap and flip bounds count whole operations: selection's `O(n)`
swaps do not include finding minima, and pancake's `O(n)` flips do not include
finding maxima or moving the elements of a reversed prefix. Neither is a
linear-time sorting claim.

Quick sort still needs a formal cost definition,
a connection to their executable algorithms, concrete bounds, and asymptotic
proofs. No total-runtime or space-complexity theorem is currently claimed.

### Reading the Radix time-complexity proof

Start with [Radix/Complexity.lean](LeanSort/Verification/Radix/Complexity.lean).
It states the mathematical argument before the Lean proof:

```text
n = number of elements; b = number of binary passes (at least 1)
one pass:       n visits + at most n copied nodes
after b passes: n*b ≤ pass work ≤ 2*n*b
maximum scan:   n ≤ n*b
therefore:      n*b ≤ W ≤ 3*n*b, so W = Θ(n*b)
```

[Radix/Cost.lean](LeanSort/Verification/Radix/Cost.lean) defines the work units
and proves each bound. For `[3, 2, 1, 0]`, `n = 4`, `b = 2`: there are exactly
8 digit tests, while the scan/partition/append model counts 16 units of work.
Both are formal cost claims, not measurements of elapsed time. The main theorem
uses mathlib's `Θ`; its input filter means `n*b` grows without bound, not an
average-case input distribution or an assumption that `b` is fixed.

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
