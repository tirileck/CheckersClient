#pragma once
#include "framework.h"
#include "WindowsHeader.h"

#pragma region Prototypes
void RegisterWNDClasses(HINSTANCE hInstanse);
#pragma endregion


// Вызывается при первом запуске программы
void Init(HINSTANCE hInstanse) {
	RegisterWNDClasses(hInstanse);

}

void RegisterWNDClasses(HINSTANCE hInstanse) {
	HelloWindow::RegisterHelloWndClass(hInstanse);
	GameWindow::RegisterGameWndClass(hInstanse);


	WhiteFigure::RegisterWhiteFigureClass(hInstanse);
	BlackFigure::RegisterBlackFigureClass(hInstanse);


	StepRect::RegisterStepRectClass(hInstanse);
}