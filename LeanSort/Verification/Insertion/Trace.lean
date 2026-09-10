import LeanSort.Verification.Insertion.Equations
import LeanSort.Verification.Insertion.Correctness
import LeanSort.Verification.Shared.RearrangementLemmas

/-!
# Correctness of the insertion-sort trace

The offset carried by `sortTr` and `insertTr` is a position in the ambient list. The
stronger lemmas below therefore keep an arbitrary prefix whose length is that offset.
-/

namespace LeanSort.Insertion

/-- Replaying concatenated words is the same as replaying them successively. -/
theorem replay_append {α : Type*} (t u : List Gen) (l : List α) :
    replay (t ++ u) l = replay u (replay t l) := by
  simpa [replay] using
    (Rearrangement.replay_append Rearrangement.AdjacentTransposition.apply t u l)

/-- The trace emitted while inserting `x` performs exactly the insertion recorded in the
first component of `insertTr`, inside an ambient list with prefix `p`. -/
theorem replay_insertTr {α : Type*} [LinearOrder α] (off : ℕ) (p : List α)
    (x : α) (s : List α) (hp : p.length = off) :
    replay (insertTr off x s).2 (p ++ x :: s) = p ++ (insertTr off x s).1 := by
  induction s generalizing off p with
  | nil => simp [replay, Rearrangement.replay]
  | cons y ys ih =>
      by_cases h : x ≤ y
      · rw [insertTr_cons_of_le h]
        simp [replay, Rearrangement.replay]
      · rw [insertTr_cons_of_gt h]
        simp only [replay, Rearrangement.replay, List.foldl_cons]
        rw [show Rearrangement.AdjacentTransposition.apply off (p ++ x :: y :: ys) =
            p ++ y :: x :: ys by
          simpa [hp] using Rearrangement.AdjacentTransposition.apply_prefix p x y ys]
        simpa [replay, Rearrangement.replay, List.append_assoc] using
          ih (off := off + 1) (p := p ++ [y]) (by simp [hp])

/-- The complete contract of a single insertion: library meaning, exact path,
replay inside any prefix, and preservation of sortedness. -/
structure InsertSpec {α : Type*} [LinearOrder α] (off : ℕ) (x : α) (s result : List α)
    (trace : List Gen) : Prop where
  output_eq : result = s.orderedInsert (· ≤ ·) x
  trace_eq : trace = List.range' off (s.takeWhile (fun y => decide (y < x))).length
  replays : ∀ p : List α, p.length = off → replay trace (p ++ x :: s) = p ++ result
  sorted : s.Pairwise (· ≤ ·) → result.Pairwise (· ≤ ·)

theorem insertTr_spec {α : Type*} [LinearOrder α] (off : ℕ) (x : α) (s : List α) :
    InsertSpec off x s (insertTr off x s).1 (insertTr off x s).2 where
  output_eq := insertTr_fst off x s
  trace_eq := insertTr_trace off x s
  replays p hp := replay_insertTr off p x s hp
  sorted hs := by rw [insertTr_fst]; exact hs.orderedInsert x s

/-- The trace emitted by `sortTr` performs exactly the rearrangement recorded in its first
component, inside an ambient list with prefix `p`. -/
theorem replay_sortTr {α : Type*} [LinearOrder α] (off : ℕ) (p l : List α)
    (hp : p.length = off) :
    replay (sortTr off l).2 (p ++ l) = p ++ (sortTr off l).1 := by
  induction l generalizing off p with
  | nil => simp [replay, Rearrangement.replay]
  | cons x l ih =>
      rw [sortTr_cons, replay_append]
      rw [show p ++ x :: l = (p ++ [x]) ++ l by simp]
      rw [ih (off := off + 1) (p := p ++ [x])]
      · simpa [List.append_assoc] using
          (insertTr_spec off x (sortTr (off + 1) l).1).replays p hp
      · simp [hp]

/-- Replaying the word emitted by insertion sort yields its computed sorted result. -/
theorem replay_insertionSortTrace {α : Type*} [LinearOrder α] (l : List α) :
    replay (insertionSortTrace l) l = insertionSortResult l := by
  simpa [insertionSortTrace, insertionSortResult] using
    replay_sortTr (α := α) 0 [] l rfl

