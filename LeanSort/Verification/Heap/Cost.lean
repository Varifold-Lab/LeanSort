module

public import LeanSort.Verification.Heap.Correctness
import all Batteries.Data.BinaryHeap.Basic

/-! Extraction and key-comparison costs. The extraction counter charges one unit
per root removal. The separate comparison-counted execution follows every branch
of construction and extraction, and is proved to return Batteries' result.
Index tests, allocation, copying, and instrumentation overhead are not key comparisons. -/

public section

namespace LeanSort.Heap

section Extractions

variable {α : Type} [LinearOrder α]

@[simp] theorem heapSortTrace_length (xs : List α) :
    (heapSortTrace xs).length = xs.length := by
  simpa only [List.length_map, heapSortResult_length] using
    congrArg List.length (heapSortTrace_values xs)

/-- Number of root extractions, not the total work performed inside them. -/
def heapExtractionCost (xs : List α) : Nat := (heapSortTrace xs).length

@[simp] theorem heapExtractionCost_eq_length (xs : List α) :
    heapExtractionCost xs = xs.length := heapSortTrace_length xs

end Extractions

section Comparisons

open Batteries

variable {β : Type}

/-- The library's child selection, made explicit for comparison instrumentation. -/
@[expose] def selectChild (lt : β → β → Bool) (a : Vector β n) (i : Fin n) : Option (Fin n) :=
  let left := 2 * i.val + 1
  let right := left + 1
  if hl : left < n then
    if hr : right < n then
      if lt a[left] a[right] then some ⟨right, hr⟩ else some ⟨left, hl⟩
    else some ⟨left, hl⟩
  else none

private theorem selectChild_eq (lt : β → β → Bool) (a : Vector β n) (i : Fin n) :
    selectChild lt a i = BinaryHeap.maxChild lt a i := rfl

private theorem maxChild_growth (lt : β → β → Bool) (a : Vector β n) (i j : Fin n)
    (h : BinaryHeap.maxChild lt a i = some j) : 2 * i.val + 1 ≤ j.val := by
  unfold BinaryHeap.maxChild at h
  dsimp only at h
  split at h
  · split at h
    · split at h <;> cases h <;> simp
    · cases h; simp
  · contradiction

/-- Count only key comparisons: at most one between siblings and one with the parent. -/
@[expose] def siftRun (lt : β → β → Bool) (a : Vector β n) (i : Fin n) : Vector β n × Nat :=
  match hx : selectChild lt a i with
  | none => (a, 0)
  | some j =>
    let localCost := (if 2 * i.val + 2 < n then 1 else 0) + 1
    if lt a[i] a[j] then
      have : n - j.val < n - i.val := by
        have := maxChild_growth lt a i j ((selectChild_eq lt a i).symm.trans hx)
        omega
      let run := siftRun lt (a.swap i j) j
      (run.1, localCost + run.2)
    else (a, localCost)
termination_by n - i.val

theorem siftRun_result (lt : β → β → Bool) (a : Vector β n) (i : Fin n) :
    (siftRun lt a i).1 = BinaryHeap.heapifyDown lt a i := by
  fun_induction BinaryHeap.heapifyDown lt a i with
  | case1 a i hx =>
    change selectChild lt a i = none at hx
    rw [siftRun]
    split <;> simp_all
  | case2 a i j hx hij hcmp ih =>
    change selectChild lt a i = some j at hx
    rw [siftRun]
    split <;> simp_all
  | case3 a i j hx hij hcmp =>
    change selectChild lt a i = some j at hx
    rw [siftRun]
    split <;> simp_all

private theorem log2_mono {m n : Nat} (h : m ≤ n) : m.log2 ≤ n.log2 := by
  by_cases hm : m = 0
  · simp [hm]
  · exact (Nat.le_log2 (by omega)).2 ((Nat.le_log2 hm).1 (Nat.le_refl _ ) |>.trans h)

private theorem log2_child (i j : Nat) (h : 2 * i + 1 ≤ j) :
    (i + 1).log2 + 1 ≤ (j + 1).log2 := by
  rw [← Nat.log2_two_mul (Nat.succ_ne_zero i)]
  exact log2_mono (by omega)

