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
input occurrence have been established. **Pending** means the correctness proof
has not yet been written. **Partial** identifies the remaining correctness gap.

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
| [Bitonic](LeanSort/Algorithm/Bitonic.lean) | Partial: permutation proved; sortedness pending | Comparator schedule; checked replay |
| [Introsort](LeanSort/Algorithm/Intro.lean) | Pending | Not implemented |
| [Powersort](LeanSort/Algorithm/Power.lean) | Pending | Not implemented |

For rows marked **Pending**, verification modules, including trace verification,
formal cost bounds, and applicable stability proofs, have not yet been added.
Executable regression checks have passed, but do not replace proofs.

Bitonic additionally has verified comparator index bounds, exact schedule execution,
and a comparator count of `p * d * (d + 1) / 4`, where `p = 2^d` is the padded
length. Its general bitonic-merge sortedness proof is still missing.

Formal cost results include insertion's exact inversion count, selection's
exact `n(n−1)/2` comparisons, tree's tight worst-case `n(n−1)/2` comparisons,
and merge's `O(n log n)` comparison bound.
These count specified operations; they do not measure wall-clock time or memory.
Counting, radix, and bucket accept natural-number keys; the other algorithms accept
linearly ordered types.

See the [verification guide](docs/verification.md) for all cost bounds,
trace-checker guarantees, assumptions, and theorem references.

Powersort also exposes `LeanSort.Power.powerSortBy` for sorting records by a
total-preorder comparator.

## Explore the code

- [Model](LeanSort/Model/) — shared mathematical definitions.
- [Algorithm](LeanSort/Algorithm/) — executable sorting implementations.
- [Verification](LeanSort/Verification/) — correctness, trace semantics, costs, and checks.

Where available, start with `Correctness.lean` in a verification directory for the sorting
contract or `Checks.lean` for examples. Dependencies are pinned in
[lakefile.toml](lakefile.toml) and [lake-manifest.json](lake-manifest.json).
