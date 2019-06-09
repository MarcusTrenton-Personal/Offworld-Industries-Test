// Fill out your copyright notice in the Description page of Project Settings.


#include "MainMenuBase.h"
#include "Constants.h"
#include "RockPaperScissorsEvents.h"
#include "ROckPaperScissorsPlayerController.h"
#include "Runtime/Core/Public/Misc/DefaultValueHelper.h"


bool UMainMenuBase::IsValidBet(const FString text) const
{
	int32 intValue = 0;
	const bool isInteger = FDefaultValueHelper::ParseInt(text, intValue);
	const bool isValid = isInteger && intValue > 0;
	return isValid;
}