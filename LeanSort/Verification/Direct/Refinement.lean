import LeanSort.Semantics.Direct
import LeanSort.Algorithm.Direct.Profile
import LeanSort.Verification.Direct.Symbolic
import LeanSort.Verification.RunAdaptive.Strategy

namespace LeanSort.Direct
open Comparison RunAdaptive

theorem scan_counted_eq {α : Type} [LinearOrder α] (xs : List α) :
    scanCounted xs = (discover xs).eval := by
  simpa only [evalMorphism, symbolic_discover, scanCounted] using
    (Morphism.discover evalMorphism symbolicCompare countedCompare eval_compare xs).symm

theorem scan_eq {α : Type} [LinearOrder α] (xs : List α) :
    scan xs = (discover xs).eval.ret := by
  simpa only [plainMorphism, symbolic_discover, scan] using
    (Morphism.discover plainMorphism symbolicCompare plainCompare plain_compare xs).symm

theorem merge_counted_eq {α : Type} [LinearOrder α] (xs ys : List α) :
    mergeCounted xs ys = (ComparisonSort.merge xs ys).eval := by
  simpa only [evalMorphism, symbolic_merge, mergeCounted] using
    (Morphism.merge evalMorphism symbolicCompare countedCompare eval_compare xs ys).symm

theorem merge_eq {α : Type} [LinearOrder α] (xs ys : List α) :
    merge xs ys = (ComparisonSort.merge xs ys).eval.ret := by
  simpa only [plainMorphism, symbolic_merge, merge] using
    (Morphism.merge plainMorphism symbolicCompare plainCompare plain_compare xs ys).symm

theorem tree_counted_eq {α : Type} [LinearOrder α] (t : MergeTree α) :
    treeCounted t = t.program.eval := by
  simpa only [evalMorphism, symbolic_tree, treeCounted] using
    (Morphism.tree evalMorphism symbolicCompare countedCompare eval_compare t).symm

theorem tree_eq {α : Type} [LinearOrder α] (t : MergeTree α) :
    tree t = t.program.eval.ret := by
  simpa only [plainMorphism, symbolic_tree, tree] using
    (Morphism.tree plainMorphism symbolicCompare plainCompare plain_compare t).symm

theorem run_counted_eq {α : Type} [LinearOrder α] (s : Strategy) (xs : List α) :
    runCounted s xs = (s.program xs).eval := by
  simpa only [evalMorphism, symbolic_strategy, runCounted] using
    (Morphism.strategy evalMorphism symbolicCompare countedCompare eval_compare s xs).symm

theorem run_eq {α : Type} [LinearOrder α] (s : Strategy) (xs : List α) :
    run s xs = s.run xs := by
  simpa only [plainMorphism, symbolic_strategy, run, Strategy.run] using
    (Morphism.strategy plainMorphism symbolicCompare plainCompare plain_compare s xs).symm

theorem uncounted_eq_counted {α : Type} [LinearOrder α] (s : Strategy) (xs : List α) :
    run s xs = (runCounted s xs).ret := by rw [run_eq, run_counted_eq]; rfl

/-- Existence of a costed execution for the uncounted body, via its symbolic
instrumentation and the two interpretation laws. -/
theorem uncounted_execution {α : Type} [LinearOrder α] (s : Strategy) (xs : List α) :
    Execution s xs (run s xs) (runCounted s xs).time := by
  simpa only [Execution, symbolic_strategy, run_eq, run_counted_eq, Strategy.run] using
    Program.eval_executes (s.program xs)

/-- Both output and cost are uniquely determined by that operational semantics. -/
theorem execution_iff {α : Type} [LinearOrder α] (s : Strategy) (xs out : List α) (cost : Nat) :
    Execution s xs out cost ↔ out = run s xs ∧ cost = (runCounted s xs).time := by
  constructor
  · intro h
    have he := Executes.eval_eq h
    rw [symbolic_strategy, ← run_counted_eq] at he
    constructor
    · rw [uncounted_eq_counted, he]
    · rw [he]
  · rintro ⟨rfl, rfl⟩
    exact uncounted_execution s xs

