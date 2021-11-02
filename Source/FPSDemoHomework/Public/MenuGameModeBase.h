// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "MenuGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class FPSDEMOHOMEWORK_API AMenuGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
public:
	AMenuGameModeBase();

	UFUNCTION(BlueprintCallable, Category = "UMG Game")
	void ChangeMenuWidget(TSubclassOf<UUserWidget> NewWidgetClass);

	virtual void Tick(float DeltaSeconds) override;
	
	/** 游戏开始时调用。*/
	virtual void BeginPlay() override;

	/** 游戏开始时，用作菜单的控件类。*/
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "UMG Game")
	TSubclassOf<UUserWidget> StartingWidgetClass;

	/** 用作菜单的控件实例。*/
	UPROPERTY(EditAnywhere)
	UUserWidget* CurrentWidget;
};
