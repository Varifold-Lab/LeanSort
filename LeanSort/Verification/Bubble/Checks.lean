import LeanSort.Verification.Bubble.Trace

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

-- Exercise the bounded interface, including empty, singleton, and duplicate-heavy inputs.
#guard (List.range 6).all fun len =>
  (List.replicate len [0, 1, 2]).sections.all fun xs =>
    let result := bubbleSortResult xs
    result == xs.mergeSort && replayBounded xs (bubbleSortTraceBounded xs) == result

end LeanSort.Bubble
