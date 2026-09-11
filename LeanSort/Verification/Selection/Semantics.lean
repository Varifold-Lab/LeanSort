import LeanSort.Verification.Selection.Trace

/-! Selection derivations describe legal minimum choices and their recursive
effects. Strict replay validates this algorithmic semantics, whereas ordinary
checked replay only validates index bounds and the resulting rearrangement. -/

namespace LeanSort.Selection

/-- A derivation accounts for every nonempty round, including a minimum already
at the head. The rules invoke the minimum contract and primitive swap, not the sorter. -/
inductive SelectionDerivation {α : Type*} [LinearOrder α] :
    ℕ → ℕ → List α → List α → List Gen → Prop where
  | stop (off xs) : SelectionDerivation 0 off xs xs []
  | empty (fuel off) : SelectionDerivation (fuel + 1) off [] [] []
  | select {fuel off x xs i m output trace} : MinimumSpec (x :: xs) i m →
      SelectionDerivation fuel (off + 1) (swapHeadAt i x xs).2 output trace →
      SelectionDerivation (fuel + 1) off (x :: xs) ((swapHeadAt i x xs).1 :: output)
        ((if i = 0 then [] else [(off, off + i)]) ++ trace)

theorem SelectionDerivation.execution {α : Type*} [LinearOrder α]
    {fuel off : ℕ} {xs output : List α} {trace : List Gen}
    (h : SelectionDerivation fuel off xs output trace) : sortAuxTr fuel off xs = (output, trace) := by
  induction h with
  | stop => rfl
  | empty => rfl
  | @select fuel off x xs i m output trace hm _ ih =>
      have ha := (argmin?_iff_minimumSpec _ _ _).mpr hm
      have hi : minIdx (x :: xs) = i := by simp [minIdx, ha]
      simp only [sortAuxTr, round, hi, ih]

theorem sortAuxTr_derivation {α : Type*} [LinearOrder α] (fuel off : ℕ) (xs : List α) :
    SelectionDerivation fuel off xs (sortAuxTr fuel off xs).1 (sortAuxTr fuel off xs).2 := by
  induction fuel generalizing off xs with
  | zero => exact .stop off xs
  | succ fuel ih =>
      cases xs with
      | nil => exact .empty fuel off
      | cons x xs =>
          cases ha : argmin? (x :: xs) with
          | none => have := (argmin?_eq_none _).mp ha; simp at this
          | some pair =>
              obtain ⟨i, m⟩ := pair
              have hi : minIdx (x :: xs) = i := by simp [minIdx, ha]
              simpa only [sortAuxTr, round, hi] using
                SelectionDerivation.select (argmin?_minimumSpec _ _ _ ha)
                  (ih (off + 1) (swapHeadAt i x xs).2)

theorem selectionDerivation_iff {α : Type*} [LinearOrder α]
    (fuel off : ℕ) (xs output : List α) (trace : List Gen) :
    SelectionDerivation fuel off xs output trace ↔ sortAuxTr fuel off xs = (output, trace) := by
  refine ⟨SelectionDerivation.execution, ?_⟩
  intro h
  simpa only [h] using sortAuxTr_derivation fuel off xs

theorem SelectionDerivation.deterministic {α : Type*} [LinearOrder α]
    {fuel off : ℕ} {xs ys zs : List α} {t u : List Gen}
    (h : SelectionDerivation fuel off xs ys t) (k : SelectionDerivation fuel off xs zs u) :
    ys = zs ∧ t = u := Prod.mk.inj (h.execution.symm.trans k.execution)

/-- A successful plan consumption is exactly an append decomposition. -/
theorem consumePlan?_iff (plan trace rest : List Gen) :
    consumePlan? plan trace = some rest ↔ trace = plan ++ rest := by
  induction plan generalizing trace with
  | nil => simp [consumePlan?]
  | cons move plan ih =>
      cases trace with
      | nil => simp [consumePlan?]
      | cons actual trace =>
          by_cases h : move = actual
          · subst actual
            simp [consumePlan?, ih]
          · simp [consumePlan?, h, Ne.symm h]

/-- Strict checking accepts exactly the output and trace of the specified run. -/
theorem replaySelectionAux?_iff {α : Type*} [LinearOrder α]
    (fuel off : ℕ) (xs output : List α) (trace : List Gen) :
    replaySelectionAux? fuel off xs trace = some output ↔
      sortAuxTr fuel off xs = (output, trace) := by
  induction fuel generalizing off xs output trace with
  | zero =>
      cases trace <;> simp [replaySelectionAux?, eq_comm]
  | succ fuel ih =>
      cases xs with
      | nil => cases trace <;> simp [replaySelectionAux?, eq_comm]
      | cons x xs =>
          let step := round off x xs
          constructor
          · intro h
            change (consumePlan? step.2 trace).bind (fun rest =>
              (replaySelectionAux? fuel (off + 1) step.1.2 rest).map (step.1.1 :: ·)) = some output at h
            cases hc : consumePlan? step.2 trace with
            | none => simp [hc] at h
            | some rest =>
                cases hr : replaySelectionAux? fuel (off + 1) step.1.2 rest with
                | none => simp [hc, hr] at h
                | some next =>
                    have he := (ih (off + 1) step.1.2 next rest).mp hr
                    have ht := (consumePlan?_iff step.2 trace rest).mp hc
                    simp only [hc, hr, Option.bind_some, Option.map_some, Option.some.injEq] at h
                    change (step.1.1 :: (sortAuxTr fuel (off + 1) step.1.2).1,
                      step.2 ++ (sortAuxTr fuel (off + 1) step.1.2).2) = (output, trace)
                    rw [he]
                    exact Prod.ext h ht.symm
          · intro h
            let run := sortAuxTr fuel (off + 1) step.1.2
            have ho : step.1.1 :: run.1 = output := congrArg Prod.fst h
            have ht : step.2 ++ run.2 = trace := congrArg Prod.snd h
            have hc := (consumePlan?_iff step.2 trace run.2).mpr ht.symm
            have hr := (ih (off + 1) step.1.2 run.1 run.2).mpr (by rfl)
            change (consumePlan? step.2 trace).bind (fun rest =>
              (replaySelectionAux? fuel (off + 1) step.1.2 rest).map (step.1.1 :: ·)) = some output
            simp only [hc, hr, Option.bind_some, Option.map_some, ho]

