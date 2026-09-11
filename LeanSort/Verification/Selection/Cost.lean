import LeanSort.Verification.Selection.Equations
import LeanSort.Verification.Selection.Correctness

/-! # Selection-sort swap cost -/

namespace LeanSort.Selection

/-- With `fuel` selection rounds available, the algorithm emits at most `fuel` swaps. -/
theorem length_sortAuxTr_snd_le_fuel {α : Type*} [LinearOrder α]
    (fuel off : ℕ) (xs : List α) :
    (sortAuxTr fuel off xs).2.length ≤ fuel := by
  induction fuel generalizing off xs with
  | zero => simp
  | succ fuel ih =>
      cases xs with
      | nil => simp
      | cons x xs =>
          rw [sortAuxTr_succ_cons]
          dsimp only
          generalize hi : minIdx (x :: xs) = i
          generalize hswap : swapHeadAt i x xs = swapped
          rcases swapped with ⟨newHead, newTail⟩
          generalize hsort : sortAuxTr fuel (off + 1) newTail = sorted
          rcases sorted with ⟨result, trace⟩
          have htrace : trace.length ≤ fuel := by
            have := ih (off + 1) newTail
            rw [hsort] at this
            exact this
          by_cases hzero : i = 0
          · simp [hzero]
            exact Nat.le.step htrace
          · simp [hzero]
            exact htrace

/-- Selection sort emits at most one arbitrary-position swap per input entry. -/
theorem length_selectionSortTrace_le {α : Type*} [LinearOrder α] (xs : List α) :
    (selectionSortTrace xs).length ≤ xs.length := by
  simpa [selectionSortTrace, sortTrace] using
    length_sortAuxTr_snd_le_fuel xs.length 0 xs

/-- The swap cost of selection sort is the number of transpositions in its trace. -/
def selectionSwapCost {α : Type*} [LinearOrder α] (xs : List α) : ℕ :=
  (selectionSortTrace xs).length

/-- The swap cost is bounded pointwise by the input length. -/
theorem selectionSwapCost_le {α : Type*} [LinearOrder α] (xs : List α) :
    selectionSwapCost xs ≤ xs.length :=
  length_selectionSortTrace_le xs

/-- The last remaining entry never needs a swap, even with surplus fuel. -/
theorem length_sortAuxTr_snd_le_pred {α : Type*} [LinearOrder α]
    (fuel off : ℕ) (xs : List α) :
    (sortAuxTr fuel off xs).2.length ≤ xs.length - 1 := by
  induction fuel generalizing off xs with
  | zero => simp
  | succ fuel ih =>
      cases xs with
      | nil => simp
      | cons x xs =>
          cases xs with
          | nil =>
              cases fuel <;> simp [sortAuxTr_succ_cons, minIdx, argmin?]
          | cons y ys =>
              have ht := ih (off + 1) (round off x (y :: ys)).1.2
              have hlen : (round off x (y :: ys)).1.2.length = (y :: ys).length := by
                simpa [round] using (swapHeadAt_perm (minIdx (x :: y :: ys)) x (y :: ys)).length_eq
              have hr : (round off x (y :: ys)).2.length ≤ 1 := by
                simp only [round]
                split <;> simp
              change ((round off x (y :: ys)).2 ++
                (sortAuxTr fuel (off + 1) (round off x (y :: ys)).1.2).2).length ≤ _
              rw [List.length_append]
              simp only [List.length_cons] at hlen ⊢
              omega

theorem length_sortAuxTr_snd_le_min {α : Type*} [LinearOrder α]
    (fuel off : ℕ) (xs : List α) :
    (sortAuxTr fuel off xs).2.length ≤ min fuel (xs.length - 1) :=
  le_min (length_sortAuxTr_snd_le_fuel fuel off xs) (length_sortAuxTr_snd_le_pred fuel off xs)

theorem selectionSwapCost_le_pred {α : Type*} [LinearOrder α] (xs : List α) :
    selectionSwapCost xs ≤ xs.length - 1 :=
  length_sortAuxTr_snd_le_pred xs.length 0 xs

end LeanSort.Selection
