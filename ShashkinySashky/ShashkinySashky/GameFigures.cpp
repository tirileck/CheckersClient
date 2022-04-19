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
					gameFigures->figures[i][j] = WhiteFigure::CreateWND(hInstanse, parentHwnd, j * FIGURE_WIDTH, i * FIGURE_HEIGHT, gameFigures->CurrHMenu++);
					currFigure++;
				}
				else if (i % 2 == 1 && j % 2 == 0) {
					gameFigures->figures[i][j] = WhiteFigure::CreateWND(hInstanse, parentHwnd, j * FIGURE_WIDTH, i * FIGURE_HEIGHT, gameFigures->CurrHMenu++);
					currFigure++;
				} else{
					gameFigures->figures[i][j] = nullptr;
				}
			}
			else if (currFigure >= 12 && i >= 5) {
				if (i % 2 == 0 && j % 2 == 1) {
					gameFigures->figures[i][j] = BlackFigure::CreateWND(hInstanse, parentHwnd, j * FIGURE_WIDTH, i * FIGURE_HEIGHT, gameFigures->CurrHMenu++);
					currFigure++;
				}
				else if (i % 2 == 1 && j % 2 == 0) {
					gameFigures->figures[i][j] = BlackFigure::CreateWND(hInstanse, parentHwnd, j * FIGURE_WIDTH, i * FIGURE_HEIGHT, gameFigures->CurrHMenu++);
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


