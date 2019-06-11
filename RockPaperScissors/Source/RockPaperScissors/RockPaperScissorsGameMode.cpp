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
		//TODO: Randomly determine at AI. Put duration in a constant. Broadcast to a player upon them joining a game.
		UWorld* World = GetWorld();
		if (World)
		{
			for (FConstPlayerControllerIterator Iterator = World->GetPlayerControllerIterator(); Iterator; ++Iterator)
			{
				APlayerController* PlayerController = Cast<APlayerController>(*Iterator);
				if (PlayerController)
				{
					int32 ControllerId = PlayerController->GetLocalPlayer()->GetControllerId();
					UE_LOG(LogTemp, Warning, TEXT("Found Player %i"), ControllerId);
					PlayerEnemyDurations[ControllerId] = RefreshNewEnemy();
					EnemyDuration& CurrentEnemy = PlayerEnemyDurations[ControllerId];
					GameInstance->GlobalEventHandler->OnEnemyAiChange.Broadcast(ControllerId, CurrentEnemy.RemainingHands, CurrentEnemy.Enemy->GetName());
				}
			}
		}
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

		EnemyDuration& CurrentEnemy = PlayerEnemyDurations[PlayerControllerId];
		const EWeapon EEnemyWeapon = CurrentEnemy.Enemy->SelectWeapon();
		const EGameResult EResult = GetPlayerGameResult(EPlayerWeapon, EEnemyWeapon);
		CurrentEnemy.Enemy->ProcessGameResult(PlayerControllerId, EPlayerWeapon, EEnemyWeapon, EResult);

		const int32 NewMoney = GetNewPlayerMoney(Money, Bet, EResult);

		GameInstance->GlobalEventHandler->OnGameResult.Broadcast(PlayerControllerId, GamesPlayedCount, EResult, NewMoney, EEnemyWeapon);

		DecreaseEnemyDurationForPlayer(PlayerControllerId, GameInstance->GlobalEventHandler);
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

ARockPaperScissorsGameMode::EnemyDuration ARockPaperScissorsGameMode::RefreshNewEnemy() const
{
	IEnemy* Enemy = SelectEnemy();
	EnemyDuration RefreshedEnemy = { Enemy, ENEMY_HANDS_BEFORE_CHANGE };
	return RefreshedEnemy;
}

EGameResult ARockPaperScissorsGameMode::GetPlayerGameResult(const EWeapon EPlayerWeapon, const EWeapon EEnemyWeapon) const
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

int32 ARockPaperScissorsGameMode::GetNewPlayerMoney(int32 Money, int32 Bet, EGameResult EResult)
{
	int32 MoneyChange = 0;
	switch (EResult)
	{
	case EGameResult::VE_Loss:
		MoneyChange = -Bet;
		break;

	case EGameResult::VE_Win:
		MoneyChange = Bet;
		break;

	case EGameResult::VE_Draw:
	default:
		MoneyChange = 0;
	}
	const int32 NewMoney = Money + MoneyChange;
	return NewMoney;
}

void ARockPaperScissorsGameMode::DecreaseEnemyDurationForPlayer(int32 PlayerControllerId, UGlobalEventHandler* GlobalEventHandler)
{
	EnemyDuration& CurrentEnemy = PlayerEnemyDurations[PlayerControllerId];
	CurrentEnemy.RemainingHands--;
	if (CurrentEnemy.RemainingHands <= 0)
	{
		PlayerEnemyDurations[PlayerControllerId] = RefreshNewEnemy();
		CurrentEnemy = PlayerEnemyDurations[PlayerControllerId];
		URockPaperScissorsGameInstance* GameInstance = Cast<URockPaperScissorsGameInstance>(GetGameInstance());
		GlobalEventHandler->OnEnemyAiChange.Broadcast(PlayerControllerId, CurrentEnemy.RemainingHands, CurrentEnemy.Enemy->GetName());
	}
}