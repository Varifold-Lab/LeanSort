import LeanSort.Verification.Bucket.Complexity

/-! Regressions for interval boundaries, sparse keys, exact costs, and strict logs. -/

namespace LeanSort.Bucket

example (xs : List Nat) : IsSortingResult (· ≤ ·) xs (bucketSortResult xs) :=
  bucketSortResult_spec xs

example (xs : List Nat) (x : Nat) (hx : x ∈ xs) :
    x / bucketWidth xs < (distribute xs).size := by
  simpa using bucketIndex_lt xs x hx

#guard bucketSortResult [] = []
#guard bucketSortResult [7] = [7]
#guard bucketSortResult [3, 1, 2, 1] = [1, 1, 2, 3]
#guard bucketSortResult [10 ^ 30, 0, 1, 10 ^ 30, 10 ^ 15] =
  [0, 1, 10 ^ 15, 10 ^ 30, 10 ^ 30]
#guard (distribute [10 ^ 30, 0, 1]).size = 3
#guard distribute [7, 6, 1, 0] = #[[1, 0], [], [], [7, 6]]
#guard distribute [5, 0, 4, 1, 3, 2] = #[[0], [1], [2], [3], [4], [5]]
#guard bucketSortTrace [7, 6, 1, 0] = [(7, 3), (6, 3), (1, 0), (0, 0)]
#guard replayChecked? (bucketSortTrace [7, 6, 1, 0]) [7, 6, 1, 0] = some [0, 1, 6, 7]
#guard replayChecked? [] [] = some []
-- Missing, extra, altered-key, wrong-bucket, and out-of-range events.
#guard replayChecked? [] [7] = none
#guard replayChecked? [(7, 0)] [] = none
#guard replayChecked? [(8, 0)] [7] = none
#guard replayChecked? [(7, 1)] [7] = none
#guard replayChecked? [(7, 100)] [7] = none
#guard replayChecked? [(7, 0), (7, 0)] [7] = none
#guard replayScatter? 2 [8] [(8, 4)] #[[], [], [], []] = none

#guard insertRun 4 [1, 2, 3] = ([1, 2, 3, 4], 3)
#guard insertRun 0 [1, 2, 3] = ([0, 1, 2, 3], 1)
#guard insertRun 1 [1, 1] = ([1, 1, 1], 1)
#guard bucketComparisonCost [] = 0
#guard bucketComparisonCost [7] = 1
#guard bucketComparisonCost [3, 1, 2, 1] = 5
#guard bucketComparisonCost [7, 6, 1, 0] = 6

private def smallInputs : Nat → List (List Nat)
  | 0 => [[]]
  | n + 1 => (smallInputs n).flatMap fun xs => [0, 1, 2, 7].map (fun x => x :: xs)

-- All 5,461 lists of lengths zero through six over {0, 1, 2, 7}.
#guard ((List.range 7).flatMap smallInputs).all fun xs =>
  let result := bucketSortResult xs
  let trace := bucketSortTrace xs
  result == xs.mergeSort &&
    (bucketComparisonRun xs).1 == result &&
    replayChecked? trace xs == some result &&
    replayChecked? (trace ++ [(0, 0)]) xs == none &&
    bucketComparisonCost xs ≤ xs.length + xs.length.choose 2 &&
    bucketPlacementCost xs == xs.length &&
    ((List.range (bucketCount xs)).all fun i =>
      (distribute xs)[i]?.getD [] == xs.filter (fun x => x / bucketWidth xs == i))

end LeanSort.Bucket
