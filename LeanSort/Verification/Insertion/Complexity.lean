import LeanSort.Verification.Insertion.Cost
import Mathlib.Analysis.SpecialFunctions.Choose

/-!
# Worst-case swap complexity of insertion sort

This module measures only the adjacent transpositions recorded in the insertion-sort
trace. It does not state a bound on comparisons or on the total running time.
-/

namespace LeanSort.Insertion

open Asymptotics

/-- The worst possible adjacent-swap cost on an input of length `n`. -/
def insertionWorstSwapCost (n : ℕ) : ℕ :=
  n.choose 2

/-- Every input's swap cost is bounded by the worst cost for its length. -/
theorem insertionSwapCost_le_worstSwapCost {α : Type*} [LinearOrder α]
    (xs : List α) :
    insertionSwapCost xs ≤ insertionWorstSwapCost xs.length := by
  rw [insertionSwapCost_eq_inversions, insertionWorstSwapCost]
  exact inversions_le_choose_two xs

/-- The canonical reverse-ordered input attains the worst swap cost. -/
theorem descendingRange_attains_insertionWorstSwapCost (n : ℕ) :
    (descendingRange n).length = n ∧
      insertionSwapCost (descendingRange n) = insertionWorstSwapCost n := by
  simp [insertionWorstSwapCost]

/-- Insertion sort's worst-case adjacent-swap cost is `Θ(n²)`. -/
theorem insertionWorstSwapCost_isTheta_quadratic :
    (fun n : ℕ => (insertionWorstSwapCost n : ℝ)) =Θ[Filter.atTop]
      (fun n : ℕ => (n : ℝ) ^ 2) := by
  simpa only [insertionWorstSwapCost] using isTheta_choose 2

end LeanSort.Insertion
