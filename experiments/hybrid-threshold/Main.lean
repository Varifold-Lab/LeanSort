import LeanSort.Verification.HybridMerge.Correctness

/-! Opt-in, offline parameter tuning. No UI, external dependencies, or file writes.
Timings describe these concrete Lean implementations under `lean --run` only.
-/

namespace HybridThresholdExperiment

inductive Plan where
  | hybrid (threshold : Nat)
  | merge
  | insertion
  deriving BEq

def Plan.name : Plan → String
  | .hybrid t => s!"hybrid-{t}"
  | .merge => "merge"
  | .insertion => "insertion"

@[noinline] def Plan.run (p : Plan) (xs : List Nat) : List Nat :=
  match p with
  | .hybrid t => LeanSort.HybridMerge.sort t xs
  | .merge => LeanSort.Merge.mergeSortResult xs
  | .insertion => LeanSort.Insertion.insertionSortResult xs

structure Case where
  name : String
  input : List Nat

-- Deterministic test generator, not a claim of uniform randomness.
def randomList (n seed modulus : Nat) : List Nat :=
  ((List.range n).foldl (fun (state, xs) _ =>
    let next := (1664525 * state + 1013904223) % 4294967296
    (next, next % modulus :: xs)) (seed, [])).2

def cases (lengths seeds : List Nat) : List Case := lengths.flatMap fun n =>
  let ordered := List.range n
  let middle := n / 2
  let near := ordered.take middle ++
    (ordered.drop middle |>.take 2).reverse ++ ordered.drop (middle + 2)
  [⟨s!"sorted/{n}", ordered⟩,
   ⟨s!"reverse/{n}", ordered.reverse⟩,
   ⟨s!"near-sorted/{n}", near⟩,
   ⟨s!"two-runs/{n}", ordered.drop middle ++ ordered.take middle⟩] ++
  seeds.flatMap fun seed =>
    [⟨s!"pseudorandom/{n}/{seed}", randomList n seed (4 * n + 1)⟩,
     ⟨s!"duplicates/{n}/{seed}", randomList n seed 4⟩]

def validate (plans : List Plan) (data : List Case) : IO Unit := do
  for c in data do
    let expected := LeanSort.Merge.mergeSortResult c.input
    for p in plans do
      unless p.run c.input == expected do
        throw (IO.userError s!"regression failed: {p.name}, {c.name}")

-- Consume every output, including its element values. This O(n) checksum and
-- IO overhead are included in every timing; validation and generation are not.
def runBatch (sink : IO.Ref Nat) (p : Plan) (data : List Case) : IO Unit := do
  let mut checksum := 0
  for c in data do
    checksum := (p.run c.input).foldl (fun h x => (h * 33 + x) % 1000000007) checksum
  sink.set checksum

structure Measurement where
  plan : Plan
  medianNs : Nat
  minNs : Nat
  maxNs : Nat

def measure (plans : List Plan) (data : List Case) (rounds : Nat) :
    IO (List Measurement) := do
  let sink ← IO.mkRef 0
  -- Warm up each candidate. Alternate order to reduce systematic order bias.
  for p in plans do runBatch sink p data
  let mut samples := plans.map fun p => (p, ([] : List Nat))
  for round in List.range rounds do
    for p in (if round % 2 == 0 then plans else plans.reverse) do
      let start ← IO.monoNanosNow
      runBatch sink p data
      let elapsed := (← IO.monoNanosNow) - start
      samples := samples.map fun (q, times) =>
        (q, if p == q then elapsed :: times else times)
  return samples.map fun (p, times) =>
    let ordered := LeanSort.Merge.mergeSortResult times
    ⟨p, ordered[ordered.length / 2]!, ordered.head!, ordered.getLast!⟩

def printMeasurements (phase : String) (results : List Measurement) : IO Unit := do
  for r in results do
    IO.println s!"{phase},{r.plan.name},{r.medianNs},{r.minNs},{r.maxNs}"

def main (args : List String) : IO UInt32 := do
  unless args == [] || args == ["--smoke"] do
    IO.eprintln "usage: lake env lean --run experiments/hybrid-threshold/Main.lean [--smoke]"
    return 2
  let smoke := args == ["--smoke"]
  let train := cases (if smoke then [8, 16] else [32, 96]) [17, 29]
  let heldout := cases (if smoke then [12, 24] else [48, 128]) [41, 53]
  let thresholds := [1, 8, 24, 64]
  let hybrids := thresholds.map Plan.hybrid
  let baselines := [Plan.merge, Plan.insertion]
  let rounds := if smoke then 1 else 5
  -- These checks are finite regressions, separate from the universal Lean proof.
  validate (hybrids ++ baselines) train
  let training ← measure (hybrids ++ baselines) train rounds
  -- Select one global threshold using training data only. Baselines are not
  -- eligible thresholds and held-out measurements never influence selection.
  let eligible := training.filter fun r => match r.plan with
    | .hybrid _ => true
    | _ => false
  let some first := eligible.head? | throw (IO.userError "no candidate thresholds")
  let winner := eligible.foldl (fun best r =>
    if r.medianNs < best.medianNs then r else best) first
  IO.println s!"mode={if smoke then "smoke" else "experiment"}; rounds={rounds}; train_cases={train.length}; heldout_cases={heldout.length}"
  IO.println "phase,plan,median_batch_ns,min_batch_ns,max_batch_ns"
  printMeasurements "train" training
  IO.println s!"selected_from_training={winner.plan.name}"
  validate (winner.plan :: baselines) heldout
  let testing ← measure (winner.plan :: baselines) heldout rounds
  printMeasurements "heldout" testing
  IO.println "All measured outputs passed finite regression checks."
  IO.println "Timings include output consumption; no claim of global optimality or speedup."
  return 0

end HybridThresholdExperiment

def main := HybridThresholdExperiment.main
