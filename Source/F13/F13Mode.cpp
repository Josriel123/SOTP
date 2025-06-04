#include "F13Mode.h"
#include "F13KillerCharacter.h"
#include "F13SurvivorCharacter.h"
#include "F13PlayerController.h"
#include "F13PlayerState.h"
#include "F13GameState.h"

AF13Mode::AF13Mode()
{
    static ConstructorHelpers::FClassFinder<APawn> KillerBP(
        TEXT("/Game/Characters/Jasons/Part_3/Blueprints/BP_KillerCharacter"));  

    static ConstructorHelpers::FClassFinder<APawn> SurvivorBP(
        TEXT("/Game/Characters/Survivors/Tommy_Jarvis/Blueprints/BP_TommyJarvis"));

    //if (KillerBP.Succeeded())
    //{
        //DefaultPawnClass = KillerBP.Class;   // This is the ABP_KillerCharacter_C class
    //}

    if (SurvivorBP.Succeeded())
    {
        DefaultPawnClass = SurvivorBP.Class;   // This is the ABP_KillerCharacter_C class
    }

    PlayerControllerClass = AF13PlayerController::StaticClass();
    PlayerStateClass = AF13PlayerState::StaticClass();
    GameStateClass = AF13GameState::StaticClass();
}
