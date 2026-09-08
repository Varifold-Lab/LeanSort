import LeanSort.Verification.CostedPlan.Cost
import LeanSort.Verification.Comparison.Bounds
import LeanSort.Verification.Merge.Complexity

namespace LeanSort.CostedPlan
open Filter Asymptotics

def logBase (n : Nat) : Nat := n * Nat.clog 2 n + n

theorem logBase_monotone : Monotone logBase := by
  intro a b h
  exact Nat.add_le_add (Nat.mul_le_mul h (Nat.clog_monotone 2 h)) h

theorem le_logBase (n : Nat) : n ≤ logBase n := by unfold logBase; omega

theorem Schema.upper_le_quadratic (p : Schema) (n : Nat) :
    p.upper n ≤ p.quadraticWeight * n ^ 2 := by
  induction p generalizing n with
  | leaf c =>
    cases c with
    | merge => simpa [Schema.upper, Component.upper, Schema.quadraticWeight] using
        ComparisonBounds.mergeSort_le_square n
    | insertion => simpa [Schema.upper, Component.upper, Schema.quadraticWeight] using
        ComparisonBounds.insertion_le_square n
    | hybrid t => exact ComparisonBounds.hybrid_le_square t n
  | split cut left right ihl ihr =>
    have hl := ihl (cut.position n)
    have hr := ihr (n - cut.position n)
    have hla := Nat.mul_le_mul_left left.quadraticWeight
      (Nat.pow_le_pow_left (cut.position_le n) 2)
    have hrb := Nat.mul_le_mul_left right.quadraticWeight
      (Nat.pow_le_pow_left (Nat.sub_le n (cut.position n)) 2)
    have hn : n ≤ n ^ 2 := by nlinarith
    simp only [Schema.upper, Schema.quadraticWeight]
    nlinarith
  | guardSorted fallback ih =>
    have hf := ih n
    have hn : n ≤ n ^ 2 := by nlinarith
    simp only [Schema.upper, Schema.quadraticWeight]
    nlinarith [Nat.sub_le n 1]

theorem Schema.upper_le_logBase (p : Schema) (n k : Nat) (cert : p.logWeight = some k) :
    p.upper n ≤ k * logBase n := by
  induction p generalizing n k with
  | leaf c =>
    cases c with
    | merge =>
      simp only [Schema.logWeight, Option.some.injEq] at cert
      subst k
      simp only [Schema.upper, Component.upper, ComparisonBounds.mergeSort, one_mul, logBase]
      omega
    | insertion => simp [Schema.logWeight] at cert
    | hybrid t =>
      simp only [Schema.logWeight, Option.some.injEq] at cert
      subst k
      have h := ComparisonBounds.hybrid_le_log_add t n
      simp only [Schema.upper, Component.upper, logBase]
      nlinarith [Nat.zero_le (max 1 t * (n * Nat.clog 2 n))]
  | split cut left right ihl ihr =>
    cases hl : left.logWeight with
    | none => simp [Schema.logWeight, hl] at cert
    | some kl =>
      cases hr : right.logWeight with
      | none => simp [Schema.logWeight, hl, hr] at cert
      | some kr =>
        simp [Schema.logWeight, hl, hr] at cert
        subst k
        have hleft := ihl (cut.position n) kl hl
        have hright := ihr (n - cut.position n) kr hr
        have hla := Nat.mul_le_mul_left kl (logBase_monotone (cut.position_le n))
        have hrb := Nat.mul_le_mul_left kr (logBase_monotone (Nat.sub_le n (cut.position n)))
        have hn := le_logBase n
        simp only [Schema.upper]
        nlinarith
  | guardSorted fallback ih =>
    cases hf : fallback.logWeight with
    | none => simp [Schema.logWeight, hf] at cert
    | some kf =>
      simp [Schema.logWeight, hf] at cert
      subst k
      have hp := ih n kf hf
      have hn := le_logBase n
      simp only [Schema.upper]
      nlinarith [Nat.sub_le n 1]

theorem logBase_isBigO_nlog :
    (fun n : Nat => (logBase n : ℝ)) =O[atTop]
      (fun n : Nat => (n : ℝ) * Real.log (n : ℝ)) := by
  have hb : (fun n : Nat => (logBase n : ℝ)) =O[atTop]
      (fun n : Nat => (Merge.mergeComparisonUpperBound n : ℝ)) := by
    apply IsBigO.of_bound 2
    filter_upwards [eventually_ge_atTop 2] with n hn
    simp only [Real.norm_natCast]
    have hlog : 1 ≤ Nat.clog 2 n := Nat.clog_pos (by omega) (by omega)
    have h : logBase n ≤ 2 * Merge.mergeComparisonUpperBound n := by
      have hm := Nat.mul_le_mul_left n hlog
      simp only [logBase, Merge.mergeComparisonUpperBound]
      nlinarith
    exact_mod_cast h
  exact hb.trans Merge.mergeComparisonUpperBound_isBigO_n_mul_log

theorem Schema.upper_isBigO_quadratic (p : Schema) :
    (fun n : Nat => (p.upper n : ℝ)) =O[atTop] (fun n : Nat => (n : ℝ) ^ 2) := by
  apply IsBigO.of_bound (p.quadraticWeight : ℝ)
  filter_upwards with n
  rw [Real.norm_natCast, Real.norm_eq_abs, abs_of_nonneg (sq_nonneg _)]
  exact_mod_cast p.upper_le_quadratic n

theorem Schema.upper_isBigO_nlog (p : Schema) (k : Nat) (cert : p.logWeight = some k) :
    (fun n : Nat => (p.upper n : ℝ)) =O[atTop]
      (fun n : Nat => (n : ℝ) * Real.log (n : ℝ)) := by
  have hb : (fun n : Nat => (p.upper n : ℝ)) =O[atTop] (fun n : Nat => (logBase n : ℝ)) := by
    apply IsBigO.of_bound (k : ℝ)
    filter_upwards with n
    simp only [Real.norm_natCast]
    exact_mod_cast p.upper_le_logBase n k cert
  exact hb.trans logBase_isBigO_nlog

/-- Transfers a length envelope to actual operational cost on arbitrary lists. -/
theorem Schema.cost_isBigO_of_upper {α : Type} [LinearOrder α] (p : Schema) (g : Nat → ℝ)
    (envelope : (fun n : Nat => (p.upper n : ℝ)) =O[atTop] g) :
    (fun xs : List α => ((p.eval xs).time : ℝ)) =O[Filter.comap List.length atTop]
      (fun xs : List α => g xs.length) := by
  have hc : (fun xs : List α => ((p.eval xs).time : ℝ)) =O[Filter.comap List.length atTop]
      (fun xs : List α => (p.upper xs.length : ℝ)) := by
    apply IsBigO.of_bound 1
    filter_upwards with xs
    simp only [Real.norm_natCast, one_mul]
    exact_mod_cast p.cost_le_upper xs
  have he := envelope.comp_tendsto
    (Filter.tendsto_comap : Tendsto (List.length : List α → Nat) (Filter.comap List.length atTop) atTop)
  exact hc.trans he

end LeanSort.CostedPlan
