import LeanSort.Verification.Radix.Trace

/-! Counts digit tests, not the bit complexity of arithmetic or trace allocation. -/

namespace LeanSort.Radix

/-- One recorded decision per digit extraction and zero-bit test. -/
def traceCost (trace : List DigitStep) : ℕ :=
  (trace.map (fun step => step.choices.length)).sum

def digitTests (xs : List ℕ) : ℕ := traceCost (radixSortTrace xs)

@[simp] theorem partitionTrace_choice_count (bit : ℕ) (xs : List ℕ) :
    (partitionTrace bit xs).2.length = xs.length := by
  simp [partitionTrace_choices]

theorem passesTrace_round_count (bits : List ℕ) (xs : List ℕ) :
    (passesTrace bits xs).2.length = bits.length := by
  induction bits generalizing xs with
  | nil => rfl
  | cons bit bits ih => simp [passesTrace, ih]

theorem passesTrace_cost (bits : List ℕ) (xs : List ℕ) :
    traceCost (passesTrace bits xs).2 = bits.length * xs.length := by
  induction bits generalizing xs with
  | nil => simp [passesTrace, traceCost]
  | cons bit bits ih =>
      simp only [passesTrace, traceCost, List.map_cons, List.sum_cons]
      change (partitionTrace bit xs).2.length +
        traceCost (passesTrace bits _).2 = _
      rw [partitionTrace_choice_count, ih, partitionTrace_parts]
      change xs.length + bits.length * (digitPass bit xs).length = _
      simp [Nat.add_mul, Nat.add_comm]

theorem radixSortTrace_round_count (xs : List ℕ) :
    (radixSortTrace xs).length = radixBits xs := by
  simp [radixSortTrace, sortTrace, passesTrace_round_count]

/-- The generated execution performs exactly `n * b` digit tests. -/
theorem digitTests_eq (xs : List ℕ) : digitTests xs = xs.length * radixBits xs := by
  simp [digitTests, radixSortTrace, sortTrace, passesTrace_cost, Nat.mul_comm]

theorem digitTests_lower (xs : List ℕ) : xs.length ≤ digitTests xs := by
  rw [digitTests_eq]
  exact Nat.le_mul_of_pos_right _ (radixBits_pos xs)

end LeanSort.Radix
