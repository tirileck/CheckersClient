#pragma once
#include "framework.h"

static const wchar_t HELLO_WINDOW_CLASS_NAME[] = L"Sample Window Class";
static const wchar_t HELLO_WINDOW_NAME[] = L"Добро пожаловать!";

class HelloWindow
{
public:
	HWND WindowHwnd;					// Дескриптор созданного окна
	
	HWND LabelHwnd;
	HWND InputNameHwnd;
	HWND StartButtonHwnd;

	static HelloWindow* CreateWND(HINSTANCE hInstanse);

	static void RegisterHelloWndClass(HINSTANCE hInstanse);		//Регистрирует класс окна
};

