import LeanSort.Verification.Pancake.Equations
import LeanSort.Model.SortingResult

/-! # Correctness of pancake sort -/

namespace LeanSort.Pancake

open List

/-! ## The selected maximum -/

theorem argmax?_eq_none {α : Type*} [LinearOrder α] (xs : List α) :
    argmax? xs = none ↔ xs = [] := by
  cases xs with
  | nil => simp
  | cons x xs =>
      rw [argmax?_cons]
      cases h : argmax? xs with
      | none => simp
      | some pair =>
          simp only
          split <;> simp

/-- `argmax?` returns a valid position containing a maximum of the list. -/
theorem argmax?_spec {α : Type*} [LinearOrder α] :
    ∀ (xs : List α) (i : ℕ) (maximum : α), argmax? xs = some (i, maximum) →
      i < xs.length ∧ xs[i]? = some maximum ∧ ∀ z ∈ xs, z ≤ maximum := by
  intro xs
  induction xs with
  | nil =>
      intro i maximum h
      simp at h
  | cons x xs ih =>
      intro i maximum h
      rw [argmax?_cons] at h
      cases htail : argmax? xs with
      | none =>
          have hnil : xs = [] := (argmax?_eq_none xs).mp htail
          subst xs
          simp at h
          obtain ⟨rfl, rfl⟩ := h
          simp
      | some pair =>
          obtain ⟨j, value⟩ := pair
          rcases ih j value htail with ⟨hj, hget, hmax⟩
          by_cases hx : value ≤ x
          · simp [htail, hx] at h
            obtain ⟨rfl, rfl⟩ := h
            refine ⟨by simp, by simp, ?_⟩
            intro z hz
            rcases List.mem_cons.mp hz with hzx | hz
            · rw [hzx]
            · exact (hmax z hz).trans hx
          · simp [htail, hx] at h
            obtain ⟨rfl, rfl⟩ := h
            refine ⟨by simp [hj], by simpa using hget, ?_⟩
            intro z hz
            rcases List.mem_cons.mp hz with hzx | hz
            · rw [hzx]
              exact le_of_not_ge hx
            · exact hmax z hz

/-- On a nonempty list, `maxIdx` is valid and points to a maximum. -/
theorem maxIdx_spec {α : Type*} [LinearOrder α] (xs : List α) (hne : xs ≠ []) :
    ∃ maximum,
      maxIdx xs < xs.length ∧
      xs[maxIdx xs]? = some maximum ∧
      ∀ z ∈ xs, z ≤ maximum := by
  cases harg : argmax? xs with
  | none =>
      exact (hne ((argmax?_eq_none xs).mp harg)).elim
  | some pair =>
      obtain ⟨i, maximum⟩ := pair
      rcases argmax?_spec xs i maximum harg with ⟨hi, hget, hmax⟩
      refine ⟨maximum, ?_, ?_, hmax⟩
      · simpa [maxIdx, harg] using hi
      · simpa [maxIdx, harg] using hget

/-! ## Prefix reversals -/

/-- A prefix reversal preserves the input multiset, including when its length is invalid. -/
theorem flip_perm {α : Type*} (k : ℕ) (xs : List α) :
    flip k xs ~ xs := by
  by_cases h : k ≤ xs.length
  · rw [flip_of_le_length k xs h]
    simpa only [List.take_append_drop] using
      (List.reverse_perm (xs.take k)).append_right (xs.drop k)
  · rw [flip_of_length_lt k xs (Nat.lt_of_not_ge h)]

@[simp] theorem flip_length {α : Type*} (k : ℕ) (xs : List α) :
    (flip k xs).length = xs.length :=
  (flip_perm k xs).length_eq

/-- Reversing a prefix presented explicitly as `front ++ suffix` reverses exactly
`front`. -/
theorem flip_append_of_length_eq {α : Type*} (k : ℕ)
    (front suffix : List α) (hfront : front.length = k) :
    flip k (front ++ suffix) = front.reverse ++ suffix := by
  subst k
  rw [flip_of_le_length]
  · simp
  · simp

