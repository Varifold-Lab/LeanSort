import Mathlib.Data.List.Sort

/-! Counting sort for natural numbers, with a histogram indexed by key.
Storage grows with the largest key, so this is intended for small key ranges. -/

namespace LeanSort.Counting

/-- Number of counters, including the zero-key counter for empty input. -/
def keyRange (xs : List ℕ) : ℕ := xs.foldl max 0 + 1

/-- Allocate one counter per key, then increment each input key's counter. -/
def histogram (xs : List ℕ) : Array ℕ :=
  xs.foldl (fun counts x => counts.modify x (· + 1))
    (Array.replicate (keyRange xs) 0)

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

/-- Record each increment while constructing the histogram. -/
def histogramTraceAux : List ℕ → Array ℕ → Array ℕ × List CountStep
  | [], counts => (counts, [])
  | x :: xs, counts =>
      let next := counts.modify x (· + 1)
      let rest := histogramTraceAux xs next
      (rest.1, ⟨x, next[x]?.getD 0⟩ :: rest.2)

/-- Counting sort together with its histogram-update trace. -/
def sortTrace (xs : List ℕ) : List ℕ × List CountStep :=
  let result := histogramTraceAux xs (Array.replicate (keyRange xs) 0)
  (histogramOutput result.1, result.2)

def countingSortTrace (xs : List ℕ) : List CountStep := (sortTrace xs).2

end LeanSort.Counting
