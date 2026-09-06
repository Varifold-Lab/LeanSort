import LeanSort.Verification.Selection.Equations

/-! # Correctness of the selection-sort trace -/

namespace LeanSort.Selection

open List

/-!
The offset carried by `sortAuxTr` is a position in the ambient list. The stronger
lemma below therefore keeps an arbitrary prefix whose length is that offset.
-/

/-- Swapping the head of a suffix with one of its entries performs exactly
`swapHeadAt`, even when the requested suffix index is out of range. -/
private theorem swap_prefix_head {α : Type*} (p : List α) (i : ℕ) (x : α)
    (xs : List α) :
    (p ++ x :: xs).swap p.length (p.length + i) =
      p ++ (swapHeadAt i x xs).1 :: (swapHeadAt i x xs).2 := by
  induction p with
  | nil =>
      cases i with
      | zero => simp
      | succ i =>
          cases h : xs[i]? with
          | none =>
              have hi : xs.length ≤ i :=
                Nat.le_of_not_gt ((getElem?_eq_none_iff xs i).mp h)
              simp [swapHeadAt, h, List.set_eq_of_length_le hi]
          | some y => simp [swapHeadAt, h]
  | cons y p ih =>
      simp only [List.length_cons, List.cons_append]
      rw [Nat.add_right_comm p.length 1 i, List.swap_cons]
      exact congrArg (List.cons y) ih

/-- Replaying the word emitted by `sortAuxTr` performs exactly the rearrangement
recorded in its first component, inside an ambient list with prefix `p`. -/
private theorem replay_sortAuxTr {α : Type*} [LinearOrder α] (fuel off : ℕ)
    (p xs : List α) (hp : p.length = off) :
    replay (sortAuxTr fuel off xs).2 (p ++ xs) = p ++ (sortAuxTr fuel off xs).1 := by
  induction fuel generalizing off p xs with
  | zero => simp [replay, Rearrangement.replay]
  | succ fuel ih =>
      cases xs with
      | nil => simp [replay, Rearrangement.replay]
      | cons x xs =>
          rw [sortAuxTr_succ_cons]
          simp only
          let i := minIdx (x :: xs)
          cases hswap : swapHeadAt i x xs with
          | mk newHead newTail =>
              cases hrec : sortAuxTr fuel (off + 1) newTail with
              | mk result trace =>
                  by_cases hi : i = 0
                  · have hi' : minIdx (x :: xs) = 0 := by simpa [i] using hi
                    have hpair : (newHead, newTail) = (x, xs) := by
                      simpa [hi] using hswap.symm
                    obtain ⟨rfl, rfl⟩ := Prod.mk.inj hpair
                    simp only [hi', ite_true]
                    simpa [hrec, List.append_assoc] using
                      ih (off := off + 1) (p := p ++ [newHead]) (xs := newTail)
                        (by simp [hp])
                  · have hi' : ¬minIdx (x :: xs) = 0 := by simpa [i] using hi
                    simp only [hi', ite_false, replay, Rearrangement.replay,
                      List.foldl_cons]
                    rw [show apply (off, off + minIdx (x :: xs)) (p ++ x :: xs) =
                        p ++ newHead :: newTail by
                      simpa [apply, Rearrangement.Transposition.apply, hp, i, hswap] using
                        swap_prefix_head p i x xs]
                    simpa [replay, Rearrangement.replay, hrec, List.append_assoc] using
                      ih (off := off + 1) (p := p ++ [newHead]) (xs := newTail)
                        (by simp [hp])

/-- Replaying the word emitted by selection sort yields its computed result. -/
theorem replay_selectionSortTrace {α : Type*} [LinearOrder α] (xs : List α) :
    replay (selectionSortTrace xs) xs = selectionSortResult xs := by
  simpa [selectionSortTrace, selectionSortResult, sortTrace] using
    replay_sortAuxTr xs.length 0 [] xs rfl

end LeanSort.Selection
