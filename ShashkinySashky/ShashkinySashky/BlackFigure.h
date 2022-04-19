#pragma once
#include "framework.h"
#include "Figure.h"

static const wchar_t BLACK_FIGURE_WINDOW_CLASS_NAME[] = L"BlackFigureWindowClass";

class BlackFigure : public Figure
{
public:

	static BlackFigure* CreateWND(HINSTANCE hInstanse, HWND parentHwnd, int posX, int posY, int hMenu);

	static void RegisterBlackFigureClass(HINSTANCE hInstanse);		//Регистрирует класс окна
};

