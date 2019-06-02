// Fill out your copyright notice in the Description page of Project Settings.


#include "MainMenuBase.h"
#include "Engine.h"

void UMainMenuBase::PlayGame()
{
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("Some debug message!"));
	}
}