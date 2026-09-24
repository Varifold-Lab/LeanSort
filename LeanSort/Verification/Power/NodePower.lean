import LeanSort.Verification.Power.Equations
import Mathlib.Tactic.Linarith
import Mathlib.Tactic.Ring

namespace LeanSort.Power

/-- Integer dyadic bucket containing the rational point `a / d` at level `k`. -/
def bucket (d a k : Nat) : Nat := (2 ^ k * a) / d

/-- The first binary level at which the two normalized midpoints separate. -/
structure FirstDifference (d a b p : Nat) : Prop where
  different : bucket d a p ≠ bucket d b p
  earlier : ∀ k < p, bucket d a k = bucket d b k

theorem powerLoop_le (d fuel a b : Nat) : powerLoop d fuel a b ≤ fuel := by
  induction fuel generalizing a b with
  | zero => rfl
  | succ fuel ih => simp only [powerLoop]; split <;> first | omega | have := ih (2*a) (2*b); omega

theorem bucket_double (d a k : Nat) : bucket d (2 * a) k = bucket d a (k + 1) := by
  simp [bucket, pow_succ, Nat.mul_assoc, Nat.mul_comm]

theorem powerLoop_spec (d fuel a b : Nat) (h : bucket d a fuel ≠ bucket d b fuel) :
    FirstDifference d a b (powerLoop d fuel a b) := by
  induction fuel generalizing a b with
  | zero => exact ⟨h, by simp⟩
  | succ fuel ih =>
    simp only [powerLoop]
    split
    · exact ⟨by simpa [bucket] using ‹a / d ≠ b / d›, by omega⟩
    · rename_i he
      have hh := ih (2*a) (2*b) (by simpa [bucket_double] using h)
      constructor
      · simpa [Nat.add_comm, bucket_double] using hh.different
      · intro k hk
        cases k with
        | zero => simpa [bucket] using not_not.mp he
        | succ k => simpa [bucket_double] using hh.earlier k (by omega)

theorem FirstDifference.unique {d a b p q : Nat}
    (hp : FirstDifference d a b p) (hq : FirstDifference d a b q) : p = q := by
  by_contra h
  rcases lt_or_gt_of_ne h with h | h
  · exact hp.different (hq.earlier p h)
  · exact hq.different (hp.earlier q h)

theorem bucket_mono (d k : Nat) {a b : Nat} (h : a ≤ b) : bucket d a k ≤ bucket d b k :=
  Nat.div_le_div_right (Nat.mul_le_mul_left _ h)

theorem FirstDifference.outer {d a b c p q : Nat} (hab : a ≤ b) (hbc : b ≤ c)
    (hp : FirstDifference d a b p) (hq : FirstDifference d b c q) :
    FirstDifference d a c (min p q) := by
  constructor
  · by_cases h : p ≤ q
    · rw [min_eq_left h]
      have h1 := bucket_mono d p hab
      have h2 := bucket_mono d p hbc
      have := hp.different
      omega
    · rw [min_eq_right (by omega)]
      have h1 := bucket_mono d q hab
      have h2 := bucket_mono d q hbc
      have := hq.different
      omega
  · intro k hk
    exact (hp.earlier k (by omega)).trans (hq.earlier k (by omega))

theorem bucket_parent (d a k : Nat) : bucket d a (k + 1) / 2 = bucket d a k := by
  simp only [bucket, pow_succ, Nat.div_div_eq_div_mul]
  rw [Nat.mul_comm d 2]
  rw [show 2 ^ k * 2 * a = 2 * (2 ^ k * a) by ring]
  exact Nat.mul_div_mul_left _ _ (by decide)

/-- Consecutive ordered pairs cannot cross the same dyadic boundary twice. -/
theorem FirstDifference.adjacent_ne {d a b c p : Nat}
    (hab : a ≤ b) (hbc : b ≤ c) (h0 : bucket d a 0 = bucket d c 0)
    (hp : FirstDifference d a b p) (hq : FirstDifference d b c p) : False := by
  cases p with
  | zero =>
    have h1 := bucket_mono d 0 hab
    have h2 := bucket_mono d 0 hbc
    exact hp.different (by omega)
  | succ k =>
    have he1 := hp.earlier k (by omega)
    have he2 := hq.earlier k (by omega)
    have h1 := bucket_mono d (k+1) hab
    have h2 := bucket_mono d (k+1) hbc
    have hd1 := hp.different
    have hd2 := hq.different
    have ha := bucket_parent d a k
    have hb := bucket_parent d b k
    have hc := bucket_parent d c k
    omega

