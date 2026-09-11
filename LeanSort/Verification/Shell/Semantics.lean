import LeanSort.Verification.Shell.Cost

/-! Local inversion rules, pass contracts, and structured schedule verification.
Arbitrary gap schedules describe legal executions but need not sort globally. -/

namespace LeanSort.Shell

/-- A gapped insertion swaps only a strict inversion, or stops when the next
comparison is unavailable or ordered. The rules do not invoke the sorter. -/
inductive InsertDerivation {α : Type*} [LinearOrder α] (gap : ℕ) :
    Array α → ℕ → Array α → List Gen → Prop where
  | blocked (xs i) (h : ¬ (0 < gap ∧ gap ≤ i ∧ i < xs.size)) :
      InsertDerivation gap xs i xs []
  | ordered (xs i) (h : 0 < gap ∧ gap ≤ i ∧ i < xs.size)
      (hs : ¬ xs[i] < xs[i - gap]) : InsertDerivation gap xs i xs []
  | swap (xs i) (h : 0 < gap ∧ gap ≤ i ∧ i < xs.size)
      (hs : xs[i] < xs[i - gap]) {output trace} :
      InsertDerivation gap (xs.swap i (i - gap)) (i - gap) output trace →
      InsertDerivation gap xs i output ((i, i - gap) :: trace)

theorem InsertDerivation.execution {α : Type*} [LinearOrder α]
    {gap i : ℕ} {xs output : Array α} {trace : List Gen}
    (h : InsertDerivation gap xs i output trace) : gapInsertTrace gap xs i = (output, trace) := by
  induction h with
  | blocked xs i h => rw [gapInsertTrace]; simp [h]
  | ordered xs i h hs => rw [gapInsertTrace]; simp [h, hs]
  | swap xs i h hs _ ih => rw [gapInsertTrace]; simp [h, hs, ih]

theorem gapInsertTrace_derivation {α : Type*} [LinearOrder α]
    (gap : ℕ) (xs : Array α) (i : ℕ) :
    InsertDerivation gap xs i (gapInsertTrace gap xs i).1 (gapInsertTrace gap xs i).2 := by
  fun_induction gapInsertTrace with
  | case1 xs i h hs output trace he ih =>
      apply InsertDerivation.swap xs i h hs
      simpa only [he] using ih
  | case2 xs i h hs => exact .ordered xs i h hs
  | case3 xs i h => exact .blocked xs i h

theorem insertDerivation_iff {α : Type*} [LinearOrder α]
    (gap : ℕ) (xs : Array α) (i : ℕ) (output : Array α) (trace : List Gen) :
    InsertDerivation gap xs i output trace ↔ gapInsertTrace gap xs i = (output, trace) := by
  refine ⟨InsertDerivation.execution, ?_⟩
  intro h
  simpa only [h] using gapInsertTrace_derivation gap xs i

theorem InsertDerivation.sorted {α : Type*} [LinearOrder α]
    {gap i stop : ℕ} {xs output : Array α} {trace : List Gen}
    (h : InsertDerivation gap xs i output trace) (hg : 0 < gap)
    (hi : i < stop) (hs : stop ≤ xs.size) (hc : GapSortedExcept gap stop i xs) :
    GapSorted gap stop output := by
  have he := gapInsertTrace_result gap xs i
  rw [h.execution] at he
  change output = gapInsert gap xs i at he
  rw [he]
  exact gapInsert_sorted gap xs i stop hg hi hs hc

/-- An insertion schedule composes the local rules in the supplied index order. -/
inductive InsertionsDerivation {α : Type*} [LinearOrder α] (gap : ℕ) :
    List ℕ → Array α → Array α → List Gen → Prop where
  | nil (xs) : InsertionsDerivation gap [] xs xs []
  | cons {i indices xs next output word rest} : InsertDerivation gap xs i next word →
      InsertionsDerivation gap indices next output rest →
      InsertionsDerivation gap (i :: indices) xs output (word ++ rest)

theorem InsertionsDerivation.execution {α : Type*} [LinearOrder α]
    {gap : ℕ} {indices : List ℕ} {xs output : Array α} {trace : List Gen}
    (h : InsertionsDerivation gap indices xs output trace) :
    insertionsTrace gap indices xs = (output, trace) := by
  induction h with
  | nil => rfl
  | cons hi _ ih => simp only [insertionsTrace, hi.execution, ih]

theorem insertionsTrace_derivation {α : Type*} [LinearOrder α]
    (gap : ℕ) (indices : List ℕ) (xs : Array α) :
    InsertionsDerivation gap indices xs (insertionsTrace gap indices xs).1
      (insertionsTrace gap indices xs).2 := by
  induction indices generalizing xs with
  | nil => exact .nil xs
  | cons i indices ih => exact .cons (gapInsertTrace_derivation gap xs i) (ih _)

theorem insertionsDerivation_iff {α : Type*} [LinearOrder α]
    (gap : ℕ) (indices : List ℕ) (xs output : Array α) (trace : List Gen) :
    InsertionsDerivation gap indices xs output trace ↔ insertionsTrace gap indices xs = (output, trace) := by
  refine ⟨InsertionsDerivation.execution, ?_⟩
  intro h
  simpa only [h] using insertionsTrace_derivation gap indices xs

