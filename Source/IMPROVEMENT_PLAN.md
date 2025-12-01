# Project Architecture Assessment & Improvement Plan

Based on the analysis of the project structure, Blueprints, and `ARCHITECTURE.md`, here is an assessment of the current organization and a roadmap for future improvements.

## Strengths (Keep doing this!)

1.  **Solid Networking Foundation**:
    *   You are correctly using the "Unreal Way" for networking: `PlayerController` for client inputs (RPCs), `PlayerState` for persistent data, and `GameMode` for authoritative logic.
    *   **Host Migration**: Integrating HMS at the base class level (`AHMS_GameMode`, etc.) is excellent. It keeps your specific game logic clean while ensuring migration features are available everywhere.

2.  **Data-Driven Architecture**:
    *   Your use of `DT_CharacterOptions` and `DT_CharacterStats` is a professional approach. It allows you to balance the game (changing speeds, cooldowns) without touching code.

3.  **Clear UI/Logic Separation**:
    *   Your widgets (`WBP_CharacterSelection`, `WBP_HostLobbyMenu`) are mostly "dumb" views that send commands to the `PlayerController`. This is good architecture because it keeps the UI decoupled from the game logic.

## Opportunities for Improvement (Actionable Items)

### 1. Decouple UI from GameState (Status: **COMPLETE**)
*   **Issue**: Original implementation used brittle `Get All Widgets` calls and suffered from race conditions where UI updated before data arrived.
*   **Solution Implemented**: **Polling Pattern**.
    1.  Removed all UI references from `GameState` and `GameMode`.
    2.  `WBP_HostLobbyMenu` now uses a self-contained Timer (0.5s) to check `GameState->PlayerArray`.
    3.  This guarantees the UI only updates when valid data is present, resolving the "Empty List" bug.
*   **Benefit**: robust against network lag, zero coupling between classes, and deleted redundant code.

### 2. Safer URL Construction (Priority: Medium)
*   **Current Issue**: In `ServerStartMatch`, the connection string (`?listen?humans=N?bots=M`) is built manually with string appends. A single typo will break the game.
*   **Proposed Solution**: Create a C++ Helper.
    *   Create a `UBlueprintFunctionLibrary` (e.g., `UPantheonLibrary`).
    *   Add a function `GetGameplayURL(int Humans, int Bots)` that uses `FString::Printf` to format the string safely.
*   **Benefit**: Eliminates "magic strings" in Blueprints and reduces bug risk.

### 3. Scalable Ability System (Priority: High for Long Term)
*   **Current Issue**: `FCharacterStats` uses booleans (`bCanDash`, `bCanDoubleJump`). As you add more unique Killers (Traps, Invisibility, Teleport), this struct will become massive.
*   **Proposed Solution**: Component or Tag-Based System.
    *   Instead of booleans, the Data Table should list **Abilities** to grant.
    *   **Option A (Simple)**: An array of `TSubclassOf<UActorComponent>`. The character loops through this and adds the components on spawn.
    *   **Option B (Advanced)**: Use Gameplay Tags (e.g., `Ability.Movement.Dash`) to check permission.
*   **Benefit**: Allows for infinite unique abilities without modifying the core character class or stats struct.

### 4. Robust Match State Machine (Priority: Medium)
*   **Current Issue**: The game transitions directly from Lobby to Gameplay via `ServerTravel`.
*   **Proposed Solution**: Implement an `EMatchState` Enum.
    *   Define states: `WaitingForPlayers`, `IntroSequence`, `Gameplay`, `SuddenDeath`, `PostMatch`.
    *   Replicate this state on the `GameState`.
    *   Have Player Controllers and UI listen for state changes (e.g., "Disable Input during Intro", "Show Scoreboard during PostMatch").
*   **Benefit**: Essential for the polish and flow of an asymmetric multiplayer game.
