import Mathlib.Data.List.Sort

/-!
Bucket sort for natural-number keys. Allocate one bucket per input occurrence
(one empty bucket for empty input), distribute by equal-width value intervals,
sort each bucket by insertion sort, then concatenate in bucket order.

The bucket array size depends on the input length, not the largest key. Uneven
distributions can put all keys in one bucket, so no unconditional linear-time
bound is claimed. Definitions here do not include correctness or cost proofs.
-/

namespace LeanSort.Bucket

/-- Positive number of buckets allocated for this input. -/
def bucketCount (xs : List Nat) : Nat := max 1 xs.length

/-- Positive interval width. With `m` the largest key and `b` the bucket count,
`m / b + 1` ensures every input key has bucket index strictly below `b`. -/
def bucketWidth (xs : List Nat) : Nat :=
  xs.foldl max 0 / bucketCount xs + 1

/-- Distribute input occurrences into consecutive value intervals.
Prepending during the scan avoids repeated list appends; reversing each bucket
afterwards restores input order. All indices are computed using the width and
count of this same input. Empty buckets remain present. -/
def distribute (xs : List Nat) : Array (List Nat) :=
  let width := bucketWidth xs
  let buckets := xs.foldl
    (fun buckets x => buckets.modify (x / width) (fun bucket => x :: bucket))
    (Array.replicate (bucketCount xs) [])
  buckets.map List.reverse

/-- Sort within each bucket, then concatenate from the lowest interval to the
highest. Equal keys are retained as separate occurrences. -/
def bucketSortResult (xs : List Nat) : List Nat :=
  (distribute xs).toList.flatMap (fun bucket => bucket.insertionSort (· ≤ ·))

end LeanSort.Bucket
