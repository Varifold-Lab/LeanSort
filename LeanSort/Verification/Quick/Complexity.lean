import LeanSort.Verification.Quick.Cost
import Mathlib.Analysis.SpecialFunctions.Choose

/-! Exact worst-case partition comparison cost. List allocation, concatenation,
trace construction, and replay are outside this model. -/

namespace LeanSort.Quick

open Asymptotics

/-- All keys at most the pivot form a single left branch. -/
theorem partition_eq_left {α : Type*} [LinearOrder α] (p : α) (xs : List α)
    (h : ∀ x ∈ xs, x ≤ p) : xs.partition (fun x => decide (x ≤ p)) = (xs, []) := by
  induction xs with
  | nil => simp
  | cons x xs ih =>
      have hx := h x (by simp)
      have ht : ∀ y ∈ xs, y ≤ p := fun y hy => h y (by simp [hy])
      simpa [List.partition_eq_filter_filter, Function.comp_def, hx] using ih ht

/-- Strictly greater keys form a single right branch. -/
theorem partition_eq_right {α : Type*} [LinearOrder α] (p : α) (xs : List α)
    (h : ∀ x ∈ xs, p < x) : xs.partition (fun x => decide (x ≤ p)) = ([], xs) := by
  induction xs with
  | nil => simp
  | cons x xs ih =>
      have hx := not_le_of_gt (h x (by simp))
      have ht : ∀ y ∈ xs, p < y := fun y hy => h y (by simp [hy])
      simpa [List.partition_eq_filter_filter, Function.comp_def, hx] using ih ht

/-- Nonincreasing inputs, including duplicates, attain the triangular bound. -/
theorem comparisonCost_of_nonincreasing {α : Type*} [LinearOrder α]
    (xs : List α) (h : xs.Pairwise (· ≥ ·)) : comparisonCost xs = xs.length.choose 2 := by
  induction xs with
  | nil => simp
  | cons p xs ih =>
      obtain ⟨hp, ht⟩ := List.pairwise_cons.mp h
      rw [comparisonCost_cons, partition_eq_left p xs hp]
      simp [ih ht, Nat.choose_succ_succ]

/-- Strictly increasing inputs also attain the bound, along the right branch. -/
theorem comparisonCost_of_strictlyIncreasing {α : Type*} [LinearOrder α]
    (xs : List α) (h : xs.Pairwise (· < ·)) : comparisonCost xs = xs.length.choose 2 := by
  induction xs with
  | nil => simp
  | cons p xs ih =>
      obtain ⟨hp, ht⟩ := List.pairwise_cons.mp h
      rw [comparisonCost_cons, partition_eq_right p xs hp]
      simp [ih ht, Nat.choose_succ_succ]

/-- A worst-case witness exists at every length, even over a one-key alphabet. -/
theorem comparisonCost_replicate {α : Type*} [LinearOrder α] (p : α) (n : Nat) :
    comparisonCost (List.replicate n p) = n.choose 2 := by
  simpa using comparisonCost_of_nonincreasing (List.replicate n p)
    (List.pairwise_replicate.mpr (Or.inr le_rfl))

def worstComparisonCost (n : Nat) : Nat := n.choose 2

theorem comparisonCost_le_worst {α : Type*} [LinearOrder α] (xs : List α) :
    comparisonCost xs ≤ worstComparisonCost xs.length := by
  simpa only [worstComparisonCost, Nat.choose_two_right] using comparisonCost_le_triangular xs

/-- Upper bound plus an attaining input identifies the actual maximum. -/
theorem worstComparisonCost_is_max (n : Nat) :
    (∀ xs : List Nat, xs.length = n → comparisonCost xs ≤ worstComparisonCost n) ∧
    (∃ xs : List Nat, xs.length = n ∧ comparisonCost xs = worstComparisonCost n) := by
  constructor
  · intro xs h
    simpa only [h] using comparisonCost_le_worst xs
  · exact ⟨List.replicate n 0, by simp, comparisonCost_replicate 0 n⟩

theorem worstComparisonCost_isTheta_quadratic :
    (fun n : Nat => (worstComparisonCost n : ℝ)) =Θ[Filter.atTop]
      (fun n : Nat => (n : ℝ) ^ 2) := by
  simpa only [worstComparisonCost] using isTheta_choose 2

end LeanSort.Quick
