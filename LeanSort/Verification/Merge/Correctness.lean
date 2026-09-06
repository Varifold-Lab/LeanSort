import LeanSort.Model.SortingResult
import LeanSort.Algorithm.Merge

/-! Sorting correctness, supplied by CSlib. -/

namespace LeanSort.Merge

theorem mergeSortResult_spec {α : Type} [LinearOrder α] (xs : List α) :
    IsSortingResult (· ≤ ·) xs (mergeSortResult xs) :=
  Cslib.Algorithms.Lean.TimeM.mergeSort_correct xs

theorem sorted_mergeSortResult {α : Type} [LinearOrder α] (xs : List α) :
    (mergeSortResult xs).Pairwise (· ≤ ·) :=
  (mergeSortResult_spec xs).1

theorem mergeSortResult_perm {α : Type} [LinearOrder α] (xs : List α) :
    (mergeSortResult xs).Perm xs :=
  (mergeSortResult_spec xs).2

end LeanSort.Merge
