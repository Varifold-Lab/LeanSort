import LeanSort.Model.MergeSearch
import LeanSort.Algorithm.RunMerge

namespace LeanSort.MergeSearch
open RunAdaptive

def checkFits : Shape → Nat → Nat → Bool
  | .empty, i, j => decide (i = j)
  | .leaf a, i, j => decide (a = i ∧ j = i+1)
  | .node l r, i, j =>
      let k := i + l.size
      decide (i < k ∧ k < j) && checkFits l i k && checkFits r k j

abbrev Table := Array (Array Nat)
def lookup (d : Table) (i j : Nat) : Nat := (d[i]?.getD #[])[j]?.getD 0
def weights (ls : List Nat) (i : Nat) : Nat := ls[i]?.getD 0

instance (n : Nat) (w : Nat → Nat) (d : Nat → Nat → Nat) : Decidable (LowerValid n w d) := by
  unfold LowerValid
  infer_instance

def checkLower (ls : List Nat) (d : Table) : Bool :=
  decide (LowerValid ls.length (weights ls) (lookup d))

def checkOptimal (ls : List Nat) (d : Table) (s : Shape) : Bool :=
  checkFits s 0 ls.length && checkLower ls d &&
    decide (s.budget (weights ls) = lookup d 0 ls.length)

def realize {α : Type} (runs : List (List α)) : Shape → MergeTree α
  | .empty => .empty
  | .leaf i => .leaf (runs[i]?.getD [])
  | .node l r => .node (realize runs l) (realize runs r)

/-- Only index structure is checked; the run data is never reordered or copied
by the untrusted plan. Invalid plans use the existing count-balanced planner. -/
def safePlan {α : Type} (runs : List (List α)) (s : Shape) : MergeTree α :=
  if checkFits s 0 runs.length then realize runs s else countPlan runs

end LeanSort.MergeSearch
