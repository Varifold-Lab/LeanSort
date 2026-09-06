import LeanSort.Verification.Selection.Equations

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

end LeanSort.Selection
