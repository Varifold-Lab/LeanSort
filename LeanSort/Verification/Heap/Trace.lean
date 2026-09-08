import LeanSort.Verification.Heap.Correctness

/-! Checked extraction traces. Replay verifies values and remaining sizes against
the actual heap, and rejects missing, extra, or incorrect steps. It re-executes
heap operations; it is not an independent certificate of sortedness. -/

namespace LeanSort.Heap

open Batteries

variable {α : Type} {lt : α → α → Bool}

/-- Check every extraction, including the terminal empty heap. -/
def replayExtract? [DecidableEq α] :
    List (ExtractStep α) → BinaryHeap α lt → Option (List α)
  | [], heap => if heap.max.isNone then some [] else none
  | step :: trace, heap =>
    match heap.max with
    | none => none
    | some x =>
      if step = ⟨x, heap.popMax.size⟩ then
        (replayExtract? trace heap.popMax).map (x :: ·)
      else none

theorem replayExtract?_extractTrace [DecidableEq α] (heap : BinaryHeap α lt) :
    replayExtract? (extractTrace heap) heap =
      some ((extractTrace heap).map ExtractStep.value) := by
  fun_induction extractTrace heap with
  | case1 heap hx => simp [replayExtract?, hx]
  | case2 heap x hx _ ih => simp [replayExtract?, hx, ih]

/-- Acceptance characterizes exactly the complete execution trace. -/
theorem replayExtract?_eq_some_iff [DecidableEq α]
    (trace : List (ExtractStep α)) (heap : BinaryHeap α lt) (ys : List α) :
    replayExtract? trace heap = some ys ↔
      trace = extractTrace heap ∧ ys = trace.map ExtractStep.value := by
  induction trace generalizing heap ys with
  | nil =>
    cases hx : heap.max with
    | none => simp [replayExtract?, hx, eq_comm]
    | some x => simp [replayExtract?, hx, extractTrace_of_max_some heap hx]
  | cons step trace ih =>
    cases hx : heap.max with
    | none => simp [replayExtract?, hx]
    | some x =>
      by_cases hs : step = ⟨x, heap.popMax.size⟩
      · subst step
        simp [replayExtract?, hx, extractTrace_of_max_some heap hx,
          ih, eq_comm]
      · simp only [BinaryHeap.size_popMax] at hs
        simp [replayExtract?, hx, hs, extractTrace_of_max_some heap hx]

/-- Replay a whole-sort extraction trace from the library's initial heap. -/
def replayHeap? [LinearOrder α] (trace : List (ExtractStep α)) (xs : List α) :
    Option (List α) :=
  replayExtract? trace (initialHeap xs)

theorem replayHeap?_heapSortTrace [LinearOrder α] (xs : List α) :
    replayHeap? (heapSortTrace xs) xs = some (heapSortResult xs) := by
  rw [← heapSortTrace_values xs]
  exact replayExtract?_extractTrace (initialHeap xs)

theorem replayHeap?_eq_some_iff [LinearOrder α]
    (trace : List (ExtractStep α)) (xs ys : List α) :
    replayHeap? trace xs = some ys ↔
      trace = heapSortTrace xs ∧ ys = heapSortResult xs := by
  rw [replayHeap?, replayExtract?_eq_some_iff]
  change (trace = heapSortTrace xs ∧ _) ↔ _
  constructor
  · rintro ⟨rfl, rfl⟩
    exact ⟨rfl, heapSortTrace_values xs⟩
  · rintro ⟨rfl, rfl⟩
    exact ⟨rfl, (heapSortTrace_values xs).symm⟩

end LeanSort.Heap
