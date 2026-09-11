import LeanSort.Verification.Radix.Cost

/-! Local binary-digit rules and their composition into scheduled LSD passes.
Arbitrary schedules have execution semantics; low-bit sortedness requires the
specified increasing bit schedule and the corresponding input invariant. -/

namespace LeanSort.Radix

/-- Stable bucket construction, independently specified by digit values. -/
inductive PartitionDerivation (bit : ℕ) :
    List ℕ → List ℕ → List ℕ → List Bool → Prop where
  | nil : PartitionDerivation bit [] [] [] []
  | zero {x xs zeros ones ds} : x / 2 ^ bit % 2 = 0 →
      PartitionDerivation bit xs zeros ones ds →
      PartitionDerivation bit (x :: xs) (x :: zeros) ones (true :: ds)
  | one {x xs zeros ones ds} : x / 2 ^ bit % 2 = 1 →
      PartitionDerivation bit xs zeros ones ds →
      PartitionDerivation bit (x :: xs) zeros (x :: ones) (false :: ds)

theorem PartitionDerivation.execution {bit : ℕ} {xs zeros ones : List ℕ}
    {ds : List Bool} (h : PartitionDerivation bit xs zeros ones ds) :
    partitionTrace bit xs = ((zeros, ones), ds) := by
  induction h with
  | nil => rfl
  | zero h _ ih => simp [partitionTrace, h, ih]
  | one h _ ih => simp [partitionTrace, h, ih]

theorem partitionTrace_derivation (bit : ℕ) (xs : List ℕ) :
    PartitionDerivation bit xs (partitionTrace bit xs).1.1
      (partitionTrace bit xs).1.2 (partitionTrace bit xs).2 := by
  induction xs with
  | nil => exact .nil
  | cons x xs ih =>
      by_cases h : x / 2 ^ bit % 2 = 0
      · simpa [partitionTrace, h] using PartitionDerivation.zero h ih
      · have h1 : x / 2 ^ bit % 2 = 1 := by omega
        simpa [partitionTrace, h] using PartitionDerivation.one h1 ih

theorem partitionDerivation_iff (bit : ℕ) (xs zeros ones : List ℕ) (ds : List Bool) :
    PartitionDerivation bit xs zeros ones ds ↔ partitionTrace bit xs = ((zeros, ones), ds) := by
  refine ⟨PartitionDerivation.execution, ?_⟩
  intro h
  simpa only [h] using partitionTrace_derivation bit xs

/-- Filter identities express relative-order preservation inside both buckets. -/
structure PartitionSpec (bit : ℕ) (xs zeros ones : List ℕ) (ds : List Bool) : Prop where
  zeros_eq : zeros = xs.filter (fun x => decide (x / 2 ^ bit % 2 = 0))
  ones_eq : ones = xs.filter (fun x => !decide (x / 2 ^ bit % 2 = 0))
  perm : (zeros ++ ones).Perm xs
  choice_count : ds.length = xs.length

theorem PartitionDerivation.spec {bit : ℕ} {xs zeros ones : List ℕ}
    {ds : List Bool} (h : PartitionDerivation bit xs zeros ones ds) :
    PartitionSpec bit xs zeros ones ds := by
  have hp := partitionTrace_parts bit xs
  have hc := partitionTrace_choice_count bit xs
  rw [h.execution] at hp hc
  change (zeros, ones) = xs.partition (fun x => decide (x / 2 ^ bit % 2 = 0)) at hp
  have hz := congrArg Prod.fst hp
  have ho := congrArg Prod.snd hp
  refine ⟨?_, ?_, ?_, hc⟩
  · simpa [List.partition_eq_filter_filter] using hz
  · simpa [List.partition_eq_filter_filter, Function.comp_def] using ho
  · have he : zeros ++ ones = digitPass bit xs := by
      rw [digitPass, h.execution]
    rw [he]
    exact digitPass_perm bit xs

/-- One pass joins the two stable buckets and records the processed bit. -/
inductive DigitDerivation (bit : ℕ) : List ℕ → DigitStep → List ℕ → Prop where
  | join {xs zeros ones ds} : PartitionDerivation bit xs zeros ones ds →
      DigitDerivation bit xs ⟨bit, ds⟩ (zeros ++ ones)

theorem DigitDerivation.execution {bit : ℕ} {xs ys : List ℕ} {step : DigitStep}
    (h : DigitDerivation bit xs step ys) :
    ys = digitPass bit xs ∧ step = ⟨bit, (partitionTrace bit xs).2⟩ := by
  cases h with
  | join hp => simp [digitPass, hp.execution]

theorem digitPass_derivation (bit : ℕ) (xs : List ℕ) :
    DigitDerivation bit xs ⟨bit, (partitionTrace bit xs).2⟩ (digitPass bit xs) :=
  .join (partitionTrace_derivation bit xs)

theorem replayDigit_iff_derivation (bit : ℕ) (xs ys : List ℕ) (step : DigitStep) :
    replayDigit bit xs step = some ys ↔ DigitDerivation bit xs step ys := by
  rw [replayDigit_iff]
  constructor
  · rintro ⟨rfl, rfl⟩
    exact digitPass_derivation bit xs
  · exact DigitDerivation.execution

/-- A legal pass advances the low-bit invariant only when its precondition holds. -/
theorem DigitDerivation.sortedBits {bit : ℕ} {xs ys : List ℕ} {step : DigitStep}
    (h : DigitDerivation bit xs step ys) (hs : SortedBits bit xs) : SortedBits (bit + 1) ys := by
  rw [h.execution.1]
  exact digitPass_sortedBits bit xs hs

