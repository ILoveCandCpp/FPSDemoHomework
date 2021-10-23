// Copyright Epic Games, Inc. All Rights Reserved.

#include "FPSDemoHomeworkGameMode.h"
#include "FPSDemoHomeworkHUD.h"
#include "FPSDemoHomeworkCharacter.h"
#include "UObject/ConstructorHelpers.h"

AFPSDemoHomeworkGameMode::AFPSDemoHomeworkGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = AFPSDemoHomeworkHUD::StaticClass();
}
