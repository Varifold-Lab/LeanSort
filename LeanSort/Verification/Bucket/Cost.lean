import LeanSort.Verification.Bucket.Semantics
import Mathlib.Data.Nat.Choose.Basic

/-! Counted insertion-sort execution, maximum-key comparisons, and placements.
Natural-number arithmetic is not assigned a machine-word or bit-complexity cost. -/

namespace LeanSort.Bucket

/-- Instrument the same ordered insertion used by `List.insertionSort`.
Only a comparison against a nonempty list is charged. -/
def insertRun (x : Nat) : List Nat → List Nat × Nat
  | [] => ([x], 0)
  | y :: ys =>
      if x ≤ y then (x :: y :: ys, 1)
      else let rest := insertRun x ys; (y :: rest.1, rest.2 + 1)

def insertionRun : List Nat → List Nat × Nat
  | [] => ([], 0)
  | x :: xs =>
      let rest := insertionRun xs
      let placed := insertRun x rest.1
      (placed.1, rest.2 + placed.2)

@[simp] theorem insertRun_result (x : Nat) (xs : List Nat) :
    (insertRun x xs).1 = xs.orderedInsert (· ≤ ·) x := by
  induction xs with
  | nil => rfl
  | cons y ys ih => simp [insertRun, List.orderedInsert, ih]; split <;> rfl

@[simp] theorem insertionRun_result (xs : List Nat) :
    (insertionRun xs).1 = xs.insertionSort (· ≤ ·) := by
  induction xs with
  | nil => rfl
  | cons x xs ih => simp [insertionRun, ih]

theorem insertRun_comparisons_le (x : Nat) (xs : List Nat) :
    (insertRun x xs).2 ≤ xs.length := by
  induction xs with
  | nil => simp [insertRun]
  | cons y ys ih => simp only [insertRun]; split <;> simp_all

theorem insertionRun_comparisons_le (xs : List Nat) :
    (insertionRun xs).2 ≤ xs.length.choose 2 := by
  induction xs with
  | nil => simp [insertionRun]
  | cons x xs ih =>
      have hi := insertRun_comparisons_le x (insertionRun xs).1
      simp only [insertionRun_result, List.length_insertionSort] at hi
      simp only [insertionRun, List.length_cons, Nat.choose_succ_succ, Nat.choose_one_right]
      change (insertionRun xs).2 + (insertRun x (insertionRun xs).1).2 ≤
        xs.length + xs.length.choose 2
      rw [insertionRun_result]
      omega

/-- Sort each bucket with the counted implementation and collect its result. -/
def bucketComparisonRun (xs : List Nat) : List Nat × Nat :=
  let runs := (distribute xs).toList.map insertionRun
  (runs.flatMap Prod.fst, xs.length + (runs.map Prod.snd).sum)

@[simp] theorem bucketComparisonRun_result (xs : List Nat) :
    (bucketComparisonRun xs).1 = bucketSortResult xs := by
  simp [bucketComparisonRun, bucketSortResult, bucketOutput, List.flatMap_map,
    Function.comp_def]

/-- Includes one maximum-key comparison per input occurrence, in addition to
the exact comparisons of every bucket's insertion sort. -/
def bucketComparisonCost (xs : List Nat) : Nat := (bucketComparisonRun xs).2

theorem choose_two_add (m n : Nat) :
    (m + n).choose 2 = m.choose 2 + n.choose 2 + m * n := by
  induction n with
  | zero => simp
  | succ n ih =>
      simp only [Nat.add_succ, Nat.choose_succ_succ, Nat.choose_one_right]
      change m + n + (m + n).choose 2 = m.choose 2 + (n + n.choose 2) + m * (n + 1)
      rw [ih]
      simp only [Nat.mul_add, Nat.mul_one]
      omega

theorem sum_insertionComparisons_le (buckets : List (List Nat)) :
    (buckets.map (fun bucket => (insertionRun bucket).2)).sum ≤
      (buckets.map (fun bucket => bucket.length.choose 2)).sum := by
  induction buckets with
  | nil => simp
  | cons b bs ih => simpa using Nat.add_le_add (insertionRun_comparisons_le b) ih

theorem sum_bucket_choose_le (buckets : List (List Nat)) :
    (buckets.map (fun bucket => bucket.length.choose 2)).sum ≤ buckets.flatten.length.choose 2 := by
  induction buckets with
  | nil => simp
  | cons b bs ih =>
      simp only [List.map_cons, List.sum_cons, List.flatten_cons, List.length_append,
        choose_two_add]
      omega

/-- Distribution-sensitive bound: the quadratic term is per bucket. -/
theorem bucketComparisonCost_le_bucketSizes (xs : List Nat) :
    bucketComparisonCost xs ≤ xs.length +
      ((distribute xs).toList.map (fun bucket => bucket.length.choose 2)).sum := by
  simpa [bucketComparisonCost, bucketComparisonRun, List.map_map, Function.comp_def] using
    Nat.add_le_add_left (sum_insertionComparisons_le (distribute xs).toList) xs.length

/-- Unconditional upper bound; no probability or balance assumption is needed. -/
theorem bucketComparisonCost_le (xs : List Nat) :
    bucketComparisonCost xs ≤ xs.length + xs.length.choose 2 := by
  have h := sum_bucket_choose_le (distribute xs).toList
  rw [(distribute_flatten_perm xs).length_eq] at h
  exact (bucketComparisonCost_le_bucketSizes xs).trans (Nat.add_le_add_left h xs.length)

def bucketPlacementCost (xs : List Nat) : Nat := (bucketSortTrace xs).length

@[simp] theorem bucketPlacementCost_eq_length (xs : List Nat) :
    bucketPlacementCost xs = xs.length := bucketSortTrace_length xs

theorem bucketCount_le_length_add_one (xs : List Nat) : bucketCount xs ≤ xs.length + 1 := by
  simp only [bucketCount]; omega

/-- Total number of stored occurrences in the allocated buckets. -/
theorem bucketLengths_sum (xs : List Nat) :
    ((distribute xs).toList.map List.length).sum = xs.length := by
  simpa only [List.length_flatten] using (distribute_flatten_perm xs).length_eq

end LeanSort.Bucket
