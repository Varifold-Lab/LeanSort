# Verification guide

Detailed proof coverage, trace semantics, and cost models for [LeanSort](../README.md).

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

The table tracks correctness and trace coverage as algorithms are added.
Sorting correctness means the output is sorted and is a permutation of the input.
Trace verification and formal cost models have separate coverage, described below.

| Algorithm | Sorting correctness | Trace |
| --- | --- | --- |
| Insertion sort | proved | shortest adjacent-swap trace; bounded indices |
| Bubble sort | proved | adjacent transpositions |
| Selection sort | proved | bounded transpositions; checked replay and round contracts |
| Merge sort | proved | comparison choices; single-merge derivations and checked replay |
| Pancake sort | proved | prefix reversals; active-prefix bounds and checked replay |
| Quick sort | proved | comparison decision trees; checked recursive replay |
| Heap sort | proved | root extractions; checked replay |
| Shell sort | proved | gapped transpositions |
| Counting sort | proved | histogram updates; checked replay |
| Radix sort | proved | binary partition choices |
| Tree sort | proved | insertion comparison paths; exact checked replay |
| Bucket sort | proved | key-to-bucket placements; exact checked replay |
| Bitonic sort | partial: permutation proved; sortedness pending | comparator schedule; exact checked replay |
| Introsort | pending | not implemented |
| Powersort | pending | not implemented |

Rows marked pending have executable algorithms, but no verification modules yet;
correctness, trace verification, formal cost bounds, and applicable stability
proofs remain to be written.

### Bitonic verification in progress

`bitonicSortResult_perm` proves preservation of every input occurrence for any
linearly ordered key type, including after padding is removed. `paddedInput_size`
proves the padded length is exactly `2 ^ networkDepth xs.length`.
`compareExchange_ordered` proves local endpoint order after a valid comparator.
**Global sortedness is not yet proved**: the remaining work is the bitonic-merge
invariant and its preservation through the recursive array implementation.

`mergeSchedule` and `sortSchedule` describe the actual comparator calls, including
their direction and indices. `run_sortSchedule` identifies their execution with
`sortNetwork`; `sortSchedule_valid` proves all calls are in bounds. `Executes`
provides deterministic relational semantics. `replayChecked?_iff` accepts exactly
the canonical schedule and returns exactly the algorithm's result. This is a
schedule certificate, not a sortedness certificate or a log of actual swaps.

`sortComparisons_exact` proves `4 * comparisons = 2^d * d * (d+1)`.
All comparator calls are counted, including those involving sentinels.
`paddedLength_lt_twice` bounds nonempty padding by less than twice input length;
`comparisonCost_bound` gives the explicit bound `n * d * (d+1)`.
These are sequential comparator counts, not parallel depth or wall-clock time.
Regression checks cover all 3,280 lists of length at most seven over `{0,1,2}`,
larger padding boundaries, signed and large keys, and malformed schedules.
They do not replace the missing general sortedness proof.

### Tree and bucket verification

Tree sort uses an unbalanced binary search tree with strictly smaller keys on
the left and greater-or-equal keys on the right. `ordered_insert` preserves this
structural invariant, `sorted_inorder` proves that traversal is sorted, and
`inorder_insert_perm` tracks every occurrence. `treeSortResult_spec` combines
sortedness and permutation preservation; length, membership, and occurrence-count
corollaries are also proved.

`treeSortTrace` records one root-to-empty-leaf comparison path per insertion.
`InsertionDerivation` gives these paths relational semantics, and
`replayInsert?_derivation_iff` establishes checker soundness and completeness.
`replayChecked?_iff` shows that a full log is accepted exactly when it is the
canonical log and the output is the algorithm's result. Missing or extra paths,
missing or extra decisions, incorrect comparisons, and left branches on equal
keys are rejected. `treeSortCertificate` packages the output, log, and successful
replay; every accepted certificate implies the sorting contract.

`treeComparisonCost_eq_trace` identifies construction comparisons with the total
path length. Each insertion uses at most the current tree height in comparisons.
`treeComparisonCost_le` bounds the full cost by `n choose 2`, and
`treeComparisonCost_replicate` proves that all-equal inputs attain this bound.
`treeWorstComparisonCost_isTheta_quadratic` therefore establishes a tight
worst-case `Θ(n²)` comparison count. The final traversal visits exactly `n`
occupied nodes (`treeTraversalCost_eq_length`). These results do not assume
balance or claim average-case, allocation, or wall-clock bounds. The Tree
`Checks.lean` module checks malformed logs, exact costs on repeated inputs, and
all 1,093 lists of length at most six over `{0, 1, 2}`.

