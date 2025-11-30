# Pantheon Project Architecture

## Overview
**Pantheon** is an asymmetric multiplayer game (Killers vs. Gods/Survivors) built on Unreal Engine 5. The core loop involves a "Killer" hunting down "Survivors" (Gods who have lost their power).

- **Engine**: Unreal Engine 5
- **Language**: C++ & Blueprints
- **Networking**: Listen Server with Host Migration (HMS Plugin)
- **Max Players**: 10 (1 Killer vs 9 Survivors)

## Directory Structure
- `Source/Pantheon/Public`: C++ Header files (.h)
- `Source/Pantheon/Private`: C++ Implementation files (.cpp)
- `Content/Characters`: Character Blueprints, Assets, and Data Tables.
- `Content/Bases_Blueprints`: Core Blueprints inheriting from C++ classes (GameMode, GameState, etc.).

## Core Classes & Architecture

### 1. Game Mode (`APantheonGameMode`)
*   **Parent**: `AHMS_GameMode` (Host Migration System)
*   **Responsibility**:
    *   Manages the match state (WaitingToStart, InProgress).
    *   **Role Assignment**: Randomly picks a Killer and assigns Survivor roles to others (`AssignRoles`, `PickRandomKiller`).
    *   **Bot Management**: Automatically fills empty slots with bots if `bSpawnBots` is true.
    *   **Host Migration**: Handles game rehosting via `HMS_OnGameRehosted_Cpp`.

### 2. Player State (`APantheonPlayerState`)
*   **Parent**: `APlayerState`
*   **Responsibility**:
    *   Persists player information across the session.
    *   **Character Selection**: Stores `ChosenRole` ("Killer" or "Survivor") and references to the specific character (Row Name from Data Tables).
    *   **Ready System**: Handles the "Ready" toggle for players in the lobby.
    *   **Replication**: Ensures all clients know which character/role each player has selected.

### 3. Player Controller (`APantheonPlayerController`)
*   **Parent**: `AHMS_PlayerController`
*   **Responsibility**:
    *   Handles input from the UI (Lobby Menu).
    *   Sends RPCs to the server for character selection (`ServerSetCharacterPreference`) and ready state (`ServerSetReady`).
    *   Manages client-side profile saving.
    *   **Blueprint Logic (`BP_PantheonPlayerController`)**:
        *   **UI Management**:
            *   `ShowLobbyUI`: Creates `WBP_HostLobbyMenu`, adds it to viewport, and sets Input Mode to UI Only.
            *   `TogglePauseMenu`: Toggles `WBP_PauseMenu` and switches Input Mode between Game/UI. Bound to `IA_Pause`.
        *   **Kick Handling**:
            *   `OC_KickPlayer` (Client RPC): Called by the server when this player is kicked. Logic: `Open Level("MainMenu")` -> `Destroy Session`.


### 4. Character System (`APantheonCharacterBase`)
*   **Parent**: `ACharacter`
*   **Subclasses**: `APantheonKillerCharacter`, `APantheonSurvivorCharacter`
*   **Responsibility**:
    *   **Movement**: Implements custom movement logic (Sprint, Dash, Double Jump) driven by stats.
    *   **Stats**: Reads from `DT_CharacterStats` Data Table (Speed, Acceleration, Cooldowns).
    *   **Input**: Uses Enhanced Input System (`IMC_JasonPart3`, `IA_Move`, etc.).
    *   **Replication**: Replicates movement states (e.g., `bIsSprinting`) to ensure smooth animations on clients.
    *   **Blueprint Logic (`BP_PantheonCharacterBase`)**:
        *   **Name Tag System**:
            *   `Build and Set Name Tag`: Updates the overhead widget with the player's ID/Name.
            *   Triggered on `Event Possessed` and `Event Unpossessed` (Server-side) to ensure the tag always reflects the current controller.
            *   `Event Tick`: Updates the widget's rotation to face the local camera (billboard effect) and hides it for the local player.
        *   **HMS Integration**:
            *   `HMS Pre Save Actor`: Saves the actor's transform to `PlayerTransform` variable before migration.


