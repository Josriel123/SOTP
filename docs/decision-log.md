# Decision log

Newest first. Each entry: what was decided, why, and what it means for anyone working on the project.

## 2026-10-09 — Don't track Unreal build output

**Decision:** `Binaries/`, `Intermediate/`, `Saved/`, `DerivedDataCache/`, plugin `Binaries/` and `Intermediate/`, crash dumps (`*.dmp`) and `Pantheon.sln` are ignored and no longer tracked. `.gitignore` is based on GitHub's Unreal Engine template.

**Why:** The engine and the build regenerate all of it, it changes every time the editor runs, and `Saved/Crashes/` held 71 crash dumps, which can contain memory contents.

**Kept on purpose:** `.vsconfig` (Visual Studio uses it to offer the right workloads) and `ThirdPersonMap_BuiltData.uasset` (baked lighting, so the level opens without a lighting rebuild).

**What it means:** after cloning, generate project files and build once (README > Getting Started). Older commits still contain these files unless the history is rewritten.
