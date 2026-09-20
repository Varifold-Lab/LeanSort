import LeanSort.Verification.Bitonic.Complexity
import LeanSort.Verification.Bitonic.Semantics
import LeanSort.Verification.Bitonic.Comparator
import Mathlib.Data.List.Sort

/-! Executable regressions. These checks are not a universal sortedness proof. -/

namespace LeanSort.Bitonic

example {α : Type*} [LinearOrder α] (xs : List α) :
    (bitonicSortResult xs).Perm xs := bitonicSortResult_perm xs

#guard bitonicSortResult ([] : List Nat) = []
#guard bitonicSortResult [7] = [7]
#guard bitonicSortResult [3, 1, 2, 1] = [1, 1, 2, 3]
#guard bitonicSortResult ([3, -2, 0, -2, 10] : List Int) = [-2, -2, 0, 3, 10]
#guard bitonicSortResult [10 ^ 30, 0, 1, 10 ^ 30, 10 ^ 15] =
  [0, 1, 10 ^ 15, 10 ^ 30, 10 ^ 30]
#guard paddedInput ([] : List Nat) = #[none]
#guard paddedInput [3, 2, 1] = #[some 3, some 2, some 1, none]
#guard sortComparisons 0 = 0
#guard sortComparisons 1 = 1
#guard sortComparisons 2 = 6
#guard sortComparisons 3 = 24
#guard sortComparisons 4 = 80
#guard sortComparisons 10 = 28160
#guard compareExchange true 0 9 #[some 3, some 2] = #[some 3, some 2]
#guard compareExchange true 0 1 #[none, some 2] = #[some 2, none]
#guard compareExchange false 0 1 #[some 2, none] = #[none, some 2]
#guard replayChecked? [2, 1] [] = none
#guard replayChecked? [2, 1] [⟨false, 0, 1⟩] = none
#guard replayChecked? [2, 1] [⟨true, 0, 2⟩] = none
#guard replayChecked? [2, 1] [⟨true, 1, 0⟩] = none
#guard replayChecked? [2, 1] [⟨true, 0, 1⟩, ⟨true, 0, 1⟩] = none

private def smallInputs : Nat → List (List Nat)
  | 0 => [[]]
  | n + 1 => (smallInputs n).flatMap fun xs => [0, 1, 2].map (fun x => x :: xs)

-- All 3,280 lists of lengths zero through seven over {0, 1, 2}.
#guard ((List.range 8).flatMap smallInputs).all fun xs =>
  let schedule := sortSchedule (networkDepth xs.length) 0 true
  let output := bitonicSortResult xs
  output == xs.mergeSort &&
    replayChecked? xs schedule == some output &&
    schedule.length == sortComparisons (networkDepth xs.length) &&
    schedule.all (fun c => c.first < c.second && c.second < (paddedInput xs).size)

-- Longer cases cross power-of-two padding boundaries and exercise descending blocks.
#guard [8, 9, 15, 16, 17, 31, 32, 33, 64, 65].all fun n =>
  [List.range n, (List.range n).reverse, List.replicate n 4,
    (List.range n).map (fun i => (i * 7) % 5)].all fun xs =>
      bitonicSortResult xs == xs.mergeSort

end LeanSort.Bitonic
