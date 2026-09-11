import LeanSort.Verification.Selection.Comparisons
import Mathlib.Analysis.SpecialFunctions.Choose

/-!
# Asymptotic swap and comparison complexity of selection sort

Swaps are O(n), while minimum-scan comparisons are exactly n choose 2 and Θ(n²).
Neither model counts list allocation, copying, or total elapsed running time.
-/

namespace LeanSort.Selection

open Asymptotics

/-- Along lists whose lengths tend to infinity, selection sort's swap count is
`O(n)`. Both sides are cast to `ℝ`, the normed codomain used by mathlib's
asymptotics library. -/
theorem selectionSwapCost_isBigO_length {α : Type*} [LinearOrder α] :
    (fun xs : List α => (selectionSwapCost xs : ℝ)) =O[
      Filter.comap List.length Filter.atTop]
      (fun xs : List α => (xs.length : ℝ)) := by
  apply Asymptotics.isBigO_of_le
  intro xs
  simp only [Real.norm_natCast]
  exact_mod_cast selectionSwapCost_le xs

/-- Selection's key-comparison cost is Θ(n²) on all inputs as length grows. -/
theorem selectionComparisonCost_isTheta_quadratic {α : Type*} [LinearOrder α] :
    (fun xs : List α => (selectionComparisonCost xs : ℝ)) =Θ[
      Filter.comap List.length Filter.atTop]
      (fun xs : List α => (xs.length : ℝ) ^ 2) := by
  have ht : Filter.Tendsto (List.length (α := α))
      (Filter.comap List.length Filter.atTop) Filter.atTop := Filter.tendsto_comap
  constructor
  · simpa only [selectionComparisonCost_eq, Function.comp_def] using
      ((isTheta_choose 2).1.comp_tendsto ht)
  · simpa only [selectionComparisonCost_eq, Function.comp_def] using
      ((isTheta_choose 2).2.comp_tendsto ht)

end LeanSort.Selection
