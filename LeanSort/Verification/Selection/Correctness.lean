import LeanSort.Verification.Selection.Equations
import LeanSort.Model.SortingResult

/-! # Correctness of selection sort -/

namespace LeanSort.Selection

open List

/-! ## The selected minimum -/

theorem argmin?_eq_none {α : Type*} [LinearOrder α] (xs : List α) :
    argmin? xs = none ↔ xs = [] := by
  cases xs with
  | nil => simp
  | cons x xs =>
      rw [argmin?_cons]
      cases h : argmin? xs with
      | none => simp
      | some pair =>
          simp only
          split <;> simp

/-- The pair returned by `argmin?` consists of a valid index, the value at that
index, and a value no greater than any entry of the input. -/
theorem argmin?_spec {α : Type*} [LinearOrder α] :
    ∀ (xs : List α) (i : ℕ) (m : α), argmin? xs = some (i, m) →
      i < xs.length ∧ xs[i]? = some m ∧ ∀ z ∈ xs, m ≤ z := by
  intro xs
  induction xs with
  | nil =>
      intro i m h
      simp at h
  | cons x xs ih =>
      intro i m h
      rw [argmin?_cons] at h
      cases htail : argmin? xs with
      | none =>
          have hnil : xs = [] := (argmin?_eq_none xs).mp htail
          subst xs
          simp at h
          obtain ⟨rfl, rfl⟩ := h
          simp
      | some pair =>
          obtain ⟨j, value⟩ := pair
          have hs := ih j value htail
          rcases hs with ⟨hj, hget, hmin⟩
          by_cases hx : x ≤ value
          · simp [htail, hx] at h
            obtain ⟨rfl, rfl⟩ := h
            refine ⟨by simp, by simp, ?_⟩
            intro z hz
            rcases List.mem_cons.mp hz with hzx | hz
            · rw [hzx]
            · exact hx.trans (hmin z hz)
          · simp [htail, hx] at h
            obtain ⟨rfl, rfl⟩ := h
            refine ⟨by simp [hj], by simpa using hget, ?_⟩
            intro z hz
            rcases List.mem_cons.mp hz with hzx | hz
            · rw [hzx]
              exact le_of_not_ge hx
            · exact hmin z hz

/-- Every earlier position is strictly larger than the selected value.
This proves the advertised leftmost tie policy, not just minimality. -/
theorem argmin?_leftmost {α : Type*} [LinearOrder α] (xs : List α) :
    ∀ i m, argmin? xs = some (i, m) →
      ∀ j, j < i → ∀ z, xs[j]? = some z → m < z := by
  induction xs with
  | nil => simp
  | cons x xs ih =>
      intro i m h j hj z hz
      rw [argmin?_cons] at h
      cases ht : argmin? xs with
      | none =>
          simp only [ht, Option.some.injEq, Prod.mk.injEq] at h
          omega
      | some pair =>
          obtain ⟨k, v⟩ := pair
          by_cases hx : x ≤ v
          · simp [ht, hx] at h
            omega
          · simp [ht, hx] at h
            obtain ⟨rfl, rfl⟩ := h
            cases j with
            | zero =>
                simp at hz
                subst z
                exact lt_of_not_ge hx
            | succ j =>
                exact ih k v ht j (by omega) z (by simpa using hz)

/-- A minimum is a valid selected occurrence; no earlier occurrence can tie it. -/
structure MinimumSpec {α : Type*} [LinearOrder α] (xs : List α) (i : ℕ) (m : α) : Prop where
  index_lt : i < xs.length
  value_at : xs[i]? = some m
  minimal : ∀ z ∈ xs, m ≤ z
  leftmost : ∀ j, j < i → ∀ z, xs[j]? = some z → m < z

theorem argmin?_minimumSpec {α : Type*} [LinearOrder α] (xs : List α)
    (i : ℕ) (m : α) (h : argmin? xs = some (i, m)) : MinimumSpec xs i m :=
  ⟨(argmin?_spec xs i m h).1, (argmin?_spec xs i m h).2.1,
    (argmin?_spec xs i m h).2.2, argmin?_leftmost xs i m h⟩

theorem MinimumSpec.unique {α : Type*} [LinearOrder α] {xs : List α}
    {i j : ℕ} {m n : α} (h : MinimumSpec xs i m) (k : MinimumSpec xs j n) :
    i = j ∧ m = n := by
  have he : m = n := le_antisymm
    (h.minimal n (List.mem_of_getElem? k.value_at))
    (k.minimal m (List.mem_of_getElem? h.value_at))
  subst n
  refine ⟨?_, rfl⟩
  rcases lt_trichotomy i j with hij | hij | hij
  · exact False.elim ((lt_irrefl m) (k.leftmost i hij m h.value_at))
  · exact hij
  · exact False.elim ((lt_irrefl m) (h.leftmost j hij m k.value_at))