theorem insertTr_indices {α : Type*} [LinearOrder α] (off : ℕ) (x : α) (s : List α)
    (i : Gen) (hi : i ∈ (insertTr off x s).2) : off ≤ i ∧ i < off + s.length := by
  rw [insertTr_trace, List.mem_range'_1] at hi
  have hlen := (List.takeWhile_sublist (p := fun y => decide (y < x)) (l := s)).length_le
  exact ⟨hi.1, hi.2.trans_le (Nat.add_le_add_left hlen off)⟩

theorem sortTr_indices {α : Type*} [LinearOrder α] (off : ℕ) (xs : List α)
    (i : Gen) (hi : i ∈ (sortTr off xs).2) : off ≤ i ∧ i + 1 < off + xs.length := by
  induction xs generalizing off with
  | nil => simp at hi
  | cons x xs ih =>
    rw [sortTr_cons, List.mem_append] at hi
    rcases hi with hi | hi
    · have hb := ih (off + 1) hi
      refine ⟨(Nat.le_succ off).trans hb.1, ?_⟩
      simpa [Nat.add_assoc, Nat.add_comm, Nat.add_left_comm] using hb.2
    · have hb := insertTr_indices off x (sortTr (off + 1) xs).1 i hi
      have hlen : (sortTr (off + 1) xs).1.length = xs.length := by
        rw [sortTr_fst]
        exact (List.perm_insertionSort (· ≤ ·) xs).length_eq
      rw [hlen] at hb
      refine ⟨hb.1, ?_⟩
      simpa only [List.length_cons, Nat.add_assoc] using Nat.add_lt_add_right hb.2 1

/-- Each generated position carries a proof that both swapped entries exist. -/
def insertionSortBoundedTrace {α : Type*} [LinearOrder α] (xs : List α) :
    List (SwapIndex xs.length) :=
  (insertionSortTrace xs).attach.map fun i =>
    ⟨i.val, Nat.lt_sub_of_add_lt (by
      simpa using (sortTr_indices 0 xs i.val i.property).2)⟩

@[simp] theorem insertionSortBoundedTrace_erase {α : Type*} [LinearOrder α] (xs : List α) :
    (insertionSortBoundedTrace xs).map Fin.val = insertionSortTrace xs := by
  simp [insertionSortBoundedTrace, List.map_map]

theorem replay_insertionSortBoundedTrace {α : Type*} [LinearOrder α] (xs : List α) :
    replayBounded xs (insertionSortBoundedTrace xs) = insertionSortResult xs := by
  simpa [replayBounded] using replay_insertionSortTrace xs

/-- A sorting certificate binds the computed result to its executable trace and
the two mathematical guarantees. Keeping these fields together prevents a
result and a trace from being reasoned about independently by accident. -/
structure SortCertificate {α : Type*} [LinearOrder α] (input : List α) where
  output : List α
  trace : List Gen
  replay_eq : replay trace input = output
  sorted : output.Pairwise (· ≤ ·)
  perm : output.Perm input

/-- The instrumented insertion sort produces a complete certificate. -/
def insertionSortCertificate {α : Type*} [LinearOrder α] (xs : List α) :
  SortCertificate xs where
  output := insertionSortResult xs
  trace := insertionSortTrace xs
  replay_eq := replay_insertionSortTrace xs
  sorted := sorted_insertionSortResult xs
  perm := insertionSortResult_perm xs

@[simp] theorem insertionSortCertificate_output {α : Type*} [LinearOrder α]
    (xs : List α) :
    (insertionSortCertificate xs).output = insertionSortResult xs := rfl

@[simp] theorem insertionSortCertificate_trace {α : Type*} [LinearOrder α]
    (xs : List α) :
    (insertionSortCertificate xs).trace = insertionSortTrace xs := rfl

theorem insertionSortCertificate_isSortingResult {α : Type*} [LinearOrder α]
    (xs : List α) :
    IsSortingResult (· ≤ ·) xs (insertionSortCertificate xs).output := by
  exact ⟨(insertionSortCertificate xs).sorted, (insertionSortCertificate xs).perm⟩

end LeanSort.Insertion
