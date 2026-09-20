import LeanSort.Verification.Tree.Complexity

/-! Executable regressions complement the universal proofs: duplicates, path
rejection, unbalanced trees, and exhaustive small inputs. -/

namespace LeanSort.Tree

example (xs : List Nat) : IsSortingResult (· ≤ ·) xs (treeSortResult xs) :=
  treeSortResult_spec xs

example (xs : List Int) : treeComparisonCost xs ≤ xs.length.choose 2 :=
  treeComparisonCost_le xs

#guard treeSortResult ([] : List Nat) = []
#guard treeSortResult [7] = [7]
#guard treeSortResult [3, 1, 2, 1] = [1, 1, 2, 3]
#guard treeSortResult ([-2, 3, 0, -2] : List Int) = [-2, -2, 0, 3]
#guard treeSortTrace [3, 1, 2, 1] = [[], [true], [true, false], [true, false, true]]
#guard treeComparisonCost [3, 1, 2, 1] = 6
#guard replayChecked? (treeSortTrace [3, 1, 2, 1]) [3, 1, 2, 1] = some [1, 1, 2, 3]

-- Distinguish no insertions from one insertion with no comparisons.
#guard replayChecked? [] ([] : List Nat) = some []
#guard replayChecked? [[]] ([] : List Nat) = none
#guard replayChecked? [] [3] = none
#guard replayChecked? [[]] [3] = some [3]
-- Reject premature leaves, extra decisions, false branches, and wrong tie policy.
#guard replayChecked? [[true]] [3] = none
#guard replayChecked? [[], []] [3, 1] = none
#guard replayChecked? [[], [true, false]] [3, 1] = none
#guard replayChecked? [[], [false]] [3, 1] = none
#guard replayChecked? [[], [true]] [3, 3] = none
#guard replayChecked? [[], [false]] [3, 3] = some [3, 3]
#guard replayChecked? [[], [true], []] [3, 1] = none

#guard (List.range 33).all fun n =>
  let xs := List.replicate n 5
  treeComparisonCost xs == n.choose 2 &&
    treeTraversalCost xs == n && height (fromList xs) == n

private def smallInputs : Nat → List (List Nat)
  | 0 => [[]]
  | n + 1 => (smallInputs n).flatMap fun xs => [0, 1, 2].map (fun x => x :: xs)

-- All 1,093 lists of lengths zero through six over {0, 1, 2}.
#guard ((List.range 7).flatMap smallInputs).all fun xs =>
  let result := treeSortResult xs
  let trace := treeSortTrace xs
  result == xs.mergeSort &&
    (sortTrace xs).1 == result &&
    replayChecked? trace xs == some result &&
    trace.length == xs.length &&
    treeComparisonCost xs == (trace.map List.length).sum &&
    treeComparisonCost xs ≤ xs.length.choose 2 &&
    replayChecked? (trace ++ [[]]) xs == none

end LeanSort.Tree