/-- The independent minimum contract characterizes exactly the executable choice. -/
theorem argmin?_iff_minimumSpec {α : Type*} [LinearOrder α]
    (xs : List α) (i : ℕ) (m : α) :
    argmin? xs = some (i, m) ↔ MinimumSpec xs i m := by
  refine ⟨argmin?_minimumSpec xs i m, ?_⟩
  intro hs
  cases ha : argmin? xs with
  | none =>
      have he := (argmin?_eq_none xs).mp ha
      have hb := hs.index_lt
      simp [he] at hb
  | some pair =>
      obtain ⟨j, n⟩ := pair
      obtain ⟨rfl, rfl⟩ := hs.unique (argmin?_minimumSpec xs j n ha)
      rfl

theorem minIdx_lt {α : Type*} [LinearOrder α] (x : α) (xs : List α) :
    minIdx (x :: xs) < (x :: xs).length := by
  cases h : argmin? (x :: xs) with
  | none => have := (argmin?_eq_none _).mp h; simp at this
  | some pair =>
      simpa [minIdx, h] using (argmin?_spec _ pair.1 pair.2 h).1

/-- Exchanging the head with any position preserves the input multiset. -/
theorem swapHeadAt_perm {α : Type*} (i : ℕ) (x : α) (xs : List α) :
    (swapHeadAt i x xs).1 :: (swapHeadAt i x xs).2 ~ x :: xs := by
  cases i with
  | zero => simp
  | succ i =>
      rw [swapHeadAt_succ]
      cases h : xs[i]? with
      | none => simp
      | some y =>
          simpa [h] using List.getD_set_perm_cons xs i x

/-- Swapping at `minIdx` places a minimum of the original list at the head. -/
theorem swapHeadAt_minIdx_minimal {α : Type*} [LinearOrder α]
    (x : α) (xs : List α) :
    ∀ z ∈ x :: xs, (swapHeadAt (minIdx (x :: xs)) x xs).1 ≤ z := by
  cases harg : argmin? (x :: xs) with
  | none =>
      have hnil := (argmin?_eq_none (x :: xs)).mp harg
      simp at hnil
  | some pair =>
      obtain ⟨i, m⟩ := pair
      have hs := argmin?_spec (x :: xs) i m harg
      rcases hs with ⟨hi, hget, hmin⟩
      have hidx : minIdx (x :: xs) = i := by simp [minIdx, harg]
      rw [hidx]
      intro z hz
      cases i with
      | zero =>
          simp at hget
          subst m
          exact hmin z hz
      | succ i =>
          simp only [getElem?_cons_succ] at hget
          simpa [swapHeadAt_succ, hget] using hmin z hz

/-! ## Recursive sorting -/

/-- The first component of a nonempty selection round is independent of whether
the selected swap is recorded in the trace. -/
theorem sortAuxTr_fst_succ_cons {α : Type*} [LinearOrder α]
    (fuel off : ℕ) (x : α) (xs : List α) :
    (sortAuxTr (fuel + 1) off (x :: xs)).1 =
      (swapHeadAt (minIdx (x :: xs)) x xs).1 ::
        (sortAuxTr fuel (off + 1)
          (swapHeadAt (minIdx (x :: xs)) x xs).2).1 := by
  rw [sortAuxTr_succ_cons]
  dsimp only
  split <;> rfl

theorem sortAuxTr_fst_perm {α : Type*} [LinearOrder α] (fuel off : ℕ)
    (xs : List α) :
    (sortAuxTr fuel off xs).1 ~ xs := by
  induction fuel generalizing off xs with
  | zero => simp
  | succ fuel ih =>
      cases xs with
      | nil => simp
      | cons x xs =>
          rw [sortAuxTr_fst_succ_cons]
          exact (ih (off + 1)
            (swapHeadAt (minIdx (x :: xs)) x xs).2).cons _ |>.trans
              (swapHeadAt_perm (minIdx (x :: xs)) x xs)

