import LeanSort.Verification.Pancake.Cost
import Mathlib.Analysis.Asymptotics.Basic

/-!
# Asymptotic flip complexity of pancake sort

This module counts prefix reversals, not comparisons or the element-level work performed
inside a reversal.
-/

namespace LeanSort.Pancake

open Asymptotics

/-- Along lists whose lengths tend to infinity, pancake sort emits `O(n)` flips. -/
theorem pancakeFlipCost_isBigO_length {α : Type*} [LinearOrder α] :
    (fun xs : List α => (pancakeFlipCost xs : ℝ)) =O[
      Filter.comap List.length Filter.atTop]
      (fun xs : List α => (xs.length : ℝ)) := by
  apply IsBigO.of_bound 2
  filter_upwards with xs
  simp only [Real.norm_natCast]
  exact_mod_cast pancakeFlipCost_le_two_mul_length xs

end LeanSort.Pancake
