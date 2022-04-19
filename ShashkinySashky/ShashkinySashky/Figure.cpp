#include "Figure.h"

void Figure::Draw() {
	ShowWindow(WindowHwnd, SW_SHOW);
}

void Figure::MoveBottomRight() {
	posX += 100;
	posY += 100;
	MovePosition(posX, posY);
}
void Figure::MoveBottomLeft() {
	posX -= 100;
	posY += 100;
	MovePosition(posX, posY);
}
void Figure::MoveTopRight() {
	posX += 100;
	posY -= 100;
	MovePosition(posX, posY);
}
void Figure::MoveTopLeft() {
	posX -= 100;
	posY -= 100;
	MovePosition(posX, posY);
}