theorem scan_execution {α : Type} [LinearOrder α] (xs : List α) :
    Executes (Engine.discover symbolicCompare xs) (scan xs) (scanCounted xs).time := by
  simpa only [symbolic_discover, scan_eq, scan_counted_eq] using Program.eval_executes (discover xs)

theorem merge_execution {α : Type} [LinearOrder α] (xs ys : List α) :
    Executes (Engine.merge symbolicCompare xs ys) (merge xs ys) (mergeCounted xs ys).time := by
  simpa only [symbolic_merge, merge_eq, merge_counted_eq] using
    Program.eval_executes (ComparisonSort.merge xs ys)

theorem tree_execution {α : Type} [LinearOrder α] (t : MergeTree α) :
    Executes (Engine.tree symbolicCompare t) (tree t) (treeCounted t).time := by
  simpa only [symbolic_tree, tree_eq, tree_counted_eq] using Program.eval_executes t.program

theorem correct {α : Type} [LinearOrder α] (s : Strategy) (xs : List α) :
    IsSortingResult (· ≤ ·) xs (run s xs) := by rw [run_eq]; exact s.correct xs

theorem cost_bound {α : Type} [LinearOrder α] (s : Strategy) (xs : List α) :
    (runCounted s xs).time ≤ s.bound xs := by rw [run_counted_eq]; exact s.cost_bound xs

theorem execution_bound {α : Type} [LinearOrder α] (s : Strategy) (xs out : List α) (cost : Nat)
    (h : Execution s xs out cost) : cost ≤ s.bound xs := by
  rw [((execution_iff s xs out cost).mp h).2]
  exact cost_bound s xs

theorem count_bound {α : Type} [LinearOrder α] (xs : List α) :
    (runCounted .countBalanced xs).time ≤ upper xs.length (scan xs).length := by
  simpa only [run_counted_eq, Strategy.program, scan_eq, runCount] using count_cost_le_upper xs

theorem length_bound {α : Type} [LinearOrder α] (xs : List α) :
    (runCounted .lengthBalanced xs).time ≤ xs.length - 1 + (lengthPlan (scan xs)).budget := by
  simpa only [run_counted_eq, Strategy.program, scan_eq] using cost_le_tree_budget lengthPlan xs

theorem count_sorted_exact {α : Type} [LinearOrder α] (xs : List α) (h : xs.Pairwise (· ≤ ·)) :
    (runCounted .countBalanced xs).time = xs.length - 1 := by
  simpa only [run_counted_eq, Strategy.program] using count_cost_of_sorted xs h

theorem length_sorted_exact {α : Type} [LinearOrder α] (xs : List α) (h : xs.Pairwise (· ≤ ·)) :
    (runCounted .lengthBalanced xs).time = xs.length - 1 := by
  simpa only [run_counted_eq, Strategy.program] using length_cost_of_sorted xs h

theorem count_isBigO_structural {α : Type} [LinearOrder α] :
    (fun xs : List α => ((runCounted .countBalanced xs).time : ℝ)) =O[
      Filter.comap List.length Filter.atTop]
      (fun xs : List α => structuralScale xs.length (scan xs).length) := by
  simpa only [run_counted_eq, Strategy.program, scan_eq, runCount] using
    (count_cost_isBigO_structural (α := α))

theorem count_isBigO_nlog {α : Type} [LinearOrder α] :
    (fun xs : List α => ((runCounted .countBalanced xs).time : ℝ)) =O[
      Filter.comap List.length Filter.atTop]
      (fun xs : List α => (xs.length : ℝ) * Real.log xs.length) := by
  simpa only [run_counted_eq, Strategy.program] using (count_cost_isBigO_nlog (α := α))

theorem diagnostic_bound_eq {α : Type} [LinearOrder α] (s : Strategy) (xs : List α) :
    diagnosticBound s xs = s.bound xs := by
  cases s <;> simp [diagnosticBound, Strategy.bound, upper, runCount, scan_eq]

end LeanSort.Direct
