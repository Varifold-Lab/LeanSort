import Mathlib.Data.List.Sort
import LeanSort.Model.Rearrangement

/-! Shell sort with the original halving gap sequence, implemented on arrays. -/

namespace LeanSort.Shell

/-- Insert one entry into its gap-separated column. A zero gap is a no-op. -/
def gapInsert {α : Type*} [LinearOrder α] (gap : ℕ) (xs : Array α) (i : ℕ) : Array α :=
  if h : 0 < gap ∧ gap ≤ i ∧ i < xs.size then
    if xs[i] < xs[i - gap] then
      gapInsert gap (xs.swap i (i - gap)) (i - gap)
    else xs
  else xs
termination_by i
decreasing_by omega

/-- One gapped insertion-sort pass. -/
def gapPass {α : Type*} [LinearOrder α] (gap : ℕ) (xs : Array α) : Array α :=
  (List.range xs.size).foldl (gapInsert gap) xs

/-- Positive gaps obtained by repeated halving, ending at one. -/
def gaps (n : ℕ) : List ℕ :=
  if n = 0 then [] else n :: gaps (n / 2)
termination_by n
decreasing_by omega

def shellSortResult {α : Type*} [LinearOrder α] (xs : List α) : List α :=
  ((gaps (xs.length / 2)).foldl (fun a gap => gapPass gap a) xs.toArray).toList

abbrev Gen := Rearrangement.Transposition.Gen

/-- Gapped insertion recording exactly the swaps it executes. -/
def gapInsertTrace {α : Type*} [LinearOrder α]
    (gap : ℕ) (xs : Array α) (i : ℕ) : Array α × List Gen :=
  if h : 0 < gap ∧ gap ≤ i ∧ i < xs.size then
    if xs[i] < xs[i - gap] then
      let (result, rest) := gapInsertTrace gap (xs.swap i (i - gap)) (i - gap)
      (result, (i, i - gap) :: rest)
    else (xs, [])
  else (xs, [])
termination_by i
decreasing_by omega

def insertionsTrace {α : Type*} [LinearOrder α]
    (gap : ℕ) : List ℕ → Array α → Array α × List Gen
  | [], xs => (xs, [])
  | i :: indices, xs =>
      let (next, word) := gapInsertTrace gap xs i
      let (result, rest) := insertionsTrace gap indices next
      (result, word ++ rest)

def gapPassTrace {α : Type*} [LinearOrder α] (gap : ℕ) (xs : Array α) :
    Array α × List Gen := insertionsTrace gap (List.range xs.size) xs

def passesTrace {α : Type*} [LinearOrder α] : List ℕ → Array α → Array α × List Gen
  | [], xs => (xs, [])
  | gap :: steps, xs =>
      let (next, word) := gapPassTrace gap xs
      let (result, rest) := passesTrace steps next
      (result, word ++ rest)

def sortTrace {α : Type*} [LinearOrder α] (xs : List α) : List α × List Gen :=
  let (result, word) := passesTrace (gaps (xs.length / 2)) xs.toArray
  (result.toList, word)

def shellSortTrace {α : Type*} [LinearOrder α] (xs : List α) : List Gen :=
  (sortTrace xs).2

/-- Replay swaps; an out-of-bounds swap is a no-op. -/
def replayArray {α : Type*} (word : List Gen) (xs : Array α) : Array α :=
  Rearrangement.replay (fun move a => a.swapIfInBounds move.1 move.2) word xs

def replay {α : Type*} (word : List Gen) (xs : List α) : List α :=
  (replayArray word xs.toArray).toList

end LeanSort.Shell
