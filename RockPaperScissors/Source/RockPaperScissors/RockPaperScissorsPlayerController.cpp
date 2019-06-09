// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "RockPaperScissorsPlayerController.h"
#include "Engine.h" //For debug string only
#include "Util.h" //For debug string only
#include "RockPaperScissorsGameInstance.h"

ARockPaperScissorsPlayerController::ARockPaperScissorsPlayerController()
{
	bShowMouseCursor = true;
	bEnableClickEvents = true;
	bEnableTouchEvents = true;
	DefaultMouseCursor = EMouseCursor::Crosshairs;
}

void ARockPaperScissorsPlayerController::BeginPlay()
{
	Super::BeginPlay();

	URockPaperScissorsGameInstance* GameInstance = Cast<URockPaperScissorsGameInstance>(GetGameInstance());
	if (GameInstance && GameInstance->GlobalEventHandler)
	{
		GameInstance->GlobalEventHandler->OnMainMenuHandSelected.AddDynamic(this, &ARockPaperScissorsPlayerController::SendPlayerHand);
	}
}

void ARockPaperScissorsPlayerController::SendPlayerHand(const EWeapon EPlayerWeapon, const int32 Bet)
{
	const FString PlayerWeaponString = Util::EnumToString(FString("EWeapon"), EPlayerWeapon, FString("Unknown"));
	UE_LOG(LogTemp, Log, TEXT("Received SendPlayerHand %s of bet %i"), *PlayerWeaponString, Bet);

	if (GEngine)
	{
		const FString playerWeaponString = "Test";
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, FString("Player picked ") + playerWeaponString);
	}

	//TODO: Get Money from custom PlayerState and send off new event with PlayerId to the GameMode.
}