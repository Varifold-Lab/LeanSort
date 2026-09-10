import LeanSort.Verification.Insertion.Cost

/-! Executable checks for insertion sort and its adjacent-transposition trace. -/

namespace LeanSort.Insertion

#guard insertionSortResult [3, 1, 2] = [1, 2, 3]
#guard insertionSortTrace [3, 1, 2] = [0, 1]

#guard insertionSortResult [5, 4, 3, 2, 1] = [1, 2, 3, 4, 5]
#guard (insertionSortTrace [5, 4, 3, 2, 1]).length = 10

#guard insertionSortTrace [1, 2, 3] = []

#guard insertionSortResult ([-2, 3, 0] : List Int) = [-2, 0, 3]

#guard insertionSortResult [2, 7, 1, 8, 2, 8] = [1, 2, 2, 7, 8, 8]
#guard insertionSortTrace [2, 7, 1, 8, 2, 8] = [3, 1, 2, 0]

#guard replay (insertionSortTrace [3, 1, 2]) [3, 1, 2] = [1, 2, 3]
#guard replay (insertionSortTrace [2, 7, 1, 8, 2, 8]) [2, 7, 1, 8, 2, 8] =
  [1, 2, 2, 7, 8, 8]
#guard replay (insertionSortTrace [5, 4, 3, 2, 1]) [5, 4, 3, 2, 1] =
  [1, 2, 3, 4, 5]

-- Nonzero offsets, stopping at equal keys, and insertion into an unsorted block.
#guard insertTr 2 3 [1, 2, 4] = ([1, 2, 3, 4], [2, 3])
#guard replay [2, 3] [9, 8, 3, 1, 2, 4] = [9, 8, 1, 2, 3, 4]
#guard insertTr 0 2 [1, 2, 2] = ([1, 2, 2, 2], [0])
#guard insertTr 0 2 [3, 1, 4] = ([2, 3, 1, 4], [])
#guard insertionSortTrace [3, 2, 1] = [1, 0, 1]

-- All 364 lists of length at most five over {0, 1, 2}.
#guard (List.range 6).all fun n =>
  ((List.replicate n [0, 1, 2]).sections).all fun xs =>
    let result := insertionSortResult xs
    result == xs.mergeSort &&
      replay (insertionSortTrace xs) xs == result &&
      replayBounded xs (insertionSortBoundedTrace xs) == result &&
      insertionSwapCost xs == inversions xs

end LeanSort.Insertion