Bucket sort allocates `max 1 n` equal-width buckets for natural-number inputs.
`bucketIndex_lt` proves that every input key indexes the allocation, so the
array update cannot silently discard an occurrence. `distribute_get` identifies
each bucket with the exact input subsequence selected by its interval; the fold's
temporary reversal is undone. `DistributionSpec` expresses this contract
independently of the fold, and any array satisfying it yields a sorted permutation.
`bucketSortResult_spec` proves global sortedness and occurrence preservation,
using the interval order between buckets and insertion sort within each bucket.

The placement trace records input keys and their destination indices, preserving
duplicates and input order. It does not record bucket-internal comparisons.
`replayChecked?_iff` proves exact acceptance of the canonical placement log and
output. Replay rejects missing or extra events, changed keys, wrong bucket labels,
and out-of-range destinations. `bucketSortCertificate` packages the output, log,
and checked replay, with a proved sorting contract.

`bucketComparisonRun_result` connects a comparison-counted execution to the
ordinary sorting result. `bucketComparisonCost` includes the `n` comparisons of
the maximum-key scan plus each bucket's actual insertion-sort comparisons.
`bucketComparisonCost_le_bucketSizes` bounds this by `n + ∑ᵢ choose(nᵢ, 2)`;
`bucketComparisonCost_le` gives the unconditional bound `n + choose(n, 2)` and
`bucketComparisonCost_isBigO_quadratic` establishes `O(n²)`. Placement events
are exactly `n`, hence `Θ(n)`; bucket lengths sum to `n`, and the allocation is
at most `n + 1` buckets. These bounds neither assume uniform keys nor claim
expected linear time or a tight quadratic lower bound. They exclude tracing
overhead, allocation time, and the bit complexity of unbounded-natural arithmetic.
The Bucket `Checks.lean` module exercises malformed logs, sparse large keys,
interval boundaries, exact sample costs, and all 5,461 lists of length at most
six over `{0, 1, 2, 7}`.

Insertion sort sorts the tail first, then inserts the head, using `Writer` to
accumulate the adjacent-swap trace. A single insertion scans the initial block of
elements strictly smaller than the inserted value and emits exactly that interval
of swaps. The `insertTr_spec` theorem combines agreement with `List.orderedInsert`,
the exact trace, replay under any prefix, and preservation of sortedness.
`insertionSortCertificate` packages the output, trace, replay equality, sortedness,
and permutation proofs together. `insertionSortBoundedTrace` represents each swap
index as `Fin (n - 1)`, proving both positions exist; erasing the bounds recovers
the original trace, and bounded replay yields the same output.

The trace length is proved equal to the input's inversion count.
`insertionSortTrace_optimal` proves that replay sorts the input and that no
adjacent-swap trace sorting the same input is shorter. This is an operation-count
result; total runtime is outside this model. Exhaustive checks on all 364 lists of
length at most five over `{0, 1, 2}` cover output agreement, ordinary and bounded
replay, and the exact inversion cost. Minimality is established by a universal
proof.

Selection sort exposes each minimum-selection round as a result paired with its
zero-or-one swap plan. `MinimumSpec` independently characterizes the selected
occurrence: it is a valid minimum and every earlier position is strictly larger.
The contract is proved equivalent to `argmin?` and uniquely determines both
index and value, establishing the leftmost tie policy.

`RoundSpec` proves that replay fixes the minimum at the active head, preserves
the input multiset and an arbitrary preceding prefix, retains the tail length,
and emits at most one swap. Generated swaps satisfy `off ≤ i < j < off + n`;
each round starts at its active head, so previously fixed positions remain intact.
`replayChecked?` accepts exactly in-bounds swaps with `i < j` and agreement with
ordinary replay. A valid arbitrary swap word need not sort. The execution-based
`selectionSortCertificate` derives sorting correctness, checked replay, index
bounds, and the swap budget. Choosing the first minimum does not claim whole-sort
stability. Checks cover all 364 lists of length at most five over `{0, 1, 2}`,
duplicate minima, prefix replay, and invalid swaps. See
[Selection/Trace.lean](../LeanSort/Verification/Selection/Trace.lean) and
[Selection/Correctness.lean](../LeanSort/Verification/Selection/Correctness.lean).

Selection also certifies intermediate states: `SettledPrefix k` means the first
`k` entries are ordered and no larger than any remaining entry.
`selectionPartialCertificate` provides this invariant, exactly `min(k,n)` settled
entries, permutation preservation, and checked replay under an arbitrary fixed
prefix. Its swap budget is `min(k,n-1)` (natural subtraction gives zero on empty
input); a complete run therefore uses at most `n-1` swaps. The final remaining
element never requires a swap. Sufficient fuel gives the complete sorting
contract. Regression checks exercise every small input at every fuel level from
zero through two rounds beyond its length.

