import LeanSort.Algorithm.Radix

/-! Each digit pass, and hence the whole radix sort, preserves the input multiset. -/

namespace LeanSort.Radix

theorem digitPass_perm (bit : ℕ) (xs : List ℕ) : (digitPass bit xs).Perm xs := by
  simpa [digitPass, Function.comp_def] using
    List.filter_append_perm (fun x => decide (x / 2 ^ bit % 2 = 0)) xs

private theorem passes_perm (bits : List ℕ) (xs : List ℕ) :
    (bits.foldl (fun result bit => digitPass bit result) xs).Perm xs := by
  induction bits generalizing xs with
  | nil => exact .refl _
  | cons bit rest ih => exact (ih (digitPass bit xs)).trans (digitPass_perm bit xs)

theorem radixSortResult_perm (xs : List ℕ) : (radixSortResult xs).Perm xs :=
  passes_perm _ xs

end LeanSort.Radix
