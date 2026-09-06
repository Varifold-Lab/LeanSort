import LeanSort.Verification.Shell.Cost
import Mathlib.Analysis.Asymptotics.Basic

/-! Quadratic upper bound for swaps; this does not count allocation or trace construction. -/

namespace LeanSort.Shell

open Asymptotics

/-- With the implemented halving gaps, the generated swap count is O(n²). -/
theorem shellSwapCost_isBigO_length_sq {α : Type*} [LinearOrder α] :
    (fun xs : List α => (shellSwapCost xs : ℝ)) =O[
      Filter.comap List.length Filter.atTop]
      (fun xs : List α => (xs.length : ℝ) ^ 2) := by
  apply IsBigO.of_bound 2
  filter_upwards with xs
  simp only [norm_pow, Real.norm_natCast]
  exact_mod_cast shellSwapCost_le_two_mul_sq xs

end LeanSort.Shell
