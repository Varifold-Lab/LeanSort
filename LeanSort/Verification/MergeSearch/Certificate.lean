import LeanSort.Algorithm.MergeSearch.Certificate
import LeanSort.Verification.Direct.Refinement

namespace LeanSort.MergeSearch
open RunAdaptive Comparison

theorem Fits.le (h : Fits s i j) : i ≤ j := by cases h <;> omega

theorem Fits.indices (h : Fits s i j) : s.indices = List.range' i (j-i) := by
  induction h with
  | empty i => simp [Shape.indices]
  | leaf i => simp [Shape.indices, List.range']
  | @node l r i k j hik hkj hl hr il ir =>
      simp only [Shape.indices, il, ir]
      have he : i + (k-i) = k := by omega
      have hn : (k-i) + (j-k) = j-i := by omega
      simpa only [he, hn] using (List.range'_append_1 (s := i) (m := k-i) (n := j-k))

theorem weight_indices (s : Shape) (w : Nat → Nat) :
    s.weight w = (s.indices.map w).sum := by
  induction s <;> simp_all [Shape.weight, Shape.indices]

theorem Fits.weight (h : Fits s i j) (w : Nat → Nat) : s.weight w = mass w i j := by
  rw [weight_indices, h.indices]; rfl

theorem checkFits_sound (s : Shape) (i j : Nat) (h : checkFits s i j = true) : Fits s i j := by
  induction s generalizing i j with
  | empty => simp only [checkFits, decide_eq_true_eq] at h; subst j; exact .empty i
  | leaf a => simp only [checkFits, decide_eq_true_eq] at h; rcases h with ⟨rfl,rfl⟩; exact .leaf _
  | node l r il ir =>
      simp only [checkFits, Bool.and_eq_true, decide_eq_true_eq] at h
      exact .node h.1.1.1 h.1.1.2 (il _ _ h.1.2) (ir _ _ h.2)

theorem lower_sound (h : LowerValid n w d) (hf : Fits s i j) (hj : j ≤ n) :
    d i j ≤ s.budget w := by
  induction hf with
  | empty i => simpa [Shape.budget] using (h.1 ⟨i,by omega⟩).le
  | leaf i => simpa [Shape.budget] using (h.2.1 ⟨i,by omega⟩).le
  | @node l r i k j hik hkj hl hr il ir =>
      have hh := h.2.2 ⟨i,by omega⟩ ⟨k,by omega⟩ ⟨j,by omega⟩ hik hkj
      have hw := (Fits.node hik hkj hl hr).weight w
      have hll := il (by omega)
      have hrr := ir hj
      simp only [Shape.budget, Shape.weight] at *
      omega

theorem checkLower_sound (h : checkLower ls d = true) :
    ∀ s, Fits s 0 ls.length → lookup d 0 ls.length ≤ s.budget (weights ls) := by
  intro s hs
  exact lower_sound (of_decide_eq_true h) hs (by omega)

theorem checkOptimal_sound (h : checkOptimal ls d s = true) :
    Optimal (weights ls) ls.length s := by
  simp only [checkOptimal, Bool.and_eq_true, decide_eq_true_eq] at h
  refine ⟨checkFits_sound _ _ _ h.1.1, ?_⟩
  intro t ht
  rw [h.2]
  exact checkLower_sound h.1.2 t ht

theorem zero_lower (n : Nat) (w : Nat → Nat) : LowerValid n w (fun _ _ => 0) := by
  exact ⟨fun _ => rfl, fun _ => rfl, fun _ _ _ _ _ => Nat.zero_le _⟩

theorem realize_weight (runs : List (List α)) (s : Shape) :
    (realize runs s).weight = s.weight (fun i => (runs[i]?.getD []).length) := by
  induction s <;> simp_all [realize, MergeTree.weight, Shape.weight]

theorem realize_budget (runs : List (List α)) (s : Shape) :
    (realize runs s).budget = s.budget (fun i => (runs[i]?.getD []).length) := by
  induction s <;> simp_all [realize, MergeTree.budget, Shape.budget, realize_weight]

theorem realize_indices (runs : List (List α)) (s : Shape) :
    (realize runs s).leaves = s.indices.map (fun i => runs[i]?.getD []) := by
  induction s <;> simp_all [realize, MergeTree.leaves, Shape.indices]

theorem index_range (xs : List α) (fallback : α) :
    (List.range xs.length).map (fun i => xs[i]?.getD fallback) = xs := by
  apply List.ext_getElem
  · simp
  · intro i hi hj
    simp [List.getElem?_eq_getElem hj]

theorem realize_leaves (runs : List (List α)) (h : Fits s 0 runs.length) :
    (realize runs s).leaves = runs := by
  rw [realize_indices, h.indices]
  simpa [List.range_eq_range'] using index_range runs []

theorem safePlan_leaves (runs : List (List α)) (s : Shape) : (safePlan runs s).leaves = runs := by
  unfold safePlan
  split
  · exact realize_leaves runs (checkFits_sound _ _ _ (by assumption))
  · exact countPlan_leaves runs

theorem safe_correct [LinearOrder α] (s : Shape) {xs : List α} {runs : List (List α)} (h : ValidRuns xs runs) :
    IsSortingResult (· ≤ ·) xs (Direct.tree (safePlan runs s)) := by
  rw [Direct.tree_eq]
  refine ⟨(safePlan runs s).program_sorted ?_, ?_⟩
  · simpa only [safePlan_leaves] using h.2.1
  · simpa only [safePlan_leaves, h.1] using (safePlan runs s).program_perm

theorem safe_cost [LinearOrder α] (runs : List (List α)) (s : Shape) :
    (Direct.treeCounted (safePlan runs s)).time ≤ (safePlan runs s).budget := by
  rw [Direct.tree_counted_eq]
  exact MergeTree.cost_le_budget _

theorem discovered_correct [LinearOrder α] (s : Shape) (xs : List α) :
    IsSortingResult (· ≤ ·) xs (Direct.tree (safePlan (Direct.scan xs) s)) := by
  apply safe_correct
  rw [Direct.scan_eq]
  exact discover_spec xs

theorem discovered_cost [LinearOrder α] (s : Shape) (xs : List α) :
    (Direct.scanCounted xs).time + (Direct.treeCounted (safePlan (Direct.scan xs) s)).time ≤
      xs.length - 1 + (safePlan (Direct.scan xs) s).budget := by
  rw [Direct.scan_counted_eq, discover_cost]
  exact Nat.add_le_add_left (safe_cost _ _) _

end LeanSort.MergeSearch
