import LeanSort.Algorithm.RunMerge

namespace LeanSort.RunAdaptive

/-- Locate the run containing the integer midpoint, then choose its closer end.
This is the Peeksort split rule (Munro--Wild, ESA 2018, Algorithm 1), applied
to eagerly discovered run lengths. It is NOT the original lazy-scanning or
optimized array implementation. No entropy/near-optimality theorem is imported.
Source: https://www.wild-inter.net/publications/munro-wild-2018.pdf
-/
def peekCutAux (middle index start : Nat) : List Nat → Nat
  | [] => index
  | size :: rest =>
    if middle < start + size then
      if index = 0 then 1
      else if rest.isEmpty then index
      else if middle - start < (start + size - 1) - middle then index else index + 1
    else peekCutAux middle (index + 1) (start + size) rest

/-- Clipping guarantees progress even for malformed externally supplied empty
runs. Genuine discoveries contain only nonempty runs. Arithmetic on lengths
uses no key comparisons, but is included in deployment time. -/
def lengthCut {α : Type} (runs : List (List α)) : Nat :=
  let lengths := runs.map List.length
  min (runs.length - 1) (max 1 (peekCutAux ((lengths.sum - 1) / 2) 0 0 lengths))

def lengthPlan {α : Type} (runs : List (List α)) : MergeTree α :=
  if runs.length < 2 then
    match runs with
    | [] => .empty
    | run :: _ => .leaf run
  else
    .node (lengthPlan (runs.take (lengthCut runs)))
      (lengthPlan (runs.drop (lengthCut runs)))
termination_by runs.length
decreasing_by
  all_goals
    simp_wf
    have hpos : 0 < lengthCut runs := by dsimp only [lengthCut]; omega
    have hlt : lengthCut runs < runs.length := by dsimp only [lengthCut]; omega
    omega

end LeanSort.RunAdaptive
