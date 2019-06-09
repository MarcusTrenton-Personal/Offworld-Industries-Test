// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "RockPaperScissorsEvents.h"
#include "GlobalEventHandler.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FMainMenuEventDelegate_OnHandSelected, EWeapon, EPlayerWeapon, int32, Bet);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_FiveParams(FPlayerControllerEventDelegate_OnHandSelected, 
	int32, PlayerControllerId, 
	EWeapon, EPlayerWeapon, 
	int32, Bet, 
	int32, Money, 
	int32, GamesPlayedCount);

UCLASS(meta = (BlueprintSpawnableComponent), Category = "Global Events")
class ROCKPAPERSCISSORS_API UGlobalEventHandler : public UActorComponent
{
	GENERATED_BODY()

public:	

	UPROPERTY(BlueprintAssignable, BlueprintCallable, Category = "Global Events")
	FMainMenuEventDelegate_OnHandSelected OnMainMenuHandSelected;

	UPROPERTY(BlueprintAssignable, BlueprintCallable, Category = "Global Events")
	FPlayerControllerEventDelegate_OnHandSelected OnPlayerHandSelected;
};
