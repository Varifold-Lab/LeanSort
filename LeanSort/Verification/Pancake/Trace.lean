import LeanSort.Verification.Pancake.Equations
import LeanSort.Verification.Shared.RearrangementLemmas
import LeanSort.Verification.Pancake.Correctness
import LeanSort.Verification.Pancake.Cost

/-! Semantics of the prefix-reversal trace emitted by pancake sort. -/

namespace LeanSort.Pancake

/-- Replaying the trace of one round reconstructs that round's output. -/
theorem replay_round {α : Type*} [LinearOrder α] (k : ℕ) (xs : List α) :
    replay (round k xs).2 xs = (round k xs).1 := rfl

theorem replay_append {α : Type*} (first rest : List Gen) (xs : List α) :
    replay (first ++ rest) xs = replay rest (replay first xs) :=
  Rearrangement.replay_append flip first rest xs

/-- Replaying all traces emitted by `sortAux` reconstructs its result. -/
theorem replay_sortAux {α : Type*} [LinearOrder α] (k : ℕ) (xs : List α) :
    replay (sortAux k xs).2 xs = (sortAux k xs).1 := by
  induction k generalizing xs with
  | zero => simp [sortAux, replay]
  | succ k ih =>
      simpa only [sortAux, replay_append, replay_round] using
        ih (round (k + 1) xs).1

/-- The complete pancake-sort trace replays from the input to the reported output. -/
theorem replay_pancakeSortTrace {α : Type*} [LinearOrder α] (xs : List α) :
    replay (pancakeSortTrace xs) xs = pancakeSort xs := by
  exact replay_sortAux xs.length xs

/-- Every emitted flip acts nontrivially within the active prefix. -/
theorem round_trace_bounds {α : Type*} [LinearOrder α]
    (k : ℕ) (xs : List α) (hkpos : 0 < k) (hk : k ≤ xs.length) :
    ∀ j ∈ (round k xs).2, 2 ≤ j ∧ j ≤ k := by
  have hlen : (xs.take k).length = k := by simp [List.length_take, Nat.min_eq_left hk]
  have hne : xs.take k ≠ [] := by
    intro h
    have := congrArg List.length h
    simp [hlen] at this
    omega
  obtain ⟨v, hm, _, _⟩ := maxIdx_spec (xs.take k) hne
  rw [hlen] at hm
  intro j hj
  rw [round_eq] at hj
  dsimp only at hj
  split_ifs at hj <;>
    simp only [List.mem_cons, List.mem_nil_iff, or_false] at hj
  all_goals simp only [Gen, Rearrangement.PrefixReversal.Gen] at *
  all_goals omega

/-- One round exposes the maximum it fixes, the untouched suffix, replay,
valid flip lengths, and the two-flip budget in a single proposition. -/
structure RoundSpec {α : Type*} [LinearOrder α]
    (k : ℕ) (input output : List α) (trace : List Gen) : Prop where
  replay_eq : replay trace input = output
  bounds : ∀ j ∈ trace, 2 ≤ j ∧ j ≤ k
  cost_le : trace.length ≤ 2
  fixes_maximum : ∃ front maximum,
    output = front ++ maximum :: input.drop k ∧
    front.length + 1 = k ∧
    (front ++ [maximum]).Perm (input.take k) ∧
    ∀ z ∈ input.take k, z ≤ maximum

theorem round_spec {α : Type*} [LinearOrder α]
    (k : ℕ) (xs : List α) (hkpos : 0 < k) (hk : k ≤ xs.length) :
    RoundSpec k xs (round k xs).1 (round k xs).2 where
  replay_eq := replay_round k xs
  bounds := round_trace_bounds k xs hkpos hk
  cost_le := length_round_snd_le_two k xs
  fixes_maximum := round_fst_decompose k xs hkpos hk

/-- Whole-input permutation follows from the active-prefix decomposition. -/
theorem RoundSpec.perm {α : Type*} [LinearOrder α]
    {k : ℕ} {input output : List α} {trace : List Gen}
    (h : RoundSpec k input output trace) : output.Perm input := by
  obtain ⟨front, maximum, hout, _, hp, _⟩ := h.fixes_maximum
  rw [hout]
  simpa [List.append_assoc] using hp.append_right (input.drop k)

