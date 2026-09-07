import LeanSort.Algorithm.Counting

/-! Computation rules and size invariants for the histogram implementation. -/

namespace LeanSort.Counting

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
      (rest.1, ⟨x, next[x]?.getD 0⟩ :: rest.2) := rfl

@[simp] theorem countingSortTrace_nil : countingSortTrace [] = [] := rfl

end LeanSort.Counting
