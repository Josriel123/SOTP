# 🏛️ Pantheon — Asymmetric Multiplayer Horror Game

> **1 Killer. 9 Gods. Only survival matters.**

Pantheon is an asymmetric multiplayer game built in **Unreal Engine 5**, inspired by the match structure of games like *Dead by Daylight*. One player takes on the role of a relentless Killer while up to 9 players survive as fallen Gods stripped of their power. The game features a robust C++ and Blueprint hybrid architecture, data-driven character design, and seamless host migration via the HMS V2 plugin.

---

## 🎮 Game Overview

| Feature | Details |
|---|---|
| **Genre** | Asymmetric Multiplayer / Horror |
| **Max Players** | 10 (1 Killer + 9 Survivors) |
| **Engine** | Unreal Engine 5.6 |
| **Network Model** | Listen Server with Host Migration |
| **Language** | C++ & Blueprints |

### Core Loop
- One player is **randomly assigned** as the Killer at match start.
- The remaining players are **Survivors (Gods)** who must outlast and evade the Killer.
- The Host can fill empty slots with **AI Bots** to ensure a full lobby.
- If the host disconnects mid-match, **Host Migration (HMS V2)** automatically elects a new host and restores the full game state — no one gets kicked.

---

## ✨ Key Features

- **🎲 Random Role Assignment** — The server randomly designates one player as the Killer each match.
- **🤖 Bot Support** — Host can configure the number of AI bots to fill empty survivor slots.
- **⚡ Seamless Host Migration** — Uses the HMS V2 plugin to handle host disconnections without ending the match.
- **🧩 Data-Driven Characters** — All characters, stats (speed, dash, double-jump), and abilities are defined in Unreal Data Tables — no code changes needed to add new characters.
- **🏃 Advanced Movement System** — Characters support Sprint, Dash, and Double Jump, all configurable per-character via data tables.
- **🎨 Dynamic Lobby UI** — Fully replicated lobby with real-time player list, character selection, ready system, and host-only controls (Start Game, Bot count, Kick).
- **🔌 EOS & Online Subsystem** — Integrated with Epic Online Services (`OnlineSubsystemEOS`) for session management.
- **🏷️ Overhead Name Tags** — Billboard-style name tags for all players powered by UMG widgets.

---

## 🏗️ Architecture

The project follows Unreal Engine's standard multiplayer architecture pattern:

```
GameMode          ← Authoritative server logic (role assignment, match state, bots)
├── GameState     ← Replicated match data (player array, match status)
├── PlayerState   ← Per-player persistent data (role, character choice, ready state)
├── PlayerController ← Client input & UI ownership (RPCs → server)
└── CharacterBase ← Pawn logic (movement, stats, replication)
```

### Core C++ Classes

| Class | Responsibility |
|---|---|
| `APantheonGameMode` | Role assignment, bot spawning, match management, HMS rehost handler |
| `APantheonPlayerState` | Character selection, ready toggle, role replication |
| `APantheonPlayerController` | UI management, lobby input RPCs, profile save/load |
| `APantheonCharacterBase` | Sprint, Dash, Double Jump; reads from `DT_CharacterStats` |
| `APantheonKillerCharacter` | Killer-specific subclass |
| `APantheonSurvivorCharacter` | Survivor-specific subclass |
| `UPantheonGameInstance` | Session lifecycle (Create / Find / Join / Destroy) |
| `APantheonBotController` | AI controller for bot survivors |

### Data Tables

| Table | Struct | Purpose |
|---|---|---|
| `DT_CharacterOptions` | `FCharacterOption` | Character display names, pawn classes, and UI icons |
| `DT_CharacterStats` | `FCharacterStats` | Movement speeds, acceleration, dash distance, jump velocity |

---

## 🔌 Plugins

| Plugin | Purpose |
|---|---|
| **HMS V2** (`HostMigrationSystemV2`) | Transparent host migration on listen servers |
| **Advanced Sessions** | Extended session creation/join helpers |
| **Modeling Tools Editor Mode** | Editor-side mesh modeling utilities |

---

## 🚀 Getting Started

### Prerequisites

