#pragma once
#include "framework.h"

static const COLORREF RedColor = RGB(255, 0, 0);
static const COLORREF GreenColor = RGB(0, 255, 0);
static const wchar_t STEP_RECT_WINDOW_CLASS_NAME[] = L"StepRectWindowClass";

enum drawColor{RED = 1, GREEN = 2};

class StepRect
{
public:
	HWND WindowHwnd;					// ���������� ���������� ����

	static StepRect* CreateWND(HINSTANCE hInstanse, HWND parentHwnd, int posX, int posY, int hMenu);

	static void RegisterStepRectClass(HINSTANCE hInstanse);		//������������ ����� ����

	void DrawRect(HINSTANCE hInstanse, drawColor color);
};

