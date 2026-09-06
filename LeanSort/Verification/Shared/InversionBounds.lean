import LeanSort.Model.Inversions
import Mathlib.Data.Nat.Choose.Basic

/-! Shared inversion equations, extremal bounds, and a worst-case witness. -/

namespace LeanSort

@[simp] theorem inversions_nil {α : Type*} [LinearOrder α] :
    inversions ([] : List α) = 0 := rfl

@[simp] theorem inversions_cons {α : Type*} [LinearOrder α] (x : α) (l : List α) :
    inversions (x :: l) = l.countP (fun y => decide (y < x)) + inversions l := rfl

/-- The canonical reverse-ordered list `[n - 1, ..., 1, 0]` of length `n`. -/
def descendingRange (n : ℕ) : List ℕ :=
  (List.range n).reverse

@[simp] theorem descendingRange_zero : descendingRange 0 = [] := rfl

@[simp] theorem descendingRange_succ (n : ℕ) :
    descendingRange (n + 1) = n :: descendingRange n := by
  simp [descendingRange, List.range_succ]

@[simp] theorem length_descendingRange (n : ℕ) :
    (descendingRange n).length = n := by
  simp [descendingRange]

@[simp] theorem mem_descendingRange {k n : ℕ} :
    k ∈ descendingRange n ↔ k < n := by
  simp [descendingRange]

/-- `descendingRange n` is strictly decreasing, so every pair of positions is inverted. -/
theorem descendingRange_pairwise_gt (n : ℕ) :
    (descendingRange n).Pairwise (· > ·) := by
  induction n with
  | zero => simp
  | succ n ih =>
      rw [descendingRange_succ]
      simp only [List.pairwise_cons]
      exact ⟨fun k hk => mem_descendingRange.mp hk, ih⟩

/-- A list has at most one inversion for each pair of positions. -/
theorem inversions_le_choose_two {α : Type*} [LinearOrder α] (l : List α) :
    inversions l ≤ l.length.choose 2 := by
  induction l with
  | nil => simp
  | cons x l ih =>
      rw [inversions_cons, List.length_cons, Nat.choose_succ_succ]
      simpa using Nat.add_le_add
        (List.countP_le_length (l := l) (p := fun y => decide (y < x))) ih

/-- Every pair of positions in a strictly decreasing list is an inversion. -/
theorem inversions_eq_choose_two_of_pairwise_gt {α : Type*} [LinearOrder α]
    {l : List α} (hl : l.Pairwise (· > ·)) :
    inversions l = l.length.choose 2 := by
  induction l with
  | nil => simp
  | cons x l ih =>
      rw [inversions_cons, List.length_cons, Nat.choose_succ_succ]
      have hcount : l.countP (fun y => decide (y < x)) = l.length := by
        apply List.countP_eq_length.mpr
        intro y hy
        simp only [decide_eq_true_eq]
        exact List.rel_of_pairwise_cons hl hy
      rw [hcount, ih hl.of_cons]
      simp

/-- The canonical reverse-ordered list attains the maximum possible inversion count. -/
@[simp] theorem inversions_descendingRange (n : ℕ) :
    inversions (descendingRange n) = n.choose 2 := by
  simpa using
    inversions_eq_choose_two_of_pairwise_gt (descendingRange_pairwise_gt n)

end LeanSort
