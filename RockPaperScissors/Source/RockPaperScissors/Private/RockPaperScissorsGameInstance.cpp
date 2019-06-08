// Fill out your copyright notice in the Description page of Project Settings.


#include "RockPaperScissorsGameInstance.h"
#include "GlobalEventHandler.h"

URockPaperScissorsGameInstance::URockPaperScissorsGameInstance(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	UE_LOG(LogTemp, Warning, TEXT("Before construct GlobalEventHandler"));
	//GlobalEventHandler = CreateDefaultSubobject<UGlobalEventHandler>(TEXT("GlobalEventHandler"));
	//UE_LOG(LogTemp, Warning, TEXT("After construct GlobalEventHandler"));
}