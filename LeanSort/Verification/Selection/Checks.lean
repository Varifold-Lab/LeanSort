import LeanSort.Algorithm.Selection

/-! # Executable checks for selection sort -/

namespace LeanSort.Selection

#guard selectionSortResult [3, 1, 2] = [1, 2, 3]
#guard selectionSortTrace [3, 1, 2] = [(0, 1), (1, 2)]
#guard replay (selectionSortTrace [3, 1, 2]) [3, 1, 2] =
  selectionSortResult [3, 1, 2]

#guard selectionSortResult [2, 1, 2, 1] = [1, 1, 2, 2]
#guard selectionSortTrace [2, 1, 2, 1] = [(0, 1), (1, 3)]
#guard replay (selectionSortTrace [2, 1, 2, 1]) [2, 1, 2, 1] =
  selectionSortResult [2, 1, 2, 1]

#guard selectionSortResult [1, 2, 3, 4] = [1, 2, 3, 4]
#guard selectionSortTrace [1, 2, 3, 4] = []

#guard selectionSortResult ([-2, 3, 0, -2] : List Int) = [-2, -2, 0, 3]
#guard replay (selectionSortTrace ([-2, 3, 0, -2] : List Int)) [-2, 3, 0, -2] =
  selectionSortResult [-2, 3, 0, -2]

end LeanSort.Selection