theorem replaySelectionAux?_iff_derivation {α : Type*} [LinearOrder α]
    (fuel off : ℕ) (xs output : List α) (trace : List Gen) :
    replaySelectionAux? fuel off xs trace = some output ↔
      SelectionDerivation fuel off xs output trace :=
  (replaySelectionAux?_iff _ _ _ _ _).trans (selectionDerivation_iff _ _ _ _ _).symm

theorem replaySelection?_iff {α : Type*} [LinearOrder α]
    (xs output : List α) (trace : List Gen) :
    replaySelection? xs trace = some output ↔ sortTrace xs = (output, trace) :=
  replaySelectionAux?_iff _ _ _ _ _

theorem replaySelection?_sound {α : Type*} [LinearOrder α]
    (xs output : List α) (trace : List Gen)
    (h : replaySelection? xs trace = some output) : IsSortingResult (· ≤ ·) xs output := by
  have he := (replaySelection?_iff _ _ _).mp h
  simpa only [selectionSortResult, he] using selectionSortResult_spec xs

theorem replaySelection?_iff_derivation {α : Type*} [LinearOrder α]
    (xs output : List α) (trace : List Gen) :
    replaySelection? xs trace = some output ↔
      SelectionDerivation xs.length 0 xs output trace :=
  replaySelectionAux?_iff_derivation _ _ _ _ _

theorem SelectionDerivation.perm {α : Type*} [LinearOrder α]
    {fuel off : ℕ} {xs output : List α} {trace : List Gen}
    (h : SelectionDerivation fuel off xs output trace) : output.Perm xs := by
  simpa only [h.execution] using sortAuxTr_fst_perm fuel off xs

theorem SelectionDerivation.replay {α : Type*} [LinearOrder α]
    {fuel off : ℕ} {xs output : List α} {trace : List Gen}
    (h : SelectionDerivation fuel off xs output trace) (p : List α) (hp : p.length = off) :
    replay trace (p ++ xs) = p ++ output := by
  simpa only [h.execution] using replay_sortAuxTr fuel off p xs hp

theorem SelectionDerivation.complete {α : Type*} [LinearOrder α]
    {fuel off : ℕ} {xs output : List α} {trace : List Gen}
    (h : SelectionDerivation fuel off xs output trace) (hf : xs.length ≤ fuel) :
    IsSortingResult (· ≤ ·) xs output := by
  refine ⟨?_, h.perm⟩
  simpa only [h.execution] using sorted_sortAuxTr_of_length_le fuel off xs hf

theorem SelectionDerivation.settled {α : Type*} [LinearOrder α]
    {fuel off : ℕ} {xs output : List α} {trace : List Gen}
    (h : SelectionDerivation fuel off xs output trace) : SettledPrefix fuel output := by
  simpa only [h.execution] using sortAuxTr_settled fuel off xs

theorem SelectionDerivation.cost {α : Type*} [LinearOrder α]
    {fuel off : ℕ} {xs output : List α} {trace : List Gen}
    (h : SelectionDerivation fuel off xs output trace) : trace.length ≤ min fuel (xs.length - 1) := by
  simpa only [h.execution] using length_sortAuxTr_snd_le_min fuel off xs

theorem Certificate.derivation {α : Type*} [LinearOrder α] {xs : List α} (c : Certificate xs) :
    SelectionDerivation xs.length 0 xs c.output c.trace :=
  (selectionDerivation_iff _ _ _ _ _).mpr c.execution

theorem Certificate.strictReplay {α : Type*} [LinearOrder α] {xs : List α} (c : Certificate xs) :
    replaySelection? xs c.trace = some c.output := (replaySelection?_iff _ _ _).mpr c.execution

theorem PartialCertificate.derivation {α : Type*} [LinearOrder α]
    {fuel : ℕ} {p xs : List α} (c : PartialCertificate fuel p xs) :
    SelectionDerivation fuel p.length xs c.output c.trace :=
  (selectionDerivation_iff _ _ _ _ _).mpr c.execution

theorem PartialCertificate.strictReplay {α : Type*} [LinearOrder α]
    {fuel : ℕ} {p xs : List α} (c : PartialCertificate fuel p xs) :
    replaySelectionAux? fuel p.length xs c.trace = some c.output :=
  (replaySelectionAux?_iff _ _ _ _ _).mpr c.execution

end LeanSort.Selection
