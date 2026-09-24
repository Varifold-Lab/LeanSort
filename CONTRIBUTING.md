# Contributing to LeanSort

Contributions to sorting implementations, proofs, regression checks, and
documentation are welcome. For a substantial new algorithm or change to the
verification model, open an issue first to discuss the scope.

## Build locally

Install [elan](https://github.com/leanprover/elan), clone the repository, and run:

```sh
lake build
```

The repository pins Lean in `lean-toolchain` and dependency revisions in
`lakefile.toml` and `lake-manifest.json`. The default build checks the library,
proofs, and executable regression examples imported by `LeanSort.lean`.

## Implementations and proofs

- Keep executable algorithms in `LeanSort/Algorithm/`, shared mathematical
  definitions in `LeanSort/Model/`, and proofs in `LeanSort/Verification/`.
- Prove the sorting contract: the output is ordered and is a permutation of the
  input, including repeated occurrences. Do not introduce `sorry`, `admit`, or
  new axioms to bypass a proof.
- Connect traces and counted executions to the actual implementation. State
  exactly which operations a cost model counts and which assumptions a theorem
  requires. Regression examples complement universal proofs.
- Split verification modules by mathematical responsibility. Not every
  algorithm needs the same files; see [the verification guide](docs/verification.md).
- Import new verification modules and regression checks from `LeanSort.lean`.
- Update the README and verification guide when proof coverage changes.

## Pull requests

Keep each pull request focused. Describe the behavior or theorem being added,
the main proof idea when useful, and the checks you ran. Run `lake build` before
submitting and include examples for relevant edge cases, such as empty inputs,
duplicates, and algorithm-specific boundaries.

Preserve third-party copyright and license notices. When adapting external
proofs or code, record the source, revision, license, and modifications alongside
the adaptation, following the existing `third_party/aks/` example.

## License

By submitting a contribution for inclusion in LeanSort, you agree to license it
under the project's [Apache License 2.0](LICENSE), unless explicitly stated
otherwise and agreed with the maintainers. Submit only material you have the
right to contribute under these terms. Contributors retain their copyright.
