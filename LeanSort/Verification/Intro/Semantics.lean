import LeanSort.Verification.Intro.Trace

namespace LeanSort.Intro

variable {α : Type} [LinearOrder α]

/-- Evaluation rules explicitly require heap fallback at zero budget and pass
the same decremented budget to both children of every partition. -/
inductive Derivation (cutoff : Nat) : Nat → List α → List α → Trace → Prop
  | heap (xs) : Derivation cutoff 0 xs (LeanSort.Heap.heapSortResult xs) (.heap xs.length)
  | insertion (depth : Nat) (xs) (small : xs.length ≤ cutoff) :
      Derivation cutoff (depth + 1) xs (xs.insertionSort (· ≤ ·)) (.insertion xs.length)
  | partition (depth : Nat) (p : α) (rest : List α) (large : cutoff < (p :: rest).length)
      {lo ro : List α} {lt rt : Trace}
      (left : Derivation cutoff depth (rest.partition (fun x => decide (x ≤ p))).1 lo lt)
      (right : Derivation cutoff depth (rest.partition (fun x => decide (x ≤ p))).2 ro rt) :
      Derivation cutoff (depth + 1) (p :: rest) (lo ++ p :: ro)
        (.partition (rest.map (fun x => decide (x ≤ p))) lt rt)

theorem Derivation.execution {cutoff depth : Nat} {xs output : List α} {trace : Trace}
    (h : Derivation cutoff depth xs output trace) :
    output = introSortAux cutoff depth xs ∧ trace = traceAux cutoff depth xs := by
  induction h with
  | heap => exact ⟨rfl, rfl⟩
  | insertion d xs small => simp only [introSortAux, traceAux, small, ite_true, and_self]
  | partition d p rest large left right ihl ihr =>
    simp only [introSortAux, traceAux, ite_eq_right (Nat.not_le.mpr large)]
    exact ⟨by rw [ihl.1, ihr.1], by rw [ihl.2, ihr.2]⟩

theorem derivation (cutoff depth : Nat) (xs : List α) :
    Derivation cutoff depth xs (introSortAux cutoff depth xs) (traceAux cutoff depth xs) := by
  induction depth generalizing xs with
  | zero => exact .heap xs
  | succ depth ih =>
    by_cases h : xs.length ≤ cutoff
    · simpa only [introSortAux, traceAux, h, ite_true] using
        (Derivation.insertion (α := α) (cutoff := cutoff) depth xs h)
    · cases xs with
      | nil => simp at h
      | cons p rest =>
        simpa only [introSortAux, traceAux, h, ite_false] using
          (Derivation.partition depth p rest (by omega : cutoff < (p :: rest).length)
            (ih _) (ih _))

theorem replayAux?_derivation_iff (cutoff depth : Nat) (trace : Trace) (xs output : List α) :
    replayAux? cutoff depth trace xs = some output ↔ Derivation cutoff depth xs output trace := by
  rw [replayAux?_iff]
  constructor
  · rintro ⟨rfl, rfl⟩
    exact derivation cutoff depth xs
  · intro h
    exact ⟨h.execution.2, h.execution.1⟩

structure Certificate (xs : List α) where
  output : List α
  trace : Trace
  accepted : replayChecked? trace xs = some output

theorem Derivation.correct {cutoff depth : Nat} {xs output : List α} {trace : Trace}
    (h : Derivation cutoff depth xs output trace) : IsSortingResult (· ≤ ·) xs output := by
  rw [h.execution.1]
  exact introSortAux_spec _ _ _

theorem Derivation.deterministic {cutoff depth : Nat} {xs output₁ output₂ : List α}
    {trace₁ trace₂ : Trace} (h₁ : Derivation cutoff depth xs output₁ trace₁)
    (h₂ : Derivation cutoff depth xs output₂ trace₂) :
    output₁ = output₂ ∧ trace₁ = trace₂ :=
  ⟨h₁.execution.1.trans h₂.execution.1.symm, h₁.execution.2.trans h₂.execution.2.symm⟩

theorem replayChecked?_derivation_iff (trace : Trace) (xs output : List α) :
    replayChecked? trace xs = some output ↔
      Derivation insertionCutoff (depthLimit xs.length) xs output trace :=
  replayAux?_derivation_iff _ _ _ _ _

theorem Certificate.output_eq {xs : List α} (c : Certificate xs) :
    c.output = introSortResult xs := (replayChecked?_iff _ _ _).mp c.accepted |>.2

theorem Certificate.trace_eq {xs : List α} (c : Certificate xs) :
    c.trace = introSortTrace xs := (replayChecked?_iff _ _ _).mp c.accepted |>.1

theorem Certificate.derivation {xs : List α} (c : Certificate xs) :
    Derivation insertionCutoff (depthLimit xs.length) xs c.output c.trace :=
  (replayChecked?_derivation_iff _ _ _).mp c.accepted

theorem Certificate.correct {xs : List α} (c : Certificate xs) :
    IsSortingResult (· ≤ ·) xs c.output := replayChecked?_spec _ _ _ c.accepted

def introSortCertificate (xs : List α) : Certificate xs :=
  ⟨introSortResult xs, introSortTrace xs, replay_introSortTrace xs⟩

end LeanSort.Intro
