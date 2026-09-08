module

public import LeanSort.Verification.Heap.Equations
import all Batteries.Data.BinaryHeap.Basic
public import Mathlib.Data.List.Sort

/-! Correctness of Batteries' binary-heap sort: element conservation and sortedness.
The heap-order proof tracks a single possible violation during each sift. -/

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

section Order

variable [LinearOrder α]

abbrev minLt (x y : α) : Bool := decide (y < x)

/-- The two child positions of a binary heap node. -/
def Child (parent child : Nat) : Prop :=
  child = 2 * parent + 1 ∨ child = 2 * parent + 2

private theorem Child.index_lt (h : Child p c) : p < c := by
  rcases h with h | h <;> omega

private theorem Child.parent_unique (h : Child p c) (h' : Child q c) : p = q := by
  rcases h with h | h <;> rcases h' with h' | h' <;> omega

/-- All parent-child edges starting at or after `start` satisfy the minimum-heap order. -/
def HeapOrderedFrom (a : Vector α n) (start : Nat) : Prop :=
  ∀ p c : Fin n, start ≤ p.val → Child p.val c.val → a[p] ≤ a[c]

/-- During sifting, only `hole` may violate heap order. Its parent also bounds
its children, so moving a child up cannot break the already repaired edge. -/
def SiftInvariant (a : Vector α n) (start : Nat) (hole : Fin n) : Prop :=
  (∀ p c : Fin n, start ≤ p.val → p ≠ hole → Child p.val c.val → a[p] ≤ a[c]) ∧
  (∀ p c : Fin n, start ≤ p.val → Child p.val hole.val →
    Child hole.val c.val → a[p] ≤ a[c])

private theorem maxChild_none (a : Vector α n) (i : Fin n)
    (h : BinaryHeap.maxChild minLt a i = none) :
    ∀ c : Fin n, ¬ Child i.val c.val := by
  unfold BinaryHeap.maxChild at h
  dsimp only at h
  split at h
  · split at h
    · split at h <;> contradiction
    · contradiction
  · intro c hc
    rcases hc with hc | hc <;> omega

private theorem maxChild_spec (a : Vector α n) (i j : Fin n)
    (h : BinaryHeap.maxChild minLt a i = some j) :
    Child i.val j.val ∧ ∀ c : Fin n, Child i.val c.val → a[j] ≤ a[c] := by
  unfold BinaryHeap.maxChild at h
  dsimp only at h
  split at h
  · split at h
    · split at h
      · cases h
        constructor
        · exact Or.inr rfl
        · intro c hc
          rcases hc with hc | hc
          · have : c = ⟨2 * i.val + 1, by omega⟩ := Fin.ext hc
            subst c
            simp_all [minLt, le_of_lt]
          · have : c = ⟨2 * i.val + 1 + 1, by omega⟩ := Fin.ext (by omega)
            subst c
            exact le_rfl
      · cases h
        constructor
        · exact Or.inl rfl
        · intro c hc
          rcases hc with hc | hc
          · have : c = ⟨2 * i.val + 1, by omega⟩ := Fin.ext hc
            subst c
            exact le_rfl
          · have : c = ⟨2 * i.val + 1 + 1, by omega⟩ := Fin.ext (by omega)
            subst c
            simpa [minLt] using (show ¬ a[2 * i.val + 1 + 1] < a[2 * i.val + 1] from by simpa using ‹¬ minLt _ _ = true›)
    · cases h
      constructor
      · exact Or.inl rfl
      · intro c hc
        have : c = ⟨2 * i.val + 1, by omega⟩ := Fin.ext (by rcases hc with hc | hc <;> omega)
        subst c
        exact le_rfl
  · contradiction

omit [LinearOrder α] in
private theorem swap_get (a : Vector α n) (i j p : Fin n) :
    (a.swap i j)[p] = if p = i then a[j] else if p = j then a[i] else a[p] := by
  by_cases hi : p = i
  · subst p; simp
  · by_cases hj : p = j
    · subst p; simp [hi]
    · have hi' : p.val ≠ i.val := fun h => hi (Fin.ext h)
      have hj' : p.val ≠ j.val := fun h => hj (Fin.ext h)
      simp [hi, hj, hi', hj']

private theorem SiftInvariant.swap (a : Vector α n) (i j : Fin n)
    (hstart : start ≤ i.val) (h : SiftInvariant a start i)
    (hij : Child i.val j.val) (hmin : ∀ c : Fin n, Child i.val c.val → a[j] ≤ a[c])
    (hle : a[j] ≤ a[i]) : SiftInvariant (a.swap i j) start j := by
  have hijlt := hij.index_lt
  have hji : j ≠ i := fun he => by subst j; omega
  constructor
  · intro p c hp hpj hpc
    rw [swap_get a i j p, swap_get a i j c]
    by_cases hpi : p = i
    · subst p
      have hci : c ≠ i := fun he => by subst c; have := hpc.index_lt; omega
      by_cases hcj : c = j
      · subst c
        simpa [hji] using hle
      · simpa [hci, hcj] using hmin c hpc
    · by_cases hci : c = i
      · subst c
        simpa [hpi, hpj] using h.2 p j hp hpc hij
      · have hcj : c ≠ j := by
          intro he
          subst c
          exact hpi (Fin.ext (hpc.parent_unique hij))
        simpa [hpi, hpj, hci, hcj] using h.1 p c hp hpi hpc
  · intro p c hp hpj hjc
    rw [swap_get a i j p, swap_get a i j c]
    have hpi : p = i := Fin.ext (hpj.parent_unique hij)
    subst p
    have hjclt := hjc.index_lt
    have hci : c ≠ i := fun he => by subst c; omega
    have hcj : c ≠ j := fun he => by subst c; omega
    simpa [hci, hcj] using h.1 j c (by omega) hji hjc

/-- Sifting repairs the one possible violation and preserves all other heap edges. -/
theorem heapifyDown_ordered (a : Vector α n) (i : Fin n)
    (hstart : start ≤ i.val) (h : SiftInvariant a start i) :
    HeapOrderedFrom (BinaryHeap.heapifyDown minLt a i) start := by
  fun_induction BinaryHeap.heapifyDown minLt a i with
  | case1 a i hx =>
    intro p c hp hpc
    by_cases hpi : p = i
    · subst p
      exact False.elim (maxChild_none a i hx c hpc)
    · exact h.1 p c hp hpi hpc
  | case2 a i j hx hij hcmp ih =>
    have hs := maxChild_spec a i j hx
    exact ih (by have := hs.1.index_lt; omega)
      (SiftInvariant.swap a i j hstart h hs.1 hs.2 (le_of_lt (by simpa using hcmp)))
  | case3 a i j hx hij hcmp =>
    have hs := maxChild_spec a i j hx
    intro p c hp hpc
    by_cases hpi : p = i
    · subst p
      exact (le_of_not_gt (by simpa using hcmp)).trans (hs.2 c hpc)
    · exact h.1 p c hp hpi hpc

theorem mkHeap_ordered (a : Vector α n) :
    HeapOrderedFrom (BinaryHeap.mkHeap minLt a) 0 := by
  have initial : HeapOrderedFrom a (n / 2) := by
    intro p c hp hc
    have := c.isLt
    rcases hc with hc | hc <;> omega
  unfold BinaryHeap.mkHeap
  generalize_proofs hb
  generalize n / 2 = k at hb initial ⊢
  induction k generalizing a with
  | zero => exact initial
  | succ k ih =>
    apply ih
    apply heapifyDown_ordered _ _ (Nat.le_refl k)
    constructor
    · intro p c hp hne hpc
      apply initial p c _ hpc
      have : p.val ≠ k := fun he => hne (Fin.ext he)
      omega
    · intro p c hp hpi hpc
      have := hpi.index_lt
      dsimp only at this
      omega

/-- A minimum heap, expressed on the library's existing vector representation. -/
def HeapOrdered (heap : BinaryHeap α minLt) : Prop := HeapOrderedFrom heap.vector 0

private theorem heapOrdered_mk (a : Vector α n) :
    HeapOrdered (⟨a.toArray⟩ : BinaryHeap α minLt) ↔ HeapOrderedFrom a 0 := by
  rcases a with ⟨a, rfl⟩
  rfl

theorem initialHeap_ordered (xs : List α) : HeapOrdered (initialHeap xs) := by
  exact (heapOrdered_mk _).2 (mkHeap_ordered ⟨xs.toArray, rfl⟩)

private theorem pop_swap_invariant (a : Vector α n) (hn : 0 < n) (hn' : 0 < n - 1)
    (h : HeapOrderedFrom a 0) :
    SiftInvariant ((a.swap 0 (n - 1) hn (by omega)).pop) 0 ⟨0, hn'⟩ := by
  constructor
  · intro p c hp hne hpc
    have hp0 : p.val ≠ 0 := fun he => hne (Fin.ext he)
    have hpc' := hpc.index_lt
    have hc0 : c.val ≠ 0 := by omega
    have hplast : p.val ≠ n - 1 := Nat.ne_of_lt p.isLt
    have hclast : c.val ≠ n - 1 := Nat.ne_of_lt c.isLt
    simpa [Vector.getElem_pop, Vector.getElem_swap, hp0, hc0, hplast, hclast] using
      h ⟨p.val, by omega⟩ ⟨c.val, by omega⟩ (by omega) hpc
  · intro p c hp hpi hpc
    have := hpi.index_lt
    dsimp only at this
    omega

theorem popMax_ordered (heap : BinaryHeap α minLt) (h : HeapOrdered heap) :
    HeapOrdered heap.popMax := by
  by_cases hs : heap.size ≤ 1
  · intro p c hp hpc
    have hh := BinaryHeap.size_popMax heap
    have := p.isLt
    omega
  unfold BinaryHeap.popMax
  split
  · exact h
  · rename_i hn
    split
    · rename_i hn'
      exact (heapOrdered_mk _).2 (heapifyDown_ordered _ _ (Nat.zero_le _)
        (pop_swap_invariant heap.vector (Nat.pos_of_ne_zero hn) hn' h))
    · omega

/-- Every entry is bounded below by the root. -/
theorem HeapOrdered.root_le (heap : BinaryHeap α minLt) (h : HeapOrdered heap)
    (hn : 0 < heap.size) (i : Fin heap.size) : heap.vector[0] ≤ heap.vector[i] := by
  have aux : ∀ k, ∀ hk : k < heap.size, heap.vector[0] ≤ heap.vector[k] := by
    intro k
    induction k using Nat.strong_induction_on with
    | h k ih =>
      intro hk
      by_cases hk0 : k = 0
      · subst k; exact le_rfl
      · have hparent : (k - 1) / 2 < k := by omega
        exact (ih _ hparent (by omega)).trans
          (h ⟨(k - 1) / 2, by omega⟩ ⟨k, hk⟩ (Nat.zero_le _) (by
            unfold Child
            dsimp only
            omega))
  exact aux i.val i.isLt

private theorem root_le_remaining (heap : BinaryHeap α minLt) (h : HeapOrdered heap)
    (hx : heap.max = some x) : ∀ y ∈ heap.popMax.arr.toList, x ≤ y := by
  intro y hy
  have hy' := (popMax_perm heap hx).mem_iff.mp (List.mem_cons_of_mem x hy)
  obtain ⟨i, hi, hiy⟩ := List.mem_iff_getElem.mp hy'
  have hn := BinaryHeap.size_pos_of_max hx
  have hx0 : heap.arr[0]'hn = x := by
    simpa [BinaryHeap.max, Array.getElem?_eq_getElem hn] using hx
  have hb := h.root_le heap hn ⟨i, by simpa [BinaryHeap.size] using hi⟩
  change heap.arr[0] ≤ heap.arr[i] at hb
  have hiy' : heap.arr[i] = y := by simpa only [Array.getElem_toList] using hiy
  simpa only [hx0, hiy'] using hb

private theorem extractTrace_values_perm (heap : BinaryHeap α minLt) :
    ((extractTrace heap).map ExtractStep.value).Perm heap.arr.toList := by
  fun_induction extractTrace heap with
  | case1 heap hx =>
    have : heap.arr = #[] := by simpa [BinaryHeap.max] using hx
    simp [this]
  | case2 heap x hx _ ih =>
    exact (ih.cons x).trans (popMax_perm heap hx)

theorem extractTrace_sorted (heap : BinaryHeap α minLt) (h : HeapOrdered heap) :
    ((extractTrace heap).map ExtractStep.value).Pairwise (· ≤ ·) := by
  fun_induction extractTrace heap with
  | case1 => exact .nil
  | case2 heap x hx _ ih =>
    simp only [List.map_cons, List.pairwise_cons]
    exact ⟨fun y hy => root_le_remaining heap h hx y
      ((extractTrace_values_perm heap.popMax).mem_iff.mp hy), ih (popMax_ordered heap h)⟩

theorem heapSortResult_sorted (xs : List α) :
    (heapSortResult xs).Pairwise (· ≤ ·) := by
  rw [← heapSortTrace_values]
  exact extractTrace_sorted (initialHeap xs) (initialHeap_ordered xs)

/-- The output is an ordered rearrangement of the input. -/
theorem heapSortResult_correct (xs : List α) :
    (heapSortResult xs).Pairwise (· ≤ ·) ∧ (heapSortResult xs).Perm xs :=
  ⟨heapSortResult_sorted xs, heapSortResult_perm xs⟩

end Order

end LeanSort.Heap
