import LeanSort.Algorithm.Radix

namespace LeanSort.Radix

@[simp] theorem digitPass_nil (bit : ℕ) : digitPass bit [] = [] := rfl

theorem digitPass_eq_filters (bit : ℕ) (xs : List ℕ) :
    digitPass bit xs = xs.filter (fun x => decide (x / 2 ^ bit % 2 = 0)) ++
      xs.filter (fun x => !decide (x / 2 ^ bit % 2 = 0)) := by
  simp [digitPass, Function.comp_def]

theorem passes_succ (bits : ℕ) (xs : List ℕ) :
    (List.range (bits + 1)).foldl (fun result bit => digitPass bit result) xs =
      digitPass bits ((List.range bits).foldl (fun result bit => digitPass bit result) xs) := by
  simp [List.range_succ, List.foldl_append]

theorem radixBits_pos (xs : List ℕ) : 0 < radixBits xs := Nat.succ_pos _

@[simp] theorem radixSortResult_nil : radixSortResult [] = [] := rfl

theorem partitionTrace_parts (bit : ℕ) (xs : List ℕ) :
    (partitionTrace bit xs).1 = xs.partition (fun x => decide (x / 2 ^ bit % 2 = 0)) := by
  induction xs with
  | nil => rfl
  | cons x xs ih =>
      by_cases h : x / 2 ^ bit % 2 = 0 <;>
        simp [partitionTrace, h, ih, List.partition_eq_filter_filter]

theorem partitionTrace_choices (bit : ℕ) (xs : List ℕ) :
    (partitionTrace bit xs).2 = xs.map (fun x => decide (x / 2 ^ bit % 2 = 0)) := by
  induction xs with
  | nil => rfl
  | cons x xs ih =>
      by_cases h : x / 2 ^ bit % 2 = 0 <;> simp [partitionTrace, h, ih]

theorem passesTrace_result (bits : List ℕ) (xs : List ℕ) :
    (passesTrace bits xs).1 = bits.foldl (fun result bit => digitPass bit result) xs := by
  induction bits generalizing xs with
  | nil => rfl
  | cons bit bits ih => simp [passesTrace, ih, partitionTrace_parts, digitPass]

theorem sortTrace_result (xs : List ℕ) : (sortTrace xs).1 = radixSortResult xs :=
  passesTrace_result _ _

end LeanSort.Radix
