// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "PatchesCol.generated.h"

/**
 * 
 */
UCLASS()
class TESTSCENE_API UPatchesCol : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	UFUNCTION(BlueprintCallable, Category = "Comparator")
	static void CheckCollision(FTransform Patch, FTransform Spot, FTransform& Position, bool& Collided);
};
