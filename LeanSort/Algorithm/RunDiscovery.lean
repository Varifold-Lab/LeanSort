import LeanSort.Semantics.Comparison

namespace LeanSort.RunAdaptive
open Comparison

/-- Scan every adjacent pair once, including descents at run boundaries.
The first run's head is supplied separately, avoiding partial head operations.
The result contains its tail and all subsequent runs. -/
def scanTail {α : Type} (x : α) : List α → Program α (List α × List (List α))
  | [] => .pure ([], [])
  | y :: ys => .compare .check x y fun ascending =>
      (scanTail y ys).bind fun (first, rest) =>
        if ascending then .pure (y :: first, rest)
        else .pure ([], (y :: first) :: rest)

def discover {α : Type} : List α → Program α (List (List α))
  | [] => .pure []
  | x :: xs => (scanTail x xs).bind fun (first, rest) => .pure ((x :: first) :: rest)

end LeanSort.RunAdaptive
