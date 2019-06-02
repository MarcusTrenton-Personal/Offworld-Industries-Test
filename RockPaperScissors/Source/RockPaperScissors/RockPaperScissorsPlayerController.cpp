// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "RockPaperScissorsPlayerController.h"

ARockPaperScissorsPlayerController::ARockPaperScissorsPlayerController()
{
	bShowMouseCursor = true;
	bEnableClickEvents = true;
	bEnableTouchEvents = true;
	DefaultMouseCursor = EMouseCursor::Crosshairs;
}
