import LeanSort.Verification.Selection.Trace
import LeanSort.Verification.Selection.Semantics
import LeanSort.Verification.Selection.Complexity

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

-- Equal minima select the first occurrence, even when a later minimum exists.
#guard argmin? [3, 1, 1, 2] = some (1, 1)
#guard argmin? [1, 1, 0, 0] = some (2, 0)
#guard argmin? ([] : List Nat) = none
#guard round 4 (3 : Nat) [1, 1, 2] = ((1, [3, 1, 2]), [(4, 5)])
#guard round 4 (1 : Nat) [1, 2] = ((1, [1, 2]), [])
#guard replay (round 2 (3 : Nat) [1, 2]).2 [9, 8, 3, 1, 2] = [9, 8, 1, 3, 2]

-- Valid rearrangements are distinct from generated sorting certificates.
#guard replayChecked? [] [2, 1] = some [2, 1]
#guard replayChecked? [(0, 1)] [1, 2] = some [2, 1]
#guard replayChecked? [(0, 0)] [1, 2] = none
#guard replayChecked? [(1, 0)] [1, 2] = none
#guard replayChecked? [(0, 2)] [1, 2] = none
#guard replayChecked? [(0, 1)] ([] : List Nat) = none

example : MinimumSpec ([3, 1, 1, 2] : List Nat) 1 1 :=
  (argmin?_iff_minimumSpec _ _ _).mp (by decide)
example (xs : List Nat) : IsSortingResult (· ≤ ·) xs (selectionSortCertificate xs).output :=
  (selectionSortCertificate xs).spec

-- All 364 lists of length at most five, including all duplicates and empty input.
#guard (List.range 6).all fun len =>
  (List.range (3 ^ len)).all fun code =>
    let xs := (List.range len).map (fun i => code / 3 ^ i % 3)
    let c := selectionSortCertificate xs
    c.output == xs.mergeSort && replayChecked? c.trace xs == some c.output &&
      replaySelection? xs c.trace == some c.output &&
      selectionComparisonCost xs == xs.length.choose 2 &&
      c.trace.length ≤ xs.length - 1 &&
      c.trace.all (fun move => decide (move.1 < move.2 ∧ move.2 < xs.length))

-- A partial execution settles only its processed prefix.
#guard (selectionPartialCertificate 1 [9, 8] [3, 1, 2]).output = [1, 3, 2]
#guard (selectionPartialCertificate 1 [9, 8] [3, 1, 2]).trace = [(2, 3)]
#guard (selectionPartialCertificate 0 [9, 8] [3, 1, 2]).output = [3, 1, 2]
#guard (selectionPartialCertificate 8 [9, 8] [3, 1, 2]).output = [1, 2, 3]
#guard (selectionPartialCertificate 8 [9, 8] [7]).trace = []

example : SettledPrefix 1 ([1, 3, 2] : List Nat) :=
  (selectionPartialCertificate 1 ([] : List Nat) [3, 1, 2]).settled

-- Every small input at every fuel level, including two surplus rounds.
#guard (List.range 6).all fun len =>
  (List.range (3 ^ len)).all fun code =>
    let xs := (List.range len).map (fun i => code / 3 ^ i % 3)
    (List.range (len + 3)).all fun fuel =>
      let c := selectionPartialCertificate fuel [9, 8] xs
      let counted := sortAuxWithComparisons fuel 2 xs
      decide ((c.output.take fuel).Pairwise (· ≤ ·)) &&
        (c.output.take fuel).all (fun a => (c.output.drop fuel).all (fun b => decide (a ≤ b))) &&
        (c.output.take fuel).length == min fuel xs.length &&
        replayChecked? c.trace ([9, 8] ++ xs) == some ([9, 8] ++ c.output) &&
        replaySelectionAux? fuel 2 xs c.trace == some c.output &&
        counted.1 == (c.output, c.trace) &&
        counted.2 == xs.length.choose 2 - (xs.length - fuel).choose 2 &&
        c.trace.length ≤ min fuel (xs.length - 1)

-- Legal swaps can sort while violating the leftmost-minimum policy.
#guard replayChecked? [(0, 2)] [2, 1, 1] = some [1, 1, 2]
#guard replaySelection? [2, 1, 1] [(0, 2)] = none
#guard replaySelection? [2, 1, 1] [(0, 1), (1, 2)] = some [1, 1, 2]
-- A redundant swap pair preserves the final result but is not a selection run.
#guard replayChecked? [(0, 1), (0, 1)] [1, 2] = some [1, 2]
#guard replaySelection? [1, 2] [(0, 1), (0, 1)] = none
#guard replaySelection? [2, 1] [] = none
#guard replaySelection? ([] : List Nat) [] = some []
#guard replaySelection? [1, 1, 1] [] = some [1, 1, 1]
#guard replaySelectionAux? 0 0 [2, 1] [] = some [2, 1]
#guard replaySelectionAux? 1 2 [2, 1] [(0, 1)] = none
#guard replaySelectionAux? 1 2 [2, 1] [(2, 3)] = some [1, 2]

-- Direct derivations expose both swapping and no-swap rounds.
example : SelectionDerivation 1 0 ([2, 1, 1] : List Nat) [1, 2, 1] [(0, 1)] :=
  .select ((argmin?_iff_minimumSpec _ 1 1).mp (by decide)) (.stop 1 [2, 1])
example : SelectionDerivation 1 0 ([1, 2] : List Nat) [1, 2] [] :=
  .select ((argmin?_iff_minimumSpec _ 0 1).mp (by decide)) (.stop 1 [2])

-- Already sorted and all-equal inputs still perform every minimum-scan comparison.
#guard selectionComparisonCost [1, 2, 3, 4, 5] = 10
#guard selectionSwapCost [1, 2, 3, 4, 5] = 0
#guard selectionComparisonCost [2, 2, 2, 2, 2] = 10
#guard selectionSwapCost [2, 2, 2, 2, 2] = 0
#guard selectionComparisonCost [5, 4, 3, 2, 1] = 10
#guard argminWithComparisons ([] : List Nat) = (none, 0)
#guard argminWithComparisons [7] = (some (0, 7), 0)
#guard argminWithComparisons [3, 1, 1, 2] = (some (1, 1), 3)
#guard (sortAuxWithComparisons 2 0 [5, 4, 3, 2, 1]).2 = 7
#guard (sortAuxWithComparisons 8 0 [5, 4, 3, 2, 1]).2 = 10

end LeanSort.Selection
