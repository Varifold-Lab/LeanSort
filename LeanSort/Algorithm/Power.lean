import Mathlib.Data.List.Sort
import Mathlib.Data.Nat.Log

/-!
List-based binary Powersort, following Munro and Wild's node-power merge policy:
https://www.wild-inter.net/publications/munro-wild-2018

Detect natural runs, compute powers from adjacent ORIGINAL run midpoints, and
merge pending runs with greater powers before pushing the new boundary. Runs
are materialized before scheduling; this version omits minimum-run extension
and galloping. Correctness, stability, dyadic-power, and comparison-complexity
proofs are in `LeanSort.Verification.Power`.
-/

namespace LeanSort.Power

/-- Restore an ascending run accumulated backwards. Strictly descending runs
are already ascending in the accumulator; singleton runs have no direction. -/
def finishRun {α : Type*} (reversed : List α) (ascending : Option Bool) : List α :=
  if ascending = some false then reversed else reversed.reverse

/-- Scan once, accumulating the current run backwards and completed runs in
reverse order. `le` must describe a total preorder. Descending runs are strict,
so reversing one does not reverse occurrences with equal keys. -/
def scanRuns {α : Type*} (le : α → α → Bool) :
    List α → List α → Option Bool → List (List α) → List (List α)
  | [], current, direction, done =>
      (if current.isEmpty then done else finishRun current direction :: done).reverse
  | x :: xs, [], _, done => scanRuns le xs [x] none done
  | x :: xs, previous :: rest, none, done =>
      scanRuns le xs (x :: previous :: rest) (some (le previous x)) done
  | x :: xs, previous :: rest, some ascending, done =>
      if (if ascending then le previous x else !(le previous x)) then
        scanRuns le xs (x :: previous :: rest) (some ascending) done
      else
        scanRuns le xs [x] none (finishRun (previous :: rest) (some ascending) :: done)

/-- Nonempty sorted runs, in their original left-to-right order. -/
def naturalRuns {α : Type*} (le : α → α → Bool) (xs : List α) : List (List α) :=
  scanRuns le xs [] none []

/-- Count matching binary positions of two rational midpoints, bounded by fuel.
Each step doubles the numerators, avoiding floating-point rounding. -/
def powerLoop (denominator : Nat) : Nat → Nat → Nat → Nat
  | 0, _, _ => 0
  | fuel + 1, a, b =>
      if a / denominator ≠ b / denominator then 0
      else 1 + powerLoop denominator fuel (2 * a) (2 * b)

/-- First differing binary position of the normalized midpoints of adjacent
runs. Preconditions: positive run lengths and `start + leftLen + rightLen ≤ n`.
The midpoints are `(2*start + leftLen)/(2*n)` and
`(2*start + 2*leftLen + rightLen)/(2*n)`.
For valid runs their separation is at least `1/n`, so `n.log2 + 1` doublings
suffice. The bounded helper remains total for arbitrary arguments. -/
def nodePower (n start leftLen rightLen : Nat) : Nat :=
  let a := 2 * start + leftLen
  let b := a + leftLen + rightLen
  powerLoop (2 * n) (n.log2 + 1) a b

/-- A pending sorted block with the power of its right boundary. -/
structure Pending (α : Type*) where
  values : List α
  power : Nat
  deriving Repr

/-- Collapse higher-power boundaries. The stack head is the rightmost pending
block, immediately left of `current`; ties in merging consume the left element. -/
def collapse {α : Type*} (le : α → α → Bool) (power : Nat) :
    List (Pending α) → List α → List α × List (Pending α)
  | [], current => (current, [])
  | top :: rest, current =>
      if top.power > power then collapse le power rest (top.values.merge current le)
      else (current, top :: rest)

/-- Drain pending blocks from right to left, preserving their original order. -/
def finishStack {α : Type*} (le : α → α → Bool) :
    List (Pending α) → List α → List α
  | [], current => current
  | top :: rest, current => finishStack le rest (top.values.merge current le)

/-- Process fresh runs. Compute the next boundary power BEFORE collapsing the
stack: `start` and `current` refer to the latest original run, not a merged block. -/
def mergeRuns {α : Type*} (le : α → α → Bool) (n : Nat) :
    List (List α) → Nat → List α → List (Pending α) → List α
  | [], _, current, stack => finishStack le stack current
  | next :: rest, start, current, stack =>
      let length := current.length
      let power := nodePower n start length next.length
      let (combined, remaining) := collapse le power stack current
      mergeRuns le n rest (start + length) next (⟨combined, power⟩ :: remaining)

/-- Powersort with an explicit total-preorder comparator. This interface also
supports records ordered by a key without ordering their other fields. -/
def powerSortBy {α : Type*} (le : α → α → Bool) (xs : List α) : List α :=
  match naturalRuns le xs with
  | [] => []
  | first :: rest => mergeRuns le xs.length rest 0 first []

/-- Ascending Powersort using the type's linear order. -/
def powerSortResult {α : Type*} [LinearOrder α] (xs : List α) : List α :=
  powerSortBy (fun x y => decide (x ≤ y)) xs

end LeanSort.Power
