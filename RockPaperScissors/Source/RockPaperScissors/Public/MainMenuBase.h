// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MainMenuBase.generated.h"

UCLASS()
class ROCKPAPERSCISSORS_API UMainMenuBase : public UUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "MainMenu")
	void SendHand(const EWeapon EPlayerWeapon, const int32 BetAmount);

	UFUNCTION(BlueprintPure, Category = "MainMenu")
	bool IsValidBet(const FString Text) const;
};
