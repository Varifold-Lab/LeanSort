module

public import LeanSort.Verification.Heap.Equations
import all Batteries.Data.BinaryHeap.Basic
public import Mathlib.Data.List.Sort

/-! Element conservation for Batteries' binary-heap sort.
These theorems do not yet establish that extraction is ordered. -/

public section

namespace LeanSort.Heap

open Batteries

variable {α : Type} {lt : α → α → Bool}

/-- Sifting only exchanges elements; it preserves their multiplicities. -/
theorem heapifyDown_perm (a : Vector α n) (i : Fin n) :
    (BinaryHeap.heapifyDown lt a i).toList.Perm a.toList := by
  fun_induction BinaryHeap.heapifyDown lt a i with
  | case1 => exact .refl _
  | case2 a i j _ _ _ ih =>
    exact ih.trans (Vector.swap_perm i.isLt j.isLt).toList
  | case3 => exact .refl _

/-- Building a heap only rearranges the input. -/
theorem mkHeap_perm (a : Vector α n) :
    (BinaryHeap.mkHeap lt a).toList.Perm a.toList := by
  unfold BinaryHeap.mkHeap
  generalize_proofs h
  generalize n / 2 = k at h ⊢
  induction k generalizing a with
  | zero => exact .refl _
  | succ k ih =>
    exact (ih _ _).trans (heapifyDown_perm a ⟨k, Nat.lt_of_succ_le h⟩)

/-- Removing the root accounts for exactly one occurrence of its value. -/
theorem popMax_perm (heap : BinaryHeap α lt) (hx : heap.max = some x) :
    (x :: heap.popMax.arr.toList).Perm heap.arr.toList := by
  have hpos := BinaryHeap.size_pos_of_max hx
  change 0 < heap.arr.size at hpos
  have hx0 : heap.arr[0]'hpos = x := by
    simpa [BinaryHeap.max, Array.getElem?_eq_getElem hpos] using hx
  have hlast : heap.arr.size - 1 < heap.arr.size := Nat.pred_lt (Nat.ne_of_gt hpos)
  let swapped := heap.arr.swap 0 (heap.arr.size - 1) hpos hlast
  have restore : swapped.pop.toList ++ [x] = swapped.toList := by
    let : Inhabited α := ⟨x⟩
    have h := Array.eq_push_pop_back!_of_size_ne_zero (xs := swapped) (by
      dsimp only [swapped]
      rw [Array.size_swap]
      exact Nat.ne_of_gt hpos)
    have hb : swapped.back! = x := by
      dsimp only [Array.back!, swapped]
      rw [Array.size_swap]
      rw [getElem!_pos _ _ (by simpa only [Array.size_swap] using hlast)]
      exact Array.getElem_swap_right.trans hx0
    simpa [hb] using (congrArg Array.toList h).symm
  have hp : heap.popMax.arr.toList.Perm swapped.pop.toList := by
    unfold BinaryHeap.popMax
    split
    · rename_i hempty
      exact False.elim ((Nat.ne_of_gt hpos) hempty)
    · split
      · exact heapifyDown_perm _ _
      · exact .refl _
  exact (hp.cons x).trans ((List.perm_append_singleton _ _).symm.trans
    (restore ▸ (Array.swap_perm hpos hlast).toList))

/-- The output already collected and the remaining heap conserve all elements. -/
private theorem heapSort_loop_perm (heap : BinaryHeap α (flip lt)) (out : Array α) :
    (Array.heapSort.loop lt heap out).toList.Perm (out.toList ++ heap.arr.toList) := by
  fun_induction Array.heapSort.loop lt heap out with
  | case1 heap out hx =>
    have hempty : heap.arr = #[] := by
      simpa [BinaryHeap.max] using hx
    simp [hempty]
  | case2 heap out x hx _ ih =>
    exact ih.trans (by
      simpa [List.append_assoc] using (popMax_perm heap hx).append_left out.toList)

/-- Array heap sort conserves its input for any comparator. -/
theorem array_heapSort_perm (a : Array α) (lt : α → α → Bool) :
    (a.heapSort lt).toList.Perm a.toList :=
  (heapSort_loop_perm _ #[]).trans (mkHeap_perm ⟨a, rfl⟩)

/-- Heap sort preserves every element, including its multiplicity. -/
theorem heapSortResult_perm [LinearOrder α] (xs : List α) :
    (heapSortResult xs).Perm xs :=
  array_heapSort_perm xs.toArray _

/-- Length preservation is a consequence of element conservation. -/
@[simp] theorem heapSortResult_length [LinearOrder α] (xs : List α) :
    (heapSortResult xs).length = xs.length :=
  (heapSortResult_perm xs).length_eq

@[simp] theorem mem_heapSortResult [LinearOrder α] (xs : List α) (x : α) :
    x ∈ heapSortResult xs ↔ x ∈ xs :=
  (heapSortResult_perm xs).mem_iff

@[simp] theorem count_heapSortResult [LinearOrder α] (xs : List α) (x : α) :
    (heapSortResult xs).count x = xs.count x :=
  (heapSortResult_perm xs).count_eq x

end LeanSort.Heap
