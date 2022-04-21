#pragma once
#include "framework.h"

enum TypeOfClass{WHITE_FIGURE = 1, BLACK_FIGURE = 2};

class Figure
{
public:
	TypeOfClass type;
	int posX;
	int posY;
	int IndexX;
	int IndexY;
	int wmId;
	bool isShash = true;

	HWND WindowHwnd;					// ���������� ���������� ����

	void Draw();

	void MovePosition(int x, int y) {
		SetWindowPos(WindowHwnd, HWND_TOP, y, x, 0, 0, SWP_NOSIZE);
	}

	void MoveBottomRight();
	void MoveBottomLeft();
	void MoveTopRight();
	void MoveTopLeft();


	void HideFigure();
};