- **Unreal Engine 5.6** — [Download from Epic Games Launcher](https://www.unrealengine.com/)
- **Visual Studio 2022** (with the *Game Development with C++* workload)
- **HMS V2 Plugin** — Available on the [Unreal Marketplace](com.epicgames.launcher://ue/marketplace/product/23b51829593540eeb81c801014787306)
- **Advanced Sessions Plugin** — Available on the Unreal Marketplace

### Setup

1. **Clone the repository:**
   ```bash
   git clone https://github.com/Josriel123/SOTP.git
   ```

2. **Install Marketplace Plugins:**
   - Purchase and install **HMS V2** and **Advanced Sessions** from the Unreal Marketplace to your engine version.

3. **Generate Project Files:**
   Right-click `Pantheon.uproject` → *Generate Visual Studio project files*

4. **Build the project:**
   Open `Pantheon.sln` in Visual Studio and build in **Development Editor** configuration.

5. **Open in Unreal Engine:**
   Double-click `Pantheon.uproject` to launch the editor.

---

## ➕ Adding a New Character

Pantheon is fully data-driven — adding a new playable character requires **no C++ changes**.

1. **Create a Blueprint** inheriting from `APantheonSurvivorCharacter` (or `APantheonKillerCharacter`). Set up the mesh and animations.

2. **Define Stats** — Open `DT_CharacterStats`, add a new row (e.g., `Survivor_Ares`), and configure movement and ability values.

3. **Register the Character** — Open `DT_CharacterOptions`, add a new row, and set the `RoleName`, `CharacterDisplayName`, `PawnClass`, and `Texture`.

4. **Link Stats** — In the new Blueprint's Class Defaults, set `StatsRowName` to match the `DT_CharacterStats` row you created.

The character will automatically appear in the lobby's character selection screen.

---

## 🌐 Networking & Host Migration

Pantheon uses a **Listen Server** model with the **HMS V2** plugin to provide seamless host migration:

1. **Host Disconnects** → HMS detects the loss.
2. **Peer Election** → A new host is automatically elected.
3. **State Serialization** → Match data (timers, player roles, transforms) is saved to `BP_HMSGameSave`.
4. **Rehosting** → The new host creates a new session and loads the map; existing clients automatically reconnect.
5. **State Restoration** → `HMS_OnGameRehosted_Cpp` restores all saved data on the new host.

> **Note:** To properly leave a session without triggering auto-reconnect, ensure `HMS_GameInstance::HMS_ResetHostMigration()` is called on disconnect.

---

## 🗂️ Project Structure

```
SOTP/
├── Config/                   # Engine, Game, and Input configuration
├── Content/
│   ├── Characters/           # Character Blueprints, Meshes, Data Tables
│   └── Bases_Blueprints/     # Core Blueprints (GameMode, GameState, etc.)
├── Plugins/
│   └── AdvancedSessions/     # Session management plugin
├── Source/
│   ├── ARCHITECTURE.md       # Detailed system architecture documentation
│   ├── IMPROVEMENT_PLAN.md   # Roadmap and technical debt tracking
│   └── Pantheon/
│       ├── Public/           # C++ Header files
│       └── Private/          # C++ Implementation files
└── Pantheon.uproject
```

---

## 🗺️ Roadmap

- [ ] **Safer URL Construction** — Replace manual string concatenation in `ServerStartMatch` with a `UPantheonLibrary` Blueprint Function Library helper.
- [ ] **Scalable Ability System** — Replace boolean flags (`bCanDash`, `bCanDoubleJump`) with a component or Gameplay Tag-based ability system.
- [ ] **Match State Machine** — Implement a replicated `EMatchState` enum (`WaitingForPlayers → IntroSequence → Gameplay → SuddenDeath → PostMatch`).
- [ ] **Additional Characters** — Expand the roster of Killers and Survivor Gods.
- [ ] **Win Condition Logic** — Implement endgame triggers and post-match scoreboard.

---

## 🛠️ Tech Stack

- **Unreal Engine 5.6**
- **C++ 17** (via UBT / MSVC)
- **UMG** (Unreal Motion Graphics) for UI
- **Enhanced Input System**
- **Epic Online Services (EOS)**
- **HMS V2** — Host Migration System
- **Advanced Sessions** plugin

---

## 📄 License

This project is a personal/portfolio project. All rights reserved.

---

*Built with ❤️ in Unreal Engine 5.*
