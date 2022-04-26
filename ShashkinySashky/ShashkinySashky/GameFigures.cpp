#pragma once
#include "GameFigures.h"
#include "WhiteFigure.h"
#include "BlackFigure.h"

GameFigures* GameFigures::InitFigure(HINSTANCE hInstanse, HWND parentHwnd) {
	GameFigures* gameFigures = new GameFigures();
	
	int currFigure = 0;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (currFigure < 12 && i >= 0 && i <= 2 ) {
				if (i % 2 == 0 && j% 2 == 1) {
					gameFigures->figures[i][j] = WhiteFigure::CreateWND(hInstanse, parentHwnd, j * FIGURE_WIDTH, i * FIGURE_HEIGHT, gameFigures->CurrHMenu++, i, j);
					EnableWindow(gameFigures->figures[i][j]->WindowHwnd, false);
					currFigure++;
				}
				else if (i % 2 == 1 && j % 2 == 0) {
					gameFigures->figures[i][j] = WhiteFigure::CreateWND(hInstanse, parentHwnd, j * FIGURE_WIDTH, i * FIGURE_HEIGHT, gameFigures->CurrHMenu++, i, j);
					EnableWindow(gameFigures->figures[i][j]->WindowHwnd, false);
					currFigure++;
				} else{
					gameFigures->figures[i][j] = nullptr;
				}
			}
			else if (currFigure >= 12 && i >= 5) {
				if (i % 2 == 0 && j % 2 == 1) {
					gameFigures->figures[i][j] = BlackFigure::CreateWND(hInstanse, parentHwnd, j * FIGURE_WIDTH, i * FIGURE_HEIGHT, gameFigures->CurrHMenu++, i, j);
					EnableWindow(gameFigures->figures[i][j]->WindowHwnd, false);
					currFigure++;
				}
				else if (i % 2 == 1 && j % 2 == 0) {
					gameFigures->figures[i][j] = BlackFigure::CreateWND(hInstanse, parentHwnd, j * FIGURE_WIDTH, i * FIGURE_HEIGHT, gameFigures->CurrHMenu++, i, j);
					EnableWindow(gameFigures->figures[i][j]->WindowHwnd, false);
					currFigure++;
				}
				else {
					gameFigures->figures[i][j] = nullptr;
				}
			}
			else {
				gameFigures->figures[i][j] = nullptr;
			}
		}
	}
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (gameFigures->figures[i][j] != nullptr)
				gameFigures->figures[i][j]->Draw();
		}
	}
	
	return gameFigures;
}


void GameFigures::MoveShash(int oldX, int oldY, int newX, int newY) {
	figures[newX][newY] = figures[oldX][oldY];
	figures[oldX][oldY] = nullptr;
	
	figures[newX][newY]->MovePosition(newX * FIGURE_HEIGHT, newY * FIGURE_WIDTH);
	figures[newX][newY]->IndexX = newX;
	figures[newX][newY]->IndexY = newY;

}

Figure* GameFigures::GetFigure(int hMenu) {
	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++)
			if (figures[i][j] != nullptr && figures[i][j]->wmId == hMenu)
				return figures[i][j];
	return nullptr;
}

void GameFigures::EatShah(Figure* eaten) {
	eaten->HideFigure();
	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++)
			if (figures[i][j] == eaten) {
				figures[i][j] = nullptr;
				return;
			}
}

Figure* GameFigures::GetEatenFigure(int oldX, int oldY, int newX, int newY) {
	if (oldX - 2 == newX && oldY - 2 == newY) {
		return figures[oldX - 1][oldY - 1];
	} else if (oldX - 2 == newX && oldY + 2 == newY) {
		return figures[oldX - 1][oldY + 1];
	}
	else if(oldX + 2 == newX && oldY - 2 == newY) {
		return figures[oldX + 1][oldY - 1];
	}
	else if(oldX + 2 == newX && oldY + 2 == newY) {
		return figures[oldX + 1][oldY + 1];
	}
	return nullptr;
}

void GameFigures::EnableFigures(TypeOfClass typeOfFigure, bool enable) {
	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++)
			if (figures[i][j] != nullptr && figures[i][j]->type == typeOfFigure)
				EnableWindow(figures[i][j]->WindowHwnd, enable);
}
