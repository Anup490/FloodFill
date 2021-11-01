// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "FloodFillGameModeBase.generated.h"

/**
 * 
 */

class UUserWidget;
class UFloodFillWidget;

UCLASS()
class FLOODFILL_API AFloodFillGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
	UFloodFillWidget* FloodFillWidget;
protected:
	UFUNCTION(BlueprintCallable)
	void ShowUI(TSubclassOf<UUserWidget> FloodFillUIClass);
};
