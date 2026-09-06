import LeanSort.Verification.Selection.Cost
import Mathlib.Analysis.Asymptotics.Basic

/-!
# Asymptotic swap complexity of selection sort

This module measures only the arbitrary-position swaps recorded in the selection-sort
trace. It does not state a bound on comparisons or on the total running time.
-/

namespace LeanSort.Selection

open Asymptotics

/-- Along lists whose lengths tend to infinity, selection sort's swap count is
`O(n)`. Both sides are cast to `ℝ`, the normed codomain used by mathlib's
asymptotics library. -/
theorem selectionSwapCost_isBigO_length {α : Type*} [LinearOrder α] :
    (fun xs : List α => (selectionSwapCost xs : ℝ)) =O[
      Filter.comap List.length Filter.atTop]
      (fun xs : List α => (xs.length : ℝ)) := by
  apply Asymptotics.isBigO_of_le
  intro xs
  simp only [Real.norm_natCast]
  exact_mod_cast selectionSwapCost_le xs

end LeanSort.Selection
