import LeanSort.Verification.RunAdaptive.Strategy
import Lean

namespace RunExperiment
open Lean LeanSort LeanSort.RunAdaptive LeanSort.Comparison

def orError {α : Type} : Except String α → IO α
  | .ok x => pure x
  | .error e => throw (IO.userError e)

def checkedMerge : CostedPlan.Schema := .guardSorted (.leaf .merge)
def fixedTwo : CostedPlan.Schema := .split (.fraction 1 2) checkedMerge checkedMerge
def fixedThree : CostedPlan.Schema := .split (.fraction 1 3) checkedMerge fixedTwo
def fixedFour : CostedPlan.Schema := .split (.fraction 1 2) fixedTwo fixedTwo

def decode (name : String) : Except String Strategy :=
  match name with
  | "merge" => .ok (.fixed (.leaf .merge))
  | "fixed_two" => .ok (.fixed fixedTwo)
  | "fixed_three" => .ok (.fixed fixedThree)
  | "fixed_four" => .ok (.fixed fixedFour)
  | "runs_count" => .ok .countBalanced
  | "runs_length" => .ok .lengthBalanced
  | _ =>
    if name.startsWith "hybrid_" then
      match (name.drop 7).toString.toNat? with
      | some t => if [1, 4, 8, 16, 24, 64].contains t then .ok (.fixed (.leaf (.hybrid t)))
                  else .error "unsupported frozen threshold"
      | none => .error "bad threshold"
    else .error "unknown strategy"

def checksum (xs : List Nat) : Nat := xs.foldl (fun a x => (a * 33 + x) % 1000000007) 0

def shape : MergeTree Nat → Json
  | .empty => toJson ([] : List Nat)
  | .leaf xs => toJson xs.length
  | .node l r => Json.arr #[shape l, shape r]

@[noinline] def timedRun (s : Strategy) (source : IO.Ref (List Nat))
    (sink : IO.Ref Nat) (expected : List Nat) : IO Nat := do
  let start ← IO.monoNanosNow
  let xs ← source.get
  let out := s.run xs
  sink.set (checksum out)
  let elapsed := (← IO.monoNanosNow) - start
  unless out == expected do throw (IO.userError "incorrect deployment output")
  return elapsed

@[noinline] def timedScan (source : IO.Ref (List Nat)) (sink : IO.Ref Nat) : IO Nat := do
  let start ← IO.monoNanosNow
  let xs ← source.get
  let rs := (discover xs).eval.ret
  sink.set (rs.foldl (fun a r => a + checksum r) 0)
  return (← IO.monoNanosNow) - start

@[noinline] def timedPlan (planner : List (List Nat) → MergeTree Nat)
    (source : IO.Ref (List (List Nat))) (sink : IO.Ref Nat) : IO Nat := do
  let start ← IO.monoNanosNow
  let rs ← source.get
  let tree := planner rs
  sink.set (tree.budget + tree.weight)
  return (← IO.monoNanosNow) - start

@[noinline] def timedMerge (source : IO.Ref (MergeTree Nat)) (sink : IO.Ref Nat)
    (expected : List Nat) : IO Nat := do
  let start ← IO.monoNanosNow
  let tree ← source.get
  let out := tree.program.eval.ret
  sink.set (checksum out)
  let elapsed := (← IO.monoNanosNow) - start
  unless out == expected do throw (IO.userError "incorrect merge-only output")
  return elapsed

def diagnostics (planner : List (List Nat) → MergeTree Nat) (xs expected : List Nat)
    (rounds : Nat) : IO Json := do
  let source ← IO.mkRef xs
  let rs := (discover xs).eval.ret
  let tree := planner rs
  let runSource ← IO.mkRef rs
  let treeSource ← IO.mkRef tree
  let sink ← IO.mkRef 0
  let mut scans : List Nat := []
  let mut plans : List Nat := []
  let mut merges : List Nat := []
  for _ in List.range rounds do
    scans := (← timedScan source sink) :: scans
    plans := (← timedPlan planner runSource sink) :: plans
    merges := (← timedMerge treeSource sink expected) :: merges
  return Json.mkObj [("scan_ns", toJson scans.reverse), ("plan_with_consumption_ns", toJson plans.reverse),
    ("merge_only_ns", toJson merges.reverse)]

