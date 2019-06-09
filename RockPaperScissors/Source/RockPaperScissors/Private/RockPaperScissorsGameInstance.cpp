// Fill out your copyright notice in the Description page of Project Settings.


#include "RockPaperScissorsGameInstance.h"
#include "GlobalEventHandler.h"

URockPaperScissorsGameInstance::URockPaperScissorsGameInstance(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	GlobalEventHandler = CreateDefaultSubobject<UGlobalEventHandler>(TEXT("GlobalEventHandler"));
}