theorem sorted_sortAuxTr_of_length_le {α : Type*} [LinearOrder α] :
    ∀ (fuel off : ℕ) (xs : List α), xs.length ≤ fuel →
      (sortAuxTr fuel off xs).1.Pairwise (· ≤ ·) := by
  intro fuel
  induction fuel with
  | zero =>
      intro off xs hlength
      have hnil : xs = [] := List.length_eq_zero_iff.mp
        (Nat.eq_zero_of_le_zero hlength)
      subst xs
      simp
  | succ fuel ih =>
      intro off xs hlength
      cases xs with
      | nil => simp
      | cons x xs =>
          rw [sortAuxTr_fst_succ_cons]
          apply List.Pairwise.cons
          · intro z hz
            have hrecPerm := sortAuxTr_fst_perm fuel (off + 1)
              (swapHeadAt (minIdx (x :: xs)) x xs).2
            have hzTail : z ∈ (swapHeadAt (minIdx (x :: xs)) x xs).2 :=
              hrecPerm.mem_iff.mp hz
            have hswapPerm := swapHeadAt_perm (minIdx (x :: xs)) x xs
            apply swapHeadAt_minIdx_minimal x xs z
            exact hswapPerm.mem_iff.mp (by simp [hzTail])
          · apply ih (off + 1)
            have htailLength :
                (swapHeadAt (minIdx (x :: xs)) x xs).2.length = xs.length := by
              have hswapPerm := swapHeadAt_perm (minIdx (x :: xs)) x xs
              simpa using hswapPerm.length_eq
            rw [htailLength]
            exact Nat.le_of_succ_le_succ hlength

/-- The first `k` entries are ordered and no larger than any unprocessed entry.
If `k` exceeds the length, the entire list is the settled prefix. -/
def SettledPrefix {α : Type*} [LinearOrder α] (k : ℕ) (xs : List α) : Prop :=
  (xs.take k).Pairwise (· ≤ ·) ∧
    ∀ a ∈ xs.take k, ∀ b ∈ xs.drop k, a ≤ b

/-- Even a fuel-limited run settles its entire processed prefix. -/
theorem sortAuxTr_settled {α : Type*} [LinearOrder α] (fuel off : ℕ) (xs : List α) :
    SettledPrefix fuel (sortAuxTr fuel off xs).1 := by
  induction fuel generalizing off xs with
  | zero => simp [SettledPrefix]
  | succ fuel ih =>
      cases xs with
      | nil => simp [SettledPrefix]
      | cons x xs =>
          let moved := swapHeadAt (minIdx (x :: xs)) x xs
          let rest := (sortAuxTr fuel (off + 1) moved.2).1
          have hs := ih (off + 1) moved.2
          have hm : ∀ z ∈ rest, moved.1 ≤ z := by
            intro z hz
            have ht := (sortAuxTr_fst_perm fuel (off + 1) moved.2).mem_iff.mp hz
            have hi := (swapHeadAt_perm (minIdx (x :: xs)) x xs).mem_iff.mp
              (show z ∈ moved.1 :: moved.2 from List.mem_cons_of_mem _ ht)
            exact swapHeadAt_minIdx_minimal x xs z hi
          rw [sortAuxTr_fst_succ_cons]
          change SettledPrefix (fuel + 1) (moved.1 :: rest)
          change (rest.take fuel).Pairwise (· ≤ ·) ∧
            (∀ a ∈ rest.take fuel, ∀ b ∈ rest.drop fuel, a ≤ b) at hs
          simp only [SettledPrefix, List.take_succ_cons, List.drop_succ_cons,
            List.pairwise_cons]
          refine ⟨⟨?_, hs.1⟩, ?_⟩
          · intro z hz
            exact hm z (List.mem_of_mem_take hz)
          · intro a ha b hb
            rcases List.mem_cons.mp ha with rfl | ha
            · exact hm b (List.mem_of_mem_drop hb)
            · exact hs.2 a ha b hb

/-- The number of settled entries is exactly the smaller of fuel and input size. -/
theorem sortAuxTr_settled_length {α : Type*} [LinearOrder α]
    (fuel off : ℕ) (xs : List α) :
    ((sortAuxTr fuel off xs).1.take fuel).length = min fuel xs.length := by
  rw [List.length_take, (sortAuxTr_fst_perm fuel off xs).length_eq]

/-! ## Output correctness -/

theorem selectionSortResult_perm {α : Type*} [LinearOrder α] (xs : List α) :
    selectionSortResult xs ~ xs := by
  exact sortAuxTr_fst_perm xs.length 0 xs

theorem sorted_selectionSortResult {α : Type*} [LinearOrder α] (xs : List α) :
    (selectionSortResult xs).Pairwise (· ≤ ·) := by
  exact sorted_sortAuxTr_of_length_le xs.length 0 xs le_rfl

theorem selectionSortResult_spec {α : Type*} [LinearOrder α] (xs : List α) :
    IsSortingResult (· ≤ ·) xs (selectionSortResult xs) :=
  ⟨sorted_selectionSortResult xs, selectionSortResult_perm xs⟩

end LeanSort.Selection
