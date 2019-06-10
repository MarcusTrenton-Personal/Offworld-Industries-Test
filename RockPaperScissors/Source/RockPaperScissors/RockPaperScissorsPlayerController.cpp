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
		GameInstance->GlobalEventHandler->OnMainMenuHandSelected.AddDynamic(	this, &ARockPaperScissorsPlayerController::SendPlayerHand);
		GameInstance->GlobalEventHandler->OnGameResult.AddDynamic(				this, &ARockPaperScissorsPlayerController::OnGameResult);
	}
}

void ARockPaperScissorsPlayerController::SendPlayerHand(const EWeapon EPlayerWeapon, const int32 Bet)
{
	ARockPaperScissorsPlayerState* RPSPlayerState = GetPlayerState<ARockPaperScissorsPlayerState>();
	if (RPSPlayerState)
	{
		int32 Money = RPSPlayerState->Money;
		int32 GamesPlayedCount = RPSPlayerState->GamesPlayedCount;
		int32 ControllerId = GetId();

		URockPaperScissorsGameInstance* GameInstance = Cast<URockPaperScissorsGameInstance>(GetGameInstance());
		if (GameInstance && GameInstance->GlobalEventHandler)
		{
			GameInstance->GlobalEventHandler->OnPlayerHandSelected.Broadcast(ControllerId, EPlayerWeapon, Bet, Money, GamesPlayedCount);
		}
	}
}

void ARockPaperScissorsPlayerController::OnGameResult(
	const int32 PlayerControllerId,
	const int32 GameIndex,
	const EGameResult EResult,
	const int32 Money,
	const EWeapon EEnemyWeapon)
{
	UE_LOG(LogTemp, Warning, TEXT("Received game result"));
	int32 ControllerId = GetId();
	if (ControllerId == PlayerControllerId)
	{
		ARockPaperScissorsPlayerState* RPSPlayerState = GetPlayerState<ARockPaperScissorsPlayerState>();
		if (RPSPlayerState)
		{
			RPSPlayerState->Money = Money;
			RPSPlayerState->GamesPlayedCount = GameIndex + 1;

			//Now that the player state has been updated, it's safe to let the UI know.
			URockPaperScissorsGameInstance* GameInstance = Cast<URockPaperScissorsGameInstance>(GetGameInstance());
			if (GameInstance && GameInstance->GlobalEventHandler)
			{
				GameInstance->GlobalEventHandler->OnPostGameResult.Broadcast(PlayerControllerId, GameIndex, EResult, Money, EEnemyWeapon);
			}
		}
	}
}

int32 ARockPaperScissorsPlayerController::GetId() const
{
	return GetLocalPlayer()->GetControllerId(); //This is a stupid way to get it, but the API doesn't show another
}