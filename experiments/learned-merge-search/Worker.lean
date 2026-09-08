import LeanSort.Verification.MergeSearch.Checks
import Lean

namespace MergeSearchWorker
open Lean LeanSort LeanSort.MergeSearch LeanSort.RunAdaptive

def orError {α : Type} : Except String α → IO α
  | .ok x => pure x
  | .error e => throw (IO.userError e)

def decode : Nat → Json → Except String Shape
  | 0, _ => .error "tree depth exceeds resource limit"
  | fuel+1, j =>
    if j == Json.null then .ok .empty
    else match j.getNat? with
      | .ok i => .ok (.leaf i)
      | .error _ => do
        let a ← j.getArr?
        if a.size != 2 then throw "binary node requires two children"
        return .node (← decode fuel a[0]!) (← decode fuel a[1]!)

def encode : Shape → Json
  | .empty => .null
  | .leaf i => toJson i
  | .node l r => toJson [encode l,encode r]

def signature (t : MergeTree Nat) : Json :=
  match t with
  | .empty => .null
  | .leaf r => toJson r.length
  | .node l r => toJson [signature l,signature r]

def checksum (xs : List Nat) : Nat := xs.foldl (fun a x => (a*33+x)%1000000007) 0

@[noinline] def timedTree (source : IO.Ref (MergeTree Nat)) (sink : IO.Ref Nat) : IO (Nat × List Nat) := do
  let start ← IO.monoNanosNow
  let t ← source.get
  let out := Direct.tree t
  sink.set (checksum out)
  let stop ← IO.monoNanosNow
  return (stop-start,out)

def handle (j : Json) : IO Json := do
  let ls ← orError (j.getObjValAs? (List Nat) "lengths")
  unless ls.all (· > 0) && ls.length ≤ 64 do throw (IO.userError "positive lengths, at most 64 runs required")
  let d ← orError (j.getObjValAs? (Array (Array Nat)) "table")
  let raw ← orError (j.getObjValAs? (List Json) "trees")
  let rs ← orError (j.getObjValAs? (List (List Nat)) "runs")
  let execute ← orError (j.getObjValAs? Bool "execute")
  let certStart ← IO.monoNanosNow
  let lower := checkLower ls d
  unless lower do throw (IO.userError "invalid lower certificate")
  let parsed := raw.map (fun x => (decode 130 x).toOption)
  let flags := parsed.map (fun s => s.any (fun t => checkFits t 0 ls.length))
  let budgets := parsed.map (fun s => s.map (fun t => t.budget (weights ls)))
  let optimal := parsed.map (fun s => s.any (fun t => checkFits t 0 ls.length && decide (t.budget (weights ls) = lookup d 0 ls.length)))
  let certSink ← IO.mkRef 0
  certSink.set (flags.filter id |>.length) 
  certSink.set ((budgets.filterMap id).sum + (optimal.filter id).length)
  let certStop ← IO.monoNanosNow
  -- Force all certificate results before the stop marker is used below.
  unless flags.length == budgets.length && optimal.length == budgets.length do throw (IO.userError "certificate vector mismatch")
  let mut outputs : List Json := []
  if execute then
    unless rs.map List.length == ls && rs.all (fun r => decide (r.Pairwise (· ≤ ·))) do
      throw (IO.userError "invalid sorted run precondition")
    let expected := rs.flatten.mergeSort
    for item in parsed do
      let s := item.getD .empty
      let t := safePlan rs s
      let counted := Direct.treeCounted t
      let symbolic := t.program.eval
      unless counted.ret == expected && counted.ret == symbolic.ret && counted.time == symbolic.time && counted.time ≤ t.budget do
        throw (IO.userError "execution/refinement/budget mismatch")
      let source ← IO.mkRef t
      let sink ← IO.mkRef 0
      let mut times : List Nat := []
      for _ in List.range 3 do
        let (ns,out) ← timedTree source sink
        unless out == expected do throw (IO.userError "timed output mismatch")
        times := times ++ [ns]
      outputs := outputs ++ [Json.mkObj [("output",toJson counted.ret),("comparisons",toJson counted.time),
        ("budget",toJson t.budget),("times_ns",toJson times),("leaves",toJson t.leaves)]]
  let synthetic := ls.map (fun n => List.replicate n 0)
  return Json.mkObj [("lower_checked",toJson lower),("lower",toJson (lookup d 0 ls.length)),
    ("fits",toJson flags),("budgets",toJson budgets),("optimal",toJson optimal),
    ("certificate_ns",toJson (certStop-certStart)),("executions",toJson outputs),
    ("count_signature",signature (countPlan synthetic)),("length_signature",signature (lengthPlan synthetic))]

partial def loop : IO Unit := do
  let line ← (← IO.getStdin).getLine
  if line.isEmpty then return
  let result ← try handle (← orError (Json.parse line))
    catch e => pure (Json.mkObj [("error",toJson e.toString)])
  let stdout ← IO.getStdout
  stdout.putStrLn result.compress
  stdout.flush
  loop

end MergeSearchWorker
def main : IO Unit := MergeSearchWorker.loop
