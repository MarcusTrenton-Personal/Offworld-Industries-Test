// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Constants.h"
#include "BartEnemy.h"
#include "NashEnemy.h"
#include "RockfordEnemy.h"
#include "GlobalEventHandler.h"
#include <vector>
#include <map>
#include "GameFramework/GameModeBase.h"
#include "RockPaperScissorsGameMode.generated.h"

/** GameMode class to specify pawn and playercontroller */
UCLASS(minimalapi)
class ARockPaperScissorsGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	ARockPaperScissorsGameMode();

	void StartPlay() override;

private:

	FRandomStream RandomGenerator;

	BartEnemy Bart;
	NashEnemy Nash;
	RockfordEnemy Rockford;

	std::vector<IEnemy*> Enemies {&Bart, &Nash, &Rockford};

	const int32 ENEMY_HANDS_BEFORE_CHANGE = 5;

	struct EnemyDuration
	{
		IEnemy* Enemy;
		int32 RemainingHands;
	};

	std::map<int32, EnemyDuration> PlayerEnemyDurations;

	UFUNCTION()
	void StartPlayerGameRound(
		const int32 PlayerControllerId,
		const EWeapon EPlayerWeapon,
		const int32 Bet,
		const int32 Money,
		const int32 GamesPlayedCount);

	IEnemy* SelectEnemy() const;
	EnemyDuration RefreshNewEnemy() const;
	EGameResult GetPlayerGameResult(const EWeapon EPlayerWeapon, const EWeapon EEnemyWeapon) const;
	int32 GetNewPlayerMoney(int32 Money, int32 Bet, EGameResult EResult);
	void DecreaseEnemyDurationForPlayer(int32 PlayerControllerId, UGlobalEventHandler* GlobalEventHandler);
};



