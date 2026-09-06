import Mathlib.Data.List.Sort
import Mathlib.Data.Nat.Log

/-! Binary least-significant-digit radix sort for natural numbers. -/

namespace LeanSort.Radix

/-- Stable partition by one binary digit: zero-bit keys precede one-bit keys. -/
def digitPass (bit : ℕ) (xs : List ℕ) : List ℕ :=
  let parts := xs.partition (fun x => decide (x / 2 ^ bit % 2 = 0))
  parts.1 ++ parts.2

/-- Process all bits of the maximum key, from least to most significant. -/
def radixSortResult (xs : List ℕ) : List ℕ :=
  (List.range ((xs.foldl max 0).log2 + 1)).foldl
    (fun result bit => digitPass bit result) xs

end LeanSort.Radix
