import LeanSort.Model.SortingResult
import LeanSort.Verification.Bubble.Equations

namespace LeanSort.Bubble

open List

/-! ### Preservation of the input multiset -/

theorem passAuxTr_fst_perm {α : Type*} [LinearOrder α] (off : ℕ) (x : α)
    (xs : List α) :
    (passAuxTr off x xs).1 ~ x :: xs := by
  induction xs generalizing off x with
  | nil => simp
  | cons y ys ih =>
      by_cases h : x ≤ y
      · rw [passAuxTr_cons_of_le h]
        exact (ih (off + 1) y).cons x
      · rw [passAuxTr_cons_of_gt h]
        exact ((ih (off + 1) x).cons y).trans (Perm.swap y x ys).symm

theorem passTr_fst_perm {α : Type*} [LinearOrder α] (off : ℕ) (xs : List α) :
    (passTr off xs).1 ~ xs := by
  cases xs with
  | nil => simp
  | cons x xs => exact passAuxTr_fst_perm off x xs

theorem sortAuxTr_fst_perm {α : Type*} [LinearOrder α] (passes : ℕ)
    (xs : List α) :
    (sortAuxTr passes xs).1 ~ xs := by
  induction passes generalizing xs with
  | zero => simp
  | succ passes ih =>
      rw [sortAuxTr_succ]
      exact (ih (passTr 0 xs).1).trans (passTr_fst_perm 0 xs)

theorem bubbleSortResult_perm {α : Type*} [LinearOrder α] (xs : List α) :
    bubbleSortResult xs ~ xs :=
  sortAuxTr_fst_perm xs.length xs

/-! ### One pass moves a maximum to the end -/

theorem passAuxTr_fst_decompose {α : Type*} [LinearOrder α] (off : ℕ) (x : α)
    (xs : List α) :
    ∃ front maximum,
      (passAuxTr off x xs).1 = front ++ [maximum] ∧
      front.length = xs.length ∧
      ∀ z ∈ x :: xs, z ≤ maximum := by
  induction xs generalizing off x with
  | nil =>
      exact ⟨[], x, rfl, rfl, by simp⟩
  | cons y ys ih =>
      by_cases hxy : x ≤ y
      · obtain ⟨front, maximum, hresult, hlength, hmax⟩ :=
          ih (off + 1) y
        refine ⟨x :: front, maximum, ?_, by simp [hlength], ?_⟩
        · rw [passAuxTr_cons_of_le hxy, hresult]
          rfl
        · intro z hz
          simp only [mem_cons] at hz
          rcases hz with hxz | hyz | hz
          · subst z
            exact hxy.trans (hmax y (by simp))
          · subst z
            exact hmax y (by simp)
          · exact hmax z (by simp [hz])
      · obtain ⟨front, maximum, hresult, hlength, hmax⟩ :=
          ih (off + 1) x
        refine ⟨y :: front, maximum, ?_, by simp [hlength], ?_⟩
        · rw [passAuxTr_cons_of_gt hxy, hresult]
          rfl
        · intro z hz
          simp only [mem_cons] at hz
          rcases hz with hxz | hyz | hz
          · subst z
            exact hmax x (by simp)
          · subst z
            exact (le_of_not_ge hxy).trans (hmax x (by simp))
          · exact hmax z (by simp [hz])

/-! A maximal final element is unaffected by later full passes. -/

theorem passAuxTr_fst_append_of_le {α : Type*} [LinearOrder α]
    (off : ℕ) (x maximum : α) (xs : List α)
    (hx : x ≤ maximum) (hxs : ∀ z ∈ xs, z ≤ maximum) :
    (passAuxTr off x (xs ++ [maximum])).1 =
      (passAuxTr off x xs).1 ++ [maximum] := by
  induction xs generalizing off x with
  | nil =>
      simp only [nil_append]
      rw [passAuxTr_cons_of_le hx]
      rfl
  | cons y ys ih =>
      have hy : y ≤ maximum := hxs y (by simp)
      have hys : ∀ z ∈ ys, z ≤ maximum := by
        intro z hz
        exact hxs z (by simp [hz])
      by_cases hxy : x ≤ y
      · change (passAuxTr off x (y :: (ys ++ [maximum]))).1 =
            (passAuxTr off x (y :: ys)).1 ++ [maximum]
        rw [passAuxTr_cons_of_le hxy, passAuxTr_cons_of_le hxy,
          ih (off + 1) y hy hys]
        simp
      · change (passAuxTr off x (y :: (ys ++ [maximum]))).1 =
            (passAuxTr off x (y :: ys)).1 ++ [maximum]
        rw [passAuxTr_cons_of_gt hxy, passAuxTr_cons_of_gt hxy,
          ih (off + 1) x hx hys]
        simp

