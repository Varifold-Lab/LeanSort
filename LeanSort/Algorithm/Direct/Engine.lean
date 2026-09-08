import LeanSort.Algorithm.RunStrategy

/-! One recursive algorithm body, three interpretations of its comparison calls.
Id is the uncounted implementation; TimeM is direct instrumentation; Program
is a symbolic model used ONLY for refinement, never by the direct deployment.
No recursive call builds or interprets a Comparison.Program in Id/TimeM mode.
-/
namespace LeanSort.Direct
open Comparison RunAdaptive

instance programMonad {α : Type} : Monad (Program α) where
  pure := Program.pure
  bind := Program.bind

abbrev Compare (m : Type → Type) (α : Type) := Phase → α → α → m Bool

@[inline] def symbolicCompare {α : Type} : Compare (Program α) α :=
  fun phase x y => .compare phase x y .pure

@[inline] def countedCompare {α : Type} [LinearOrder α] : Compare Result α :=
  fun _ x y => ⟨decide (x ≤ y), 1⟩

@[inline] def plainCompare {α : Type} [LinearOrder α] : Compare Id α :=
  fun _ x y => decide (x ≤ y)

namespace Engine
variable {m : Type → Type} [Monad m] {α : Type}

@[specialize] def scanTail (cmp : Compare m α) (x : α) : List α → m (List α × List (List α))
  | [] => pure ([], [])
  | y :: ys => do
      let ascending ← cmp .check x y
      let (first, rest) ← scanTail cmp y ys
      if ascending then pure (y :: first, rest)
      else pure ([], (y :: first) :: rest)

@[specialize] def discover (cmp : Compare m α) : List α → m (List (List α))
  | [] => pure []
  | x :: xs => do
      let (first, rest) ← scanTail cmp x xs
      pure ((x :: first) :: rest)

@[specialize] def merge (cmp : Compare m α) : List α → List α → m (List α)
  | [], ys => pure ys
  | xs, [] => pure xs
  | x :: xs, y :: ys => do
      let smaller ← cmp .sort x y
      if smaller then
        let rest ← merge cmp xs (y :: ys)
        pure (x :: rest)
      else
        let rest ← merge cmp (x :: xs) ys
        pure (y :: rest)
termination_by xs ys => xs.length + ys.length

@[specialize] def insert (cmp : Compare m α) (x : α) : List α → m (List α)
  | [] => pure [x]
  | y :: ys => do
      let smaller ← cmp .sort x y
      if smaller then pure (x :: y :: ys)
      else
        let rest ← insert cmp x ys
        pure (y :: rest)

@[specialize] def insertion (cmp : Compare m α) : List α → m (List α)
  | [] => pure []
  | x :: xs => do
      let rest ← insertion cmp xs
      insert cmp x rest

@[specialize] def mergeSort (cmp : Compare m α) (xs : List α) : m (List α) := do
  if xs.length < 2 then pure xs
  else
    let left ← mergeSort cmp (xs.take (xs.length / 2))
    let right ← mergeSort cmp (xs.drop (xs.length / 2))
    merge cmp left right
termination_by xs.length
decreasing_by all_goals simp_wf; omega

@[specialize] def hybrid (cmp : Compare m α) (threshold : Nat) (xs : List α) : m (List α) := do
  if xs.length ≤ max 1 threshold then insertion cmp xs
  else
    let left ← hybrid cmp threshold (xs.take (xs.length / 2))
    let right ← hybrid cmp threshold (xs.drop (xs.length / 2))
    merge cmp left right
termination_by xs.length
decreasing_by all_goals simp_wf; omega

@[specialize] def checkSorted (cmp : Compare m α) : List α → m Bool
  | [] => pure true
  | [_] => pure true
  | x :: y :: ys => do
      let smaller ← cmp .check x y
      if smaller then checkSorted cmp (y :: ys) else pure false

@[specialize] def component (cmp : Compare m α) : CostedPlan.Component → List α → m (List α)
  | .merge, xs => mergeSort cmp xs
  | .insertion, xs => insertion cmp xs
  | .hybrid t, xs => hybrid cmp t xs

@[specialize] def schema (cmp : Compare m α) : CostedPlan.Schema → List α → m (List α)
  | .leaf c, xs => component cmp c xs
  | .split cut left right, xs => do
      let ls ← schema cmp left (xs.take (cut.position xs.length))
      let rs ← schema cmp right (xs.drop (cut.position xs.length))
      merge cmp ls rs
  | .guardSorted fallback, xs => do
      let sorted ← checkSorted cmp xs
      if sorted then pure xs else schema cmp fallback xs

@[specialize] def tree (cmp : Compare m α) : MergeTree α → m (List α)
  | .empty => pure []
  | .leaf xs => pure xs
  | .node left right => do
      let ls ← tree cmp left
      let rs ← tree cmp right
      merge cmp ls rs

@[specialize] def adaptive (cmp : Compare m α) (planner : List (List α) → MergeTree α)
    (xs : List α) : m (List α) := do
  let runs ← discover cmp xs
  tree cmp (planner runs)

@[specialize] def strategy (cmp : Compare m α) : Strategy → List α → m (List α)
  | .fixed p, xs => schema cmp p xs
  | .countBalanced, xs => adaptive cmp countPlan xs
  | .lengthBalanced, xs => adaptive cmp lengthPlan xs

end Engine
end LeanSort.Direct