def profile (s : Strategy) (xs expected : List Nat) : IO Json := do
  let result := (s.program xs).eval
  unless result.ret == expected do throw (IO.userError "incorrect profiled output")
  let rs := (discover xs).eval.ret
  let (checks, plan, treeBudget, ready, conditional) := match s with
    | .fixed p => ((p.checkProgram xs).eval.time, toJson (reprStr p), none,
        p.readyCheck xs, some (p.readyUpper xs.length))
    | .countBalanced => (xs.length - 1, shape (countPlan rs), some (countPlan rs).budget, false, none)
    | .lengthBalanced => (xs.length - 1, shape (lengthPlan rs), some (lengthPlan rs).budget, false, none)
  let bound := s.bound xs
  unless checks ≤ result.time && result.time ≤ bound do throw (IO.userError "cost inequality failed")
  if ready then
    if let some b := conditional then
      unless result.time ≤ b do throw (IO.userError "inapplicable/failed conditional bound")
  return Json.mkObj [("comparisons", toJson result.time), ("check_comparisons", toJson checks),
    ("merge_or_sort_comparisons", toJson (result.time - checks)), ("bound", toJson bound),
    ("tree_budget", toJson treeBudget), ("conditional_applicable", toJson ready),
    ("conditional_bound", toJson conditional), ("plan", plan)]

def handle (j : Json) : IO Json := do
  let xs ← orError (j.getObjValAs? (List Nat) "input")
  let expected ← orError (j.getObjValAs? (List Nat) "expected")
  let names ← orError (j.getObjValAs? (List String) "strategies")
  let rounds ← orError (j.getObjValAs? Nat "rounds")
  let seed ← orError (j.getObjValAs? Nat "order_seed")
  unless 1 ≤ rounds && rounds ≤ 21 && !names.isEmpty do throw (IO.userError "invalid measurement settings")
  let selected ← names.mapM fun name => do return (name, ← orError (decode name))
  let source ← IO.mkRef xs
  let sink ← IO.mkRef 0
  for (_, s) in selected do
    let _ ← timedRun s source sink expected
  let mut samples := selected.map fun (name, _) => (name, ([] : List Nat))
  for round in List.range rounds do
    let offset := (seed + round) % selected.length
    let order := selected.drop offset ++ selected.take offset
    for (name, s) in (if round % 2 == 0 then order else order.reverse) do
      let ns ← timedRun s source sink expected
      samples := samples.map fun (key, times) => (key, if name == key then ns :: times else times)
  -- Everything below is OFFLINE diagnostic replay; never added to E2E again.
  let rs := (discover xs).eval.ret
  let mut records : List Json := []
  for (name, s) in selected do
    let diag ← match s with
      | .countBalanced => diagnostics countPlan xs expected rounds
      | .lengthBalanced => diagnostics lengthPlan xs expected rounds
      | .fixed _ => pure Json.null
    let times := ((samples.find? (·.1 == name)).getD (name, [])).2.reverse
    records := records ++ [Json.mkObj [("strategy", toJson name), ("samples_ns", toJson times),
      ("profile", ← profile s xs expected), ("diagnostics", diag)]]
  unless rs.flatten == xs && rs.all (fun r => !r.isEmpty && (ComparisonSort.checkSorted r).eval.ret) do
    throw (IO.userError "discovered runs failed independent finite check")
  return Json.mkObj [("run_lengths", toJson (rs.map List.length)), ("run_count", toJson rs.length),
    ("scan_comparisons", toJson (discover xs).eval.time), ("measurements", toJson records),
    ("all_outputs_correct", toJson true)]

partial def loop : IO Unit := do
  let input ← IO.getStdin
  let output ← IO.getStdout
  let line ← input.getLine
  if line.isEmpty then return
  let response ← try handle (← orError (Json.parse line))
    catch e => pure (Json.mkObj [("error", toJson e.toString)])
  output.putStrLn response.compress
  output.flush
  loop

end RunExperiment

def main : IO Unit := do
  let out ← IO.getStdout
  out.putStrLn "{\"ready\":true,\"backend\":\"lean--run/comparison-program\"}"
  out.flush
  RunExperiment.loop
