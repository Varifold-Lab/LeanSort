import LeanSort.Verification.Merge.Cost
import Mathlib.Analysis.Asymptotics.Lemmas
import Mathlib.Analysis.SpecialFunctions.Log.Base

/-!
# Merge-sort asymptotic comparison complexity

The concrete trace cost is uniformly bounded by `n * ⌈log₂ n⌉`. This module
shows that this certified worst-case upper envelope is `O(n log n)` over `ℝ`.
-/

namespace LeanSort.Merge

open Filter Asymptotics

/-- A certified upper envelope for merge-sort comparisons on inputs of length `n`. -/
def mergeComparisonUpperBound (n : ℕ) : ℕ :=
  n * Nat.clog 2 n

/-- Every concrete merge-sort comparison cost is below the certified envelope. -/
theorem mergeComparisonCost_le_upperBound
    {α : Type} [LinearOrder α] (xs : List α) :
    mergeComparisonCost xs ≤ mergeComparisonUpperBound xs.length :=
  mergeComparisonCost_le_length_mul_clog_two xs

/-- The discrete ceiling logarithm in base two is `O(log n)` after casting to `ℝ`. -/
private theorem clog_two_isBigO_log :
    (fun n : ℕ => (Nat.clog 2 n : ℝ)) =O[atTop]
      (fun n : ℕ => Real.log (n : ℝ)) := by
  apply IsBigO.of_bound (2 / Real.log 2)
  filter_upwards [eventually_ge_atTop 2] with n hn
  have hnreal : (2 : ℝ) ≤ (n : ℝ) := by
    exact_mod_cast hn
  have hlogb0 : 0 ≤ Real.logb 2 (n : ℝ) :=
    Real.logb_nonneg (by norm_num) (by linarith)
  have hlogb1 : 1 ≤ Real.logb 2 (n : ℝ) := by
    rw [← Real.logb_self_eq_one (by norm_num : (1 : ℝ) < 2)]
    exact
      (Real.logb_le_logb (by norm_num) (by norm_num) (by positivity)).2 hnreal
  have hceil :
      (Nat.clog 2 n : ℝ) < Real.logb 2 (n : ℝ) + 1 := by
    rw [← Real.natCeil_logb_natCast]
    exact Nat.ceil_lt_add_one hlogb0
  have hlog0 : 0 ≤ Real.log (n : ℝ) :=
    Real.log_nonneg (by linarith)
  rw [Real.norm_eq_abs, Real.norm_eq_abs,
    abs_of_nonneg (Nat.cast_nonneg _), abs_of_nonneg hlog0]
  calc
    (Nat.clog 2 n : ℝ) ≤ 2 * Real.logb 2 (n : ℝ) := by
      linarith
    _ = (2 / Real.log 2) * Real.log (n : ℝ) := by
      rw [Real.logb]
      ring

/-- The certified comparison envelope is `O(n log n)`. -/
theorem mergeComparisonUpperBound_isBigO_n_mul_log :
    (fun n : ℕ => (mergeComparisonUpperBound n : ℝ)) =O[atTop]
      (fun n : ℕ => (n : ℝ) * Real.log (n : ℝ)) := by
  have hn :
      (fun n : ℕ => (n : ℝ)) =O[atTop]
        (fun n : ℕ => (n : ℝ)) :=
    isBigO_refl _ _
  simpa only [mergeComparisonUpperBound, Nat.cast_mul] using
    hn.mul clog_two_isBigO_log

/-- Concrete merge-sort comparison cost is `O(n log n)` along growing input lengths. -/
theorem mergeComparisonCost_isBigO_length_mul_log
    {α : Type} [LinearOrder α] :
    (fun xs : List α => (mergeComparisonCost xs : ℝ)) =O[
      Filter.comap List.length Filter.atTop]
      (fun xs : List α => (xs.length : ℝ) * Real.log (xs.length : ℝ)) := by
  have hcost :
      (fun xs : List α => (mergeComparisonCost xs : ℝ)) =O[
        Filter.comap List.length Filter.atTop]
        (fun xs : List α => (mergeComparisonUpperBound xs.length : ℝ)) := by
    apply IsBigO.of_bound 1
    filter_upwards with xs
    simp only [Real.norm_natCast, one_mul]
    exact_mod_cast mergeComparisonCost_le_upperBound xs
  have henvelope :
      (fun xs : List α => (mergeComparisonUpperBound xs.length : ℝ)) =O[
        Filter.comap List.length Filter.atTop]
        (fun xs : List α => (xs.length : ℝ) * Real.log (xs.length : ℝ)) := by
    simpa only [Function.comp_def] using
      mergeComparisonUpperBound_isBigO_n_mul_log.comp_tendsto
        (Filter.tendsto_comap :
          Filter.Tendsto List.length
            (Filter.comap List.length Filter.atTop) Filter.atTop)
  exact hcost.trans henvelope

/-- Any natural-valued cost bounded by the certified envelope is `O(n log n)`. -/
theorem comparisonCost_isBigO_n_mul_log_of_le
    (cost : ℕ → ℕ)
    (hcost : ∀ n, cost n ≤ mergeComparisonUpperBound n) :
    (fun n : ℕ => (cost n : ℝ)) =O[atTop]
      (fun n : ℕ => (n : ℝ) * Real.log (n : ℝ)) := by
  apply (IsBigO.of_bound 1 ?_).trans
    mergeComparisonUpperBound_isBigO_n_mul_log
  filter_upwards with n
  simp only [Real.norm_natCast, one_mul]
  exact_mod_cast hcost n

end LeanSort.Merge
