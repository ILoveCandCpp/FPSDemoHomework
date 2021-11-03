// Copyright Epic Games, Inc. All Rights Reserved.

#include "FPSDemoHomeworkGameMode.h"
#include "Blueprint/UserWidget.h"
#include "FPSDemoHomeworkHUD.h"
#include "FPSDemoHomeworkCharacter.h"
#include "MyGameStateBase.h"
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

void AFPSDemoHomeworkGameMode::ChangeMenuWidget(TSubclassOf<UUserWidget> NewWidgetClass)
{
	if (CurrentWidget != nullptr)
	{
		CurrentWidget->RemoveFromViewport();
		CurrentWidget = nullptr;
	}
	if (NewWidgetClass != nullptr)
	{
		CurrentWidget = CreateWidget<UUserWidget>(GetWorld(), NewWidgetClass);
		if (CurrentWidget != nullptr)
		{
			CurrentWidget->AddToViewport();
		}
	}
}

void AFPSDemoHomeworkGameMode::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	/* UE_LOG(LogTemp, Error, TEXT(" AFPSDemoHomeworkGameMode::Tick  "));
	AMyGameStateBase* GS = Cast<AMyGameStateBase>(GetWorld()->GetGameState());
	if (GS)
	{
		if(GS->Socre >= 10)
		{
			UE_LOG(LogTemp, Error, TEXT(" AFPSDemoHomeworkGameMode::Tick  "));
			OnVictory();
		}
	}*/
}

void AFPSDemoHomeworkGameMode::OnVictory()
{
	UE_LOG(LogTemp, Error, TEXT("ERRRRRRRRRRRRRRRRRRRR OnVictory "));
	static ConstructorHelpers::FClassFinder<UUserWidget> UserWidgetClassFinder(TEXT("WidgetBlueprint'/Game/FirstPersonCPP/Blueprints/BP_Victory.BP_Victory'"));
	if(UserWidgetClassFinder.Succeeded())
	{
		if (CurrentWidget != nullptr)
		{
			CurrentWidget->RemoveFromViewport();
			CurrentWidget = nullptr;
		}
		if (UserWidgetClassFinder.Class != nullptr)
		{
			CurrentWidget = CreateWidget<UUserWidget>(GetWorld(), UserWidgetClassFinder.Class);
			if (CurrentWidget != nullptr)
			{
				CurrentWidget->AddToViewport();
			}
		}
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("ERRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRR"));
	}
}


void AFPSDemoHomeworkGameMode::BeginPlay()
{
	Super::BeginPlay();
	ChangeMenuWidget(StartingWidgetClass);
}
