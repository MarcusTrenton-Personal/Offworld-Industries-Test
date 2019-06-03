// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 * 
 */
class ROCKPAPERSCISSORS_API Util
{
public:

	//Take from https ://answers.unrealengine.com/questions/330496/conversion-of-enum-to-string.html
	template<typename T>
	static FString EnumToString(const FString& enumName, const T value, const FString& defaultValue)
	{
		UEnum* pEnum = FindObject<UEnum>(ANY_PACKAGE, *enumName, true);
		return pEnum
			? ExpandEnumString(pEnum->GetNameByIndex(static_cast<uint8>(value)).ToString(), enumName)
			: defaultValue;
	}

	static FString ExpandEnumString(const FString& name, const FString& enumName)
	{
		FString expanded(name);
		FString spaceLetter("");
		FString spaceNumber("");
		FString search("");
		expanded.ReplaceInline(*enumName, TEXT(""), ESearchCase::CaseSensitive);
		expanded.ReplaceInline(TEXT("::"), TEXT(""), ESearchCase::CaseSensitive);
		for (TCHAR letter = 'A'; letter <= 'Z'; ++letter)
		{
			search = FString::Printf(TEXT("%c"), letter);
			spaceLetter = FString::Printf(TEXT(" %c"), letter);
			expanded.ReplaceInline(*search, *spaceLetter, ESearchCase::CaseSensitive);
		}
		for (TCHAR number = '0'; number <= '9'; ++number)
		{
			search = FString::Printf(TEXT("%c"), number);
			spaceNumber = FString::Printf(TEXT(" %c"), number);
			expanded.ReplaceInline(*search, *spaceNumber, ESearchCase::CaseSensitive);
		}
		expanded.ReplaceInline(TEXT("_"), TEXT(" -"), ESearchCase::CaseSensitive);
		expanded = expanded.RightChop(1).Trim().TrimEnd();
		return expanded;
	}
};
