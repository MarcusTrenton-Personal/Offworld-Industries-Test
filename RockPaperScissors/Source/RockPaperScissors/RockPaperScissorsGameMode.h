// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Constants.h"
#include "BartEnemy.h"
#include "NashEnemy.h"
#include "RockfordEnemy.h"
#include <vector>
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

	UFUNCTION()
	void StartPlayerGameRound(
		const int32 PlayerControllerId,
		const EWeapon EPlayerWeapon,
		const int32 Bet,
		const int32 Money,
		const int32 GamesPlayedCount);

	IEnemy* SelectEnemy() const;

	EGameResult GetPlayerGameResult(EWeapon EPlayerWeapon, EWeapon EEnemyWeapon) const;
};