/-- Composition requires exactly the supplied schedule, including empty passes. -/
inductive PassesDerivation : List ℕ → List ℕ → List DigitStep → List ℕ → Prop where
  | nil (xs) : PassesDerivation [] xs [] xs
  | cons {bit bits xs next ys step rest} : DigitDerivation bit xs step next →
      PassesDerivation bits next rest ys →
      PassesDerivation (bit :: bits) xs (step :: rest) ys

theorem PassesDerivation.replay {bits xs ys : List ℕ} {trace : List DigitStep}
    (h : PassesDerivation bits xs trace ys) : replayPasses bits xs trace = some ys := by
  induction h with
  | nil => rfl
  | cons hd _ ih =>
      simp only [replayPasses, (replayDigit_iff_derivation _ _ _ _).mpr hd, Option.bind_some, ih]

theorem passesTrace_derivation (bits xs : List ℕ) :
    PassesDerivation bits xs (passesTrace bits xs).2 (passesTrace bits xs).1 := by
  induction bits generalizing xs with
  | nil => exact .nil xs
  | cons bit bits ih =>
      exact .cons (digitPass_derivation bit xs) (ih (digitPass bit xs))

theorem passesDerivation_iff (bits xs ys : List ℕ) (trace : List DigitStep) :
    PassesDerivation bits xs trace ys ↔ passesTrace bits xs = (ys, trace) := by
  constructor
  · intro h
    exact (replayPasses_iff _ _ _ _).mp h.replay
  · intro h
    simpa only [h] using passesTrace_derivation bits xs

theorem replayPasses_iff_derivation (bits xs ys : List ℕ) (trace : List DigitStep) :
    replayPasses bits xs trace = some ys ↔ PassesDerivation bits xs trace ys :=
  (replayPasses_iff _ _ _ _).trans (passesDerivation_iff _ _ _ _).symm

theorem PassesDerivation.deterministic {bits xs ys zs : List ℕ} {t u : List DigitStep}
    (h : PassesDerivation bits xs t ys) (k : PassesDerivation bits xs u zs) : ys = zs ∧ t = u :=
  Prod.mk.inj (((passesDerivation_iff _ _ _ _).mp h).symm.trans
    ((passesDerivation_iff _ _ _ _).mp k))

theorem PassesDerivation.perm {bits xs ys : List ℕ} {trace : List DigitStep}
    (h : PassesDerivation bits xs trace ys) : ys.Perm xs := by
  rw [replayPasses_sound _ _ _ _ h.replay]
  exact passes_perm bits xs

/-- Low-bit order is guaranteed for the canonical prefix of the LSD schedule. -/
theorem PassesDerivation.sortedBits {bits : ℕ} {xs ys : List ℕ} {trace : List DigitStep}
    (h : PassesDerivation (List.range bits) xs trace ys) : SortedBits bits ys := by
  rw [replayPasses_sound _ _ _ _ h.replay]
  exact passes_sortedBits bits xs

theorem PassesDerivation.cost {bits xs ys : List ℕ} {trace : List DigitStep}
    (h : PassesDerivation bits xs trace ys) : traceCost trace = bits.length * xs.length := by
  have he := (passesDerivation_iff _ _ _ _).mp h
  simpa only [he] using passesTrace_cost bits xs

theorem passesTrace_schedule (bits xs : List ℕ) :
    ((passesTrace bits xs).2.map DigitStep.bit) = bits := by
  induction bits generalizing xs with
  | nil => rfl
  | cons bit bits ih => simp [passesTrace, ih]

theorem PassesDerivation.schedule {bits xs ys : List ℕ} {trace : List DigitStep}
    (h : PassesDerivation bits xs trace ys) : trace.map DigitStep.bit = bits := by
  have he := (passesDerivation_iff _ _ _ _).mp h
  simpa only [he] using passesTrace_schedule bits xs

/-- Execution identity certifies the canonical LSD schedule and all its decisions. -/
structure Certificate (input : List ℕ) where
  output : List ℕ
  trace : List DigitStep
  execution : sortTrace input = (output, trace)

def radixSortCertificate (xs : List ℕ) : Certificate xs :=
  ⟨(sortTrace xs).1, (sortTrace xs).2, rfl⟩

theorem Certificate.replay {xs : List ℕ} (c : Certificate xs) : replay xs c.trace = some c.output :=
  (replay_iff _ _ _).mpr c.execution

theorem Certificate.derivation {xs : List ℕ} (c : Certificate xs) :
    PassesDerivation (List.range (radixBits xs)) xs c.trace c.output :=
  (passesDerivation_iff _ _ _ _).mpr c.execution

theorem Certificate.spec {xs : List ℕ} (c : Certificate xs) :
    LeanSort.IsSortingResult (· ≤ ·) xs c.output := replay_sound _ _ _ c.replay

theorem Certificate.cost {xs : List ℕ} (c : Certificate xs) :
    traceCost c.trace = xs.length * radixBits xs := by
  have h := digitTests_eq xs
  simpa only [digitTests, radixSortTrace, c.execution] using h

theorem Certificate.rounds {xs : List ℕ} (c : Certificate xs) : c.trace.length = radixBits xs := by
  simpa only [radixSortTrace, c.execution] using radixSortTrace_round_count xs

end LeanSort.Radix
