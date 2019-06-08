// Fill out your copyright notice in the Description page of Project Settings.


#include "MainMenuBase.h"
#include "Engine.h" //For debug string only
#include "Constants.h"
#include "Util.h" //For debug string only
#include "RockPaperScissorsEvents.h"
#include "ROckPaperScissorsPlayerController.h"
#include "Runtime/Core/Public/Misc/DefaultValueHelper.h"

void UMainMenuBase::SendHand(const EWeapon EPlayerWeapon, const int32 BetAmount)
{
	if (GEngine)
	{
		const FString playerWeaponString = Util::EnumToString(FString("EWeapon"), EPlayerWeapon, FString("Unknown"));
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, FString("You picked ") + playerWeaponString);
	}

	//const FRockPaperScissorsHandEventParams handParams{ EPlayerWeapon, BetAmount };
	//OnHandDelegate(handParams);
}

bool UMainMenuBase::IsValidBet(const FString text) const
{
	int32 intValue = 0;
	const bool isInteger = FDefaultValueHelper::ParseInt(text, intValue);
	const bool isValid = isInteger && intValue > 0;
	return isValid;
}