import LeanSort.Verification.Shell.Equations
import LeanSort.Model.SortingResult
import Mathlib.Data.Nat.ModEq

namespace LeanSort.Shell

theorem gapInsert_perm {α : Type*} [LinearOrder α] (gap : ℕ) (xs : Array α) (i : ℕ) :
    (gapInsert gap xs i).Perm xs := by
  fun_induction gapInsert with
  | case1 xs i h _ ih => exact ih.trans (Array.swap_perm h.2.2 (by omega))
  | case2 => exact .refl _
  | case3 => exact .refl _

theorem insertions_perm {α : Type*} [LinearOrder α]
    (gap : ℕ) (indices : List ℕ) (xs : Array α) :
    (indices.foldl (gapInsert gap) xs).Perm xs := by
  induction indices generalizing xs with
  | nil => exact .refl _
  | cons i rest ih => exact (ih (gapInsert gap xs i)).trans (gapInsert_perm gap xs i)

theorem gapPass_perm {α : Type*} [LinearOrder α] (gap : ℕ) (xs : Array α) :
    (gapPass gap xs).Perm xs := insertions_perm gap (List.range xs.size) xs

theorem passes_perm {α : Type*} [LinearOrder α]
    (steps : List ℕ) (xs : Array α) :
    (steps.foldl (fun a gap => gapPass gap a) xs).Perm xs := by
  induction steps generalizing xs with
  | nil => exact .refl _
  | cons gap rest ih => exact (ih (gapPass gap xs)).trans (gapPass_perm gap xs)

theorem shellSortResult_perm {α : Type*} [LinearOrder α] (xs : List α) :
    (shellSortResult xs).Perm xs := by
  simpa [shellSortResult_eq_passes] using
    Array.perm_iff_toList_perm.mp (passes_perm (gaps (xs.length / 2)) xs.toArray)

@[simp] theorem gapInsert_size {α : Type*} [LinearOrder α] (gap : ℕ) (xs : Array α) (i : ℕ) :
    (gapInsert gap xs i).size = xs.size := (gapInsert_perm gap xs i).size_eq

@[simp] theorem gapPass_size {α : Type*} [LinearOrder α] (gap : ℕ) (xs : Array α) :
    (gapPass gap xs).size = xs.size := (gapPass_perm gap xs).size_eq

/-- Each gap-separated column is ordered within the processed prefix. -/
def GapSorted {α : Type*} [LinearOrder α] (gap stop : ℕ) (xs : Array α) : Prop :=
  ∀ a b (ha : a < xs.size) (hb : b < xs.size),
    a < b → b < stop → a % gap = b % gap → xs[a] ≤ xs[b]

/-- During insertion, only comparisons ending at the moving entry may be unordered. -/
def GapSortedExcept {α : Type*} [LinearOrder α]
    (gap stop hole : ℕ) (xs : Array α) : Prop :=
  ∀ a b (ha : a < xs.size) (hb : b < xs.size),
    a < b → b < stop → a % gap = b % gap → b ≠ hole → xs[a] ≤ xs[b]

private theorem column_distance {a b gap : ℕ} (hab : a < b)
    (hmod : a % gap = b % gap) : a + gap ≤ b := by
  have hd : gap ∣ b - a := Nat.ModEq.dvd' hmod
  have := Nat.le_of_dvd (by omega : 0 < b - a) hd
  omega

private theorem pred_mod {gap i : ℕ} (h : gap ≤ i) : (i - gap) % gap = i % gap := by
  have he := congrArg (fun n => n % gap) (Nat.sub_add_cancel h)
  simpa using he

