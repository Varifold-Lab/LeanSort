import LeanSort.Semantics.Comparison

/-! Component programs expose every key comparison as an operation node. -/

namespace LeanSort.ComparisonSort
open Comparison

def insert {α : Type} (x : α) : List α → Program α (List α)
  | [] => .pure [x]
  | y :: ys => .compare .sort x y fun smaller =>
      if smaller then .pure (x :: y :: ys)
      else (insert x ys).bind fun rest => .pure (y :: rest)

def insertion {α : Type} : List α → Program α (List α)
  | [] => .pure []
  | x :: xs => (insertion xs).bind fun rest => insert x rest

def merge {α : Type} : List α → List α → Program α (List α)
  | [], ys => .pure ys
  | xs, [] => .pure xs
  | x :: xs, y :: ys => .compare .sort x y fun smaller =>
      if smaller then (merge xs (y :: ys)).bind fun rest => .pure (x :: rest)
      else (merge (x :: xs) ys).bind fun rest => .pure (y :: rest)
termination_by xs ys => xs.length + ys.length

def mergeSort {α : Type} (xs : List α) : Program α (List α) :=
  if xs.length < 2 then .pure xs
  else
    (mergeSort (xs.take (xs.length / 2))).bind fun left =>
    (mergeSort (xs.drop (xs.length / 2))).bind fun right => merge left right
termination_by xs.length
decreasing_by all_goals simp_wf; omega

def hybrid {α : Type} (threshold : Nat) (xs : List α) : Program α (List α) :=
  if xs.length ≤ max 1 threshold then insertion xs
  else
    (hybrid threshold (xs.take (xs.length / 2))).bind fun left =>
    (hybrid threshold (xs.drop (xs.length / 2))).bind fun right => merge left right
termination_by xs.length
decreasing_by all_goals simp_wf; omega

def checkSorted {α : Type} : List α → Program α Bool
  | [] => .pure true
  | [_] => .pure true
  | x :: y :: ys => .compare .check x y fun smaller =>
      if smaller then checkSorted (y :: ys) else .pure false

end LeanSort.ComparisonSort
