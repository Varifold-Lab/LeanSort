import Mathlib.Data.List.Sort
import Mathlib.Data.Nat.Log

/-! Binary least-significant-digit radix sort for natural numbers. -/

namespace LeanSort.Radix

/-- Number of binary passes, including one pass for an empty or all-zero input. -/
def radixBits (xs : List ℕ) : ℕ := (xs.foldl max 0).log2 + 1

/-- Stable partition by one binary digit: zero-bit keys precede one-bit keys. -/
def digitPass (bit : ℕ) (xs : List ℕ) : List ℕ :=
  let parts := xs.partition (fun x => decide (x / 2 ^ bit % 2 = 0))
  parts.1 ++ parts.2

/-- Process all bits of the maximum key, from least to most significant. -/
def radixSortResult (xs : List ℕ) : List ℕ :=
  (List.range (radixBits xs)).foldl
    (fun result bit => digitPass bit result) xs

/-- The bit processed and its stable partition decisions (`true` means zero). -/
structure DigitStep where
  bit : ℕ
  choices : List Bool
  deriving DecidableEq, Repr

/-- Instrumented partition: each digit test emits exactly one decision. -/
def partitionTrace (bit : ℕ) : List ℕ → (List ℕ × List ℕ) × List Bool
  | [] => (([], []), [])
  | x :: xs =>
      let (parts, rest) := partitionTrace bit xs
      let zero := decide (x / 2 ^ bit % 2 = 0)
      if zero then ((x :: parts.1, parts.2), true :: rest)
      else ((parts.1, x :: parts.2), false :: rest)

def passesTrace : List ℕ → List ℕ → List ℕ × List DigitStep
  | [], xs => (xs, [])
  | bit :: bits, xs =>
      let (parts, choices) := partitionTrace bit xs
      let (result, rest) := passesTrace bits (parts.1 ++ parts.2)
      (result, ⟨bit, choices⟩ :: rest)

def sortTrace (xs : List ℕ) : List ℕ × List DigitStep :=
  passesTrace (List.range (radixBits xs)) xs

def radixSortTrace (xs : List ℕ) : List DigitStep := (sortTrace xs).2

end LeanSort.Radix
