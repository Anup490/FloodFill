// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Math/Color.h"
#include "FloodFillWidget.generated.h"

class FloodFiller;
/**
 * 
 */
UCLASS()
class FLOODFILL_API UFloodFillWidget : public UUserWidget
{
	GENERATED_BODY()

	FloodFiller* pFloodFiller;
protected:
	UFUNCTION(BlueprintCallable)
	void InitFloodFiller();

	UFUNCTION(BlueprintCallable)
	void RunFloodFiller(int row, int column, int newC);

	UFUNCTION(BlueprintCallable)
	FColor GetColorByMatrixPosition(int row, int column);
	
};
