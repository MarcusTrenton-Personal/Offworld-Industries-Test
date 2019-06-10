// Fill out your copyright notice in the Description page of Project Settings.


#include "NashEnemy.h"

NashEnemy::NashEnemy()
{
	RandomGenerator.GenerateNewSeed();
}

FString NashEnemy::GetName() const
{
	return FString("Nash");
}

EWeapon NashEnemy::SelectWeapon() const
{
	EWeapon EEnemyWeapon = EWeapon::VE_Rock;

	const int32 RandomNumber = RandomGenerator.RandRange(0, 2);
	switch (RandomNumber)
	{
	case 0:
		EEnemyWeapon = EWeapon::VE_Rock;
		break;

	case 1:
		EEnemyWeapon = EWeapon::VE_Paper;
		break;

	case 2:
		EEnemyWeapon = EWeapon::VE_Scissors;
		break;

	default:
		EEnemyWeapon = EWeapon::VE_Rock;
	}

	return EEnemyWeapon;
}

void NashEnemy::ProcessGameResult(
	const int32 PlayerControllerId,
	const EWeapon EPlayerWeapon,
	const EWeapon EEnemyWeapon,
	const EGameResult EResult)
{
	//Learning is pointless
}