import LeanSort.Verification.Bubble.Cost
import Mathlib.Analysis.SpecialFunctions.Choose

/-!
# Worst-case swap complexity of bubble sort

This module measures only the adjacent transpositions recorded in the bubble-sort
trace. It does not state a bound on comparisons or on the total running time.
-/

namespace LeanSort.Bubble

open Asymptotics

/-- The worst possible adjacent-swap cost on an input of length `n`. -/
def bubbleWorstSwapCost (n : ℕ) : ℕ :=
  n.choose 2

/-- Every input's swap cost is bounded by the worst cost for its length. -/
theorem bubbleSwapCost_le_worstSwapCost {α : Type*} [LinearOrder α]
    (xs : List α) :
    bubbleSwapCost xs ≤ bubbleWorstSwapCost xs.length := by
  rw [bubbleSwapCost_eq_inversions, bubbleWorstSwapCost]
  exact inversions_le_choose_two xs

/-- The canonical reverse-ordered input attains the worst swap cost. -/
theorem descendingRange_attains_bubbleWorstSwapCost (n : ℕ) :
    (descendingRange n).length = n ∧
      bubbleSwapCost (descendingRange n) = bubbleWorstSwapCost n := by
  simp [bubbleWorstSwapCost]

/-- Bubble sort's worst-case adjacent-swap cost is `Θ(n²)`. -/
theorem bubbleWorstSwapCost_isTheta_quadratic :
    (fun n : ℕ => (bubbleWorstSwapCost n : ℝ)) =Θ[Filter.atTop]
      (fun n : ℕ => (n : ℝ) ^ 2) := by
  simpa only [bubbleWorstSwapCost] using isTheta_choose 2

end LeanSort.Bubble
