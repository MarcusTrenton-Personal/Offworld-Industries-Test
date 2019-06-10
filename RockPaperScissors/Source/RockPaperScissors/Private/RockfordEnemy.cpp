// Fill out your copyright notice in the Description page of Project Settings.


#include "RockfordEnemy.h"

RockfordEnemy::RockfordEnemy()
{
	LastPlayerWeapon = EWeapon::VE_Scissors;
}

FString RockfordEnemy::GetName() const
{
	return FString("Rockford");
}

EWeapon RockfordEnemy::SelectWeapon() const
{
	EWeapon EWeaponChoice = EWeapon::VE_Paper;

	//Fight to win the last war.
	switch (LastPlayerWeapon)
	{
	case EWeapon::VE_Paper :
		EWeaponChoice = EWeapon::VE_Scissors;
		break;

	case EWeapon::VE_Rock :
		EWeaponChoice = EWeapon::VE_Paper;
		break;

	case EWeapon::VE_Scissors :
		EWeaponChoice = EWeapon::VE_Rock;
		break;

	default:
		EWeaponChoice = EWeapon::VE_Paper;
	}

	return EWeaponChoice;
}

void RockfordEnemy::ProcessGameResult(
	const int32 PlayerControllerId,
	const EWeapon EPlayerWeapon,
	const EWeapon EEnemyWeapon,
	const EGameResult EResult)
{
	LastPlayerWeapon = EPlayerWeapon; //Remember the last war.
}