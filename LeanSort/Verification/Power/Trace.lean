import LeanSort.Verification.Power.Correctness

/-! Scheduling logs from an instrumented execution of the original scheduler.
Merge events record operand lengths; boundary events use original run lengths.
Replay recomputes runs and merges. Internal key comparisons are not logged. -/

namespace LeanSort.Power

inductive Event where
  | boundary (start leftLength rightLength power : Nat)
  | merge (leftLength rightLength : Nat)
  deriving DecidableEq, Repr

structure Trace where
  runLengths : List Nat
  events : List Event
  deriving DecidableEq, Repr

variable {α : Type*}

def collapseTr (le : α → α → Bool) (power : Nat) :
    List (Pending α) → List α → (List α × List (Pending α)) × List Event
  | [], current => ((current, []), [])
  | top :: rest, current =>
    if top.power > power then
      let result := collapseTr le power rest (top.values.merge current le)
      (result.1, .merge top.values.length current.length :: result.2)
    else ((current, top :: rest), [])

def finishStackTr (le : α → α → Bool) : List (Pending α) → List α → List α × List Event
  | [], current => (current, [])
  | top :: rest, current =>
    let result := finishStackTr le rest (top.values.merge current le)
    (result.1, .merge top.values.length current.length :: result.2)

def mergeRunsTr (le : α → α → Bool) (n : Nat) :
    List (List α) → Nat → List α → List (Pending α) → List α × List Event
  | [], _, current, stack => finishStackTr le stack current
  | next :: rest, start, current, stack =>
    let power := nodePower n start current.length next.length
    let collapsed := collapseTr le power stack current
    let result := mergeRunsTr le n rest (start + current.length) next
      (⟨collapsed.1.1, power⟩ :: collapsed.1.2)
    (result.1, .boundary start current.length next.length power :: collapsed.2 ++ result.2)

def powerSortTr (le : α → α → Bool) (xs : List α) : List α × Trace :=
  let runs := naturalRuns le xs
  let result := match runs with
    | [] => ([], [])
    | first :: rest => mergeRunsTr le xs.length rest 0 first []
  (result.1, ⟨runs.map List.length, result.2⟩)

@[simp] theorem collapseTr_result (le : α → α → Bool) (power : Nat)
    (stack : List (Pending α)) (current : List α) :
    (collapseTr le power stack current).1 = collapse le power stack current := by
  induction stack generalizing current with
  | nil => rfl
  | cons top rest ih => simp only [collapseTr, collapse]; split <;> simp_all

@[simp] theorem finishStackTr_result (le : α → α → Bool)
    (stack : List (Pending α)) (current : List α) :
    (finishStackTr le stack current).1 = finishStack le stack current := by
  induction stack generalizing current with
  | nil => rfl
  | cons top rest ih => exact ih _

@[simp] theorem mergeRunsTr_result (le : α → α → Bool) (n : Nat)
    (runs : List (List α)) (start : Nat) (current : List α) (stack : List (Pending α)) :
    (mergeRunsTr le n runs start current stack).1 = mergeRuns le n runs start current stack := by
  induction runs generalizing start current stack with
  | nil => exact finishStackTr_result _ _ _
  | cons next rest ih => simp [mergeRunsTr, mergeRuns, ih]

@[simp] theorem powerSortTr_result (le : α → α → Bool) (xs : List α) :
    (powerSortTr le xs).1 = powerSortBy le xs := by
  unfold powerSortTr powerSortBy
  cases naturalRuns le xs <;> simp

def powerSortTrace (le : α → α → Bool) (xs : List α) : Trace := (powerSortTr le xs).2

/-- Exact schedule checking by re-execution, including run sizes, original
boundary powers, and all collapse/drain merges. -/
def replayChecked? (le : α → α → Bool) (xs : List α) (trace : Trace) : Option (List α) :=
  let result := powerSortTr le xs
  if trace = result.2 then some result.1 else none

theorem replayChecked?_iff (le : α → α → Bool) (xs output : List α) (trace : Trace) :
    replayChecked? le xs trace = some output ↔
      trace = powerSortTrace le xs ∧ output = powerSortBy le xs := by
  unfold replayChecked? powerSortTrace
  dsimp only
  split <;> simp_all [eq_comm]

@[simp] theorem replay_powerSortTrace (le : α → α → Bool) (xs : List α) :
    replayChecked? le xs (powerSortTrace le xs) = some (powerSortBy le xs) :=
  (replayChecked?_iff _ _ _ _).mpr ⟨rfl, rfl⟩

theorem replayChecked?_spec (le : α → α → Bool)
    (htrans : ∀ a b c, le a b = true → le b c = true → le a c = true)
    (htotal : ∀ a b, le a b = true ∨ le b a = true)
    (xs output : List α) (trace : Trace) (h : replayChecked? le xs trace = some output) :
    IsSortingResult (fun a b => le a b = true) xs output := by
  obtain ⟨_, rfl⟩ := (replayChecked?_iff _ _ _ _).mp h
  exact powerSortBy_spec le htrans htotal xs

structure Certificate (le : α → α → Bool) (xs : List α) where
  output : List α
  trace : Trace
  accepted : replayChecked? le xs trace = some output

def powerSortCertificate (le : α → α → Bool) (xs : List α) : Certificate le xs :=
  ⟨powerSortBy le xs, powerSortTrace le xs, replay_powerSortTrace le xs⟩

theorem Certificate.correct (le : α → α → Bool)
    (htrans : ∀ a b c, le a b = true → le b c = true → le a c = true)
    (htotal : ∀ a b, le a b = true ∨ le b a = true)
    (xs : List α) (c : Certificate le xs) :
    IsSortingResult (fun a b => le a b = true) xs c.output :=
  replayChecked?_spec le htrans htotal xs c.output c.trace c.accepted

end LeanSort.Power
