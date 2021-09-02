// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Math/Color.h"
/**
 * 
 */
class FLOODFILL_API FloodFiller
{
    int** screen;
    void FloodFillUtil(int x, int y, int prevC, int newC);
    void DisplayScreen();
public:
    FloodFiller();
    ~FloodFiller();
    void InitScreen();
    void FloodFill(int x, int y, int newC);
    FColor GetColorByNumber(int num);
    int GetNumberByColor(FColor color);
    FColor GetColorByMatrixLocation(int row, int column);
};
