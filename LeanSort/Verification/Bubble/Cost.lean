import LeanSort.Verification.Bubble.Correctness
import LeanSort.Verification.Shared.InversionBounds

namespace LeanSort.Bubble

open List

/-! The number of adjacent transpositions performed by bubble sort. -/

/-- The swap cost recorded in the bubble-sort rearrangement trace. -/
def bubbleSwapCost {α : Type*} [LinearOrder α] (xs : List α) : ℕ :=
  (bubbleSortTrace xs).length

/-- One bubble-pass continuation accounts for every inversion it removes: the emitted
adjacent swaps plus the inversions remaining in its output equal the inversions in its
input. -/
theorem length_passAuxTr_snd_add_inversions_fst {α : Type*} [LinearOrder α]
    (off : ℕ) (x : α) (xs : List α) :
    (passAuxTr off x xs).2.length + inversions (passAuxTr off x xs).1 =
      inversions (x :: xs) := by
  induction xs generalizing off x with
  | nil => simp
  | cons y ys ih =>
      by_cases hxy : x ≤ y
      · rw [passAuxTr_cons_of_le hxy]
        simp only
        rw [inversions_cons x (passAuxTr (off + 1) y ys).1,
          inversions_cons x (y :: ys)]
        have hcount := (passAuxTr_fst_perm (off + 1) y ys).countP_eq
          (fun z => decide (z < x))
        have hrec := ih (off + 1) y
        omega
      · have hyx : y < x := lt_of_not_ge hxy
        rw [passAuxTr_cons_of_gt hxy]
        simp only [List.length_cons]
        rw [inversions_cons y (passAuxTr (off + 1) x ys).1,
          inversions_cons x (y :: ys), inversions_cons y ys]
        have hcount := (passAuxTr_fst_perm (off + 1) x ys).countP_eq
          (fun z => decide (z < y))
        have hrec := ih (off + 1) x
        simp [hyx, not_lt_of_ge (le_of_lt hyx), inversions_cons] at hcount hrec ⊢
        omega

/-- One full bubble pass has the same cost/inversion accounting invariant. -/
theorem length_passTr_snd_add_inversions_fst {α : Type*} [LinearOrder α]
    (off : ℕ) (xs : List α) :
    (passTr off xs).2.length + inversions (passTr off xs).1 = inversions xs := by
  cases xs with
  | nil => simp
  | cons x xs => exact length_passAuxTr_snd_add_inversions_fst off x xs

/-- Across any number of passes, emitted swaps plus remaining inversions equal the
original inversion count. -/
theorem length_sortAuxTr_snd_add_inversions_fst {α : Type*} [LinearOrder α]
    (passes : ℕ) (xs : List α) :
    (sortAuxTr passes xs).2.length + inversions (sortAuxTr passes xs).1 =
      inversions xs := by
  induction passes generalizing xs with
  | zero => simp
  | succ passes ih =>
      rw [sortAuxTr_succ, List.length_append]
      simp only
      have hpass := length_passTr_snd_add_inversions_fst 0 xs
      have hrest := ih (passTr 0 xs).1
      omega

/-- A sorted list has no inversions. -/
theorem inversions_eq_zero_of_pairwise {α : Type*} [LinearOrder α]
    {xs : List α} (hs : xs.Pairwise (· ≤ ·)) :
    inversions xs = 0 := by
  induction xs with
  | nil => rfl
  | cons x xs ih =>
      rw [inversions_cons, ih hs.of_cons, Nat.add_zero, List.countP_eq_zero]
      intro y hy
      simp only [decide_eq_true_eq]
      exact not_lt_of_ge (rel_of_pairwise_cons hs hy)

/-- Bubble sort performs exactly one adjacent swap per inversion in the input. -/
theorem length_bubbleSortTrace {α : Type*} [LinearOrder α] (xs : List α) :
    (bubbleSortTrace xs).length = inversions xs := by
  have haccount := length_sortAuxTr_snd_add_inversions_fst xs.length xs
  have hsorted : inversions (bubbleSortResult xs) = 0 :=
    inversions_eq_zero_of_pairwise (sorted_bubbleSortResult xs)
  change inversions (sortAuxTr xs.length xs).1 = 0 at hsorted
  change (sortAuxTr xs.length xs).2.length = inversions xs
  omega

/-- The finite swap cost is exactly the input inversion count. -/
@[simp] theorem bubbleSwapCost_eq_inversions {α : Type*} [LinearOrder α]
    (xs : List α) : bubbleSwapCost xs = inversions xs :=
  length_bubbleSortTrace xs

end LeanSort.Bubble
