// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "MyPlayerState.generated.h"

/**
 * 
 */
UCLASS()
class FPSDEMOHOMEWORK_API AMyPlayerState : public APlayerState
{
	GENERATED_BODY()

public:
	AMyPlayerState();
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
	float Health = 1.0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
	float Energy = 1.0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
	int32 Ammo = 30;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
	int32 OnceFiredAmmo = 1;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
	int32 MaxAmmo = 30;
	
};
