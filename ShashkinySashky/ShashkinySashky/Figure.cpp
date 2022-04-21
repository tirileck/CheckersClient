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