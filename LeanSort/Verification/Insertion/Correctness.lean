import LeanSort.Model.SortingResult
import LeanSort.Verification.Insertion.Equations

/-! Correctness of the list produced by instrumented insertion sort. -/

namespace LeanSort.Insertion

open List

theorem insertTr_fst {α : Type*} [LinearOrder α] (off : ℕ) (x : α) (s : List α) :
    (insertTr off x s).1 = s.orderedInsert (· ≤ ·) x := by
  induction s generalizing off with
  | nil => rfl
  | cons y ys ih =>
      by_cases h : x ≤ y
      · simp [insertTr_cons_of_le h, h]
      · simp [insertTr_cons_of_gt h, h, ih]

theorem sortTr_fst {α : Type*} [LinearOrder α] (off : ℕ) (l : List α) :
    (sortTr off l).1 = l.insertionSort (· ≤ ·) := by
  induction l generalizing off with
  | nil => rfl
  | cons x l ih => simp [sortTr_cons, insertTr_fst, ih]

theorem insertionSortResult_eq {α : Type*} [LinearOrder α] (l : List α) :
    insertionSortResult l = l.insertionSort (· ≤ ·) := sortTr_fst 0 l

theorem sorted_insertionSortResult {α : Type*} [LinearOrder α] (l : List α) :
    (insertionSortResult l).Pairwise (· ≤ ·) := by
  rw [insertionSortResult_eq]
  exact pairwise_insertionSort _ l

theorem insertionSortResult_perm {α : Type*} [LinearOrder α] (l : List α) :
    insertionSortResult l ~ l := by
  rw [insertionSortResult_eq]
  exact perm_insertionSort _ l

theorem insertionSortResult_spec {α : Type*} [LinearOrder α] (l : List α) :
    IsSortingResult (· ≤ ·) l (insertionSortResult l) :=
  ⟨sorted_insertionSortResult l, insertionSortResult_perm l⟩

end LeanSort.Insertion
