// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "DataSingleton.h"
#include "DataSingletonLibrary.generated.h"

//note about UBlueprintFunctionLibrary
// This class is a base class for any function libraries exposed to blueprints.
// Methods in subclasses are expected to be static, and no methods should be added to the base class.


/**
 * Modified from https://wiki.unrealengine.com/index.php?title=Global_Data_Access,_Data_Storage_Class_Accessible_From_Any_CPP_or_BP_Class_During_Runtime
 */
UCLASS()
class ROCKPAPERSCISSORS_API UDataSingletonLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
public:
	UDataSingletonLibrary(const FObjectInitializer& ObjectInitializer);

	UFUNCTION(BlueprintPure, Category = "Data Singleton")
	static UDataSingleton* GetData(bool& IsValid);

private:
	const FObjectInitializer* StoredObjectInitializer;
};
