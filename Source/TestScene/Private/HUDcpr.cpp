// Fill out your copyright notice in the Description page of Project Settings.


#include "HUDcpr.h"
#include "Engine/Engine.h"

static int PreviousDepth;
static int ChestCompressions = 5;
static FLinearColor Color = FLinearColor(0, 0, 0, 0);

FLinearColor UHUDcpr::DisplayHUD(float Depth, float Frequency, float LowerBPM, float UpperBPM, FString& BpmInfoText) {
	//hud values brackets for both depth and frequency. Frequency is calculated for 5 compressions
	
	if (PreviousDepth != Depth) {
		PreviousDepth = Depth;
		if (Depth != 0.0) {
			if (Depth <= 6.0) {
				if (Depth >= 4.0) {
					// if (GEngine)
					// 	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Green, FString::Printf(TEXT("Correct Compression, depth : %f"), Depth));
				}
				else if (Depth > 0.0)
				{
					// if (GEngine)
					// 	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, FString::Printf(TEXT("COMPRESSION TOO SHALLOW PUSH DEEPER")));
				}
				else {

				}
			}
			else {
				// if (GEngine)
				// 	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, FString::Printf(TEXT("COMPRESSION TOO DEEP")));
			}
		}
		
	}

	float freqHigh = ChestCompressions / (UpperBPM / 60.0);
	float freqLow = ChestCompressions / (LowerBPM / 60.0);

	if (Frequency != 0.0) {
		if (Frequency <= freqLow) { /* OLD VALUE: 4.16, NEW VALUE: 3.0 */
			if (Frequency >= freqHigh) { /* OLD VALUE: 2.5, NEW VALUE: 2.5 */
				// if (GEngine)
				// 	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Green, FString::Printf(TEXT("Correct frequency, Frequency : %f"), Frequency));
				BpmInfoText = "Oikea";
				// BpmInfoText = "CORRECT";
				Color = Color.Green;
			}
			else {
				// if (GEngine)
				// 	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, FString::Printf(TEXT("TOO FAST, SLOW DOWN")));
				BpmInfoText = "Hidasta Vauhtia!";
				// BpmInfoText = "SLOW DOWN!";
				Color = Color.Red;
			}
		}
		else {
			// if (GEngine)
			// 	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, FString::Printf(TEXT("TOO SLOW, GO FASTER")));
			BpmInfoText = "Mene Nopeammin!";
			// BpmInfoText = "GO FASTER!";
			Color = Color.Red;
		}
		BpmInfoText += FString::Printf(TEXT("\nPuristustaajuus:\n%.2f BPM"), (ChestCompressions / Frequency)*60);
		// BpmInfoText += FString::Printf(TEXT("\nCompression Rate:\n%.2f BPM"), (ChestCompressions / Frequency)*60);
	}
	
	return Color;
}
