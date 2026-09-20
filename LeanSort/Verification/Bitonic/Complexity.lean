import LeanSort.Verification.Bitonic.Cost
import Mathlib.Tactic.Linarith

namespace LeanSort.Bitonic

/-- Power-of-two padding increases nonempty input size by less than a factor of two. -/
theorem paddedLength_lt_twice (n : Nat) (hn : 0 < n) :
    2 ^ networkDepth n < 2 * n := by
  unfold networkDepth
  split
  · simp only [Nat.pow_zero]
    omega
  · have h := Nat.log2_self_le (n := n - 1) (by omega)
    rw [Nat.pow_succ]
    omega

/-- An explicit bound in input length and ceiling-log depth; no asymptotic
or machine-time claim is needed to use this inequality. -/
theorem comparisonCost_bound (n : Nat) :
    sortComparisons (networkDepth n) ≤ n * networkDepth n * (networkDepth n + 1) := by
  by_cases hn : n = 0
  · subst n
    simp [networkDepth, sortComparisons]
  · have hp := paddedLength_lt_twice n (by omega)
    have he := sortComparisons_exact (networkDepth n)
    have hb := Nat.mul_le_mul_right (networkDepth n * (networkDepth n + 1))
      (Nat.le_of_lt hp)
    nlinarith

end LeanSort.Bitonic