theorem insertionsTrace_moves {α : Type*} [LinearOrder α]
    (gap : ℕ) (indices : List ℕ) (xs : Array α) :
    ∀ move ∈ (insertionsTrace gap indices xs).2,
      move.1 < xs.size ∧ move.2 + gap = move.1 ∧ 0 < gap := by
  induction indices generalizing xs with
  | nil => simp [insertionsTrace]
  | cons i indices ih =>
      intro move hm
      simp only [insertionsTrace, List.mem_append] at hm
      rcases hm with hm | hm
      · exact gapInsertTrace_moves gap xs i move hm
      · simpa only [gapInsertTrace_result, gapInsert_size] using ih _ move hm

/-- A full positive-gap pass orders its columns and records bounded swaps one
gap apart. This contract makes no claim that different columns are ordered. -/
structure GapPassSpec {α : Type*} [LinearOrder α]
    (gap : ℕ) (input output : Array α) (trace : List Gen) : Prop where
  perm : output.Perm input
  size_eq : output.size = input.size
  columns : 0 < gap → GapSorted gap input.size output
  replay_eq : replayArray trace input = output
  moves : ∀ move ∈ trace, move.1 < input.size ∧ move.2 + gap = move.1 ∧ 0 < gap
  cost : trace.length ≤ input.size * (input.size / gap)

theorem gapPassTrace_spec {α : Type*} [LinearOrder α] (gap : ℕ) (xs : Array α) :
    GapPassSpec gap xs (gapPassTrace gap xs).1 (gapPassTrace gap xs).2 := by
  refine ⟨?_, ?_, ?_, replay_gapPassTrace gap xs, insertionsTrace_moves gap _ xs,
    gapPassTrace_cost gap xs⟩
  · rw [gapPassTrace_result]; exact gapPass_perm gap xs
  · rw [gapPassTrace_result]; exact gapPass_size gap xs
  · intro hg; rw [gapPassTrace_result]; exact gapPass_sorted gap xs hg

/-- Structured trace erasure recovers the original flat execution exactly. -/
theorem structuredPasses_flatten {α : Type*} [LinearOrder α] (steps : List ℕ) (xs : Array α) :
    ((structuredPasses steps xs).1, flattenSteps (structuredPasses steps xs).2) = passesTrace steps xs := by
  induction steps generalizing xs with
  | nil => rfl
  | cons gap steps ih =>
      simp only [structuredPasses, passesTrace, flattenSteps, List.flatMap_cons]
      have h := ih (gapPassTrace gap xs).1
      have hf := congrArg Prod.fst h
      have ht := congrArg Prod.snd h
      apply Prod.ext
      · exact hf
      · exact congrArg ((gapPassTrace gap xs).2 ++ ·) ht

theorem structuredPasses_schedule {α : Type*} [LinearOrder α] (steps : List ℕ) (xs : Array α) :
    (structuredPasses steps xs).2.map PassStep.gap = steps := by
  induction steps generalizing xs with
  | nil => rfl
  | cons gap steps ih => simp [structuredPasses, ih]

theorem shellPassTrace_flatten {α : Type*} [LinearOrder α] (xs : List α) :
    flattenSteps (shellPassTrace xs) = shellSortTrace xs :=
  congrArg Prod.snd (structuredPasses_flatten _ _)

/-- A schedule composes insertion rules, retaining every pass boundary. -/
inductive ScheduleDerivation {α : Type*} [LinearOrder α] :
    List ℕ → Array α → Array α → List PassStep → Prop where
  | nil (xs) : ScheduleDerivation [] xs xs []
  | cons {gap gaps xs next output word rest} :
      InsertionsDerivation gap (List.range xs.size) xs next word →
      ScheduleDerivation gaps next output rest →
      ScheduleDerivation (gap :: gaps) xs output (⟨gap, word⟩ :: rest)

theorem ScheduleDerivation.execution {α : Type*} [LinearOrder α]
    {steps : List ℕ} {xs output : Array α} {trace : List PassStep}
    (h : ScheduleDerivation steps xs output trace) : structuredPasses steps xs = (output, trace) := by
  induction h with
  | nil => rfl
  | cons hp _ ih => simp only [structuredPasses, gapPassTrace, hp.execution, ih]

theorem structuredPasses_derivation {α : Type*} [LinearOrder α]
    (steps : List ℕ) (xs : Array α) :
    ScheduleDerivation steps xs (structuredPasses steps xs).1 (structuredPasses steps xs).2 := by
  induction steps generalizing xs with
  | nil => exact .nil xs
  | cons gap steps ih => exact .cons (insertionsTrace_derivation gap _ xs) (ih _)

theorem scheduleDerivation_iff {α : Type*} [LinearOrder α]
    (steps : List ℕ) (xs output : Array α) (trace : List PassStep) :
    ScheduleDerivation steps xs output trace ↔ structuredPasses steps xs = (output, trace) := by
  refine ⟨ScheduleDerivation.execution, ?_⟩
  intro h
  simpa only [h] using structuredPasses_derivation steps xs

