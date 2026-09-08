import LeanSort.Algorithm.Adaptive
import LeanSort.Verification.HybridMerge.Correctness
import LeanSort.Verification.Merge.Correctness

namespace LeanSort.Adaptive

/-- Correct for every finite plan and list, including arbitrary nested cut points.
No property of the optimizer or distribution of inputs is assumed. -/
theorem Plan.run_spec {α : Type} [LinearOrder α] (plan : Plan) (xs : List α) :
    IsSortingResult (· ≤ ·) xs (plan.run xs) := by
  induction plan generalizing xs with
  | merge => exact Merge.mergeSortResult_spec xs
  | insertion => exact Insertion.insertionSortResult_spec xs
  | hybrid t => exact HybridMerge.sort_spec t xs
  | split cut left right ihLeft ihRight =>
    have hl := ihLeft (xs.take cut)
    have hr := ihRight (xs.drop cut)
    refine ⟨Cslib.Algorithms.Lean.TimeM.sorted_merge hl.1 hr.1, ?_⟩
    exact (Cslib.Algorithms.Lean.TimeM.merge_perm _ _).trans
      (by simpa only [List.take_append_drop] using hl.2.append hr.2)

theorem execute_spec {α : Type} [LinearOrder α] (proposal : Option Plan) (xs : List α) :
    IsSortingResult (· ≤ ·) xs (execute proposal xs) :=
  Plan.run_spec (proposal.getD .merge) xs

theorem selectAndRun_spec {α : Type} [LinearOrder α]
    (choose : List α → Option Plan) (xs : List α) :
    IsSortingResult (· ≤ ·) xs (selectAndRun choose xs) :=
  execute_spec (choose xs) xs

theorem rejected_eq_merge {α : Type} [LinearOrder α] (xs : List α) :
    execute none xs = Merge.mergeSortResult xs := rfl

end LeanSort.Adaptive
