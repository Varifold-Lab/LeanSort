import Batteries.Data.BinaryHeap
import Mathlib.Order.Defs.LinearOrder

/-! Binary-heap sorting, reusing Batteries' array implementation. -/

namespace LeanSort.Heap

/-- Ascending heap sort through an array-backed binary heap.
The library collects extracted minima into a separate output array; this API
does not claim an in-place or constant-extra-space implementation. -/
def heapSortResult {α : Type} [LinearOrder α] (xs : List α) : List α :=
  (xs.toArray.heapSort (fun x y => decide (x < y))).toList

end LeanSort.Heap
