import LeanSort.Model.SortingResult
import LeanSort.Verification.Counting.Equations
import LeanSort.Verification.Shared.MaxKey

/-!
Complete correctness of histogram-based counting sort: every bucket equals the
input multiplicity, expansion preserves all elements, and the output is ordered.
-/

namespace LeanSort.Counting

theorem sorted_histogramOutput (counts : Array ℕ) :
    (histogramOutput counts).Pairwise (· ≤ ·) := by
  unfold histogramOutput
  refine List.pairwise_flatMap.mpr ⟨by simp, List.pairwise_le_range.imp ?_⟩
  intro a b hab x hx y hy
  simpa only [(List.mem_replicate.mp hx).2, (List.mem_replicate.mp hy).2] using hab

theorem sorted_countingSortResult (xs : List ℕ) :
    (countingSortResult xs).Pairwise (· ≤ ·) := sorted_histogramOutput (histogram xs)

theorem mem_lt_keyRange (xs : List ℕ) (x : ℕ) (hx : x ∈ xs) : x < keyRange xs :=
  Nat.lt_succ_of_le (mem_le_foldl_max xs 0 x hx)

/-- The processed input fits the allocation, and every bucket is its exact multiplicity. -/
structure HistogramSpec (width : ℕ) (processed : List ℕ) (counts : Array ℕ) : Prop where
  size_eq : counts.size = width
  keys_lt : ∀ key ∈ processed, key < width
  multiplicity : ∀ key, counts[key]?.getD 0 = processed.count key

theorem histogramSpec_empty (width : ℕ) :
    HistogramSpec width [] (Array.replicate width 0) := by
  refine ⟨Array.size_replicate, by simp, ?_⟩
  intro key
  by_cases h : key < width <;> simp [h]

/-- Processing one more key preserves the histogram invariant. -/
theorem HistogramSpec.extend {width : ℕ} {processed : List ℕ} {counts : Array ℕ}
    (h : HistogramSpec width processed counts) (key : ℕ) (hkey : key < width) :
    HistogramSpec width (processed ++ [key]) (increment counts key) := by
  have hstep := increment_spec counts key (by simpa [h.size_eq] using hkey)
  refine ⟨hstep.size_eq.trans h.size_eq, ?_, ?_⟩
  · intro x hx
    rcases List.mem_append.mp hx with hx | hx
    · exact h.keys_lt x hx
    · rcases List.mem_singleton.mp hx with rfl
      exact hkey
  · intro query
    rw [hstep.buckets, h.multiplicity, List.count_append]
    by_cases hquery : query = key
    · simp [hquery]
    · simp [hquery, Ne.symm hquery]

/-- The fold extends the processed prefix while maintaining its exact histogram. -/
theorem HistogramSpec.fold {width : ℕ} {processed : List ℕ} {counts : Array ℕ}
    (h : HistogramSpec width processed counts) (xs : List ℕ)
    (hxs : ∀ key ∈ xs, key < width) :
    HistogramSpec width (processed ++ xs) (xs.foldl increment counts) := by
  induction xs generalizing processed counts with
  | nil => simpa using h
  | cons x xs ih =>
      simpa [List.foldl_cons, List.append_assoc] using
        ih (h.extend x (hxs x (by simp))) (fun key hk => hxs key (by simp [hk]))

theorem histogram_spec (xs : List ℕ) : HistogramSpec (keyRange xs) xs (histogram xs) := by
  simpa [histogram] using
    (histogramSpec_empty (keyRange xs)).fold xs (mem_lt_keyRange xs)

theorem histogramFold_get (xs : List ℕ) (counts : Array ℕ) (key : ℕ)
    (hkey : key < counts.size) (hxs : ∀ x ∈ xs, x < counts.size) :
    (xs.foldl (fun counts x => counts.modify x (· + 1)) counts)[key]?.getD 0 =
      counts[key]?.getD 0 + xs.count key := by
  induction xs generalizing counts with
  | nil => simp
  | cons x xs ih =>
      simp only [List.foldl_cons]
      rw [ih (counts.modify x (· + 1)) (by simpa using hkey)
        (fun y hy => by simpa using hxs y (by simp [hy]))]
      by_cases heq : x = key <;>
        simp [Array.getElem?_modify, Array.getElem?_eq_getElem hkey, heq,
          Nat.add_assoc, Nat.add_comm]

theorem histogram_get (xs : List ℕ) (key : ℕ) :
    (histogram xs)[key]?.getD 0 = xs.count key := (histogram_spec xs).multiplicity key

theorem count_expand_range (counts : ℕ → ℕ) (n key : ℕ) :
    ((List.range n).flatMap (fun x => List.replicate (counts x) x)).count key =
      if key < n then counts key else 0 := by
  induction n with
  | zero => simp
  | succ n ih =>
      simp only [List.range_succ, List.flatMap_append, List.flatMap_cons,
        List.flatMap_nil, List.append_nil, List.count_append, ih, List.count_replicate]
      split_ifs <;> simp_all <;> omega

/-- Expanding any histogram reproduces precisely the count in each bucket. -/
theorem histogramOutput_count (counts : Array ℕ) (key : ℕ) :
    (histogramOutput counts).count key = counts[key]?.getD 0 := by
  rw [histogramOutput, count_expand_range]
  by_cases hkey : key < counts.size <;> simp [hkey]

/-- The expansion phase turns any certified histogram into a sorted permutation. -/
theorem HistogramSpec.output {width : ℕ} {xs : List ℕ} {counts : Array ℕ}
    (h : HistogramSpec width xs counts) :
    IsSortingResult (· ≤ ·) xs (histogramOutput counts) :=
  ⟨sorted_histogramOutput counts,
    List.perm_iff_count.mpr fun key => (histogramOutput_count counts key).trans (h.multiplicity key)⟩

theorem countingSortResult_count (xs : List ℕ) (key : ℕ) :
    (countingSortResult xs).count key = xs.count key :=
  (histogramOutput_count (histogram xs) key).trans (histogram_get xs key)

theorem countingSortResult_perm (xs : List ℕ) : (countingSortResult xs).Perm xs :=
  List.perm_iff_count.mpr (countingSortResult_count xs)

@[simp] theorem countingSortResult_length (xs : List ℕ) :
    (countingSortResult xs).length = xs.length := (countingSortResult_perm xs).length_eq

theorem countingSortResult_spec (xs : List ℕ) :
    IsSortingResult (· ≤ ·) xs (countingSortResult xs) :=
  (histogram_spec xs).output

end LeanSort.Counting
