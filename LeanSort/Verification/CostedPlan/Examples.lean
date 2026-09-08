import LeanSort.Verification.CostedPlan.Conditions
import LeanSort.Verification.CostedPlan.ChecksCost

namespace LeanSort.CostedPlan.Examples

def twoInsertion : Schema := .split (.fraction 1 2) (.leaf .insertion) (.leaf .insertion)
def twoGuarded : Schema :=
  .split (.fraction 1 2) (.guardSorted (.leaf .merge)) (.guardSorted (.leaf .merge))
def mergeHalves : Schema := .split (.fraction 1 2) (.leaf .merge) (.leaf .merge)

theorem half_position (n : Nat) : (Cut.fraction 1 2).position n = n / 2 := by
  simp [Cut.position, Nat.min_eq_right (Nat.div_le_self n 2)]

/-- A strictly smaller sufficient envelope, not a pointwise cost dominance claim. -/
theorem twoInsertion_smaller_envelope (n : Nat) (hn : 8 ≤ n) :
    twoInsertion.upper n < (Schema.leaf .insertion).upper n := by
  have ha : 4 ≤ n / 2 := by omega
  have hab : n / 2 ≤ n - n / 2 := by omega
  have hsum : n / 2 + (n - n / 2) = n := by omega
  have hprod := Nat.mul_le_mul_left (n / 2) ha
  have hprod' := Nat.mul_le_mul_left (n / 2) hab
  have hnprod : n < n / 2 * (n - n / 2) := by nlinarith [Nat.mod_lt n (by omega : 0 < 2), Nat.mod_add_div n 2]
  have hid := ComparisonBounds.insertion_add (n / 2) (n - n / 2)
  rw [hsum] at hid
  simp only [twoInsertion, Schema.upper, Component.upper, half_position]
  omega

theorem twoGuarded_linear {α : Type} [LinearOrder α] (xs : List α)
    (ready : twoGuarded.Ready xs) : (twoGuarded.eval xs).time ≤ 2 * xs.length := by
  simpa only [Nat.mul_comm] using twoGuarded.ready_cost_le_depth xs ready 1 rfl

/-- Under the two-sorted-block premise, including the runtime checks, the
certified envelope is smaller than the usual general-input merge envelope. -/
theorem twoGuarded_smaller_envelope (n : Nat) (hn : 8 ≤ n) :
    twoGuarded.readyUpper n < (Schema.leaf .merge).upper n := by
  have hb := twoGuarded.readyUpper_le_depth n 1 rfl
  have hc := Nat.clog_monotone 2 hn
  have h8 : Nat.clog 2 8 = 3 := by decide
  rw [h8] at hc
  have hm := Nat.mul_le_mul_left n hc
  simp only [Schema.upper, Component.upper, ComparisonBounds.mergeSort]
  nlinarith

/-- Structural deduplication is not semantic deduplication: this split simply
unrolls the first step of merge sort on nontrivial inputs. -/
theorem mergeHalves_program {α : Type} (xs : List α) (hn : 2 ≤ xs.length) :
    mergeHalves.program xs = ComparisonSort.mergeSort xs := by
  rw [ComparisonSort.mergeSort]
  simp only [show ¬ xs.length < 2 by omega, ↓reduceIte,
    mergeHalves, Schema.program, Component.program, half_position]

/-- A checked counterexample to inferring pointwise dominance from envelopes:
20 < 28, but on this already sorted input 10 comparisons > 7 comparisons. -/
theorem smaller_envelope_but_more_operations :
    twoInsertion.upper 8 = 20 ∧ (Schema.leaf .insertion).upper 8 = 28 ∧
    (twoInsertion.eval (List.range 8)).time = 10 ∧
    ((Schema.leaf .insertion).eval (List.range 8)).time = 7 := by decide +kernel

theorem twoInsertion_not_pointwise_dominates :
    ¬ (∀ xs : List Nat, (twoInsertion.eval xs).time ≤
      ((Schema.leaf .insertion).eval xs).time) := by
  intro h
  have hx := h (List.range 8)
  have hc := smaller_envelope_but_more_operations
  rw [hc.2.2.1, hc.2.2.2] at hx
  omega

end LeanSort.CostedPlan.Examples
