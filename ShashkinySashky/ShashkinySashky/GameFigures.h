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

};

