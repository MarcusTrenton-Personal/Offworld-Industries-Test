// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "GlobalEventHandler.h"
#include "DataSingleton.generated.h"

/**
 * Modified from https://wiki.unrealengine.com/index.php?title=Global_Data_Access,_Data_Storage_Class_Accessible_From_Any_CPP_or_BP_Class_During_Runtime
 */
UCLASS(Blueprintable, BlueprintType)
class ROCKPAPERSCISSORS_API UDataSingleton : public UObject
{
	GENERATED_BODY()

public:
	UDataSingleton(const FObjectInitializer& ObjectInitializer);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data Singleton")
	FVector SolusEssentialVector;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data Singleton")
	UGlobalEventHandler* GlobalEventHandler;
};
