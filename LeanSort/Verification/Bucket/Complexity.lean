import LeanSort.Verification.Bucket.Cost
import Mathlib.Analysis.Asymptotics.Theta
import Mathlib.Analysis.Asymptotics.Lemmas

/-! Unconditional O(n²) key comparisons and Θ(n) distribution events.
Expected linear behavior would require a separate input-distribution model. -/

namespace LeanSort.Bucket

open Asymptotics

theorem comparisonBudget_le_square (n : Nat) : n + n.choose 2 ≤ n ^ 2 := by
  cases n with
  | zero => simp
  | succ n =>
      have h := Nat.div_le_self ((n + 1) * n) 2
      simp only [Nat.choose_two_right, Nat.add_sub_cancel, pow_two]
      simp only [Nat.mul_add, Nat.add_mul, Nat.mul_one, Nat.one_mul] at *
      omega

theorem bucketComparisonCost_isBigO_quadratic :
    (fun xs : List Nat => (bucketComparisonCost xs : ℝ)) =O[
      Filter.comap List.length Filter.atTop]
      (fun xs : List Nat => (xs.length : ℝ) ^ 2) := by
  apply isBigO_of_le
  intro xs
  rw [Real.norm_natCast, Real.norm_eq_abs, abs_of_nonneg (sq_nonneg _)]
  exact_mod_cast (bucketComparisonCost_le xs).trans (comparisonBudget_le_square xs.length)

theorem bucketPlacementCost_isTheta_length :
    (fun xs : List Nat => (bucketPlacementCost xs : ℝ)) =Θ[
      Filter.comap List.length Filter.atTop]
      (fun xs : List Nat => (xs.length : ℝ)) := by
  simp only [bucketPlacementCost_eq_length]
  exact isTheta_refl _ _

end LeanSort.Bucket
