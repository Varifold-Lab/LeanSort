import LeanSort.Verification.RunAdaptive.Cost
import LeanSort.Verification.CostedPlan.Complexity

namespace LeanSort.RunAdaptive
open Filter Asymptotics

/-- Real-valued form of the structural comparison envelope. max(1,r) makes the
zero-run input explicit; neither r nor its logarithm is hidden in a constant. -/
noncomputable def structuralScale (n r : Nat) : ℝ := (n : ℝ) * (1 + Real.log (max 1 r : Nat))

theorem clog_le_real (r : Nat) :
    (Nat.clog 2 r : ℝ) ≤ Real.logb 2 (max 1 r : Nat) + 1 := by
  have hmono : Nat.clog 2 r ≤ Nat.clog 2 (max 1 r) := Nat.clog_monotone 2 (Nat.le_max_right _ _)
  have hp : (1 : ℝ) ≤ (max 1 r : Nat) := by exact_mod_cast Nat.le_max_left 1 r
  have hlog : 0 ≤ Real.logb 2 (max 1 r : Nat) := Real.logb_nonneg (by norm_num) hp
  have hc : (Nat.clog 2 (max 1 r) : ℝ) < Real.logb 2 (max 1 r : Nat) + 1 := by
    rw [← Real.natCeil_logb_natCast]
    exact Nat.ceil_lt_add_one hlog
  have hm : (Nat.clog 2 r : ℝ) ≤ Nat.clog 2 (max 1 r) := by exact_mod_cast hmono
  exact hm.trans hc.le

/-- A single real constant works for all n and r, including zero. -/
theorem upper_le_structuralScale (n r : Nat) :
    (upper n r : ℝ) ≤ (2 + (Real.log 2)⁻¹) * structuralScale n r := by
  have hlog : 0 ≤ Real.log (max 1 r : Nat) := Real.log_nonneg (by exact_mod_cast Nat.le_max_left 1 r)
  have hinv : 0 ≤ (Real.log 2)⁻¹ := le_of_lt (inv_pos.mpr (Real.log_pos (by norm_num)))
  have hn : (0 : ℝ) ≤ n := Nat.cast_nonneg n
  have hsub : ((n - 1 : Nat) : ℝ) ≤ n := by exact_mod_cast Nat.sub_le n 1
  have hc := mul_le_mul_of_nonneg_left (clog_le_real r) hn
  have hextra := mul_nonneg hn (add_nonneg (mul_nonneg (by norm_num : (0 : ℝ) ≤ 2) hlog) hinv)
  simp only [upper, Nat.cast_add, Nat.cast_mul, structuralScale, Real.logb, div_eq_mul_inv] at *
  nlinarith

theorem count_cost_isBigO_structural {α : Type} [LinearOrder α] :
    (fun xs : List α => ((sortProgram countPlan xs).eval.time : ℝ)) =O[
      Filter.comap List.length atTop]
      (fun xs : List α => structuralScale xs.length (runCount xs)) := by
  apply IsBigO.of_bound (2 + (Real.log 2)⁻¹)
  filter_upwards with xs
  have hscale : 0 ≤ structuralScale xs.length (runCount xs) := by
    unfold structuralScale
    apply mul_nonneg (Nat.cast_nonneg _)
    have h := Real.log_nonneg (show (1 : ℝ) ≤ (max 1 (runCount xs) : Nat) by
      exact_mod_cast Nat.le_max_left 1 (runCount xs))
    linarith
  rw [Real.norm_natCast, Real.norm_eq_abs, abs_of_nonneg hscale]
  have hc : ((sortProgram countPlan xs).eval.time : ℝ) ≤ (upper xs.length (runCount xs) : ℝ) := by
    exact_mod_cast count_cost_le_upper xs
  exact hc.trans (upper_le_structuralScale _ _)

theorem count_cost_isBigO_nlog {α : Type} [LinearOrder α] :
    (fun xs : List α => ((sortProgram countPlan xs).eval.time : ℝ)) =O[
      Filter.comap List.length atTop]
      (fun xs : List α => (xs.length : ℝ) * Real.log xs.length) := by
  have hb : (fun xs : List α => ((sortProgram countPlan xs).eval.time : ℝ)) =O[
      Filter.comap List.length atTop] (fun xs : List α => (CostedPlan.logBase xs.length : ℝ)) := by
    apply IsBigO.of_bound 1
    filter_upwards with xs
    simp only [Real.norm_natCast, one_mul]
    have h := count_cost_le_nlog_envelope xs
    have hh : upper xs.length xs.length ≤ CostedPlan.logBase xs.length := by
      simp only [upper, CostedPlan.logBase]
      omega
    exact_mod_cast h.trans hh
  exact hb.trans (CostedPlan.logBase_isBigO_nlog.comp_tendsto
    (Filter.tendsto_comap : Tendsto (List.length : List α → Nat) (Filter.comap List.length atTop) atTop))

theorem sorted_cost_isBigO_linear {α : Type} [LinearOrder α] :
    (fun xs : {xs : List α // xs.Pairwise (· ≤ ·)} =>
      ((sortProgram countPlan xs.val).eval.time : ℝ)) =O[
        Filter.comap (fun xs : {xs : List α // xs.Pairwise (· ≤ ·)} => xs.val.length) atTop]
      (fun xs : {xs : List α // xs.Pairwise (· ≤ ·)} => (xs.val.length : ℝ)) := by
  apply IsBigO.of_bound 1
  filter_upwards with xs
  rw [count_cost_of_sorted xs.val xs.property]
  simp only [Real.norm_natCast, one_mul]
  exact_mod_cast Nat.sub_le xs.val.length 1

end LeanSort.RunAdaptive
