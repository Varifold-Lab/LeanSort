import LeanSort.Algorithm.Quick

namespace LeanSort.Quick

@[simp] theorem quickSortResult_nil {α : Type*} [LinearOrder α] :
    quickSortResult ([] : List α) = [] := by rw [quickSortResult]

theorem quickSortResult_cons {α : Type*} [LinearOrder α] (pivot : α) (xs : List α) :
    quickSortResult (pivot :: xs) =
      quickSortResult (xs.partition (fun x => decide (x ≤ pivot))).1 ++
        pivot :: quickSortResult (xs.partition (fun x => decide (x ≤ pivot))).2 := by
  rw [quickSortResult]

end LeanSort.Quick
