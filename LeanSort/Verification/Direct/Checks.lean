import LeanSort.Verification.Direct.Refinement
import LeanSort.Algorithm.Direct.Ablation

namespace LeanSort.Direct
open Comparison RunAdaptive

theorem staged_eq {α : Type} [LinearOrder α] (ds dm : Bool)
    (planner : List (List α) → MergeTree α) (xs : List α) :
    staged ds dm planner xs = (sortProgram planner xs).eval := by
  cases ds <;> cases dm <;>
    simp [staged, scan_counted_eq, tree_counted_eq, sortProgram, Program.eval_bind]

-- Finite regressions supplement the generic decision-tree/interpretation proofs.
#guard (List.range 6).all fun n => (List.replicate n [0, 1, 2]).sections.all fun xs =>
  strategies.all fun s =>
    run s xs == xs.mergeSort && (runCounted s xs).ret == run s xs &&
    (runCounted s xs).time == (s.program xs).eval.time

#guard (scan [1, 1, 3, 0, 2, 2]) == [[1, 1, 3], [0, 2, 2]]
#guard (scanCounted [1, 1, 3, 0, 2, 2]).time == 5
#guard (mergeCounted [1, 3] [2, 4]).time == 3
#guard merge [1, 3] [2, 4] == [1, 2, 3, 4]
#guard (runCounted .countBalanced ([50, 30] ++ List.range 16)).time == 50
#guard (runCounted .lengthBalanced ([50, 30] ++ List.range 16)).time == 34
#guard (runCounted .countBalanced ([] : List Nat)).time == 0

end LeanSort.Direct
