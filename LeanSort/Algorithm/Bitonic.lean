import Mathlib.Data.Nat.Log
import Mathlib.Order.Defs.LinearOrder

/-!
Bitonic sorting on an array padded to a power of two. `none` represents a
sentinel greater than every real key, so padding needs no maximum element of the
key type. Comparator positions depend only on the padded length, not key values.
The network is executed sequentially here; this is not a parallel implementation.
Correctness and network-cost proofs belong in the verification layer.
-/

namespace LeanSort.Bitonic

/-- Ceiling of log₂(n), with depth zero for empty and singleton inputs. -/
def networkDepth (n : Nat) : Nat :=
  if n ≤ 1 then 0 else (n - 1).log2 + 1

/-- Comparison on padded keys, treating `none` as positive infinity. -/
def paddedLE {α : Type*} [LinearOrder α] : Option α → Option α → Bool
  | _, none => true
  | none, some _ => false
  | some x, some y => decide (x ≤ y)

/-- One ascending or descending comparator. Invalid indices leave the array
unchanged; the sorting network calls this only with indices in its padded array. -/
def compareExchange {α : Type*} [LinearOrder α]
    (ascending : Bool) (i j : Nat) (xs : Array (Option α)) : Array (Option α) :=
  if h : i < xs.size ∧ j < xs.size then
    let ordered := if ascending then paddedLE xs[i] xs[j] else paddedLE xs[j] xs[i]
    if ordered then xs else xs.swap i j
  else xs

/-- Merge a bitonic block of length `2 ^ depth` starting at `start`.
Compare opposite halves, then recursively merge each half in the same direction.
The block must fit in the array and be bitonic; this is not a general merge API. -/
def mergeNetwork {α : Type*} [LinearOrder α] :
    Nat → Nat → Bool → Array (Option α) → Array (Option α)
  | 0, _, _, xs => xs
  | depth + 1, start, ascending, xs =>
      let half := 2 ^ depth
      let compared := (List.range half).foldl
        (fun state i => compareExchange ascending (start + i) (start + half + i) state) xs
      let left := mergeNetwork depth start ascending compared
      mergeNetwork depth (start + half) ascending left

/-- Sort a block of length `2 ^ depth` that fits in the array.
Sorting the first half up and the second half down creates a bitonic block. -/
def sortNetwork {α : Type*} [LinearOrder α] :
    Nat → Nat → Bool → Array (Option α) → Array (Option α)
  | 0, _, _, xs => xs
  | depth + 1, start, ascending, xs =>
      let half := 2 ^ depth
      let left := sortNetwork depth start true xs
      let right := sortNetwork depth (start + half) false left
      mergeNetwork (depth + 1) start ascending right

/-- Pad to the smallest power of two at least the input length.
Empty input is represented by one sentinel. Real occurrences remain distinct. -/
def paddedInput {α : Type*} (xs : List α) : Array (Option α) :=
  (xs.map some ++ List.replicate (2 ^ networkDepth xs.length - xs.length) none).toArray

/-- Ascending bitonic sort for arbitrary input lengths, removing only sentinels. -/
def bitonicSortResult {α : Type*} [LinearOrder α] (xs : List α) : List α :=
  let sorted := sortNetwork (networkDepth xs.length) 0 true (paddedInput xs)
  sorted.toList.filterMap id

end LeanSort.Bitonic
