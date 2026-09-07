import LeanSort.Verification.Shell.Correctness

/-! Semantics of the gapped transposition trace emitted by Shell sort. -/

namespace LeanSort.Shell

theorem replayArray_append {α : Type*} (first rest : List Gen) (xs : Array α) :
    replayArray (first ++ rest) xs = replayArray rest (replayArray first xs) := by
  simp [replayArray, Rearrangement.replay, List.foldl_append]

theorem replay_gapInsertTrace {α : Type*} [LinearOrder α]
    (gap : ℕ) (xs : Array α) (i : ℕ) :
    replayArray (gapInsertTrace gap xs i).2 xs = (gapInsertTrace gap xs i).1 := by
  fun_induction gapInsertTrace with
  | case1 xs i h hlt result rest he ih =>
      rw [he] at ih
      simpa only [replayArray, Rearrangement.replay, List.foldl_cons,
        Array.swapIfInBounds, dite_eq_left h.2.2,
        dite_eq_left (show i - gap < xs.size by omega)] using ih
  | case2 => rfl
  | case3 => rfl

theorem replay_insertionsTrace {α : Type*} [LinearOrder α]
    (gap : ℕ) (indices : List ℕ) (xs : Array α) :
    replayArray (insertionsTrace gap indices xs).2 xs = (insertionsTrace gap indices xs).1 := by
  induction indices generalizing xs with
  | nil => rfl
  | cons i indices ih =>
      simp only [insertionsTrace, replayArray_append, replay_gapInsertTrace, ih]

theorem replay_gapPassTrace {α : Type*} [LinearOrder α] (gap : ℕ) (xs : Array α) :
    replayArray (gapPassTrace gap xs).2 xs = (gapPassTrace gap xs).1 :=
  replay_insertionsTrace _ _ _

theorem replay_passesTrace {α : Type*} [LinearOrder α] (steps : List ℕ) (xs : Array α) :
    replayArray (passesTrace steps xs).2 xs = (passesTrace steps xs).1 := by
  induction steps generalizing xs with
  | nil => rfl
  | cons gap steps ih =>
      simp only [passesTrace, replayArray_append, replay_gapPassTrace, ih]

theorem replay_shellSortTrace {α : Type*} [LinearOrder α] (xs : List α) :
    replay (shellSortTrace xs) xs = shellSortResult xs := by
  simp [replay, shellSortTrace, sortTrace, replay_passesTrace,
    passesTrace_result, shellSortResult]

theorem replay_shellSortTrace_spec {α : Type*} [LinearOrder α] (xs : List α) :
    LeanSort.IsSortingResult (· ≤ ·) xs (replay (shellSortTrace xs) xs) := by
  rw [replay_shellSortTrace]
  exact shellSortResult_spec xs

/-- Every recorded transposition exchanges valid positions exactly one gap apart. -/
theorem gapInsertTrace_moves {α : Type*} [LinearOrder α]
    (gap : ℕ) (xs : Array α) (i : ℕ) :
    ∀ move ∈ (gapInsertTrace gap xs i).2,
      move.1 < xs.size ∧ move.2 + gap = move.1 ∧ 0 < gap := by
  fun_induction gapInsertTrace with
  | case1 xs i h hlt result rest he ih =>
      rw [he] at ih
      intro move hm
      rcases List.mem_cons.mp hm with rfl | hm
      · exact ⟨h.2.2, by omega, h.1⟩
      · simpa using ih move hm
  | case2 => simp
  | case3 => simp

end LeanSort.Shell
