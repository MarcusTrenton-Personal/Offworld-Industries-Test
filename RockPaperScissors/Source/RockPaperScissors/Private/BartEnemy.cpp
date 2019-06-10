// Fill out your copyright notice in the Description page of Project Settings.


#include "BartEnemy.h"

FString BartEnemy::GetName() const
{
	return FString("Bart");
}

EWeapon BartEnemy::SelectWeapon() const
{
	return EWeapon::VE_Rock;
}

void BartEnemy::ProcessGameResult(
	const int32 PlayerControllerId,
	const EWeapon EPlayerWeapon,
	const EWeapon EEnemyWeapon,
	const EGameResult EResult)
{
	//Don't bother learning
}
