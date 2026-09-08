module

public import Batteries.Data.BinaryHeap
public import Mathlib.Order.Defs.LinearOrder

/-! Binary-heap sorting, reusing Batteries' array implementation. -/

public section

namespace LeanSort.Heap

/-- Ascending heap sort through an array-backed binary heap.
The library collects extracted minima into a separate output array; this API
does not claim an in-place or constant-extra-space implementation. -/
@[expose] def heapSortResult {α : Type} [LinearOrder α] (xs : List α) : List α :=
  (xs.toArray.heapSort (fun x y => decide (x < y))).toList

/-- One root extraction, recording its value and the number of entries left.
This is an extraction trace, not a trace of internal comparisons or swaps. -/
structure ExtractStep (α : Type) where
  value : α
  remaining : Nat
  deriving DecidableEq, Repr

/-- Optional instrumentation of the library's extraction phase. -/
@[expose] def extractTrace {α : Type} {lt : α → α → Bool}
    (heap : Batteries.BinaryHeap α lt) : List (ExtractStep α) :=
  match hx : heap.max with
  | none => []
  | some x =>
    have : heap.popMax.size < heap.size := by
      rw [Batteries.BinaryHeap.size_popMax]
      exact Nat.sub_lt (Batteries.BinaryHeap.size_pos_of_max hx) Nat.zero_lt_one
    ⟨x, heap.popMax.size⟩ :: extractTrace heap.popMax
termination_by heap.size

/-- Build the same minimum heap used by Batteries' ascending heap sort. -/
@[expose] def initialHeap {α : Type} [LinearOrder α] (xs : List α) :=
  xs.toArray.toBinaryHeap (fun x y => decide (y < x))

@[expose] def heapSortTrace {α : Type} [LinearOrder α] (xs : List α) :
    List (ExtractStep α) :=
  extractTrace (initialHeap xs)

/-- Optional traced execution; the ordinary sorting entry point does not build a trace. -/
@[expose] def sortTrace {α : Type} [LinearOrder α] (xs : List α) :
    List α × List (ExtractStep α) :=
  let trace := heapSortTrace xs
  (trace.map ExtractStep.value, trace)

end LeanSort.Heap
