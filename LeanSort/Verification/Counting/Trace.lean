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
  induction xs generalizing counts <;> simp [histogramTraceAux, *]

theorem histogramTraceAux_length (xs : List ℕ) (counts : Array ℕ) :
    (histogramTraceAux xs counts).2.length = xs.length := by
  induction xs generalizing counts <;> simp [histogramTraceAux, *]

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

theorem replayHistogram?_generated (xs : List ℕ) (counts : Array ℕ)
    (hxs : ∀ x ∈ xs, x < counts.size) :
    replayHistogram? xs (histogramTraceAux xs counts).2 counts =
      some (histogramTraceAux xs counts).1 := by
  induction xs generalizing counts with
  | nil => rfl
  | cons x xs ih =>
      have hx := hxs x (by simp)
      simpa [histogramTraceAux, replayHistogram?, hx, Array.getElem_modify_self] using
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

end LeanSort.Counting
