import LeanSort.Verification.Intro.Cost
import LeanSort.Verification.Heap.Complexity

/-! Worst-case O(n log n) key comparisons, including insertion and heap leaves.
No random pivots, balanced partitions, in-place execution, or wall-clock claim. -/

namespace LeanSort.Intro

open Asymptotics

theorem introComparisonCost_isBigO_length_mul_log {α : Type} [LinearOrder α] :
    (fun xs : List α => (introComparisonCost xs : ℝ)) =O[
      Filter.comap List.length Filter.atTop]
      (fun xs : List α => (xs.length : ℝ) * Real.log (xs.length : ℝ)) := by
  apply IsBigO.of_bound (26 / Real.log 2)
  filter_upwards [(Filter.eventually_ge_atTop 2).comap (List.length (α := α))] with xs hn
  have hnreal : (2 : ℝ) ≤ (xs.length : ℝ) := by exact_mod_cast hn
  have hlogb0 : 0 ≤ Real.logb 2 (xs.length : ℝ) :=
    Real.logb_nonneg (by norm_num) (by linarith)
  have hlogb1 : 1 ≤ Real.logb 2 (xs.length : ℝ) := by
    rw [← Real.logb_self_eq_one (by norm_num : (1 : ℝ) < 2)]
    exact (Real.logb_le_logb (by norm_num) (by norm_num) (by positivity)).2 hnreal
  have hfloor : (xs.length.log2 : ℝ) ≤ Real.logb 2 (xs.length : ℝ) := by
    rw [Nat.log2_eq_log_two, ← Real.natFloor_logb_natCast]
    exact Nat.floor_le hlogb0
  have hc : (introComparisonCost xs : ℝ) ≤
      (xs.length : ℝ) * (6 * (xs.length.log2 : ℝ) + 20) := by
    exact_mod_cast introComparisonCost_le xs
  have hlog0 : 0 ≤ Real.log (xs.length : ℝ) := Real.log_nonneg (by linarith)
  rw [Real.norm_natCast, Real.norm_eq_abs, abs_of_nonneg (mul_nonneg (Nat.cast_nonneg _) hlog0)]
  calc
    _ ≤ 26 * (xs.length : ℝ) * Real.logb 2 (xs.length : ℝ) := by nlinarith
    _ = _ := by rw [Real.logb]; ring

end LeanSort.Intro
