import LeanSort.Verification.Pancake.Equations

/-! Finite prefix-reversal cost of pancake sort. -/

namespace LeanSort.Pancake

/-- One round emits at most two prefix reversals. -/
theorem length_round_snd_le_two {α : Type*} [LinearOrder α]
    (k : ℕ) (xs : List α) :
    (round k xs).2.length ≤ 2 := by
  unfold round
  dsimp only
  split_ifs <;> simp

/-- `k` rounds emit at most `2 * k` prefix reversals. -/
theorem length_sortAux_snd_le_two_mul {α : Type*} [LinearOrder α]
    (k : ℕ) (xs : List α) :
    (sortAux k xs).2.length ≤ 2 * k := by
  induction k generalizing xs with
  | zero => simp [sortAux]
  | succ k ih =>
      simp only [sortAux]
      generalize hround : round (k + 1) xs = step
      rcases step with ⟨afterRound, word⟩
      generalize hsort : sortAux k afterRound = result
      rcases result with ⟨sorted, rest⟩
      simp only [List.length_append]
      have hr := length_round_snd_le_two (k + 1) xs
      rw [hround] at hr
      simp only at hr
      have hs := ih afterRound
      rw [hsort] at hs
      simp only at hs
      omega

/-- The flip cost is the number of prefix reversals in the emitted trace. -/
def pancakeFlipCost {α : Type*} [LinearOrder α] (xs : List α) : ℕ :=
  (pancakeSortTrace xs).length

/-- The finite flip cost is at most twice the input length. -/
theorem pancakeFlipCost_le_two_mul_length {α : Type*} [LinearOrder α]
    (xs : List α) :
    pancakeFlipCost xs ≤ 2 * xs.length := by
  exact length_sortAux_snd_le_two_mul xs.length xs

end LeanSort.Pancake
