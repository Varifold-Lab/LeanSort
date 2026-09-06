import LeanSort.Verification.Bubble.Equations
import LeanSort.Verification.Shared.RearrangementLemmas

namespace LeanSort.Bubble

/-! Correctness of the word of adjacent transpositions emitted by bubble sort. -/

/-- Replaying concatenated words is the same as replaying them successively. -/
private theorem replay_append {α : Type*} (t u : List Gen) (l : List α) :
    replay (t ++ u) l = replay u (replay t l) := by
  simpa [replay] using
    (Rearrangement.replay_append Rearrangement.AdjacentTransposition.apply t u l)

/-- Replaying a pass continuation performs exactly the rearrangement in its result. -/
private theorem replay_passAuxTr {α : Type*} [LinearOrder α] (off : ℕ)
    (p : List α) (x : α) (xs : List α) (hp : p.length = off) :
    replay (passAuxTr off x xs).2 (p ++ x :: xs) = p ++ (passAuxTr off x xs).1 := by
  induction xs generalizing off p x with
  | nil => simp [replay, Rearrangement.replay]
  | cons y ys ih =>
      by_cases h : x ≤ y
      · rw [passAuxTr_cons_of_le h]
        simpa [List.append_assoc] using
          ih (off := off + 1) (p := p ++ [x]) (x := y) (by simp [hp])
      · rw [passAuxTr_cons_of_gt h]
        simp only [replay, Rearrangement.replay, List.foldl_cons]
        rw [show Rearrangement.AdjacentTransposition.apply off (p ++ x :: y :: ys) =
            p ++ y :: x :: ys by
          simpa [hp] using Rearrangement.AdjacentTransposition.apply_prefix p x y ys]
        simpa [replay, Rearrangement.replay, List.append_assoc] using
          ih (off := off + 1) (p := p ++ [y]) (x := x) (by simp [hp])

/-- Replaying one bubble pass performs exactly the rearrangement in its result. -/
private theorem replay_passTr {α : Type*} [LinearOrder α] (off : ℕ)
    (p xs : List α) (hp : p.length = off) :
    replay (passTr off xs).2 (p ++ xs) = p ++ (passTr off xs).1 := by
  cases xs with
  | nil => simp [replay, Rearrangement.replay]
  | cons x xs =>
      simpa using replay_passAuxTr off p x xs hp

/-- Replaying all passes performs exactly the rearrangement recorded by `sortAuxTr`. -/
private theorem replay_sortAuxTr {α : Type*} [LinearOrder α] (passes : ℕ)
    (xs : List α) :
    replay (sortAuxTr passes xs).2 xs = (sortAuxTr passes xs).1 := by
  induction passes generalizing xs with
  | zero => simp [replay, Rearrangement.replay]
  | succ passes ih =>
      rw [sortAuxTr_succ]
      rw [replay_append]
      have hpass : replay (passTr 0 xs).2 xs = (passTr 0 xs).1 := by
        simpa using replay_passTr 0 [] xs rfl
      rw [hpass]
      exact ih (xs := (passTr 0 xs).1)

/-- Replaying the word emitted by bubble sort yields its computed result. -/
theorem replay_bubbleSortTrace {α : Type*} [LinearOrder α] (xs : List α) :
    replay (bubbleSortTrace xs) xs = bubbleSortResult xs := by
  simpa [bubbleSortTrace, bubbleSortResult, sortTrace] using
    replay_sortAuxTr xs.length xs

end LeanSort.Bubble
