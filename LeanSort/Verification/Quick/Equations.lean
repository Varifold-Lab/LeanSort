import LeanSort.Algorithm.Quick

namespace LeanSort.Quick

/-- The single scan agrees with the library partition and records its predicates. -/
theorem partitionTr_eq {α : Type*} [LinearOrder α] (p : α) (xs : List α) :
    partitionTr p xs = (xs.partition (fun x => decide (x ≤ p)),
      xs.map (fun x => decide (x ≤ p))) := by
  induction xs with
  | nil => simp [partitionTr]
  | cons x xs ih =>
      simp only [partitionTr, ih, List.partition_eq_filter_filter]
      by_cases h : x ≤ p <;> simp [h, Function.comp_def]

@[simp] theorem quickSortTr_nil {α : Type*} [LinearOrder α] :
    quickSortTr ([] : List α) = ([], .empty) := by rw [quickSortTr]

theorem quickSortTr_cons {α : Type*} [LinearOrder α] (p : α) (xs : List α) :
    quickSortTr (p :: xs) =
      let parts := xs.partition (fun x => decide (x ≤ p))
      ((quickSortTr parts.1).1 ++ p :: (quickSortTr parts.2).1,
        .node (xs.map (fun x => decide (x ≤ p)))
          (quickSortTr parts.1).2 (quickSortTr parts.2).2) := by
  rw [quickSortTr, partitionTr_eq]

/-- Induction on the mathematical partition tree, independent of implementation. -/
@[elab_as_elim] theorem quickSortResult_induct {α : Type*} [LinearOrder α]
    {P : List α → Prop} (case1 : P [])
    (case2 : ∀ p xs, P (xs.partition (fun x => decide (x ≤ p))).1 →
      P (xs.partition (fun x => decide (x ≤ p))).2 → P (p :: xs))
    (xs : List α) : P xs := by
  induction xs using (measure List.length).wf.induction with
  | h xs ih =>
      cases xs with
      | nil => exact case1
      | cons p xs =>
          apply case2 p xs
          all_goals
            apply ih
            simp only [List.partition_eq_filter_filter]
            exact Nat.lt_succ_of_le (List.length_filter_le ..)

@[simp] theorem quickSortResult_nil {α : Type*} [LinearOrder α] :
    quickSortResult ([] : List α) = [] := by simp [quickSortResult]

theorem quickSortResult_cons {α : Type*} [LinearOrder α] (pivot : α) (xs : List α) :
    quickSortResult (pivot :: xs) =
      quickSortResult (xs.partition (fun x => decide (x ≤ pivot))).1 ++
        pivot :: quickSortResult (xs.partition (fun x => decide (x ≤ pivot))).2 := by
  simp only [quickSortResult, quickSortTr_cons]

end LeanSort.Quick
