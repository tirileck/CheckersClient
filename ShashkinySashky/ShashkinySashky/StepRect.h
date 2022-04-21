#pragma once
#include "framework.h"

static const COLORREF RedColor = RGB(255, 0, 0);
static const COLORREF GreenColor = RGB(0, 255, 0);
static const wchar_t STEP_RECT_WINDOW_CLASS_NAME[] = L"StepRectWindowClass";

enum DRAWSTEPRECTCOLOW{RED = 1, GREEN = 2};

class StepRect
{
public:
	HINSTANCE hInstance;
	HWND WindowHwnd;					// Дескриптор созданного окна

	int HMenu;
	int IndexX, IndexY;

	static StepRect* CreateWND(HINSTANCE hInstanse, HWND parentHwnd, int posX, int posY, int hMenu, int indexX, int indexY);

	static void RegisterStepRectClass(HINSTANCE hInstanse);		//Регистрирует класс окна

	void DrawRect(DRAWSTEPRECTCOLOW color);

	void HideRect();
};

