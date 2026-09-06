import LeanSort.Algorithm.Insertion

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

end LeanSort.Insertion
