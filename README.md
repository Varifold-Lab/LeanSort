# LeanSort

**Sorting algorithms and formal verification in Lean 4.**

LeanSort connects executable sorting algorithms with proofs of correctness,
execution traces, and operation counts. The core correctness contract is a sorted
permutation of the input: no elements lost, added, or duplicated. Implementations
and proofs are developed incrementally; their current status is listed below.

The library is designed for studying and extending the mathematics of sorting.
It builds on mathlib, CSlib, and Batteries.

## Quick start

Install [elan](https://github.com/leanprover/elan), then run:

```sh
git clone https://github.com/Varifold-Lab/LeanSort.git
cd LeanSort
lake build
```

The repository pins Lean and its dependencies. `lake build` checks all proofs
and executable regression examples.

Try this in a Lean file inside the repository:

```lean
import LeanSort

open LeanSort.Quick

#eval quickSortResult [3, 1, 2, 1] -- [1, 1, 2, 3]

-- Correctness for every input, including duplicates.
example (xs : List Nat) :
    LeanSort.IsSortingResult (· ≤ ·) xs (quickSortResult xs) :=
  quickSortResult_spec xs
```

## Algorithms and verification status

All listed algorithms have executable implementations available through
`import LeanSort`. **Proved** means both sortedness and preservation of every
input occurrence have been established. All 15 algorithms have this correctness
contract proved and integrated into the library.

| Algorithm | Correctness | Execution trace |
| --- | --- | --- |
| [Insertion](LeanSort/Algorithm/Insertion.lean) | [Proved](LeanSort/Verification/Insertion/Correctness.lean) | Adjacent swaps; shortest sorting trace |
| [Bubble](LeanSort/Algorithm/Bubble.lean) | [Proved](LeanSort/Verification/Bubble/Correctness.lean) | Adjacent swaps |
| [Selection](LeanSort/Algorithm/Selection.lean) | [Proved](LeanSort/Verification/Selection/Correctness.lean) | Minimum-selection rounds and swaps |
| [Merge](LeanSort/Algorithm/Merge.lean) | [Proved](LeanSort/Verification/Merge/Correctness.lean) | Comparison choices within merges |
| [Pancake](LeanSort/Algorithm/Pancake.lean) | [Proved](LeanSort/Verification/Pancake/Correctness.lean) | Prefix reversals |
| [Quick](LeanSort/Algorithm/Quick.lean) | [Proved](LeanSort/Verification/Quick/Correctness.lean) | Recursive partition decision trees |
| [Heap](LeanSort/Algorithm/Heap.lean) | [Proved](LeanSort/Verification/Heap/Correctness.lean) | Root extractions |
| [Shell](LeanSort/Algorithm/Shell.lean) | [Proved](LeanSort/Verification/Shell/Correctness.lean) | Gap-labelled passes and swaps |
| [Counting](LeanSort/Algorithm/Counting.lean) | [Proved](LeanSort/Verification/Counting/Correctness.lean) | Histogram updates |
| [Radix](LeanSort/Algorithm/Radix.lean) | [Proved](LeanSort/Verification/Radix/Correctness.lean) | Binary partition decisions |
| [Tree](LeanSort/Algorithm/Tree.lean) | [Proved](LeanSort/Verification/Tree/Correctness.lean) | Insertion comparison paths; checked replay |
| [Bucket](LeanSort/Algorithm/Bucket.lean) | [Proved](LeanSort/Verification/Bucket/Correctness.lean) | Key-to-bucket placements; checked replay |
| [Bitonic](LeanSort/Algorithm/Bitonic.lean) | [Proved](LeanSort/Verification/Bitonic/Correctness.lean) | Comparator schedule; checked replay |
| [Introsort](LeanSort/Algorithm/Intro.lean) | [Proved](LeanSort/Verification/Intro/Correctness.lean) | Partition decisions and insertion/heap leaves; checked replay |
| [Powersort](LeanSort/Algorithm/Power.lean) | [Proved](LeanSort/Verification/Power/Correctness.lean) | Original-run boundaries and merges; checked replay |

Correctness, trace verification, cost bounds, and stability have separate coverage.
Executable regression checks accompany the proofs but do not replace them.

Bitonic has verified comparator index bounds, exact schedule execution,
and a comparator count of `p * d * (d + 1) / 4`, where `p = 2^d` is the padded
length. Its sortedness proof uses the zero-one principle and an exact correspondence
between the mathematical network and the executable array implementation.

Formal cost results include insertion's exact inversion count, selection's
exact `n(n−1)/2` comparisons, tree's tight worst-case `n(n−1)/2` comparisons,
and the `O(n log n)` comparison bounds for merge sort, Introsort, and Powersort.
These count specified operations; they do not measure wall-clock time or memory.
Counting, radix, and bucket accept natural-number keys; the other algorithms accept
linearly ordered types.

See the [verification guide](docs/verification.md) for all cost bounds,
trace-checker guarantees, assumptions, and theorem references.

Introsort's proof covers arbitrary insertion cutoffs and depth budgets, including
heap fallback at zero depth. With its default parameters, the comparison bound
is `n * (6 * log₂ n + 20)`, including partitioning, insertion leaves, and heap leaves.

Powersort also exposes `LeanSort.Power.powerSortBy` for sorting records by a
total-preorder comparator, with proved correctness and key-based stability.
Its scheduler performs exactly `max(r - 1, 0)` merges for `r` natural runs.
Run detection and all merges together use at most `n * (log₂ n + 2)` key
comparisons, with a formal worst-case `O(n log n)` bound. The dyadic node-power
specification and logarithmic merge-tree height are also proved.

## Explore the code

- [Model](LeanSort/Model/) — shared mathematical definitions.
- [Algorithm](LeanSort/Algorithm/) — executable sorting implementations.
- [Verification](LeanSort/Verification/) — correctness, trace semantics, costs, and checks.

Where available, start with `Correctness.lean` in a verification directory for the sorting
contract or `Checks.lean` for examples. Dependencies are pinned in
[lakefile.toml](lakefile.toml) and [lake-manifest.json](lake-manifest.json).

## Contributing

Contributions to implementations, proofs, tests, and documentation are welcome.
See [CONTRIBUTING.md](CONTRIBUTING.md) for the build and pull-request workflow.

## License

LeanSort's original code and documentation are licensed under the
[Apache License 2.0](LICENSE). Copyright remains with the contributors.
See [NOTICE](NOTICE) for attribution and the retained
[AKS third-party notices](third_party/aks/NOTICE.md).
External dependencies retain their own licenses.
