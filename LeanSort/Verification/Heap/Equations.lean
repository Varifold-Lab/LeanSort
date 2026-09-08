module

public import LeanSort.Algorithm.Heap
import all Batteries.Data.BinaryHeap.Basic
public import Mathlib.Data.List.Sort

/-! Equations connecting extraction instrumentation to Batteries' implementation. -/

public section

namespace LeanSort.Heap

open Batteries

variable {α : Type} {lt : α → α → Bool}

@[simp] theorem extractTrace_of_max_none (heap : BinaryHeap α lt) (h : heap.max = none) :
    extractTrace heap = [] := by
  rw [extractTrace]
  split <;> simp_all

theorem extractTrace_of_max_some (heap : BinaryHeap α lt) (h : heap.max = some x) :
    extractTrace heap = ⟨x, heap.popMax.size⟩ :: extractTrace heap.popMax := by
  rw [extractTrace]
  split <;> simp_all

@[simp] theorem initialHeap_size [LinearOrder α] (xs : List α) :
    (initialHeap xs).size = xs.length := by
  simp [initialHeap, Array.toBinaryHeap, BinaryHeap.size]

private theorem loop_eq_extractTrace (heap : BinaryHeap α (flip lt)) (out : Array α) :
    (Array.heapSort.loop lt heap out).toList =
      out.toList ++ (extractTrace heap).map ExtractStep.value := by
  fun_induction Array.heapSort.loop lt heap out with
  | case1 heap out hx => simp [extractTrace_of_max_none heap hx]
  | case2 heap out x hx _ ih =>
    simpa [extractTrace_of_max_some heap hx, List.append_assoc] using ih

/-- The instrumented extraction sequence is exactly the library's output. -/
@[simp] theorem heapSortTrace_values [LinearOrder α] (xs : List α) :
    (heapSortTrace xs).map ExtractStep.value = heapSortResult xs := by
  exact (loop_eq_extractTrace (initialHeap xs) #[]).symm

@[simp] theorem sortTrace_result [LinearOrder α] (xs : List α) :
    (sortTrace xs).1 = heapSortResult xs :=
  heapSortTrace_values xs

@[simp] theorem sortTrace_trace [LinearOrder α] (xs : List α) :
    (sortTrace xs).2 = heapSortTrace xs := rfl

end LeanSort.Heap
