import LeanSort.Algorithm.ComparisonSort
import LeanSort.Model.ComparisonBounds
import LeanSort.Verification.Comparison.Semantics
import LeanSort.Verification.Insertion.Correctness
import LeanSort.Verification.HybridMerge.Correctness
import LeanSort.Verification.Merge.Correctness

namespace LeanSort.ComparisonSort
open Comparison

@[simp] theorem insert_ret {α : Type} [LinearOrder α] (x : α) (xs : List α) :
    (insert x xs).eval.ret = xs.orderedInsert (· ≤ ·) x := by
  induction xs with
  | nil => rfl
  | cons y ys ih =>
    by_cases h : x ≤ y <;>
      simp [insert, Program.eval, Program.eval_bind, List.orderedInsert, h, ih]

@[simp] theorem insertion_ret {α : Type} [LinearOrder α] (xs : List α) :
    (insertion xs).eval.ret = Insertion.insertionSortResult xs := by
  rw [Insertion.insertionSortResult_eq]
  induction xs with
  | nil => rfl
  | cons x xs ih => simp [insertion, Program.eval_bind, ih, List.insertionSort]

@[simp] theorem insertion_length {α : Type} [LinearOrder α] (xs : List α) :
    (insertion xs).eval.ret.length = xs.length := by
  rw [insertion_ret]
  exact (Insertion.insertionSortResult_perm xs).length_eq

theorem insert_cost_le {α : Type} [LinearOrder α] (x : α) (xs : List α) :
    (insert x xs).eval.time ≤ xs.length := by
  induction xs with
  | nil => simp [insert, Program.eval]
  | cons y ys ih =>
    by_cases h : x ≤ y
    · simp [insert, Program.eval, h]
    · simpa [insert, Program.eval, Program.eval_bind, h] using ih

theorem insertion_cost_le {α : Type} [LinearOrder α] (xs : List α) :
    (insertion xs).eval.time ≤ ComparisonBounds.insertion xs.length := by
  induction xs with
  | nil => simp [insertion, Program.eval, ComparisonBounds.insertion]
  | cons x xs ih =>
    have hi := insert_cost_le x (insertion xs).eval.ret
    rw [insertion_length] at hi
    simp only [insertion, Program.eval_bind]
    simp [ComparisonBounds.insertion, List.length_cons, Nat.choose_succ_succ] at *
    omega

/-- Equality of BOTH return value and comparison count with CSlib, not a conversion
from insertion's swap count. -/
theorem merge_eval {α : Type} [LinearOrder α] (xs ys : List α) :
    (merge xs ys).eval = Cslib.Algorithms.Lean.TimeM.merge xs ys := by
  cases xs with
  | nil =>
    apply Cslib.Algorithms.Lean.TimeM.ext <;>
      simp [merge, Program.eval, Cslib.Algorithms.Lean.TimeM.merge]
  | cons x xs =>
    cases ys with
    | nil =>
      apply Cslib.Algorithms.Lean.TimeM.ext <;>
        simp [merge, Program.eval, Cslib.Algorithms.Lean.TimeM.merge]
    | cons y ys =>
      have hl := merge_eval xs (y :: ys)
      have hr := merge_eval (x :: xs) ys
      by_cases h : x ≤ y <;>
        apply Cslib.Algorithms.Lean.TimeM.ext <;>
        simp [merge, Program.eval, Program.eval_bind, Cslib.Algorithms.Lean.TimeM.merge,
          h, hl, hr, Nat.add_comm]
termination_by xs.length + ys.length

theorem mergeSort_eval {α : Type} [LinearOrder α] (xs : List α) :
    (mergeSort xs).eval = Cslib.Algorithms.Lean.TimeM.mergeSort xs := by
  rw [mergeSort, Cslib.Algorithms.Lean.TimeM.mergeSort]
  split_ifs with h
  · rfl
  · have hl := mergeSort_eval (xs.take (xs.length / 2))
    have hr := mergeSort_eval (xs.drop (xs.length / 2))
    apply Cslib.Algorithms.Lean.TimeM.ext <;>
      simp [Program.eval_bind, hl, hr, merge_eval]
