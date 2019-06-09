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

	UE_LOG(LogTemp, Warning, TEXT("PlayerController constructed"));
}

void ARockPaperScissorsPlayerController::BeginPlay()
{
	Super::BeginPlay();

	UE_LOG(LogTemp, Warning, TEXT("PlayerController BeginPlay"));

	URockPaperScissorsGameInstance* GameInstance = Cast<URockPaperScissorsGameInstance>(GetGameInstance());
	if (GameInstance && GameInstance->GlobalEventHandler)
	{
		GameInstance->GlobalEventHandler->OnMainMenuHandSelected.AddDynamic(this, &ARockPaperScissorsPlayerController::SendPlayerHand);
		UE_LOG(LogTemp, Warning, TEXT("Added event binding"));
	}
}

void ARockPaperScissorsPlayerController::SendPlayerHand(EWeapon EPlayerWeapon, int32 Bet)
{
	const FString PlayerWeaponString = Util::EnumToString(FString("EWeapon"), EPlayerWeapon, FString("Unknown"));
	UE_LOG(LogTemp, Log, TEXT("Received SendPlayerHand %s of bet %i"), *PlayerWeaponString, Bet);

	if (GEngine)
	{
		
		const FString playerWeaponString = "Test";
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, FString("Player picked ") + playerWeaponString);
	}
}