import LeanSort.Algorithm.Direct.Engine

namespace LeanSort.Direct
open Comparison RunAdaptive

@[noinline] def scan {α : Type} [LinearOrder α] (xs : List α) : List (List α) :=
  Engine.discover plainCompare xs
@[noinline] def scanCounted {α : Type} [LinearOrder α] (xs : List α) : Result (List (List α)) :=
  Engine.discover countedCompare xs
@[noinline] def merge {α : Type} [LinearOrder α] (xs ys : List α) : List α :=
  Engine.merge plainCompare xs ys
@[noinline] def mergeCounted {α : Type} [LinearOrder α] (xs ys : List α) : Result (List α) :=
  Engine.merge countedCompare xs ys
@[noinline] def tree {α : Type} [LinearOrder α] (t : MergeTree α) : List α :=
  Engine.tree plainCompare t
@[noinline] def treeCounted {α : Type} [LinearOrder α] (t : MergeTree α) : Result (List α) :=
  Engine.tree countedCompare t
@[noinline] def run {α : Type} [LinearOrder α] (s : Strategy) (xs : List α) : List α :=
  Engine.strategy plainCompare s xs
@[noinline] def runCounted {α : Type} [LinearOrder α] (s : Strategy) (xs : List α) : Result (List α) :=
  Engine.strategy countedCompare s xs

end LeanSort.Direct
