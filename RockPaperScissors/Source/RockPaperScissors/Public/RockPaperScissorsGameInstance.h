// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "GlobalEventHandler.h"
#include "RockPaperScissorsGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class ROCKPAPERSCISSORS_API URockPaperScissorsGameInstance : public UGameInstance
{
	GENERATED_BODY()

public:
	URockPaperScissorsGameInstance(const FObjectInitializer& ObjectInitializer);
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data Singleton")
	UGlobalEventHandler* GlobalEventHandler;
};