private theorem swap_preserves_except {α : Type*} [LinearOrder α]
    (gap stop i : ℕ) (xs : Array α) (hg : 0 < gap) (hgi : gap ≤ i)
    (hi : i < xs.size) (his : i < stop)
    (h : GapSortedExcept gap stop i xs) (hlt : xs[i] < xs[i - gap]) :
    GapSortedExcept gap stop (i - gap) (xs.swap i (i - gap)) := by
  have hp : i - gap < xs.size := by omega
  have hpi : i - gap < i := by omega
  have hm := pred_mod hgi
  intro a b ha hb hab hbs habmod hbne
  have ha' : a < xs.size := by simpa using ha
  have hb' : b < xs.size := by simpa using hb
  by_cases hbi : b = i
  · subst b
    have hap := column_distance hab habmod
    by_cases hap' : a = i - gap
    · subst a
      simpa using hlt.le
    · have hai : a ≠ i := by omega
      simp only [Array.getElem_swap, ite_eq_right hai, ite_eq_right hap']
      exact h a (i - gap) ha' hp (by omega) (by omega) (habmod.trans hm.symm) (by omega)
  · by_cases hai : a = i
    · subst a
      simp only [Array.getElem_swap, ite_eq_right hbi, ite_eq_right hbne]
      exact h (i - gap) b hp hb' (by omega) hbs (hm.trans habmod) hbi
    · by_cases hap : a = i - gap
      · subst a
        have hdist := column_distance hab habmod
        simp only [Array.getElem_swap, ite_eq_right (show i - gap ≠ i by omega),
          ite_eq_right hbi, ite_eq_right hbne]
        exact h i b hi hb' (by omega) hbs (hm.symm.trans habmod) hbi
      · simp only [Array.getElem_swap, ite_eq_right hai, ite_eq_right hap,
          ite_eq_right hbi, ite_eq_right hbne]
        exact h a b ha' hb' hab hbs habmod hbi

theorem gapInsert_sorted {α : Type*} [LinearOrder α] (gap : ℕ) (xs : Array α) (i : ℕ)
    (stop : ℕ) (hg : 0 < gap) (hi : i < stop) (hs : stop ≤ xs.size)
    (h : GapSortedExcept gap stop i xs) : GapSorted gap stop (gapInsert gap xs i) := by
  fun_induction gapInsert with
  | case1 xs i hc hlt ih =>
      exact ih (by omega) (by simpa using hs)
        (swap_preserves_except gap stop i xs hg hc.2.1 hc.2.2 hi h hlt)
  | case2 xs i hc hlt =>
      intro a b ha hb hab hbs hm
      by_cases hbi : b = i
      · subst b
        have hd := column_distance hab hm
        have hp : i - gap < xs.size := by omega
        have hle : xs[i - gap] ≤ xs[i] := le_of_not_gt hlt
        by_cases he : a = i - gap
        · subst a; exact hle
        · exact (h a (i - gap) ha hp (by omega) (by omega)
            (hm.trans (pred_mod hc.2.1).symm) (by omega)).trans hle
      · exact h a b ha hb hab hbs hm hbi
  | case3 xs i hc =>
      intro a b ha hb hab hbs hm
      by_cases hbi : b = i
      · subst b
        have hd := column_distance hab hm
        exact False.elim (hc ⟨hg, by omega, by omega⟩)
      · exact h a b ha hb hab hbs hm hbi

theorem insertions_size {α : Type*} [LinearOrder α]
    (gap : ℕ) (indices : List ℕ) (xs : Array α) :
    (indices.foldl (gapInsert gap) xs).size = xs.size := by
  induction indices generalizing xs with
  | nil => rfl
  | cons i rest ih => simp [ih]

theorem insertions_sorted {α : Type*} [LinearOrder α]
    (gap n : ℕ) (xs : Array α) (hg : 0 < gap) (hn : n ≤ xs.size) :
    GapSorted gap n ((List.range n).foldl (gapInsert gap) xs) := by
  induction n with
  | zero => intro a b ha hb hab hbs; omega
  | succ n ih =>
      rw [List.range_succ, List.foldl_append]
      simp only [List.foldl_cons, List.foldl_nil]
      apply gapInsert_sorted gap _ n (n + 1) hg (by omega)
        (by simpa only [insertions_size] using hn)
      intro a b ha hb hab hbs hm hbn
      exact ih (by omega) a b ha hb hab (by omega) hm

theorem gapPass_sorted {α : Type*} [LinearOrder α] (gap : ℕ) (xs : Array α)
    (hg : 0 < gap) : GapSorted gap xs.size (gapPass gap xs) :=
  insertions_sorted gap xs.size xs hg (by rfl)

theorem gapPass_one_sorted {α : Type*} [LinearOrder α] (xs : Array α) :
    (gapPass 1 xs).toList.Pairwise (· ≤ ·) := by
  rw [List.pairwise_iff_getElem]
  intro a b ha hb hab
  have h := gapPass_sorted 1 xs (by decide)
  exact h a b (by simpa using ha) (by simpa using hb) hab
    (by simpa using hb) (by simp only [Nat.mod_one])

theorem gaps_end_one (n : ℕ) (hn : 0 < n) : ∃ initialGaps, gaps n = initialGaps ++ [1] := by
  induction n using Nat.strong_induction_on with
  | h n ih =>
      rw [gaps_of_pos n hn]
      by_cases hh : n / 2 = 0
      · have : n = 1 := by omega
        subst n
        exact ⟨[], by simp⟩
      · obtain ⟨initialGaps, hp⟩ := ih (n / 2) (by omega) (by omega)
        exact ⟨n :: initialGaps, by simp [hp]⟩

theorem shellSortResult_sorted {α : Type*} [LinearOrder α] (xs : List α) :
    (shellSortResult xs).Pairwise (· ≤ ·) := by
  by_cases hn : xs.length / 2 = 0
  · have hl : xs.length ≤ 1 := by omega
    simp only [shellSortResult_eq_passes, hn, gaps_zero, List.foldl_nil, List.toList_toArray]
    rw [List.pairwise_iff_getElem]
    intro a b ha hb hab
    omega
  · obtain ⟨initialGaps, hp⟩ := gaps_end_one (xs.length / 2) (by omega)
    simpa [shellSortResult_eq_passes, hp, List.foldl_append] using
      gapPass_one_sorted (initialGaps.foldl (fun a gap => gapPass gap a) xs.toArray)

theorem shellSortResult_spec {α : Type*} [LinearOrder α] (xs : List α) :
    LeanSort.IsSortingResult (· ≤ ·) xs (shellSortResult xs) :=
  ⟨shellSortResult_sorted xs, shellSortResult_perm xs⟩

end LeanSort.Shell
