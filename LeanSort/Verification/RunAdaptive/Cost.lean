import LeanSort.Verification.RunAdaptive.Correctness

namespace LeanSort.RunAdaptive
open Comparison

/-- Actual discovered count; not a generator label and not fixed in advance. -/
def runCount {α : Type} [LinearOrder α] (xs : List α) : Nat := (discover xs).eval.ret.length

def upper (n r : Nat) : Nat := (n - 1) + n * Nat.clog 2 r

theorem cost_decomposition {α : Type} [LinearOrder α]
    (planner : List (List α) → MergeTree α) (xs : List α) :
    (sortProgram planner xs).eval.time =
      (xs.length - 1) + (planner (discover xs).eval.ret).program.eval.time := by
  simp [sortProgram, Program.eval_bind, discover_cost]

theorem check_cost {α : Type} [LinearOrder α]
    (planner : List (List α) → MergeTree α) (xs : List α) :
    (sortProgram planner xs).count .check = xs.length - 1 := by
  have h := (discover xs).count_partition
  simp only [discover_no_sorting, Nat.add_zero, discover_cost] at h
  simpa [sortProgram, Program.count_bind, MergeTree.no_checks] using h

theorem sorting_cost {α : Type} [LinearOrder α]
    (planner : List (List α) → MergeTree α) (xs : List α) :
    (sortProgram planner xs).count .sort =
      (planner (discover xs).eval.ret).program.eval.time := by
  have h := (planner (discover xs).eval.ret).program.count_partition
  simpa [sortProgram, Program.count_bind, discover_no_sorting, MergeTree.no_checks] using h

/-- Every actual generated tree has a certificate, including the length-aware
control. Its budget is not assumed to be optimal or logarithmic. -/
theorem cost_le_tree_budget {α : Type} [LinearOrder α]
    (planner : List (List α) → MergeTree α) (xs : List α) :
    (sortProgram planner xs).eval.time ≤
      (xs.length - 1) + (planner (discover xs).eval.ret).budget := by
  rw [cost_decomposition]
  exact Nat.add_le_add_left (MergeTree.cost_le_budget _) _

/-- Uniform in BOTH n and the actual r. In particular r is not a hidden constant.
All recognition comparisons are included, also when every element is its own run. -/
theorem count_cost_le_upper {α : Type} [LinearOrder α] (xs : List α) :
    (sortProgram countPlan xs).eval.time ≤ upper xs.length (runCount xs) := by
  apply (cost_le_tree_budget countPlan xs).trans
  have h := countPlan_budget (discover xs).eval.ret
  rw [(discover_spec xs).1] at h
  exact Nat.add_le_add_left h _

theorem count_cost_le_nlog_envelope {α : Type} [LinearOrder α] (xs : List α) :
    (sortProgram countPlan xs).eval.time ≤ upper xs.length xs.length := by
  apply (count_cost_le_upper xs).trans
  exact Nat.add_le_add_left (Nat.mul_le_mul_left _ (Nat.clog_monotone 2 (discover_count_le xs))) _

theorem count_cost_of_sorted {α : Type} [LinearOrder α] (xs : List α)
    (sorted : xs.Pairwise (· ≤ ·)) :
    (sortProgram countPlan xs).eval.time = xs.length - 1 := by
  rw [cost_decomposition, discover_of_sorted xs sorted]
  split_ifs <;> simp [countPlan, MergeTree.program, Program.eval]

theorem empty_case {α : Type} [LinearOrder α] :
    runCount ([] : List α) = 0 ∧ upper 0 0 = 0 ∧
      (sortProgram countPlan ([] : List α)).eval.time = 0 := by
  simp [runCount, discover, Program.eval, upper, sortProgram, Program.eval_bind,
    countPlan, MergeTree.program]

end LeanSort.RunAdaptive
