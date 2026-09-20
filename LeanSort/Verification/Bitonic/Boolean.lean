import Mathlib.Data.Finset.Max
import Mathlib.Order.Fin.Basic
import Mathlib.Data.Bool.Basic
import Mathlib.Data.Fintype.Fin

/-!
Adapted from girving/aks, AKS/Bitonic/{Bitonic01,CompareLayer,Correctness}.lean.
Source: https://github.com/girving/aks (Apache-2.0).
Modified for LeanSort: independent imports, local namespace, selected interval
and threshold lemmas only. See third_party/aks/LICENSE and NOTICE.md.
-/
namespace LeanSort.Bitonic.Boolean
open Finset

/-! **Bitonic 0-1 Sequences** -/

/-- A 0-1 sequence is *bitonic* if some Bool value forms a contiguous interval `[lo, hi)`.
    Equivalently, the sequence has at most two "transitions" between false and true
    (a rotation of a monotone sequence). -/
def IsBitonic01 {n : Nat} (v : Fin n → Bool) : Prop :=
  ∃ (b : Bool) (lo hi : Nat), lo ≤ hi ∧ hi ≤ n ∧
    (∀ i : Fin n, v i = b ↔ lo ≤ i.val ∧ i.val < hi)

/-- A monotone 0-1 sequence is bitonic (the false block is `[0, t₀)` where `t₀` is
    the first true position). -/
