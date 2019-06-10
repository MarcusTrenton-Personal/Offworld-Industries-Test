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

	RandomGenerator.GenerateNewSeed();
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

		IEnemy* Enemy = SelectEnemy();
		const EWeapon EEnemyWeapon = Enemy->SelectWeapon();
		const EGameResult EResult = GetPlayerGameResult(EPlayerWeapon, EEnemyWeapon);
		Enemy->ProcessGameResult(
			PlayerControllerId,
			EPlayerWeapon,
			EEnemyWeapon,
			EResult);

		int32 MoneyChange = 0;
		switch (EResult)
		{
		case EGameResult::VE_Loss :
			MoneyChange = -Bet;
			break;

		case EGameResult::VE_Win :
			MoneyChange = Bet;
			break;

		case EGameResult::VE_Draw : 
		default :
			MoneyChange = 0;
		}
		const int32 NewMoney = Money + MoneyChange;

		GameInstance->GlobalEventHandler->OnGameResult.Broadcast(PlayerControllerId, GamesPlayedCount, EResult, NewMoney, EEnemyWeapon);
	}
}

IEnemy* ARockPaperScissorsGameMode::SelectEnemy() const
{
	IEnemy* Enemy = nullptr;
	if (!Enemies.empty())
	{
		const int32 RandomIndex = RandomGenerator.RandRange(0, Enemies.size() - 1);
		Enemy = Enemies[RandomIndex];
	}
	
	return Enemy;
}

EGameResult ARockPaperScissorsGameMode::GetPlayerGameResult(EWeapon EPlayerWeapon, EWeapon EEnemyWeapon) const
{
	//TODO: Reduce this check down to operator overload checks
	EGameResult EResult = EGameResult::VE_Loss;

	if (EPlayerWeapon == EEnemyWeapon)
	{
		EResult = EGameResult::VE_Draw;
	}
	//Only cases left to detect is Player win conditions. The rest are losses by default.
	else if (	(EPlayerWeapon == EWeapon::VE_Rock &&		EEnemyWeapon == EWeapon::VE_Scissors) ||
				(EPlayerWeapon == EWeapon::VE_Scissors &&	EEnemyWeapon == EWeapon::VE_Paper) ||
				(EPlayerWeapon == EWeapon::VE_Paper &&		EEnemyWeapon == EWeapon::VE_Rock))
	{
		EResult = EGameResult::VE_Win;
	}

	return EResult;
}