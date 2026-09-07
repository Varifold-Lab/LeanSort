import LeanSort.Verification.Shell.Trace
import Mathlib.Tactic.Linarith

/-! Operational swap counts for the implemented halving-gap sequence. -/

namespace LeanSort.Shell

/-- Count the actual transpositions emitted by the instrumented algorithm. -/
def shellSwapCost {α : Type*} [LinearOrder α] (xs : List α) : ℕ :=
  (shellSortTrace xs).length

theorem gapInsertTrace_cost {α : Type*} [LinearOrder α] (gap : ℕ) (xs : Array α) (i : ℕ) :
    (gapInsertTrace gap xs i).2.length ≤ i / gap := by
  fun_induction gapInsertTrace with
  | case1 xs i h hlt result rest he ih =>
      rw [he] at ih
      have hd := Nat.div_eq_sub_div h.1 h.2.1
      simp only [List.length_cons]
      exact (Nat.add_le_add_right ih 1).trans_eq hd.symm
  | case2 => exact Nat.zero_le _
  | case3 => exact Nat.zero_le _

theorem insertionsTrace_cost {α : Type*} [LinearOrder α]
    (gap : ℕ) (indices : List ℕ) (xs : Array α) :
    (insertionsTrace gap indices xs).2.length ≤ (indices.map (fun i => i / gap)).sum := by
  induction indices generalizing xs with
  | nil => rfl
  | cons i indices ih =>
      simp only [insertionsTrace, List.length_append, List.map_cons, List.sum_cons]
      exact Nat.add_le_add (gapInsertTrace_cost gap xs i) (ih _)

private theorem sum_div_le (indices : List ℕ) (gap n : ℕ) (h : ∀ i ∈ indices, i ≤ n) :
    (indices.map (fun i => i / gap)).sum ≤ indices.length * (n / gap) := by
  induction indices with
  | nil => simp
  | cons i indices ih =>
      simp only [List.map_cons, List.sum_cons, List.length_cons, Nat.add_mul, Nat.one_mul]
      have hi := Nat.div_le_div_right (h i (by simp)) (c := gap)
      have hr := ih (fun j hj => h j (by simp [hj]))
      omega

theorem gapPassTrace_cost {α : Type*} [LinearOrder α] (gap : ℕ) (xs : Array α) :
    (gapPassTrace gap xs).2.length ≤ xs.size * (xs.size / gap) := by
  apply (insertionsTrace_cost gap (List.range xs.size) xs).trans
  simpa using sum_div_le (List.range xs.size) gap xs.size
    (fun i hi => Nat.le_of_lt (List.mem_range.mp hi))

theorem passesTrace_cost {α : Type*} [LinearOrder α] (steps : List ℕ) (xs : Array α) :
    (passesTrace steps xs).2.length ≤ xs.size * (steps.map (fun gap => xs.size / gap)).sum := by
  induction steps generalizing xs with
  | nil => simp [passesTrace]
  | cons gap steps ih =>
      simp only [passesTrace, List.length_append, List.map_cons, List.sum_cons, Nat.mul_add]
      have hr := ih (gapPassTrace gap xs).1
      simp only [gapPassTrace_result, gapPass_size] at hr
      simpa only [gapPassTrace_result] using Nat.add_le_add (gapPassTrace_cost gap xs) hr

/-- Halving a positive gap at least doubles the corresponding quotient. -/
private theorem quotient_double (n gap : ℕ) (hg : 1 < gap) :
    2 * (n / gap) ≤ n / (gap / 2) := by
  apply (Nat.le_div_iff_mul_le (by omega : 0 < gap / 2)).mpr
  have hd := Nat.div_mul_le_self n gap
  have hh := Nat.div_mul_le_self gap 2
  have hm := Nat.mul_le_mul_left (n / gap) hh
  nlinarith

/-- A telescoping bound for the reciprocals of the halving gaps. -/
theorem gaps_quotient_sum (n gap : ℕ) (hg : 0 < gap) :
    ((gaps gap).map (fun g => n / g)).sum + n / gap ≤ 2 * n := by
  induction gap using Nat.strong_induction_on with
  | h gap ih =>
      rw [gaps_of_pos gap hg]
      simp only [List.map_cons, List.sum_cons]
      by_cases he : gap = 1
      · subst gap; simp; omega
      · have hr := ih (gap / 2) (by omega) (by omega)
        have hd := quotient_double n gap (by omega)
        omega

theorem shellSwapCost_le_two_mul_sq {α : Type*} [LinearOrder α] (xs : List α) :
    shellSwapCost xs ≤ 2 * xs.length ^ 2 := by
  have hc := passesTrace_cost (gaps (xs.length / 2)) xs.toArray
  change shellSwapCost xs ≤ _ at hc
  simp only [List.size_toArray] at hc
  by_cases hg : xs.length / 2 = 0
  · simp [hg] at hc
    omega
  · have hs := gaps_quotient_sum xs.length (xs.length / 2) (by omega)
    have hm := Nat.mul_le_mul_left xs.length (show
      ((gaps (xs.length / 2)).map (fun g => xs.length / g)).sum ≤ 2 * xs.length from
        (Nat.le_add_right _ _).trans hs)
    nlinarith

end LeanSort.Shell
