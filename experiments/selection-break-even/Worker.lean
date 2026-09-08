import LeanSort.Algorithm.BudgetSelection.Features
import Lean

namespace BudgetWorker
open Lean LeanSort LeanSort.LearnedSelection

def orError {α : Type} : Except String α → IO α
  | .ok x => pure x
  | .error e => throw (IO.userError e)

def decodeTree : Nat → Json → Except String Tree
  | 0, _ => .error "model tree exceeds depth budget"
  | fuel + 1, j => do
    let kind ← j.getObjValAs? String "kind"
    if kind == "leaf" then
      let values ← j.getObjValAs? (List Int) "values"
      if values.length ≤ 7 then return .leaf values else .error "leaf too wide"
    else if kind == "branch" then
      return .branch (← j.getObjValAs? Nat "feature") (← j.getObjValAs? Nat "threshold")
        (← decodeTree fuel (← j.getObjVal? "left")) (← decodeTree fuel (← j.getObjVal? "right"))
    else .error "unsupported tree"

def kindName : BudgetSelection.FeatureSet → String
  | .length => "length" | .eight => "eight" | .sixteen => "sixteen" | .legacy => "legacy"

def decodeKind (s : String) : Except String BudgetSelection.FeatureSet :=
  match s with
  | "length" => .ok .length | "eight" => .ok .eight | "sixteen" => .ok .sixteen | "legacy" => .ok .legacy
  | _ => .error "unknown feature budget"

def kinds : List BudgetSelection.FeatureSet := [.length,.eight,.sixteen,.legacy]

def decodeModel (kind : BudgetSelection.FeatureSet) (j : Json) : Model :=
  let parsed : Except String Model := do
    unless (← j.getObjValAs? Nat "schema_version") == 1 &&
      (← j.getObjValAs? String "candidate_version") == "verified-direct-seven-v1" &&
      (← j.getObjValAs? String "feature_version") == "budget-" ++ kindName kind ++ "-v1" do
        throw "unsupported schema"
    let tree ← decodeTree 9 (← j.getObjVal? "tree")
    match ← j.getObjValAs? String "kind" with
    | "classifier" => return .classifier tree
    | "cost_ranking" => return .costRanking tree
    | _ => throw "unsupported model"
  parsed.toOption.getD .invalid

def decodePolicy (j : Json) : BudgetSelection.Policy :=
  let parsed : Except String BudgetSelection.Policy := do
    let kind ← decodeKind (← j.getObjValAs? String "feature_kind")
    let choice ← match ← j.getObjValAs? String "kind" with
      | "fixed" => pure (BudgetSelection.Choice.fixed (← j.getObjValAs? Int "id"))
      | "rule" => pure (.rule (← j.getObjValAs? Nat "length_cut") (← j.getObjValAs? Nat "descent_cut"))
      | "learned" => pure (.learned (decodeModel kind (← j.getObjVal? "model")))
      | _ => throw "unsupported policy"
    return ⟨kind,choice⟩
  parsed.toOption.getD ⟨.length,.learned .invalid⟩

def featureSelect (p : BudgetSelection.Policy) (fs : List Nat) : Option Int := BudgetSelection.choose p.choice fs

def usesFeatures (p : BudgetSelection.Policy) : Bool :=
  match p.choice with | .fixed _ => false | _ => true

def checksum (xs : List Nat) : Nat := xs.foldl (fun a x => (a * 33 + x) % 1000000007) 0

@[noinline] def timedKernel (id : Nat) (source : IO.Ref (List Nat))
    (outSink idSink : IO.Ref Nat) (expected : List Nat) : IO (Nat × Nat) := do
  let start ← IO.monoNanosNow
  let xs ← source.get
  let out := dispatch (some (Int.ofNat id)) xs
  outSink.set (checksum out)
  idSink.set id
  let elapsed := (← IO.monoNanosNow) - start
  unless out == expected do throw (IO.userError "kernel output mismatch")
  return (elapsed, id)

@[noinline] def timedPolicy (p : BudgetSelection.Policy) (source : IO.Ref (List Nat))
    (outSink idSink : IO.Ref Nat) (expected : List Nat) : IO (Nat × Nat) := do
  let start ← IO.monoNanosNow
  let xs ← source.get
  let id := BudgetSelection.select p xs
  let out := dispatch id xs
  outSink.set (checksum out)
  idSink.set (resolve id)
  let elapsed := (← IO.monoNanosNow) - start
  unless out == expected do throw (IO.userError "policy output mismatch")
  return (elapsed, resolve id)

