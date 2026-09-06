import LeanSort.Algorithm.Heap
import Mathlib.Data.List.Sort

/-! Executable regression checks; not a universal correctness proof. -/

namespace LeanSort.Heap

#guard heapSortResult ([] : List Nat) = []
#guard heapSortResult [7] = [7]
#guard heapSortResult [1, 2, 3, 4] = [1, 2, 3, 4]
#guard heapSortResult [4, 3, 2, 1] = [1, 2, 3, 4]
#guard heapSortResult [2, 1, 2, 1] = [1, 1, 2, 2]
#guard heapSortResult [2, 2, 2] = [2, 2, 2]
#guard heapSortResult ([-2, 3, 0, -2] : List Int) = [-2, -2, 0, 3]

-- All 243 length-five lists over {0, 1, 2}, compared with library merge sort.
#guard (List.range 243).all fun n =>
  let xs := List.ofFn (fun i : Fin 5 => n / 3 ^ i.val % 3)
  heapSortResult xs == xs.mergeSort

end LeanSort.Heap