theorem passTr_fst_append_maximum {α : Type*} [LinearOrder α]
    (off : ℕ) (xs : List α) (maximum : α)
    (hmax : ∀ z ∈ xs, z ≤ maximum) :
    (passTr off (xs ++ [maximum])).1 = (passTr off xs).1 ++ [maximum] := by
  cases xs with
  | nil => rfl
  | cons x xs =>
      exact passAuxTr_fst_append_of_le off x maximum xs
        (hmax x (by simp)) (by
          intro z hz
          exact hmax z (by simp [hz]))

theorem sortAuxTr_fst_append_maximum {α : Type*} [LinearOrder α]
    (passes : ℕ) (xs : List α) (maximum : α)
    (hmax : ∀ z ∈ xs, z ≤ maximum) :
    (sortAuxTr passes (xs ++ [maximum])).1 =
      (sortAuxTr passes xs).1 ++ [maximum] := by
  induction passes generalizing xs with
  | zero => rfl
  | succ passes ih =>
      rw [sortAuxTr_succ, sortAuxTr_succ,
        passTr_fst_append_maximum 0 xs maximum hmax]
      apply ih
      intro z hz
      exact hmax z ((passTr_fst_perm 0 xs).mem_iff.mp hz)

/-! ### Sortedness -/

theorem sorted_sortAuxTr_of_length_le {α : Type*} [LinearOrder α] :
    ∀ (passes : ℕ) (xs : List α), xs.length ≤ passes →
      (sortAuxTr passes xs).1.Pairwise (· ≤ ·) := by
  intro passes
  induction passes with
  | zero =>
      intro xs hlength
      have : xs = [] := length_eq_zero_iff.mp (Nat.eq_zero_of_le_zero hlength)
      subst xs
      simp
  | succ passes ih =>
      intro xs hlength
      cases xs with
      | nil =>
          rw [sortAuxTr_succ]
          exact ih [] (Nat.zero_le passes)
      | cons x xs =>
          obtain ⟨front, maximum, hpass, hfrontLength, hmaximum⟩ :=
            passAuxTr_fst_decompose 0 x xs
          have hfrontMaximum : ∀ z ∈ front, z ≤ maximum := by
            intro z hz
            apply hmaximum z
            apply (passAuxTr_fst_perm 0 x xs).mem_iff.mp
            rw [hpass]
            exact mem_append_left [maximum] hz
          have hpLength : front.length ≤ passes := by
            rw [hfrontLength]
            exact Nat.le_of_succ_le_succ hlength
          have hpSorted := ih front hpLength
          have hpMaximum : ∀ z ∈ (sortAuxTr passes front).1, z ≤ maximum := by
            intro z hz
            exact hfrontMaximum z ((sortAuxTr_fst_perm passes front).mem_iff.mp hz)
          rw [sortAuxTr_succ, passTr_cons, hpass,
            sortAuxTr_fst_append_maximum passes front maximum hfrontMaximum]
          exact pairwise_append.mpr ⟨hpSorted, pairwise_singleton _ maximum, by
            intro a ha b hb
            simp only [mem_singleton] at hb
            subst b
            exact hpMaximum a ha⟩

theorem sorted_bubbleSortResult {α : Type*} [LinearOrder α] (xs : List α) :
    (bubbleSortResult xs).Pairwise (· ≤ ·) :=
  sorted_sortAuxTr_of_length_le xs.length xs le_rfl

/-- Bubble sort returns a sorted permutation of its input. -/
theorem bubbleSortResult_spec {α : Type*} [LinearOrder α] (xs : List α) :
    IsSortingResult (· ≤ ·) xs (bubbleSortResult xs) :=
  ⟨sorted_bubbleSortResult xs, bubbleSortResult_perm xs⟩

end LeanSort.Bubble
