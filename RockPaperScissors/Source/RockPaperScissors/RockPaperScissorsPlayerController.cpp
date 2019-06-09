// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "RockPaperScissorsPlayerController.h"
#include "RockPaperScissorsGameInstance.h"
#include "RockPaperScissorsPlayerState.h"

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
	ARockPaperScissorsPlayerState* RPSPlayerState = GetPlayerState<ARockPaperScissorsPlayerState>();
	if (RPSPlayerState)
	{
		int32 Money = RPSPlayerState->Money;
		int32 GamesPlayedCount = RPSPlayerState->GamesPlayedCount;
		int32 ControllerId = GetLocalPlayer()->GetControllerId(); //This is a stuipd way to get it, but the API doesn't show another//GetPlayerControllerId();
		UE_LOG(LogTemp, Log, TEXT("PlayerState Money %i GamesPlayerCount %i Player Controller "), Money, GamesPlayedCount, ControllerId);

		URockPaperScissorsGameInstance* GameInstance = Cast<URockPaperScissorsGameInstance>(GetGameInstance());
		if (GameInstance && GameInstance->GlobalEventHandler)
		{
			GameInstance->GlobalEventHandler->OnPlayerHandSelected.Broadcast(ControllerId, EPlayerWeapon, Bet, Money, GamesPlayedCount);
			UE_LOG(LogTemp, Warning, TEXT("Sent Player Hand"));
		}
	}
}