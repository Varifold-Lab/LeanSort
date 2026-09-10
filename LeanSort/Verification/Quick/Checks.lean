import LeanSort.Verification.Quick.Cost
import LeanSort.Verification.Quick.Semantics
import LeanSort.Verification.Quick.Complexity
import LeanSort.Verification.Quick.Tree

namespace LeanSort.Quick

#guard partitionTr (2 : Nat) [2, 3, 1, 4, 2] =
  (([2, 1, 2], [3, 4]), [true, false, true, false, true])
#guard partitionTr (0 : Int) [-1, 2, 0, -3] =
  (([-1, 0, -3], [2]), [true, false, true, true])

-- Derive legal executions directly from order rules, without running the sorter.
example : PartitionDerivation (2 : Nat) [2, 3, 1] [2, 1] [3] [true, false, true] :=
  .left (by decide) (.right (by decide) (.left (by decide) .nil))

example : QuickDerivation ([2, 1, 3] : List Nat)
    (.node [true, false] (.node [] .empty .empty) (.node [] .empty .empty)) [1, 2, 3] :=
  .node (.left (by decide) (.right (by decide) .nil))
    (.node .nil .empty .empty) (.node .nil .empty .empty)

#guard quickSortResult ([] : List Nat) = []
#guard quickSortResult [7] = [7]
#guard quickSortResult [1, 2, 3, 4] = [1, 2, 3, 4]
#guard quickSortResult [4, 3, 2, 1] = [1, 2, 3, 4]
#guard quickSortResult [2, 1, 2, 1] = [1, 1, 2, 2]
#guard quickSortResult [2, 2, 2] = [2, 2, 2]
#guard quickSortResult ([-2, 3, 0, -2] : List Int) = [-2, -2, 0, 3]

-- All 243 length-five lists over {0, 1, 2}, compared with library merge sort.
#guard (List.range 243).all fun n =>
  let xs := List.ofFn (fun i : Fin 5 => n / 3 ^ i.val % 3)
  quickSortResult xs == xs.mergeSort

-- Every list of length at most five over {0, 1, 2}, including duplicates.
#guard ((List.range 6).flatMap fun k =>
  (List.range (3 ^ k)).map fun n =>
    List.ofFn (fun i : Fin k => n / 3 ^ i.val % 3)).all fun xs =>
  let execution := quickSortTr xs
  execution.1 == xs.mergeSort &&
    replayChecked? execution.2 xs == some execution.1 &&
    execution.2.pivots == xs.length &&
    comparisonCost xs ≤ xs.length * (xs.length - 1) / 2 &&
    comparisonCost xs == execution.2.depthSum 0 &&
    comparisonCost xs + xs.length ≤ xs.length * execution.2.height

-- A singleton still has a pivot node, with two empty children.
#guard (quickSortTr [7]).2 = .node [] .empty .empty
#guard (quickSortTr [2, 1, 2, 3]).2 =
  .node [true, true, false]
    (.node [false] .empty (.node [] .empty .empty))
    (.node [] .empty .empty)
#guard replayChecked? .empty [1] = none
#guard replayChecked? (.node [] .empty .empty) ([] : List Nat) = none
#guard replayChecked? (.node [false] (.node [] .empty .empty) .empty) [2, 1] = none
#guard replayChecked? (.node [true] .empty .empty) [2, 1] = none
#guard replayChecked? (.node [true, true] (.node [] .empty .empty) .empty) [2, 1] = none
#guard replayChecked? (.node [] (.node [] .empty .empty) .empty) [1] = none
#guard comparisonCost [1, 2, 3, 4, 5] = 10
#guard comparisonCost [5, 4, 3, 2, 1] = 10
#guard comparisonCost [2, 2, 2, 2, 2] = 10
#guard comparisonCost [3, 1, 2, 4, 5] = 6

#guard (quickSortTr [1, 2, 3, 4, 5]).2.height = 5
#guard (quickSortTr [3, 1, 2, 4, 5]).2.height = 3
#guard (quickSortTr [3, 1, 2, 4, 5]).2.depthSum 0 = 6
#guard (quickSortTr [3, 1, 2, 4, 5]).2.depthSum 2 = 16
#guard comparisonCost [4, 2, 6, 1, 3, 5, 7] = 10
#guard (quickSortTr [4, 2, 6, 1, 3, 5, 7]).2.height = 3

-- A fabricated decision list is not a structural depth count.
#guard (Trace.node [true] .empty .empty).comparisons = 1
#guard (Trace.node [true] .empty .empty).depthSum 0 = 0

example : comparisonCost ([9, 9, 4, 1] : List Nat) = Nat.choose 4 2 :=
  comparisonCost_of_nonincreasing _ (by decide)
example (n : Nat) : comparisonCost (List.replicate n (7 : Int)) = n.choose 2 :=
  comparisonCost_replicate 7 n

end LeanSort.Quick
