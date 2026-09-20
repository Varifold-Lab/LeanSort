import LeanSort.Verification.Tree.Trace

/-! Relational insertion semantics and checked sorting certificates. -/

namespace LeanSort.Tree

variable {α : Type*} [LinearOrder α]

/-- A path describes actual BST insertion steps, ending exactly at an empty
leaf. Unvisited subtrees are preserved, and ties must take the right branch. -/
inductive InsertionDerivation (x : α) : SearchTree α → SearchTree α → List Bool → Prop
  | leaf : InsertionDerivation x .empty (.node .empty x .empty) []
  | left {l l' r : SearchTree α} {v : α} {path : List Bool}
      (branch : x < v) (next : InsertionDerivation x l l' path) :
      InsertionDerivation x (.node l v r) (.node l' v r) (true :: path)
  | right {l r r' : SearchTree α} {v : α} {path : List Bool}
      (branch : ¬ x < v) (next : InsertionDerivation x r r' path) :
      InsertionDerivation x (.node l v r) (.node l v r') (false :: path)

theorem InsertionDerivation.execution {x : α} {before after : SearchTree α}
    {path : List Bool} (h : InsertionDerivation x before after path) :
    after = insert x before ∧ path = insertionPath x before := by
  induction h with
  | leaf => simp [insert, insertionPath]
  | left h _ ih => simp [insert, insertionPath, h, ih.1, ih.2]
  | right h _ ih => simp [insert, insertionPath, h, ih.1, ih.2]

theorem insertion_derivation (x : α) (t : SearchTree α) :
    InsertionDerivation x t (insert x t) (insertionPath x t) := by
  induction t with
  | empty => exact .leaf
  | node l v r ihl ihr =>
      by_cases h : x < v
      · simpa [insert, insertionPath, h] using
          (InsertionDerivation.left (r := r) h ihl)
      · simpa [insert, insertionPath, h] using
          (InsertionDerivation.right (l := l) h ihr)

theorem insertionDerivation_iff (x : α) (before after : SearchTree α) (path : List Bool) :
    InsertionDerivation x before after path ↔
      after = insert x before ∧ path = insertionPath x before := by
  constructor
  · exact InsertionDerivation.execution
  · rintro ⟨rfl, rfl⟩
    exact insertion_derivation x before

/-- The executable checker is sound and complete for the relational semantics. -/
theorem replayInsert?_derivation_iff (x : α) (before after : SearchTree α) (path : List Bool) :
    replayInsert? x before path = some after ↔ InsertionDerivation x before after path := by
  rw [replayInsert?_eq, insertionDerivation_iff]
  by_cases h : path = insertionPath x before <;> simp [h, eq_comm]

/-- A result and a comparison log accompanied by successful checked replay. -/
structure Certificate (xs : List α) where
  output : List α
  trace : List (List Bool)
  accepted : replayChecked? trace xs = some output

theorem Certificate.output_eq {xs : List α} (c : Certificate xs) :
    c.output = treeSortResult xs := (replayChecked?_iff xs c.output c.trace).mp c.accepted |>.2

theorem Certificate.trace_eq {xs : List α} (c : Certificate xs) :
    c.trace = treeSortTrace xs := (replayChecked?_iff xs c.output c.trace).mp c.accepted |>.1

theorem Certificate.correct {xs : List α} (c : Certificate xs) :
    IsSortingResult (· ≤ ·) xs c.output := replayChecked?_spec xs c.output c.trace c.accepted

def treeSortCertificate (xs : List α) : Certificate xs :=
  ⟨treeSortResult xs, treeSortTrace xs, replay_treeSortTrace xs⟩

end LeanSort.Tree
