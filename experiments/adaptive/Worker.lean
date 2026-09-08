import LeanSort.Verification.Adaptive.Correctness
import Lean

/-! Persistent local benchmark worker. JSON/model loading happens outside timing;
feature extraction, tree traversal, plan dispatch, sorting and output consumption
happen inside each adaptive measurement. Every output is checked after timing.
-/

namespace AdaptiveExperiment
open Lean LeanSort.Adaptive

def featureNames : List String :=
  ["length", "descent_permille", "ascending_runs", "adjacent_equal_permille",
   "value_range", "prefix_duplicate_permille"]

@[noinline] def features (xs : List Nat) : Array Nat := Id.run do
  let mut n := 0
  let mut down := 0
  let mut equal := 0
  let mut lo := xs.headD 0
  let mut hi := lo
  let mut previous : Option Nat := none
  for x in xs do
    if let some p := previous then
      if p > x then down := down + 1
      if p == x then equal := equal + 1
    n := n + 1
    lo := min lo x
    hi := max hi x
    previous := some x
  let sample := xs.take 32
  let duplicates := sample.length - sample.eraseDups.length
  return #[n, 1000 * down / max 1 (n - 1), if n == 0 then 0 else down + 1,
    1000 * equal / max 1 (n - 1), hi - lo,
    1000 * duplicates / max 1 sample.length]

def planJson : Plan → Json
  | .merge => Json.mkObj [("kind", toJson "merge")]
  | .insertion => Json.mkObj [("kind", toJson "insertion")]
  | .hybrid t => Json.mkObj [("kind", toJson "hybrid"), ("threshold", toJson t)]
  | .split cut l r => Json.mkObj [("kind", toJson "split"), ("cut", toJson cut),
      ("left", planJson l), ("right", planJson r)]

def decodePlan : Nat → Json → Except String Plan
  | 0, _ => .error "plan nesting limit"
  | fuel + 1, j => do
    match ← j.getObjValAs? String "kind" with
    | "merge" => return .merge
    | "insertion" => return .insertion
    | "hybrid" =>
      let t ← j.getObjValAs? Nat "threshold"
      unless [1, 8, 24, 64].contains t do throw "unsupported threshold"
      return .hybrid t
    | "split" =>
      let cut ← j.getObjValAs? Nat "cut"
      let left ← decodePlan fuel (← j.getObjVal? "left")
      let right ← decodePlan fuel (← j.getObjVal? "right")
      return .split cut left right
    | _ => throw "unknown plan"

inductive Tree where
  | leaf (plan : Plan)
  | branch (feature threshold : Nat) (left right : Tree)

def Tree.predict : Tree → Array Nat → Plan
  | .leaf p, _ => p
  | .branch f t l r, xs =>
    if xs[f]?.getD 0 ≤ t then l.predict xs else r.predict xs

def decodeTree : Nat → Json → Except String Tree
  | 0, _ => .error "tree nesting limit"
  | fuel + 1, j => do
    match ← j.getObjValAs? String "kind" with
    | "leaf" => return .leaf (← decodePlan 16 (← j.getObjVal? "plan"))
    | "branch" =>
      let f ← j.getObjValAs? Nat "feature"
      unless f < featureNames.length do throw "unknown feature"
      return .branch f (← j.getObjValAs? Nat "threshold")
        (← decodeTree fuel (← j.getObjVal? "left"))
        (← decodeTree fuel (← j.getObjVal? "right"))
    | _ => throw "unknown tree node"

def decodeModel (j : Json) : Except String Tree := do
  unless (← j.getObjValAs? Nat "schema_version") == 1 do throw "model version"
  unless (← j.getObjValAs? (List String) "feature_names") == featureNames do
    throw "feature schema mismatch"
  decodeTree 16 (← j.getObjVal? "tree")

def candidates : List (String × Plan) :=
  [("merge", .merge), ("insertion", .insertion), ("hybrid-1", .hybrid 1),
   ("hybrid-8", .hybrid 8), ("hybrid-24", .hybrid 24), ("hybrid-64", .hybrid 64)]

def manual (f : Array Nat) : Plan :=
  if f[0]?.getD 0 ≤ 32 || f[1]?.getD 0 == 0 then .insertion
  else if f[1]?.getD 0 ≤ 50 then .hybrid 64 else .hybrid 24

inductive Strategy where
  | fixed (plan : Plan)
  | rule
  | learned (tree : Option Tree)

def Strategy.choose : Strategy → List Nat → Option Plan
  | .fixed p, _ => some p
  | .rule, xs => some (manual (features xs))
  | .learned t, xs => t.map (·.predict (features xs))

@[noinline] def Strategy.run (s : Strategy) (xs : List Nat) : List Nat :=
  selectAndRun s.choose xs

theorem strategy_spec (s : Strategy) (xs : List Nat) :
    LeanSort.IsSortingResult (· ≤ ·) xs (s.run xs) :=
  selectAndRun_spec s.choose xs

def checksum (xs : List Nat) : Nat :=
  xs.foldl (fun acc x => (acc * 33 + x) % 1000000007) 0

def checkedRun (sink : IO.Ref Nat) (s : Strategy) (xs expected : List Nat) : IO Nat := do
  let start ← IO.monoNanosNow
  let output := s.run xs
  sink.set (checksum output)
  let elapsed := (← IO.monoNanosNow) - start
  unless output == expected do throw (IO.userError "incorrect sorting output")
  return elapsed

