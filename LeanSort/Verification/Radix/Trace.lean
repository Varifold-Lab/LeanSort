import LeanSort.Verification.Radix.Correctness

/-! Replay validates bit order and every bucket decision, including trace lengths. -/

namespace LeanSort.Radix

/-- Stable partition driven only by a recorded sequence of bucket choices. -/
def partitionByChoices : List Bool → List ℕ → List ℕ × List ℕ
  | choice :: choices, x :: xs =>
      let parts := partitionByChoices choices xs
      if choice then (x :: parts.1, parts.2) else (parts.1, x :: parts.2)
  | _, _ => ([], [])

def replayDigit (bit : ℕ) (xs : List ℕ) (step : DigitStep) : Option (List ℕ) :=
  if step.bit = bit ∧ step.choices = xs.map (fun x => decide (x / 2 ^ bit % 2 = 0)) then
    let parts := partitionByChoices step.choices xs
    some (parts.1 ++ parts.2)
  else none

def replayPasses : List ℕ → List ℕ → List DigitStep → Option (List ℕ)
  | [], xs, [] => some xs
  | bit :: bits, xs, step :: rest =>
      (replayDigit bit xs step).bind (fun next => replayPasses bits next rest)
  | _, _, _ => none

def replay (xs : List ℕ) (trace : List DigitStep) : Option (List ℕ) :=
  replayPasses (List.range (radixBits xs)) xs trace

theorem partitionByChoices_map (bit : ℕ) (xs : List ℕ) :
    partitionByChoices (xs.map (fun x => decide (x / 2 ^ bit % 2 = 0))) xs =
      xs.partition (fun x => decide (x / 2 ^ bit % 2 = 0)) := by
  induction xs with
  | nil => rfl
  | cons x xs ih =>
      by_cases h : x / 2 ^ bit % 2 = 0 <;>
        simp [partitionByChoices, h, ih, List.partition_eq_filter_filter]

theorem replayDigit_eq (bit : ℕ) (xs : List ℕ) (step : DigitStep) :
    replayDigit bit xs step =
      if step.bit = bit ∧ step.choices = xs.map (fun x => decide (x / 2 ^ bit % 2 = 0))
      then some (digitPass bit xs) else none := by
  unfold replayDigit
  split
  · rename_i h
    simp [h, partitionByChoices_map, digitPass]
  · rfl

theorem replayDigit_partitionTrace (bit : ℕ) (xs : List ℕ) :
    replayDigit bit xs ⟨bit, (partitionTrace bit xs).2⟩ = some (digitPass bit xs) := by
  simp [replayDigit_eq, partitionTrace_choices]

theorem replayDigit_sound (bit : ℕ) (xs : List ℕ) (step : DigitStep) (ys : List ℕ)
    (h : replayDigit bit xs step = some ys) : ys = digitPass bit xs := by
  rw [replayDigit_eq] at h
  split at h
  · exact (Option.some.inj h).symm
  · contradiction

theorem replayPasses_generated (bits : List ℕ) (xs : List ℕ) :
    replayPasses bits xs (passesTrace bits xs).2 = some (passesTrace bits xs).1 := by
  induction bits generalizing xs with
  | nil => rfl
  | cons bit bits ih =>
      simp only [passesTrace, replayPasses, replayDigit_partitionTrace, Option.bind_some]
      simpa only [partitionTrace_parts, digitPass] using ih (digitPass bit xs)

theorem replayPasses_sound (bits : List ℕ) (xs : List ℕ) (trace : List DigitStep)
    (ys : List ℕ) (h : replayPasses bits xs trace = some ys) :
    ys = bits.foldl (fun result bit => digitPass bit result) xs := by
  induction bits generalizing xs trace with
  | nil =>
      cases trace with
      | nil => exact (Option.some.inj h).symm
      | cons step rest => simp [replayPasses] at h
  | cons bit bits ih =>
      cases trace with
      | nil => simp [replayPasses] at h
      | cons step rest =>
          simp only [replayPasses] at h
          cases hd : replayDigit bit xs step with
          | none => simp [hd] at h
          | some next =>
              simp only [hd, Option.bind_some] at h
              simpa only [List.foldl_cons, replayDigit_sound bit xs step next hd] using
                ih next rest h

theorem replay_radixSortTrace (xs : List ℕ) :
    replay xs (radixSortTrace xs) = some (radixSortResult xs) := by
  simpa only [replay, radixSortTrace, sortTrace, passesTrace_result, radixSortResult] using
    replayPasses_generated (List.range (radixBits xs)) xs

/-- Every accepted trace reconstructs a sorted permutation of the original input. -/
theorem replay_sound (xs ys : List ℕ) (trace : List DigitStep)
    (h : replay xs trace = some ys) : LeanSort.IsSortingResult (· ≤ ·) xs ys := by
  have hy : ys = radixSortResult xs := replayPasses_sound _ _ _ _ h
  rw [hy]
  exact radixSortResult_spec xs

end LeanSort.Radix
