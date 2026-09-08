import LeanSort.Verification.Heap.Cost
import Mathlib.Analysis.Asymptotics.Theta

/-! The number of extractions is Θ(n). This is not a linear-time sorting claim:
the comparisons and swaps inside each extraction are outside this cost model. -/

namespace LeanSort.Heap

open Asymptotics

theorem heapExtractionCost_isTheta_length {α : Type} [LinearOrder α] :
    (fun xs : List α => (heapExtractionCost xs : ℝ)) =Θ[
      Filter.comap List.length Filter.atTop]
      (fun xs : List α => (xs.length : ℝ)) := by
  simp only [heapExtractionCost_eq_length]
  exact isTheta_refl _ _

end LeanSort.Heap
