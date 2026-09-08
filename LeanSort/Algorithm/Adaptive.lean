import LeanSort.Algorithm.HybridMerge

/-! A small, typed plan language. Learned choices do not supply executable code.
`split` permits nested, input-dependent cuts; this experiment learns only leaves.
-/

namespace LeanSort.Adaptive

inductive Plan where
  | merge
  | insertion
  | hybrid (threshold : Nat)
  | split (cut : Nat) (left right : Plan)
  deriving BEq, Repr

@[noinline] def Plan.run {α : Type} [LinearOrder α] : Plan → List α → List α
  | .merge, xs => Merge.mergeSortResult xs
  | .insertion, xs => Insertion.insertionSortResult xs
  | .hybrid threshold, xs => HybridMerge.sort threshold xs
  | .split cut left right, xs =>
    (Cslib.Algorithms.Lean.TimeM.merge
      (left.run (xs.take cut)) (right.run (xs.drop cut))).ret

/-- Rejected/missing proposals fall back to merge sort. -/
def execute {α : Type} [LinearOrder α] (proposal : Option Plan) (xs : List α) : List α :=
  (proposal.getD .merge).run xs

def selectAndRun {α : Type} [LinearOrder α]
    (choose : List α → Option Plan) (xs : List α) : List α :=
  execute (choose xs) xs

end LeanSort.Adaptive
