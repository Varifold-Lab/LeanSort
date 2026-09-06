import Mathlib.Data.List.Sort

/-! Counting sort for natural numbers, with a histogram indexed by key.
Storage grows with the largest key, so this is intended for small key ranges. -/

namespace LeanSort.Counting

/-- Allocate one counter per key, then increment each input key's counter. -/
def histogram (xs : List ℕ) : Array ℕ :=
  xs.foldl (fun counts x => counts.modify x (· + 1))
    (Array.replicate (xs.foldl max 0 + 1) 0)

/-- Enumerate the keys in increasing order, repeating each according to its count. -/
def countingSortResult (xs : List ℕ) : List ℕ :=
  let counts := histogram xs
  (List.range counts.size).flatMap fun key =>
    List.replicate (counts[key]?.getD 0) key

end LeanSort.Counting
