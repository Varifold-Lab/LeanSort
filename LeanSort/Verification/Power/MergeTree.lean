import LeanSort.Verification.Power.NodePower
import LeanSort.Verification.Power.Correctness

/-! A refinement of the existing scheduler to alphabetic merge trees.
Midpoints refer to original runs, including after a collapse. -/

namespace LeanSort.Power

inductive MergeTree (α : Type*) where
  | leaf (values : List α) (midpoint : Nat)
  | join (left right : MergeTree α)
  deriving Repr

namespace MergeTree

variable {α : Type*}

def eval (le : α → α → Bool) : MergeTree α → List α
  | .leaf xs _ => xs
  | .join l r => (l.eval le).merge (r.eval le) le

def size : MergeTree α → Nat
  | .leaf xs _ => xs.length
  | .join l r => l.size + r.size

def height : MergeTree α → Nat
  | .leaf .. => 0
  | .join l r => max l.height r.height + 1

def midpoint : MergeTree α → Nat
  | .leaf _ m => m
  | .join l _ => l.midpoint

@[simp] theorem eval_length (le : α → α → Bool) (t : MergeTree α) :
    (t.eval le).length = t.size := by
  induction t with
  | leaf => rfl
  | join l r hl hr => simp [eval, size, hl, hr]

end MergeTree

structure TreePending (α : Type*) where
  tree : MergeTree α
  power : Nat
  deriving Repr

variable {α : Type*}

def TreePending.erase (le : α → α → Bool) (t : TreePending α) : Pending α :=
  ⟨t.tree.eval le, t.power⟩

def collapseTree (p : Nat) : List (TreePending α) → MergeTree α →
    MergeTree α × List (TreePending α)
  | [], current => (current, [])
  | top :: rest, current =>
    if top.power > p then collapseTree p rest (.join top.tree current)
    else (current, top :: rest)

def finishTree : List (TreePending α) → MergeTree α → MergeTree α
  | [], current => current
  | top :: rest, current => finishTree rest (.join top.tree current)

def scheduleTree (n : Nat) : List (List α) → Nat → List α → List (TreePending α) → MergeTree α
  | [], start, current, stack => finishTree stack (.leaf current (2*start+current.length))
  | next :: rest, start, current, stack =>
    let p := nodePower n start current.length next.length
    let result := collapseTree p stack (.leaf current (2*start+current.length))
    scheduleTree n rest (start+current.length) next (⟨result.1, p⟩ :: result.2)

theorem collapseTree_eval (le : α → α → Bool) (p : Nat)
    (stack : List (TreePending α)) (current : MergeTree α) :
    ((collapseTree p stack current).1.eval le,
      (collapseTree p stack current).2.map (TreePending.erase le)) =
      collapse le p (stack.map (TreePending.erase le)) (current.eval le) := by
  induction stack generalizing current with
  | nil => rfl
  | cons top rest ih =>
    simp only [collapseTree, List.map_cons, collapse, TreePending.erase]
    split
    · exact ih (.join top.tree current)
    · rfl

theorem finishTree_eval (le : α → α → Bool)
    (stack : List (TreePending α)) (current : MergeTree α) :
    (finishTree stack current).eval le =
      finishStack le (stack.map (TreePending.erase le)) (current.eval le) := by
  induction stack generalizing current with
  | nil => rfl
  | cons top rest ih => exact ih (.join top.tree current)

theorem scheduleTree_eval (le : α → α → Bool) (n : Nat) (runs : List (List α))
    (start : Nat) (current : List α) (stack : List (TreePending α)) :
    (scheduleTree n runs start current stack).eval le =
      mergeRuns le n runs start current (stack.map (TreePending.erase le)) := by
  induction runs generalizing start current stack with
  | nil => exact finishTree_eval le stack _
  | cons next rest ih =>
    simp only [scheduleTree, ih, List.map_cons, TreePending.erase, mergeRuns]
    have h := collapseTree_eval le (nodePower n start current.length next.length)
      stack (.leaf current (2*start+current.length))
    have h1 := congrArg Prod.fst h
    have h2 := congrArg Prod.snd h
    simp only [MergeTree.eval] at h1 h2
    rw [h1, h2]

/-- Each pending boundary separates the representatives of its neighboring
blocks. Powers strictly increase toward the top of the stack. -/
inductive StackValid (n : Nat) : List (TreePending α) → Nat → Prop
  | nil (m : Nat) : StackValid n [] m
  | cons (top : TreePending α) (rest : List (TreePending α)) (m : Nat)
      (gap : top.tree.midpoint + 2 ≤ m)
      (rank : top.power = midpointPower n top.tree.midpoint m)
      (height : top.tree.height + top.power ≤ maxPower n)
      (increasing : ∀ t ∈ rest, t.power < top.power)
      (tail : StackValid n rest top.tree.midpoint) : StackValid n (top :: rest) m

theorem StackValid.power_le {n m : Nat} {stack : List (TreePending α)}
    (h : StackValid n stack m) : ∀ t ∈ stack, t.power ≤ maxPower n := by
  induction h with
  | nil => simp
  | cons top rest m gap rank height increasing tail ih =>
    intro t ht
    rcases List.mem_cons.mp ht with rfl | ht
    · omega
    · exact ih _ ht