`SelectionDerivation` independently describes every nonempty selection round,
including rounds that emit no swap, using `MinimumSpec` and the primitive head
swap. It is proved equivalent to `sortAuxTr`, and determines a unique output and
trace for a fixed input, offset, and fuel budget. Its partial-prefix and swap-cost
contracts follow from that equivalence.

`replaySelectionAux?` and `replaySelection?` enforce the algorithm itself: they
recompute each leftmost minimum and consume exactly its swap plan, rejecting
missing, extra, or noncanonical swaps. Acceptance is proved equivalent to the
generated execution and to a legal derivation. This checker re-executes minimum
selection; it is not a cheaper independent sorting algorithm. It rejects a trace
that sorts `[2,1,1]` by swapping with the later `1`, even though generic checked
replay accepts that valid rearrangement. Both full and partial certificates now
provide legal derivations and strict replay. See
[Selection/Semantics.lean](../LeanSort/Verification/Selection/Semantics.lean).

Selection's comparison model is executable: `argminWithComparisons` charges one
unit when comparing a head against an existing tail minimum, and is proved to
return `argmin?`'s result with exactly `max(n-1,0)` comparisons.
`sortAuxWithComparisons` uses those minimum scans and is proved to reproduce the
entire original output/trace pair. After `k` rounds its cost is exactly
`choose(n,2) - choose(n-k,2)`, with natural subtraction, including surplus fuel.
A complete run therefore performs exactly `n*(n-1)/2` key comparisons on every
input, including already sorted and all-equal lists. The comparison cost is
formally `Θ(n²)` as input length grows, while swaps remain bounded by `n-1`.
Full and partial certificates identify the counted execution as well. This model
excludes index checks, swaps, list copying, and checker/instrumentation overhead.
See [Selection/Comparisons.lean](../LeanSort/Verification/Selection/Comparisons.lean).

Quick sort uses a deterministic first pivot. `partitionTr` performs one scan,
producing both partitions and their comparison decisions without re-comparing
the input to construct the trace. `quickSortTr` is the single recursive execution
core; `quickSortResult` projects its output.
`PartitionSpec` identifies both sides with order-preserving filters, proves
multiset conservation, and puts ties on the left and strictly greater keys on
the right. This local order preservation is not a key-based stability theorem
for the whole sort.

`quickSortTr` records a tree with one node per pivot, the partition decisions in
input order, and both recursive subtrees; empty calls have explicit leaves.
Its output agrees with `quickSortResult` by definition. Checked replay validates every
decision and recursive boundary while re-executing partitioning.
`replayChecked?_iff` proves acceptance exactly when the supplied output and tree
are the generated execution; any accepted tree therefore yields a sorted
permutation. `quickSortCertificate` stores execution identity and derives replay
and sorting correctness. This is a comparison trace, not a sequence of swaps.

`PartitionDerivation` independently specifies legal left/right steps using order
premises. `QuickDerivation` composes a partition derivation with both recursive
derivations and pivot concatenation. Neither relation invokes the sorter.
Both are proved equivalent to their executable counterparts;
`replayChecked?_iff_derivation` connects checked replay to these rules.
A derivation uniquely determines both output and trace, implies the sorting
contract, and is provided by every execution certificate. See
[Quick/Semantics.lean](../LeanSort/Verification/Quick/Semantics.lean).

The trace contains exactly one pivot per input occurrence. Its comparison count
satisfies the exact partition recurrence and the universal bound `n*(n-1)/2`.
Nonincreasing inputs (including duplicates) and strictly increasing inputs
are proved to attain this bound; constant lists witness the maximum at every
length. `worstComparisonCost_isTheta_quadratic` proves the resulting worst-case
comparison cost is `Θ(n²)`.

The structural depth sum ignores decision-list lengths. On generated trees it
is proved equal to the comparison count: a pivot at depth `d` participated in
`d` ancestor partitions. If `h` is the number of pivot levels on a longest
branch, the proved bound is `comparisons + n ≤ n*h`. The worst-case input
families above have height exactly `n`. See
[Quick/Tree.lean](../LeanSort/Verification/Quick/Tree.lean) and
[Quick/Complexity.lean](../LeanSort/Verification/Quick/Complexity.lean).
Checks cover all 364 lists of length at most five over `{0, 1, 2}`, malformed
comparison trees, and ascending, descending, all-equal, and balanced examples.
See [Quick/Trace.lean](../LeanSort/Verification/Quick/Trace.lean) and
[Quick/Cost.lean](../LeanSort/Verification/Quick/Cost.lean).

