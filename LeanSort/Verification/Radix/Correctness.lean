import LeanSort.Verification.Radix.Equations
import LeanSort.Model.SortingResult

namespace LeanSort.Radix

theorem digitPass_perm (bit : ℕ) (xs : List ℕ) : (digitPass bit xs).Perm xs := by
  simpa [digitPass_eq_partition, Function.comp_def] using
    List.filter_append_perm (fun x => decide (x / 2 ^ bit % 2 = 0)) xs

theorem passes_perm (bits : List ℕ) (xs : List ℕ) :
    (bits.foldl (fun result bit => digitPass bit result) xs).Perm xs := by
  induction bits generalizing xs with
  | nil => exact .refl _
  | cons bit rest ih => exact (ih (digitPass bit xs)).trans (digitPass_perm bit xs)

theorem radixSortResult_perm (xs : List ℕ) : (radixSortResult xs).Perm xs :=
  by rw [radixSortResult_eq_passes]; exact passes_perm _ xs

@[simp] theorem digitPass_length (bit : ℕ) (xs : List ℕ) :
    (digitPass bit xs).length = xs.length := (digitPass_perm bit xs).length_eq

@[simp] theorem radixSortResult_length (xs : List ℕ) :
    (radixSortResult xs).length = xs.length := (radixSortResult_perm xs).length_eq

/-- After `bits` passes, the processed low bits are in ascending order. -/
def SortedBits (bits : ℕ) (xs : List ℕ) : Prop :=
  xs.Pairwise (fun x y => x % 2 ^ bits ≤ y % 2 ^ bits)

theorem digitPass_sortedBits (bit : ℕ) (xs : List ℕ) (h : SortedBits bit xs) :
    SortedBits (bit + 1) (digitPass bit xs) := by
  unfold SortedBits
  rw [digitPass_eq_partition]
  simp only [List.partition_eq_filter_filter]
  apply List.pairwise_append.mpr
  refine ⟨List.pairwise_filter.mpr (h.imp ?_),
    List.pairwise_filter.mpr (h.imp ?_), ?_⟩
  · intro a b hab ha hb
    have ha : a / 2 ^ bit % 2 = 0 := by simpa using ha
    have hb : b / 2 ^ bit % 2 = 0 := by simpa using hb
    simpa [Nat.mod_pow_succ, ha, hb] using hab
  · intro a b hab ha hb
    have ha : a / 2 ^ bit % 2 ≠ 0 := by simpa using ha
    have hb : b / 2 ^ bit % 2 ≠ 0 := by simpa using hb
    have ha' : a / 2 ^ bit % 2 = 1 := by omega
    have hb' : b / 2 ^ bit % 2 = 1 := by omega
    simpa [Nat.mod_pow_succ, ha', hb'] using hab
  · intro a ha b hb
    have ha : a / 2 ^ bit % 2 = 0 := by simpa using (List.mem_filter.mp ha).2
    have hb : b / 2 ^ bit % 2 ≠ 0 := by simpa using (List.mem_filter.mp hb).2
    have hb' : b / 2 ^ bit % 2 = 1 := by omega
    have hm := Nat.mod_lt a (show 0 < 2 ^ bit from Nat.pow_pos (by decide))
    simp only [Nat.mod_pow_succ, ha, hb', Nat.mul_zero, Nat.add_zero, Nat.mul_one]
    omega

theorem passes_sortedBits (bits : ℕ) (xs : List ℕ) :
    SortedBits bits ((List.range bits).foldl (fun result bit => digitPass bit result) xs) := by
  induction bits with
  | zero => simp [SortedBits, Nat.mod_one, List.pairwise_iff_getElem]
  | succ bits ih =>
    simpa [List.range_succ, List.foldl_append] using
      digitPass_sortedBits bits _ ih

private theorem max_bound (xs : List ℕ) (initial : ℕ) :
    initial ≤ xs.foldl max initial ∧ ∀ x ∈ xs, x ≤ xs.foldl max initial := by
  induction xs generalizing initial with
  | nil => simp
  | cons y ys ih =>
    obtain ⟨hi, hm⟩ := ih (max initial y)
    constructor
    · exact (Nat.le_max_left initial y).trans hi
    · intro x hx
      rcases List.mem_cons.mp hx with rfl | hx
      · exact (Nat.le_max_right initial x).trans hi
      · exact hm x hx

theorem radixSortResult_sorted (xs : List ℕ) :
    (radixSortResult xs).Pairwise (· ≤ ·) := by
  have bound : ∀ x ∈ radixSortResult xs, x < 2 ^ radixBits xs := by
    intro x hx
    have hm := (max_bound xs 0).2 x ((radixSortResult_perm xs).mem_iff.mp hx)
    have hp := Nat.lt_pow_succ_log_self (by decide : 1 < 2) (xs.foldl max 0)
    rw [← Nat.log2_eq_log_two] at hp
    exact hm.trans_lt hp
  rw [radixSortResult_eq_passes] at bound ⊢
  exact (passes_sortedBits _ xs).imp_of_mem (fun ha hb hab => by
    simpa only [Nat.mod_eq_of_lt (bound _ ha), Nat.mod_eq_of_lt (bound _ hb)] using hab)

theorem radixSortResult_spec (xs : List ℕ) :
    LeanSort.IsSortingResult (· ≤ ·) xs (radixSortResult xs) :=
  ⟨radixSortResult_sorted xs, radixSortResult_perm xs⟩

end LeanSort.Radix
