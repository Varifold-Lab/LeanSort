# AKS bitonic interval lemmas

`LeanSort/Verification/Bitonic/Boolean.lean` adapts selected proofs from
[`girving/aks`](https://github.com/girving/aks), distributed under Apache-2.0
(see LICENSE in this directory).

Upstream revision inspected: `c7fb62ed80a4a610f87f34db0082cadbd7c00c9f`.
Source files: `AKS/Bitonic/Bitonic01.lean`, `CompareLayer.lean`, and
`Correctness.lean`. Changes replace AKS dependencies with mathlib imports,
introduce a LeanSort namespace, and retain only Boolean interval and threshold
lemmas. The array refinement and the proofs for LeanSort's ascending/descending
network are developed separately.
