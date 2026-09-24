import LeanSort.Verification.Intro.Correctness

/-! Strategy trees record all partition decisions and delegated leaf sizes.
Checked replay reruns insertion/heap leaves; their internal comparisons are not
encoded in this tree. Depth zero takes precedence over the insertion cutoff. -/

namespace LeanSort.Intro

inductive Trace where
  | heap (size : Nat)
  | insertion (size : Nat)
  | empty
  | partition (decisions : List Bool) (left right : Trace)
  deriving DecidableEq, Repr

variable {α : Type} [LinearOrder α]

def traceAux (cutoff : Nat) : Nat → List α → Trace
  | 0, xs => .heap xs.length
  | depth + 1, xs =>
    if xs.length ≤ cutoff then .insertion xs.length else
      match xs with
      | [] => .empty
      | p :: rest =>
        let parts := rest.partition (fun x => decide (x ≤ p))
        .partition (rest.map (fun x => decide (x ≤ p)))
          (traceAux cutoff depth parts.1) (traceAux cutoff depth parts.2)

def introSortTrace (xs : List α) : Trace := traceAux insertionCutoff (depthLimit xs.length) xs

def replayAux? (cutoff : Nat) : Nat → Trace → List α → Option (List α)
  | 0, trace, xs =>
    if trace = .heap xs.length then some (LeanSort.Heap.heapSortResult xs) else none
  | depth + 1, trace, xs =>
    if xs.length ≤ cutoff then
      if trace = .insertion xs.length then some (xs.insertionSort (· ≤ ·)) else none
    else
      match xs, trace with
      | [], .empty => some []
      | p :: rest, .partition decisions left right =>
        if decisions = rest.map (fun x => decide (x ≤ p)) then
          let parts := rest.partition (fun x => decide (x ≤ p))
          do
            let l ← replayAux? cutoff depth left parts.1
            let r ← replayAux? cutoff depth right parts.2
            pure (l ++ p :: r)
        else none
      | _, _ => none

theorem replayAux?_eq (cutoff depth : Nat) (trace : Trace) (xs : List α) :
    replayAux? cutoff depth trace xs =
      if trace = traceAux cutoff depth xs then some (introSortAux cutoff depth xs) else none := by
  induction depth generalizing trace xs with
  | zero => rfl
  | succ depth ih =>
    by_cases h : xs.length ≤ cutoff
    · simp [replayAux?, traceAux, introSortAux, h]
    · cases xs with
      | nil => simp at h
      | cons p rest =>
        simp only [List.length_cons] at h
        cases trace <;> simp [replayAux?, traceAux, introSortAux, h, ih]
        split_ifs <;> simp_all

def replayChecked? (trace : Trace) (xs : List α) : Option (List α) :=
  replayAux? insertionCutoff (depthLimit xs.length) trace xs

theorem replayAux?_iff (cutoff depth : Nat) (trace : Trace) (xs output : List α) :
    replayAux? cutoff depth trace xs = some output ↔
      trace = traceAux cutoff depth xs ∧ output = introSortAux cutoff depth xs := by
  rw [replayAux?_eq]
  split <;> simp_all [eq_comm]

theorem replayChecked?_iff (trace : Trace) (xs output : List α) :
    replayChecked? trace xs = some output ↔
      trace = introSortTrace xs ∧ output = introSortResult xs := replayAux?_iff _ _ _ _ _

@[simp] theorem replay_introSortTrace (xs : List α) :
    replayChecked? (introSortTrace xs) xs = some (introSortResult xs) :=
  (replayChecked?_iff _ _ _).mpr ⟨rfl, rfl⟩

theorem replayChecked?_spec (trace : Trace) (xs output : List α)
    (h : replayChecked? trace xs = some output) : IsSortingResult (· ≤ ·) xs output := by
  obtain ⟨_, rfl⟩ := (replayChecked?_iff _ _ _).mp h
  exact introSortResult_spec xs

/-- Every input occurrence is either a pivot or belongs to exactly one delegated leaf. -/
def Trace.accounted : Trace → Nat
  | .heap n | .insertion n => n
  | .empty => 0
  | .partition _ l r => l.accounted + 1 + r.accounted

def Trace.partitionDepth : Trace → Nat
  | .partition _ l r => 1 + max l.partitionDepth r.partitionDepth
  | _ => 0

theorem traceAux_accounted (cutoff depth : Nat) (xs : List α) :
    (traceAux cutoff depth xs).accounted = xs.length := by
  induction depth generalizing xs with
  | zero => rfl
  | succ depth ih =>
    by_cases h : xs.length ≤ cutoff
    · simp [traceAux, h, Trace.accounted]
    · cases xs with
      | nil => simp at h
      | cons p rest =>
        have := partition_lengths p rest
        simp only [List.length_cons] at h
        simp only [traceAux, ite_eq_right h, Trace.accounted, ih, List.length_cons]
        omega

theorem traceAux_partitionDepth_le (cutoff depth : Nat) (xs : List α) :
    (traceAux cutoff depth xs).partitionDepth ≤ depth := by
  induction depth generalizing xs with
  | zero => simp [traceAux, Trace.partitionDepth]
  | succ depth ih =>
    by_cases h : xs.length ≤ cutoff
    · simp [traceAux, h, Trace.partitionDepth]
    · cases xs with
      | nil => simp at h
      | cons p rest =>
        simp only [traceAux, ite_eq_right h, Trace.partitionDepth]
        have hl := ih (rest.partition (fun x => decide (x ≤ p))).1
        have hr := ih (rest.partition (fun x => decide (x ≤ p))).2
        omega

@[simp] theorem introSortTrace_accounted (xs : List α) :
    (introSortTrace xs).accounted = xs.length := traceAux_accounted _ _ _

theorem introSortTrace_partitionDepth_le (xs : List α) :
    (introSortTrace xs).partitionDepth ≤ 2 * xs.length.log2 := traceAux_partitionDepth_le _ _ _

end LeanSort.Intro