def maxPower (n : Nat) : Nat := n.log2 + 1

theorem bucket_separated (n a b : Nat) (hn : 0 < n) (hab : a + 2 ≤ b) :
    bucket (2*n) a (maxPower n) ≠ bucket (2*n) b (maxPower n) := by
  have hexp : n < 2 ^ (n.log2 + 1) := by
    rw [Nat.log2_eq_log_two]
    exact Nat.lt_pow_succ_log_self (by decide) n
  have hs : 2 ^ maxPower n * a + 2*n ≤ 2 ^ maxPower n * b := by
    unfold maxPower
    nlinarith
  have hh := Nat.div_le_div_right (c := 2*n) hs
  have hd : 0 < 2*n := by omega
  rw [Nat.add_div_right _ hd] at hh
  unfold bucket
  omega

/-- Power between arbitrary ordered run midpoints, represented with denominator `2*n`. -/
def midpointPower (n a b : Nat) : Nat := powerLoop (2*n) (maxPower n) a b

theorem midpointPower_spec {n a b : Nat} (hn : 0 < n) (hab : a + 2 ≤ b) :
    FirstDifference (2*n) a b (midpointPower n a b) :=
  powerLoop_spec _ _ _ _ (bucket_separated n a b hn hab)

theorem midpointPower_le (n a b : Nat) : midpointPower n a b ≤ maxPower n := powerLoop_le ..

theorem midpointPower_pos {n a b : Nat} (hn : 0 < n) (hab : a + 2 ≤ b) (hb : b < 2*n) :
    0 < midpointPower n a b := by
  have h := midpointPower_spec hn hab
  by_contra hp
  have he : midpointPower n a b = 0 := by omega
  have hh := h.different
  simp [he, bucket, Nat.div_eq_of_lt hb, Nat.div_eq_of_lt (show a < 2*n by omega)] at hh

theorem midpointPower_outer {n a b c : Nat} (hn : 0 < n)
    (hab : a + 2 ≤ b) (hbc : b + 2 ≤ c) :
    midpointPower n a c = min (midpointPower n a b) (midpointPower n b c) :=
  (midpointPower_spec hn (by omega : a + 2 ≤ c)).unique
    ((midpointPower_spec hn hab).outer (by omega) (by omega) (midpointPower_spec hn hbc))

theorem midpointPower_adjacent_ne {n a b c : Nat} (hn : 0 < n)
    (hab : a + 2 ≤ b) (hbc : b + 2 ≤ c) (hc : c < 2*n) :
    midpointPower n a b ≠ midpointPower n b c := by
  intro he
  exact FirstDifference.adjacent_ne (by omega : a ≤ b) (by omega : b ≤ c)
    (by simp [bucket, Nat.div_eq_of_lt hc, Nat.div_eq_of_lt (show a < 2*n by omega)])
    (he ▸ midpointPower_spec hn hab) (midpointPower_spec hn hbc)

theorem nodePower_spec {n start left right : Nat} (hl : 0 < left) (hr : 0 < right)
    (hn : start + left + right ≤ n) :
    FirstDifference (2*n) (2*start+left) (2*start+2*left+right)
      (nodePower n start left right) := by
  rw [nodePower_eq]
  exact midpointPower_spec (by omega) (by omega)

theorem nodePower_bounds {n start left right : Nat} (hl : 0 < left) (hr : 0 < right)
    (hn : start + left + right ≤ n) :
    1 ≤ nodePower n start left right ∧ nodePower n start left right ≤ maxPower n := by
  rw [nodePower_eq]
  exact ⟨midpointPower_pos (by omega) (by omega) (by omega), midpointPower_le ..⟩

end LeanSort.Power