/-- Each recursive descent increases the logarithmic depth by at least one. -/
theorem siftRun_comparisons_le (lt : β → β → Bool) (a : Vector β n) (i : Fin n) :
    (siftRun lt a i).2 ≤ 2 * (n.log2 + 1 - (i.val + 1).log2) := by
  fun_induction BinaryHeap.heapifyDown lt a i with
  | case1 a i hx =>
    change selectChild lt a i = none at hx
    rw [siftRun]
    split <;> simp_all
  | case2 a i j hx hij hcmp ih =>
    have hg := log2_child i.val j.val (maxChild_growth lt a i j hx)
    have hj : (j.val + 1).log2 ≤ n.log2 := log2_mono (Nat.succ_le_of_lt j.isLt)
    rw [siftRun]
    split
    · simp
    · rename_i j' he
      have heq : j' = j := Option.some.inj (he.symm.trans hx)
      subst j'
      simp only [hcmp, ↓reduceIte]
      split_ifs <;> omega
  | case3 a i j hx hij hcmp =>
    have hi : (i.val + 1).log2 ≤ n.log2 := log2_mono (Nat.succ_le_of_lt i.isLt)
    rw [siftRun]
    split
    · simp
    · rename_i j' he
      have heq : j' = j := Option.some.inj (he.symm.trans hx)
      subst j'
      simp only [hcmp, Bool.false_eq_true, ↓reduceIte]
      split_ifs <;> omega

theorem siftRun_comparisons_le_height (lt : β → β → Bool) (a : Vector β n) (i : Fin n) :
    (siftRun lt a i).2 ≤ 2 * (n.log2 + 1) :=
  (siftRun_comparisons_le lt a i).trans (Nat.mul_le_mul_left 2 (Nat.sub_le _ _))

/-- Bottom-up heap construction with the comparisons of every sift accumulated. -/
@[expose] def buildRun (lt : β → β → Bool) :
    (k : Nat) → Vector β n → k ≤ n → Vector β n × Nat
  | 0, a, _ => (a, 0)
  | k + 1, a, h =>
    let first := siftRun lt a ⟨k, Nat.lt_of_succ_le h⟩
    let rest := buildRun lt k first.1 (by omega)
    (rest.1, first.2 + rest.2)

private theorem buildRun_result (lt : β → β → Bool) (k : Nat) (a : Vector β n) (h : k ≤ n) :
    (buildRun lt k a h).1 = BinaryHeap.mkHeap.loop lt k a h := by
  induction k generalizing a with
  | zero => rfl
  | succ k ih => simp [buildRun, BinaryHeap.mkHeap.loop, ih, siftRun_result]

theorem buildRun_comparisons_le (lt : β → β → Bool) (k : Nat) (a : Vector β n) (h : k ≤ n) :
    (buildRun lt k a h).2 ≤ 2 * k * (n.log2 + 1) := by
  induction k generalizing a with
  | zero => simp [buildRun]
  | succ k ih =>
    have hfirst := siftRun_comparisons_le_height lt a ⟨k, Nat.lt_of_succ_le h⟩
    have hrest := ih (siftRun lt a ⟨k, Nat.lt_of_succ_le h⟩).1 (by omega)
    simpa [buildRun, Nat.mul_add, Nat.add_mul, Nat.add_comm, Nat.add_left_comm, Nat.add_assoc] using
      Nat.add_le_add hfirst hrest

/-- Root removal with its actual sift comparisons. -/
@[expose] def popRun {lt : β → β → Bool} (heap : BinaryHeap β lt) : BinaryHeap β lt × Nat :=
  if hn : heap.size = 0 then (heap, 0) else
    let a := (heap.vector.swap 0 (heap.size - 1) (Nat.pos_of_ne_zero hn) (Nat.pred_lt hn)).pop
    if h : 0 < heap.size - 1 then
      let run := siftRun lt a ⟨0, h⟩
      (⟨run.1.toArray⟩, run.2)
    else (⟨a.toArray⟩, 0)

@[simp] theorem popRun_result {lt : β → β → Bool} (heap : BinaryHeap β lt) :
    (popRun heap).1 = heap.popMax := by
  unfold popRun BinaryHeap.popMax
  split <;> simp_all only
  split <;> simp [siftRun_result]

theorem popRun_comparisons_le {lt : β → β → Bool} (heap : BinaryHeap β lt) :
    (popRun heap).2 ≤ 2 * (heap.size.log2 + 1) := by
  unfold popRun
  split
  · simp
  · split
    · exact (siftRun_comparisons_le_height _ _ _).trans
        (Nat.mul_le_mul_left 2 (Nat.add_le_add_right (log2_mono (Nat.sub_le _ _)) 1))
    · simp