/-- Read through IO after starting the timer: pure loop-invariant features must
not be shared with the feature vector used for logging outside the timer. -/
@[noinline] def timedFeatures (source : IO.Ref (List Nat)) (sink : IO.Ref Nat) : IO Nat := do
  let start ← IO.monoNanosNow
  let xs ← source.get
  sink.set ((features xs).foldl (· + ·) 0)
  return (← IO.monoNanosNow) - start

def benchmark (strategies : List (String × Strategy)) (xs expected : List Nat)
    (rounds inner orderSeed : Nat) : IO Json := do
  let sink ← IO.mkRef 0
  let mut samples := strategies.map fun (name, _) => (name, ([] : List Nat))
  let rotated := strategies.drop (orderSeed % strategies.length) ++
    strategies.take (orderSeed % strategies.length)
  for (_, s) in rotated do
    let _ ← checkedRun sink s xs expected
  for round in List.range rounds do
    let offset := round % rotated.length
    let order := rotated.drop offset ++ rotated.take offset
    for (name, s) in (if round % 2 == 0 then order else order.reverse) do
      for _ in List.range inner do
        let elapsed ← checkedRun sink s xs expected
        samples := samples.map fun (key, times) =>
          (key, if name == key then elapsed :: times else times)
  return toJson (samples.map fun (name, times) => Json.mkObj
    [("strategy", toJson name), ("samples_ns", toJson times.reverse)])

def getInput (j : Json) : Except String (List Nat) := j.getObjValAs? (List Nat) "input"

def orError {α : Type} (x : Except String α) : IO α :=
  match x with
  | .ok v => pure v
  | .error e => throw (IO.userError e)

def handle (j : Json) (model : Option Tree) (best : Plan) : IO Json := do
  let xs ← orError (getInput j)
  match ← orError (j.getObjValAs? String "cmd") with
  | "predict" =>
    let proposal := (Strategy.learned model).choose xs
    return Json.mkObj [("features", toJson (features xs)),
      ("plan", planJson (proposal.getD .merge)), ("fallback", toJson proposal.isNone),
      ("output", toJson (execute proposal xs))]
  | "execute" =>
    let decoded := decodePlan 16 (j.getObjValD "plan")
    return Json.mkObj [("fallback", toJson decoded.toOption.isNone),
      ("output", toJson (execute decoded.toOption xs))]
  | "measure" =>
    let expected ← orError (j.getObjValAs? (List Nat) "expected")
    let rounds ← orError (j.getObjValAs? Nat "rounds")
    let inner ← orError (j.getObjValAs? Nat "inner")
    unless 1 ≤ rounds && rounds ≤ 21 && 1 ≤ inner && inner ≤ 10 do
      throw (IO.userError "invalid repetition count")
    let stage ← orError (j.getObjValAs? String "stage")
    unless stage == "train" || stage == "test" do throw (IO.userError "invalid stage")
    let mut strategies := candidates.map fun (name, p) => (name, Strategy.fixed p)
    let learned := Strategy.learned model
    if stage == "test" then
      strategies := strategies ++ [("best_fixed", .fixed best), ("manual_rule", .rule),
        ("decision_tree", learned),
        ("tree_plan_only", .fixed ((learned.choose xs).getD .merge))]
    let result ← benchmark strategies xs expected rounds inner
      ((j.getObjValAs? Nat "order_seed").toOption.getD 0)
    let f := features xs
    let sink ← IO.mkRef 0
    let featureSource ← IO.mkRef xs
    let mut featureTimes : List Nat := []
    for _ in List.range (rounds * inner) do
      featureTimes := (← timedFeatures featureSource sink) :: featureTimes
    return Json.mkObj [("features", toJson f), ("measurements", result),
      ("feature_samples_ns", toJson featureTimes.reverse),
      ("tree_plan", planJson ((learned.choose xs).getD .merge)),
      ("manual_plan", planJson (manual f)), ("all_outputs_correct", toJson true)]
  | _ => throw (IO.userError "unknown command")

partial def loop (model : Option Tree) (best : Plan) : IO Unit := do
  let input ← IO.getStdin
  let output ← IO.getStdout
  let line ← input.getLine
  if line.isEmpty then return
  let mut nextModel := model
  let mut nextBest := best
  let response ← try
    let j ← orError (Json.parse line)
    if (j.getObjValAs? String "cmd").toOption == some "configure" then
      let decoded := decodeModel (j.getObjValD "model")
      nextModel := decoded.toOption
      nextBest := (decodePlan 16 (j.getObjValD "best_fixed")).toOption.getD .merge
      pure (Json.mkObj [("accepted", toJson nextModel.isSome),
        ("fallback", toJson nextModel.isNone),
        ("reason", toJson (match decoded with | .ok _ => "" | .error e => e))])
    else handle j model best
  catch e => pure (Json.mkObj [("error", toJson e.toString)])
  output.putStrLn response.compress
  output.flush
  loop nextModel nextBest

end AdaptiveExperiment

def main : IO Unit := do
  let out ← IO.getStdout
  out.putStrLn "{\"ready\":true,\"backend\":\"lean--run\",\"schema_version\":1}"
  out.flush
  AdaptiveExperiment.loop none .merge
