import LeanSort.Verification.Radix.Cost
import Mathlib.Analysis.Asymptotics.Basic

/-! Tight bounds for the digit-test counter under the unit-cost digit model. -/

namespace LeanSort.Radix

open Asymptotics

/-- The exact counter gives a tight bound along any family of inputs. -/
theorem digitTests_isTheta (l : Filter (List ℕ)) :
    (fun xs : List ℕ => (digitTests xs : ℝ)) =Θ[l]
      (fun xs => (xs.length : ℝ) * (radixBits xs : ℝ)) := by
  simp only [digitTests_eq, Nat.cast_mul]
  exact ⟨isBigO_refl _ _, isBigO_refl _ _⟩

/-- In particular, the digit-test count is Θ(n b) as the workload grows. -/
theorem digitTests_isTheta_workload :
    (fun xs : List ℕ => (digitTests xs : ℝ)) =Θ[
      Filter.comap (fun xs : List ℕ => xs.length * radixBits xs) Filter.atTop]
      (fun xs => (xs.length : ℝ) * (radixBits xs : ℝ)) :=
  digitTests_isTheta _

end LeanSort.Radix
