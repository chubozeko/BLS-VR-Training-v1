// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "MorphMapBP.generated.h"
/**
 * 
 */
UCLASS()
class TESTSCENE_API UMorphMapBP : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

	UFUNCTION(BlueprintCallable, Category = "MorphMap")
	static float MapValue(float inputValue, float minInput, float maxInput, float minOutput, float maxOutput);
	UFUNCTION(BlueprintCallable, Category = "Compression")
	static void CompressionProcessor(float DistanceToChest, float LastValue, float& MorphValue, float& Depth, float& Frequency, bool& CompressionInProgress, FString& DataReading);
public:
	static float StartDepth;
	static float CompressionDepth;
};
