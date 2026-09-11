import LeanSort.Verification.Radix.Trace

/-!
# Radix cost models

Two different counters are proved below:

* `digitTests`: exactly `n * b` digit tests, counted from the existing trace.
* `radixWorkCost`: maximum scan + partition visits + append copies,
  between `n * b` and `3 * (n * b)`.

Here `n = xs.length` and `b = radixBits xs`. For the mathematical overview and
formal Theta conclusion, start at `Verification/Radix/Complexity.lean`.
-/

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
      rw [← digitPass_eq_partition]
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

/-! ## Algorithm-level work: maximum scan + partition visits + append copies

Each maximum-scan visit costs one unit. In a pass, each input element's digit
test and bucket placement cost one unit; copying a node of the zero bucket
during `parts.1 ++ parts.2` costs one more unit. This is a declared unit-cost
model, not a count of Lean runtime instructions or of the instrumentation itself.
Bit arithmetic, pass-index construction, and allocation overhead are not charged.
-/

/-- The same pass sequence as `radixSortResult`, paired with its modeled work. -/
def passesWithWork : List ℕ → List ℕ → List ℕ × ℕ
  | [], xs => (xs, 0)
  | bit :: bits, xs =>
      let parts := xs.partition (fun x => decide (x / 2 ^ bit % 2 = 0))
      let rest := passesWithWork bits (parts.1 ++ parts.2)
      (rest.1, xs.length + parts.1.length + rest.2)

/-- Include the initial maximum scan, then execute all binary passes. -/
def sortWithWork (xs : List ℕ) : List ℕ × ℕ :=
  let result := passesWithWork (List.range (radixBits xs)) xs
  (result.1, xs.length + result.2)

/-- Algorithm-level work in the scan/partition/append model above. -/
def radixWorkCost (xs : List ℕ) : ℕ := (sortWithWork xs).2

theorem passesWithWork_result (bits : List ℕ) (xs : List ℕ) :
    (passesWithWork bits xs).1 =
      bits.foldl (fun result bit => digitPass bit result) xs := by
  induction bits generalizing xs with
  | nil => rfl
  | cons bit bits ih => simp [passesWithWork, ih, digitPass_eq_partition]

/-- The cost is attached to a run that returns the original algorithm's output. -/
theorem sortWithWork_result (xs : List ℕ) :
    (sortWithWork xs).1 = radixSortResult xs :=
  by rw [radixSortResult_eq_passes]; exact passesWithWork_result _ _

/-- Each round visits all `n` elements and copies at most `n` zero-bucket nodes.
Length preservation makes these per-round bounds accumulate over all rounds. -/
theorem passesWithWork_bounds (bits : List ℕ) (xs : List ℕ) :
    bits.length * xs.length ≤ (passesWithWork bits xs).2 ∧
      (passesWithWork bits xs).2 ≤ 2 * (bits.length * xs.length) := by
  induction bits generalizing xs with
  | nil => simp [passesWithWork]
  | cons bit bits ih =>
      have rest := ih (digitPass bit xs)
      rw [digitPass_length] at rest
      have buckets := digitPass_length bit xs
      simp only [digitPass_eq_partition, List.length_append] at buckets
      simp only [passesWithWork, List.length_cons]
      rw [← digitPass_eq_partition]
      change (bits.length + 1) * xs.length ≤
          xs.length + (xs.partition (fun x => decide (x / 2 ^ bit % 2 = 0))).1.length +
            (passesWithWork bits (digitPass bit xs)).2 ∧
        xs.length + (xs.partition (fun x => decide (x / 2 ^ bit % 2 = 0))).1.length +
            (passesWithWork bits (digitPass bit xs)).2 ≤
          2 * ((bits.length + 1) * xs.length)
      rw [Nat.add_mul, Nat.one_mul]
      omega

/-- **Main finite bound:** `n*b ≤ W(xs) ≤ 3*n*b`, on every input.
There are `b ≥ 1` rounds, so the initial `n`-visit maximum scan is at most `n*b`.
Together with `n*b ≤ pass work ≤ 2*n*b`, this proves the claimed bounds. -/
theorem radixWorkCost_bounds (xs : List ℕ) :
    xs.length * radixBits xs ≤ radixWorkCost xs ∧
      radixWorkCost xs ≤ 3 * (xs.length * radixBits xs) := by
  have passes := passesWithWork_bounds (List.range (radixBits xs)) xs
  simp only [List.length_range, Nat.mul_comm (radixBits xs)] at passes
  have scan := Nat.le_mul_of_pos_right xs.length (radixBits_pos xs)
  change xs.length * radixBits xs ≤
      xs.length + (passesWithWork (List.range (radixBits xs)) xs).2 ∧
    xs.length + (passesWithWork (List.range (radixBits xs)) xs).2 ≤
      3 * (xs.length * radixBits xs)
  omega

end LeanSort.Radix