/-- The two reversals used by an interior round move the selected entry to the end
of the active prefix. -/
private theorem flip_flip_index {α : Type*} (active suffix : List α) (i : ℕ)
    (hi : i < active.length) :
    flip active.length (flip (i + 1) (active ++ suffix)) =
      (active.drop (i + 1)).reverse ++ active.take i ++ active[i] :: suffix := by
  have htakeLength : (active.take (i + 1)).length = i + 1 := by
    simp [List.length_take, Nat.min_eq_left (Nat.succ_le_iff.mpr hi)]
  have hsplit : active ++ suffix =
      active.take (i + 1) ++ (active.drop (i + 1) ++ suffix) := by
    rw [← List.append_assoc, List.take_append_drop]
  rw [hsplit, flip_append_of_length_eq (i + 1)
    (active.take (i + 1)) (active.drop (i + 1) ++ suffix) htakeLength]
  have hfrontLength :
      ((active.take (i + 1)).reverse ++ active.drop (i + 1)).length =
        active.length := by
    simp [List.length_take, List.length_drop,
      Nat.min_eq_left (Nat.succ_le_iff.mpr hi)]
    omega
  rw [← List.append_assoc,
    flip_append_of_length_eq active.length
      ((active.take (i + 1)).reverse ++ active.drop (i + 1)) suffix hfrontLength,
    List.reverse_append, List.reverse_reverse]
  simp only [List.append_assoc]
  congr 1
  rw [← List.singleton_append, ← List.append_assoc,
    List.take_append_getElem hi]

/-! ## One pancake round -/

/-- A pancake round only rearranges its input. -/
theorem round_fst_perm {α : Type*} [LinearOrder α] (k : ℕ) (xs : List α) :
    (round k xs).1 ~ xs := by
  rw [round_eq]
  dsimp only
  split
  · exact List.Perm.refl xs
  · split
    · exact flip_perm k xs
    · exact (flip_perm k (flip (maxIdx (xs.take k) + 1) xs)).trans
        (flip_perm (maxIdx (xs.take k) + 1) xs)

@[simp] theorem round_fst_length {α : Type*} [LinearOrder α] (k : ℕ)
    (xs : List α) :
    (round k xs).1.length = xs.length :=
  (round_fst_perm k xs).length_eq

