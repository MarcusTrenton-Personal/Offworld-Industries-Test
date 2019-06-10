// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Enemy.h"
#include "RandomStream.h"

/**
 * Enemy randomly chooses a weapon. https://www.quantamagazine.org/the-game-theory-math-behind-rock-paper-scissors-20180402/ 
 */
class ROCKPAPERSCISSORS_API NashEnemy : public IEnemy
{
public:
	NashEnemy();
	FString GetName() const override;
	EWeapon SelectWeapon() const override;
	void ProcessGameResult(
		const int32 PlayerControllerId,
		const EWeapon EPlayerWeapon,
		const EWeapon EEnemyWeapon,
		const EGameResult EResult) override;

private:
	FRandomStream RandomGenerator;
};
