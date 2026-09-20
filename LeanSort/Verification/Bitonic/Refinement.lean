import LeanSort.Verification.Bitonic.Functional
import Mathlib.Order.WithBot

namespace LeanSort.Bitonic

variable {α : Type*} [LinearOrder α]

def liftPad : Option α → WithTop α
  | none => ⊤
  | some x => ↑x

/-- Array contents viewed as a total wire assignment. Out-of-range wires use top. -/
def wires (xs : Array (Option α)) (k : Nat) : WithTop α := liftPad (xs[k]?.getD none)

theorem paddedLE_eq_decide (x y : Option α) :
    paddedLE x y = decide (liftPad x ≤ liftPad y) := by
  cases x <;> cases y <;>
    simp [paddedLE, liftPad]

omit [LinearOrder α] in
@[simp] theorem wires_get (xs : Array (Option α)) (k : Nat) (hk : k < xs.size) :
    wires xs k = liftPad xs[k] := by
  simp [wires, Array.getElem?_eq_getElem hk]

theorem wires_compareExchange (c : Comparator) (xs : Array (Option α))
    (hi : c.first < xs.size) (hj : c.second < xs.size) :
    wires (compareExchange c.ascending c.first c.second xs) =
      Functional.step c (wires xs) := by
  rcases c with ⟨a, i, j⟩
  funext k
  cases a
  · by_cases h : liftPad xs[j] ≤ liftPad xs[i]
    all_goals
      by_cases hki : k = i <;> by_cases hkj : k = j <;>
        simp_all [compareExchange, paddedLE_eq_decide, Functional.step,
          Functional.low, Functional.high, wires, Array.getElem?_swap,
          le_of_not_ge, not_le_of_gt]
    all_goals split_ifs <;> simp_all
  · by_cases h : liftPad xs[i] ≤ liftPad xs[j]
    all_goals
      by_cases hki : k = i <;> by_cases hkj : k = j <;>
        simp_all [compareExchange, paddedLE_eq_decide, Functional.step,
          Functional.low, Functional.high, wires, Array.getElem?_swap,
          le_of_not_ge, not_le_of_gt]
    all_goals split_ifs <;> simp_all

theorem wires_runSchedule (cs : List Comparator) (xs : Array (Option α))
    (hc : ∀ c ∈ cs, c.first < xs.size ∧ c.second < xs.size) :
    wires (runSchedule cs xs) = Functional.run cs (wires xs) := by
  induction cs generalizing xs with
  | nil => rfl
  | cons c cs ih =>
    have h := hc c (by simp)
    change wires (runSchedule cs (compareExchange c.ascending c.first c.second xs)) = _
    rw [ih _ (fun d hd => by simpa using hc d (by simp [hd])), wires_compareExchange c xs h.1 h.2]
    rfl

theorem wires_sortNetwork (d s : Nat) (a : Bool) (xs : Array (Option α))
    (hsize : s + 2 ^ d ≤ xs.size) :
    wires (sortNetwork d s a xs) = Functional.run (sortSchedule d s a) (wires xs) := by
  rw [← run_sortSchedule]
  apply wires_runSchedule
  intro c hc
  have := sortSchedule_bounds d s a c hc
  omega

end LeanSort.Bitonic