Merge sort gives comparison choices a relational semantics through
`MergeDerivation`: a left step requires `x ≤ y`, a right step requires `y < x`,
and an exhausted run appends the other run without further comparisons.
`replayMerge?_iff_derivation` proves that replay accepts exactly the legal
derivations. Each derivation uniquely determines the instrumented result and
trace; for sorted input runs, its contract gives a sorted permutation of their
concatenation and the exact CSlib comparison count. Unsorted runs can also have
legal traces, so replay acceptance alone does not imply sortedness.

`mergeSortCertificate` binds the whole-sort output and flat trace to the
instrumented execution, sortedness, permutation, and comparison count.
The flat trace does not record recursive merge boundaries; the checked replay
API applies to a single merge with its two input runs. Choosing the left head on
ties is explicit, but no general key-based stability theorem is claimed.
Regression checks cover all 1,600 pairs of runs of length at most three over
`{0, 1, 2}`, and whole-sort certificates on all 364 lists of length at most five.
See [Merge/Trace.lean](../LeanSort/Verification/Merge/Trace.lean) for the semantics
and certificate proofs.

Pancake sort defines each round by selecting a maximum, constructing `roundPlan`,
and replaying that plan. The plan is empty when the maximum is at the end, has one
flip when it is at the head, and otherwise has two flips. Output and trace thus
share one execution definition. `RoundSpec` states that replay reconstructs its
output, the input multiset is preserved, at most two flips are emitted, and a
maximum of the active prefix is fixed at its end while the suffix is untouched.
Every emitted flip has length between two and the active-prefix length; later
rounds stay within that range as the active prefix shrinks.

`replayChecked?` rejects zero-length, single-element, and out-of-bounds flips.
Its acceptance theorem characterizes exactly valid flip lengths and agreement
with ordinary replay. A valid arbitrary trace need not sort the input.
`pancakeSortCertificate` stores the output, trace, and their execution identity;
sortedness, permutation, checked replay, and the `2*n` flip bound are derived
from that identity. Exhaustive checks cover all
364 lists of length at most five over `{0, 1, 2}` and every active-prefix length,
including preservation of the suffix. See
[Pancake/Trace.lean](../LeanSort/Verification/Pancake/Trace.lean).

Heap sort reuses Batteries' array-backed binary heap, with a separate output
array. Its permutation theorem proves preservation of elements and their
multiplicities; length and membership preservation follow directly. The proof
covers sifting, heap construction, root removal, and the extraction loop.
Sortedness follows from a minimum-heap invariant: sifting repairs the sole possible
violating node, construction establishes heap order, and root removal preserves it.
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

Shell sort's public result projects the traced execution. Its `Semantics` module
defines independent rules for strict-inversion swaps, insertion sequences, and
gap schedules, and proves their equivalence with execution. Each positive-gap
pass orders its columns; global sortedness follows from the final gap of one.
Structured traces preserve gap labels and empty passes, and flatten exactly to
the original transposition trace. The strict checker recomputes each expected
pass and accepts exactly its execution, rejecting missing, reordered, or altered
passes. Certificates provide sortedness, permutation, canonical gap schedules,
checked replay, and the `2n²` swap bound. The bound counts swaps, not checker
runtime or comparisons. Exhaustive checks cover structured replay and erasure.

Counting's verification follows the same six-module layout as the established
algorithms: `Equations`, `Correctness`, `Trace`, `Cost`, `Complexity`, and `Checks`.
Its correctness proof establishes that every histogram bucket equals the input
multiplicity. Each trace event records a key and its updated counter value;
replay checks the input order and counter updates before expanding the histogram.
Both generated-trace acceptance and arbitrary accepted-trace correctness are
proved. These are histogram events, not position swaps.

Radix sort uses one partition implementation for the pass result and its bucket
decisions; `radixSortResult` projects the same `sortTrace` execution that supplies
the trace. Each pass orders the processed low bits, yielding a sorted permutation
after the full least-significant-digit schedule.

`PartitionDerivation` specifies zero/one digit rules independently of execution.
Its contract identifies both buckets with order-preserving filters and proves
multiset conservation and one decision per input occurrence. `DigitDerivation`
joins the buckets; `PassesDerivation` composes the exact supplied bit schedule.
Legal derivations, generated execution, and checked replay are proved equivalent,
and the output and trace are unique for a fixed input and schedule.