### 5. Game Instance (`UPantheonGameInstance`)
*   **Parent**: `UGameInstance`
*   **Responsibility**:
    *   Manages the life-cycle of Online Sessions (Create, Find, Join, Destroy).
    *   Persists data between levels (Main Menu -> Lobby -> Gameplay).

## Data-Driven Design (Data Tables)

The project uses Data Tables to define characters and their stats, making it easy to add new content without touching C++.

### 1. Character Options (`DT_CharacterOptions`)
*   **Struct**: `FCharacterOption`
*   **Purpose**: Defines the *visuals* and *class* for a character.
*   **Fields**:
    *   `RoleName`: "Killer" or "Survivor".
    *   `CharacterDisplayName`: Name shown in UI (e.g., "Jason (Part 3)").
    *   `PawnClass`: The Blueprint class to spawn (e.g., `BP_JasonPart3`).
    *   `Texture`: Icon for the UI.

### 2. Character Stats (`DT_CharacterStats`)
*   **Struct**: `FCharacterStats`
*   **Purpose**: Defines the *gameplay values* for a character.
*   **Fields**:
    *   **Movement**: `WalkSpeed`, `SprintSpeed`, `WalkAccel`, `SprintAccel`.
    *   **Abilities**: `bCanDash`, `DashDistance`, `bCanDoubleJump`, `DoubleJumpZVelocity`.

## Workflow: How to Add a New Character

1.  **Create Blueprint**:
    *   Create a new Blueprint Class inheriting from `APantheonSurvivorCharacter` (or Killer).
    *   Setup the mesh and animations.
2.  **Define Stats**:
    *   Open `DT_CharacterStats`.
    *   Add a new Row (e.g., `Survivor_NewGod`).
    *   Set the movement speeds and ability flags.
3.  **Register Character**:
    *   Open `DT_CharacterOptions`.
    *   Add a new Row.
    *   Set `RoleName`, `DisplayName`, and `Texture`.
    *   Set `PawnClass` to your new Blueprint.
4.  **Link Stats**:
    *   In your new Blueprint (Class Defaults), set the `StatsRowName` to match the row you created in `DT_CharacterStats`.

## Host Migration System (HMS) Implementation

The project uses **HMS V2** to handle listen server host migration. This ensures that if the host disconnects, the game can pick a new host and continue.

### 1. Core Components
*   **Game Instance (`BP_PantheonGameInstance`)**:
    *   Inherits from `UPantheonGameInstance` -> `UHMS_GameInstance`.
    *   **Crucial Events**:
        *   `Event HMS Rehost Game`: Triggered on the new host. Logic: `Destroy Session` -> `Create Session` (Advanced Sessions) -> `Open Level` (with saved data).
        *   `Event HMS Reconnect To Game`: Triggered on clients. Logic: Executes console command `open <HMS_ReconnectAddress>` to join the new host.
*   **Game Save (`BP_HMSGameSave`)**:
    *   Used to persist critical match data during the migration process.
    *   Variables marked as "SaveGame" in the GameMode or other classes are serialized into this object before the server shuts down and restored on the new host.

### 2. Migration Flow
1.  **Host Disconnects**: HMS detects the connection loss.
2.  **Election**: Peers elect a new host (usually based on best connection/hardware).
3.  **State Saving**: The old state is serialized into `BP_HMSGameSave`.
4.  **Rehosting**:
    *   **New Host**: Fires `Event HMS Rehost Game`. Creates a new session and loads the map.
    *   **Clients**: Fire `Event HMS Reconnect To Game`. They wait for the new host to be ready and then connect via IP/NetDriver.
5.  **State Restoration**: `HMS_OnGameRehosted_Cpp` (in GameMode) or Blueprint equivalents restore the game state (timer, player roles, etc.) from the saved data.

