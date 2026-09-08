import LeanSort.Verification.Heap.Correctness

/-! Exact extraction count. Each root removal costs one unit here; building the
heap, comparisons, internal swaps, and trace construction are not charged. -/

namespace LeanSort.Heap

variable {α : Type} [LinearOrder α]

@[simp] theorem heapSortTrace_length (xs : List α) :
    (heapSortTrace xs).length = xs.length := by
  simpa only [List.length_map, heapSortResult_length] using
    congrArg List.length (heapSortTrace_values xs)

/-- Number of root extractions, not the total work performed inside them. -/
def heapExtractionCost (xs : List α) : Nat := (heapSortTrace xs).length

@[simp] theorem heapExtractionCost_eq_length (xs : List α) :
    heapExtractionCost xs = xs.length := heapSortTrace_length xs

end LeanSort.Heap