theorem monotone_isBitonic01 {n : Nat} {v : Fin n → Bool} (hv : Monotone v) :
    IsBitonic01 v := by
  by_cases h_all : ∀ i : Fin n, v i = false
  · exact ⟨false, 0, n, Nat.zero_le _, Nat.le.refl,
      fun i ↦ ⟨fun _ ↦ ⟨Nat.zero_le _, i.isLt⟩, fun _ ↦ h_all i⟩⟩
  · have ⟨t, ht⟩ : ∃ t : Fin n, v t ≠ false := by
      by_contra hall; exact h_all (fun i ↦ by by_contra hi; exact hall ⟨i, hi⟩)
    have ht_true : v t = true := by cases hv : v t <;> simp_all
    have h_up : ∀ i j : Fin n, i ≤ j → v i = true → v j = true :=
      fun i j hij hi ↦ Bool.eq_true_of_true_le (hi ▸ hv hij)
    let S := Finset.univ.filter (fun i : Fin n ↦ v i = true)
    have hS : S.Nonempty := ⟨t, Finset.mem_filter.mpr ⟨Finset.mem_univ _, ht_true⟩⟩
    let t₀ := S.min' hS
    have ht₀_true : v t₀ = true := (Finset.mem_filter.mp (Finset.min'_mem S hS)).2
    have ht₀_min : ∀ i : Fin n, v i = true → t₀ ≤ i :=
      fun i hi ↦ Finset.min'_le S i (Finset.mem_filter.mpr ⟨Finset.mem_univ _, hi⟩)
    exact ⟨false, 0, t₀.val, Nat.zero_le _, Nat.le_of_lt t₀.isLt,
      fun i ↦ ⟨fun hf ↦ ⟨Nat.zero_le _, by
        by_contra hge
        have hle : t₀ ≤ i := Fin.le_def.mpr (by omega)
        exact absurd (h_up t₀ i hle ht₀_true) (by rw [hf]; decide)⟩,
        fun ⟨_, hi⟩ ↦ by
          by_contra hne
          have htrue : v i = true := by cases hv : v i <;> simp_all
          have hle := ht₀_min i htrue
          exact absurd hle (not_le.mpr (Fin.lt_def.mpr hi))⟩⟩

/-- All-false is bitonic. -/
theorem allFalse_isBitonic01 {n : Nat} : IsBitonic01 (fun _ : Fin n ↦ false) :=
  ⟨false, 0, n, Nat.zero_le _, Nat.le.refl,
    fun i ↦ ⟨fun _ ↦ ⟨Nat.zero_le _, i.isLt⟩, fun _ ↦ rfl⟩⟩

/-- All-true is bitonic. -/
theorem allTrue_isBitonic01 {n : Nat} : IsBitonic01 (fun _ : Fin n ↦ true) :=
  ⟨false, 0, 0, Nat.le.refl, Nat.zero_le n,
    fun _ ↦ ⟨fun h ↦ Bool.noConfusion h, fun ⟨_, h⟩ ↦ absurd h (by omega)⟩⟩

/-! **Interval Helpers for Compare Layer** -/

/-- Helper to get clean `Fin.val` characterization from the `IsBitonic01` hypothesis. -/
theorem isBitonic01_val_left {m : Nat} {v : Fin (2 * m) → Bool} {b : Bool} {lo hi : Nat}
    (hv : ∀ j : Fin (2 * m), v j = b ↔ lo ≤ j.val ∧ j.val < hi) (i : Fin m) :
    v ⟨i.val, by omega⟩ = b ↔ lo ≤ i.val ∧ i.val < hi := by
  have := hv ⟨i.val, by omega⟩; simpa using this

theorem isBitonic01_val_right {m : Nat} {v : Fin (2 * m) → Bool} {b : Bool} {lo hi : Nat}
    (hv : ∀ j : Fin (2 * m), v j = b ↔ lo ≤ j.val ∧ j.val < hi) (i : Fin m) :
    v ⟨i.val + m, by omega⟩ = b ↔ lo ≤ i.val + m ∧ i.val + m < hi := by
  have := hv ⟨i.val + m, by omega⟩; simpa using this

/-- AND of bitonic input (b=false case). -/
theorem and_bitonic_false {m : Nat} {v : Fin (2 * m) → Bool} {lo hi : Nat}
    (hhi : hi ≤ 2 * m) (_hlo : lo ≤ hi)
    (hv : ∀ j : Fin (2 * m), v j = false ↔ lo ≤ j.val ∧ j.val < hi) :
    ∃ (b : Bool) (lo' hi' : Nat), lo' ≤ hi' ∧ hi' ≤ m ∧
      ∀ i : Fin m, (v ⟨i.val, by omega⟩ && v ⟨i.val + m, by omega⟩) = b ↔
        lo' ≤ i.val ∧ i.val < hi' := by
  have hvi := fun i ↦ isBitonic01_val_left hv i
  have hvim := fun i ↦ isBitonic01_val_right hv i
  by_cases h1 : hi ≤ m
  · refine ⟨false, lo, hi, _hlo, h1, fun i ↦ ?_⟩
    rw [Bool.and_eq_false_iff]; constructor
    · intro h; rcases h with h | h
      · exact (hvi i).mp h
      · exact absurd ((hvim i).mp h) (by omega)
    · intro h; exact Or.inl ((hvi i).mpr h)
  · by_cases h2 : m ≤ lo
    · refine ⟨false, lo - m, hi - m, by omega, by omega, fun i ↦ ?_⟩
      rw [Bool.and_eq_false_iff]; constructor
      · intro h; rcases h with h | h
        · exact absurd ((hvi i).mp h) (by omega)
        · have := (hvim i).mp h; omega
      · intro h; exact Or.inr ((hvim i).mpr (by omega))
    · by_cases h3 : lo ≤ hi - m
      · refine ⟨false, 0, m, Nat.zero_le _, Nat.le.refl, fun i ↦ ?_⟩
        rw [Bool.and_eq_false_iff]; constructor
        · intro _; exact ⟨Nat.zero_le _, i.isLt⟩
        · intro _
          by_cases h : lo ≤ i.val
          · exact Or.inl ((hvi i).mpr ⟨h, by omega⟩)
          · exact Or.inr ((hvim i).mpr (by omega))
      · refine ⟨true, hi - m, lo, by omega, by omega, fun i ↦ ?_⟩
        rw [Bool.and_eq_true]; constructor
        · intro ⟨h1, h2⟩
          have hni : ¬(lo ≤ i.val ∧ i.val < hi) := fun hc ↦ by
            have := (hvi i).mpr hc; rw [h1] at this; exact Bool.noConfusion this
          have hnim : ¬(lo ≤ i.val + m ∧ i.val + m < hi) := fun hc ↦ by
            have := (hvim i).mpr hc; rw [h2] at this; exact Bool.noConfusion this
          omega
        · intro ⟨h1, h2⟩
          exact ⟨by cases hv' : v ⟨i.val, by omega⟩ with
                   | false => exact absurd ((hvi i).mp hv') (by omega)
                   | true => rfl,
                 by cases hv' : v ⟨i.val + m, by omega⟩ with
                   | false => exact absurd ((hvim i).mp hv') (by omega)
                   | true => rfl⟩

/-- AND of bitonic input (b=true case). -/
theorem and_bitonic_true {m : Nat} {v : Fin (2 * m) → Bool} {lo hi : Nat}
    (hhi : hi ≤ 2 * m) (_hlo : lo ≤ hi)
    (hv : ∀ j : Fin (2 * m), v j = true ↔ lo ≤ j.val ∧ j.val < hi) :
    ∃ (b : Bool) (lo' hi' : Nat), lo' ≤ hi' ∧ hi' ≤ m ∧
      ∀ i : Fin m, (v ⟨i.val, by omega⟩ && v ⟨i.val + m, by omega⟩) = b ↔
        lo' ≤ i.val ∧ i.val < hi' := by
  have hvi := fun i ↦ isBitonic01_val_left hv i
  have hvim := fun i ↦ isBitonic01_val_right hv i
  by_cases h1 : hi ≤ m
  · refine ⟨true, 0, 0, Nat.le.refl, by omega, fun i ↦ ?_⟩
    rw [Bool.and_eq_true]; constructor
    · intro ⟨_, h2⟩; have := (hvim i).mp h2; omega
    · intro ⟨_, h⟩; omega
  · by_cases h2 : m ≤ lo
    · refine ⟨true, 0, 0, Nat.le.refl, by omega, fun i ↦ ?_⟩
      rw [Bool.and_eq_true]; constructor
      · intro ⟨h1, _⟩; have := (hvi i).mp h1; omega
      · intro ⟨_, h⟩; omega
    · by_cases h3 : hi - m ≤ lo
      · refine ⟨true, 0, 0, Nat.le.refl, by omega, fun i ↦ ?_⟩
        rw [Bool.and_eq_true]; constructor
        · intro ⟨h1, h2⟩; have := (hvi i).mp h1; have := (hvim i).mp h2; omega
        · intro ⟨_, h⟩; omega
      · refine ⟨true, lo, hi - m, by omega, by omega, fun i ↦ ?_⟩
        rw [Bool.and_eq_true]; constructor
        · intro ⟨h1, h2⟩; exact ⟨((hvi i).mp h1).1, by have := (hvim i).mp h2; omega⟩
        · intro ⟨h1, h2⟩; exact ⟨(hvi i).mpr ⟨h1, by omega⟩, (hvim i).mpr (by omega)⟩

/-- OR of bitonic input (b=false case). -/
theorem or_bitonic_false {m : Nat} {v : Fin (2 * m) → Bool} {lo hi : Nat}
    (hhi : hi ≤ 2 * m) (_hlo : lo ≤ hi)
    (hv : ∀ j : Fin (2 * m), v j = false ↔ lo ≤ j.val ∧ j.val < hi) :
    ∃ (b : Bool) (lo' hi' : Nat), lo' ≤ hi' ∧ hi' ≤ m ∧
      ∀ i : Fin m, (v ⟨i.val, by omega⟩ || v ⟨i.val + m, by omega⟩) = b ↔
        lo' ≤ i.val ∧ i.val < hi' := by
  have hvi := fun i ↦ isBitonic01_val_left hv i
  have hvim := fun i ↦ isBitonic01_val_right hv i
  by_cases h1 : hi ≤ m
  · refine ⟨false, 0, 0, Nat.le.refl, by omega, fun i ↦ ?_⟩
    rw [Bool.or_eq_false_iff]; constructor
    · intro ⟨_, h2⟩; exact absurd ((hvim i).mp h2) (by omega)
    · intro ⟨_, h⟩; omega
  · by_cases h2 : m ≤ lo
    · refine ⟨false, 0, 0, Nat.le.refl, by omega, fun i ↦ ?_⟩
      rw [Bool.or_eq_false_iff]; constructor
      · intro ⟨h1, _⟩; exact absurd ((hvi i).mp h1) (by omega)
      · intro ⟨_, h⟩; omega
    · by_cases h3 : lo ≤ hi - m
      · refine ⟨false, lo, hi - m, by omega, by omega, fun i ↦ ?_⟩
        rw [Bool.or_eq_false_iff]; constructor
        · intro ⟨h1, h2⟩; exact ⟨((hvi i).mp h1).1, by have := (hvim i).mp h2; omega⟩
        · intro ⟨h1, h2⟩; exact ⟨(hvi i).mpr ⟨h1, by omega⟩, (hvim i).mpr (by omega)⟩
      · refine ⟨false, 0, 0, Nat.le.refl, by omega, fun i ↦ ?_⟩
        rw [Bool.or_eq_false_iff]; constructor
        · intro ⟨h1, h2⟩; have := (hvi i).mp h1; have := (hvim i).mp h2; omega
        · intro ⟨_, h⟩; omega

/-- OR of bitonic input (b=true case). -/
theorem or_bitonic_true {m : Nat} {v : Fin (2 * m) → Bool} {lo hi : Nat}
    (hhi : hi ≤ 2 * m) (_hlo : lo ≤ hi)
    (hv : ∀ j : Fin (2 * m), v j = true ↔ lo ≤ j.val ∧ j.val < hi) :
    ∃ (b : Bool) (lo' hi' : Nat), lo' ≤ hi' ∧ hi' ≤ m ∧
      ∀ i : Fin m, (v ⟨i.val, by omega⟩ || v ⟨i.val + m, by omega⟩) = b ↔
        lo' ≤ i.val ∧ i.val < hi' := by
  have hvi := fun i ↦ isBitonic01_val_left hv i
  have hvim := fun i ↦ isBitonic01_val_right hv i
  by_cases h1 : hi ≤ m
  · refine ⟨true, lo, hi, _hlo, h1, fun i ↦ ?_⟩
    rw [Bool.or_eq_true]; constructor
    · intro h; rcases h with h | h
      · exact (hvi i).mp h
      · exact absurd ((hvim i).mp h) (by omega)
    · intro h; exact Or.inl ((hvi i).mpr h)
  · by_cases h2 : m ≤ lo
    · refine ⟨true, lo - m, hi - m, by omega, by omega, fun i ↦ ?_⟩
      rw [Bool.or_eq_true]; constructor
      · intro h; rcases h with h | h
        · exact absurd ((hvi i).mp h) (by omega)
        · have := (hvim i).mp h; omega
      · intro h; exact Or.inr ((hvim i).mpr (by omega))
    · by_cases h3 : lo ≤ hi - m
      · refine ⟨true, 0, m, Nat.zero_le _, Nat.le.refl, fun i ↦ ?_⟩
        rw [Bool.or_eq_true]; constructor
        · intro _; exact ⟨Nat.zero_le _, i.isLt⟩
        · intro _
          by_cases h : lo ≤ i.val
          · exact Or.inl ((hvi i).mpr ⟨h, by omega⟩)
          · exact Or.inr ((hvim i).mpr (by omega))
      · refine ⟨false, hi - m, lo, by omega, by omega, fun i ↦ ?_⟩
        rw [Bool.or_eq_false_iff]; constructor
        · intro ⟨h1, h2⟩
          have hni : ¬(lo ≤ i.val ∧ i.val < hi) := fun hc ↦ by
            have := (hvi i).mpr hc; rw [h1] at this; exact Bool.noConfusion this
          have hnim : ¬(lo ≤ i.val + m ∧ i.val + m < hi) := fun hc ↦ by
            have := (hvim i).mpr hc; rw [h2] at this; exact Bool.noConfusion this
          omega
        · intro ⟨h1, h2⟩
          exact ⟨by cases hv' : v ⟨i.val, by omega⟩ with
                   | true => exact absurd ((hvi i).mp hv') (by omega)
                   | false => rfl,
                 by cases hv' : v ⟨i.val + m, by omega⟩ with
                   | true => exact absurd ((hvim i).mp hv') (by omega)
                   | false => rfl⟩

theorem and_or_left_le_right_false {m : Nat} {v : Fin (2 * m) → Bool} {lo hi : Nat}
    (_hhi : hi ≤ 2 * m) (_hlo : lo ≤ hi)
    (hv : ∀ j : Fin (2 * m), v j = false ↔ lo ≤ j.val ∧ j.val < hi) :
    (∀ i : Fin m, (v ⟨i.val, by omega⟩ && v ⟨i.val + m, by omega⟩) = false) ∨
    (∀ i : Fin m, (v ⟨i.val, by omega⟩ || v ⟨i.val + m, by omega⟩) = true) := by
  have hvi := fun i ↦ isBitonic01_val_left hv i
  have hvim := fun i ↦ isBitonic01_val_right hv i
  by_cases hcov : ∀ i : Fin m, (lo ≤ i.val ∧ i.val < hi) ∨ (lo ≤ i.val + m ∧ i.val + m < hi)
  · left; intro i; rw [Bool.and_eq_false_iff]
    rcases hcov i with h | h
    · exact Or.inl ((hvi i).mpr h)
    · exact Or.inr ((hvim i).mpr h)
  · right
    have ⟨i₀, hi₀⟩ := Classical.not_forall.mp hcov
    have hi₀1 : ¬(lo ≤ i₀.val ∧ i₀.val < hi) := fun h ↦ hi₀ (Or.inl h)
    have hi₀2 : ¬(lo ≤ i₀.val + m ∧ i₀.val + m < hi) := fun h ↦ hi₀ (Or.inr h)
    intro j
    cases hj1 : v ⟨j.val, by omega⟩ with
    | true => simp
    | false =>
      cases hj2 : v ⟨j.val + m, by omega⟩ with
      | true => simp
      | false =>
        exfalso
        have := (hvi j).mp hj1
        have := (hvim j).mp hj2
        omega

/-- After the compare layer on a bitonic input with `b=true`,
    either all AND values are false or all OR values are true. -/
theorem and_or_left_le_right_true {m : Nat} {v : Fin (2 * m) → Bool} {lo hi : Nat}
    (_hhi : hi ≤ 2 * m) (_hlo : lo ≤ hi)
    (hv : ∀ j : Fin (2 * m), v j = true ↔ lo ≤ j.val ∧ j.val < hi) :
    (∀ i : Fin m, (v ⟨i.val, by omega⟩ && v ⟨i.val + m, by omega⟩) = false) ∨
    (∀ i : Fin m, (v ⟨i.val, by omega⟩ || v ⟨i.val + m, by omega⟩) = true) := by
  have hvi := fun i ↦ isBitonic01_val_left hv i
  have hvim := fun i ↦ isBitonic01_val_right hv i
  by_cases hcov : ∀ i : Fin m, ¬((lo ≤ i.val ∧ i.val < hi) ∧ (lo ≤ i.val + m ∧ i.val + m < hi))
  · left; intro i; rw [Bool.and_eq_false_iff]
    have := hcov i
    by_cases h1 : v ⟨i.val, by omega⟩ = true
    · have h1i := (hvi i).mp h1
      have h2i : ¬(lo ≤ i.val + m ∧ i.val + m < hi) := fun hc ↦ this ⟨h1i, hc⟩
      right; cases hb : v ⟨i.val + m, by omega⟩ with
      | false => rfl
      | true => exact absurd ((hvim i).mp hb) h2i
    · left; cases hb : v ⟨i.val, by omega⟩ with
      | false => rfl
      | true => exact absurd hb h1
  · right
    have ⟨i₀, hi₀⟩ := Classical.not_forall.mp hcov
    have hi₀' : (lo ≤ i₀.val ∧ i₀.val < hi) ∧ (lo ≤ i₀.val + m ∧ i₀.val + m < hi) := by
      by_contra h; exact hi₀ h
    intro j
    cases hj1 : v ⟨j.val, by omega⟩ with
    | true => simp
    | false =>
      cases hj2 : v ⟨j.val + m, by omega⟩ with
      | true => simp
      | false =>
        exfalso
        have hni : ¬(lo ≤ j.val ∧ j.val < hi) := fun hc ↦ by
          have := (hvi j).mpr hc; rw [this] at hj1; exact Bool.noConfusion hj1
        have hnim : ¬(lo ≤ j.val + m ∧ j.val + m < hi) := fun hc ↦ by
          have := (hvim j).mpr hc; rw [this] at hj2; exact Bool.noConfusion hj2
        omega

theorem mono_bool_threshold {n : Nat} {f : Fin n → Bool} (hf : Monotone f) :
    (∀ i, f i = false) ∨ (∃ t : Nat, t ≤ n ∧ ∀ i : Fin n, f i = true ↔ t ≤ i.val) := by
  by_cases hall : ∀ i : Fin n, f i = false
  · exact Or.inl hall
  · right
    have ⟨j, hj⟩ : ∃ j : Fin n, f j = true := by
      by_contra h; exact hall (fun i ↦ by cases hfi : f i with
        | false => rfl | true => exact absurd ⟨i, hfi⟩ h)
    let S := Finset.univ.filter (fun i : Fin n ↦ f i = true)
    have hS : S.Nonempty := ⟨j, Finset.mem_filter.mpr ⟨Finset.mem_univ _, hj⟩⟩
    refine ⟨(S.min' hS).val, Nat.le_of_lt (S.min' hS).isLt,
      fun i ↦ ⟨fun hi ↦ ?_, fun hle ↦ ?_⟩⟩
    · exact Fin.le_def.mp (Finset.min'_le S i (Finset.mem_filter.mpr ⟨Finset.mem_univ _, hi⟩))
    · exact Bool.eq_true_of_true_le ((Finset.mem_filter.mp (Finset.min'_mem S hS)).2 ▸
        hf (Fin.le_def.mpr hle))

/-- An antitone Bool function has a threshold: either all true, or there exists `t`
    such that `g i = true ↔ i < t`. -/
theorem anti_bool_threshold {n : Nat} {g : Fin n → Bool} (hg : Antitone g) :
    (∀ i, g i = true) ∨ (∃ t : Nat, t ≤ n ∧ ∀ i : Fin n, g i = true ↔ i.val < t) := by
  by_cases hall : ∀ i : Fin n, g i = true
  · exact Or.inl hall
  · right
    have : ∃ j : Fin n, g j = false := by
      by_contra h; apply hall; intro i; cases hgi : g i with
        | true => rfl | false => exact absurd ⟨i, hgi⟩ h
    by_cases hsome : ∃ j : Fin n, g j = true
    · let S := Finset.univ.filter (fun i : Fin n ↦ g i = true)
      have hS : S.Nonempty := by
        obtain ⟨j', hj'⟩ := hsome
        exact ⟨j', Finset.mem_filter.mpr ⟨Finset.mem_univ _, hj'⟩⟩
      refine ⟨(S.max' hS).val + 1, by omega,
        fun i ↦ ⟨fun hi ↦ ?_, fun hlt ↦ ?_⟩⟩
      · exact Nat.lt_succ_of_le (Fin.le_def.mp
          (Finset.le_max' S i (Finset.mem_filter.mpr ⟨Finset.mem_univ _, hi⟩)))
      · exact Bool.eq_true_of_true_le ((Finset.mem_filter.mp (Finset.max'_mem S hS)).2 ▸
          hg (Fin.le_def.mpr (by omega)))
    · exact ⟨0, Nat.zero_le _, fun i ↦
        ⟨fun hi ↦ absurd ⟨i, hi⟩ hsome, fun h ↦ absurd h (by omega)⟩⟩


end LeanSort.Bitonic.Boolean

namespace LeanSort.Bitonic.Boolean

theorem bitonic_not {n : Nat} {v : Fin n → Bool} (hv : IsBitonic01 v) :
    IsBitonic01 (fun i => !(v i)) := by
  obtain ⟨b, lo, hi, hlo, hhi, hv⟩ := hv
  refine ⟨!b, lo, hi, hlo, hhi, fun i => ?_⟩
  simpa using hv i

theorem upDown_bitonic {m : Nat} (v : Fin (2 * m) → Bool)
    (hl : Monotone (fun i : Fin m => v ⟨i, by omega⟩))
    (hr : Antitone (fun i : Fin m => v ⟨i + m, by omega⟩)) : IsBitonic01 v := by
  have ht : ∃ t ≤ m, ∀ i : Fin m, v ⟨i, by omega⟩ = true ↔ t ≤ i.val := by
    rcases mono_bool_threshold hl with h | h
    · exact ⟨m, le_rfl, fun i => by simp [h i, Nat.not_le.mpr i.isLt]⟩
    · exact h
  have hu : ∃ u ≤ m, ∀ i : Fin m, v ⟨i + m, by omega⟩ = true ↔ i.val < u := by
    rcases anti_bool_threshold hr with h | h
    · exact ⟨m, le_rfl, fun i => by simp [h i, i.isLt]⟩
    · exact h
  obtain ⟨t, htm, ht⟩ := ht
  obtain ⟨u, hum, hu⟩ := hu
  refine ⟨true, t, m + u, by omega, by omega, fun i => ?_⟩
  by_cases hi : i.val < m
  · have h := ht ⟨i.val, hi⟩
    simpa only [Fin.eta] using h.trans (by omega : t ≤ i.val ↔ t ≤ i.val ∧ i.val < m + u)
  · have h := hu ⟨i.val - m, by omega⟩
    have he : (⟨i.val - m + m, by omega⟩ : Fin (2 * m)) = i := by
      apply Fin.ext
      dsimp
      omega
    dsimp only at h
    rw [he] at h
    exact h.trans (by omega)

end LeanSort.Bitonic.Boolean