### 3. Required Setup
*   **GameMode**: Must inherit from `AHMS_GameMode`.
*   **PlayerController**: Must inherit from `AHMS_PlayerController`.
*   **GameInstance**: Must inherit from `UHMS_GameInstance`.

### 4. Actor Persistence & References
*   **Saving Actors**:
    *   Add the `HMS_Interface` component to any Actor you want to persist across migration.
    *   Mark variables as **SaveGame** to automatically serialize them.
    *   Use `HMS Pre Save Actor` and `HMS Post Load Actor` events for custom save logic.
    *   Toggle `HMS_Interface::HMS_ShouldSerialize` to conditionally skip saving an actor.
*   **Actor References**:
    *   Standard pointers become invalid. Use `HMS_ActorReference` struct instead.
    *   The variable holding `HMS_ActorReference` must be marked **SaveGame**.
    *   **Requirement**: The referenced actor must also have the `HMS_Interface` component.

### 5. Best Practices
*   **Quitting**: When a player explicitly leaves, call `HMS_GameInstance::HMS_ResetHostMigration` to prevent auto-reconnection attempts.

## UI System

The User Interface is built using Unreal Motion Graphics (UMG) and heavily relies on Data Tables for dynamic content.

### Character Selection Flow (`WBP_CharacterSelection`)
1.  **Initialization (`Event Construct`)**:
    *   Iterates through all Row Names in `DT_CharacterOptions`.
    *   For each row, retrieves the `FCharacterOption` struct.
    *   Creates a `WBP_CharcaterOptionRow` widget.
    *   **Filtering**: Checks `RoleName`. If "Killer", adds to `KillerList_Box`. If "Survivor", adds to `SurvivorList_Box`.
2.  **Interaction**:
    *   When a player clicks a character option, the `WBP_CharcaterOptionRow` fires an event caught by the main widget.
    *   **Network Call**: The widget casts to `APantheonPlayerController` and calls `ServerSetCharacterPreference(RowKey, RoleName)`.
### Lobby Menu (`WBP_HostLobbyMenu`)
*   **Player List Management**:
    *   `RebuildPlayerList`: Clears the current list and iterates through `GameState->PlayerArray`.
    *   For each `PantheonPlayerState`, creates a `WBP_PlayerListRow` widget, sets its data (Name, ID), and adds it to the `PlayerList` container.
    *   **Replication Hook**: The `GameState` uses a RepNotify event (`OnRep_AllPlayerStates`) to detect when players join/leave. This event finds the `WBP_HostLobbyMenu` widget and calls `RebuildPlayerList`, ensuring the UI stays in sync on all clients.
*   **Host Controls**:

    *   Checks `IsServer` on Construct.
    *   If Host: Shows "Start Game" button and Bot controls (`CB Bots`, `TX Bots`).
    *   If Client: Hides these controls.
*   **Lobby Interactions**:
    *   **Ready Button**: Toggles the player's ready state via `ServerSetReady` on the PlayerController.
    *   **Start Game**: (Host Only) Calls `ServerStartMatch` on the `PantheonLobbyMenu`.
        *   **Validation**: Iterates `GameState->PlayerArray` to ensure all players are `IsReady`.
        *   **Execution**: If all ready, constructs a URL with parameters (`?listen?humans=N?bots=M`) and calls `ServerTravel` to the Gameplay Map.

### Player List Row (`WBP_PlayerListRow`)
*   **Visuals**: Displays Profile Icon, Username, Ping, and Ready Status (Checkmark).
*   **Host Logic**:
    *   Checks `IsServer` on Construct.
    *   If Host: Enables the "Kick" button (disabled for self with tooltip "You can't kick yourself").
*   **Data Binding**:
    *   `SetData`: Caches the `PantheonPlayerState` and sets initial values.
    *   **Real-time Updates**: Binds to the `OnReadyChanged` delegate on the PlayerState to toggle the Ready Icon visibility immediately when a player readies up.
*   **Kick Functionality**:
    *   On Click: Casts the GameMode to `BP_PantheonLobbyMenu` and calls `KickPlayer` with the specific `PlayerID`.