/-- Later rounds remain inside the original active prefix. -/
theorem sortAux_trace_bounds {α : Type*} [LinearOrder α]
    (k : ℕ) (xs : List α) (hk : k ≤ xs.length) :
    ∀ j ∈ (sortAux k xs).2, 2 ≤ j ∧ j ≤ k := by
  induction k generalizing xs with
  | zero => simp [sortAux]
  | succ k ih =>
      have step := round_spec (k + 1) xs (by omega) hk
      have hs := ih (round (k + 1) xs).1 (by simp; omega)
      simpa only [sortAux, List.mem_append] using
        (show ∀ j, j ∈ (round (k + 1) xs).2 ∨
          j ∈ (sortAux k (round (k + 1) xs).1).2 → 2 ≤ j ∧ j ≤ k + 1 from by
          intro j hj
          rcases hj with hj | hj
          · exact step.bounds j hj
          · have hb := hs j hj; exact ⟨hb.1, Nat.le_trans hb.2 (Nat.le_succ k)⟩)

/-- Checked replay accepts exactly traces whose lengths are valid, and returns
ordinary replay. This condition alone does not imply sortedness. -/
theorem replayChecked?_iff {α : Type*} (trace : List Gen) (xs result : List α) :
    replayChecked? trace xs = some result ↔
      (∀ k ∈ trace, 2 ≤ k ∧ k ≤ xs.length) ∧ replay trace xs = result := by
  induction trace generalizing xs with
  | nil => simp [replayChecked?, replay, Rearrangement.replay]
  | cons k rest ih =>
      by_cases hk : 2 ≤ k ∧ k ≤ xs.length
      · simp [replayChecked?, hk, ih, replay, Rearrangement.replay]
      · simp [replayChecked?, hk]

theorem replayChecked?_pancakeSortTrace {α : Type*} [LinearOrder α] (xs : List α) :
    replayChecked? (pancakeSortTrace xs) xs = some (pancakeSort xs) := by
  apply (replayChecked?_iff _ _ _).2
  exact ⟨sortAux_trace_bounds xs.length xs le_rfl, replay_pancakeSortTrace xs⟩

/-- Store the execution identity once; replay, correctness and cost are derived
below rather than duplicated as independent certificate fields. -/
structure SortCertificate {α : Type*} [LinearOrder α] (input : List α) where
  output : List α
  trace : List Gen
  execution_eq : sortTrace input = (output, trace)

theorem SortCertificate.output_eq {α : Type*} [LinearOrder α] {input : List α}
    (cert : SortCertificate input) : cert.output = pancakeSort input :=
  (congrArg Prod.fst cert.execution_eq).symm

theorem SortCertificate.trace_eq {α : Type*} [LinearOrder α] {input : List α}
    (cert : SortCertificate input) : cert.trace = pancakeSortTrace input :=
  (congrArg Prod.snd cert.execution_eq).symm

theorem SortCertificate.checked_replay {α : Type*} [LinearOrder α] {input : List α}
    (cert : SortCertificate input) : replayChecked? cert.trace input = some cert.output := by
  rw [cert.output_eq, cert.trace_eq]
  exact replayChecked?_pancakeSortTrace input

theorem SortCertificate.sorted {α : Type*} [LinearOrder α] {input : List α}
    (cert : SortCertificate input) : cert.output.Pairwise (· ≤ ·) := by
  rw [cert.output_eq]
  exact sorted_pancakeSort input

theorem SortCertificate.perm {α : Type*} [LinearOrder α] {input : List α}
    (cert : SortCertificate input) : cert.output.Perm input := by
  rw [cert.output_eq]
  exact pancakeSort_perm input

theorem SortCertificate.cost_le {α : Type*} [LinearOrder α] {input : List α}
    (cert : SortCertificate input) : cert.trace.length ≤ 2 * input.length := by
  rw [cert.trace_eq]
  exact pancakeFlipCost_le_two_mul_length input

def pancakeSortCertificate {α : Type*} [LinearOrder α] (xs : List α) :
    SortCertificate xs where
  output := pancakeSort xs
  trace := pancakeSortTrace xs
  execution_eq := by simp [pancakeSort, pancakeSortTrace]

end LeanSort.Pancake
