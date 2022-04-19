#pragma once
#include "framework.h"

enum TypeOfClass{WHITE_FIGURE = 1, BLACK_FIGURE = 2};

class Figure
{
public:
	TypeOfClass type;
	int posX;
	int posY;
	int wmId;
	bool isShash = true;

	HWND WindowHwnd;					// Дескриптор созданного окна

	void Draw();

	void MovePosition(int x, int y) {
		SetWindowPos(WindowHwnd, HWND_TOP, x, y, 0, 0, SWP_NOSIZE);
	}

	void MoveBottomRight();
	void MoveBottomLeft();
	void MoveTopRight();
	void MoveTopLeft();
};

