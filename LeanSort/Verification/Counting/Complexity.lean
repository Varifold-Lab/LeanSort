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
  refine ⟨isBigO_of_le' (c := 3) _ ?_, isBigO_of_le _ ?_⟩ <;>
    intro xs <;> simp only [← Nat.cast_add, Real.norm_natCast]
  · exact_mod_cast countingWorkCost_le xs
  · exact_mod_cast length_add_keyRange_le_countingWorkCost xs

end LeanSort.Counting
