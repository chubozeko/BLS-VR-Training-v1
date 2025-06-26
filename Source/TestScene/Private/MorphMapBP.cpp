// Fill out your copyright notice in the Description page of Project Settings.



#include "MorphMapBP.h"
#include "Engine/Engine.h"




float UMorphMapBP::StartDepth= 11.0; 
float UMorphMapBP::CompressionDepth = 1000.0; // max float for condition to be true at first
static int CompressionCount = 0;
static float StartTime, EndTime;
static float MovingAvg[5];
static bool ArrayFull;

//Map function to be used with morph targets
float UMorphMapBP::MapValue(float InputValue, float MinInput, float MaxInput, float MinOutput, float MaxOutput) {
    if (InputValue <= MaxInput)
        return ((MaxInput - InputValue) / (MaxInput - MinInput)) * (MaxOutput - MinOutput) + MinOutput;
    else return 0.0;
}

void UMorphMapBP::CompressionProcessor(float DistanceToChest, float LastValue, float& MorphValue, float& Depth, float& Frequency, bool& CompressionInProgress, FString& DataReading) {
    
    if (!CompressionInProgress && DistanceToChest != 0.0 && DistanceToChest <= StartDepth){

        if (CompressionCount % 5 == 0) {
            StartTime = LastValue;
        }
        // Compression started
        CompressionInProgress = true;
        //minDepth = DistanceToChest;

    }

    if (CompressionInProgress) {        
        // Update compression depth
        if (DistanceToChest < CompressionDepth) {
            CompressionDepth = DistanceToChest;
        }
        
    }

    // Check if compression is complete 
    if (CompressionInProgress && DistanceToChest != 0.0 && DistanceToChest >= StartDepth ) {
        // compression ended
        CompressionInProgress = false;
        EndTime = LastValue;
        MovingAvg[CompressionCount % 5] = EndTime - StartTime;
        ++CompressionCount;
       
        if (CompressionCount%4 == 0 && ArrayFull == false) {
            ArrayFull = true;
        }

        //Moving average for frequency maybe remove true flag and return 5 faulty values then start returning proper values.

        if (ArrayFull == true) {
            for (int i = 0; i < 5; i++) {
                Frequency = +MovingAvg[i];
        }
        }
        Depth = StartDepth - CompressionDepth;
        DataReading = FString::FromInt(CompressionCount), "," + FString::SanitizeFloat(Depth) + "," + FString::SanitizeFloat(Frequency) + ",";
        CompressionDepth = 1000.0;
                
    }   
    // Update last value
    MorphValue = MapValue(DistanceToChest, 7.0, 11.0, 0.0, 2);
    
}