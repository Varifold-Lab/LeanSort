import LeanSort.Algorithm.Bubble

namespace LeanSort.Bubble

/-! Executable checks for instrumented bubble sort. -/

#guard bubbleSortResult [3, 1, 2] = [1, 2, 3]
#guard bubbleSortTrace [3, 1, 2] = [0, 1]
#guard replay (bubbleSortTrace [3, 1, 2]) [3, 1, 2] = bubbleSortResult [3, 1, 2]

#guard bubbleSortResult [2, 1, 2, 1] = [1, 1, 2, 2]
#guard bubbleSortTrace [2, 1, 2, 1] = [0, 2, 1]
#guard replay (bubbleSortTrace [2, 1, 2, 1]) [2, 1, 2, 1] =
  bubbleSortResult [2, 1, 2, 1]

#guard bubbleSortTrace [1, 2, 3, 4] = []

#guard bubbleSortResult ([-2, 3, 0, -2] : List Int) = [-2, -2, 0, 3]
#guard replay (bubbleSortTrace ([-2, 3, 0, -2] : List Int)) [-2, 3, 0, -2] =
  bubbleSortResult [-2, 3, 0, -2]

end LeanSort.Bubble
