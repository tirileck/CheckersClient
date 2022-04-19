#pragma once
#include "framework.h"
#include "StepRect.h"

class CanStep
{
public:
	int CurrHMenu = 11000;

	StepRect* stepRects[8][8];

	static CanStep* InitRects(HINSTANCE hInstanse, HWND parentHwnd);

	//static void CreateStepLights(int wmId);

	void DrawRect(HINSTANCE hInstance, int i, int j, drawColor color) {
		stepRects[i][j]->DrawRect(hInstance, color);
	}
};

