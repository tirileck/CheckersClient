#pragma once
#include "framework.h"
#include "Figure.h"


class GameFigures
{
public:
	int CurrHMenu = 15000;

	Figure* figures[8][8];

	static GameFigures* InitFigure(HINSTANCE hInstanse, HWND parentHwnd);

	void DrawFigure(HINSTANCE hInstance, int i, int j) {
		figures[i][j]->Draw();
	}

	void MoveShash(int oldX, int oldY, int newX, int newY);

	Figure* GetFigure(int hMenu);

	void EatShah(Figure* eaten);

	Figure* GetEatenFigure(int oldX, int oldY, int newX, int newY);

	void EnableFigures(TypeOfClass typeOfFigure, bool enable);
};

