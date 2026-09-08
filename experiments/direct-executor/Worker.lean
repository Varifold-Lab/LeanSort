import LeanSort.Algorithm.Direct.Profile
import Lean

namespace DirectExperiment
open Lean LeanSort LeanSort.Comparison LeanSort.RunAdaptive

def orError {α : Type} : Except String α → IO α
  | .ok x => pure x
  | .error e => throw (IO.userError e)

def decode : String → Except String Strategy
  | "merge" => .ok (.fixed (.leaf .merge))
  | "hybrid_8" => .ok (.fixed (.leaf (.hybrid 8)))
  | "fixed_four" => .ok (.fixed Direct.fixedFour)
  | "runs_count" => .ok .countBalanced
  | "runs_length" => .ok .lengthBalanced
  | _ => .error "strategy is not in frozen protocol"

def checksum (xs : List Nat) : Nat := xs.foldl (fun a x => (a * 33 + x) % 1000000007) 0

-- Identical clocks, source reads, full output consumption and two sinks.
-- A/B force the actual counter; C writes constant zero to the same second sink.
@[noinline] def timedReference (s : Strategy) (source : IO.Ref (List Nat))
    (outSink costSink : IO.Ref Nat) (expected : List Nat) : IO (Nat × Nat) := do
  let start ← IO.monoNanosNow
  let xs ← source.get
  let result := (s.program xs).eval
  outSink.set (checksum result.ret)
  costSink.set result.time
  let elapsed := (← IO.monoNanosNow) - start
  unless result.ret == expected do throw (IO.userError "reference output mismatch")
  return (elapsed, result.time)

@[noinline] def timedCounted (s : Strategy) (source : IO.Ref (List Nat))
    (outSink costSink : IO.Ref Nat) (expected : List Nat) : IO (Nat × Nat) := do
  let start ← IO.monoNanosNow
  let xs ← source.get
  let result := Direct.runCounted s xs
  outSink.set (checksum result.ret)
  costSink.set result.time
  let elapsed := (← IO.monoNanosNow) - start
  unless result.ret == expected do throw (IO.userError "direct-counted output mismatch")
  return (elapsed, result.time)

@[noinline] def timedPlain (s : Strategy) (source : IO.Ref (List Nat))
    (outSink costSink : IO.Ref Nat) (expected : List Nat) : IO (Nat × Nat) := do
  let start ← IO.monoNanosNow
  let xs ← source.get
  let result := Direct.run s xs
  outSink.set (checksum result)
  costSink.set 0
  let elapsed := (← IO.monoNanosNow) - start
  unless result == expected do throw (IO.userError "direct-plain output mismatch")
  return (elapsed, 0)

@[noinline] def timedStaged (ds dm : Bool) (planner : List (List Nat) → MergeTree Nat)
    (source : IO.Ref (List Nat)) (outSink costSink : IO.Ref Nat)
    (expected : List Nat) : IO (Nat × Nat) := do
  let start ← IO.monoNanosNow
  let xs ← source.get
  let result := Direct.staged ds dm planner xs
  outSink.set (checksum result.ret)
  costSink.set result.time
  let elapsed := (← IO.monoNanosNow) - start
  unless result.ret == expected do throw (IO.userError "ablation output mismatch")
  return (elapsed, result.time)

def execute (s : Strategy) (mode : String) (source : IO.Ref (List Nat))
    (outSink costSink : IO.Ref Nat) (expected : List Nat) : IO (Nat × Nat) := do
  match mode with
  | "reference" => timedReference s source outSink costSink expected
  | "counted" => timedCounted s source outSink costSink expected
  | "plain" => timedPlain s source outSink costSink expected
  | _ =>
    let planner ← match s with
      | .countBalanced => pure countPlan
      | .lengthBalanced => pure lengthPlan
      | .fixed _ => throw (IO.userError "stage ablations require dynamic runs")
    let (ds, dm) ← match mode with
      | "staged_reference" => pure (false, false)
      | "scan_only" => pure (true, false)
      | "merge_only" => pure (false, true)
      | "staged_direct" => pure (true, true)
      | _ => throw (IO.userError "unknown mode")
    timedStaged ds dm planner source outSink costSink expected

def shape : MergeTree Nat → Json
  | .empty => toJson ([] : List Nat)
  | .leaf xs => toJson xs.length
  | .node l r => Json.arr #[shape l, shape r]

