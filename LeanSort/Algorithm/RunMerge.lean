import LeanSort.Model.MergeTree
import LeanSort.Algorithm.ComparisonSort
import LeanSort.Algorithm.RunDiscovery

namespace LeanSort.RunAdaptive
open Comparison

def MergeTree.program {α : Type} : MergeTree α → Program α (List α)
  | .empty => .pure []
  | .leaf run => .pure run
  | .node left right => left.program.bind fun ls =>
      right.program.bind fun rs => ComparisonSort.merge ls rs

/-- Balance by the NUMBER of discovered runs, not by their lengths. -/
def countPlan {α : Type} (runs : List (List α)) : MergeTree α :=
  if runs.length < 2 then
    match runs with
    | [] => .empty
    | run :: _ => .leaf run
  else
    .node (countPlan (runs.take (runs.length / 2)))
      (countPlan (runs.drop (runs.length / 2)))
termination_by runs.length
decreasing_by all_goals simp_wf; omega

/-- The planner is run INSIDE execution, after discovery, on exactly its result.
No run boundary, count or sortedness proof is supplied by the caller. -/
def sortProgram {α : Type} (planner : List (List α) → MergeTree α) (xs : List α) :
    Program α (List α) :=
  (discover xs).bind fun runs => (planner runs).program

@[noinline] def sort {α : Type} [LinearOrder α]
    (planner : List (List α) → MergeTree α) (xs : List α) : List α :=
  (sortProgram planner xs).eval.ret

end LeanSort.RunAdaptive
