// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Constants.h"

/**
 * 
 */
class ROCKPAPERSCISSORS_API IEnemy
{
public:
	virtual FString GetName() const = 0;
	virtual EWeapon SelectWeapon() const = 0;
	virtual void ProcessGameResult(
		const int32 PlayerControllerId,
		const EWeapon EPlayerWeapon,
		const EWeapon EEnemyWeapon,
		const EGameResult EResult) = 0;
};
