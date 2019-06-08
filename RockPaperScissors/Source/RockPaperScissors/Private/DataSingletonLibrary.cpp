// Fill out your copyright notice in the Description page of Project Settings.


#include "DataSingletonLibrary.h"
//#include "Engine.h"

UDataSingletonLibrary::UDataSingletonLibrary(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	UE_LOG(LogTemp, Warning, TEXT("Constructing Singleton"));
	//StoredObjectInitializer = &ObjectInitializer;
}

UDataSingleton* UDataSingletonLibrary::GetData(bool& IsValid)
{
	UE_LOG(LogTemp, Warning, TEXT("In GetData"));

	IsValid = false;
	UDataSingleton* DataInstance = Cast<UDataSingleton>(GEngine->GameSingleton);
	if (!GEngine->GameSingleton)
	{
		UE_LOG(LogTemp, Warning, TEXT("GEngine->GameSingleton is null"));

		//UDataSingleton newSingleton = GEngine->CreateDefaultSubobject<UDataSingleton>(TEXT("Singleton"));

		//Leads to fixing singleton
		//1) Load up default level and inspect blueprint for initiatization. A singleton should only be instantiated once, so it makes sense to define that point. FAILED.
		//2) Inspect custom level for initialization. FAILED.
		//3) Check project settings for more singleton or initialization configuration. FAILED.
		//4) Make the single object directly. FAILED
		//5) Find and call the PlayerController directly via Engine 
	}

	if (!DataInstance)
	{
		UE_LOG(LogTemp, Warning, TEXT("DataInstance is null"));
		return nullptr;
	}
	if (!DataInstance->IsValidLowLevel())
	{
		UE_LOG(LogTemp, Warning, TEXT("DataInstance is low-level null"));
		return nullptr;
	}

	IsValid = true;
	return DataInstance;
}