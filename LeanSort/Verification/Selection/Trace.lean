import LeanSort.Verification.Selection.Equations
import LeanSort.Verification.Selection.Correctness
import LeanSort.Verification.Selection.Cost

/-! # Correctness of the selection-sort trace -/

namespace LeanSort.Selection

open List

/-!
The offset carried by `sortAuxTr` is a position in the ambient list. The stronger
lemma below therefore keeps an arbitrary prefix whose length is that offset.
-/

/-- Swapping the head of a suffix with one of its entries performs exactly
`swapHeadAt`, even when the requested suffix index is out of range. -/
theorem swap_prefix_head {α : Type*} (p : List α) (i : ℕ) (x : α)
    (xs : List α) :
    (p ++ x :: xs).swap p.length (p.length + i) =
      p ++ (swapHeadAt i x xs).1 :: (swapHeadAt i x xs).2 := by
  induction p with
  | nil =>
      cases i with
      | zero => simp
      | succ i =>
          cases h : xs[i]? with
          | none =>
              have hi : xs.length ≤ i :=
                Nat.le_of_not_gt ((getElem?_eq_none_iff xs i).mp h)
              simp [swapHeadAt, h, List.set_eq_of_length_le hi]
          | some y => simp [swapHeadAt, h]
  | cons y p ih =>
      simp only [List.length_cons, List.cons_append]
      rw [Nat.add_right_comm p.length 1 i, List.swap_cons]
      exact congrArg (List.cons y) ih

