#pragma once
#include "framework.h"
#include "WindowsHeader.h"

#pragma region Prototypes
void RegisterWNDClasses(HINSTANCE hInstanse);
#pragma endregion


// ���������� ��� ������ ������� ���������
void Init(HINSTANCE hInstanse) {
	RegisterWNDClasses(hInstanse);
}

void RegisterWNDClasses(HINSTANCE hInstanse) {
	HelloWindow::RegisterHelloWndClass(hInstanse);
}