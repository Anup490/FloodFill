// Fill out your copyright notice in the Description page of Project Settings.
#include "FloodFiller.h"

#define M 2
#define N 2


FloodFiller::FloodFiller()
{
    screen = new int* [N];
    for (int i = 0; i < N; ++i)
    {
        screen[i] = new int[M];
    }
}

FloodFiller::~FloodFiller()
{
    delete[] screen;
}

void FloodFiller::InitScreen()
{
    int screenDefVal[M][N] = { {0, 1},
                     {0, 1} };

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; j++)
        {
            screen[i][j] = screenDefVal[i][j];
        }
    }
    DisplayScreen();
}

void FloodFiller::FloodFillUtil(int x, int y, int prevC, int newC)
{
    // Base cases
    if (x < 0 || x >= M || y < 0 || y >= N)
        return;
    if (screen[x][y] != prevC)
        return;
    if (screen[x][y] == newC)
        return;

    // Replace the color at (x, y)
    screen[x][y] = newC;

    // Recur for north, east, south and west
    FloodFillUtil(x + 1, y, prevC, newC);
    FloodFillUtil(x - 1, y, prevC, newC);
    FloodFillUtil(x, y + 1, prevC, newC);
    FloodFillUtil(x, y - 1, prevC, newC);
}

void FloodFiller::FloodFill(int x, int y, int newC)
{
    int prevC = screen[x][y];
    if (prevC == newC) return;
    FloodFillUtil(x, y, prevC, newC);
    DisplayScreen();
}

FColor FloodFiller::GetColorByNumber(int num)
{
    switch (num)
    {
    case 0:
        return FColor::Red;
    default:
        return FColor::Blue;
    }        
}

int FloodFiller::GetNumberByColor(FColor color)
{
    if (color.R == 1)
    {
        return 0;
    }
    return 1;
}

FColor FloodFiller::GetColorByMatrixLocation(int row, int column)
{
    if ((row < M) && (column < N))
    {
        UE_LOG(LogTemp, Warning, TEXT("row : %d column : %d new color : %d"), row, column, screen[row][column]);
        return GetColorByNumber(screen[row][column]);
    }
    return FColor::Blue;
}

void FloodFiller::DisplayScreen()
{
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; j++)
        {
            UE_LOG(LogTemp, Warning, TEXT("row : %d column : %d new color : %d"), i, j, screen[i][j]);
        }
    }
}