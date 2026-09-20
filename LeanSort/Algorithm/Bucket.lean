import Mathlib.Data.List.Sort

/-!
Bucket sort for natural-number keys. Allocate one bucket per input occurrence
(one empty bucket for empty input), distribute by equal-width value intervals,
sort each bucket by insertion sort, then concatenate in bucket order.

The bucket array size depends on the input length, not the largest key. Uneven
distributions can put all keys in one bucket, so no unconditional linear-time
bound is claimed. Proofs and cost models live in `Verification/Bucket`.
-/

namespace LeanSort.Bucket

/-- Positive number of buckets allocated for this input. -/
def bucketCount (xs : List Nat) : Nat := max 1 xs.length

/-- Positive interval width. With `m` the largest key and `b` the bucket count,
`m / b + 1` ensures every input key has bucket index strictly below `b`. -/
def bucketWidth (xs : List Nat) : Nat :=
  xs.foldl max 0 / bucketCount xs + 1

/-- Prepend each key to its interval's bucket. Public sorting supplies a positive
width and an allocation large enough for every key. -/
def scatter (width : Nat) (xs : List Nat) (buckets : Array (List Nat)) :
    Array (List Nat) :=
  xs.foldl (fun buckets x => buckets.modify (x / width) (fun bucket => x :: bucket)) buckets

/-- Distribute input occurrences into consecutive value intervals.
Prepending during the scan avoids repeated list appends; reversing each bucket
afterwards restores input order. All indices are computed using the width and
count of this same input. Empty buckets remain present. -/
def distribute (xs : List Nat) : Array (List Nat) :=
  let width := bucketWidth xs
  let buckets := scatter width xs (Array.replicate (bucketCount xs) [])
  buckets.map List.reverse

def bucketOutput (buckets : Array (List Nat)) : List Nat :=
  buckets.toList.flatMap (fun bucket => bucket.insertionSort (· ≤ ·))

/-- Sort within each bucket, then concatenate from the lowest interval to the
highest. Equal keys are retained as separate occurrences. -/
def bucketSortResult (xs : List Nat) : List Nat :=
  bucketOutput (distribute xs)

/-- One distribution event: the input key and its destination bucket.
This log covers placement, not the comparisons performed inside each bucket. -/
abbrev Placement := Nat × Nat

def bucketSortTrace (xs : List Nat) : List Placement :=
  xs.map (fun x => (x, x / bucketWidth xs))

def sortTrace (xs : List Nat) : List Nat × List Placement :=
  (bucketSortResult xs, bucketSortTrace xs)

/-- Validate and replay each placement against the input and allocation.
Invalid bucket indices and missing, extra, or altered events are rejected. -/
def replayScatter? (width : Nat) :
    List Nat → List Placement → Array (List Nat) → Option (Array (List Nat))
  | [], [], buckets => some buckets
  | x :: xs, step :: steps, buckets =>
      if step = (x, x / width) ∧ x / width < buckets.size then
        replayScatter? width xs steps (buckets.modify (x / width) (x :: ·))
      else none
  | _, _, _ => none

/-- Restore each checked bucket's input order and sort it with the same
insertion sort used by the ordinary algorithm. -/
def replayChecked? (trace : List Placement) (xs : List Nat) : Option (List Nat) :=
  (replayScatter? (bucketWidth xs) xs trace (Array.replicate (bucketCount xs) [])).map
    (fun buckets => bucketOutput (buckets.map List.reverse))

end LeanSort.Bucket
