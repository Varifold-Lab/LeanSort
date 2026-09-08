import LeanSort.Model.SortingPlan
import LeanSort.Algorithm.ComparisonSort
import LeanSort.Algorithm.Adaptive

namespace LeanSort.CostedPlan
open Comparison

def Component.program {α : Type} : Component → List α → Program α (List α)
  | .merge, xs => ComparisonSort.mergeSort xs
  | .insertion, xs => ComparisonSort.insertion xs
  | .hybrid t, xs => ComparisonSort.hybrid t xs

def Schema.program {α : Type} : Schema → List α → Program α (List α)
  | .leaf c, xs => c.program xs
  | .split cut left right, xs =>
    (left.program (xs.take (cut.position xs.length))).bind fun ls =>
    (right.program (xs.drop (cut.position xs.length))).bind fun rs => ComparisonSort.merge ls rs
  | .guardSorted fallback, xs =>
    (ComparisonSort.checkSorted xs).bind fun sorted =>
      if sorted then .pure xs else fallback.program xs

def Schema.eval {α : Type} [LinearOrder α] (p : Schema) (xs : List α) : Result (List α) :=
  (p.program xs).eval

/-- The executable algorithm is the output projection of this same costed semantics. -/
@[noinline] def Schema.run {α : Type} [LinearOrder α] (p : Schema) (xs : List α) : List α :=
  (p.eval xs).ret

def Schema.ofAdaptive : Adaptive.Plan → Schema
  | .merge => .leaf .merge
  | .insertion => .leaf .insertion
  | .hybrid t => .leaf (.hybrid t)
  | .split cut l r => .split (.prefix cut) (ofAdaptive l) (ofAdaptive r)

end LeanSort.CostedPlan
