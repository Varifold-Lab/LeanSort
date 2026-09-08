import LeanSort.Algorithm.RunLengthPlan
import LeanSort.Algorithm.CostedPlan

namespace LeanSort.RunAdaptive
open Comparison

inductive Strategy where
  | fixed (schema : CostedPlan.Schema)
  | countBalanced
  | lengthBalanced
  deriving Repr

def Strategy.program {α : Type} : Strategy → List α → Program α (List α)
  | .fixed p, xs => p.program xs
  | .countBalanced, xs => sortProgram countPlan xs
  | .lengthBalanced, xs => sortProgram lengthPlan xs

@[noinline] def Strategy.run {α : Type} [LinearOrder α] (s : Strategy) (xs : List α) : List α :=
  (s.program xs).eval.ret

end LeanSort.RunAdaptive
