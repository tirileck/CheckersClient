#pragma once
#include "framework.h"
#include "Figure.h"

static const wchar_t WHITE_FIGURE_WINDOW_CLASS_NAME[] = L"WhiteFigureWindowClass";

class WhiteFigure : public Figure
{

public:

	static WhiteFigure* CreateWND(HINSTANCE hInstanse, HWND parentHwnd, int posX, int posY, int hMenu, int indexX, int indexY);

	static void RegisterWhiteFigureClass(HINSTANCE hInstanse);		//Регистрирует класс окна
};

