// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once 

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "FPSDemoHomeworkHUD.generated.h"

UCLASS()
class AFPSDemoHomeworkHUD : public AHUD
{
	GENERATED_BODY()

public:
	AFPSDemoHomeworkHUD();

	/** Primary draw call for the HUD */
	virtual void DrawHUD() override;

private:
	/** Crosshair asset pointer */
	class UTexture2D* CrosshairTex;

};

