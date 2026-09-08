import Cslib.Algorithms.Lean.TimeM
import Mathlib.Order.Defs.LinearOrder

/-! A comparison-effect language. One `compare` node costs one key comparison.
List traversal, allocation, index/length arithmetic and counter maintenance are
outside this model. Tags partition the SAME unit into checking and sorting work.
-/

namespace LeanSort.Comparison

inductive Phase where
  | check
  | sort
  deriving DecidableEq, BEq, Repr

inductive Program (α β : Type) where
  | pure (value : β)
  | compare (phase : Phase) (left right : α) (next : Bool → Program α β)

def Program.bind {α β γ : Type} : Program α β → (β → Program α γ) → Program α γ
  | .pure x, f => f x
  | .compare phase x y next, f => .compare phase x y (fun b => (next b).bind f)

abbrev Result (β : Type) := Cslib.Algorithms.Lean.TimeM Nat β

def Program.eval {α β : Type} [LinearOrder α] : Program α β → Result β
  | .pure x => ⟨x, 0⟩
  | .compare _ x y next =>
    let rest := (next (decide (x ≤ y))).eval
    ⟨rest.ret, rest.time + 1⟩

/-- A phase-specific replay count, used for diagnostics, not extra deployment work. -/
def Program.count {α β : Type} [LinearOrder α] (phase : Phase) : Program α β → Nat
  | .pure _ => 0
  | .compare tag x y next =>
    (next (decide (x ≤ y))).count phase + if phase = tag then 1 else 0

/-- Big-step operational semantics: precisely one charge for each comparison. -/
inductive Executes {α β : Type} [LinearOrder α] : Program α β → β → Nat → Prop
  | pure (x : β) : Executes (.pure x) x 0
  | compare (phase : Phase) (x y : α) (next : Bool → Program α β) (out : β) (cost : Nat)
      (tail : Executes (next (decide (x ≤ y))) out cost) :
      Executes (.compare phase x y next) out (cost + 1)

end LeanSort.Comparison
