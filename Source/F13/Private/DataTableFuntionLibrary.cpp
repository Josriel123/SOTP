#include "DataTableFunctionLibrary.h"

bool UDataTableFunctionLibrary::GetCharacterOptionRow(UDataTable* DataTable, FName RowName, FCharacterOption& OutRow)
{
    if (!DataTable)
    {
        return false;
    }

    FCharacterOption* Row = DataTable->FindRow<FCharacterOption>(RowName, TEXT("Lookup Character Option"));

    if (Row)
    {
        OutRow = *Row;
        return true;
    }

    return false;
}
