import LeanSort.Model.SortingResult
import LeanSort.Verification.Bubble.Equations
import Mathlib.Data.List.Induction

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

/-- A full pass preserves a sorted suffix that dominates the unfinished prefix. -/
theorem passTr_fst_append_sorted_suffix {α : Type*} [LinearOrder α]
    (off : ℕ) (front suffix : List α) (hs : suffix.Pairwise (· ≤ ·))
    (hcross : ∀ a ∈ front, ∀ b ∈ suffix, a ≤ b) :
    (passTr off (front ++ suffix)).1 = (passTr off front).1 ++ suffix := by
  revert hs hcross
  induction suffix using List.reverseRecOn with
  | nil => simp
  | append_singleton suffix maximum ih =>
      intro hs hcross
      obtain ⟨hs, _, hlast⟩ := List.pairwise_append.mp hs
      have hmax : ∀ z ∈ front ++ suffix, z ≤ maximum := by
        intro z hz
        rcases List.mem_append.mp hz with hz | hz
        · exact hcross z hz maximum (by simp)
        · exact hlast z hz maximum (by simp)
      rw [← List.append_assoc, passTr_fst_append_maximum off (front ++ suffix) maximum hmax,
        ih hs (fun a ha b hb => hcross a ha b (by simp [hb])), List.append_assoc]

/-- At most `remaining` entries are unfinished. The suffix is sorted and dominates
every entry of the unfinished prefix. -/
def SettledSuffix {α : Type*} [LinearOrder α] (xs : List α) (remaining : ℕ) : Prop :=
  ∃ front suffix, xs = front ++ suffix ∧ front.length ≤ remaining ∧
    suffix.Pairwise (· ≤ ·) ∧ ∀ a ∈ front, ∀ b ∈ suffix, a ≤ b

theorem settledSuffix_initial {α : Type*} [LinearOrder α] (xs : List α) :
    SettledSuffix xs xs.length :=
  ⟨xs, [], by simp, le_rfl, by simp, by simp⟩

theorem settledSuffix_zero {α : Type*} [LinearOrder α] {xs : List α}
    (h : SettledSuffix xs 0) : xs.Pairwise (· ≤ ·) := by
  obtain ⟨front, suffix, rfl, hfront, hs, _⟩ := h
  have hempty : front = [] := List.length_eq_zero_iff.mp (Nat.eq_zero_of_le_zero hfront)
  simpa [hempty] using hs

/-- Each pass settles one more entry; an already settled list stays settled. -/
theorem settledSuffix_passTr {α : Type*} [LinearOrder α] (off : ℕ) (xs : List α)
    (remaining : ℕ) (h : SettledSuffix xs remaining) :
    SettledSuffix (passTr off xs).1 (remaining - 1) := by
  obtain ⟨front, suffix, rfl, hsize, hs, hcross⟩ := h
  cases front with
  | nil =>
      refine ⟨[], suffix, ?_, by simp, hs, by simp⟩
      simpa using passTr_fst_append_sorted_suffix off [] suffix hs hcross
  | cons x front =>
      obtain ⟨next, maximum, hout, hlength, hmax⟩ := passAuxTr_fst_decompose off x front
      have hmem : ∀ a ∈ next, a ∈ x :: front := by
        intro a ha
        apply (passAuxTr_fst_perm off x front).mem_iff.mp
        rw [hout]
        exact List.mem_append_left _ ha
      have hm : maximum ∈ x :: front := by
        apply (passAuxTr_fst_perm off x front).mem_iff.mp
        simp [hout]
      refine ⟨next, maximum :: suffix, ?_, ?_, ?_, ?_⟩
      · rw [passTr_fst_append_sorted_suffix off (x :: front) suffix hs hcross,
          passTr_cons, hout]
        simp
      · simp only [List.length_cons] at hsize
        omega
      · exact List.pairwise_cons.mpr ⟨hcross maximum hm, hs⟩
      · intro a ha b hb
        rcases List.mem_cons.mp hb with rfl | hb
        · exact hmax a (hmem a ha)
        · exact hcross a (hmem a ha) b hb

/-- Repeated passes reduce the unfinished-prefix bound by the number of passes. -/
theorem settledSuffix_sortAuxTr {α : Type*} [LinearOrder α] (passes : ℕ)
    (xs : List α) (remaining : ℕ) (h : SettledSuffix xs remaining) :
    SettledSuffix (sortAuxTr passes xs).1 (remaining - passes) := by
  induction passes generalizing xs remaining with
  | zero => simpa using h
  | succ passes ih =>
      rw [sortAuxTr_succ]
      simpa [Nat.sub_sub, Nat.add_comm] using
        ih (passTr 0 xs).1 (remaining - 1) (settledSuffix_passTr 0 xs remaining h)

theorem sorted_sortAuxTr_of_length_le {α : Type*} [LinearOrder α] :
    ∀ (passes : ℕ) (xs : List α), xs.length ≤ passes →
      (sortAuxTr passes xs).1.Pairwise (· ≤ ·) := by
  intro passes xs hlength
  apply settledSuffix_zero
  simpa [Nat.sub_eq_zero_of_le hlength] using
    settledSuffix_sortAuxTr passes xs xs.length (settledSuffix_initial xs)

theorem sorted_bubbleSortResult {α : Type*} [LinearOrder α] (xs : List α) :
    (bubbleSortResult xs).Pairwise (· ≤ ·) :=
  sorted_sortAuxTr_of_length_le xs.length xs le_rfl

/-- Bubble sort returns a sorted permutation of its input. -/
theorem bubbleSortResult_spec {α : Type*} [LinearOrder α] (xs : List α) :
    IsSortingResult (· ≤ ·) xs (bubbleSortResult xs) :=
  ⟨sorted_bubbleSortResult xs, bubbleSortResult_perm xs⟩

end LeanSort.Bubble
