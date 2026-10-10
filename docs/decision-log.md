# Decision log

Newest first. Each entry: what was decided, why, and what it means for anyone working on the project.

## 2026-10-09 — EOS credentials live in a gitignored Config/UserEngine.ini

**Decision:** The `+Artifacts=` line in `[/Script/OnlineSubsystemEOS.EOSSettings]` (client ID, client secret, product/sandbox/deployment IDs, encryption key) moved out of `Config/DefaultEngine.ini` into `Config/UserEngine.ini`, which is gitignored (`/Config/User*.ini`). `DefaultGame.ini` allow-lists that file for packaging. The two OneDrive conflict copies (`DefaultEngine-Joel_Laptop.ini`, `DefaultInput-Joel_Laptop.ini`) were deleted; Unreal never read them.

**Why:** The credentials had been public since June 2025. The client uses a game-client-level policy (checked in the Epic Developer Portal), so its credentials ship inside every build anyway and weren't rotated. Still, a public repo shouldn't carry them.

**How it works:** Unreal loads `Config/User{Type}.ini` after `Default{Type}.ini` (the "GameDirUser" layer in UE 5.6's `ConfigHierarchy.h`). Packaging stages it too, and the allow-list removes the warning.

**What it means:** to play online, create `Config/UserEngine.ini` from the template in README > Setup. If you edit the EOS artifact in Project Settings, the editor can write it back into `DefaultEngine.ini`, so check that file before committing.

## 2026-10-09 — Don't track Unreal build output

**Decision:** `Binaries/`, `Intermediate/`, `Saved/`, `DerivedDataCache/`, plugin `Binaries/` and `Intermediate/`, crash dumps (`*.dmp`) and `Pantheon.sln` are ignored and no longer tracked. `.gitignore` is based on GitHub's Unreal Engine template.

**Why:** The engine and the build regenerate all of it, it changes every time the editor runs, and `Saved/Crashes/` held 71 crash dumps, which can contain memory contents.

**Kept on purpose:** `.vsconfig` (Visual Studio uses it to offer the right workloads) and `ThirdPersonMap_BuiltData.uasset` (baked lighting, so the level opens without a lighting rebuild).

**What it means:** after cloning, generate project files and build once (README > Getting Started). Older commits still contain these files unless the history is rewritten.
