// Fill out your copyright notice in the Description page of Project Settings.


#include "DataSingleton.h"

UDataSingleton::UDataSingleton(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	SolusEssentialVector = FVector(9000, 0, 0);

	//GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, FString::Printf(TEXT("GlobalEventHandler is null before %s"), GlobalEventHandler == nullptr ? "Null" : "Instantiated"));
	UE_LOG(LogTemp, Warning, TEXT("Before construct GlobalEventHandler"));
	GlobalEventHandler = CreateDefaultSubobject<UGlobalEventHandler>(TEXT("GlobalEventHandler"));
	//GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, FString::Printf(TEXT("GlobalEventHandler is null after %s"), GlobalEventHandler == nullptr ? "Null" : "Instantiated"));
	UE_LOG(LogTemp, Warning, TEXT("After construct GlobalEventHandler"));
}