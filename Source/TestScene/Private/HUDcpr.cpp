// Fill out your copyright notice in the Description page of Project Settings.


#include "HUDcpr.h"
#include "Engine/Engine.h"

static int PreviousDepth;
static FLinearColor Color = FLinearColor(0, 0, 0, 0);

FLinearColor UHUDcpr::DisplayHUD(float Depth, float Frequency) {
	//hud values brackets for both depth and frequency. Frequency is calculated for 5 compressions
	
	if (PreviousDepth != Depth) {
		PreviousDepth = Depth;
		if (Depth != 0.0) {
			if (Depth <= 6.0) {
				if (Depth >= 4.0) {
					if (GEngine)
						GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Green, FString::Printf(TEXT("Correct Compression, depth : %f"), Depth));
				}
				else if (Depth > 0.0)
				{
					if (GEngine)
						GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, FString::Printf(TEXT("COMPRESSION TOO SHALLOW PUSH DEEPER")));
				}
				else {

				}
			}
			else {
				if (GEngine)
					GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, FString::Printf(TEXT("COMPRESSION TOO DEEP")));
			}
		}
		
	}
	if (Frequency != 0.0) {
		if (Frequency <= 4.16) {
			if (Frequency >= 2.5) {
				if (GEngine)
					GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Green, FString::Printf(TEXT("Correct frequency, Frequency : %f"), Frequency));
				Color = Color.Green;
			}
			else {
				if (GEngine)
					GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, FString::Printf(TEXT("TOO FAST, SLOW DOWN")));
				Color = Color.Red;
			}
		}
		else {
			if (GEngine)
				GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, FString::Printf(TEXT("TOO SLOW, GO FASTER")));
			Color = Color.Red;
		}
	}
	return Color;
}