/-- Fuel bounds the number of extractions; callers supply at least the heap size. -/
@[expose] def drainRun {lt : β → β → Bool} :
    Nat → BinaryHeap β lt → Array β → Array β × Nat
  | 0, _, out => (out, 0)
  | fuel + 1, heap, out =>
    match heap.max with
    | none => (out, 0)
    | some x =>
      let popped := popRun heap
      let rest := drainRun fuel popped.1 (out.push x)
      (rest.1, popped.2 + rest.2)

private theorem drainRun_result (lt : β → β → Bool) (fuel : Nat)
    (heap : BinaryHeap β (flip lt)) (out : Array β) (h : heap.size ≤ fuel) :
    (drainRun fuel heap out).1 = Array.heapSort.loop lt heap out := by
  induction fuel generalizing heap out with
  | zero =>
    have hx : heap.max = none := by
      simp [BinaryHeap.max, Array.getElem?_eq_none (by change heap.size ≤ 0; exact h)]
    rw [Array.heapSort.loop]
    split <;> simp_all [drainRun]
  | succ fuel ih =>
    rw [Array.heapSort.loop]
    split
    · rename_i hx
      simp [drainRun, hx]
    · rename_i x hx
      simpa [drainRun, hx] using ih heap.popMax (out.push x) (by
        rw [BinaryHeap.size_popMax]
        omega)

theorem drainRun_comparisons_le {lt : β → β → Bool} (fuel : Nat)
    (heap : BinaryHeap β lt) (out : Array β) (h : heap.size ≤ bound) :
    (drainRun fuel heap out).2 ≤ 2 * fuel * (bound.log2 + 1) := by
  induction fuel generalizing heap out with
  | zero => simp [drainRun]
  | succ fuel ih =>
    cases hx : heap.max with
    | none => simp [drainRun, hx]
    | some x =>
      have hp := (popRun_comparisons_le heap).trans
        (Nat.mul_le_mul_left 2 (Nat.add_le_add_right (log2_mono h) 1))
      have hr := ih heap.popMax (out.push x) (by rw [BinaryHeap.size_popMax]; omega)
      simpa [drainRun, hx, Nat.mul_add, Nat.add_mul,
        Nat.add_comm, Nat.add_left_comm, Nat.add_assoc] using Nat.add_le_add hp hr

/-- Comparison-counted execution of both bottom-up construction and extraction. -/
@[expose] def heapComparisonRun [LinearOrder β] (xs : List β) : List β × Nat :=
  let built := buildRun minLt (xs.length / 2)
    ⟨xs.toArray, rfl⟩ (by simp; omega)
  let drained := drainRun (lt := minLt) xs.length ⟨built.1.toArray⟩ #[]
  (drained.1.toList, built.2 + drained.2)

@[simp] theorem heapComparisonRun_result [LinearOrder β] (xs : List β) :
    (heapComparisonRun xs).1 = heapSortResult xs := by
  simp only [heapComparisonRun, buildRun_result]
  exact congrArg Array.toList
    (drainRun_result (fun x y => decide (x < y)) xs.length (initialHeap xs) #[]
      (Nat.le_of_eq (initialHeap_size xs)))

/-- Number of calls to the key comparator in the counted execution. -/
@[expose] def heapComparisonCost [LinearOrder β] (xs : List β) : Nat :=
  (heapComparisonRun xs).2

theorem heapComparisonCost_le [LinearOrder β] (xs : List β) :
    heapComparisonCost xs ≤ 4 * xs.length * (xs.length.log2 + 1) := by
  let built := buildRun (minLt (α := β)) (xs.length / 2)
    ⟨xs.toArray, rfl⟩ (by simp; omega)
  have hb := buildRun_comparisons_le (minLt (α := β)) (xs.length / 2)
    ⟨xs.toArray, rfl⟩ (by simp; omega)
  simp only [List.size_toArray] at hb
  have hb' : built.2 ≤ 2 * xs.length * (xs.length.log2 + 1) :=
    hb.trans (Nat.mul_le_mul_right _ (Nat.mul_le_mul_left 2 (Nat.div_le_self _ _)))
  have hd := drainRun_comparisons_le (bound := xs.length) xs.length
    (⟨built.1.toArray⟩ : BinaryHeap β minLt) #[] (by simp [BinaryHeap.size])
  change built.2 + (drainRun xs.length (⟨built.1.toArray⟩ : BinaryHeap β minLt) #[]).2 ≤ _
  calc
    _ ≤ 2 * xs.length * (xs.length.log2 + 1) +
        2 * xs.length * (xs.length.log2 + 1) := Nat.add_le_add hb' hd
    _ = _ := by rw [← Nat.add_mul]; congr 1; omega

end Comparisons

end LeanSort.Heap
