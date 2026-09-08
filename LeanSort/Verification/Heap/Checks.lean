import LeanSort.Verification.Heap.Trace
import LeanSort.Verification.Heap.Cost

/-! Regression checks for the proved sorting result, extraction replay, and the
comparison-counted execution, including malformed traces and small exhaustive inputs. -/

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

-- Extraction values and post-extraction sizes, including repeated values.
#guard heapSortTrace [2, 1, 2, 0] = [⟨0, 3⟩, ⟨1, 2⟩, ⟨2, 1⟩, ⟨2, 0⟩]
#guard replayHeap? [] ([] : List Nat) = some []
#guard replayHeap? [] [1] = none
#guard replayHeap? [⟨1, 0⟩] ([] : List Nat) = none
#guard replayHeap? [⟨1, 0⟩, ⟨1, 0⟩] [1] = none
#guard replayHeap? [⟨2, 0⟩] [1] = none
#guard replayHeap? [⟨1, 1⟩] [1] = none
#guard replayHeap? [⟨1, 1⟩, ⟨1, 1⟩] [1, 1] = none

-- All 364 lists of length at most five over {0, 1, 2}.
#guard (List.range 6).all fun n =>
  ((List.replicate n [0, 1, 2]).sections).all fun xs =>
    let (result, trace) := sortTrace xs
    result == xs.mergeSort &&
      replayHeap? trace xs == some result &&
      heapExtractionCost xs == xs.length &&
      (heapComparisonRun xs).1 == result &&
      heapComparisonCost xs ≤ 4 * xs.length * (xs.length.log2 + 1)

-- No key comparisons for empty/singleton heaps; one for either two-element order.
#guard heapComparisonCost ([] : List Nat) = 0
#guard heapComparisonCost [7] = 0
#guard heapComparisonCost [1, 2] = 1
#guard heapComparisonCost [2, 1] = 1
#guard heapComparisonCost [3, 2, 1] = 3

-- Exercise both child branches and incomplete last levels at larger heap sizes.
#guard [7, 8, 9, 31, 32, 33, 63, 64, 65].all fun n =>
  [List.range n, (List.range n).reverse, List.replicate n 4].all fun xs =>
    (heapComparisonRun xs).1 == xs.mergeSort &&
      heapComparisonCost xs ≤ 4 * n * (n.log2 + 1)

#guard (heapComparisonRun ([-2, 3, 0, -2] : List Int)).1 = [-2, -2, 0, 3]

end LeanSort.Heap
