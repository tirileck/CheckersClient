#pragma once
#include "framework.h"
#include "CanStep.h"
#include "GameFigures.h"

static const wchar_t GAME_WINDOW_CLASS_NAME[] = L"GameWindowClass";
static const wchar_t GAME_WINDOW_NAME[] = L"Играемс....";

static const COLORREF LightColor = RGB(255, 196, 41);
static const COLORREF DarkColor = RGB(61, 3, 3);

static CanStep* canSteps;
static GameFigures* figures;


class GameWindow
{
public:
	HWND WindowHwnd;					// Дескриптор созданного окна

	WHO currentPlayer;

	void StartGame(WHO firstPlayer);

	static GameWindow* CreateWND(HINSTANCE hInstanse);

	static void RegisterGameWndClass(HINSTANCE hInstanse);		//Регистрирует класс окна

};


