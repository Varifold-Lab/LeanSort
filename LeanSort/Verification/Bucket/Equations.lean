import LeanSort.Algorithm.Bucket
import LeanSort.Verification.Shared.MaxKey

/-! Safe allocation and exact contents of the distribution array. -/

namespace LeanSort.Bucket

theorem bucketCount_pos (xs : List Nat) : 0 < bucketCount xs := by
  simp [bucketCount]

theorem bucketWidth_pos (xs : List Nat) : 0 < bucketWidth xs := by
  simp [bucketWidth]

theorem bucketIndex_lt (xs : List Nat) (x : Nat) (hx : x ∈ xs) :
    x / bucketWidth xs < bucketCount xs := by
  apply (Nat.div_lt_iff_lt_mul (bucketWidth_pos xs)).mpr
  exact (mem_le_foldl_max xs 0 x hx).trans_lt
    (Nat.lt_mul_div_succ _ (bucketCount_pos xs))

@[simp] theorem scatter_size (width : Nat) (xs : List Nat) (buckets : Array (List Nat)) :
    (scatter width xs buckets).size = buckets.size := by
  induction xs generalizing buckets with
  | nil => rfl
  | cons x xs ih => simpa [scatter] using ih (buckets.modify (x / width) (x :: ·))

@[simp] theorem distribute_size (xs : List Nat) :
    (distribute xs).size = bucketCount xs := by simp [distribute]

/-- The raw fold prepends selected input occurrences in reverse input order. -/
theorem scatter_get (width : Nat) (xs : List Nat) (buckets : Array (List Nat))
    (i : Nat) (hi : i < buckets.size) :
    (scatter width xs buckets)[i]?.getD [] =
      (xs.filter (fun x => x / width == i)).reverse ++ buckets[i]?.getD [] := by
  induction xs generalizing buckets with
  | nil => simp [scatter]
  | cons x xs ih =>
      change (scatter width xs (buckets.modify (x / width) (x :: ·)))[i]?.getD [] = _
      rw [ih _ (by simpa using hi)]
      by_cases h : x / width = i <;>
        simp [h, Array.getElem?_modify, Array.getElem?_eq_getElem hi,
          List.reverse_cons, List.append_assoc]

/-- Final buckets are exact stable filters, including empty buckets. -/
theorem distribute_get (xs : List Nat) (i : Nat) (hi : i < bucketCount xs) :
    (distribute xs)[i]?.getD [] = xs.filter (fun x => x / bucketWidth xs == i) := by
  have h := scatter_get (bucketWidth xs) xs (Array.replicate (bucketCount xs) []) i
    (by simpa using hi)
  have hb : i < (scatter (bucketWidth xs) xs (Array.replicate (bucketCount xs) [])).size :=
    by simpa using hi
  simp only [distribute, Array.getElem?_map]
  rw [Array.getElem?_eq_getElem hb]
  simp only [Option.map_some, Option.getD_some]
  have he : (scatter (bucketWidth xs) xs (Array.replicate (bucketCount xs) []))[i] =
      (xs.filter (fun x => x / bucketWidth xs == i)).reverse := by
    simpa [Array.getElem?_eq_getElem hb, hi] using h
  rw [he, List.reverse_reverse]

theorem distribute_toList (xs : List Nat) :
    (distribute xs).toList = (List.range (bucketCount xs)).map
      (fun i => xs.filter (fun x => x / bucketWidth xs == i)) := by
  apply List.ext_getElem
  · simp
  · intro i hi hj
    have h := distribute_get xs i (by simpa using hi)
    have hib : i < (distribute xs).size := by simpa using hi
    simpa [Array.getElem?_eq_getElem hib] using h

@[simp] theorem bucketSortResult_nil : bucketSortResult [] = [] := by
  simp [bucketSortResult, bucketOutput, distribute, scatter, bucketCount]

end LeanSort.Bucket
