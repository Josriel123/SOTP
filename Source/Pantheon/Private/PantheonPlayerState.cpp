#include "PantheonPlayerState.h"
#include "CharacterOption.h"
#include "Engine/DataTable.h"
#include "Engine/Engine.h"
#include "GameFramework/PlayerController.h"
#include "Misc/Guid.h"
#include "Net/UnrealNetwork.h"
#include "OnlineSubsystemUtils.h"
#include "UObject/ConstructorHelpers.h"


APantheonPlayerState::APantheonPlayerState() {
  // Start with no DataTable loaded.
  CharacterOptionsTable = nullptr;

  // Only the server (ROLE_Authority) should load the DataTable once in the
  // constructor.
  if (HasAuthority()) {
    static ConstructorHelpers::FObjectFinder<UDataTable> DT_Finder(
        TEXT("/Game/Characters/Data/DT_CharacterOptions.DT_CharacterOptions"));
    if (DT_Finder.Succeeded()) {
      CharacterOptionsTable = DT_Finder.Object;
    } else {
      UE_LOG(LogTemp, Error,
             TEXT("APantheonPlayerState ctor: Failed to find DataTable "
                  "'/Game/Characters/Data/DT_CharacterOptions'"));
    }
  }

  // Initialize replicated fields to defaults.
  ChosenRole = TEXT("");
  bIsReady = false;
}

void APantheonPlayerState::GetLifetimeReplicatedProps(
    TArray<FLifetimeProperty> &OutLifetimeProps) const {
  Super::GetLifetimeReplicatedProps(OutLifetimeProps);

  DOREPLIFETIME(APantheonPlayerState, bIsReady);
  DOREPLIFETIME(APantheonPlayerState, ChosenRole);
  DOREPLIFETIME(APantheonPlayerState, SelectedPawnClass);
  DOREPLIFETIME(APantheonPlayerState, bIsBot);
  DOREPLIFETIME(APantheonPlayerState, SurvivorRowKey);
  DOREPLIFETIME(APantheonPlayerState, KillerRowKey);
}

TSubclassOf<APawn>
APantheonPlayerState::GetChosenPawnClassForRole(const FString &InRole) const {
  // Only the server should do the DataTable lookup
  if (GetLocalRole() != ROLE_Authority)
    return nullptr;

  if (!CharacterOptionsTable) {
    UE_LOG(LogTemp, Error,
           TEXT("GetPawnClassForRole: CharacterOptionsTable is nullptr!"));
    return nullptr;
  }

  /* Pick the correct row key based on the requested role */
  const FName Key = (InRole == TEXT("Killer")) ? KillerRowKey : SurvivorRowKey;

  static const FString Ctx(TEXT("GetPawnClassForRole"));
  const FCharacterOption *Row =
      CharacterOptionsTable->FindRow<FCharacterOption>(Key, Ctx);

  if (!Row) {
    UE_LOG(LogTemp, Warning,
           TEXT("GetPawnClassForRole: No row found for key '%s' (role %s)"),
           *Key.ToString(), *InRole);
    return nullptr;
  }

  return Row->PawnClass;
}

void APantheonPlayerState::SetReady(bool bNewReady) {
  if (bIsReady == bNewReady)
    return; // no change

  bIsReady = bNewReady;
  OnRep_IsReady(); // update server immediately
}

void APantheonPlayerState::OnRep_IsReady() {
  OnReadyChanged.Broadcast(this, bIsReady);

  UE_LOG(LogTemp, Log, TEXT("PlayerState[%s] Ready = %s (OnRep)"),
         *GetPlayerName(), bIsReady ? TEXT("TRUE") : TEXT("FALSE"));
}

void APantheonPlayerState::EnsureUniqueIdForBot() {
  if (!bIsBot || GetUniqueId().IsValid()) {
    return;
  }

  const FString FakeId = FString::Printf(TEXT("Bot-%08X"), FMath::Rand());

  FUniqueNetIdStringRef NewId = FUniqueNetIdString::Create(FakeId, TEXT("BOT"));

  SetUniqueId(FUniqueNetIdRepl(FUniqueNetIdRef(NewId)));
}

void APantheonPlayerState::AssignRandomSurvivor() {
  if (!HasAuthority() || !CharacterOptionsTable) {
    return;
  }

  TArray<FName> RowNames = CharacterOptionsTable->GetRowNames();
  TArray<FName> SurvivorRows;

  for (const FName &RowName : RowNames) {
    static const FString Ctx(TEXT("AssignRandomSurvivor"));
    const FCharacterOption *Row =
        CharacterOptionsTable->FindRow<FCharacterOption>(RowName, Ctx);
    if (Row && Row->RoleName == TEXT("Survivor")) {
      SurvivorRows.Add(RowName);
    }
  }

  if (SurvivorRows.Num() > 0) {
    const int32 Idx = FMath::RandRange(0, SurvivorRows.Num() - 1);
    SurvivorRowKey = SurvivorRows[Idx];
    ChosenRole = TEXT("Survivor");

    // Also set the pawn class immediately so the GameMode sees it
    SelectedPawnClass = GetChosenPawnClassForRole(ChosenRole);

    UE_LOG(LogTemp, Log, TEXT("Bot %s assigned random survivor: %s"),
           *GetPlayerName(), *SurvivorRowKey.ToString());
  }
}

void APantheonPlayerState::CopyProperties(APlayerState *NewPlayerState) {
  Super::CopyProperties(NewPlayerState);

  if (APantheonPlayerState *NewPS =
          Cast<APantheonPlayerState>(NewPlayerState)) {
    NewPS->SurvivorRowKey = SurvivorRowKey;
    NewPS->KillerRowKey = KillerRowKey;
    NewPS->ChosenRole = ChosenRole;
    NewPS->SelectedPawnClass = SelectedPawnClass;
  }
}
