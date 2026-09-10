import LeanSort.Verification.Quick.Correctness

/-! Partition contracts, execution agreement, and checked tree semantics. -/

namespace LeanSort.Quick

/-- Partitioning preserves multiplicities and the relative order within each
side, with ties on the left and strictly greater keys on the right. -/
structure PartitionSpec {α : Type*} [LinearOrder α]
    (pivot : α) (input left right : List α) : Prop where
  left_eq : left = input.filter (fun x => decide (x ≤ pivot))
  right_eq : right = input.filter (fun x => !decide (x ≤ pivot))
  perm : (left ++ right).Perm input
  left_bound : ∀ x ∈ left, x ≤ pivot
  right_bound : ∀ x ∈ right, pivot < x

theorem partition_spec {α : Type*} [LinearOrder α] (pivot : α) (xs : List α) :
    PartitionSpec pivot xs (xs.partition (fun x => decide (x ≤ pivot))).1
      (xs.partition (fun x => decide (x ≤ pivot))).2 := by
  refine ⟨?_, ?_, ?_, ?_, ?_⟩
  · simp [List.partition_eq_filter_filter, Function.comp_def]
  · simp [List.partition_eq_filter_filter, Function.comp_def]
  · simpa [List.partition_eq_filter_filter, Function.comp_def] using
      List.filter_append_perm (fun x => decide (x ≤ pivot)) xs
  · intro x hx
    have h : x ∈ xs ∧ x ≤ pivot := by simpa using hx
    exact h.2
  · intro x hx
    have hm : x ∈ xs ∧ ¬ x ≤ pivot := by simpa using hx
    have h := hm.2
    exact lt_of_not_ge h

theorem partitionTr_spec {α : Type*} [LinearOrder α] (p : α) (xs : List α) :
    PartitionSpec p xs (partitionTr p xs).1.1 (partitionTr p xs).1.2 := by
  simpa only [partitionTr_eq] using partition_spec p xs

theorem quickSortTr_result {α : Type*} [LinearOrder α] (xs : List α) :
    (quickSortTr xs).1 = quickSortResult xs := rfl

theorem replay_quickSortTr {α : Type*} [LinearOrder α] (xs : List α) :
    replayChecked? (quickSortTr xs).2 xs = some (quickSortTr xs).1 := by
  induction xs using quickSortResult_induct with
  | case1 => simp [replayChecked?]
  | case2 pivot xs ihl ihr =>
      let parts := xs.partition (fun x => decide (x ≤ pivot))
      rw [quickSortTr_cons]
      simp only [replayChecked?, partitionTr_eq, ite_true]
      rw [ihl, ihr]

/-- Any accepted tree reconstructs the algorithm's result, even when supplied
externally. Missing nodes, extra nodes, and false comparisons are rejected. -/
theorem replayChecked?_result {α : Type*} [LinearOrder α]
    (trace : Trace) (xs output : List α)
    (h : replayChecked? trace xs = some output) : output = quickSortResult xs := by
  induction trace generalizing xs output with
  | empty =>
      cases xs with
      | nil => simpa [replayChecked?, quickSortResult_nil] using h.symm
      | cons p xs => simp [replayChecked?] at h
  | node decisions left right ihl ihr =>
      cases xs with
      | nil => simp [replayChecked?] at h
      | cons p xs =>
          simp only [replayChecked?, partitionTr_eq] at h
          split at h
          · split at h
            · rename_i l r hl hr
              have el := ihl _ _ hl
              have er := ihr _ _ hr
              simp only [Option.some.injEq] at h
              rw [← h, el, er, quickSortResult_cons]
            · contradiction
          · contradiction

/-- Determinism includes the entire comparison tree, not merely the output. -/
theorem replayChecked?_trace {α : Type*} [LinearOrder α]
    (trace : Trace) (xs output : List α)
    (h : replayChecked? trace xs = some output) : trace = (quickSortTr xs).2 := by
  induction trace generalizing xs output with
  | empty =>
      cases xs with
      | nil => simp
      | cons p xs => simp [replayChecked?] at h
  | node decisions left right ihl ihr =>
      cases xs with
      | nil => simp [replayChecked?] at h
      | cons p xs =>
          simp only [replayChecked?, partitionTr_eq] at h
          split at h
          · rename_i hd
            split at h
            · rename_i l r hl hr
              rw [quickSortTr_cons]
              simp only [hd, ihl _ _ hl, ihr _ _ hr]
            · contradiction
          · contradiction

/-- Acceptance characterizes exactly the generated execution. -/
theorem replayChecked?_iff {α : Type*} [LinearOrder α]
    (trace : Trace) (xs output : List α) :
    replayChecked? trace xs = some output ↔ quickSortTr xs = (output, trace) := by
  constructor
  · intro h
    apply Prod.ext
    · exact (quickSortTr_result xs).trans (replayChecked?_result trace xs output h).symm
    · exact (replayChecked?_trace trace xs output h).symm
  · intro h
    simpa only [h] using replay_quickSortTr xs

theorem replayChecked?_spec {α : Type*} [LinearOrder α]
    (trace : Trace) (xs output : List α)
    (h : replayChecked? trace xs = some output) :
    IsSortingResult (· ≤ ·) xs output := by
  rw [replayChecked?_result trace xs output h]
  exact quickSortResult_spec xs

/-- Execution identity is the certificate's sole stored proof. -/
structure Certificate {α : Type*} [LinearOrder α] (input : List α) where
  output : List α
  trace : Trace
  execution : quickSortTr input = (output, trace)

def quickSortCertificate {α : Type*} [LinearOrder α] (xs : List α) : Certificate xs :=
  ⟨(quickSortTr xs).1, (quickSortTr xs).2, rfl⟩

theorem Certificate.replay {α : Type*} [LinearOrder α] {xs : List α}
    (c : Certificate xs) : replayChecked? c.trace xs = some c.output := by
  simpa only [c.execution] using replay_quickSortTr xs

theorem Certificate.spec {α : Type*} [LinearOrder α] {xs : List α}
    (c : Certificate xs) : IsSortingResult (· ≤ ·) xs c.output :=
  replayChecked?_spec c.trace xs c.output c.replay

end LeanSort.Quick
