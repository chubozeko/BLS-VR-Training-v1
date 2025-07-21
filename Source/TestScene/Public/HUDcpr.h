// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "HUDcpr.generated.h"

/**
 * 
 */
UCLASS()
class TESTSCENE_API UHUDcpr : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

	UFUNCTION(BlueprintCallable, Category = "HUD")
	static FLinearColor DisplayHUD(float Depth , float Frequency, float LowerBPM, float UpperBPM, FString& BpmInfoText, float& FrequencyInBPM);
};