theorem collapseTree_valid {n next p : Nat} (hn : 0 < n) (hnext : next < 2*n)
    (stack : List (TreePending α)) (current : MergeTree α)
    (hv : StackValid n stack current.midpoint)
    (hgap : current.midpoint + 2 ≤ next)
    (hp : p = midpointPower n current.midpoint next)
    (hheight : current.height + p ≤ maxPower n)
    (hfit : ∀ t ∈ stack, current.height + t.power ≤ maxPower n) :
    let result := collapseTree p stack current
    StackValid n result.2 result.1.midpoint ∧
      (∀ t ∈ result.2, t.power < p) ∧
      result.1.height + p ≤ maxPower n ∧
      result.1.midpoint + 2 ≤ next ∧ p = midpointPower n result.1.midpoint next := by
  induction stack generalizing current with
  | nil =>
    dsimp only [collapseTree]
    exact ⟨.nil _, by simp, hheight, hgap, hp⟩
  | cons top rest ih =>
    cases hv with
    | cons _ _ _ gap rank height increasing tail =>
      simp only [collapseTree]
      split
      · rename_i hpop
        apply ih (.join top.tree current) tail
        · simpa only [MergeTree.midpoint] using (show top.tree.midpoint + 2 ≤ next by omega)
        · simp only [MergeTree.midpoint]
          rw [midpointPower_outer hn gap hgap, ← rank, ← hp, min_eq_right (by omega)]
        · have hf := hfit top (by simp)
          simp only [MergeTree.height]
          omega
        · intro t ht
          have hlt := increasing t ht
          have hf := hfit top (by simp)
          simp only [MergeTree.height]
          omega
      · rename_i hstop
        have hne : top.power ≠ p := by
          rw [rank, hp]
          exact midpointPower_adjacent_ne hn gap hgap hnext
        have hlt : top.power < p := by omega
        refine ⟨.cons top rest _ gap rank height increasing tail, ?_, hheight, hgap, hp⟩
        intro t ht
        rcases List.mem_cons.mp ht with rfl | ht
        · exact hlt
        · exact lt_trans (increasing t ht) hlt

theorem finishTree_height {n : Nat} (hn : 0 < n)
    (stack : List (TreePending α)) (current : MergeTree α)
    (hv : StackValid n stack current.midpoint) (hm : current.midpoint < 2*n)
    (hheight : current.height ≤ maxPower n)
    (hfit : ∀ t ∈ stack, current.height + t.power ≤ maxPower n) :
    (finishTree stack current).height ≤ maxPower n := by
  induction stack generalizing current with
  | nil => exact hheight
  | cons top rest ih =>
    cases hv with
    | cons _ _ _ gap rank height increasing tail =>
      have hp : 0 < top.power := rank ▸ midpointPower_pos hn gap hm
      have hf := hfit top (by simp)
      apply ih (.join top.tree current) tail
      · simp only [MergeTree.midpoint]; omega
      · simp only [MergeTree.height]; omega
      · intro t ht
        have hlt := increasing t ht
        simp only [MergeTree.height]
        omega

theorem scheduleTree_height {n : Nat} (hn : 0 < n) (runs : List (List α))
    (start : Nat) (current : List α) (stack : List (TreePending α))
    (hc : 0 < current.length) (hr : ∀ r ∈ runs, 0 < r.length)
    (hsize : start + current.length + runs.flatten.length ≤ n)
    (hv : StackValid n stack (2*start+current.length)) :
    (scheduleTree n runs start current stack).height ≤ maxPower n := by
  induction runs generalizing start current stack with
  | nil =>
    apply finishTree_height hn _ _ hv
    · simp only [MergeTree.midpoint]; simp only [List.flatten_nil, List.length_nil] at hsize; omega
    · simp [MergeTree.height]
    · simpa only [MergeTree.height, Nat.zero_add] using hv.power_le
  | cons next rest ih =>
    have hnext := hr next (by simp)
    have hsz : start + current.length + next.length + rest.flatten.length ≤ n := by
      simpa [List.flatten_cons, List.length_append, Nat.add_assoc] using hsize
    have hp := nodePower_bounds hc hnext (by omega : start + current.length + next.length ≤ n)
    have hh := collapseTree_valid (p := nodePower n start current.length next.length) hn
      (show 2*(start+current.length)+next.length < 2*n by omega)
      stack (.leaf current (2*start+current.length)) hv
      (by simp only [MergeTree.midpoint]; omega)
      (by rw [nodePower_eq]; unfold midpointPower maxPower; simp only [MergeTree.midpoint]; congr 1; omega)
      (by simpa only [MergeTree.height, Nat.zero_add] using hp.2)
      (by simpa only [MergeTree.height, Nat.zero_add] using hv.power_le)
    dsimp only [scheduleTree]
    apply ih _ _ _ hnext (fun r h => hr r (by simp [h])) (by omega)
    exact .cons _ _ _ hh.2.2.2.1 hh.2.2.2.2 hh.2.2.1 hh.2.1 hh.1

end LeanSort.Power
