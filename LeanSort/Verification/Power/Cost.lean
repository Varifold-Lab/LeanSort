import LeanSort.Verification.Power.Trace

/-! Exact scheduler-operation counts. A merge event counts a whole merge,
not its comparisons or runtime. -/

namespace LeanSort.Power

variable {α : Type*}

def Event.mergeCount : Event → Nat
  | .merge .. => 1
  | .boundary .. => 0

def mergeCount (events : List Event) : Nat := (events.map Event.mergeCount).sum

@[simp] theorem mergeCount_nil : mergeCount [] = 0 := rfl
@[simp] theorem mergeCount_cons (event : Event) (events : List Event) :
    mergeCount (event :: events) = event.mergeCount + mergeCount events := rfl
@[simp] theorem mergeCount_append (a b : List Event) :
    mergeCount (a ++ b) = mergeCount a + mergeCount b := by simp [mergeCount]

theorem collapseTr_mergeCount (le : α → α → Bool) (power : Nat)
    (stack : List (Pending α)) (current : List α) :
    mergeCount (collapseTr le power stack current).2 +
      (collapseTr le power stack current).1.2.length = stack.length := by
  induction stack generalizing current with
  | nil => rfl
  | cons top rest ih =>
    simp only [collapseTr]
    split
    · simpa [Event.mergeCount, Nat.add_assoc, Nat.add_comm, Nat.add_left_comm] using
        ih (top.values.merge current le)
    · simp

theorem finishStackTr_mergeCount (le : α → α → Bool)
    (stack : List (Pending α)) (current : List α) :
    mergeCount (finishStackTr le stack current).2 = stack.length := by
  induction stack generalizing current with
  | nil => rfl
  | cons top rest ih => simp [finishStackTr, Event.mergeCount, ih, Nat.add_comm]

theorem mergeRunsTr_mergeCount (le : α → α → Bool) (n : Nat)
    (runs : List (List α)) (start : Nat) (current : List α) (stack : List (Pending α)) :
    mergeCount (mergeRunsTr le n runs start current stack).2 = runs.length + stack.length := by
  induction runs generalizing start current stack with
  | nil => simpa [mergeRunsTr] using finishStackTr_mergeCount le stack current
  | cons next rest ih =>
    have h := collapseTr_mergeCount le (nodePower n start current.length next.length) stack current
    simp only [mergeRunsTr, mergeCount_cons, Event.mergeCount, Nat.zero_add,
      mergeCount_append, ih, List.length_cons]
    omega

theorem powerSortTrace_mergeCount (le : α → α → Bool) (xs : List α) :
    mergeCount (powerSortTrace le xs).events = (naturalRuns le xs).length - 1 := by
  unfold powerSortTrace powerSortTr
  cases naturalRuns le xs <;> simp [mergeRunsTr_mergeCount]

theorem mergeRunsTr_eventCount (le : α → α → Bool) (n : Nat)
    (runs : List (List α)) (start : Nat) (current : List α) (stack : List (Pending α)) :
    (mergeRunsTr le n runs start current stack).2.length = 2 * runs.length + stack.length := by
  have hc : ∀ (stack : List (Pending α)) current power,
      (collapseTr le power stack current).2.length +
        (collapseTr le power stack current).1.2.length = stack.length := by
    intro stack
    induction stack with
    | nil => intros; rfl
    | cons top rest ih =>
      intro current power
      simp only [collapseTr]
      split
      · simp only [List.length_cons]
        have := ih (top.values.merge current le) power
        omega
      · simp
  have hf : ∀ (stack : List (Pending α)) current,
      (finishStackTr le stack current).2.length = stack.length := by
    intro stack
    induction stack with
    | nil => intros; rfl
    | cons top rest ih => intro current; simp [finishStackTr, ih]
  induction runs generalizing start current stack with
  | nil => simpa [mergeRunsTr] using hf stack current
  | cons next rest ih =>
    have h := hc stack current (nodePower n start current.length next.length)
    simp only [mergeRunsTr, List.length_cons, List.length_append, ih]
    omega

theorem powerSortTrace_eventCount (le : α → α → Bool) (xs : List α) :
    (powerSortTrace le xs).events.length = 2 * ((naturalRuns le xs).length - 1) := by
  unfold powerSortTrace powerSortTr
  cases naturalRuns le xs <;> simp [mergeRunsTr_eventCount]

theorem scanRuns_nonempty (le : α → α → Bool) (xs current : List α)
    (direction : Option Bool) (done : List (List α)) (hd : ∀ run ∈ done, run ≠ []) :
    ∀ run ∈ scanRuns le xs current direction done, run ≠ [] := by
  induction xs generalizing current direction done with
  | nil =>
    intro run hr
    simp only [scanRuns, List.mem_reverse] at hr
    split at hr
    · exact hd _ hr
    · rcases List.mem_cons.mp hr with rfl | hr
      · have h := (finishRun_perm current direction).length_eq
        rename_i hc
        intro he
        simp [he] at h
        exact hc (by simp [List.length_eq_zero_iff.mp h.symm])
      · exact hd _ hr
  | cons x xs ih =>
    cases current with
    | nil => exact ih _ _ _ hd
    | cons p rest =>
      cases direction with
      | none => exact ih _ _ _ hd
      | some d =>
        simp only [scanRuns]
        by_cases h : (if d then le p x else !(le p x)) = true
        · rw [ite_eq_left h]; exact ih _ _ _ hd
        · rw [ite_eq_right h]
          apply ih
          intro run hr
          rcases List.mem_cons.mp hr with rfl | hr
          · have hp := (finishRun_perm (p :: rest) (some d)).length_eq
            intro he
            simp [he] at hp
          · exact hd _ hr

theorem naturalRuns_nonempty (le : α → α → Bool) (xs : List α) :
    ∀ run ∈ naturalRuns le xs, run ≠ [] := scanRuns_nonempty le xs [] none [] (by simp)

theorem naturalRuns_length_le (le : α → α → Bool) (xs : List α) :
    (naturalRuns le xs).length ≤ xs.length := by
  have h : ∀ (runs : List (List α)), (∀ run ∈ runs, run ≠ []) → runs.length ≤ runs.flatten.length := by
    intro runs
    induction runs with
    | nil => simp
    | cons run rest ih =>
      intro hr
      have hp := hr run (by simp)
      have ht := ih (fun r h => hr r (by simp [h]))
      have hn : 0 < run.length := List.length_pos_iff.mpr hp
      simp only [List.length_cons, List.flatten_cons, List.length_append]
      omega
  have hp := (naturalRuns_perm le xs).length_eq
  exact hp ▸ h _ (naturalRuns_nonempty le xs)

theorem powerSortTrace_mergeCount_le (le : α → α → Bool) (xs : List α) :
    mergeCount (powerSortTrace le xs).events ≤ xs.length - 1 := by
  rw [powerSortTrace_mergeCount]
  exact Nat.sub_le_sub_right (naturalRuns_length_le le xs) 1

theorem powerSortTrace_eventCount_le (le : α → α → Bool) (xs : List α) :
    (powerSortTrace le xs).events.length ≤ 2 * (xs.length - 1) := by
  rw [powerSortTrace_eventCount]
  exact Nat.mul_le_mul_left 2 (Nat.sub_le_sub_right (naturalRuns_length_le le xs) 1)

end LeanSort.Power
