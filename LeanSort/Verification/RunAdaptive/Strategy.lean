import LeanSort.Algorithm.RunStrategy
import LeanSort.Verification.RunAdaptive.Checks
import LeanSort.Verification.CostedPlan.ChecksCost

namespace LeanSort.RunAdaptive
open Comparison

/-- Offline certificate diagnostic, not a second discovery during deployment. -/
def Strategy.bound {α : Type} [LinearOrder α] : Strategy → List α → Nat
  | .fixed p, xs => p.upper xs.length
  | .countBalanced, xs => upper xs.length (runCount xs)
  | .lengthBalanced, xs => xs.length - 1 + (lengthPlan (discover xs).eval.ret).budget

theorem Strategy.correct {α : Type} [LinearOrder α] (s : Strategy) (xs : List α) :
    IsSortingResult (· ≤ ·) xs (s.run xs) := by
  cases s with
  | fixed p => exact p.run_spec xs
  | countBalanced => exact count_sort_spec xs
  | lengthBalanced => exact length_sort_spec xs

theorem Strategy.cost_bound {α : Type} [LinearOrder α] (s : Strategy) (xs : List α) :
    (s.program xs).eval.time ≤ s.bound xs := by
  cases s with
  | fixed p => exact p.cost_le_upper xs
  | countBalanced => exact count_cost_le_upper xs
  | lengthBalanced => exact cost_le_tree_budget lengthPlan xs

theorem Strategy.execution {α : Type} [LinearOrder α] (s : Strategy) (xs : List α) :
    Executes (s.program xs) (s.run xs) (s.program xs).eval.time := Program.eval_executes _

theorem Strategy.phases {α : Type} [LinearOrder α] (s : Strategy) (xs : List α) :
    (s.program xs).count .check + (s.program xs).count .sort = (s.program xs).eval.time :=
  Program.count_partition _

end LeanSort.RunAdaptive
