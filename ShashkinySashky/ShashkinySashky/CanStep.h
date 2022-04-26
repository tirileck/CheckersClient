#pragma once
#include "framework.h"
#include "StepRect.h"
#include "Figure.h"
#include "GameFigures.h"

enum TYPEFIGURE{WHITESHASH, BLACKSHASH, WHITEQUEEN, BLACKQUEEN};
enum WHO { ME, ENEMY };
enum DIRECTION{ NOTHING, LEFTUP, LEFTDOWN, RIGHTUP, RIGHTDOWN};

class CanStep
{
public:
	int CurrHMenu = 11000;

	HINSTANCE hInstace;
	StepRect* stepRects[8][8];

	static CanStep* InitRects(HINSTANCE hInstanse, HWND parentHwnd);

	//static void CreateStepLights(int wmId);

	void DrawRect(int i, int j, DRAWSTEPRECTCOLOW color) {
		stepRects[i][j]->DrawRect(color);
	}

	void HideRects() {
		for(int i = 0; i < 8; i++)
			for (int j = 0; j < 8; j++)
				stepRects[i][j]->HideRect();
	}

	// Получает указатель на квадрат по hMenu
	StepRect* GetStepRect(int hMenu);

	void CreateStepLogic(GameFigures* gameFigures, int figureX, int figureY, TYPEFIGURE type, WHO who, bool eaten = false, int fromX = -1, int fromY = -1, DIRECTION direction = NOTHING);

	void ClearEatenFiguresFromRects();

	void EnableRects(bool enable);

};

