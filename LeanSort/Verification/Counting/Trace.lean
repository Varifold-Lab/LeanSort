import LeanSort.Verification.Counting.Correctness

/-!
Histogram-update trace semantics. Replay consumes exactly the input's keys,
checks every new counter value, and rejects missing, extra, or invalid updates.
These events are counter updates, not rearrangements of input positions.
-/

namespace LeanSort.Counting

@[simp] theorem histogramTraceAux_result (xs : List ℕ) (counts : Array ℕ) :
    (histogramTraceAux xs counts).1 =
      xs.foldl (fun counts x => counts.modify x (· + 1)) counts := by
  induction xs generalizing counts <;> simp [histogramTraceAux_cons, *]

/-- The event keys reproduce the input in order, including duplicates. -/
theorem histogramTraceAux_keys (xs : List ℕ) (counts : Array ℕ) :
    (histogramTraceAux xs counts).2.map CountStep.key = xs := by
  induction xs generalizing counts <;> simp [histogramTraceAux_cons, *]

theorem histogramTraceAux_length (xs : List ℕ) (counts : Array ℕ) :
    (histogramTraceAux xs counts).2.length = xs.length := by
  simpa using congrArg List.length (histogramTraceAux_keys xs counts)

theorem countingSortTrace_keys (xs : List ℕ) :
    (countingSortTrace xs).map CountStep.key = xs :=
  histogramTraceAux_keys xs (Array.replicate (keyRange xs) 0)

@[simp] theorem sortTrace_result (xs : List ℕ) :
    (sortTrace xs).1 = countingSortResult xs := by
  simp [sortTrace, countingSortResult, histogram]

theorem countingSortTrace_length (xs : List ℕ) :
    (countingSortTrace xs).length = xs.length := by
  simp [countingSortTrace, sortTrace, histogramTraceAux_length]

/-- Validate the update log against the input and reconstruct the final histogram. -/
def replayHistogram? : List ℕ → List CountStep → Array ℕ → Option (Array ℕ)
  | [], [], counts => some counts
  | x :: xs, step :: steps, counts =>
      if step.key = x ∧ x < counts.size ∧ step.value = counts[x]?.getD 0 + 1 then
        replayHistogram? xs steps (counts.modify x (· + 1))
      else none
  | _, _, _ => none

/-- Replay the histogram updates and expand the validated final histogram. -/
def replay? (xs : List ℕ) (trace : List CountStep) : Option (List ℕ) :=
  (replayHistogram? xs trace (Array.replicate (keyRange xs) 0)).map histogramOutput

/-- Bounds are certified by the type; input order and counter values are still validated. -/
def replayBounded? (xs : List ℕ) (trace : List (BoundedCountStep (keyRange xs))) :
    Option (List ℕ) := replay? xs (trace.map BoundedCountStep.erase)

theorem replayHistogram?_generated (xs : List ℕ) (counts : Array ℕ)
    (hxs : ∀ x ∈ xs, x < counts.size) :
    replayHistogram? xs (histogramTraceAux xs counts).2 counts =
      some (histogramTraceAux xs counts).1 := by
  induction xs generalizing counts with
  | nil => rfl
  | cons x xs ih =>
      have hx := hxs x (by simp)
      simpa [histogramTraceAux_cons, replayHistogram?, hx, Array.getElem_modify_self] using
        ih (counts.modify x (· + 1)) (fun y hy => by simpa using hxs y (by simp [hy]))

/-- Every generated trace is accepted and reconstructs the executable output. -/
theorem replay_countingSortTrace (xs : List ℕ) :
    replay? xs (countingSortTrace xs) = some (countingSortResult xs) := by
  simpa [replay?, countingSortTrace, sortTrace, countingSortResult, histogram] using
    congrArg (Option.map histogramOutput)
      (replayHistogram?_generated xs (Array.replicate (keyRange xs) 0)
        (fun x hx => by simpa using mem_lt_keyRange xs x hx))

theorem replayHistogram?_sound (xs : List ℕ) (steps : List CountStep)
    (counts result : Array ℕ) (h : replayHistogram? xs steps counts = some result) :
    result = xs.foldl (fun counts x => counts.modify x (· + 1)) counts := by
  induction xs generalizing steps counts with
  | nil =>
      cases steps <;> simp_all [replayHistogram?]
  | cons x xs ih =>
      cases steps with
      | nil => simp [replayHistogram?] at h
      | cons step steps =>
          exact ih steps _ (Option.ite_none_right_eq_some.mp h).2

/-- Soundness also holds for arbitrary traces supplied by a caller. -/
theorem replay?_sound (xs : List ℕ) (trace : List CountStep) (output : List ℕ)
    (h : replay? xs trace = some output) : output = countingSortResult xs := by
  obtain ⟨counts, hr, rfl⟩ := Option.map_eq_some_iff.mp h
  exact congrArg histogramOutput (replayHistogram?_sound xs trace _ counts hr)

theorem replay?_spec (xs : List ℕ) (trace : List CountStep) (output : List ℕ)
    (h : replay? xs trace = some output) : IsSortingResult (· ≤ ·) xs output := by
  rw [replay?_sound xs trace output h]
  exact countingSortResult_spec xs

/-- A run returns a sorted permutation, logs each input key in order, and replays exactly. -/
structure CountingRunSpec (input : List ℕ) (result : List ℕ × List CountStep) : Prop where
  sorting : IsSortingResult (· ≤ ·) input result.1
  keys : result.2.map CountStep.key = input
  replays : replay? input result.2 = some result.1

theorem sortTrace_spec (xs : List ℕ) : CountingRunSpec xs (sortTrace xs) := by
  refine ⟨?_, countingSortTrace_keys xs, ?_⟩
  · simpa using countingSortResult_spec xs
  · simpa [countingSortTrace] using replay_countingSortTrace xs

/-- Attach the allocation bound to every generated event without changing the log. -/
def countingSortTraceBounded (xs : List ℕ) : List (BoundedCountStep (keyRange xs)) :=
  (countingSortTrace xs).attach.map fun ⟨step, hstep⟩ =>
    ⟨⟨step.key, by
      have hmem : step.key ∈ (countingSortTrace xs).map CountStep.key :=
        List.mem_map.mpr ⟨step, hstep, rfl⟩
      rw [countingSortTrace_keys] at hmem
      exact mem_lt_keyRange xs step.key hmem⟩, step.value⟩

@[simp] theorem countingSortTraceBounded_erase (xs : List ℕ) :
    (countingSortTraceBounded xs).map BoundedCountStep.erase = countingSortTrace xs := by
  simp [countingSortTraceBounded, BoundedCountStep.erase, List.map_map]

theorem replay_countingSortTraceBounded (xs : List ℕ) :
    replayBounded? xs (countingSortTraceBounded xs) = some (countingSortResult xs) := by
  simpa [replayBounded?] using replay_countingSortTrace xs

theorem replayBounded?_spec (xs : List ℕ) (trace : List (BoundedCountStep (keyRange xs)))
    (output : List ℕ) (h : replayBounded? xs trace = some output) :
    IsSortingResult (· ≤ ·) xs output :=
  replay?_spec xs (trace.map BoundedCountStep.erase) output h

end LeanSort.Counting
