// Fill out your copyright notice in the Description page of Project Settings.


#include "MainMenuBase.h"
#include "Engine.h"
#include "Constants.h"
#include "Util.h"

void UMainMenuBase::SendWeaponChoice(EWeapon playerWeapon)
{
	if (GEngine)
	{
		FString playerWeaponString = Util::EnumToString(FString("EWeapon"), playerWeapon, FString("Unknown"));
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, FString("You picked ") + playerWeaponString);
	}
}