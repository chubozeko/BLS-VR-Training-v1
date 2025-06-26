// Fill out your copyright notice in the Description page of Project Settings.


#include "PatchesCol.h"
#include "Engine/Engine.h"

void UPatchesCol::CheckCollision(FTransform Patches, FTransform Spot, FTransform& Position, bool& Collided) {

	Collided = Patches.AreTranslationsEqual(Patches, Spot, 5.0f);
	if (Collided){
		Position = Spot;		
	}
	else {
		Position = Patches;		
	}
}