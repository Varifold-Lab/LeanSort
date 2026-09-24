import LeanSort.Verification.Intro.Semantics
import LeanSort.Verification.Intro.Complexity

namespace LeanSort.Intro

example {α : Type} [LinearOrder α] (xs : List α) :
    IsSortingResult (· ≤ ·) xs (introSortResult xs) := introSortResult_spec xs

example {α : Type} [LinearOrder α] (cutoff depth : Nat) (xs : List α) :
    IsSortingResult (· ≤ ·) xs (introSortAux cutoff depth xs) := introSortAux_spec _ _ _

#guard introSortResult ([] : List Nat) = []
#guard introSortResult [7] = [7]
#guard introSortResult ([3, -2, 0, -2, 10] : List Int) = [-2, -2, 0, 3, 10]
#guard introSortResult [10 ^ 30, 0, 1, 10 ^ 30] = [0, 1, 10 ^ 30, 10 ^ 30]
#guard depthLimit 0 = 0
#guard depthLimit 1 = 0
#guard depthLimit 16 = 8
#guard traceAux 16 0 [3, 2, 1] = .heap 3
#guard traceAux 16 1 [3, 2, 1] = .insertion 3
#guard traceAux 0 1 [2, 1, 3] = .partition [true, false] (.heap 1) (.heap 1)
#guard traceAux 0 1 [2, 2, 2] = .partition [true, true] (.heap 2) (.heap 0)
#guard traceAux 0 2 [4, 2, 1, 3, 6, 5, 7] =
  .partition [true, true, true, false, false, false]
    (.partition [true, false] (.heap 1) (.heap 1))
    (.partition [true, false] (.heap 1) (.heap 1))
#guard traceAux 16 1 (List.range 16) = .insertion 16
#guard traceAux 16 1 (List.range 17) =
  .partition (List.replicate 16 false) (.heap 0) (.heap 16)
#guard replayAux? 0 1 (.partition [true, false] (.heap 1) (.heap 1)) [2, 1, 3] = some [1, 2, 3]
-- Wrong strategy, size, decisions, child strategy, and truncated/extra branches.
#guard replayAux? 16 0 (.insertion 3) [3, 2, 1] = none
#guard replayAux? 16 1 (.heap 3) [3, 2, 1] = none
#guard replayAux? 16 0 (.heap 4) [3, 2, 1] = none
#guard replayAux? 0 1 (.partition [false, true] (.heap 1) (.heap 1)) [2, 1, 3] = none
#guard replayAux? 0 1 (.partition [true] (.heap 1) (.heap 1)) [2, 1, 3] = none
#guard replayAux? 0 1 (.partition [true, false, true] (.heap 1) (.heap 1)) [2, 1, 3] = none
#guard replayAux? 0 1 (.partition [true, false] (.insertion 1) (.heap 1)) [2, 1, 3] = none
#guard replayAux? 0 1 .empty [2, 1, 3] = none
#guard replayChecked? (.heap 0) ([] : List Nat) = some []
#guard replayChecked? .empty ([] : List Nat) = none
#guard (comparisonRun 16 1 [3, 2, 1]).2 = 3
#guard (comparisonRun 16 1 [1, 2, 3]).2 = 2
#guard (comparisonRun 0 1 [2, 1, 3]).2 = 2
#guard (comparisonRun 16 0 [3, 2, 1]).2 = LeanSort.Heap.heapComparisonCost [3, 2, 1]

private def smallInputs : Nat → List (List Nat)
  | 0 => [[]]
  | n + 1 => (smallInputs n).flatMap fun xs => [0, 1, 2].map (fun x => x :: xs)

-- All 3,280 inputs of lengths zero through seven, with four forced configurations.
#guard ((List.range 8).flatMap smallInputs).all fun xs =>
  introSortResult xs == xs.mergeSort &&
    replayChecked? (introSortTrace xs) xs == some (introSortResult xs) &&
    ([(0, 0), (0, 1), (1, 2), (16, 4)] : List (Nat × Nat)).all (fun (c, d) =>
      let result := introSortAux c d xs
      let trace := traceAux c d xs
      let counted := comparisonRun c d xs
      result == xs.mergeSort && counted.1 == result &&
        replayAux? c d trace xs == some result && trace.accounted == xs.length &&
        trace.partitionDepth ≤ d && counted.2 ≤ xs.length * (d + c + 4 * (xs.length.log2 + 1)))

-- Cutoff boundaries and deliberately unbalanced first-pivot inputs.
#guard [15, 16, 17, 31, 32, 33, 64, 127].all fun n =>
  [List.range n, (List.range n).reverse, List.replicate n 4,
    (List.range n).map (fun i => (i * 7) % 5)].all fun xs =>
      introSortResult xs == xs.mergeSort &&
        (comparisonRun insertionCutoff (depthLimit n) xs).1 == xs.mergeSort &&
        replayChecked? (introSortTrace xs) xs == some (introSortResult xs) &&
        (introSortTrace xs).accounted == n &&
        (introSortTrace xs).partitionDepth ≤ depthLimit n &&
        introComparisonCost xs ≤ n * (6 * n.log2 + 20)

end LeanSort.Intro