termination_by xs.length
decreasing_by all_goals simp_wf; omega

theorem merge_cost_le {α : Type} [LinearOrder α] (xs ys : List α) :
    (merge xs ys).eval.time ≤ xs.length + ys.length := by
  rw [merge_eval]
  exact Cslib.Algorithms.Lean.TimeM.merge_time xs ys

theorem mergeSort_cost_le {α : Type} [LinearOrder α] (xs : List α) :
    (mergeSort xs).eval.time ≤ ComparisonBounds.mergeSort xs.length := by
  rw [mergeSort_eval]
  exact Cslib.Algorithms.Lean.TimeM.mergeSort_time xs

@[simp] theorem hybrid_ret {α : Type} [LinearOrder α] (threshold : Nat) (xs : List α) :
    (hybrid threshold xs).eval.ret = HybridMerge.sort threshold xs := by
  rw [hybrid, HybridMerge.sort]
  split_ifs with h
  · exact insertion_ret xs
  · simp only [Program.eval_bind, merge_eval]
    rw [hybrid_ret threshold (xs.take (xs.length / 2)),
      hybrid_ret threshold (xs.drop (xs.length / 2))]
termination_by xs.length
decreasing_by all_goals simp_wf; omega

@[simp] theorem hybrid_length {α : Type} [LinearOrder α] (threshold : Nat) (xs : List α) :
    (hybrid threshold xs).eval.ret.length = xs.length := by
  rw [hybrid_ret]
  exact (HybridMerge.sort_spec threshold xs).2.length_eq

theorem hybrid_cost_le {α : Type} [LinearOrder α] (threshold : Nat) (xs : List α) :
    (hybrid threshold xs).eval.time ≤ ComparisonBounds.hybrid threshold xs.length := by
  rw [hybrid, ComparisonBounds.hybrid]
  split_ifs with h
  · exact insertion_cost_le xs
  · have hl := hybrid_cost_le threshold (xs.take (xs.length / 2))
    have hr := hybrid_cost_le threshold (xs.drop (xs.length / 2))
    have hm := merge_cost_le
      (hybrid threshold (xs.take (xs.length / 2))).eval.ret
      (hybrid threshold (xs.drop (xs.length / 2))).eval.ret
    simp only [hybrid_length, List.length_take, List.length_drop] at hm hl hr
    simp only [Program.eval_bind]
    have hhalf : min (xs.length / 2) xs.length = xs.length / 2 :=
      Nat.min_eq_left (Nat.div_le_self _ _)
    rw [hhalf] at hm hl
    omega
termination_by xs.length
decreasing_by all_goals simp_wf; omega

theorem checkSorted_spec {α : Type} [LinearOrder α] (xs : List α) :
    (checkSorted xs).eval.ret = true ↔ xs.Pairwise (· ≤ ·) := by
  induction xs with
  | nil => simp [checkSorted, Program.eval]
  | cons x xs ih =>
    cases xs with
    | nil => simp [checkSorted, Program.eval]
    | cons y ys =>
      by_cases h : x ≤ y
      · simp only [checkSorted, Program.eval, decide_eq_true h, ↓reduceIte]
        rw [ih]
        constructor
        · intro hs
          exact List.pairwise_cons.mpr ⟨by
            intro a ha
            rcases List.mem_cons.mp ha with rfl | ha
            · exact h
            · exact h.trans ((List.pairwise_cons.mp hs).1 a ha), hs⟩
        · exact List.Pairwise.of_cons
      · simp [checkSorted, Program.eval, h, List.pairwise_cons]

theorem checkSorted_cost_le {α : Type} [LinearOrder α] (xs : List α) :
    (checkSorted xs).eval.time ≤ xs.length - 1 := by
  induction xs with
  | nil => simp [checkSorted, Program.eval]
  | cons x xs ih =>
    cases xs with
    | nil => simp [checkSorted, Program.eval]
    | cons y ys =>
      by_cases h : x ≤ y
      · simpa [checkSorted, Program.eval, h] using ih
      · simp [checkSorted, Program.eval, h]

end LeanSort.ComparisonSort