/-- A valid positive round splits into a remaining prefix followed by a maximum of
the active prefix and the untouched suffix. -/
theorem round_fst_decompose {α : Type*} [LinearOrder α]
    (k : ℕ) (xs : List α) (hkpos : 0 < k) (hk : k ≤ xs.length) :
    ∃ front maximum,
      (round k xs).1 = front ++ maximum :: xs.drop k ∧
      front.length + 1 = k ∧
      (front ++ [maximum]) ~ xs.take k ∧
      ∀ z ∈ xs.take k, z ≤ maximum := by
  have hactiveLength : (xs.take k).length = k := by
    simp [List.length_take, Nat.min_eq_left hk]
  have hactiveNe : xs.take k ≠ [] := by
    intro hnil
    have hzero := congrArg List.length hnil
    simp [hactiveLength] at hzero
    omega
  obtain ⟨maximum, hm0, hget0, hmax⟩ := maxIdx_spec (xs.take k) hactiveNe
  let m := maxIdx (xs.take k)
  have hm : m < (xs.take k).length := by simpa [m] using hm0
  have hget : (xs.take k)[m]? = some maximum := by simpa [m] using hget0
  have hvalue : (xs.take k)[m] = maximum := by
    rw [List.getElem?_eq_getElem hm] at hget
    exact Option.some.inj hget
  by_cases hend0 : m + 1 = k
  · have hend : maxIdx (xs.take k) + 1 = k := by simpa [m] using hend0
    have hprefix : (xs.take k).take m ++ [maximum] = xs.take k := by
      calc
        (xs.take k).take m ++ [maximum] =
            (xs.take k).take m ++ [(xs.take k)[m]] := by rw [hvalue]
        _ = (xs.take k).take (m + 1) := List.take_append_getElem hm
        _ = xs.take k := by
          rw [hend0, List.take_of_length_le hactiveLength.le]
    let front := (xs.take k).take m
    have hout : (round k xs).1 = front ++ maximum :: xs.drop k := by
      rw [round_of_max_at_end k xs hend]
      calc
        xs = xs.take k ++ xs.drop k := (List.take_append_drop k xs).symm
        _ = front ++ maximum :: xs.drop k := by
          rw [← hprefix]
          simp [front, List.append_assoc]
    refine ⟨front, maximum, hout, ?_, ?_, hmax⟩
    · simp [front]
      omega
    · apply (List.perm_append_right_iff (xs.drop k)).mp
      have hp := round_fst_perm k xs
      rw [hout] at hp
      have hs : xs ~ xs.take k ++ xs.drop k :=
        List.Perm.of_eq (List.take_append_drop k xs).symm
      have hp' := hp.trans hs
      simpa [List.append_assoc] using hp'
  · by_cases hhead0 : m = 0
    · have hend : maxIdx (xs.take k) + 1 ≠ k := by simpa [m] using hend0
      have hhead : maxIdx (xs.take k) = 0 := by simpa [m] using hhead0
      have hgetZero : (xs.take k)[0]? = some maximum := by
        simpa [hhead0] using hget
      have hactiveCons : xs.take k = maximum :: (xs.take k).drop 1 := by
        cases hactive : xs.take k with
        | nil => simp [hactive] at hgetZero
        | cons a rest =>
            simp [hactive] at hgetZero
            subst a
            simp
      let front := ((xs.take k).drop 1).reverse
      have hflip : flip k xs = (xs.take k).reverse ++ xs.drop k := by
        simpa only [List.take_append_drop] using
          flip_append_of_length_eq k (xs.take k) (xs.drop k) hactiveLength
      have hout : (round k xs).1 = front ++ maximum :: xs.drop k := by
        rw [round_of_max_at_head k xs hend hhead]
        rw [hflip, hactiveCons]
        simp [front, List.append_assoc]
      refine ⟨front, maximum, hout, ?_, ?_, hmax⟩
      · simp [front, hactiveLength]
        omega
      · apply (List.perm_append_right_iff (xs.drop k)).mp
        have hp := round_fst_perm k xs
        rw [hout] at hp
        have hs : xs ~ xs.take k ++ xs.drop k :=
          List.Perm.of_eq (List.take_append_drop k xs).symm
        have hp' := hp.trans hs
        simpa [List.append_assoc] using hp'
    · have hend : maxIdx (xs.take k) + 1 ≠ k := by simpa [m] using hend0
      have hhead : maxIdx (xs.take k) ≠ 0 := by simpa [m] using hhead0
      let front := ((xs.take k).drop (m + 1)).reverse ++ (xs.take k).take m
      have hdouble :
          flip k (flip (m + 1) xs) =
            ((xs.take k).drop (m + 1)).reverse ++
              (xs.take k).take m ++ (xs.take k)[m] :: xs.drop k := by
        simpa only [hactiveLength, List.take_append_drop] using
          flip_flip_index (xs.take k) (xs.drop k) m hm
      have hout : (round k xs).1 = front ++ maximum :: xs.drop k := by
        rw [round_of_max_interior k xs hend hhead]
        change flip k (flip (m + 1) xs) = _
        rw [hdouble, hvalue]
      refine ⟨front, maximum, hout, ?_, ?_, hmax⟩
      · simp [front, hactiveLength]
        omega
      · apply (List.perm_append_right_iff (xs.drop k)).mp
        have hp := round_fst_perm k xs
        rw [hout] at hp
        have hs : xs ~ xs.take k ++ xs.drop k :=
          List.Perm.of_eq (List.take_append_drop k xs).symm
        have hp' := hp.trans hs
        simpa [List.append_assoc] using hp'

/-! ## Recursive sorting -/

