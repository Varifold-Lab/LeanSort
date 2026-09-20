import LeanSort.Verification.Bucket.Correctness

/-! Exact placement logs and sound, complete checked replay. -/

namespace LeanSort.Bucket

@[simp] theorem bucketSortTrace_length (xs : List Nat) :
    (bucketSortTrace xs).length = xs.length := by simp [bucketSortTrace]

theorem bucketSortTrace_keys (xs : List Nat) :
    (bucketSortTrace xs).map Prod.fst = xs := by
  simp [bucketSortTrace, List.map_map, Function.comp_def]

theorem bucketSortTrace_indices_lt (xs : List Nat) (step : Placement)
    (hs : step ∈ bucketSortTrace xs) : step.2 < bucketCount xs := by
  obtain ⟨x, hx, rfl⟩ := List.mem_map.mp hs
  exact bucketIndex_lt xs x hx

@[simp] theorem sortTrace_result (xs : List Nat) :
    (sortTrace xs).1 = bucketSortResult xs := rfl

theorem replayScatter?_eq (width : Nat) (xs : List Nat) (trace : List Placement)
    (buckets : Array (List Nat)) (hxs : ∀ x ∈ xs, x / width < buckets.size) :
    replayScatter? width xs trace buckets =
      if trace = xs.map (fun x => (x, x / width)) then some (scatter width xs buckets)
      else none := by
  induction xs generalizing trace buckets with
  | nil => cases trace <;> simp [replayScatter?, scatter]
  | cons x xs ih =>
      have hx := hxs x (by simp)
      cases trace with
      | nil => simp [replayScatter?]
      | cons step steps =>
          have hr : ∀ y ∈ xs, y / width < (buckets.modify (x / width) (x :: ·)).size := by
            intro y hy
            simpa using hxs y (by simp [hy])
          by_cases h : step = (x, x / width)
          · simp [replayScatter?, h, hx, ih _ _ hr, scatter]
          · simp [replayScatter?, h, hx]

theorem replayChecked?_eq (xs : List Nat) (trace : List Placement) :
    replayChecked? trace xs =
      if trace = bucketSortTrace xs then some (bucketSortResult xs) else none := by
  unfold replayChecked?
  rw [replayScatter?_eq _ _ _ _ (fun x hx => by simpa using bucketIndex_lt xs x hx)]
  split <;> simp_all [bucketSortTrace, bucketSortResult, distribute]

@[simp] theorem replay_bucketSortTrace (xs : List Nat) :
    replayChecked? (bucketSortTrace xs) xs = some (bucketSortResult xs) := by
  simp [replayChecked?_eq]

theorem replayChecked?_iff (xs output : List Nat) (trace : List Placement) :
    replayChecked? trace xs = some output ↔
      trace = bucketSortTrace xs ∧ output = bucketSortResult xs := by
  rw [replayChecked?_eq]
  split <;> simp_all [eq_comm]

theorem replayChecked?_spec (xs output : List Nat) (trace : List Placement)
    (h : replayChecked? trace xs = some output) : IsSortingResult (· ≤ ·) xs output := by
  obtain ⟨_, rfl⟩ := (replayChecked?_iff xs output trace).mp h
  exact bucketSortResult_spec xs

end LeanSort.Bucket
