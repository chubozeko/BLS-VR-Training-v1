// Fill out your copyright notice in the Description page of Project Settings.


#include "MyBlueprintFunctionLibrary.h"
#include "Engine/Engine.h"
#include "Misc/FileHelper.h"
#include "HAL/PlatformFilemanager.h"


float UMyBlueprintFunctionLibrary::CompressionDepth(FTransform Chest, FTransform Hand) {



	float CompressionDepth = 0.0;
	FVector VHand = Hand.GetLocation();
	FVector VChest = Chest.GetLocation();
	float DistanceToChest = VHand.PointPlaneDist(VHand, VChest, VChest.UpVector);
	float DistXY = VHand.DistXY(VHand, VChest);

	//uncomment to display hand position used to trigger compressions
	// if (GEngine)
	// 	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, FString::Printf(TEXT("%f"), DistanceToChest));
	// if (GEngine)
	//	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Green, FString::Printf(TEXT("%f"), DistXY));

	if (DistXY<= 10) {	
		
		//used in morphmap to process compressions
		return DistanceToChest;

	}
	else 
		return 0.0;
};

bool UMyBlueprintFunctionLibrary::SaveArrayText(FString SaveDirectory, FString FileName, TArray <FString> SaveText, bool AllowOverWriting) {

	//set file path to save data to
	SaveDirectory += "\\";
	SaveDirectory += FileName;
	if (!AllowOverWriting) {
		if (FPlatformFileManager::Get().GetPlatformFile().FileExists(*SaveDirectory)) {
			return false;
		}
	}
	
		FString FinalString = "";
		for (FString& Each : SaveText) {
			FinalString += Each;
			FinalString += LINE_TERMINATOR;
		}

		return FFileHelper::SaveStringToFile(FinalString, *SaveDirectory);
	}

