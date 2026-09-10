import LeanSort.Verification.Quick.Trace
import Mathlib.Tactic.Linarith

/-! Comparison cost of deterministic first-pivot quicksort.
This excludes list allocation, concatenation, and trace/replay overhead. -/

namespace LeanSort.Quick

def comparisonCost {α : Type*} [LinearOrder α] (xs : List α) : Nat :=
  (quickSortTr xs).2.comparisons

@[simp] theorem comparisonCost_nil {α : Type*} [LinearOrder α] :
    comparisonCost ([] : List α) = 0 := by
  simp [comparisonCost, Trace.comparisons]

theorem comparisonCost_cons {α : Type*} [LinearOrder α] (p : α) (xs : List α) :
    comparisonCost (p :: xs) = xs.length +
      comparisonCost (xs.partition (fun x => decide (x ≤ p))).1 +
      comparisonCost (xs.partition (fun x => decide (x ≤ p))).2 := by
  simp [comparisonCost, quickSortTr_cons, Trace.comparisons]

/-- Every input occurrence becomes exactly one pivot, including duplicates. -/
theorem quickSortTr_pivots {α : Type*} [LinearOrder α] (xs : List α) :
    (quickSortTr xs).2.pivots = xs.length := by
  induction xs using quickSortResult_induct with
  | case1 => simp [Trace.pivots]
  | case2 p xs ihl ihr =>
      let parts := xs.partition (fun x => decide (x ≤ p))
      have h := (partition_spec p xs).perm.length_eq
      simp only [List.length_append] at h
      simp only [quickSortTr_cons, Trace.pivots]
      change (quickSortTr parts.1).2.pivots + 1 + (quickSortTr parts.2).2.pivots = _
      rw [ihl, ihr]
      simp only [List.length_cons]
      omega

/-- Division-free triangular bound: at most n*(n-1)/2 comparisons. -/
theorem comparisonCost_bound {α : Type*} [LinearOrder α] (xs : List α) :
    2 * comparisonCost xs + xs.length ≤ xs.length * xs.length := by
  induction xs using quickSortResult_induct with
  | case1 => simp
  | case2 p xs ihl ihr =>
      let parts := xs.partition (fun x => decide (x ≤ p))
      have h := (partition_spec p xs).perm.length_eq
      simp only [List.length_append] at h
      rw [comparisonCost_cons]
      simp only [List.length_cons]
      change 2 * (xs.length + comparisonCost parts.1 + comparisonCost parts.2) +
        (xs.length + 1) ≤ (xs.length + 1) * (xs.length + 1)
      change parts.1.length + parts.2.length = xs.length at h
      nlinarith [Nat.zero_le (parts.1.length * parts.2.length)]

theorem comparisonCost_le_triangular {α : Type*} [LinearOrder α] (xs : List α) :
    comparisonCost xs ≤ xs.length * (xs.length - 1) / 2 := by
  have h := comparisonCost_bound xs
  cases xs with
  | nil => simp
  | cons p xs =>
      simp only [List.length_cons, Nat.add_sub_cancel] at *
      apply (Nat.le_div_iff_mul_le (by omega)).mpr
      nlinarith

end LeanSort.Quick
