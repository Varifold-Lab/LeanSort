import LeanSort.Verification.Selection.Semantics
import Mathlib.Data.Nat.Choose.Basic

/-! Executable comparison instrumentation, related to the original execution by
universal agreement proofs. Only key comparisons in minimum scans are charged;
index checks, swaps, list copying, and verification overhead are excluded. -/

namespace LeanSort.Selection

/-- The minimum scan charges one comparison exactly when a tail minimum exists. -/
def argminWithComparisons {α : Type*} [LinearOrder α] :
    List α → Option (ℕ × α) × ℕ
  | [] => (none, 0)
  | x :: xs =>
      let rest := argminWithComparisons xs
      match rest.1 with
      | none => (some (0, x), rest.2)
      | some (i, value) =>
          (if x ≤ value then some (0, x) else some (i + 1, value), rest.2 + 1)

theorem argminWithComparisons_result {α : Type*} [LinearOrder α] (xs : List α) :
    (argminWithComparisons xs).1 = argmin? xs := by
  induction xs with
  | nil => rfl
  | cons x xs ih =>
      simp only [argminWithComparisons, argmin?_cons, ih]
      cases argmin? xs <;> rfl

theorem argminWithComparisons_cost {α : Type*} [LinearOrder α] (xs : List α) :
    (argminWithComparisons xs).2 = xs.length - 1 := by
  induction xs with
  | nil => rfl
  | cons x xs ih =>
      by_cases hn : xs = []
      · subst xs; rfl
      · have hpos : 0 < xs.length := List.length_pos_iff.mpr hn
        cases ha : argmin? xs with
        | none => exact False.elim (hn ((argmin?_eq_none xs).mp ha))
        | some pair =>
            simp only [argminWithComparisons, argminWithComparisons_result, ha, ih, List.length_cons]
            omega

/-- A comparison-counted run returns the complete output/trace pair, so its
agreement theorem preserves minimum choices and swaps, not just sorted output. -/
def sortAuxWithComparisons {α : Type*} [LinearOrder α] :
    ℕ → ℕ → List α → (List α × List Gen) × ℕ
  | 0, _, xs => ((xs, []), 0)
  | _ + 1, _, [] => (([], []), 0)
  | fuel + 1, off, x :: xs =>
      let scan := argminWithComparisons (x :: xs)
      let i := (scan.1.map Prod.fst).getD 0
      let moved := swapHeadAt i x xs
      let rest := sortAuxWithComparisons fuel (off + 1) moved.2
      ((moved.1 :: rest.1.1, (if i = 0 then [] else [(off, off + i)]) ++ rest.1.2),
        scan.2 + rest.2)

theorem sortAuxWithComparisons_execution {α : Type*} [LinearOrder α]
    (fuel off : ℕ) (xs : List α) :
    (sortAuxWithComparisons fuel off xs).1 = sortAuxTr fuel off xs := by
  induction fuel generalizing off xs with
  | zero => rfl
  | succ fuel ih =>
      cases xs with
      | nil => rfl
      | cons x xs =>
          simp only [sortAuxWithComparisons, argminWithComparisons_result, sortAuxTr, round, minIdx]
          rw [ih]
          rfl

/-- Cost of the first `fuel` minimum scans on a list of length `size`. -/
def comparisonBudget : ℕ → ℕ → ℕ
  | 0, _ => 0
  | _ + 1, 0 => 0
  | fuel + 1, size + 1 => size + comparisonBudget fuel size

theorem sortAuxWithComparisons_cost {α : Type*} [LinearOrder α]
    (fuel off : ℕ) (xs : List α) :
    (sortAuxWithComparisons fuel off xs).2 = comparisonBudget fuel xs.length := by
  induction fuel generalizing off xs with
  | zero => rfl
  | succ fuel ih =>
      cases xs with
      | nil => rfl
      | cons x xs =>
          simp only [sortAuxWithComparisons, argminWithComparisons_cost,
            argminWithComparisons_result, List.length_cons, Nat.add_sub_cancel, comparisonBudget]
          rw [ih]
          have hlen := (swapHeadAt_perm (minIdx (x :: xs)) x xs).length_eq
          have ht : (swapHeadAt (minIdx (x :: xs)) x xs).2.length = xs.length := by
            simpa using hlen
          change xs.length + comparisonBudget fuel (swapHeadAt (minIdx (x :: xs)) x xs).2.length = _
          rw [ht]

/-- Exact partial cost: comparisons spent plus those still required total n choose 2. -/
theorem comparisonBudget_exact (fuel size : ℕ) :
    comparisonBudget fuel size + (size - fuel).choose 2 = size.choose 2 := by
  induction fuel generalizing size with
  | zero => simp [comparisonBudget]
  | succ fuel ih =>
      cases size with
      | zero => simp [comparisonBudget]
      | succ size =>
          simp only [comparisonBudget, Nat.succ_sub_succ_eq_sub,
            Nat.choose_succ_succ, Nat.choose_one_right]
          have h := ih size
          change size + comparisonBudget fuel size + (size - fuel).choose 2 = size + size.choose 2
          omega

theorem comparisonBudget_eq (fuel size : ℕ) :
    comparisonBudget fuel size = size.choose 2 - (size - fuel).choose 2 := by
  have h := comparisonBudget_exact fuel size
  omega

def selectionComparisonCost {α : Type*} [LinearOrder α] (xs : List α) : ℕ :=
  (sortAuxWithComparisons xs.length 0 xs).2

/-- All inputs of the same length have the same comparison cost, even when no
swaps are needed. This is an exact count, not merely a worst-case bound. -/
theorem selectionComparisonCost_eq {α : Type*} [LinearOrder α] (xs : List α) :
    selectionComparisonCost xs = xs.length.choose 2 := by
  simp [selectionComparisonCost, sortAuxWithComparisons_cost, comparisonBudget_eq]

theorem selectionComparisonCost_triangular {α : Type*} [LinearOrder α] (xs : List α) :
    selectionComparisonCost xs = xs.length * (xs.length - 1) / 2 := by
  rw [selectionComparisonCost_eq, Nat.choose_two_right]

theorem sortAuxWithComparisons_derivation {α : Type*} [LinearOrder α]
    (fuel off : ℕ) (xs : List α) :
    SelectionDerivation fuel off xs (sortAuxWithComparisons fuel off xs).1.1
      (sortAuxWithComparisons fuel off xs).1.2 := by
  rw [sortAuxWithComparisons_execution]
  exact sortAuxTr_derivation fuel off xs

/-- The full certificate's output and trace also identify the counted execution. -/
theorem Certificate.comparisons {α : Type*} [LinearOrder α] {xs : List α}
    (c : Certificate xs) :
    sortAuxWithComparisons xs.length 0 xs = ((c.output, c.trace), xs.length.choose 2) := by
  apply Prod.ext
  · exact (sortAuxWithComparisons_execution _ _ _).trans c.execution
  · exact selectionComparisonCost_eq xs

theorem PartialCertificate.comparisons {α : Type*} [LinearOrder α]
    {fuel : ℕ} {p xs : List α} (c : PartialCertificate fuel p xs) :
    sortAuxWithComparisons fuel p.length xs =
      ((c.output, c.trace), xs.length.choose 2 - (xs.length - fuel).choose 2) := by
  apply Prod.ext
  · exact (sortAuxWithComparisons_execution _ _ _).trans c.execution
  · rw [sortAuxWithComparisons_cost, comparisonBudget_eq]

end LeanSort.Selection
