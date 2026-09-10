import LeanSort.Verification.Merge.Equations
import LeanSort.Verification.Merge.Cost
import LeanSort.Verification.Merge.Correctness

/-!
The optional trace agrees with CSlib in both result and comparison count.
Replay checks a single merge given its two input runs. The flat whole-sort trace
does not encode recursive boundaries and is not a rearrangement trace.
-/

namespace LeanSort.Merge

open Cslib.Algorithms.Lean

private theorem mergeTr_agrees {α : Type} [LinearOrder α] (left right : List α) :
    (mergeTr left right).1 = (TimeM.merge left right).ret ∧
      (mergeTr left right).2.length = (TimeM.merge left right).time := by
  fun_induction mergeTr <;>
    simp_all [TimeM.merge, TimeM.tick, Nat.add_comm, not_le_of_gt]

@[simp] theorem mergeTr_result {α : Type} [LinearOrder α] (left right : List α) :
    (mergeTr left right).1 = (TimeM.merge left right).ret :=
  (mergeTr_agrees left right).1

@[simp] theorem mergeTr_comparisons {α : Type} [LinearOrder α] (left right : List α) :
    (mergeTr left right).2.length = (TimeM.merge left right).time :=
  (mergeTr_agrees left right).2

private theorem sortTrace_agrees {α : Type} [LinearOrder α] (xs : List α) :
    (sortTrace xs).1 = (TimeM.mergeSort xs).ret ∧
      (sortTrace xs).2.length = (TimeM.mergeSort xs).time := by
  fun_induction sortTrace with
  | case1 => rw [TimeM.mergeSort]; simp_all
  | case2 xs h middle lr lt hl rr rt hr result trace hm ihl ihr =>
      have im := mergeTr_agrees lr rr
      rw [hm] at im
      rw [TimeM.mergeSort]
      simp_all [not_lt_of_ge, List.length_append, middle]

theorem sortTrace_result {α : Type} [LinearOrder α] (xs : List α) :
    (sortTrace xs).1 = mergeSortResult xs :=
  (sortTrace_agrees xs).1

theorem mergeSortTrace_length {α : Type} [LinearOrder α] (xs : List α) :
    (mergeSortTrace xs).length = mergeComparisonCost xs :=
  (sortTrace_agrees xs).2

/-- A derivation explains each comparison and head consumption. It applies to
unsorted runs too; sortedness is a separate contract precondition. Ties go left. -/
inductive MergeDerivation {α : Type} [LinearOrder α] :
    List α → List α → List Choice → List α → Prop where
  | nilLeft (ys) : MergeDerivation [] ys [] ys
  | nilRight (xs) : MergeDerivation xs [] [] xs
  | left {x y xs ys trace result} (h : x ≤ y)
      (rest : MergeDerivation xs (y :: ys) trace result) :
      MergeDerivation (x :: xs) (y :: ys) (.takeLeft :: trace) (x :: result)
  | right {x y xs ys trace result} (h : y < x)
      (rest : MergeDerivation (x :: xs) ys trace result) :
      MergeDerivation (x :: xs) (y :: ys) (.takeRight :: trace) (y :: result)

theorem MergeDerivation.eq_mergeTr {α : Type} [LinearOrder α]
    {left right : List α} {trace : List Choice} {result : List α}
    (h : MergeDerivation left right trace result) :
    mergeTr left right = (result, trace) := by
  induction h with
  | nilLeft => simp
  | nilRight => simp
  | left h rest ih => simp [mergeTr, h, ih]
  | right h rest ih => simp [mergeTr, not_le_of_gt h, ih]

theorem mergeTr_derivation {α : Type} [LinearOrder α] (left right : List α) :
    MergeDerivation left right (mergeTr left right).2 (mergeTr left right).1 := by
  fun_induction mergeTr with
  | case1 => exact .nilLeft _
  | case2 => exact .nilRight _
  | case3 => exact .left (by assumption) (by simp_all)
  | case4 => exact .right (lt_of_not_ge (by assumption)) (by simp_all)

