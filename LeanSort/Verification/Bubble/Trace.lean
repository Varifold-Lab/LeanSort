import LeanSort.Verification.Bubble.Correctness
import LeanSort.Verification.Shared.RearrangementLemmas

namespace LeanSort.Bubble

/-! Correctness of the word of adjacent transpositions emitted by bubble sort. -/

/-- Replaying concatenated words is the same as replaying them successively. -/
private theorem replay_append {α : Type*} (t u : List Gen) (l : List α) :
    replay (t ++ u) l = replay u (replay t l) := by
  simpa [replay] using
    (Rearrangement.replay_append Rearrangement.AdjacentTransposition.apply t u l)

/-- Replaying a pass continuation performs exactly the rearrangement in its result. -/
private theorem replay_passAuxTr {α : Type*} [LinearOrder α] (off : ℕ)
    (p : List α) (x : α) (xs : List α) (hp : p.length = off) :
    replay (passAuxTr off x xs).2 (p ++ x :: xs) = p ++ (passAuxTr off x xs).1 := by
  induction xs generalizing off p x with
  | nil => simp [replay, Rearrangement.replay]
  | cons y ys ih =>
      by_cases h : x ≤ y
      · rw [passAuxTr_cons_of_le h]
        simpa [List.append_assoc] using
          ih (off := off + 1) (p := p ++ [x]) (x := y) (by simp [hp])
      · rw [passAuxTr_cons_of_gt h]
        simp only [replay, Rearrangement.replay, List.foldl_cons]
        rw [show Rearrangement.AdjacentTransposition.apply off (p ++ x :: y :: ys) =
            p ++ y :: x :: ys by
          simpa [hp] using Rearrangement.AdjacentTransposition.apply_prefix p x y ys]
        simpa [replay, Rearrangement.replay, List.append_assoc] using
          ih (off := off + 1) (p := p ++ [y]) (x := x) (by simp [hp])

/-- Replaying one bubble pass performs exactly the rearrangement in its result. -/
private theorem replay_passTr {α : Type*} [LinearOrder α] (off : ℕ)
    (p xs : List α) (hp : p.length = off) :
    replay (passTr off xs).2 (p ++ xs) = p ++ (passTr off xs).1 := by
  cases xs with
  | nil => simp [replay, Rearrangement.replay]
  | cons x xs =>
      simpa using replay_passAuxTr off p x xs hp

/-- A complete one-pass contract: preserve elements, move a maximum to the end,
and record exactly the rearrangement performed. -/
structure PassSpec {α : Type*} [LinearOrder α]
    (input : List α) (result : List α × List Gen) : Prop where
  perm : result.1.Perm input
  maximum_last : input ≠ [] → ∃ front maximum,
    result.1 = front ++ [maximum] ∧ ∀ z ∈ input, z ≤ maximum
  replays : replay result.2 input = result.1

theorem passTr_spec {α : Type*} [LinearOrder α] (xs : List α) :
    PassSpec xs (passTr 0 xs) := by
  refine ⟨passTr_fst_perm 0 xs, ?_, ?_⟩
  · intro h
    cases xs with
    | nil => exact (h rfl).elim
    | cons x xs =>
        obtain ⟨front, maximum, hout, _, hmax⟩ := passAuxTr_fst_decompose 0 x xs
        exact ⟨front, maximum, hout, hmax⟩
  · simpa using replay_passTr 0 [] xs rfl

/-- Replaying all passes performs exactly the rearrangement recorded by `sortAuxTr`. -/
private theorem replay_sortAuxTr {α : Type*} [LinearOrder α] (passes : ℕ)
    (xs : List α) :
    replay (sortAuxTr passes xs).2 xs = (sortAuxTr passes xs).1 := by
  induction passes generalizing xs with
  | zero => simp [replay, Rearrangement.replay]
  | succ passes ih =>
      rw [sortAuxTr_succ]
      rw [replay_append]
      rw [(passTr_spec xs).replays]
      exact ih (xs := (passTr 0 xs).1)

/-- Replaying the word emitted by bubble sort yields its computed result. -/
theorem replay_bubbleSortTrace {α : Type*} [LinearOrder α] (xs : List α) :
    replay (bubbleSortTrace xs) xs = bubbleSortResult xs := by
  simpa [bubbleSortTrace, bubbleSortResult, sortTrace] using
    replay_sortAuxTr xs.length xs

/-- Every emitted swap lies within the ambient block being scanned. -/
theorem passAuxTr_indices {α : Type*} [LinearOrder α] (off : ℕ) (x : α)
    (xs : List α) : ∀ i ∈ (passAuxTr off x xs).2, i + 1 < off + (x :: xs).length := by
  induction xs generalizing off x with
  | nil => simp
  | cons y ys ih =>
      by_cases h : x ≤ y
      · rw [passAuxTr_cons_of_le h]
        simpa [Nat.add_assoc, Nat.add_comm, Nat.add_left_comm] using ih (off + 1) y
      · rw [passAuxTr_cons_of_gt h]
        intro i hi
        rcases List.mem_cons.mp hi with rfl | hi
        · simp only [List.length_cons]
          exact Nat.add_lt_add_left (by omega) i
        · simpa [Nat.add_assoc, Nat.add_comm, Nat.add_left_comm] using ih (off + 1) x i hi

theorem passTr_indices {α : Type*} [LinearOrder α] (off : ℕ) (xs : List α) :
    ∀ i ∈ (passTr off xs).2, i + 1 < off + xs.length := by
  cases xs with
  | nil => simp
  | cons x xs => exact passAuxTr_indices off x xs

theorem sortAuxTr_indices {α : Type*} [LinearOrder α] (passes : ℕ) (xs : List α) :
    ∀ i ∈ (sortAuxTr passes xs).2, i + 1 < xs.length := by
  induction passes generalizing xs with
  | zero => simp
  | succ passes ih =>
      rw [sortAuxTr_succ]
      intro i hi
      rcases List.mem_append.mp hi with hi | hi
      · simpa using passTr_indices 0 xs i hi
      · simpa [(passTr_fst_perm 0 xs).length_eq] using ih (passTr 0 xs).1 i hi

/-- The public natural-number trace has a certified, bounded representation. -/
def bubbleSortTraceBounded {α : Type*} [LinearOrder α] (xs : List α) :
    List (SwapIndex xs.length) :=
  (bubbleSortTrace xs).attach.map fun ⟨i, hi⟩ =>
    ⟨i, Nat.lt_sub_of_add_lt (sortAuxTr_indices xs.length xs i hi)⟩

@[simp] theorem bubbleSortTraceBounded_values {α : Type*} [LinearOrder α] (xs : List α) :
    (bubbleSortTraceBounded xs).map Fin.val = bubbleSortTrace xs := by
  simp [bubbleSortTraceBounded, List.map_map]

theorem replay_bubbleSortTraceBounded {α : Type*} [LinearOrder α] (xs : List α) :
    replayBounded xs (bubbleSortTraceBounded xs) = bubbleSortResult xs := by
  simpa [replayBounded] using replay_bubbleSortTrace xs

end LeanSort.Bubble
