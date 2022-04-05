#pragma once
#include "framework.h"

static const wchar_t GAME_WINDOW_CLASS_NAME[] = L"GameWindowClass";
static const wchar_t GAME_WINDOW_NAME[] = L"�������....";

static const COLORREF LightColor = RGB(255, 196, 41);
static const COLORREF DarkColor = RGB(61, 3, 3);

class GameWindow
{
public:
	HWND WindowHwnd;					// ���������� ���������� ����

	

	static GameWindow* CreateWND(HINSTANCE hInstanse);

	static void RegisterGameWndClass(HINSTANCE hInstanse);		//������������ ����� ����
};