/-- The semantics determines both the output and the complete trace. -/
theorem mergeDerivation_iff {α : Type} [LinearOrder α]
    (left right : List α) (trace : List Choice) (result : List α) :
    MergeDerivation left right trace result ↔ mergeTr left right = (result, trace) := by
  constructor
  · exact MergeDerivation.eq_mergeTr
  · intro h
    have hd := mergeTr_derivation left right
    simpa [h] using hd

theorem replayMerge?_mergeTr {α : Type} [LinearOrder α] (left right : List α) :
    replayMerge? (mergeTr left right).2 left right = some (mergeTr left right).1 := by
  fun_induction mergeTr <;> simp_all [replayMerge?]

/-- Every accepted trace has a legal derivation, including its untraced suffix. -/
theorem replayMerge?_sound {α : Type} [LinearOrder α]
    (trace : List Choice) (left right result : List α)
    (h : replayMerge? trace left right = some result) :
    MergeDerivation left right trace result := by
  fun_induction replayMerge? generalizing result <;>
    simp_all only [Option.map_eq_some_iff, Option.some.injEq, reduceCtorEq]
  all_goals first
    | subst result; exact .nilLeft _
    | subst result; exact .nilRight _
    | (obtain ⟨r, hr, rfl⟩ := h; exact .left (by assumption) (by aesop))
    | (obtain ⟨r, hr, rfl⟩ := h; exact .right (lt_of_not_ge (by assumption)) (by aesop))

theorem replayMerge?_iff_derivation {α : Type} [LinearOrder α]
    (trace : List Choice) (left right result : List α) :
    replayMerge? trace left right = some result ↔
      MergeDerivation left right trace result := by
  constructor
  · exact replayMerge?_sound trace left right result
  · intro h
    have hr := replayMerge?_mergeTr left right
    simpa [h.eq_mergeTr] using hr

/-- Sorted input runs give a sorted permutation and an exact comparison count. -/
theorem MergeDerivation.contract {α : Type} [LinearOrder α]
    {left right : List α} {trace : List Choice} {result : List α}
    (h : MergeDerivation left right trace result)
    (hl : left.Pairwise (· ≤ ·)) (hr : right.Pairwise (· ≤ ·)) :
    IsSortingResult (· ≤ ·) (left ++ right) result ∧
      trace.length = (TimeM.merge left right).time := by
  have he := mergeTr_result left right
  have hc := mergeTr_comparisons left right
  rw [h.eq_mergeTr] at he hc
  dsimp only at he hc
  refine ⟨⟨?_, ?_⟩, hc⟩
  · rw [he]; exact TimeM.sorted_merge hl hr
  · rw [he]; exact TimeM.merge_perm left right

/-- Whole-sort evidence binds the flat trace to the instrumented execution and
CSlib's comparison counter. It does not claim whole-sort trace replay. -/
structure SortCertificate {α : Type} [LinearOrder α] (input : List α) where
  output : List α
  trace : List Choice
  execution_eq : sortTrace input = (output, trace)
  sorted : output.Pairwise (· ≤ ·)
  perm : output.Perm input
  comparisons_eq : trace.length = mergeComparisonCost input

def mergeSortCertificate {α : Type} [LinearOrder α] (xs : List α) :
    SortCertificate xs where
  output := (sortTrace xs).1
  trace := mergeSortTrace xs
  execution_eq := by simp [mergeSortTrace]
  sorted := by rw [sortTrace_result]; exact sorted_mergeSortResult xs
  perm := by rw [sortTrace_result]; exact mergeSortResult_perm xs
  comparisons_eq := mergeSortTrace_length xs

theorem mergeSortCertificate_output {α : Type} [LinearOrder α] (xs : List α) :
    (mergeSortCertificate xs).output = mergeSortResult xs := sortTrace_result xs

end LeanSort.Merge