/-- The result component of a successor call is the result of recursively sorting
the list produced by its round. -/
theorem sortAux_fst_succ {α : Type*} [LinearOrder α]
    (k : ℕ) (xs : List α) :
    (sortAux (k + 1) xs).1 = (sortAux k (round (k + 1) xs).1).1 := by
  rw [sortAux_succ]

/-- With `k` valid active positions, `sortAux` replaces exactly that prefix by a
sorted permutation and leaves the suffix unchanged. -/
theorem sortAux_prefix_spec {α : Type*} [LinearOrder α] :
    ∀ (k : ℕ) (xs : List α), k ≤ xs.length →
      ∃ sortedPrefix,
        (sortAux k xs).1 = sortedPrefix ++ xs.drop k ∧
        sortedPrefix.length = k ∧
        sortedPrefix.Pairwise (· ≤ ·) ∧
        sortedPrefix ~ xs.take k := by
  intro k
  induction k with
  | zero =>
      intro xs hk
      exact ⟨[], by simp, by simp, by simp, by simp⟩
  | succ k ih =>
      intro xs hk
      obtain ⟨front, maximum, hround, hfrontLength, hroundPerm, hmaximum⟩ :=
        round_fst_decompose (k + 1) xs (Nat.zero_lt_succ k) hk
      have hfrontLength' : front.length = k := by omega
      have hroundLength : (round (k + 1) xs).1.length = xs.length :=
        (round_fst_perm (k + 1) xs).length_eq
      have hkAfter : k ≤ (round (k + 1) xs).1.length := by omega
      obtain ⟨sortedFront, hresult, hsortedLength, hsorted, hsortedPerm⟩ :=
        ih (round (k + 1) xs).1 hkAfter
      have htakeRound : (round (k + 1) xs).1.take k = front := by
        rw [hround]
        simp [hfrontLength']
      have hdropRound : (round (k + 1) xs).1.drop k =
          maximum :: xs.drop (k + 1) := by
        rw [hround]
        simp [hfrontLength']
      have hsortedPermFront : sortedFront ~ front := by
        simpa only [htakeRound] using hsortedPerm
      let sortedPrefix := sortedFront ++ [maximum]
      refine ⟨sortedPrefix, ?_, ?_, ?_, ?_⟩
      · rw [sortAux_fst_succ, hresult, hdropRound]
        simp [sortedPrefix, List.append_assoc]
      · simp [sortedPrefix, hsortedLength]
      · apply List.pairwise_append.mpr
        refine ⟨hsorted, by simp, ?_⟩
        intro z hz y hy
        simp only [List.mem_singleton] at hy
        subst y
        apply hmaximum z
        apply hroundPerm.mem_iff.mp
        exact List.mem_append_left [maximum] (hsortedPermFront.mem_iff.mp hz)
      · exact (hsortedPermFront.append_right [maximum]).trans hroundPerm

/-! ## Public correctness theorems -/

theorem pancakeSort_perm {α : Type*} [LinearOrder α] (xs : List α) :
    pancakeSort xs ~ xs := by
  obtain ⟨sortedPrefix, hresult, hlength, hsorted, hperm⟩ :=
    sortAux_prefix_spec xs.length xs le_rfl
  rw [pancakeSort_eq_sortAux_fst, hresult]
  simpa using hperm

theorem sorted_pancakeSort {α : Type*} [LinearOrder α] (xs : List α) :
    (pancakeSort xs).Pairwise (· ≤ ·) := by
  obtain ⟨sortedPrefix, hresult, hlength, hsorted, hperm⟩ :=
    sortAux_prefix_spec xs.length xs le_rfl
  rw [pancakeSort_eq_sortAux_fst, hresult]
  simpa using hsorted

theorem pancakeSort_spec {α : Type*} [LinearOrder α] (xs : List α) :
    IsSortingResult (· ≤ ·) xs (pancakeSort xs) :=
  ⟨sorted_pancakeSort xs, pancakeSort_perm xs⟩

end LeanSort.Pancake
