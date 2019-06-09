// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "RockPaperScissorsGameMode.h"
#include "RockPaperScissorsPlayerController.h"
#include "RockPaperScissorsPawn.h"
#include "RockPaperScissorsPlayerState.h"
#include "RockPaperScissorsGameInstance.h"

ARockPaperScissorsGameMode::ARockPaperScissorsGameMode()
{
	// no pawn by default
	DefaultPawnClass = ARockPaperScissorsPawn::StaticClass();
	// use our own player controller class
	PlayerControllerClass = ARockPaperScissorsPlayerController::StaticClass();
	
	PlayerStateClass = ARockPaperScissorsPlayerState::StaticClass();
}

void ARockPaperScissorsGameMode::StartPlay()
{
	Super::StartPlay();
	UE_LOG(LogTemp, Warning, TEXT("In StartPlay"));

	URockPaperScissorsGameInstance* GameInstance = Cast<URockPaperScissorsGameInstance>(GetGameInstance());
	if (GameInstance && GameInstance->GlobalEventHandler)
	{
		GameInstance->GlobalEventHandler->OnPlayerHandSelected.AddDynamic(this, &ARockPaperScissorsGameMode::StartPlayerGameRound);
		UE_LOG(LogTemp, Warning, TEXT("Bound player hand event"));
	}
}

void ARockPaperScissorsGameMode::StartPlayerGameRound(
	const int32 PlayerControllerId,
	const EWeapon EPlayerWeapon,
	const int32 Bet,
	const int32 Money,
	const int32 GamesPlayedCount)
{
	UE_LOG(LogTemp, Warning, TEXT("Received player hand event"));
}