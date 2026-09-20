import LeanSort.Verification.Bitonic.Equations

namespace LeanSort.Bitonic

variable {α : Type*} [LinearOrder α]

theorem paddedLE_total (x y : Option α) :
    paddedLE x y = true ∨ paddedLE y x = true := by
  cases x with
  | none => cases y <;> simp [paddedLE]
  | some x =>
    cases y with
    | none => simp [paddedLE]
    | some y => simpa [paddedLE] using le_total x y

/-- Each valid comparison puts its two endpoints in the requested direction. -/
theorem compareExchange_ordered (ascending : Bool) (i j : Nat)
    (xs : Array (Option α)) (hi : i < xs.size) (hj : j < xs.size) :
    let ys := compareExchange ascending i j xs
    let yi := ys[i]'(by simpa [ys] using hi)
    let yj := ys[j]'(by simpa [ys] using hj)
    (if ascending then paddedLE yi yj else paddedLE yj yi) = true := by
  have ht := paddedLE_total xs[i] xs[j]
  cases ascending <;>
    simp only [compareExchange, hi, hj, and_self, dite_true, Bool.false_eq_true,
      ite_false, ite_true] <;>
    split <;> simp_all

end LeanSort.Bitonic
