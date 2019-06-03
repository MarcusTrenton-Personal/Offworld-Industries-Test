// Fill out your copyright notice in the Description page of Project Settings.


#include "MainMenuBase.h"
#include "Engine.h"
#include "Constants.h"
#include "Util.h"
#include "Runtime/Core/Public/Misc/DefaultValueHelper.h"

void UMainMenuBase::SendWeaponChoice(const EWeapon playerWeapon)
{
	if (GEngine)
	{
		const FString playerWeaponString = Util::EnumToString(FString("EWeapon"), playerWeapon, FString("Unknown"));
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, FString("You picked ") + playerWeaponString);
	}
}

bool UMainMenuBase::IsValidBet(const FString text) const
{
	int32 intValue = 0;
	const bool isInteger = FDefaultValueHelper::ParseInt(text, intValue);
	const bool isValid = isInteger && intValue > 0;
	return isValid;
}