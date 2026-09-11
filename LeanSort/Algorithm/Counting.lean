
import Mathlib.Data.List.Sort
import Init.Control.State

/-! Counting sort for natural numbers, with a histogram indexed by key.
Storage grows with the largest key, so this is intended for small key ranges. -/

namespace LeanSort.Counting

/-- Number of counters, including the zero-key counter for empty input. -/
def keyRange (xs : List ℕ) : ℕ := xs.foldl max 0 + 1

/-- Increment one bucket; out-of-range keys preserve the original array. -/
abbrev increment (counts : Array ℕ) (key : ℕ) : Array ℕ := counts.modify key (· + 1)

/-- A key that is guaranteed to index one of the allocated buckets. -/
abbrev BucketIndex (width : ℕ) := Fin width

def incrementBounded (counts : Array ℕ) (key : BucketIndex counts.size) : Array ℕ :=
  increment counts key.val

/-- Allocate one counter per key, then increment each input key's counter. -/
def histogram (xs : List ℕ) : Array ℕ :=
  xs.foldl increment (Array.replicate (keyRange xs) 0)

/-- Enumerate the keys in increasing order, repeating each according to its count. -/
def histogramOutput (counts : Array ℕ) : List ℕ :=
  (List.range counts.size).flatMap fun key =>
    List.replicate (counts[key]?.getD 0) key

def countingSortResult (xs : List ℕ) : List ℕ := histogramOutput (histogram xs)

/-- One histogram update: the input key and its new counter value. -/
structure CountStep where
  key : ℕ
  value : ℕ
  deriving DecidableEq, Repr

/-- An update event whose key is within a fixed bucket allocation. -/
structure BoundedCountStep (width : ℕ) where
  key : BucketIndex width
  value : ℕ
  deriving DecidableEq, Repr

def BoundedCountStep.erase {width : ℕ} (step : BoundedCountStep width) : CountStep :=
  ⟨step.key.val, step.value⟩

/-- Update the histogram state and return the corresponding event. -/
def countStep (key : ℕ) : StateM (Array ℕ) CountStep := do
  modify (increment · key)
  let counts ← get
  pure ⟨key, counts[key]?.getD 0⟩

/-- Traverse the input in order, threading the histogram and collecting update events. -/
def histogramTraceAux (xs : List ℕ) (counts : Array ℕ) : Array ℕ × List CountStep :=
  ((xs.mapM countStep).run counts).swap

/-- Counting sort together with its histogram-update trace. -/
def sortTrace (xs : List ℕ) : List ℕ × List CountStep :=
  (histogramTraceAux xs (Array.replicate (keyRange xs) 0)).map histogramOutput id

def countingSortTrace (xs : List ℕ) : List CountStep := (sortTrace xs).2

end LeanSort.Counting
