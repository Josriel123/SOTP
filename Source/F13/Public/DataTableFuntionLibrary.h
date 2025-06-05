#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Engine/DataTable.h"
#include "CharacterOption.h"
#include "DataTableFunctionLibrary.generated.h"




//something to say

UCLASS()
class F13_API UDataTableFunctionLibrary : public UBlueprintFunctionLibrary
{
    GENERATED_BODY()

public:

    /** Tries to find a row in the given DataTable */
    UFUNCTION(BlueprintCallable, Category = "DataTable")
    static bool GetCharacterOptionRow(UDataTable* DataTable, FName RowName, FCharacterOption& OutRow);
};
