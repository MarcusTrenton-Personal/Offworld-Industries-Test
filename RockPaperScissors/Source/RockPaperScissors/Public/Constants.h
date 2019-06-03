// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "ObjectMacros.h"

//If you change this enum, restart the Unreal Editor or else it will crash. Not sure why this instability exists. 
UENUM(BlueprintType)
enum class EWeapon : uint8
{
	VE_Rock		UMETA(DisplayName = "Rock"),
	VE_Paper	UMETA(DisplayName = "Paper"),
	VE_Scissors	UMETA(DisplayName = "Scissors")
};
