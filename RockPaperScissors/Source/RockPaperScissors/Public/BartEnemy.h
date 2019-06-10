// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Enemy.h"

/**
 * Predictable enemy that always picks Rock. https://www.youtube.com/watch?v=bYJQPYKvU6U
 */
class ROCKPAPERSCISSORS_API BartEnemy : public IEnemy
{
public:
	FString GetName() const override;
	EWeapon SelectWeapon() const override;
	void ProcessGameResult(
		const int32 PlayerControllerId,
		const EWeapon EPlayerWeapon,
		const EWeapon EEnemyWeapon,
		const EGameResult EResult) override;
};
