import LeanSort.Verification.Insertion.Correctness
import LeanSort.Verification.Insertion.Trace
import LeanSort.Verification.Shared.InversionBounds

/-! Exact adjacent-transposition cost of insertion sort. -/

namespace LeanSort.Insertion

open List

/-- Inserting `x` into a sorted block costs one swap per element below `x`. Sortedness is
what makes "elements passed over" and "elements below `x`" the same set. -/
theorem length_insertTr_snd {α : Type*} [LinearOrder α] {off : ℕ} {x : α}
    {s : List α} (hs : s.Pairwise (· ≤ ·)) :
    (insertTr off x s).2.length = s.countP (fun y => decide (y < x)) := by
  induction s generalizing off with
  | nil => rfl
  | cons y ys ih =>
      by_cases h : x ≤ y
      · rw [insertTr_cons_of_le h]
        symm
        simp only [List.length_nil, List.countP_eq_zero, decide_eq_true_eq]
        intro a ha
        rcases List.mem_cons.mp ha with rfl | ha
        · exact not_lt_of_ge h
        · have : y ≤ a := rel_of_pairwise_cons hs ha
          exact not_lt_of_ge (h.trans this)
      · have hy : y < x := lt_of_not_ge h
        rw [insertTr_cons_of_gt h, List.countP_cons, List.length_cons, ih hs.of_cons]
        simp [hy]

/-- The trace has length `inversions l`. The step that carries it: `length_insertTr_snd`
counts against the sorted tail, `inversions` against the original one, and `countP` is
permutation-invariant. -/
theorem length_sortTr_snd {α : Type*} [LinearOrder α] (off : ℕ) (l : List α) :
    (sortTr off l).2.length = inversions l := by
  induction l generalizing off with
  | nil => rfl
  | cons x l ih =>
      have hs : (l.insertionSort (· ≤ ·)).Pairwise (· ≤ ·) :=
        pairwise_insertionSort _ l
      rw [sortTr_cons, List.length_append, ih, sortTr_fst, length_insertTr_snd hs,
        inversions_cons,
        (perm_insertionSort (α := α) (· ≤ ·) l).countP_eq (fun y => decide (y < x))]
      omega

/-- Insertion sort emits exactly one adjacent transposition per inversion. This is the
numerical part of a reduced-word characterization. -/
theorem length_insertionSortTrace {α : Type*} [LinearOrder α] (l : List α) :
    (insertionSortTrace l).length = inversions l :=
  length_sortTr_snd 0 l

/-- The swap cost of insertion sort is the number of adjacent transpositions in its trace. -/
def insertionSwapCost {α : Type*} [LinearOrder α] (xs : List α) : ℕ :=
  (insertionSortTrace xs).length

/-- Pointwise, insertion sort's swap cost is exactly the inversion count. -/
@[simp] theorem insertionSwapCost_eq_inversions {α : Type*} [LinearOrder α]
    (xs : List α) :
    insertionSwapCost xs = inversions xs :=
  length_insertionSortTrace xs

/-- Every adjacent-swap trace that sorts this input is at least as long as ours.
This compares swaps, not comparisons or total runtime. -/
theorem insertionSortTrace_minimal {α : Type*} [LinearOrder α]
    (xs : List α) (trace : List Gen) (hs : (replay trace xs).Pairwise (· ≤ ·)) :
    (insertionSortTrace xs).length ≤ trace.length := by
  have h := inversions_le_replay_add_length trace xs
  change inversions xs ≤ inversions (replay trace xs) + trace.length at h
  simpa [inversions_eq_zero_of_pairwise hs, length_insertionSortTrace] using h

/-- A sorted replay with minimal adjacent-swap length. -/
theorem insertionSortTrace_optimal {α : Type*} [LinearOrder α] (xs : List α) :
    IsSortingResult (· ≤ ·) xs (replay (insertionSortTrace xs) xs) ∧
      ∀ trace : List Gen, (replay trace xs).Pairwise (· ≤ ·) →
        (insertionSortTrace xs).length ≤ trace.length := by
  refine ⟨?_, insertionSortTrace_minimal xs⟩
  rw [replay_insertionSortTrace]
  exact insertionSortResult_spec xs

end LeanSort.Insertion
