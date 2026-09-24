import LeanSort.Verification.Intro.Equations
import LeanSort.Verification.Heap.Correctness

namespace LeanSort.Intro

variable {α : Type} [LinearOrder α]

theorem introSortAux_perm (cutoff depth : Nat) (xs : List α) :
    (introSortAux cutoff depth xs).Perm xs := by
  induction depth generalizing xs with
  | zero => exact LeanSort.Heap.heapSortResult_perm xs
  | succ depth ih =>
    by_cases h : xs.length ≤ cutoff
    · rw [introSortAux_small cutoff depth xs h]
      exact List.perm_insertionSort _ _
    · cases xs with
      | nil => simp at h
      | cons p rest =>
        rw [introSortAux_partition cutoff depth p rest (by omega)]
        apply ((ih _).append ((ih _).cons p)).trans
        exact List.perm_middle.trans ((LeanSort.Quick.partition_spec p rest).perm.cons p)

theorem sorted_introSortAux (cutoff depth : Nat) (xs : List α) :
    (introSortAux cutoff depth xs).Pairwise (· ≤ ·) := by
  induction depth generalizing xs with
  | zero => exact LeanSort.Heap.heapSortResult_sorted xs
  | succ depth ih =>
    by_cases h : xs.length ≤ cutoff
    · rw [introSortAux_small cutoff depth xs h]
      exact List.pairwise_insertionSort _ _
    · cases xs with
      | nil => simp at h
      | cons p rest =>
        let parts := rest.partition (fun x => decide (x ≤ p))
        have hl : ∀ x ∈ introSortAux cutoff depth parts.1, x ≤ p := by
          intro x hx
          exact (LeanSort.Quick.partition_spec p rest).left_bound x
            ((introSortAux_perm cutoff depth parts.1).mem_iff.mp hx)
        have hr : ∀ x ∈ introSortAux cutoff depth parts.2, p ≤ x := by
          intro x hx
          exact le_of_lt ((LeanSort.Quick.partition_spec p rest).right_bound x
            ((introSortAux_perm cutoff depth parts.2).mem_iff.mp hx))
        rw [introSortAux_partition cutoff depth p rest (by omega)]
        apply List.pairwise_append.mpr
        refine ⟨ih _, List.pairwise_cons.mpr ⟨hr, ih _⟩, ?_⟩
        intro a ha b hb
        rcases List.mem_cons.mp hb with rfl | hb
        · exact hl a ha
        · exact le_trans (hl a ha) (hr b hb)

theorem introSortAux_spec (cutoff depth : Nat) (xs : List α) :
    IsSortingResult (· ≤ ·) xs (introSortAux cutoff depth xs) :=
  ⟨sorted_introSortAux cutoff depth xs, introSortAux_perm cutoff depth xs⟩

theorem introSortResult_spec (xs : List α) :
    IsSortingResult (· ≤ ·) xs (introSortResult xs) := introSortAux_spec _ _ _

theorem introSortResult_perm (xs : List α) : (introSortResult xs).Perm xs :=
  introSortAux_perm _ _ _

theorem sorted_introSortResult (xs : List α) :
    (introSortResult xs).Pairwise (· ≤ ·) := (introSortResult_spec xs).1

@[simp] theorem introSortAux_length (cutoff depth : Nat) (xs : List α) :
    (introSortAux cutoff depth xs).length = xs.length := (introSortAux_perm _ _ _).length_eq

@[simp] theorem introSortResult_length (xs : List α) :
    (introSortResult xs).length = xs.length := (introSortResult_perm xs).length_eq

end LeanSort.Intro
