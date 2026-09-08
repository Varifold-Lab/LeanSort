import LeanSort.Algorithm.PlanChecks
import LeanSort.Verification.Comparison.Phases
import LeanSort.Verification.CostedPlan.Cost

namespace LeanSort.CostedPlan
open Comparison

theorem Component.no_checks {α : Type} [LinearOrder α] (c : Component) (xs : List α) :
    (c.program xs).count .check = 0 := by
  cases c with
  | merge => exact ComparisonSort.mergeSort_no_checks xs
  | insertion => exact ComparisonSort.insertion_no_checks xs
  | hybrid t => exact ComparisonSort.hybrid_no_checks t xs

theorem Schema.checkProgram_cost {α : Type} [LinearOrder α] (p : Schema) (xs : List α) :
    (p.checkProgram xs).eval.time = (p.program xs).count .check := by
  induction p generalizing xs with
  | leaf c => simpa [Schema.checkProgram, Program.eval, Schema.program] using (c.no_checks xs).symm
  | split cut l r ihl ihr =>
    simp [Schema.checkProgram, Program.eval_bind, Schema.program, Program.count_bind,
      ComparisonSort.merge_no_checks, ihl, ihr]
  | guardSorted fallback ih =>
    simp only [Schema.checkProgram, Schema.program, Program.eval_bind, Program.count_bind]
    rw [ComparisonSort.checkSorted_check_count]
    cases h : (ComparisonSort.checkSorted xs).eval.ret <;>
      simp [Program.eval, Program.count, ih]

/-- Deployment's total cost is exactly the disjoint sum of guard and sorting
comparisons. Isolated replay is a diagnostic for the first summand only. -/
theorem Schema.checks_sort_cost {α : Type} [LinearOrder α] (p : Schema) (xs : List α) :
    (p.checkProgram xs).eval.time + (p.program xs).count .sort = (p.eval xs).time := by
  rw [p.checkProgram_cost xs]
  exact p.check_sort_partition xs

theorem Schema.readyCheck_spec {α : Type} [LinearOrder α] (p : Schema) (xs : List α) :
    p.readyCheck xs = true ↔ p.Ready xs := by
  induction p generalizing xs with
  | leaf c => simp [Schema.readyCheck, Schema.Ready]
  | split cut l r ihl ihr => simp [Schema.readyCheck, Schema.Ready, ihl, ihr]
  | guardSorted fallback ih => exact ComparisonSort.checkSorted_spec xs

end LeanSort.CostedPlan
