import LeanSort.Verification.Counting.Cost
import Mathlib.Analysis.Asymptotics.Basic

/-!
Counting sort has logical-work complexity `Θ(n + k)`. The filter allows either
the list length or the allocated key range to grow; `k` need not be bounded by `n`.
-/

namespace LeanSort.Counting

open Asymptotics

theorem countingWorkCost_isTheta_length_add_keyRange :
    (fun xs : List ℕ => (countingWorkCost xs : ℝ)) =Θ[
      Filter.comap (fun xs : List ℕ => xs.length + keyRange xs) Filter.atTop]
      (fun xs : List ℕ => (xs.length : ℝ) + (keyRange xs : ℝ)) := by
  constructor
  · apply IsBigO.of_bound 3
    apply Filter.Eventually.of_forall
    intro xs
    rw [Real.norm_natCast, Real.norm_of_nonneg (by positivity)]
    exact_mod_cast countingWorkCost_le xs
  · apply isBigO_of_le
    intro xs
    rw [Real.norm_natCast, Real.norm_of_nonneg (by positivity)]
    exact_mod_cast length_add_keyRange_le_countingWorkCost xs

end LeanSort.Counting
