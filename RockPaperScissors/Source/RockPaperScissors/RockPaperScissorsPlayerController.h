// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "Constants.h"
#include "Blueprint/UserWidget.h"
#include "RockPaperScissorsEvents.h"
#include "RockPaperScissorsPlayerController.generated.h"

/** PlayerController class used to enable cursor */
UCLASS()
class ARockPaperScissorsPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	ARockPaperScissorsPlayerController();

	virtual void BeginPlay() override;

private:

	UFUNCTION()
	void SendPlayerHand(const EWeapon EPlayerWeapon, const int32 Bet);

	UFUNCTION()
	void OnGameResult(
		const int32 PlayerControllerId,
		const int32 GameNumber,
		const EGameResult EResult,
		const int32 Money,
		const EWeapon EEnemyWeapon);

	int32 GetId() const;
};


