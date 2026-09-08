import LeanSort.Verification.Direct.Morphism

/-! Equality of entire comparison decision trees, not only sorted outputs.
The symbolic instance instruments the same Engine functions used by Id/TimeM.
-/
namespace LeanSort.Direct
open Comparison RunAdaptive

theorem symbolic_scanTail {α : Type} (x : α) (xs : List α) :
    Engine.scanTail symbolicCompare x xs = scanTail x xs := by
  induction xs generalizing x <;>
    simp [Engine.scanTail, scanTail, symbolicCompare, bind, pure, Program.bind, *]

theorem symbolic_discover {α : Type} (xs : List α) :
    Engine.discover symbolicCompare xs = discover xs := by
  cases xs <;> simp [Engine.discover, discover, symbolic_scanTail, bind, pure]

theorem symbolic_merge {α : Type} (xs ys : List α) :
    Engine.merge symbolicCompare xs ys = ComparisonSort.merge xs ys := by
  cases xs with
  | nil => simp [Engine.merge, ComparisonSort.merge, pure]
  | cons x xs =>
    cases ys with
    | nil => simp [Engine.merge, ComparisonSort.merge, pure]
    | cons y ys =>
      simp [Engine.merge, ComparisonSort.merge, symbolicCompare, bind, pure,
        Program.bind, symbolic_merge xs (y :: ys), symbolic_merge (x :: xs) ys]
termination_by xs.length + ys.length

theorem symbolic_insert {α : Type} (x : α) (xs : List α) :
    Engine.insert symbolicCompare x xs = ComparisonSort.insert x xs := by
  induction xs <;> simp [Engine.insert, ComparisonSort.insert, symbolicCompare,
    bind, pure, Program.bind, *]

theorem symbolic_insertion {α : Type} (xs : List α) :
    Engine.insertion symbolicCompare xs = ComparisonSort.insertion xs := by
  induction xs <;> simp [Engine.insertion, ComparisonSort.insertion, symbolic_insert,
    bind, pure, *]

theorem symbolic_mergeSort {α : Type} (xs : List α) :
    Engine.mergeSort symbolicCompare xs = ComparisonSort.mergeSort xs := by
  rw [Engine.mergeSort.eq_def, ComparisonSort.mergeSort.eq_def]
  split_ifs with h
  · rfl
  · simp only [bind, symbolic_mergeSort (xs.take (xs.length / 2)),
      symbolic_mergeSort (xs.drop (xs.length / 2)), symbolic_merge]
termination_by xs.length
decreasing_by all_goals simp_wf; omega

theorem symbolic_hybrid {α : Type} (t : Nat) (xs : List α) :
    Engine.hybrid symbolicCompare t xs = ComparisonSort.hybrid t xs := by
  rw [Engine.hybrid.eq_def, ComparisonSort.hybrid.eq_def]
  split_ifs with h
  · exact symbolic_insertion xs
  · simp only [bind, symbolic_hybrid t (xs.take (xs.length / 2)),
      symbolic_hybrid t (xs.drop (xs.length / 2)), symbolic_merge]
termination_by xs.length
decreasing_by all_goals simp_wf; omega

theorem symbolic_checkSorted {α : Type} (xs : List α) :
    Engine.checkSorted symbolicCompare xs = ComparisonSort.checkSorted xs := by
  match xs with
  | [] => rfl
  | [_] => rfl
  | x :: y :: ys =>
    simp [Engine.checkSorted, ComparisonSort.checkSorted, symbolicCompare, bind, pure,
      Program.bind, symbolic_checkSorted (y :: ys)]

theorem symbolic_component {α : Type} (c : CostedPlan.Component) (xs : List α) :
    Engine.component symbolicCompare c xs = c.program xs := by
  cases c <;> simp [Engine.component, CostedPlan.Component.program, symbolic_mergeSort,
    symbolic_insertion, symbolic_hybrid]

theorem symbolic_schema {α : Type} (p : CostedPlan.Schema) (xs : List α) :
    Engine.schema symbolicCompare p xs = p.program xs := by
  induction p generalizing xs <;> simp [Engine.schema, CostedPlan.Schema.program,
    bind, pure, symbolic_component, symbolic_merge, symbolic_checkSorted, *]

theorem symbolic_tree {α : Type} (t : MergeTree α) :
    Engine.tree symbolicCompare t = t.program := by
  induction t <;> simp [Engine.tree, MergeTree.program, bind, pure, symbolic_merge, *]

theorem symbolic_adaptive {α : Type} (planner : List (List α) → MergeTree α) (xs : List α) :
    Engine.adaptive symbolicCompare planner xs = sortProgram planner xs := by
  simp [Engine.adaptive, sortProgram, bind, symbolic_discover, symbolic_tree]

theorem symbolic_strategy {α : Type} (s : Strategy) (xs : List α) :
    Engine.strategy symbolicCompare s xs = s.program xs := by
  cases s <;> simp [Engine.strategy, Strategy.program, symbolic_schema, symbolic_adaptive]

end LeanSort.Direct

