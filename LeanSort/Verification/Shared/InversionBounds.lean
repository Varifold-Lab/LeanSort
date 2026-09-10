import LeanSort.Model.Inversions
import LeanSort.Verification.Shared.RearrangementLemmas
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

/-- Sorted lists have no inversions. -/
theorem inversions_eq_zero_of_pairwise {α : Type*} [LinearOrder α]
    {xs : List α} (hs : xs.Pairwise (· ≤ ·)) : inversions xs = 0 := by
  induction xs with
  | nil => rfl
  | cons x xs ih =>
    rw [inversions_cons, ih hs.of_cons, Nat.add_zero, List.countP_eq_zero]
    intro y hy
    simp only [decide_eq_true_eq]
    exact not_lt_of_ge (List.rel_of_pairwise_cons hs hy)

/-- One adjacent transposition can remove at most one inversion, including when
the index is out of range and the transposition acts as the identity. -/
theorem inversions_le_adjacent_add_one {α : Type*} [LinearOrder α]
    (i : ℕ) (xs : List α) :
    inversions xs ≤ inversions (Rearrangement.AdjacentTransposition.apply i xs) + 1 := by
  induction i generalizing xs with
  | zero =>
    cases xs with
    | nil => simp [inversions]
    | cons x xs =>
      cases xs with
      | nil => simp [inversions]
      | cons y ys =>
        change inversions (x :: y :: ys) ≤ inversions (y :: x :: ys) + 1
        simp only [inversions_cons, List.countP_cons]
        split_ifs <;> omega
  | succ i ih =>
    cases xs with
    | nil => simp [inversions]
    | cons x xs =>
      change inversions (x :: xs) ≤
        inversions (x :: Rearrangement.AdjacentTransposition.apply i xs) + 1
      simp only [inversions_cons]
      have hc := (List.swap_perm xs i (i + 1)).countP_eq (fun y => decide (y < x))
      change (Rearrangement.AdjacentTransposition.apply i xs).countP _ = xs.countP _ at hc
      rw [hc]
      have := ih xs
      omega

/-- Every adjacent-swap word pays for any inversions it removes. -/
theorem inversions_le_replay_add_length {α : Type*} [LinearOrder α]
    (trace : List Rearrangement.AdjacentTransposition.Gen) (xs : List α) :
    inversions xs ≤ inversions (Rearrangement.replay
      Rearrangement.AdjacentTransposition.apply trace xs) + trace.length := by
  induction trace generalizing xs with
  | nil => simp
  | cons i trace ih =>
    have hstep := inversions_le_adjacent_add_one i xs
    have hrest := ih (Rearrangement.AdjacentTransposition.apply i xs)
    simp only [Rearrangement.replay_cons, List.length_cons]
    omega

end LeanSort
