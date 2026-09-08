import LeanSort.Algorithm.CostedPlan

namespace LeanSort.CostedPlan
open Comparison

/-- Isolated replay of exactly the guards that deployment executes. It never sorts
elements. Used to measure checking separately; normal execution already includes
these checks, so this diagnostic must NOT be added to deployment time again. -/
def Schema.checkProgram {α : Type} : Schema → List α → Program α Unit
  | .leaf _, _ => .pure ()
  | .split cut l r, xs =>
    (l.checkProgram (xs.take (cut.position xs.length))).bind fun _ =>
      r.checkProgram (xs.drop (cut.position xs.length))
  | .guardSorted fallback, xs =>
    (ComparisonSort.checkSorted xs).bind fun sorted =>
      if sorted then .pure () else fallback.checkProgram xs

/-- An offline diagnostic for applicability of a conditional theorem. Deployment
uses `guardSorted` in the main program; it does not invoke this second traversal. -/
def Schema.readyCheck {α : Type} [LinearOrder α] : Schema → List α → Bool
  | .leaf _, _ => true
  | .split cut l r, xs =>
    l.readyCheck (xs.take (cut.position xs.length)) &&
      r.readyCheck (xs.drop (cut.position xs.length))
  | .guardSorted _, xs => (ComparisonSort.checkSorted xs).eval.ret

end LeanSort.CostedPlan
