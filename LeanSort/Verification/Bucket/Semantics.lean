import LeanSort.Verification.Bucket.Trace

/-! Extensional distribution contracts and checked sorting certificates. -/

namespace LeanSort.Bucket

/-- Each bucket is exactly the stable subsequence assigned to its interval.
The contract specifies allocation and contents independently of the scatter fold. -/
structure DistributionSpec (xs : List Nat) (buckets : Array (List Nat)) : Prop where
  size_eq : buckets.size = bucketCount xs
  contents : ∀ i, i < bucketCount xs →
    buckets[i]?.getD [] = xs.filter (fun x => x / bucketWidth xs == i)

theorem distribute_spec (xs : List Nat) : DistributionSpec xs (distribute xs) :=
  ⟨distribute_size xs, distribute_get xs⟩

theorem DistributionSpec.eq_distribute {xs : List Nat} {buckets : Array (List Nat)}
    (h : DistributionSpec xs buckets) : buckets = distribute xs := by
  apply Array.ext
  · simp [h.size_eq]
  · intro i hi hj
    have hib : i < bucketCount xs := by simpa [h.size_eq] using hi
    have he := (h.contents i hib).trans (distribute_get xs i hib).symm
    simpa [Array.getElem?_eq_getElem hi, Array.getElem?_eq_getElem hj] using he

/-- Any array satisfying the distribution contract produces a sorted permutation. -/
theorem DistributionSpec.output {xs : List Nat} {buckets : Array (List Nat)}
    (h : DistributionSpec xs buckets) : IsSortingResult (· ≤ ·) xs (bucketOutput buckets) := by
  rw [h.eq_distribute]
  exact bucketSortResult_spec xs

structure Certificate (xs : List Nat) where
  output : List Nat
  trace : List Placement
  accepted : replayChecked? trace xs = some output

theorem Certificate.output_eq {xs : List Nat} (c : Certificate xs) :
    c.output = bucketSortResult xs := (replayChecked?_iff xs c.output c.trace).mp c.accepted |>.2

theorem Certificate.trace_eq {xs : List Nat} (c : Certificate xs) :
    c.trace = bucketSortTrace xs := (replayChecked?_iff xs c.output c.trace).mp c.accepted |>.1

theorem Certificate.correct {xs : List Nat} (c : Certificate xs) :
    IsSortingResult (· ≤ ·) xs c.output := replayChecked?_spec xs c.output c.trace c.accepted

def bucketSortCertificate (xs : List Nat) : Certificate xs :=
  ⟨bucketSortResult xs, bucketSortTrace xs, replay_bucketSortTrace xs⟩

end LeanSort.Bucket
