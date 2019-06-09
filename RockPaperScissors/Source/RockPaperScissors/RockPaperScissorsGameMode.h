// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Constants.h"
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

	UFUNCTION()
	void StartPlayerGameRound(
		const int32 PlayerControllerId,
		const EWeapon EPlayerWeapon,
		const int32 Bet,
		const int32 Money,
		const int32 GamesPlayedCount);
};



