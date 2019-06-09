// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "RockPaperScissorsPlayerState.generated.h"

/**
 * 
 */
UCLASS()
class ROCKPAPERSCISSORS_API ARockPaperScissorsPlayerState : public APlayerState
{
	GENERATED_BODY()
	
public:
	//TODO: Make into a designer-tweakable variable. Put in GameInstance contained object?
	const int32 STARTING_MONEY = 100;

	ARockPaperScissorsPlayerState();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RPSPlayerState")
	int32 Money;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RPSPlayerState")
	int32 GamesPlayedCount;
};
