import LeanSort.Verification.Pancake.Equations
import LeanSort.Verification.Shared.RearrangementLemmas

/-! Semantics of the prefix-reversal trace emitted by pancake sort. -/

namespace LeanSort.Pancake

/-- Replaying the trace of one round reconstructs that round's output. -/
theorem replay_round {α : Type*} [LinearOrder α] (k : ℕ) (xs : List α) :
    replay (round k xs).2 xs = (round k xs).1 := by
  by_cases hfinal : maxIdx (xs.take k) + 1 = k
  · simp [round, hfinal, replay]
  · by_cases hhead : maxIdx (xs.take k) = 0
    · have hfinal' : ¬ 1 = k := by simpa [hhead] using hfinal
      simp [round, hhead, hfinal', replay, Rearrangement.replay]
    · simp [round, hfinal, hhead, replay, Rearrangement.replay]

/-- Replaying all traces emitted by `sortAux` reconstructs its result. -/
theorem replay_sortAux {α : Type*} [LinearOrder α] (k : ℕ) (xs : List α) :
    replay (sortAux k xs).2 xs = (sortAux k xs).1 := by
  induction k generalizing xs with
  | zero => simp [sortAux, replay]
  | succ k ih =>
      simp only [sortAux]
      generalize hround : round (k + 1) xs = step
      rcases step with ⟨afterRound, word⟩
      generalize hsort : sortAux k afterRound = result
      rcases result with ⟨sorted, rest⟩
      simp only
      unfold replay
      rw [Rearrangement.replay_append]
      have hr := replay_round (k + 1) xs
      rw [hround] at hr
      simp only at hr
      unfold replay at hr
      rw [hr]
      have hs := ih afterRound
      rw [hsort] at hs
      unfold replay at hs
      exact hs

/-- The complete pancake-sort trace replays from the input to the reported output. -/
theorem replay_pancakeSortTrace {α : Type*} [LinearOrder α] (xs : List α) :
    replay (pancakeSortTrace xs) xs = pancakeSort xs := by
  exact replay_sortAux xs.length xs

end LeanSort.Pancake