/-- Replaying the word emitted by `sortAuxTr` performs exactly the rearrangement
recorded in its first component, inside an ambient list with prefix `p`. -/
theorem replay_sortAuxTr {α : Type*} [LinearOrder α] (fuel off : ℕ)
    (p xs : List α) (hp : p.length = off) :
    replay (sortAuxTr fuel off xs).2 (p ++ xs) = p ++ (sortAuxTr fuel off xs).1 := by
  induction fuel generalizing off p xs with
  | zero => simp [replay, Rearrangement.replay]
  | succ fuel ih =>
      cases xs with
      | nil => simp [replay, Rearrangement.replay]
      | cons x xs =>
          rw [sortAuxTr_succ_cons]
          simp only
          let i := minIdx (x :: xs)
          cases hswap : swapHeadAt i x xs with
          | mk newHead newTail =>
              cases hrec : sortAuxTr fuel (off + 1) newTail with
              | mk result trace =>
                  by_cases hi : i = 0
                  · have hi' : minIdx (x :: xs) = 0 := by simpa [i] using hi
                    have hpair : (newHead, newTail) = (x, xs) := by
                      simpa [hi] using hswap.symm
                    obtain ⟨rfl, rfl⟩ := Prod.mk.inj hpair
                    simp only [hi', ite_true]
                    simpa [hrec, List.append_assoc] using
                      ih (off := off + 1) (p := p ++ [newHead]) (xs := newTail)
                        (by simp [hp])
                  · have hi' : ¬minIdx (x :: xs) = 0 := by simpa [i] using hi
                    simp only [hi', ite_false, replay, Rearrangement.replay,
                      List.foldl_cons]
                    rw [show apply (off, off + minIdx (x :: xs)) (p ++ x :: xs) =
                        p ++ newHead :: newTail by
                      simpa [apply, Rearrangement.Transposition.apply, hp, i, hswap] using
                        swap_prefix_head p i x xs]
                    simpa [replay, Rearrangement.replay, hrec, List.append_assoc] using
                      ih (off := off + 1) (p := p ++ [newHead]) (xs := newTail)
                        (by simp [hp])

/-- Replaying the word emitted by selection sort yields its computed result. -/
theorem replay_selectionSortTrace {α : Type*} [LinearOrder α] (xs : List α) :
    replay (selectionSortTrace xs) xs = selectionSortResult xs := by
  simpa [selectionSortTrace, selectionSortResult, sortTrace] using
    replay_sortAuxTr xs.length 0 [] xs rfl

/-- A round's swap plan reconstructs its result without touching the fixed prefix. -/
theorem replay_round {α : Type*} [LinearOrder α] (p : List α) (x : α) (xs : List α) :
    replay (round p.length x xs).2 (p ++ x :: xs) =
      p ++ (round p.length x xs).1.1 :: (round p.length x xs).1.2 := by
  by_cases h : minIdx (x :: xs) = 0
  · simp [round, h, replay, Rearrangement.replay]
  · simpa [round, h, replay, Rearrangement.replay, apply,
      Rearrangement.Transposition.apply] using swap_prefix_head p (minIdx (x :: xs)) x xs

/-- Every emitted move starts at the active head and ends strictly inside its suffix. -/
theorem round_bounds {α : Type*} [LinearOrder α] (off : ℕ) (x : α) (xs : List α) :
    ∀ move ∈ (round off x xs).2,
      move.1 = off ∧ move.1 < move.2 ∧ move.2 < off + (x :: xs).length := by
  intro move hm
  have hb := minIdx_lt x xs
  by_cases h : minIdx (x :: xs) = 0
  · simp [round, h] at hm
  · simp only [round, h, ite_false, List.mem_singleton] at hm
    subst move
    refine ⟨rfl, ?_, Nat.add_lt_add_left hb off⟩
    exact Nat.lt_add_of_pos_right (Nat.pos_of_ne_zero h)

/-- A nonempty round fixes a minimum, preserves every occurrence, leaves an
arbitrary prefix intact, and emits at most one valid nontrivial swap. -/
structure RoundSpec {α : Type*} [LinearOrder α]
    (p : List α) (x : α) (xs : List α) (head : α) (tail : List α) (trace : List Gen) : Prop where
  replay_eq : replay trace (p ++ x :: xs) = p ++ head :: tail
  perm : (head :: tail).Perm (x :: xs)
  minimum : ∀ z ∈ x :: xs, head ≤ z
  tail_length : tail.length = xs.length
  swap_bound : trace.length ≤ 1
  indices : ∀ move ∈ trace,
    move.1 = p.length ∧ move.1 < move.2 ∧ move.2 < p.length + (x :: xs).length

theorem round_spec {α : Type*} [LinearOrder α] (p : List α) (x : α) (xs : List α) :
    RoundSpec p x xs (round p.length x xs).1.1 (round p.length x xs).1.2
      (round p.length x xs).2 := by
  refine ⟨replay_round p x xs, swapHeadAt_perm _ x xs,
    swapHeadAt_minIdx_minimal x xs, ?_, ?_, round_bounds _ x xs⟩
  · have h := (swapHeadAt_perm (minIdx (x :: xs)) x xs).length_eq
    simpa [round] using h
  · simp only [round]
    split <;> simp

/-- Swap indices are strictly ordered and within the ambient list. -/
def ValidTrace (size : ℕ) (trace : List Gen) : Prop :=
  ∀ move ∈ trace, move.1 < move.2 ∧ move.2 < size

theorem sortAuxTr_bounds {α : Type*} [LinearOrder α] (fuel off : ℕ) (xs : List α) :
    ∀ move ∈ (sortAuxTr fuel off xs).2,
      off ≤ move.1 ∧ move.1 < move.2 ∧ move.2 < off + xs.length := by
  induction fuel generalizing off xs with
  | zero => simp
  | succ fuel ih =>
      cases xs with
      | nil => simp
      | cons x xs =>
          intro move hm
          change move ∈ (round off x xs).2 ++
            (sortAuxTr fuel (off + 1) (round off x xs).1.2).2 at hm
          rcases List.mem_append.mp hm with hm | hm
          · have hb := round_bounds off x xs move hm
            exact ⟨by omega, hb.2⟩
          · have hb := ih (off + 1) (round off x xs).1.2 move hm
            have hlen : (round off x xs).1.2.length = xs.length := by
              simpa [round] using (swapHeadAt_perm (minIdx (x :: xs)) x xs).length_eq
            simp only [List.length_cons]
            omega

theorem selectionSortTrace_valid {α : Type*} [LinearOrder α] (xs : List α) :
    ValidTrace xs.length (selectionSortTrace xs) := by
  intro move hm
  have h := sortAuxTr_bounds xs.length 0 xs move hm
  simpa using h.2

/-- The checker accepts exactly valid canonical-index swaps and ordinary replay.
It does not impose the selection algorithm's minimum choices. -/
theorem replayChecked?_iff {α : Type*} (trace : List Gen) (xs ys : List α) :
    replayChecked? trace xs = some ys ↔ ValidTrace xs.length trace ∧ replay trace xs = ys := by
  induction trace generalizing xs with
  | nil => simp [replayChecked?, ValidTrace, replay, Rearrangement.replay]
  | cons move rest ih =>
      have hlen : (apply move xs).length = xs.length := by
        simp [apply, Rearrangement.Transposition.apply]
      by_cases h : move.1 < move.2 ∧ move.2 < xs.length
      · simp [replayChecked?, h, ih, hlen, ValidTrace, replay, Rearrangement.replay,
          List.foldl_cons]
      · simp [replayChecked?, h, ValidTrace]

theorem replayChecked?_selectionSortTrace {α : Type*} [LinearOrder α] (xs : List α) :
    replayChecked? (selectionSortTrace xs) xs = some (selectionSortResult xs) :=
  (replayChecked?_iff _ _ _).mpr ⟨selectionSortTrace_valid xs, replay_selectionSortTrace xs⟩

/-- Execution identity is the sole stored proof; all contracts are derived. -/
structure Certificate {α : Type*} [LinearOrder α] (input : List α) where
  output : List α
  trace : List Gen
  execution : sortTrace input = (output, trace)

def selectionSortCertificate {α : Type*} [LinearOrder α] (xs : List α) : Certificate xs :=
  ⟨(sortTrace xs).1, (sortTrace xs).2, rfl⟩

theorem Certificate.spec {α : Type*} [LinearOrder α] {xs : List α} (c : Certificate xs) :
    IsSortingResult (· ≤ ·) xs c.output := by
  simpa only [selectionSortResult, c.execution] using selectionSortResult_spec xs

theorem Certificate.replay {α : Type*} [LinearOrder α] {xs : List α} (c : Certificate xs) :
    replayChecked? c.trace xs = some c.output := by
  simpa only [selectionSortTrace, selectionSortResult, c.execution] using
    replayChecked?_selectionSortTrace xs

theorem Certificate.valid {α : Type*} [LinearOrder α] {xs : List α} (c : Certificate xs) :
    ValidTrace xs.length c.trace := by
  simpa only [selectionSortTrace, c.execution] using selectionSortTrace_valid xs

theorem Certificate.cost {α : Type*} [LinearOrder α] {xs : List α} (c : Certificate xs) :
    c.trace.length ≤ xs.length := by
  simpa only [selectionSortTrace, c.execution] using length_selectionSortTrace_le xs

theorem Certificate.cost_le_pred {α : Type*} [LinearOrder α] {xs : List α}
    (c : Certificate xs) : c.trace.length ≤ xs.length - 1 := by
  simpa only [selectionSwapCost, selectionSortTrace, c.execution] using selectionSwapCost_le_pred xs

/-- A partial run carries its fixed ambient prefix and available round budget. -/
structure PartialCertificate {α : Type*} [LinearOrder α]
    (fuel : ℕ) (p input : List α) where
  output : List α
  trace : List Gen
  execution : sortAuxTr fuel p.length input = (output, trace)

def selectionPartialCertificate {α : Type*} [LinearOrder α]
    (fuel : ℕ) (p input : List α) : PartialCertificate fuel p input :=
  ⟨(sortAuxTr fuel p.length input).1, (sortAuxTr fuel p.length input).2, rfl⟩

theorem PartialCertificate.settled {α : Type*} [LinearOrder α]
    {fuel : ℕ} {p xs : List α} (c : PartialCertificate fuel p xs) :
    SettledPrefix fuel c.output := by
  simpa only [c.execution] using sortAuxTr_settled fuel p.length xs

theorem PartialCertificate.settled_length {α : Type*} [LinearOrder α]
    {fuel : ℕ} {p xs : List α} (c : PartialCertificate fuel p xs) :
    (c.output.take fuel).length = min fuel xs.length := by
  simpa only [c.execution] using sortAuxTr_settled_length fuel p.length xs

theorem PartialCertificate.perm {α : Type*} [LinearOrder α]
    {fuel : ℕ} {p xs : List α} (c : PartialCertificate fuel p xs) :
    c.output.Perm xs := by
  simpa only [c.execution] using sortAuxTr_fst_perm fuel p.length xs

/-- Checked replay reconstructs the ambient result and leaves its prefix intact. -/
theorem PartialCertificate.replay {α : Type*} [LinearOrder α]
    {fuel : ℕ} {p xs : List α} (c : PartialCertificate fuel p xs) :
    replayChecked? c.trace (p ++ xs) = some (p ++ c.output) := by
  apply (replayChecked?_iff _ _ _).mpr
  constructor
  · intro move hm
    have hc : (sortAuxTr fuel p.length xs).2 = c.trace := congrArg Prod.snd c.execution
    have hb := sortAuxTr_bounds fuel p.length xs move (hc.symm ▸ hm)
    simpa only [List.length_append] using hb.2
  · simpa only [c.execution] using replay_sortAuxTr fuel p.length p xs rfl

theorem PartialCertificate.cost {α : Type*} [LinearOrder α]
    {fuel : ℕ} {p xs : List α} (c : PartialCertificate fuel p xs) :
    c.trace.length ≤ min fuel (xs.length - 1) := by
  simpa only [c.execution] using length_sortAuxTr_snd_le_min fuel p.length xs

/-- Once the available rounds cover the suffix, the partial certificate is a
complete sorting certificate for that suffix. -/
theorem PartialCertificate.complete {α : Type*} [LinearOrder α]
    {fuel : ℕ} {p xs : List α} (c : PartialCertificate fuel p xs)
    (h : xs.length ≤ fuel) : IsSortingResult (· ≤ ·) xs c.output := by
  refine ⟨?_, c.perm⟩
  simpa only [c.execution] using sorted_sortAuxTr_of_length_le fuel p.length xs h

end LeanSort.Selection
