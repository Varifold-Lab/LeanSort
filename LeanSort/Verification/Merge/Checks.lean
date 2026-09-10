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

-- Ties go left; a suffix consumes no comparisons, even if it is unsorted.
#guard replayMerge? [.takeLeft] [2] [2] = some [2, 2]
#guard replayMerge? [.takeRight] [2] [2] = none
#guard replayMerge? [] ([] : List Nat) [3, 1] = some [3, 1]
#guard replayMerge? [.takeLeft, .takeRight] [1] [2] = none
#guard replayMerge? [.takeLeft] [1, 3] [2, 4] = none

-- All pairs of runs of length at most three over {0, 1, 2} (1,600 pairs).
-- Check both unsorted runs and sorted runs; legal replay alone need not sort.
#guard (List.range 4).all fun n =>
  ((List.replicate n [0, 1, 2]).sections).all fun left =>
    (List.range 4).all fun m =>
      ((List.replicate m [0, 1, 2]).sections).all fun right =>
        let (result, trace) := mergeTr left right
        result == left.merge right &&
          replayMerge? trace left right == some result &&
          replayMerge? (trace ++ [.takeLeft]) left right == none

-- Whole-sort certificate agrees with the public output and comparison model.
#guard (List.range 6).all fun n =>
  ((List.replicate n [0, 1, 2]).sections).all fun xs =>
    let cert := mergeSortCertificate xs
    cert.output == xs.mergeSort &&
      cert.trace == mergeSortTrace xs &&
      cert.trace.length == mergeComparisonCost xs

end LeanSort.Merge
