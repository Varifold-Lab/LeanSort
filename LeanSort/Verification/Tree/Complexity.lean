import LeanSort.Verification.Tree.Cost
import Mathlib.Analysis.SpecialFunctions.Choose

/-! Quadratic worst-case key comparisons and linear final traversal visits.
These theorems do not assert average-case or wall-clock complexity. -/

namespace LeanSort.Tree

open Asymptotics

def treeWorstComparisonCost (n : Nat) : Nat := n.choose 2

theorem treeComparisonCost_le_worst {α : Type*} [LinearOrder α] (xs : List α) :
    treeComparisonCost xs ≤ treeWorstComparisonCost xs.length := treeComparisonCost_le xs

theorem replicate_attains_treeWorstComparisonCost {α : Type*} [LinearOrder α]
    (x : α) (n : Nat) :
    (List.replicate n x).length = n ∧
      treeComparisonCost (List.replicate n x) = treeWorstComparisonCost n := by
  simp [treeWorstComparisonCost, treeComparisonCost_replicate]

theorem treeWorstComparisonCost_isTheta_quadratic :
    (fun n : Nat => (treeWorstComparisonCost n : ℝ)) =Θ[Filter.atTop]
      (fun n : Nat => (n : ℝ) ^ 2) := by
  simpa only [treeWorstComparisonCost] using isTheta_choose 2

theorem treeComparisonCost_isBigO_quadratic {α : Type*} [LinearOrder α] :
    (fun xs : List α => (treeComparisonCost xs : ℝ)) =O[
      Filter.comap List.length Filter.atTop]
      (fun xs : List α => (xs.length : ℝ) ^ 2) := by
  have hbound : (fun xs : List α => (treeComparisonCost xs : ℝ)) =O[
      Filter.comap List.length Filter.atTop]
      (fun xs : List α => (xs.length.choose 2 : ℝ)) := by
    apply isBigO_of_le
    intro xs
    simp only [Real.norm_natCast]
    exact_mod_cast treeComparisonCost_le xs
  exact hbound.trans ((isTheta_choose 2).1.comp_tendsto Filter.tendsto_comap)

theorem treeTraversalCost_isTheta_length {α : Type*} [LinearOrder α] :
    (fun xs : List α => (treeTraversalCost xs : ℝ)) =Θ[
      Filter.comap List.length Filter.atTop]
      (fun xs : List α => (xs.length : ℝ)) := by
  simp only [treeTraversalCost_eq_length]
  exact isTheta_refl _ _

end LeanSort.Tree
