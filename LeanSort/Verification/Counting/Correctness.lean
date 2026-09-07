import LeanSort.Model.SortingResult
import LeanSort.Verification.Counting.Equations
import LeanSort.Verification.Shared.MaxKey

/-!
Complete correctness of histogram-based counting sort: every bucket equals the
input multiplicity, expansion preserves all elements, and the output is ordered.
-/

namespace LeanSort.Counting

theorem sorted_countingSortResult (xs : List ℕ) :
    (countingSortResult xs).Pairwise (· ≤ ·) := by
  unfold countingSortResult histogramOutput
  refine List.pairwise_flatMap.mpr ⟨by simp, List.pairwise_le_range.imp ?_⟩
  intro a b hab x hx y hy
  simpa only [(List.mem_replicate.mp hx).2, (List.mem_replicate.mp hy).2] using hab

theorem mem_lt_keyRange (xs : List ℕ) (x : ℕ) (hx : x ∈ xs) : x < keyRange xs :=
  Nat.lt_succ_of_le (mem_le_foldl_max xs 0 x hx)

theorem histogramFold_get (xs : List ℕ) (counts : Array ℕ) (key : ℕ)
    (hkey : key < counts.size) (hxs : ∀ x ∈ xs, x < counts.size) :
    (xs.foldl (fun counts x => counts.modify x (· + 1)) counts)[key]?.getD 0 =
      counts[key]?.getD 0 + xs.count key := by
  induction xs generalizing counts with
  | nil => simp
  | cons x xs ih =>
      simp only [List.foldl_cons]
      rw [ih (counts.modify x (· + 1)) (by simpa using hkey)
        (fun y hy => by simpa using hxs y (by simp [hy]))]
      by_cases heq : x = key <;>
        simp [Array.getElem?_modify, Array.getElem?_eq_getElem hkey, heq,
          Nat.add_assoc, Nat.add_comm]

theorem histogram_get (xs : List ℕ) (key : ℕ) :
    (histogram xs)[key]?.getD 0 = xs.count key := by
  by_cases hkey : key < keyRange xs
  · simpa [histogram, Array.getElem?_replicate, hkey] using histogramFold_get xs
      (Array.replicate (keyRange xs) 0) key (by simpa using hkey)
      (fun x hx => by simpa using mem_lt_keyRange xs x hx)
  · have hout : ¬ key < (histogram xs).size := by simpa using hkey
    have hnot : key ∉ xs := fun hx => hkey (mem_lt_keyRange xs key hx)
    simp [Array.getElem?_eq_none (Nat.le_of_not_gt hout), List.count_eq_zero.mpr hnot]

theorem count_expand_range (counts : ℕ → ℕ) (n key : ℕ) :
    ((List.range n).flatMap (fun x => List.replicate (counts x) x)).count key =
      if key < n then counts key else 0 := by
  induction n with
  | zero => simp
  | succ n ih =>
      simp only [List.range_succ, List.flatMap_append, List.flatMap_cons,
        List.flatMap_nil, List.append_nil, List.count_append, ih, List.count_replicate]
      split_ifs <;> simp_all <;> omega

theorem countingSortResult_count (xs : List ℕ) (key : ℕ) :
    (countingSortResult xs).count key = xs.count key := by
  rw [countingSortResult_eq, count_expand_range, histogram_get]
  exact ite_eq_left_iff.mpr fun hkey =>
    (List.count_eq_zero.mpr fun hx => hkey (mem_lt_keyRange xs key hx)).symm

theorem countingSortResult_perm (xs : List ℕ) : (countingSortResult xs).Perm xs :=
  List.perm_iff_count.mpr (countingSortResult_count xs)

@[simp] theorem countingSortResult_length (xs : List ℕ) :
    (countingSortResult xs).length = xs.length := (countingSortResult_perm xs).length_eq

theorem countingSortResult_spec (xs : List ℕ) :
    IsSortingResult (· ≤ ·) xs (countingSortResult xs) :=
  ⟨sorted_countingSortResult xs, countingSortResult_perm xs⟩

end LeanSort.Counting