An arbitrary schedule preserves elements but need not sort. A pass advances
`SortedBits bit` to `SortedBits (bit + 1)` when its input satisfies that invariant;
the canonical prefix `[0, ..., b-1]` establishes `SortedBits b`. Complete-sort replay
enforces its canonical schedule and rejects missing, extra, or incorrect decisions
and rounds. Every accepted complete-sort trace reconstructs a sorted permutation.

`radixSortCertificate` derives replay, a legal derivation, sortedness, permutation,
the round count, and exactly `n*b` digit tests from its execution identity.
Empty and all-zero inputs still have one round, including an empty decision list
for an empty input. Checks include directly constructed derivations and a legal
noncanonical schedule whose output is not sorted. See
[Radix/Semantics.lean](../LeanSort/Verification/Radix/Semantics.lean).

## Complexity

The time bounds below are algorithmic reference bounds under a unit-cost model:
key comparisons, array access, and digit extraction cost constant time. They
exclude trace construction, runtime memory-management overhead, and the bit cost
of arithmetic on unbounded natural numbers. The last two columns report only
results already proved in this repository.

| Algorithm | Reference worst-case time | Formalized cost model | Proved result |
| --- | --- | --- | --- |
| Insertion sort | `O(n²)` | adjacent swaps | exactly the inversion count; minimal trace; worst case `Θ(n²)` |
| Bubble sort | `O(n²)` | adjacent swaps, worst case | `Θ(n²)` |
| Selection sort | `O(n²)` | key comparisons; arbitrary-position swaps | comparisons exactly `n*(n-1)/2`, `Θ(n²)`; swaps at most `n-1`, `O(n)` |
| Merge sort | `O(n log n)` | comparisons | `O(n log n)` |
| Pancake sort | `O(n²)` | prefix reversals | `O(n)` |
| Quick sort | `O(n²)` | partition key comparisons | exact worst case `n*(n-1)/2`; `Θ(n²)` |
| Heap sort | `O(n log n)` | key comparisons; root extractions | comparisons `O(n log n)`; extractions exactly `n` |
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
  The comparison-counted execution includes sibling and parent-child comparisons
  during both construction and extraction, and is proved to return Batteries' result.
  Each sift makes at most `2 * (floor(log2 n) + 1)` comparisons, yielding the
  conservative whole-sort bound `4 * n * (floor(log2 n) + 1)` and a formal
  `O(n log n)` theorem over the real logarithm. The separate extraction counter
  remains exactly `n`. Index tests, allocation/copying, comparator bit costs,
  and instrumentation overhead are outside the key-comparison model.
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

Quick sort has an execution-linked comparison model, an attained exact worst-case
bound, and a worst-case `Θ(n²)` theorem. Average-case and randomized-pivot
theorems remain future work. No total-runtime or space-complexity theorem is claimed.

### Reading the Insertion trace proof

- [Insertion/Equations.lean](../LeanSort/Verification/Insertion/Equations.lean)
  characterizes the single-insertion trace as a consecutive interval of swaps.
- [Insertion/Trace.lean](../LeanSort/Verification/Insertion/Trace.lean) proves replay,
  certifies index bounds, and constructs the sorting certificate.
- [Insertion/Cost.lean](../LeanSort/Verification/Insertion/Cost.lean) proves the exact
  inversion cost and minimality, using the shared
  [inversion bounds](../LeanSort/Verification/Shared/InversionBounds.lean).
- [Insertion/Complexity.lean](../LeanSort/Verification/Insertion/Complexity.lean)
  proves the worst-case cost `n * (n - 1) / 2`, attained on descending inputs,
  and its `Θ(n²)` asymptotic bound.

### Reading the Radix time-complexity proof

Start with [Radix/Complexity.lean](../LeanSort/Verification/Radix/Complexity.lean).
It states the mathematical argument before the Lean proof:

```text
n = number of elements; b = number of binary passes (at least 1)
one pass:       n visits + at most n copied nodes
after b passes: n*b ≤ pass work ≤ 2*n*b
maximum scan:   n ≤ n*b
therefore:      n*b ≤ W ≤ 3*n*b, so W = Θ(n*b)
```

[Radix/Cost.lean](../LeanSort/Verification/Radix/Cost.lean) defines the work units
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

Install Lean through [elan](https://github.com/leanprover/elan). The repository's
`lean-toolchain` selects Lean `v4.34.0-rc2`; dependency revisions are pinned in
`lakefile.toml` and resolved in `lake-manifest.json`. From the repository root:

```sh
lake build
```

The default target is `LeanSort`. Its umbrella module imports all listed algorithms
and their verification modules, including the executable `#guard` checks, so the
build checks both proofs and regression examples.
