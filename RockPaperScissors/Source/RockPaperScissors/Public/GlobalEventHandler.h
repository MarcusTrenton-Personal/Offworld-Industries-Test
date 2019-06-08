// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "RockPaperScissorsEvents.h"
#include "GlobalEventHandler.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FLevelEventDelegate_OnLevelComplete, uint8, LevelIndex);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FMainMenuEventDelegate_OnHandSelected, EWeapon, EPlayerWeapon, int32, Bet);

UCLASS(meta = (BlueprintSpawnableComponent), Category = "Global Events")
class ROCKPAPERSCISSORS_API UGlobalEventHandler : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	//UGlobalEventHandler();

	//void InitializeComponent() override;

	UPROPERTY(BlueprintAssignable, BlueprintCallable, Category = "Level Events")
	FLevelEventDelegate_OnLevelComplete OnLevelComplete;

	UPROPERTY(BlueprintAssignable, BlueprintCallable, Category = "Global Events")
	FMainMenuEventDelegate_OnHandSelected OnMainMenuHandSelected;
};