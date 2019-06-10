// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Enemy.h"

/**
 * This enemy is always picks what would have won the last hand. The first round is default rock.
 * Named after Rockford criticism of the European military to be preparing to "to fight the last war".
 * https://www.barrypopik.com/index.php/new_york_city/entry/generals_always_fight_the_last_war/
 */
class ROCKPAPERSCISSORS_API RockfordEnemy : public IEnemy
{
public:
	RockfordEnemy();
	FString GetName() const override;
	EWeapon SelectWeapon() const override;
	void ProcessGameResult(
		const int32 PlayerControllerId,
		const EWeapon EPlayerWeapon,
		const EWeapon EEnemyWeapon,
		const EGameResult EResult) override;
	
private:
	EWeapon LastPlayerWeapon;
};
