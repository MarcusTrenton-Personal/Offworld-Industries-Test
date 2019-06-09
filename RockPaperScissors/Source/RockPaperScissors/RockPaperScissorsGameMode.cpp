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

	URockPaperScissorsGameInstance* GameInstance = Cast<URockPaperScissorsGameInstance>(GetGameInstance());
	if (GameInstance && GameInstance->GlobalEventHandler)
	{
		GameInstance->GlobalEventHandler->OnPlayerHandSelected.AddDynamic(this, &ARockPaperScissorsGameMode::StartPlayerGameRound);
	}
}

void ARockPaperScissorsGameMode::StartPlayerGameRound(
	const int32 PlayerControllerId,
	const EWeapon EPlayerWeapon,
	const int32 Bet,
	const int32 Money,
	const int32 GamesPlayedCount)
{
	URockPaperScissorsGameInstance* GameInstance = Cast<URockPaperScissorsGameInstance>(GetGameInstance());
	if (GameInstance && GameInstance->GlobalEventHandler)
	{
		//TODO: Add a delay before sending results. Simulate server lag.

		//TODO: Have distinct AIs. Switch AI every few games. Let players know of AI switch.
		const int32 NewMoney = Money - 1;
		GameInstance->GlobalEventHandler->OnGameResult.Broadcast(PlayerControllerId, GamesPlayedCount, EGameResult::VE_Draw, NewMoney, EPlayerWeapon);
		UE_LOG(LogTemp, Warning, TEXT("Sent Game result"));
	}
}