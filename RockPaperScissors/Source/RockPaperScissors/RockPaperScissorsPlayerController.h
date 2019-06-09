// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "Constants.h"
#include "Blueprint/UserWidget.h"
#include "RockPaperScissorsEvents.h"
#include "RockPaperScissorsPlayerController.generated.h"

//DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FHandDelegate, FRockPaperScissorsHandEventParams, EventParams);

/** PlayerController class used to enable cursor */
UCLASS()
class ARockPaperScissorsPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	ARockPaperScissorsPlayerController();

	virtual void BeginPlay() override;

	//UFUNCTION(BlueprintAssignable, Category = "RPSPlayerController")
	//FHandDelegate OnHandDelegate;

	UFUNCTION()
	void SendPlayerHand(const EWeapon EPlayerWeapon, const int32 Bet);
};