@[noinline] def timedFeatures (kind : BudgetSelection.FeatureSet) (source : IO.Ref (List Nat)) (sink : IO.Ref Nat) : IO Nat := do
  let start ← IO.monoNanosNow
  let xs ← source.get
  let fs := BudgetSelection.features kind xs
  sink.set (checksum fs)
  return (← IO.monoNanosNow) - start

@[noinline] def timedDecision (p : BudgetSelection.Policy) (source : IO.Ref (List Nat)) (sink : IO.Ref Nat) : IO Nat := do
  let start ← IO.monoNanosNow
  let fs ← source.get
  let id := featureSelect p fs
  sink.set (resolve id)
  return (← IO.monoNanosNow) - start

def emit (j : Json) : IO Unit := do
  let out ← IO.getStdout
  out.putStrLn j.compress
  out.flush

def sampleEvent (category name : String) (round : Int) (ns id : Nat) : IO Unit :=
  emit (Json.mkObj [("event",toJson "sample"),("category",toJson category),("name",toJson name),
    ("round",toJson round),("ns",toJson ns),("chosen_id",toJson id)])

def kernelProfile (id : Nat) (xs expected : List Nat) : IO Json := do
  let s := candidate id
  let result := Direct.runCounted s xs
  let checks := Direct.runPhase .check s xs
  let sorting := Direct.runPhase .sort s xs
  unless result.ret == expected && checks.ret == expected && sorting.ret == expected &&
      checks.time + sorting.time == result.time && result.time ≤ kernelBound (some (Int.ofNat id)) xs do
    throw (IO.userError "kernel phase/count/bound failure")
  let (ready, conditional) := match s with
    | .fixed schema => (schema.readyCheck xs, some (schema.readyUpper xs.length))
    | _ => (false, none)
  if ready then
    if let some bound := conditional then
      unless result.time ≤ bound do throw (IO.userError "conditional theorem domain/cost failure")
  return Json.mkObj [("id",toJson id),("comparisons",toJson result.time),
    ("check_comparisons",toJson checks.time),("sort_comparisons",toJson sorting.time),
    ("bound",toJson (kernelBound (some (Int.ofNat id)) xs)),
    ("conditional_applicable",toJson ready),("conditional_bound",toJson conditional)]

