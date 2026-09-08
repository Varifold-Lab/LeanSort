import LeanSort.Verification.RunAdaptive.Discovery
import LeanSort.Verification.RunAdaptive.MergeTree
import LeanSort.Algorithm.RunLengthPlan

namespace LeanSort.RunAdaptive
open Comparison

theorem lengthPlan_leaves {α : Type} (runs : List (List α)) :
    (lengthPlan runs).leaves = runs := by
  rw [lengthPlan.eq_def]
  split_ifs with h
  · cases runs with
    | nil => rfl
    | cons run runs =>
      cases runs with
      | nil => rfl
      | cons next rest => simp at h; omega
  · simp only [MergeTree.leaves, lengthPlan_leaves (runs.take (lengthCut runs)),
      lengthPlan_leaves (runs.drop (lengthCut runs)), List.take_append_drop]
termination_by runs.length
decreasing_by
  all_goals
    simp_wf
    have hpos : 0 < lengthCut runs := by dsimp only [lengthCut]; omega
    have hlt : lengthCut runs < runs.length := by dsimp only [lengthCut]; omega
    omega

/-- The generator itself is constrained: it must retain all discovered leaves,
in order. Both concrete planners discharge this premise universally. -/
theorem sort_spec {α : Type} [LinearOrder α] (planner : List (List α) → MergeTree α)
    (planner_valid : ∀ runs, (planner runs).leaves = runs) (xs : List α) :
    IsSortingResult (· ≤ ·) xs (sort planner xs) := by
  have h := discover_spec xs
  simp only [sort, sortProgram, Program.eval_bind]
  refine ⟨(planner _).program_sorted ?_, ?_⟩
  · simpa only [planner_valid] using h.2.1
  · simpa only [planner_valid, h.1] using (planner (discover xs).eval.ret).program_perm

theorem count_sort_spec {α : Type} [LinearOrder α] (xs : List α) :
    IsSortingResult (· ≤ ·) xs (sort countPlan xs) := sort_spec _ countPlan_leaves xs

theorem length_sort_spec {α : Type} [LinearOrder α] (xs : List α) :
    IsSortingResult (· ≤ ·) xs (sort lengthPlan xs) := sort_spec _ lengthPlan_leaves xs

theorem operational_certificate {α : Type} [LinearOrder α]
    (planner : List (List α) → MergeTree α) (xs : List α) :
    Executes (sortProgram planner xs) (sort planner xs) (sortProgram planner xs).eval.time :=
  Program.eval_executes _

end LeanSort.RunAdaptive
