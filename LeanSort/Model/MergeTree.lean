import LeanSort.Model.SortingResult

namespace LeanSort.RunAdaptive

/-- A data-dependent alphabetic merge plan. Leaves retain their original order.
`empty` handles zero discovered runs without a fictitious empty run. -/
inductive MergeTree (α : Type) where
  | empty
  | leaf (run : List α)
  | node (left right : MergeTree α)
  deriving Repr

def MergeTree.leaves {α : Type} : MergeTree α → List (List α)
  | .empty => []
  | .leaf run => [run]
  | .node left right => left.leaves ++ right.leaves

def MergeTree.weight {α : Type} : MergeTree α → Nat
  | .empty => 0
  | .leaf run => run.length
  | .node left right => left.weight + right.weight

def MergeTree.depth {α : Type} : MergeTree α → Nat
  | .empty | .leaf _ => 0
  | .node left right => max left.depth right.depth + 1

/-- Sum of merged output lengths: an upper bound on key comparisons, NOT
a count of comparisons used to select tree edges or perform List traversals. -/
def MergeTree.budget {α : Type} : MergeTree α → Nat
  | .empty | .leaf _ => 0
  | .node left right => left.budget + right.budget + left.weight + right.weight

def ValidRuns {α : Type} [LinearOrder α] (xs : List α) (runs : List (List α)) : Prop :=
  runs.flatten = xs ∧ (∀ run ∈ runs, run.Pairwise (· ≤ ·)) ∧ (∀ run ∈ runs, run ≠ [])

end LeanSort.RunAdaptive
