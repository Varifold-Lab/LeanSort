import LeanSort.Verification.Insertion.Equations
import LeanSort.Verification.Shared.RearrangementLemmas

/-!
# Correctness of the insertion-sort trace

The offset carried by `sortTr` and `insertTr` is a position in the ambient list. The
stronger lemmas below therefore keep an arbitrary prefix whose length is that offset.
-/

namespace LeanSort.Insertion

/-- Replaying concatenated words is the same as replaying them successively. -/
theorem replay_append {α : Type*} (t u : List Gen) (l : List α) :
    replay (t ++ u) l = replay u (replay t l) := by
  simpa [replay] using
    (Rearrangement.replay_append Rearrangement.AdjacentTransposition.apply t u l)

/-- The trace emitted while inserting `x` performs exactly the insertion recorded in the
first component of `insertTr`, inside an ambient list with prefix `p`. -/
theorem replay_insertTr {α : Type*} [LinearOrder α] (off : ℕ) (p : List α)
    (x : α) (s : List α) (hp : p.length = off) :
    replay (insertTr off x s).2 (p ++ x :: s) = p ++ (insertTr off x s).1 := by
  induction s generalizing off p with
  | nil => simp [replay, Rearrangement.replay]
  | cons y ys ih =>
      by_cases h : x ≤ y
      · rw [insertTr_cons_of_le h]
        simp [replay, Rearrangement.replay]
      · rw [insertTr_cons_of_gt h]
        simp only [replay, Rearrangement.replay, List.foldl_cons]
        rw [show Rearrangement.AdjacentTransposition.apply off (p ++ x :: y :: ys) =
            p ++ y :: x :: ys by
          simpa [hp] using Rearrangement.AdjacentTransposition.apply_prefix p x y ys]
        simpa [replay, Rearrangement.replay, List.append_assoc] using
          ih (off := off + 1) (p := p ++ [y]) (by simp [hp])

/-- The trace emitted by `sortTr` performs exactly the rearrangement recorded in its first
component, inside an ambient list with prefix `p`. -/
theorem replay_sortTr {α : Type*} [LinearOrder α] (off : ℕ) (p l : List α)
    (hp : p.length = off) :
    replay (sortTr off l).2 (p ++ l) = p ++ (sortTr off l).1 := by
  induction l generalizing off p with
  | nil => simp [replay, Rearrangement.replay]
  | cons x l ih =>
      rw [sortTr_cons, replay_append]
      rw [show p ++ x :: l = (p ++ [x]) ++ l by simp]
      rw [ih (off := off + 1) (p := p ++ [x])]
      · simpa [List.append_assoc] using
          replay_insertTr off p x (sortTr (off + 1) l).1 hp
      · simp [hp]

/-- Replaying the word emitted by insertion sort yields its computed sorted result. -/
theorem replay_insertionSortTrace {α : Type*} [LinearOrder α] (l : List α) :
    replay (insertionSortTrace l) l = insertionSortResult l := by
  simpa [insertionSortTrace, insertionSortResult] using
    replay_sortTr (α := α) 0 [] l rfl

end LeanSort.Insertion
