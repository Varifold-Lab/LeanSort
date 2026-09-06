import LeanSort.Verification.Merge.Trace

namespace LeanSort.Merge

#guard mergeTr [1, 3] [2, 4] =
  ([1, 2, 3, 4], [Choice.takeLeft, Choice.takeRight, Choice.takeLeft])

#guard mergeSortResult [3, 1, 2] = [1, 2, 3]
#guard mergeSortTrace [3, 1, 2] =
  [Choice.takeLeft, Choice.takeRight, Choice.takeRight]

#guard mergeSortResult [2, 1, 2, 1] = [1, 1, 2, 2]
#guard mergeSortTrace [2, 1, 2, 1] =
  [Choice.takeRight, Choice.takeRight, Choice.takeLeft, Choice.takeRight, Choice.takeLeft]

#guard mergeSortResult [1, 2, 3, 4] = [1, 2, 3, 4]
#guard mergeSortResult ([-2, 3, 0, -2] : List Int) = [-2, -2, 0, 3]

#guard mergeSortResult ([] : List Nat) = []
#guard mergeSortResult [7] = [7]
#guard mergeComparisonCost ([] : List Nat) = 0
#guard mergeComparisonCost [7] = 0
#guard mergeComparisonCost [3, 1, 2] = 3
#guard replayMerge? [Choice.takeLeft, Choice.takeRight, Choice.takeLeft]
  [1, 3] [2, 4] = some [1, 2, 3, 4]
#guard replayMerge? [] [1] [2] = none
#guard replayMerge? [Choice.takeRight] [1] [2] = none
#guard replayMerge? [Choice.takeLeft] ([] : List Nat) [2] = none
#guard replayMerge? [] ([] : List Nat) [2] = some [2]

end LeanSort.Merge
