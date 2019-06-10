// Fill out your copyright notice in the Description page of Project Settings.


#include "MainMenuBase.h"
#include "Constants.h"
#include "RockPaperScissorsEvents.h"
#include "ROckPaperScissorsPlayerController.h"
#include "Runtime/Core/Public/Misc/DefaultValueHelper.h"


bool UMainMenuBase::IsValidBet(const int32 Bet, const int32 Money) const
{
	const bool IsValid = Bet > 0 && Bet <= Money;
	UE_LOG(LogTemp, Warning, TEXT("Bet %i Money %i IsValid %b"), Bet, Money, IsValid);
	return IsValid;
}