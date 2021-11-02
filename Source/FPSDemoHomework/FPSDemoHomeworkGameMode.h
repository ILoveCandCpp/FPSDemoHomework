// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "FPSDemoHomeworkGameMode.generated.h"

UCLASS(minimalapi)
class AFPSDemoHomeworkGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	AFPSDemoHomeworkGameMode();

	UFUNCTION(BlueprintCallable, Category = "UMG Game")
	void ChangeMenuWidget(TSubclassOf<UUserWidget> NewWidgetClass);

	virtual void Tick(float DeltaSeconds) override;

	// UFUNCTION(BlueprintNativeEvent)
	void OnVictory();
	
	/** 游戏开始时调用。*/
	virtual void BeginPlay() override;

	/** 游戏开始时，用作菜单的控件类。*/
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "UMG Game")
	TSubclassOf<UUserWidget> StartingWidgetClass;

	/** 用作菜单的控件实例。*/
	UPROPERTY(EditAnywhere)
	UUserWidget* CurrentWidget;
};



