import LeanSort.Algorithm.Counting

/-! Computation rules and size invariants for the histogram implementation. -/

namespace LeanSort.Counting

/-- A valid update preserves the allocation and adds one only to the selected bucket. -/
structure IncrementSpec (before after : Array ℕ) (key : ℕ) : Prop where
  size_eq : after.size = before.size
  buckets : ∀ query, after[query]?.getD 0 =
    before[query]?.getD 0 + if query = key then 1 else 0

theorem increment_spec (counts : Array ℕ) (key : ℕ) (hkey : key < counts.size) :
    IncrementSpec counts (increment counts key) key := by
  refine ⟨Array.size_modify, ?_⟩
  intro query
  by_cases h : query = key
  · subst query
    simp [increment, Array.getElem?_modify, Array.getElem?_eq_getElem hkey]
  · simp [increment, Array.getElem?_modify, h, Ne.symm h]

theorem incrementBounded_spec (counts : Array ℕ) (key : BucketIndex counts.size) :
    IncrementSpec counts (incrementBounded counts key) key.val :=
  increment_spec counts key.val key.isLt

/-- The state transition is a valid increment and its event reports the new count. -/
theorem countStep_spec (counts : Array ℕ) (key : ℕ) (hkey : key < counts.size) :
    IncrementSpec counts ((countStep key).run counts).2 key ∧
      ((countStep key).run counts).1 = ⟨key, counts[key]?.getD 0 + 1⟩ := by
  refine ⟨increment_spec counts key hkey, ?_⟩
  change (⟨key, (increment counts key)[key]?.getD 0⟩ : CountStep) = _
  congr 1
  simpa using (increment_spec counts key hkey).buckets key

theorem histogramFold_size (xs : List ℕ) (counts : Array ℕ) :
    (xs.foldl (fun counts x => counts.modify x (· + 1)) counts).size = counts.size :=
  List.foldlRecOn (motive := fun cs : Array ℕ => cs.size = counts.size) xs _ rfl
    fun _ h _ _ => Array.size_modify.trans h

@[simp] theorem histogram_size (xs : List ℕ) : (histogram xs).size = keyRange xs := by
  simp [histogram, histogramFold_size]

@[simp] theorem histogram_nil : histogram [] = #[0] := rfl

@[simp] theorem countingSortResult_nil : countingSortResult [] = [] := rfl

theorem countingSortResult_eq (xs : List ℕ) :
    countingSortResult xs = (List.range (keyRange xs)).flatMap
      (fun key => List.replicate ((histogram xs)[key]?.getD 0) key) := by
  simp [countingSortResult, histogramOutput]

@[simp] theorem histogramTraceAux_nil (counts : Array ℕ) :
    histogramTraceAux [] counts = (counts, []) := rfl

theorem histogramTraceAux_cons (x : ℕ) (xs : List ℕ) (counts : Array ℕ) :
    histogramTraceAux (x :: xs) counts =
      let next := counts.modify x (· + 1)
      let rest := histogramTraceAux xs next
      (rest.1, ⟨x, next[x]?.getD 0⟩ :: rest.2) := by
  simp only [histogramTraceAux, List.mapM_cons]
  rfl

@[simp] theorem countingSortTrace_nil : countingSortTrace [] = [] := rfl

end LeanSort.Counting
