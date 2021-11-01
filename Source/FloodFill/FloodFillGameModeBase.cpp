// Copyright Epic Games, Inc. All Rights Reserved.
#include "FloodFillWidget.h"
#include "Blueprint/UserWidget.h"
#include "Kismet/GameplayStatics.h"
#include "FloodFillGameModeBase.h"


void AFloodFillGameModeBase::ShowUI(TSubclassOf<UUserWidget> FloodFillUIClass)
{
	UUserWidget* Widget = CreateWidget<UUserWidget>(GetWorld(), FloodFillUIClass);
	FloodFillWidget = Cast<UFloodFillWidget>(Widget);
	FloodFillWidget->AddToViewport();
}
