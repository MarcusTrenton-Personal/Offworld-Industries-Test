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

DECLARE_DYNAMIC_MULTICAST_DELEGATE_FiveParams(FGameModeEventDelegate_OnGameResult,
	int32, PlayerControllerId,
	int32, GameIndex,
	EGameResult, EResult,
	int32, Money,
	EWeapon, EEnemyWeapon);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_FiveParams(FPlayerControllerEventDelegate_OnPostGameResult,
	int32, PlayerControllerId,
	int32, GameIndex,
	EGameResult, EResult,
	int32, Money,
	EWeapon, EEnemyWeapon);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FGameModeEventDelegate_OnEnemyAiChange,
	int32, PlayerControllerId,
	int32, GameCountForNewEnemy,
	FString, EnemyName);

UCLASS(meta = (BlueprintSpawnableComponent), Category = "Global Events")
class ROCKPAPERSCISSORS_API UGlobalEventHandler : public UActorComponent
{
	GENERATED_BODY()

public:	

	UPROPERTY(BlueprintAssignable, BlueprintCallable, Category = "Global Events")
	FMainMenuEventDelegate_OnHandSelected OnMainMenuHandSelected;

	UPROPERTY(BlueprintAssignable, BlueprintCallable, Category = "Global Events")
	FPlayerControllerEventDelegate_OnHandSelected OnPlayerHandSelected;

	UPROPERTY(BlueprintAssignable, BlueprintCallable, Category = "Global Events")
	FGameModeEventDelegate_OnGameResult OnGameResult;

	UPROPERTY(BlueprintAssignable, BlueprintCallable, Category = "Global Events")
	FPlayerControllerEventDelegate_OnPostGameResult OnPostGameResult;

	UPROPERTY(BlueprintAssignable, BlueprintCallable, Category = "Global Events")
	FGameModeEventDelegate_OnEnemyAiChange OnEnemyAiChange;
};
