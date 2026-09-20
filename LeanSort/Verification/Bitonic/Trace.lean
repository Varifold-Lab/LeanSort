import LeanSort.Verification.Bitonic.Equations

/-! Data-independent comparator schedules and their exact array semantics. -/

namespace LeanSort.Bitonic

structure Comparator where
  ascending : Bool
  first : Nat
  second : Nat
  deriving DecidableEq, Repr

def runSchedule {α : Type*} [LinearOrder α]
    (steps : List Comparator) (xs : Array (Option α)) : Array (Option α) :=
  steps.foldl (fun a c => compareExchange c.ascending c.first c.second a) xs

def mergeSchedule : Nat → Nat → Bool → List Comparator
  | 0, _, _ => []
  | depth + 1, start, ascending =>
      (List.range (2 ^ depth)).map
        (fun i => ⟨ascending, start + i, start + 2 ^ depth + i⟩) ++
      mergeSchedule depth start ascending ++
      mergeSchedule depth (start + 2 ^ depth) ascending

def sortSchedule : Nat → Nat → Bool → List Comparator
  | 0, _, _ => []
  | depth + 1, start, ascending =>
      sortSchedule depth start true ++
      sortSchedule depth (start + 2 ^ depth) false ++
      mergeSchedule (depth + 1) start ascending

variable {α : Type*} [LinearOrder α]

theorem mergeSchedule_bounds (depth start : Nat) (ascending : Bool)
    (c : Comparator) (hc : c ∈ mergeSchedule depth start ascending) :
    start ≤ c.first ∧ c.first < c.second ∧ c.second < start + 2 ^ depth := by
  induction depth generalizing start with
  | zero => simp [mergeSchedule] at hc
  | succ depth ih =>
    simp only [mergeSchedule, List.mem_append, List.mem_map] at hc
    have hp : 0 < 2 ^ depth := Nat.two_pow_pos depth
    rw [Nat.pow_succ]
    rcases hc with (⟨i, hi, rfl⟩ | hl) | hr
    · simp only [List.mem_range] at hi
      dsimp only
      omega
    · have := ih start hl
      omega
    · have := ih (start + 2 ^ depth) hr
      omega

theorem sortSchedule_bounds (depth start : Nat) (ascending : Bool)
    (c : Comparator) (hc : c ∈ sortSchedule depth start ascending) :
    start ≤ c.first ∧ c.first < c.second ∧ c.second < start + 2 ^ depth := by
  induction depth generalizing start ascending with
  | zero => simp [sortSchedule] at hc
  | succ depth ih =>
    simp only [sortSchedule, List.mem_append] at hc
    rcases hc with (hl | hr) | hm
    · have := ih start true hl
      rw [Nat.pow_succ]
      omega
    · have := ih (start + 2 ^ depth) false hr
      rw [Nat.pow_succ]
      omega
    · exact mergeSchedule_bounds _ _ _ _ hm

omit [LinearOrder α] in
/-- All scheduled calls are genuine, in-bounds comparisons. -/
theorem sortSchedule_valid (xs : List α) (c : Comparator)
    (hc : c ∈ sortSchedule (networkDepth xs.length) 0 true) :
    c.first < (paddedInput xs).size ∧ c.second < (paddedInput xs).size := by
  have := sortSchedule_bounds _ _ _ _ hc
  rw [paddedInput_size]
  omega

@[simp] theorem runSchedule_append (left right : List Comparator)
    (xs : Array (Option α)) :
    runSchedule (left ++ right) xs = runSchedule right (runSchedule left xs) := by
  simp [runSchedule, List.foldl_append]

theorem run_mergeSchedule (depth start : Nat) (ascending : Bool)
    (xs : Array (Option α)) :
    runSchedule (mergeSchedule depth start ascending) xs =
      mergeNetwork depth start ascending xs := by
  induction depth generalizing start xs with
  | zero => rfl
  | succ depth ih =>
    simp only [mergeSchedule, runSchedule_append, ih, mergeNetwork]
    simp only [runSchedule, List.foldl_map]

theorem run_sortSchedule (depth start : Nat) (ascending : Bool)
    (xs : Array (Option α)) :
    runSchedule (sortSchedule depth start ascending) xs =
      sortNetwork depth start ascending xs := by
  induction depth generalizing start ascending xs with
  | zero => rfl
  | succ depth ih =>
    simp only [sortSchedule, runSchedule_append, ih, run_mergeSchedule, sortNetwork]

/-- A checked schedule rejects omitted, extra, reordered, or altered comparators. -/
def replayChecked? (xs : List α) (steps : List Comparator) : Option (List α) :=
  if steps = sortSchedule (networkDepth xs.length) 0 true then
    some ((runSchedule steps (paddedInput xs)).toList.filterMap id)
  else none

theorem replayChecked?_iff (xs output : List α) (steps : List Comparator) :
    replayChecked? xs steps = some output ↔
      steps = sortSchedule (networkDepth xs.length) 0 true ∧
      output = bitonicSortResult xs := by
  unfold replayChecked?
  split <;> simp_all [run_sortSchedule, bitonicSortResult, eq_comm]

@[simp] theorem replay_sortSchedule (xs : List α) :
    replayChecked? xs (sortSchedule (networkDepth xs.length) 0 true) =
      some (bitonicSortResult xs) :=
  (replayChecked?_iff _ _ _).mpr ⟨rfl, rfl⟩

end LeanSort.Bitonic
