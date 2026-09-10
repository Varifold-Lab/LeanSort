import LeanSort.Verification.Pancake.Trace

namespace LeanSort.Pancake

#guard flip 3 [3, 1, 2, 9] = [2, 1, 3, 9]
#guard replay [3, 2] [3, 1, 2] = [1, 2, 3]

#guard pancakeSort [3, 1, 2] = [1, 2, 3]
#guard pancakeSortTrace [3, 1, 2] = [3, 2]

#guard pancakeSort [5, 4, 3, 2, 1] = [1, 2, 3, 4, 5]
#guard pancakeSort [1, 2, 3, 4, 5] = [1, 2, 3, 4, 5]
#guard pancakeSortTrace [1, 2, 3, 4, 5] = []
#guard pancakeSort [2, 7, 1, 8, 2, 8] = [1, 2, 2, 7, 8, 8]
#guard pancakeSort ([-1, 3, 0] : List Int) = [-1, 0, 3]

#guard replay (pancakeSortTrace [3, 1, 2]) [3, 1, 2] = pancakeSort [3, 1, 2]
#guard replay (pancakeSortTrace [5, 4, 3, 2, 1]) [5, 4, 3, 2, 1] =
  pancakeSort [5, 4, 3, 2, 1]
#guard replay (pancakeSortTrace [2, 7, 1, 8, 2, 8]) [2, 7, 1, 8, 2, 8] =
  pancakeSort [2, 7, 1, 8, 2, 8]
#guard replay (pancakeSortTrace [4, 1, 5, 2, 3]) [4, 1, 5, 2, 3] = [1, 2, 3, 4, 5]

#guard (pancakeSortTrace [4, 1, 5, 2, 3]).all (2 ≤ ·)
#guard (pancakeSortTrace [4, 1, 5, 2, 3]).length ≤ 2 * 5 - 3

-- All three round branches preserve the suffix; ties select the leftmost maximum.
#guard round 3 [1, 2, 3, 0] = ([1, 2, 3, 0], [])
#guard round 3 [3, 1, 2, 0] = ([2, 1, 3, 0], [3])
#guard round 3 [1, 3, 2, 0] = ([2, 1, 3, 0], [2, 3])
#guard maxIdx [2, 3, 3] = 1
#guard round 3 [2, 3, 3, 0] = ([3, 2, 3, 0], [2, 3])

-- Checked replay rejects degenerate and out-of-bounds moves.
#guard replayChecked? [0] [3, 1, 2] = none
#guard replayChecked? [1] [3, 1, 2] = none
#guard replayChecked? [4] [3, 1, 2] = none
#guard replayChecked? [3, 2] [3, 1, 2] = some [1, 2, 3]
#guard replayChecked? [3, 4] [3, 1, 2] = none
#guard replayChecked? [] ([] : List Nat) = some []
-- Valid moves need not sort, and are not required to be the generated trace.
#guard replayChecked? [2] [1, 2, 3] = some [2, 1, 3]

-- All 364 lists of length at most five over {0, 1, 2}, and each active prefix.
#guard (List.range 6).all fun n =>
  ((List.replicate n [0, 1, 2]).sections).all fun xs =>
    let cert := pancakeSortCertificate xs
    cert.output == xs.mergeSort &&
      replayChecked? cert.trace xs == some cert.output &&
      cert.trace.length ≤ 2 * xs.length &&
      (List.range (n + 1)).all fun k =>
        let (result, trace) := sortAux k xs
        result == (xs.take k).mergeSort ++ xs.drop k &&
          replayChecked? trace xs == some result &&
          trace.all (fun j => 2 ≤ j && j ≤ k)

end LeanSort.Pancake
