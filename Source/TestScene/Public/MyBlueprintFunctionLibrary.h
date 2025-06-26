// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "MyBlueprintFunctionLibrary.generated.h"

UCLASS()
class TESTSCENE_API UMyBlueprintFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

	UFUNCTION(BlueprintCallable, Category = "Comparator")
	static float CompressionDepth(FTransform Chest, FTransform Hand);

	UFUNCTION(BlueprintCallable, Category = "Custom", meta = (Keyword = "save"))
	static bool SaveArrayText(FString SaveDirectory, FString FileName, TArray <FString> SaveText, bool AllowOverWriting);
	
};
