import LeanSort.Algorithm.Direct.Executor

namespace LeanSort.Direct
open Comparison RunAdaptive

/-- Controlled stage-boundary execution. Both false is an essential control:
it separates the old stages without replacing either implementation. Thus the
effects of removing the outer Program.bind are not mislabeled as scan gains.
Both true checks staging overhead against the fully direct Engine entry point.
-/
@[noinline] def staged {α : Type} [LinearOrder α] (directScan directMerge : Bool)
    (planner : List (List α) → MergeTree α) (xs : List α) : Result (List α) :=
  let rs := if directScan then scanCounted xs else (discover xs).eval
  let t := planner rs.ret
  let out := if directMerge then treeCounted t else t.program.eval
  ⟨out.ret, rs.time + out.time⟩

end LeanSort.Direct
