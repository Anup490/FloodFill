// Fill out your copyright notice in the Description page of Project Settings.

#include "FloodFillWidget.h"
#include "FloodFiller.h"

void UFloodFillWidget::InitFloodFiller()
{
	pFloodFiller = new FloodFiller;
	pFloodFiller->InitScreen();
}

void UFloodFillWidget::RunFloodFiller(int row, int column, int newC)
{
	pFloodFiller->FloodFill(row, column, newC);
}

FColor UFloodFillWidget::GetColorByMatrixPosition(int row, int column)
{
	return pFloodFiller->GetColorByMatrixLocation(row, column);
}

