import LeanSort.Verification.Radix.Cost
import Mathlib.Analysis.Asymptotics.Basic

/-!
# Radix time complexity: why Theta(n * b)?

**Main result:** in the scan/partition/append work model,
`n * b ≤ radixWorkCost xs ≤ 3 * (n * b)`, hence `radixWorkCost = Θ(n * b)`.

## Parameters and derivation

* `n = xs.length`: number of elements.
* `b = radixBits xs = (xs.foldl max 0).log2 + 1`: number of binary passes.
  A positive maximum uses its binary digit count; empty/all-zero inputs use one pass.
* Each pass visits `n` elements and copies between `0` and `n` zero-bucket nodes.
  It preserves length, so all `b` passes together cost between `n*b` and `2*n*b`.
* The initial maximum scan costs `n`. Since `b ≥ 1`, `n ≤ n*b`.
  Therefore `n*b ≤ W(xs) ≤ n + 2*n*b ≤ 3*n*b`.

This chain is proved in `radixWorkCost_bounds`; it is not a postulated formula.
`sortWithWork_result` proves that the costed run returns `radixSortResult xs`.

## Meaning and limits

A unit is one maximum-scan visit, one partition visit (digit test + bucket
placement), or one node copied by list append. This is algorithm-level work,
not the elapsed time or instruction count of Lean's implementation. Bit arithmetic,
pass-index construction, allocation overhead, and instrumentation are excluded.
The separate trace counter `digitTests` is exactly `n*b`, not the whole work.

In the statement below, casts to `ℝ` let mathlib compare costs using real bounds.
`=Θ` means both an asymptotic upper and lower bound. The `comap ... atTop`
filter means `n*b` tends to infinity; it does not assume a distribution of inputs.
Both `n` and `b` depend on the input: this is not unconditional linear time in `n`.
-/

namespace LeanSort.Radix

open Asymptotics

/-- **Main complexity theorem:** scan/partition/append work is Θ(n * b).
The constants 3 (upper bound) and 1 (lower bound) work on every input. -/
theorem radixWorkCost_isTheta_workload :
    (fun xs : List ℕ => (radixWorkCost xs : ℝ)) =Θ[
      Filter.comap (fun xs : List ℕ => xs.length * radixBits xs) Filter.atTop]
      (fun xs => (xs.length : ℝ) * (radixBits xs : ℝ)) := by
  constructor
  · -- Upper bound: W(xs) ≤ 3 * (n * b).
    apply IsBigO.of_bound 3
    apply Filter.Eventually.of_forall
    intro xs
    rw [Real.norm_natCast, Real.norm_of_nonneg (by positivity)]
    exact_mod_cast (radixWorkCost_bounds xs).2
  · -- Lower bound: n * b ≤ W(xs).
    apply isBigO_of_le
    intro xs
    rw [Real.norm_natCast, Real.norm_of_nonneg (by positivity)]
    exact_mod_cast (radixWorkCost_bounds xs).1

/-- For digit tests alone, the exact equality gives Theta along any input family.
The work theorem above additionally accounts for the maximum scan and append copies. -/
theorem digitTests_isTheta (l : Filter (List ℕ)) :
    (fun xs : List ℕ => (digitTests xs : ℝ)) =Θ[l]
      (fun xs => (xs.length : ℝ) * (radixBits xs : ℝ)) := by
  simp only [digitTests_eq, Nat.cast_mul]
  exact ⟨isBigO_refl _ _, isBigO_refl _ _⟩

/-- The narrower digit-test counter is also Θ(n * b) as workload grows. -/
theorem digitTests_isTheta_workload :
    (fun xs : List ℕ => (digitTests xs : ℝ)) =Θ[
      Filter.comap (fun xs : List ℕ => xs.length * radixBits xs) Filter.atTop]
      (fun xs => (xs.length : ℝ) * (radixBits xs : ℝ)) :=
  digitTests_isTheta _

end LeanSort.Radix
