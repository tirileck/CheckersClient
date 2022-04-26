#include "Figure.h"

void Figure::Draw() {
	ShowWindow(WindowHwnd, SW_SHOW);
}

void Figure::MoveBottomRight() {
	posX += FIGURE_HEIGHT;
	posY += FIGURE_WIDTH;
	IndexX++;
	IndexY++;
	MovePosition(posX, posY);
}
void Figure::MoveBottomLeft() {
	posX -= FIGURE_HEIGHT;
	posY += FIGURE_WIDTH;
	IndexX++;
	IndexY--;
	MovePosition(posX, posY);
}
void Figure::MoveTopRight() {
	posX += FIGURE_HEIGHT;
	posY -= FIGURE_WIDTH;
	IndexX--;
	IndexY++;
	MovePosition(posX, posY);
}
void Figure::MoveTopLeft() {
	posX -= FIGURE_HEIGHT;
	posY -= FIGURE_WIDTH;
	IndexX--;
	IndexY--;
	MovePosition(posX, posY);
}


void Figure::HideFigure() {
	ShowWindow(this->WindowHwnd, SW_HIDE);
}

void Figure::MakeQueen() {
	isShash = false;
	HBITMAP hbit;
	if (type == WHITE_FIGURE) {
		hbit = (HBITMAP)LoadImage(hInstance, MAKEINTRESOURCE(IDB_BITMAP3), IMAGE_BITMAP, 0, 0, 0);
		SendMessage(this->WindowHwnd, BM_SETIMAGE, IMAGE_BITMAP, (LPARAM)hbit);
	} else {

		hbit = (HBITMAP)LoadImage(hInstance, MAKEINTRESOURCE(IDB_BITMAP1), IMAGE_BITMAP, 0, 0, 0);
		SendMessage(this->WindowHwnd, BM_SETIMAGE, IMAGE_BITMAP, (LPARAM)hbit);
	}
}