def bench (registry : List (String × BudgetSelection.Policy)) (j : Json) : IO Json := do
  let xs ← orError (j.getObjValAs? (List Nat) "input")
  let expected ← orError (j.getObjValAs? (List Nat) "expected")
  let expectedFeatures ← orError (j.getObjValAs? (List (List Nat)) "expected_features")
  let expectedCosts ← orError (j.getObjValAs? (List Nat) "expected_costs")
  let names ← orError (j.getObjValAs? (List String) "policies")
  let rounds ← orError (j.getObjValAs? Nat "rounds")
  let offsetSeed ← orError (j.getObjValAs? Nat "order_seed")
  unless 1 ≤ rounds && rounds ≤ 9 && expectedCosts.length == 7 do
    throw (IO.userError "invalid measurement configuration")
  let selected ← names.mapM fun name =>
    match registry.find? (fun p => p.1 == name) with
    | some (_,p) => pure (name,p)
    | none => throw (IO.userError "unconfigured policy")
  let source ← IO.mkRef xs
  let outSink ← IO.mkRef 0
  let idSink ← IO.mkRef 0
  -- All warmups are checked and retained but excluded from timing labels.
  for id in List.range 7 do
    let (ns,chosen) ← timedKernel id source outSink idSink expected
    sampleEvent "kernel" (toString id) (-1) ns chosen
  for (name,p) in selected do
    let (ns,chosen) ← timedPolicy p source outSink idSink expected
    sampleEvent "policy" name (-1) ns chosen
  let tasks := (List.range 7).map (fun id => ("kernel", toString id, (⟨.length,.fixed (Int.ofNat id)⟩ : BudgetSelection.Policy))) ++
    selected.map (fun (name,p) => ("policy",name,p))
  for round in List.range rounds do
    let offset := (offsetSeed + round) % tasks.length
    let order := tasks.drop offset ++ tasks.take offset
    for (category,name,p) in (if round % 2 == 0 then order else order.reverse) do
      let (ns,chosen) ← if category == "kernel" then
        timedKernel (resolve (featureSelect p [])) source outSink idSink expected
        else timedPolicy p source outSink idSink expected
      sampleEvent category name (Int.ofNat round) ns chosen
    for kind in kinds do
      sampleEvent "features" (kindName kind) (Int.ofNat round) (← timedFeatures kind source outSink) 0
  -- Independent diagnostics, never added to E2E.
  let allFeatures := kinds.map fun kind => BudgetSelection.features kind xs
  let counts := kinds.map fun kind => (BudgetSelection.counted kind xs).time
  unless allFeatures == expectedFeatures do throw (IO.userError "Python/Lean feature mismatch")
  for kind in kinds do
    let c := BudgetSelection.counted kind xs
    unless c.ret == BudgetSelection.features kind xs && c.time ≤ kind.budget do
      throw (IO.userError "feature instrumentation/bound mismatch")
  for (name,p) in selected do
    let fs := BudgetSelection.features p.featureSet xs
    let featureSource ← IO.mkRef fs
    for round in List.range rounds do
      sampleEvent "decision" name (Int.ofNat round) (← timedDecision p featureSource idSink) (resolve (featureSelect p fs))
  let profiles ← (List.range 7).mapM fun id => do
    let p ← kernelProfile id xs expected
    unless (← orError (p.getObjValAs? Nat "comparisons")) == expectedCosts[id]?.getD 0 do
      throw (IO.userError "independent key-comparison count mismatch")
    return p
  let rs := Direct.scan xs
  let predictions := selected.map fun (name,p) =>
    let fs := BudgetSelection.features p.featureSet xs
    Json.mkObj [("name",toJson name),("raw_id",toJson (featureSelect p fs)),
      ("chosen_id",toJson (resolve (featureSelect p fs))),("uses_features",toJson (usesFeatures p)),
      ("values",toJson (match p.choice with | .learned (.classifier t) | .learned (.costRanking t) => t.eval fs | _ => none))]
  return Json.mkObj [("features",toJson allFeatures),("feature_comparisons",toJson counts),
    ("kernel_profiles",toJson profiles),("predictions",toJson predictions),
    ("run_lengths",toJson (rs.map List.length)),("all_outputs_correct",toJson true)]

def handle (state : IO.Ref (List (String × BudgetSelection.Policy))) (j : Json) : IO Json := do
  match ← orError (j.getObjValAs? String "cmd") with
  | "configure" =>
    let policies ← orError (j.getObjValAs? (List Json) "policies")
    let registry ← policies.mapM fun item => do
      return (← orError (item.getObjValAs? String "name"), decodePolicy (← orError (item.getObjVal? "policy")))
    state.set registry
    return Json.mkObj [("configured",toJson registry.length)]
  | "bench" => bench (← state.get) j
  | "infer" =>
    let xs ← orError (j.getObjValAs? (List Nat) "input")
    let registry ← state.get
    let outputs := registry.map fun (name,p) =>
      let fs := BudgetSelection.features p.featureSet xs
      Json.mkObj [("name",toJson name),("features",toJson fs),
        ("raw_id",toJson (BudgetSelection.select p xs)),("chosen_id",toJson (resolve (BudgetSelection.select p xs))),
        ("output",toJson (BudgetSelection.run p xs)),
        ("values",toJson (match p.choice with | .learned (.classifier t) | .learned (.costRanking t) => t.eval fs | _ => none))]
    return Json.mkObj [("outputs",toJson outputs)]
  | _ => throw (IO.userError "unknown command")

partial def loop (state : IO.Ref (List (String × BudgetSelection.Policy))) : IO Unit := do
  let line ← (← IO.getStdin).getLine
  if line.isEmpty then return
  let response ← try handle state (← orError (Json.parse line))
    catch e => pure (Json.mkObj [("error",toJson e.toString)])
  emit (Json.mkObj [("event",toJson "done"),("result",response)])
  loop state

end BudgetWorker

def main : IO Unit := do
  BudgetWorker.emit (Lean.Json.mkObj [("ready",Lean.toJson true)])
  BudgetWorker.loop (← IO.mkRef [])
