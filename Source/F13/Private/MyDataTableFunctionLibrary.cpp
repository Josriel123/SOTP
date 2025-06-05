// Fill out your copyright notice in the Description page of Project Settings.


#include "MyDataTableFunctionLibrary.h"

bool UMyDataTableFunctionLibrary::GetCharacterOptionRow(UDataTable* DataTable, FName RowName, FCharacterOption& OutRow)
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