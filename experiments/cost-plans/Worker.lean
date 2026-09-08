import Generated.Algorithms
import LeanSort.Verification.CostedPlan.ChecksCost
import Lean

/-! CPU-only research interpreter. All policies, including single algorithms, use
the same comparison-program evaluator. No claim about optimized native sorting.
Offline selection/model loading is outside deployment timing; schema execution,
splitting, runtime guards, interpretation and output consumption are inside it. -/
namespace CostPlanExperiment
open Lean LeanSort.CostedPlan

def orError {α : Type} : Except String α → IO α
  | .ok value => pure value
  | .error error => throw (IO.userError error)

def checksum (xs : List Nat) : Nat :=
  xs.foldl (fun acc x => (acc * 33 + x) % 1000000007) 0

@[noinline] def timedRun (p : Schema) (source : IO.Ref (List Nat))
    (sink : IO.Ref Nat) (expected : List Nat) : IO Nat := do
  let start ← IO.monoNanosNow
  let xs ← source.get
  let out := p.run xs
  sink.set (checksum out)
  let elapsed := (← IO.monoNanosNow) - start
  unless out == expected do throw (IO.userError "incorrect deployment output")
  return elapsed

/-- Isolated replay diagnostic, NOT a subtraction-based timing decomposition.
Deployment above already performs these checks. Never add this time to it again. -/
@[noinline] def timedChecks (p : Schema) (source : IO.Ref (List Nat))
    (sink : IO.Ref Nat) : IO Nat := do
  let start ← IO.monoNanosNow
  let xs ← source.get
  sink.set ((p.checkProgram xs).eval.time)
  return (← IO.monoNanosNow) - start

def profile (name : String) (p : Schema) (source : IO.Ref (List Nat))
    (expected : List Nat) : IO Json := do
  let forceSink ← IO.mkRef 0
  let start ← IO.monoNanosNow
  let xs ← source.get
  let result := p.eval xs
  let checks := (p.checkProgram xs).eval.time
  let ready := p.readyCheck xs
  let upper := p.upper xs.length
  let conditional := p.readyUpper xs.length
  unless result.ret == expected do throw (IO.userError "incorrect profile output")
  unless checks ≤ result.time && result.time ≤ upper do throw (IO.userError "cost certificate regression")
  if ready && !(result.time ≤ conditional) then throw (IO.userError "conditional certificate regression")
  let record := Json.mkObj [
    ("strategy", toJson name), ("comparisons", toJson result.time),
    ("check_comparisons", toJson checks), ("sorting_comparisons", toJson (result.time - checks)),
    ("ready", toJson ready), ("upper", toJson upper), ("conditional_upper", toJson conditional)]
  -- Force all diagnostic values before stopping the timer.
  let text := record.compress
  forceSink.set text.utf8ByteSize
  let forced ← forceSink.get
  let elapsed := (← IO.monoNanosNow) - start
  return Json.mkObj [("profile", record), ("offline_profile_ns", toJson elapsed),
    ("forced_bytes", toJson forced)]

def handle (j : Json) : IO Json := do
  let xs ← orError (j.getObjValAs? (List Nat) "input")
  let expected ← orError (j.getObjValAs? (List Nat) "expected")
  let names ← orError (j.getObjValAs? (List String) "strategies")
  let rounds ← orError (j.getObjValAs? Nat "rounds")
  let orderSeed ← orError (j.getObjValAs? Nat "order_seed")
  unless 1 ≤ rounds && rounds ≤ 21 do throw (IO.userError "invalid repetition count")
  let mut selected : List (String × Schema) := []
  for name in names do
    match CostPlanGenerated.entries.find? (fun entry => entry.1 == name) with
    | none => throw (IO.userError "unknown certified algorithm ID; no execution")
    | some entry => selected := selected ++ [entry]
  unless !selected.isEmpty do throw (IO.userError "empty shortlist")
  let source ← IO.mkRef xs
  let sink ← IO.mkRef 0
  let mut samples := selected.map fun (name, _) => (name, ([] : List Nat), ([] : List Nat))
  for (_, p) in selected do
    let _ ← timedRun p source sink expected
  for round in List.range rounds do
    let offset := (orderSeed + round) % selected.length
    let rotated := selected.drop offset ++ selected.take offset
    for (name, p) in (if round % 2 == 0 then rotated else rotated.reverse) do
      let elapsed ← timedRun p source sink expected
      samples := samples.map fun (key, runs, checks) =>
        (key, if key == name then elapsed :: runs else runs, checks)
  -- Replay diagnostics after the deployment samples, avoiding cache warming
  -- from a policy's own diagnostic immediately before its timed sort.
  for round in List.range rounds do
    let offset := (orderSeed + round) % selected.length
    let rotated := selected.drop offset ++ selected.take offset
    for (name, p) in rotated do
      let elapsed ← timedChecks p source sink
      samples := samples.map fun (key, runs, checks) =>
        (key, runs, if key == name then elapsed :: checks else checks)
  let mut profiles : List Json := []
  for (name, p) in selected do
    profiles := profiles ++ [← profile name p source expected]
  return Json.mkObj [("measurements", toJson (samples.map fun (name, runs, checks) =>
    Json.mkObj [("strategy", toJson name), ("e2e_samples_ns", toJson runs.reverse),
      ("check_replay_samples_ns", toJson checks.reverse)])),
    ("profiles", toJson profiles), ("all_outputs_correct", toJson true)]

partial def loop : IO Unit := do
  let input ← IO.getStdin
  let output ← IO.getStdout
  let line ← input.getLine
  if line.isEmpty then return
  let response ← try handle (← orError (Json.parse line))
    catch error => pure (Json.mkObj [("error", toJson error.toString)])
  output.putStrLn response.compress
  output.flush
  loop

end CostPlanExperiment

def main : IO Unit := do
  let out ← IO.getStdout
  out.putStrLn "{\"ready\":true,\"backend\":\"lean--run/comparison-program\"}"
  out.flush
  CostPlanExperiment.loop
