import LeanSort.Verification.Bucket.Equations
import LeanSort.Model.SortingResult
import Mathlib.Data.List.Perm.Basic

/-! Multiplicity conservation and global sortedness across disjoint intervals. -/

namespace LeanSort.Bucket

theorem bucketSortResult_eq (xs : List Nat) :
    bucketSortResult xs = (List.range (bucketCount xs)).flatMap
      (fun i => (xs.filter (fun x => x / bucketWidth xs == i)).insertionSort (· ≤ ·)) := by
  simp [bucketSortResult, bucketOutput, distribute_toList, List.flatMap_map]

theorem count_filter_bucket (xs : List Nat) (width i key : Nat) :
    (xs.filter (fun x => x / width == i)).count key =
      if key / width = i then xs.count key else 0 := by
  by_cases h : key / width = i
  · simp [h]
  · rw [ite_eq_right h]
    apply List.count_eq_zero.mpr
    simp [h]

theorem count_bucket_range (xs : List Nat) (width n key : Nat) :
    ((List.range n).flatMap (fun i => xs.filter (fun x => x / width == i))).count key =
      if key / width < n then xs.count key else 0 := by
  induction n with
  | zero => simp
  | succ n ih =>
      simp only [List.range_succ, List.flatMap_append, List.flatMap_cons,
        List.flatMap_nil, List.append_nil, List.count_append, ih, count_filter_bucket]
      split_ifs <;> simp_all <;> omega

theorem distribute_flatten_perm (xs : List Nat) :
    (distribute xs).toList.flatten.Perm xs := by
  apply List.perm_iff_count.mpr
  intro key
  rw [distribute_toList, ← List.flatMap_def, count_bucket_range]
  by_cases h : key ∈ xs
  · simp [bucketIndex_lt xs key h]
  · simp [List.count_eq_zero.mpr h]

theorem bucketSortResult_perm (xs : List Nat) : (bucketSortResult xs).Perm xs := by
  apply (List.Perm.flatMap_left (distribute xs).toList
    (fun bucket _ => List.perm_insertionSort (· ≤ ·) bucket)).trans
  simpa only [List.flatMap_id'] using distribute_flatten_perm xs

theorem sorted_bucketSortResult (xs : List Nat) :
    (bucketSortResult xs).Pairwise (· ≤ ·) := by
  rw [bucketSortResult_eq]
  apply List.pairwise_flatMap.mpr
  refine ⟨?_, List.pairwise_lt_range.imp ?_⟩
  · intro i hi
    exact List.pairwise_insertionSort _ _
  · intro i j hij x hx y hy
    have hxi : x / bucketWidth xs = i := by simpa using (List.mem_filter.mp
      ((List.perm_insertionSort (· ≤ ·) _).mem_iff.mp hx)).2
    have hyj : y / bucketWidth xs = j := by simpa using (List.mem_filter.mp
      ((List.perm_insertionSort (· ≤ ·) _).mem_iff.mp hy)).2
    by_contra h
    have : y / bucketWidth xs ≤ x / bucketWidth xs :=
      Nat.div_le_div_right (Nat.le_of_lt (lt_of_not_ge h))
    omega

theorem bucketSortResult_spec (xs : List Nat) :
    IsSortingResult (· ≤ ·) xs (bucketSortResult xs) :=
  ⟨sorted_bucketSortResult xs, bucketSortResult_perm xs⟩

@[simp] theorem bucketSortResult_length (xs : List Nat) :
    (bucketSortResult xs).length = xs.length := (bucketSortResult_perm xs).length_eq

@[simp] theorem count_bucketSortResult (xs : List Nat) (x : Nat) :
    (bucketSortResult xs).count x = xs.count x := (bucketSortResult_perm xs).count_eq x

@[simp] theorem mem_bucketSortResult (xs : List Nat) (x : Nat) :
    x ∈ bucketSortResult xs ↔ x ∈ xs := (bucketSortResult_perm xs).mem_iff

end LeanSort.Bucket