def profile (s : Strategy) (xs expected : List Nat) : IO Json := do
  let direct := Direct.runCounted s xs
  let reference := (s.program xs).eval
  let checks := Direct.runPhase .check s xs
  let sorts := Direct.runPhase .sort s xs
  unless direct.ret == expected && reference.ret == expected &&
    checks.ret == expected && sorts.ret == expected && direct.time == reference.time &&
    checks.time == (s.program xs).count .check && sorts.time == (s.program xs).count .sort &&
    checks.time + sorts.time == direct.time && direct.time ≤ Direct.diagnosticBound s xs do
    throw (IO.userError "output, phase, refinement, or bound failure")
  let (ready, conditional) := match s with
    | .fixed p => (p.readyCheck xs, some (p.readyUpper xs.length))
    | _ => (false, none)
  if ready then
    if let some bound := conditional then
      unless direct.time ≤ bound do throw (IO.userError "conditional bound failure")
  let rs := Direct.scan xs
  let (treeBudget, plan) := match s with
    | .countBalanced => (some (countPlan rs).budget, shape (countPlan rs))
    | .lengthBalanced => (some (lengthPlan rs).budget, shape (lengthPlan rs))
    | .fixed p => (none, toJson (reprStr p))
  return Json.mkObj [("comparisons",toJson direct.time),("check_comparisons",toJson checks.time),
    ("merge_or_sort_comparisons",toJson sorts.time),("bound",toJson (Direct.diagnosticBound s xs)),
    ("tree_budget",toJson treeBudget),("plan",plan),
    ("conditional_applicable",toJson ready),("conditional_bound",toJson conditional)]

def handle (j : Json) : IO Json := do
  let xs ← orError (j.getObjValAs? (List Nat) "input")
  let expected ← orError (j.getObjValAs? (List Nat) "expected")
  let variants ← orError (j.getObjValAs? (List (String × String)) "variants")
  let costs ← orError (j.getObjValAs? (List Nat) "expected_costs")
  let rounds ← orError (j.getObjValAs? Nat "rounds")
  let seed ← orError (j.getObjValAs? Nat "order_seed")
  let withProfile ← orError (j.getObjValAs? Bool "profile")
  unless 1 ≤ rounds && rounds ≤ 21 && !variants.isEmpty && costs.length == variants.length do
    throw (IO.userError "invalid request")
  let selected ← (variants.zip costs).mapM fun ((name,mode),cost) => do
    return (name, mode, ← orError (decode name), cost)
  let source ← IO.mkRef xs
  let outSink ← IO.mkRef 0
  let costSink ← IO.mkRef 0
  let mut samples := selected.map fun (name,mode,_,_) => ((name,mode), ([] : List (Nat × Nat)))
  for (_,mode,s,cost) in selected do
    let (_,actual) ← execute s mode source outSink costSink expected
    unless mode == "plain" || actual == cost do throw (IO.userError "warmup cost mismatch")
  for round in List.range rounds do
    let offset := (seed + round) % selected.length
    let order := selected.drop offset ++ selected.take offset
    for (name,mode,s,cost) in (if round % 2 == 0 then order else order.reverse) do
      let measured ← execute s mode source outSink costSink expected
      unless mode == "plain" || measured.2 == cost do throw (IO.userError "measured cost mismatch")
      samples := samples.map fun (key,times) => (key,if key == (name,mode) then measured :: times else times)
  let mut profiles : List Json := []
  if withProfile then
    let reference := (discover xs).eval
    let direct := Direct.scanCounted xs
    unless Direct.scan xs == reference.ret && direct.ret == reference.ret &&
      direct.time == reference.time && direct.ret.flatten == xs do
      throw (IO.userError "scan refinement mismatch")
    for name in (variants.map Prod.fst).dedup do
      profiles := profiles ++ [Json.mkObj [("strategy",toJson name),
        ("profile",← profile (← orError (decode name)) xs expected)]]
  let rs := Direct.scan xs
  return Json.mkObj [("all_outputs_correct",toJson true),("profiles",toJson profiles),
    ("run_lengths",toJson (rs.map List.length)),("run_count",toJson rs.length),
    ("measurements",toJson (samples.map fun ((name,mode),times) =>
      Json.mkObj [("strategy",toJson name),("mode",toJson mode),
        ("samples_ns",toJson (times.reverse.map Prod.fst)),
        ("observed_counts",if mode == "plain" then Json.null else toJson (times.reverse.map Prod.snd))]))]

partial def loop : IO Unit := do
  let input ← IO.getStdin
  let output ← IO.getStdout
  let line ← input.getLine
  if line.isEmpty then return
  let response ← try handle (← orError (Json.parse line))
    catch e => pure (Json.mkObj [("error",toJson e.toString)])
  output.putStrLn response.compress
  output.flush
  loop

end DirectExperiment

def main : IO Unit := do
  let out ← IO.getStdout
  out.putStrLn "{\"ready\":true,\"backend\":\"lean--run\"}"
  out.flush
  DirectExperiment.loop
