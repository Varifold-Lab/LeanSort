import LeanSort.Algorithm.Power

/-! Public equations for the run scanner, dyadic powers, and stack scheduler. -/

namespace LeanSort.Power

variable {α : Type*}

@[simp] theorem finishRun_descending (xs : List α) : finishRun xs (some false) = xs := rfl
@[simp] theorem finishRun_ascending (xs : List α) : finishRun xs (some true) = xs.reverse := rfl
@[simp] theorem finishRun_undirected (xs : List α) : finishRun xs none = xs.reverse := rfl

theorem scanRuns_nil (le : α → α → Bool) (current : List α)
    (direction : Option Bool) (done : List (List α)) :
    scanRuns le [] current direction done =
      (if current.isEmpty then done else finishRun current direction :: done).reverse := rfl

theorem scanRuns_start (le : α → α → Bool) (x : α) (xs : List α)
    (direction : Option Bool) (done : List (List α)) :
    scanRuns le (x :: xs) [] direction done = scanRuns le xs [x] none done := rfl

theorem scanRuns_direction (le : α → α → Bool) (x previous : α) (xs rest : List α)
    (done : List (List α)) :
    scanRuns le (x :: xs) (previous :: rest) none done =
      scanRuns le xs (x :: previous :: rest) (some (le previous x)) done := rfl

theorem scanRuns_step (le : α → α → Bool) (x previous : α) (xs rest : List α)
    (ascending : Bool) (done : List (List α)) :
    scanRuns le (x :: xs) (previous :: rest) (some ascending) done =
      if (if ascending then le previous x else !(le previous x)) then
        scanRuns le xs (x :: previous :: rest) (some ascending) done
      else scanRuns le xs [x] none (finishRun (previous :: rest) (some ascending) :: done) := rfl

@[simp] theorem powerLoop_zero (d a b : Nat) : powerLoop d 0 a b = 0 := rfl
theorem powerLoop_succ (d fuel a b : Nat) :
    powerLoop d (fuel + 1) a b =
      if a / d ≠ b / d then 0 else 1 + powerLoop d fuel (2 * a) (2 * b) := rfl

theorem nodePower_eq (n start left right : Nat) :
    nodePower n start left right =
      powerLoop (2 * n) (n.log2 + 1) (2 * start + left) (2 * start + 2 * left + right) := by
  dsimp only [nodePower]
  congr 1; omega

@[simp] theorem collapse_nil (le : α → α → Bool) (p : Nat) (xs : List α) :
    collapse le p [] xs = (xs, []) := rfl

theorem collapse_pop (le : α → α → Bool) (p : Nat) (top : Pending α)
    (stack : List (Pending α)) (xs : List α) (h : p < top.power) :
    collapse le p (top :: stack) xs = collapse le p stack (top.values.merge xs le) := by
  simp only [collapse, h, ite_true]

theorem collapse_stop (le : α → α → Bool) (p : Nat) (top : Pending α)
    (stack : List (Pending α)) (xs : List α) (h : top.power ≤ p) :
    collapse le p (top :: stack) xs = (xs, top :: stack) := by
  simp only [collapse, Nat.not_lt.mpr h, ite_false]

@[simp] theorem finishStack_nil (le : α → α → Bool) (xs : List α) :
    finishStack le [] xs = xs := rfl
theorem finishStack_cons (le : α → α → Bool) (top : Pending α)
    (stack : List (Pending α)) (xs : List α) :
    finishStack le (top :: stack) xs = finishStack le stack (top.values.merge xs le) := rfl

@[simp] theorem mergeRuns_nil (le : α → α → Bool) (n start : Nat)
    (xs : List α) (stack : List (Pending α)) :
    mergeRuns le n [] start xs stack = finishStack le stack xs := rfl

theorem mergeRuns_cons (le : α → α → Bool) (n start : Nat) (next xs : List α)
    (rest : List (List α)) (stack : List (Pending α)) :
    mergeRuns le n (next :: rest) start xs stack =
      let p := nodePower n start xs.length next.length
      let result := collapse le p stack xs
      mergeRuns le n rest (start + xs.length) next (⟨result.1, p⟩ :: result.2) := rfl

end LeanSort.Power