theorem checkPass?_iff {α : Type*} [LinearOrder α]
    (gap : ℕ) (xs output : Array α) (step : PassStep) :
    checkPass? gap xs step = some output ↔
      output = (gapPassTrace gap xs).1 ∧ step = ⟨gap, (gapPassTrace gap xs).2⟩ := by
  unfold checkPass?
  split
  · rename_i h
    rw [h.2, replay_gapPassTrace]
    cases step
    simp_all [eq_comm]
  · rename_i h
    constructor
    · intro he; cases he
    · rintro ⟨_, rfl⟩
      exact False.elim (h ⟨rfl, rfl⟩)

theorem replaySchedule?_iff {α : Type*} [LinearOrder α]
    (steps : List ℕ) (xs output : Array α) (trace : List PassStep) :
    replaySchedule? steps xs trace = some output ↔ structuredPasses steps xs = (output, trace) := by
  induction steps generalizing xs output trace with
  | nil => cases trace <;> simp [replaySchedule?, structuredPasses, eq_comm]
  | cons gap steps ih =>
      cases trace with
      | nil => simp [replaySchedule?, structuredPasses]
      | cons step rest =>
          simp only [replaySchedule?, Option.bind_eq_some_iff]
          constructor
          · rintro ⟨next, hn, hr⟩
            obtain ⟨rfl, rfl⟩ := (checkPass?_iff gap xs next step).mp hn
            have ht := (ih _ output rest).mp hr
            simp [structuredPasses, ht]
          · intro h
            have ho := congrArg Prod.fst h
            have ht := congrArg Prod.snd h
            simp only [structuredPasses, List.cons.injEq] at ht
            refine ⟨(gapPassTrace gap xs).1, (checkPass?_iff _ _ _ _).mpr ⟨rfl, ht.1.symm⟩, ?_⟩
            apply (ih _ _ _).mpr
            exact Prod.ext ho ht.2

theorem replaySchedule?_derivation {α : Type*} [LinearOrder α]
    (steps : List ℕ) (xs output : Array α) (trace : List PassStep) :
    replaySchedule? steps xs trace = some output ↔ ScheduleDerivation steps xs output trace :=
  (replaySchedule?_iff steps xs output trace).trans (scheduleDerivation_iff steps xs output trace).symm

/-- A certificate retains the complete array execution, including empty passes. -/
structure Certificate {α : Type*} [LinearOrder α] (input : List α) where
  result : Array α
  trace : List PassStep
  execution : structuredPasses (gaps (input.length / 2)) input.toArray = (result, trace)

def certify {α : Type*} [LinearOrder α] (input : List α) : Certificate input :=
  ⟨_, _, rfl⟩

theorem Certificate.result_eq {α : Type*} [LinearOrder α] {input : List α}
    (c : Certificate input) : c.result.toList = shellSortResult input := by
  have h := congrArg Prod.fst (structuredPasses_flatten (gaps (input.length / 2)) input.toArray)
  rw [c.execution] at h
  exact congrArg Array.toList h

theorem Certificate.spec {α : Type*} [LinearOrder α] {input : List α}
    (c : Certificate input) : LeanSort.IsSortingResult (· ≤ ·) input c.result.toList := by
  rw [c.result_eq]
  exact shellSortResult_spec input

theorem Certificate.schedule {α : Type*} [LinearOrder α] {input : List α}
    (c : Certificate input) : c.trace.map PassStep.gap = gaps (input.length / 2) := by
  have h := structuredPasses_schedule (gaps (input.length / 2)) input.toArray
  simpa only [c.execution] using h

theorem Certificate.replay {α : Type*} [LinearOrder α] {input : List α}
    (c : Certificate input) : replayShell? input c.trace = some c.result.toList := by
  unfold replayShell?
  rw [(replaySchedule?_iff _ _ _ _).mpr c.execution]
  rfl

theorem Certificate.cost {α : Type*} [LinearOrder α] {input : List α}
    (c : Certificate input) : (flattenSteps c.trace).length ≤ 2 * input.length ^ 2 := by
  have h := congrArg Prod.snd c.execution
  change shellPassTrace input = c.trace at h
  rw [← h, shellPassTrace_flatten]
  exact shellSwapCost_le_two_mul_sq input

theorem replayShell?_sound {α : Type*} [LinearOrder α]
    (input output : List α) (trace : List PassStep)
    (h : replayShell? input trace = some output) :
    LeanSort.IsSortingResult (· ≤ ·) input output := by
  unfold replayShell? at h
  cases he : replaySchedule? (gaps (input.length / 2)) input.toArray trace with
  | none => simp [he] at h
  | some result =>
      let hc : Certificate input := ⟨result, trace, (replaySchedule?_iff _ _ _ _).mp he⟩
      have ho : result.toList = output := by simpa [he] using h
      rw [← ho]
      exact hc.spec

end LeanSort.Shell
