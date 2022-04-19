#pragma once
//#include "Global.h"
#include "CanStep.h"
#include "WindowElementIds.h"
#include "resource.h"
#include "StepRect.h"
#include "WindowsHeader.h"


CanStep* CanStep::InitRects(HINSTANCE hInstanse, HWND parentHwnd) {
	CanStep* canStep = new CanStep();
	for(int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++) {
			canStep->stepRects[i][j] = StepRect::CreateWND(hInstanse, parentHwnd, i * FIGURE_HEIGHT, j * FIGURE_WIDTH, canStep->CurrHMenu++);
		}

	return canStep;
}


//void CanStep::CreateStepLights(int wmId) {
//	Figure* currFigure = nullptr;
//	for(int i = 0; i < 8; i++)
//		for(int j = 0; j < 8; j++)
//			if (fuguresGlobal->figures[i][j] != nullptr && fuguresGlobal->figures[i][j]->wmId == wmId) {
//				MessageBox(NULL, L"Popa", 0, 0);
//			}
//}