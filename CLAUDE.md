# Pantheon (SOTP)

Unreal Engine 5.6 C++ project (module `Pantheon`). Read `README.md` first; past decisions are in `docs/decision-log.md`.

## Rules
- Never commit engine-generated output: `Binaries/`, `Intermediate/`, `Saved/`, `DerivedDataCache/`, plugin `Binaries/` and `Intermediate/`, `*.dmp`, `*.sln`. `.gitignore` covers them; never force-add.
- Never commit credentials. EOS client credentials live only in the gitignored `Config/UserEngine.ini`. If `+Artifacts=` reappears in `Config/DefaultEngine.ini` (Project Settings can write it back), remove it before committing.
- Record new decisions in README + `docs/decision-log.md` + this file, in the same commit.
