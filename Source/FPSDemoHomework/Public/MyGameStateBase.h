// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "MyGameStateBase.generated.h"

/**
 * 
 */
UCLASS()
class FPSDEMOHOMEWORK_API AMyGameStateBase : public AGameStateBase
{
	GENERATED_BODY()

public:
	AMyGameStateBase();
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Socre;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bIsVectory;
};
