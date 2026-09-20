# LeanSort

**Ten sorting algorithms, formally verified in Lean 4.**

LeanSort connects executable sorting algorithms with proofs of correctness,
execution traces, and operation counts. Every algorithm is proved to return
a sorted permutation of its input: no elements lost, added, or duplicated.

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

## What is verified?

All ten algorithms have sortedness and permutation proofs. Their traces record
different operations; follow each link for its verification modules.

| Algorithm | Execution trace |
| --- | --- |
| [Insertion](LeanSort/Verification/Insertion/) | Adjacent swaps; shortest sorting trace |
| [Bubble](LeanSort/Verification/Bubble/) | Adjacent swaps |
| [Selection](LeanSort/Verification/Selection/) | Minimum-selection rounds and swaps |
| [Merge](LeanSort/Verification/Merge/) | Comparison choices within merges |
| [Pancake](LeanSort/Verification/Pancake/) | Prefix reversals |
| [Quick](LeanSort/Verification/Quick/) | Recursive partition decision trees |
| [Heap](LeanSort/Verification/Heap/) | Root extractions |
| [Shell](LeanSort/Verification/Shell/) | Gap-labelled passes and swaps |
| [Counting](LeanSort/Verification/Counting/) | Histogram updates |
| [Radix](LeanSort/Verification/Radix/) | Binary partition decisions |

Formal cost results include insertion's exact inversion count, selection's
exact `n(n−1)/2` comparisons, and merge's `O(n log n)` comparison bound.
These count specified operations; they do not measure wall-clock time or memory.
Counting and radix accept natural-number keys; the other algorithms accept
linearly ordered types.

See the [verification guide](docs/verification.md) for all cost bounds,
trace-checker guarantees, assumptions, and theorem references.

## Additional algorithm implementations

Five more algorithms are available through `import LeanSort`. Their implementations
have passed executable regression checks, but formal correctness, stability, and cost
proofs have not yet been added; they are not part of the ten verified algorithms above.

| Algorithm | Entry point | Implementation |
| --- | --- | --- |
| [Tree](LeanSort/Algorithm/Tree.lean) | `LeanSort.Tree.treeSortResult` | Unbalanced binary search tree |
| [Bucket](LeanSort/Algorithm/Bucket.lean) | `LeanSort.Bucket.bucketSortResult` | Natural-number buckets with insertion sort |
| [Bitonic](LeanSort/Algorithm/Bitonic.lean) | `LeanSort.Bitonic.bitonicSortResult` | Sorting network with padding for arbitrary lengths |
| [Intro](LeanSort/Algorithm/Intro.lean) | `LeanSort.Intro.introSortResult` | Quicksort with insertion and heap-sort fallbacks |
| [Power](LeanSort/Algorithm/Power.lean) | `LeanSort.Power.powerSortResult` | Natural runs with the Powersort merge policy |

Powersort also exposes `LeanSort.Power.powerSortBy` for sorting records by a
total-preorder comparator. These implementations do not claim in-place sorting.

## Explore the code

- [Model](LeanSort/Model/) — shared mathematical definitions.
- [Algorithm](LeanSort/Algorithm/) — executable sorting implementations.
- [Verification](LeanSort/Verification/) — correctness, trace semantics, costs, and checks.

Within each verification directory, start with `Correctness.lean` for the sorting
contract or `Checks.lean` for examples. Dependencies are pinned in
[lakefile.toml](lakefile.toml) and [lake-manifest.json](lake-manifest.json).
