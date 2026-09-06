import LeanSort.Algorithm.Shell

/-! Every gapped insertion and every shell-sort pass preserves the input multiset. -/

namespace LeanSort.Shell

theorem gapInsert_perm {α : Type*} [LinearOrder α] (gap : ℕ) (xs : Array α) (i : ℕ) :
    (gapInsert gap xs i).Perm xs := by
  fun_induction gapInsert with
  | case1 xs i h _ ih => exact ih.trans (Array.swap_perm h.2.2 (by omega))
  | case2 => exact .refl _
  | case3 => exact .refl _

private theorem insertions_perm {α : Type*} [LinearOrder α]
    (gap : ℕ) (indices : List ℕ) (xs : Array α) :
    (indices.foldl (gapInsert gap) xs).Perm xs := by
  induction indices generalizing xs with
  | nil => exact .refl _
  | cons i rest ih => exact (ih (gapInsert gap xs i)).trans (gapInsert_perm gap xs i)

theorem gapPass_perm {α : Type*} [LinearOrder α] (gap : ℕ) (xs : Array α) :
    (gapPass gap xs).Perm xs :=
  insertions_perm gap (List.range xs.size) xs

private theorem passes_perm {α : Type*} [LinearOrder α]
    (steps : List ℕ) (xs : Array α) :
    (steps.foldl (fun a gap => gapPass gap a) xs).Perm xs := by
  induction steps generalizing xs with
  | nil => exact .refl _
  | cons gap rest ih => exact (ih (gapPass gap xs)).trans (gapPass_perm gap xs)

theorem shellSortResult_perm {α : Type*} [LinearOrder α] (xs : List α) :
    (shellSortResult xs).Perm xs := by
  simpa [shellSortResult] using
    Array.perm_iff_toList_perm.mp (passes_perm (gaps (xs.length / 2)) xs.toArray)

end LeanSort.Shell
