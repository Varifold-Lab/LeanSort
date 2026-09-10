import LeanSort.Model.SortingResult
import LeanSort.Verification.Quick.Equations

/-! Quicksort preserves the input multiset and produces a nondecreasing list. -/

namespace LeanSort.Quick

theorem quickSortResult_perm {α : Type*} [LinearOrder α] (xs : List α) :
    (quickSortResult xs).Perm xs := by
  induction xs using quickSortResult_induct with
  | case1 => simp
  | case2 pivot xs ihl ihr =>
      let parts := xs.partition (fun x => decide (x ≤ pivot))
      rw [quickSortResult_cons]
      apply (ihl.append (ihr.cons pivot)).trans
      apply List.perm_middle.trans
      apply List.Perm.cons
      simpa [parts, Function.comp_def] using List.filter_append_perm (fun x => decide (x ≤ pivot)) xs

theorem sorted_quickSortResult {α : Type*} [LinearOrder α] (xs : List α) :
    (quickSortResult xs).Pairwise (· ≤ ·) := by
  induction xs using quickSortResult_induct with
  | case1 => simp
  | case2 pivot xs ihl ihr =>
      let parts := xs.partition (fun x => decide (x ≤ pivot))
      have hl : ∀ x ∈ quickSortResult parts.1, x ≤ pivot := by
        intro x hx
        have hm := (quickSortResult_perm parts.1).mem_iff.mp hx
        have : x ∈ xs ∧ x ≤ pivot := by simpa [parts] using hm
        exact this.2
      have hr : ∀ x ∈ quickSortResult parts.2, pivot ≤ x := by
        intro x hx
        have hm := (quickSortResult_perm parts.2).mem_iff.mp hx
        have : x ∈ xs ∧ ¬ x ≤ pivot := by simpa [parts] using hm
        exact le_of_lt (lt_of_not_ge this.2)
      rw [quickSortResult_cons]
      apply List.pairwise_append.mpr
      refine ⟨ihl, List.pairwise_cons.mpr ⟨hr, ihr⟩, ?_⟩
      intro a ha b hb
      rcases List.mem_cons.mp hb with rfl | hb
      · exact hl a ha
      · exact le_trans (hl a ha) (hr b hb)

theorem quickSortResult_spec {α : Type*} [LinearOrder α] (xs : List α) :
    IsSortingResult (· ≤ ·) xs (quickSortResult xs) :=
  ⟨sorted_quickSortResult xs, quickSortResult_perm xs⟩

end LeanSort.Quick
