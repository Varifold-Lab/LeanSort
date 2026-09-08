import LeanSort.Algorithm.RunMerge
import LeanSort.Verification.Comparison.Phases
import Mathlib.Tactic.Linarith

namespace LeanSort.RunAdaptive
open Comparison

theorem MergeTree.weight_eq {α : Type} (tree : MergeTree α) :
    tree.weight = tree.leaves.flatten.length := by
  induction tree <;> simp_all [weight, leaves, List.flatten_append]

theorem MergeTree.program_perm {α : Type} [LinearOrder α] (tree : MergeTree α) :
    tree.program.eval.ret.Perm tree.leaves.flatten := by
  induction tree with
  | empty => exact List.Perm.refl _
  | leaf run => simp [program, Program.eval, leaves]
  | node left right ihl ihr =>
    simp only [program, Program.eval_bind, ComparisonSort.merge_eval]
    simpa only [leaves, List.flatten_append] using
      (Cslib.Algorithms.Lean.TimeM.merge_perm _ _).trans (ihl.append ihr)

@[simp] theorem MergeTree.program_length {α : Type} [LinearOrder α] (tree : MergeTree α) :
    tree.program.eval.ret.length = tree.weight := by
  rw [tree.weight_eq]
  exact tree.program_perm.length_eq

theorem MergeTree.program_sorted {α : Type} [LinearOrder α] (tree : MergeTree α)
    (h : ∀ run ∈ tree.leaves, run.Pairwise (· ≤ ·)) :
    tree.program.eval.ret.Pairwise (· ≤ ·) := by
  induction tree with
  | empty => simp [program, Program.eval]
  | leaf run => exact h run (by simp [leaves])
  | node left right ihl ihr =>
    simp only [program, Program.eval_bind, ComparisonSort.merge_eval]
    exact Cslib.Algorithms.Lean.TimeM.sorted_merge
      (ihl (by intro run hr; exact h run (by simp [leaves, hr])))
      (ihr (by intro run hr; exact h run (by simp [leaves, hr])))

theorem MergeTree.cost_le_budget {α : Type} [LinearOrder α] (tree : MergeTree α) :
    tree.program.eval.time ≤ tree.budget := by
  induction tree with
  | empty => simp [program, Program.eval, budget]
  | leaf run => simp [program, Program.eval, budget]
  | node left right ihl ihr =>
    have hm := ComparisonSort.merge_cost_le left.program.eval.ret right.program.eval.ret
    simp only [program_length] at hm
    simp only [program, Program.eval_bind, budget]
    omega

theorem MergeTree.budget_le_weight_depth {α : Type} (tree : MergeTree α) :
    tree.budget ≤ tree.weight * tree.depth := by
  induction tree with
  | empty => simp [budget, weight]
  | leaf run => simp [budget, depth]
  | node left right ihl ihr =>
    have hl := Nat.mul_le_mul_left left.weight (Nat.le_max_left left.depth right.depth)
    have hr := Nat.mul_le_mul_left right.weight (Nat.le_max_right left.depth right.depth)
    simp only [budget, weight, depth]
    nlinarith

theorem MergeTree.no_checks {α : Type} [LinearOrder α] (tree : MergeTree α) :
    tree.program.count .check = 0 := by
  induction tree <;> simp_all [program, Program.count, Program.count_bind, ComparisonSort.merge_no_checks]

theorem countPlan_leaves {α : Type} (runs : List (List α)) :
    (countPlan runs).leaves = runs := by
  rw [countPlan.eq_def]
  split_ifs with h
  · cases runs with
    | nil => rfl
    | cons run runs =>
      cases runs with
      | nil => rfl
      | cons next rest => simp at h; omega
  · simp only [MergeTree.leaves, countPlan_leaves (runs.take (runs.length / 2)),
      countPlan_leaves (runs.drop (runs.length / 2)), List.take_append_drop]
termination_by runs.length
decreasing_by all_goals simp_wf; omega

theorem countPlan_depth {α : Type} (runs : List (List α)) :
    (countPlan runs).depth ≤ Nat.clog 2 runs.length := by
  rw [countPlan.eq_def]
  split_ifs with h
  · cases runs <;> simp [MergeTree.depth]
  · have hl := countPlan_depth (runs.take (runs.length / 2))
    have hr := countPlan_depth (runs.drop (runs.length / 2))
    simp only [List.length_take, List.length_drop, Nat.min_eq_left (Nat.div_le_self _ _)] at hl hr
    have hfl := Cslib.Algorithms.Lean.TimeM.clog2_floor_half_le runs.length (by omega)
    have hcl := Cslib.Algorithms.Lean.TimeM.clog2_half_le runs.length (by omega)
    have heq : (runs.length + 1) / 2 = runs.length - runs.length / 2 := by omega
    rw [heq] at hcl
    have hpos : 0 < Nat.clog 2 runs.length := Nat.clog_pos (by omega) (by omega)
    simp only [MergeTree.depth]
    omega
termination_by runs.length
decreasing_by all_goals simp_wf; omega

theorem countPlan_budget {α : Type} (runs : List (List α)) :
    (countPlan runs).budget ≤ runs.flatten.length * Nat.clog 2 runs.length := by
  apply (countPlan runs).budget_le_weight_depth.trans
  rw [(countPlan runs).weight_eq, countPlan_leaves]
  exact Nat.mul_le_mul_left _ (countPlan_depth runs)

end LeanSort.RunAdaptive
