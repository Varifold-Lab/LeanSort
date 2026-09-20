import LeanSort.Verification.Tree.Correctness

/-! Agreement of tracing and checked replay with the executable insertion fold. -/

namespace LeanSort.Tree

variable {α : Type*} [LinearOrder α]

@[simp] theorem buildTrace_result (xs : List α) (t : SearchTree α) :
    (buildTrace xs t).1 = xs.foldl (fun tree x => insert x tree) t := by
  induction xs generalizing t with
  | nil => rfl
  | cons x xs ih => simp [buildTrace, ih]

@[simp] theorem buildTrace_length (xs : List α) (t : SearchTree α) :
    (buildTrace xs t).2.length = xs.length := by
  induction xs generalizing t with
  | nil => rfl
  | cons x xs ih => simp [buildTrace, ih]

@[simp] theorem sortTrace_result (xs : List α) :
    (sortTrace xs).1 = treeSortResult xs := by
  simp [sortTrace, treeSortResult, fromList]

@[simp] theorem treeSortTrace_length (xs : List α) :
    (treeSortTrace xs).length = xs.length := by simp [treeSortTrace, sortTrace]

/-- The checker accepts precisely the canonical path and returns the actual
inserted tree. This statement also applies to trees without a search invariant. -/
theorem replayInsert?_eq (x : α) (t : SearchTree α) (path : List Bool) :
    replayInsert? x t path =
      if path = insertionPath x t then some (insert x t) else none := by
  induction t generalizing path with
  | empty => cases path <;> simp [replayInsert?, insertionPath, insert]
  | node l v r ihl ihr =>
      cases path with
      | nil => simp [replayInsert?, insertionPath, insert]; split <;> simp
      | cons b path =>
          cases b <;> by_cases h : x < v <;>
            simp [replayInsert?, insertionPath, insert, h, ihl, ihr]

theorem replayBuild?_eq (xs : List α) (t : SearchTree α) (paths : List (List Bool)) :
    replayBuild? xs paths t =
      if paths = (buildTrace xs t).2 then some (buildTrace xs t).1 else none := by
  induction xs generalizing t paths with
  | nil => cases paths <;> simp [replayBuild?, buildTrace]
  | cons x xs ih =>
      cases paths with
      | nil => simp [replayBuild?, buildTrace]
      | cons path paths =>
          simp only [replayBuild?, replayInsert?_eq]
          by_cases h : path = insertionPath x t
          · simp [h, ih, buildTrace]
          · simp [h, buildTrace]

theorem replayChecked?_eq (xs : List α) (paths : List (List Bool)) :
    replayChecked? paths xs =
      if paths = treeSortTrace xs then some (treeSortResult xs) else none := by
  simp only [replayChecked?, replayBuild?_eq, treeSortTrace, sortTrace]
  split <;> simp_all [treeSortResult, fromList]

@[simp] theorem replay_treeSortTrace (xs : List α) :
    replayChecked? (treeSortTrace xs) xs = some (treeSortResult xs) := by
  simp [replayChecked?_eq]

/-- Acceptance certifies both the full log and the sorted output. -/
theorem replayChecked?_iff (xs output : List α) (paths : List (List Bool)) :
    replayChecked? paths xs = some output ↔
      paths = treeSortTrace xs ∧ output = treeSortResult xs := by
  rw [replayChecked?_eq]
  split <;> simp_all [eq_comm]

theorem replayChecked?_spec (xs output : List α) (paths : List (List Bool))
    (h : replayChecked? paths xs = some output) : IsSortingResult (· ≤ ·) xs output := by
  obtain ⟨_, rfl⟩ := (replayChecked?_iff xs output paths).mp h
  exact treeSortResult_spec xs

end LeanSort.Tree
