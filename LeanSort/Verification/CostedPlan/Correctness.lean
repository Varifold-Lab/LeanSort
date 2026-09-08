import LeanSort.Algorithm.CostedPlan
import LeanSort.Verification.Comparison.Components

namespace LeanSort.CostedPlan
open Comparison

theorem Cut.position_le (cut : Cut) (n : Nat) : cut.position n ≤ n := by
  cases cut <;> exact Nat.min_le_left _ _

theorem Component.program_spec {α : Type} [LinearOrder α] (c : Component) (xs : List α) :
    IsSortingResult (· ≤ ·) xs (c.program xs).eval.ret := by
  cases c with
  | merge =>
    simp only [Component.program, ComparisonSort.mergeSort_eval]
    exact Cslib.Algorithms.Lean.TimeM.mergeSort_correct xs
  | insertion =>
    simpa only [Component.program, ComparisonSort.insertion_ret] using
      Insertion.insertionSortResult_spec xs
  | hybrid t =>
    simpa only [Component.program, ComparisonSort.hybrid_ret] using HybridMerge.sort_spec t xs

theorem Schema.run_spec {α : Type} [LinearOrder α] (p : Schema) (xs : List α) :
    IsSortingResult (· ≤ ·) xs (p.run xs) := by
  induction p generalizing xs with
  | leaf c => exact c.program_spec xs
  | split cut left right ihl ihr =>
    have hl := ihl (xs.take (cut.position xs.length))
    have hr := ihr (xs.drop (cut.position xs.length))
    simp only [Schema.run, Schema.eval, Schema.program, Program.eval_bind,
      ComparisonSort.merge_eval]
    refine ⟨Cslib.Algorithms.Lean.TimeM.sorted_merge hl.1 hr.1, ?_⟩
    exact (Cslib.Algorithms.Lean.TimeM.merge_perm _ _).trans
      (by simpa only [Schema.run, Schema.eval, List.take_append_drop] using hl.2.append hr.2)
  | guardSorted fallback ih =>
    simp only [Schema.run, Schema.eval, Schema.program, Program.eval_bind]
    cases h : (ComparisonSort.checkSorted xs).eval.ret
    · exact ih xs
    · exact ⟨(ComparisonSort.checkSorted_spec xs).mp h, List.Perm.refl xs⟩

@[simp] theorem Schema.eval_length {α : Type} [LinearOrder α] (p : Schema) (xs : List α) :
    (p.eval xs).ret.length = xs.length := (p.run_spec xs).2.length_eq

theorem Schema.operational_certificate {α : Type} [LinearOrder α] (p : Schema) (xs : List α) :
    Executes (p.program xs) (p.run xs) (p.eval xs).time :=
  Program.eval_executes (p.program xs)

theorem Schema.check_sort_partition {α : Type} [LinearOrder α] (p : Schema) (xs : List α) :
    (p.program xs).count .check + (p.program xs).count .sort = (p.eval xs).time :=
  Program.count_partition (p.program xs)

/-- Existing Adaptive plans embed without changing their sorted output. -/
theorem Schema.ofAdaptive_run {α : Type} [LinearOrder α] (p : Adaptive.Plan) (xs : List α) :
    (ofAdaptive p).run xs = p.run xs := by
  induction p generalizing xs with
  | merge => simp [ofAdaptive, Schema.run, Schema.eval, Schema.program, Component.program,
      ComparisonSort.mergeSort_eval, Adaptive.Plan.run, Merge.mergeSortResult]
  | insertion => simp [ofAdaptive, Schema.run, Schema.eval, Schema.program, Component.program,
      ComparisonSort.insertion_ret, Adaptive.Plan.run]
  | hybrid t => simp [ofAdaptive, Schema.run, Schema.eval, Schema.program, Component.program,
      ComparisonSort.hybrid_ret, Adaptive.Plan.run]
  | split cut left right ihl ihr =>
    simp only [ofAdaptive, Schema.run, Schema.eval, Schema.program, Program.eval_bind,
      ComparisonSort.merge_eval, Adaptive.Plan.run]
    have ht : xs.take (min xs.length cut) = xs.take cut := by simp [Nat.min_comm]
    have hd : xs.drop (min xs.length cut) = xs.drop cut := by simp [Nat.min_comm]
    change (Cslib.Algorithms.Lean.TimeM.merge
      ((ofAdaptive left).run (xs.take (min xs.length cut)))
      ((ofAdaptive right).run (xs.drop (min xs.length cut)))).ret = _
    rw [ht, hd, ihl, ihr]

end LeanSort.CostedPlan
