#pragma once
//#include "Global.h"
#include "CanStep.h"
#include "WindowElementIds.h"
#include "resource.h"
#include "StepRect.h"
#include "WindowsHeader.h"


CanStep* CanStep::InitRects(HINSTANCE hInstanse, HWND parentHwnd) {
	CanStep* canStep = new CanStep();
	canStep->hInstace = hInstanse;
	for(int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++) {
			canStep->stepRects[i][j] = StepRect::CreateWND(hInstanse, parentHwnd, i * FIGURE_HEIGHT, j * FIGURE_WIDTH, canStep->CurrHMenu++, i, j);
		}

	return canStep;
}

StepRect* CanStep::GetStepRect(int hMenu) {
	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++)
			if (stepRects[i][j]->HMenu == hMenu)
				return stepRects[i][j];
	return nullptr;
}


void CanStep::CreateStepLogic(GameFigures* gameFigures, int figureX, int figureY, TYPEFIGURE type, WHO who, bool eaten, int fromX, int fromY, DIRECTION direction) {
	/*int figureX = figure->IndexX;
	int figureY = figure->IndexY;*/

	bool isLeftBorder = figureY < 1;
	bool isRightBorder = figureY > 6;
	bool isBottomBorder = figureX > 6;
	bool isTopBorder = figureX < 1;

	bool isLeftTwoBorder = figureY < 2;
	bool isRightTwoBorder = figureY > 5;
	bool isBottomTwoBorder = figureX > 5;
	bool isTopTwoBorder = figureX < 2;

	DRAWSTEPRECTCOLOW color = who == ME ? GREEN : RED;

	//bool eaten = false;

	switch (type)
	{
		case WHITESHASH:
			// Может ли есть
			if (!isLeftTwoBorder) {
				if (!isTopTwoBorder && gameFigures->figures[figureX-1][figureY-1] != nullptr && gameFigures->figures[figureX - 2][figureY - 2] == nullptr && gameFigures->figures[figureX - 1][figureY - 1]->type != WHITE_FIGURE) {
					// Движение в лево вверх на 2
					stepRects[figureX - 2][figureY - 2]->DrawRect(color);

					if (fromX != -1 && fromY != -1) {
						stepRects[fromX][fromY]->EnableRect(false);
						stepRects[figureX - 2][figureY - 2]->eatenFigures = *new std::vector<Figure*>(stepRects[figureX][figureY]->eatenFigures.size());
						std::copy(stepRects[figureX][figureY]->eatenFigures.begin(), stepRects[figureX][figureY]->eatenFigures.end(), stepRects[figureX - 2][figureY - 2]->eatenFigures.begin());
					}
					stepRects[figureX - 2][figureY - 2]->eatenFigures.push_back(gameFigures->figures[figureX - 1][figureY - 1]);

					if(fromX != figureX - 2 || fromY != figureY - 2)
						CreateStepLogic(gameFigures, figureX - 2, figureY - 2, type, who, true, figureX, figureY);
					eaten = true;
				}
				if (!isBottomTwoBorder && gameFigures->figures[figureX + 1][figureY - 1] != nullptr && gameFigures->figures[figureX + 2][figureY - 2] == nullptr && gameFigures->figures[figureX + 1][figureY - 1]->type != WHITE_FIGURE) {
					// Движение в лево вниз на 2
					stepRects[figureX + 2][figureY - 2]->DrawRect(color);

					if (fromX != -1 && fromY != -1) {
						stepRects[fromX][fromY]->EnableRect(false);
						stepRects[figureX + 2][figureY - 2]->eatenFigures = *new std::vector<Figure*>(stepRects[figureX][figureY]->eatenFigures.size());
						std::copy(stepRects[figureX][figureY]->eatenFigures.begin(), stepRects[figureX][figureY]->eatenFigures.end(), stepRects[figureX + 2][figureY - 2]->eatenFigures.begin());
					}
					stepRects[figureX + 2][figureY - 2]->eatenFigures.push_back(gameFigures->figures[figureX + 1][figureY - 1]);

					if (fromX != figureX + 2 || fromY != figureY - 2)
						CreateStepLogic(gameFigures, figureX + 2, figureY - 2, type, who, true, figureX, figureY);
					eaten = true;
				}

			}

			if (!isRightTwoBorder) {
				if (!isTopTwoBorder && gameFigures->figures[figureX - 1][figureY + 1] != nullptr && gameFigures->figures[figureX - 2][figureY + 2] == nullptr && gameFigures->figures[figureX - 1][figureY + 1]->type != WHITE_FIGURE) {
					// Движение в лево вверх на 2
					stepRects[figureX - 2][figureY + 2]->DrawRect(color);

					if (fromX != -1 && fromY != -1) {
						stepRects[fromX][fromY]->EnableRect(false);
						stepRects[figureX - 2][figureY + 2]->eatenFigures = *new std::vector<Figure*>(stepRects[figureX][figureY]->eatenFigures.size());
						std::copy(stepRects[figureX][figureY]->eatenFigures.begin(), stepRects[figureX][figureY]->eatenFigures.end(), stepRects[figureX - 2][figureY + 2]->eatenFigures.begin());
					}
					stepRects[figureX - 2][figureY + 2]->eatenFigures.push_back(gameFigures->figures[figureX - 1][figureY + 1]);

					if (fromX != figureX - 2 || fromY != figureY + 2)
						CreateStepLogic(gameFigures, figureX - 2, figureY + 2, type, who, true, figureX, figureY);
					eaten = true;
				}
				if (!isBottomTwoBorder && gameFigures->figures[figureX + 1][figureY + 1] != nullptr && gameFigures->figures[figureX + 2][figureY + 2] == nullptr && gameFigures->figures[figureX + 1][figureY + 1]->type != WHITE_FIGURE) {
					// Движение в лево вниз на 2
					stepRects[figureX + 2][figureY + 2]->DrawRect(color);

					if (fromX != -1 && fromY != -1) {
						stepRects[fromX][fromY]->EnableRect(false);
						stepRects[figureX + 2][figureY + 2]->eatenFigures = *new std::vector<Figure*>(stepRects[figureX][figureY]->eatenFigures.size());
						std::copy(stepRects[figureX][figureY]->eatenFigures.begin(), stepRects[figureX][figureY]->eatenFigures.end(), stepRects[figureX + 2][figureY + 2]->eatenFigures.begin());
					}
					stepRects[figureX + 2][figureY + 2]->eatenFigures.push_back(gameFigures->figures[figureX + 1][figureY + 1]);

					if (fromX != figureX + 2 || fromY != figureY + 2)
						CreateStepLogic(gameFigures, figureX + 2, figureY + 2, type, who, true, figureX, figureY);
					eaten = true;
				}

			}


			// Если не кушаем
			if (!eaten) {
				if (!isLeftBorder) {
					if (!isBottomBorder && gameFigures->figures[figureX + 1][figureY - 1] == nullptr) {
						// Движение в лево вниз на 1
						stepRects[figureX + 1][figureY - 1]->DrawRect(color);
					}

				}

				if (!isRightBorder) {
					if (!isBottomBorder && gameFigures->figures[figureX + 1][figureY + 1] == nullptr) {
						// Движение в право вниз на 2
						stepRects[figureX + 1][figureY + 1]->DrawRect(color);
					}

				}
			}

			break;
		case BLACKSHASH:
			// Может ли есть
			if (!isLeftTwoBorder) {
				if (!isTopTwoBorder && gameFigures->figures[figureX - 1][figureY - 1] != nullptr && gameFigures->figures[figureX - 2][figureY - 2] == nullptr && gameFigures->figures[figureX - 1][figureY - 1]->type != BLACK_FIGURE) {
					// Движение в лево вверх на 2
					stepRects[figureX - 2][figureY - 2]->DrawRect(color);

					if (fromX != -1 && fromY != -1) {
						stepRects[fromX][fromY]->EnableRect(false);
						stepRects[figureX - 2][figureY - 2]->eatenFigures = *new std::vector<Figure*>(stepRects[figureX][figureY]->eatenFigures.size());
						std::copy(stepRects[figureX][figureY]->eatenFigures.begin(), stepRects[figureX][figureY]->eatenFigures.end(), stepRects[figureX - 2][figureY - 2]->eatenFigures.begin());
					}
					stepRects[figureX - 2][figureY - 2]->eatenFigures.push_back(gameFigures->figures[figureX - 1][figureY - 1]);

					if (fromX != figureX - 2 || fromY != figureY - 2)
						CreateStepLogic(gameFigures, figureX - 2, figureY - 2, type, who, true, figureX, figureY);
					eaten = true;
				}
				if (!isBottomTwoBorder && gameFigures->figures[figureX + 1][figureY - 1] != nullptr && gameFigures->figures[figureX + 2][figureY - 2] == nullptr && gameFigures->figures[figureX + 1][figureY - 1]->type != BLACK_FIGURE) {
					// Движение в лево вниз на 2
					stepRects[figureX + 2][figureY - 2]->DrawRect(color);

					if (fromX != -1 && fromY != -1) {
						stepRects[fromX][fromY]->EnableRect(false);
						stepRects[figureX + 2][figureY - 2]->eatenFigures = *new std::vector<Figure*>(stepRects[figureX][figureY]->eatenFigures.size());
						std::copy(stepRects[figureX][figureY]->eatenFigures.begin(), stepRects[figureX][figureY]->eatenFigures.end(), stepRects[figureX + 2][figureY - 2]->eatenFigures.begin());
					}
					stepRects[figureX + 2][figureY - 2]->eatenFigures.push_back(gameFigures->figures[figureX + 1][figureY - 1]);

					if (fromX != figureX + 2 || fromY != figureY - 2)
						CreateStepLogic(gameFigures, figureX + 2, figureY - 2, type, who, true, figureX, figureY);
					eaten = true;
				}

			}

			if (!isRightTwoBorder) {
				if (!isTopTwoBorder && gameFigures->figures[figureX - 1][figureY + 1] != nullptr && gameFigures->figures[figureX - 2][figureY + 2] == nullptr && gameFigures->figures[figureX - 1][figureY + 1]->type != BLACK_FIGURE) {
					// Движение в право вверх на 2
					stepRects[figureX - 2][figureY + 2]->DrawRect(color);

					if (fromX != -1 && fromY != -1) {
						stepRects[fromX][fromY]->EnableRect(false);
						stepRects[figureX - 2][figureY + 2]->eatenFigures = *new std::vector<Figure*>(stepRects[figureX][figureY]->eatenFigures.size());
						std::copy(stepRects[figureX][figureY]->eatenFigures.begin(), stepRects[figureX][figureY]->eatenFigures.end(), stepRects[figureX - 2][figureY + 2]->eatenFigures.begin());
					}
					stepRects[figureX - 2][figureY + 2]->eatenFigures.push_back(gameFigures->figures[figureX - 1][figureY + 1]);

					if (fromX != figureX - 2 || fromY != figureY + 2)
						CreateStepLogic(gameFigures, figureX - 2, figureY + 2, type, who, true, figureX, figureY);
					eaten = true;
				}
				if (!isBottomTwoBorder && gameFigures->figures[figureX + 1][figureY + 1] != nullptr && gameFigures->figures[figureX + 2][figureY + 2] == nullptr && gameFigures->figures[figureX + 1][figureY + 1]->type != BLACK_FIGURE) {
					// Движение в право вниз на 2
					stepRects[figureX + 2][figureY + 2]->DrawRect(color);

					if (fromX != -1 && fromY != -1) {
						stepRects[fromX][fromY]->EnableRect(false);
						stepRects[figureX + 2][figureY + 2]->eatenFigures = *new std::vector<Figure*>(stepRects[figureX][figureY]->eatenFigures.size());
						std::copy(stepRects[figureX][figureY]->eatenFigures.begin(), stepRects[figureX][figureY]->eatenFigures.end(), stepRects[figureX + 2][figureY + 2]->eatenFigures.begin());
					}
					stepRects[figureX + 2][figureY + 2]->eatenFigures.push_back(gameFigures->figures[figureX + 1][figureY + 1]);

					if (fromX != figureX + 2 || fromY != figureY + 2)
						CreateStepLogic(gameFigures, figureX + 2, figureY + 2, type, who, true, figureX, figureY);
					eaten = true;
				}

			}


			// Если не кушаем
			if (!eaten) {
				if (!isLeftBorder) {
					if (!isTopBorder && gameFigures->figures[figureX - 1][figureY - 1] == nullptr) {
						// Движение в лево вверх на 1
						stepRects[figureX - 1][figureY - 1]->DrawRect(color);
					}

				}

				if (!isRightBorder) {
					if (!isTopBorder && gameFigures->figures[figureX - 1][figureY + 1] == nullptr) {
						// Движение в право вверх на 1
						stepRects[figureX +-1][figureY + 1]->DrawRect(color);
					}

				}
			}
			break;
		case WHITEQUEEN:
			// Белый королев
			if (!isLeftTwoBorder) {
				if (!isTopTwoBorder && gameFigures->figures[figureX - 1][figureY - 1] != nullptr && gameFigures->figures[figureX - 2][figureY - 2] == nullptr && gameFigures->figures[figureX - 1][figureY - 1]->type != WHITE_FIGURE && (direction ==NOTHING || direction == LEFTUP )) {
					// Движение в лево вверх на 2
					stepRects[figureX - 2][figureY - 2]->DrawRect(color);

					if (fromX != -1 && fromY != -1) {
						stepRects[fromX][fromY]->EnableRect(false);
						stepRects[figureX - 2][figureY - 2]->eatenFigures = *new std::vector<Figure*>(stepRects[figureX][figureY]->eatenFigures.size());
						std::copy(stepRects[figureX][figureY]->eatenFigures.begin(), stepRects[figureX][figureY]->eatenFigures.end(), stepRects[figureX - 2][figureY - 2]->eatenFigures.begin());
					}
					stepRects[figureX - 2][figureY - 2]->eatenFigures.push_back(gameFigures->figures[figureX - 1][figureY - 1]);

					if (fromX != figureX - 2 || fromY != figureY - 2)
						CreateStepLogic(gameFigures, figureX - 2, figureY - 2, type, who, true, figureX, figureY);
					eaten = true;
				}
				if (!isBottomTwoBorder && gameFigures->figures[figureX + 1][figureY - 1] != nullptr && gameFigures->figures[figureX + 2][figureY - 2] == nullptr && gameFigures->figures[figureX + 1][figureY - 1]->type != WHITE_FIGURE && (direction == NOTHING || direction == LEFTDOWN)) {
					// Движение в лево вниз на 2
					stepRects[figureX + 2][figureY - 2]->DrawRect(color);

					if (fromX != -1 && fromY != -1) {
						stepRects[fromX][fromY]->EnableRect(false);
						stepRects[figureX + 2][figureY - 2]->eatenFigures = *new std::vector<Figure*>(stepRects[figureX][figureY]->eatenFigures.size());
						std::copy(stepRects[figureX][figureY]->eatenFigures.begin(), stepRects[figureX][figureY]->eatenFigures.end(), stepRects[figureX + 2][figureY - 2]->eatenFigures.begin());
					}
					stepRects[figureX + 2][figureY - 2]->eatenFigures.push_back(gameFigures->figures[figureX + 1][figureY - 1]);

					if (fromX != figureX + 2 || fromY != figureY - 2)
						CreateStepLogic(gameFigures, figureX + 2, figureY - 2, type, who, true, figureX, figureY);
					eaten = true;
				}

			}

			if (!isRightTwoBorder) {
				if (!isTopTwoBorder && gameFigures->figures[figureX - 1][figureY + 1] != nullptr && gameFigures->figures[figureX - 2][figureY + 2] == nullptr && gameFigures->figures[figureX - 1][figureY + 1]->type != WHITE_FIGURE && (direction == NOTHING || direction == RIGHTUP)) {
					// Движение в право вверх на 2
					stepRects[figureX - 2][figureY + 2]->DrawRect(color);

					if (fromX != -1 && fromY != -1) {
						stepRects[fromX][fromY]->EnableRect(false);
						stepRects[figureX - 2][figureY + 2]->eatenFigures = *new std::vector<Figure*>(stepRects[figureX][figureY]->eatenFigures.size());
						std::copy(stepRects[figureX][figureY]->eatenFigures.begin(), stepRects[figureX][figureY]->eatenFigures.end(), stepRects[figureX - 2][figureY + 2]->eatenFigures.begin());
					}
					stepRects[figureX - 2][figureY + 2]->eatenFigures.push_back(gameFigures->figures[figureX - 1][figureY + 1]);

					if (fromX != figureX - 2 || fromY != figureY + 2)
						CreateStepLogic(gameFigures, figureX - 2, figureY + 2, type, who, true, figureX, figureY);
					eaten = true;
				}
				if (!isBottomTwoBorder && gameFigures->figures[figureX + 1][figureY + 1] != nullptr && gameFigures->figures[figureX + 2][figureY + 2] == nullptr && gameFigures->figures[figureX + 1][figureY + 1]->type != WHITE_FIGURE && (direction == NOTHING || direction == RIGHTDOWN)) {
					// Движение в право вниз на 2
					stepRects[figureX + 2][figureY + 2]->DrawRect(color);

					if (fromX != -1 && fromY != -1) {
						stepRects[fromX][fromY]->EnableRect(false);
						stepRects[figureX + 2][figureY + 2]->eatenFigures = *new std::vector<Figure*>(stepRects[figureX][figureY]->eatenFigures.size());
						std::copy(stepRects[figureX][figureY]->eatenFigures.begin(), stepRects[figureX][figureY]->eatenFigures.end(), stepRects[figureX + 2][figureY + 2]->eatenFigures.begin());
					}
					stepRects[figureX + 2][figureY + 2]->eatenFigures.push_back(gameFigures->figures[figureX + 1][figureY + 1]);

					if (fromX != figureX + 2 || fromY != figureY + 2)
						CreateStepLogic(gameFigures, figureX + 2, figureY + 2, type, who, true, figureX, figureY);
					eaten = true;
				}

			}


			// Если не кушаем
			if (!eaten) {
				if (!isLeftBorder) {
					if (!isBottomBorder && gameFigures->figures[figureX + 1][figureY - 1] == nullptr) {
						// Движение в лево вниз на 1

						if (fromX != -1 && fromY != -1) {
							//stepRects[fromX][fromY]->EnableRect(false);
							stepRects[figureX + 1][figureY -1]->eatenFigures = *new std::vector<Figure*>(stepRects[figureX][figureY]->eatenFigures.size());
							std::copy(stepRects[figureX][figureY]->eatenFigures.begin(), stepRects[figureX][figureY]->eatenFigures.end(), stepRects[figureX + 1][figureY - 1]->eatenFigures.begin());
						}

						if (direction == NOTHING || (fromX == figureX - 1 && fromY == figureY + 1)) {
							stepRects[figureX + 1][figureY - 1]->DrawRect(color);
							CreateStepLogic(gameFigures, figureX + 1, figureY - 1, type, who, false, figureX, figureY, LEFTDOWN);
						}
					}
					if (!isTopBorder && gameFigures->figures[figureX - 1][figureY - 1] == nullptr) {
						// Движение в лево вверх на 1
						if (fromX != -1 && fromY != -1) {
							//stepRects[fromX][fromY]->EnableRect(false);
							stepRects[figureX - 1][figureY - 1]->eatenFigures = *new std::vector<Figure*>(stepRects[figureX][figureY]->eatenFigures.size());
							std::copy(stepRects[figureX][figureY]->eatenFigures.begin(), stepRects[figureX][figureY]->eatenFigures.end(), stepRects[figureX - 1][figureY - 1]->eatenFigures.begin());
						}

						if (direction == NOTHING || (fromX == figureX + 1 && fromY == figureY + 1)) {
							stepRects[figureX - 1][figureY - 1]->DrawRect(color);
							CreateStepLogic(gameFigures, figureX - 1, figureY - 1, type, who, false, figureX, figureY, LEFTUP);
						}
					}

				}

				if (!isRightBorder) {
					if (!isBottomBorder && gameFigures->figures[figureX + 1][figureY + 1] == nullptr) {
						// Движение в право вниз на 1

						if (fromX != -1 && fromY != -1) {
							//stepRects[fromX][fromY]->EnableRect(false);
							stepRects[figureX + 1][figureY + 1]->eatenFigures = *new std::vector<Figure*>(stepRects[figureX][figureY]->eatenFigures.size());
							std::copy(stepRects[figureX][figureY]->eatenFigures.begin(), stepRects[figureX][figureY]->eatenFigures.end(), stepRects[figureX + 1][figureY + 1]->eatenFigures.begin());
						}

						if (direction == NOTHING || (fromX == figureX - 1 && fromY == figureY - 1)) {
							stepRects[figureX + 1][figureY + 1]->DrawRect(color);
							CreateStepLogic(gameFigures, figureX + 1, figureY + 1, type, who, false, figureX, figureY, RIGHTDOWN);
						}
					}
					if (!isTopBorder && gameFigures->figures[figureX - 1][figureY + 1] == nullptr) {
						// Движение в право вверх на 1

						if (fromX != -1 && fromY != -1) {
							//stepRects[fromX][fromY]->EnableRect(false);
							stepRects[figureX - 1][figureY + 1]->eatenFigures = *new std::vector<Figure*>(stepRects[figureX][figureY]->eatenFigures.size());
							std::copy(stepRects[figureX][figureY]->eatenFigures.begin(), stepRects[figureX][figureY]->eatenFigures.end(), stepRects[figureX - 1][figureY + 1]->eatenFigures.begin());
						}

						if (direction == NOTHING || (fromX == figureX + 1 && fromY == figureY - 1)) {
							stepRects[figureX -1][figureY + 1]->DrawRect(color);
							CreateStepLogic(gameFigures, figureX - 1, figureY + 1, type, who, false, figureX, figureY, RIGHTUP);
						}
					}

				}
			}


			break;
		case BLACKQUEEN:
			// Черный королев

			if (!isLeftTwoBorder) {
				if (!isTopTwoBorder && gameFigures->figures[figureX - 1][figureY - 1] != nullptr && gameFigures->figures[figureX - 2][figureY - 2] == nullptr && gameFigures->figures[figureX - 1][figureY - 1]->type != BLACK_FIGURE && (direction == NOTHING || direction == LEFTUP)) {
					// Движение в лево вверх на 2
					stepRects[figureX - 2][figureY - 2]->DrawRect(color);

					if (fromX != -1 && fromY != -1) {
						stepRects[fromX][fromY]->EnableRect(false);
						stepRects[figureX - 2][figureY - 2]->eatenFigures = *new std::vector<Figure*>(stepRects[figureX][figureY]->eatenFigures.size());
						std::copy(stepRects[figureX][figureY]->eatenFigures.begin(), stepRects[figureX][figureY]->eatenFigures.end(), stepRects[figureX - 2][figureY - 2]->eatenFigures.begin());
					}
					stepRects[figureX - 2][figureY - 2]->eatenFigures.push_back(gameFigures->figures[figureX - 1][figureY - 1]);

					if (fromX != figureX - 2 || fromY != figureY - 2)
						CreateStepLogic(gameFigures, figureX - 2, figureY - 2, type, who, true, figureX, figureY);
					eaten = true;
				}
				if (!isBottomTwoBorder && gameFigures->figures[figureX + 1][figureY - 1] != nullptr && gameFigures->figures[figureX + 2][figureY - 2] == nullptr && gameFigures->figures[figureX + 1][figureY - 1]->type != BLACK_FIGURE && (direction == NOTHING || direction == LEFTDOWN)) {
					// Движение в лево вниз на 2
					stepRects[figureX + 2][figureY - 2]->DrawRect(color);

					if (fromX != -1 && fromY != -1) {
						stepRects[fromX][fromY]->EnableRect(false);
						stepRects[figureX + 2][figureY - 2]->eatenFigures = *new std::vector<Figure*>(stepRects[figureX][figureY]->eatenFigures.size());
						std::copy(stepRects[figureX][figureY]->eatenFigures.begin(), stepRects[figureX][figureY]->eatenFigures.end(), stepRects[figureX + 2][figureY - 2]->eatenFigures.begin());
					}
					stepRects[figureX + 2][figureY - 2]->eatenFigures.push_back(gameFigures->figures[figureX + 1][figureY - 1]);

					if (fromX != figureX + 2 || fromY != figureY - 2)
						CreateStepLogic(gameFigures, figureX + 2, figureY - 2, type, who, true, figureX, figureY);
					eaten = true;
				}

			}

			if (!isRightTwoBorder) {
				if (!isTopTwoBorder && gameFigures->figures[figureX - 1][figureY + 1] != nullptr && gameFigures->figures[figureX - 2][figureY + 2] == nullptr && gameFigures->figures[figureX - 1][figureY + 1]->type != BLACK_FIGURE && (direction == NOTHING || direction == RIGHTUP)) {
					// Движение в право вверх на 2
					stepRects[figureX - 2][figureY + 2]->DrawRect(color);

					if (fromX != -1 && fromY != -1) {
						stepRects[fromX][fromY]->EnableRect(false);
						stepRects[figureX - 2][figureY + 2]->eatenFigures = *new std::vector<Figure*>(stepRects[figureX][figureY]->eatenFigures.size());
						std::copy(stepRects[figureX][figureY]->eatenFigures.begin(), stepRects[figureX][figureY]->eatenFigures.end(), stepRects[figureX - 2][figureY + 2]->eatenFigures.begin());
					}
					stepRects[figureX - 2][figureY + 2]->eatenFigures.push_back(gameFigures->figures[figureX - 1][figureY + 1]);

					if (fromX != figureX - 2 || fromY != figureY + 2)
						CreateStepLogic(gameFigures, figureX - 2, figureY + 2, type, who, true, figureX, figureY);
					eaten = true;
				}
				if (!isBottomTwoBorder && gameFigures->figures[figureX + 1][figureY + 1] != nullptr && gameFigures->figures[figureX + 2][figureY + 2] == nullptr && gameFigures->figures[figureX + 1][figureY + 1]->type != BLACK_FIGURE && (direction == NOTHING || direction == RIGHTDOWN)) {
					// Движение в право вниз на 2
					stepRects[figureX + 2][figureY + 2]->DrawRect(color);

					if (fromX != -1 && fromY != -1) {
						stepRects[fromX][fromY]->EnableRect(false);
						stepRects[figureX + 2][figureY + 2]->eatenFigures = *new std::vector<Figure*>(stepRects[figureX][figureY]->eatenFigures.size());
						std::copy(stepRects[figureX][figureY]->eatenFigures.begin(), stepRects[figureX][figureY]->eatenFigures.end(), stepRects[figureX + 2][figureY + 2]->eatenFigures.begin());
					}
					stepRects[figureX + 2][figureY + 2]->eatenFigures.push_back(gameFigures->figures[figureX + 1][figureY + 1]);

					if (fromX != figureX + 2 || fromY != figureY + 2)
						CreateStepLogic(gameFigures, figureX + 2, figureY + 2, type, who, true, figureX, figureY);
					eaten = true;
				}

			}


			// Если не кушаем
			if (!eaten) {
				if (!isLeftBorder) {
					if (!isTopBorder && gameFigures->figures[figureX - 1][figureY - 1] == nullptr) {
						// Движение в лево вверх на 1
						if (fromX != -1 && fromY != -1) {
							//stepRects[fromX][fromY]->EnableRect(false);
							stepRects[figureX - 1][figureY - 1]->eatenFigures = *new std::vector<Figure*>(stepRects[figureX][figureY]->eatenFigures.size());
							std::copy(stepRects[figureX][figureY]->eatenFigures.begin(), stepRects[figureX][figureY]->eatenFigures.end(), stepRects[figureX - 1][figureY - 1]->eatenFigures.begin());
						}

						if (direction == NOTHING || (fromX == figureX + 1 && fromY == figureY + 1)) {
							stepRects[figureX - 1][figureY - 1]->DrawRect(color);
							CreateStepLogic(gameFigures, figureX - 1, figureY - 1, type, who, false, figureX, figureY, LEFTUP);
						}
					}
					if (!isBottomBorder && gameFigures->figures[figureX + 1][figureY - 1] == nullptr) {
						// Движение в лево вниз на 1

						if (fromX != -1 && fromY != -1) {
							//stepRects[fromX][fromY]->EnableRect(false);
							stepRects[figureX + 1][figureY - 1]->eatenFigures = *new std::vector<Figure*>(stepRects[figureX][figureY]->eatenFigures.size());
							std::copy(stepRects[figureX][figureY]->eatenFigures.begin(), stepRects[figureX][figureY]->eatenFigures.end(), stepRects[figureX + 1][figureY - 1]->eatenFigures.begin());
						}

						if (direction == NOTHING || (fromX == figureX - 1 && fromY == figureY + 1)) {
							stepRects[figureX + 1][figureY - 1]->DrawRect(color);
							CreateStepLogic(gameFigures, figureX + 1, figureY - 1, type, who, false, figureX, figureY, LEFTDOWN);
						}
					}

				}

				if (!isRightBorder) {
					if (!isTopBorder && gameFigures->figures[figureX - 1][figureY + 1] == nullptr) {
						// Движение в право вверх на 1

						if (fromX != -1 && fromY != -1) {
							//stepRects[fromX][fromY]->EnableRect(false);
							stepRects[figureX - 1][figureY + 1]->eatenFigures = *new std::vector<Figure*>(stepRects[figureX][figureY]->eatenFigures.size());
							std::copy(stepRects[figureX][figureY]->eatenFigures.begin(), stepRects[figureX][figureY]->eatenFigures.end(), stepRects[figureX - 1][figureY + 1]->eatenFigures.begin());
						}

						if (direction == NOTHING || (fromX == figureX + 1 && fromY == figureY - 1)) {
							stepRects[figureX - 1][figureY + 1]->DrawRect(color);
							CreateStepLogic(gameFigures, figureX - 1, figureY + 1, type, who, false, figureX, figureY, RIGHTDOWN);
						}
					}
					if (!isBottomBorder && gameFigures->figures[figureX + 1][figureY + 1] == nullptr) {
						// Движение в право вниз на 1

						if (fromX != -1 && fromY != -1) {
							//stepRects[fromX][fromY]->EnableRect(false);
							stepRects[figureX + 1][figureY + 1]->eatenFigures = *new std::vector<Figure*>(stepRects[figureX][figureY]->eatenFigures.size());
							std::copy(stepRects[figureX][figureY]->eatenFigures.begin(), stepRects[figureX][figureY]->eatenFigures.end(), stepRects[figureX + 1][figureY + 1]->eatenFigures.begin());
						}

						if (direction == NOTHING || (fromX == figureX - 1 && fromY == figureY - 1)) {
							stepRects[figureX + 1][figureY + 1]->DrawRect(color);
							CreateStepLogic(gameFigures, figureX + 1, figureY + 1, type, who, false, figureX, figureY, RIGHTDOWN);
						}
					}

				}
			}






			break;
		default:
			break;
	}
}

void CanStep::ClearEatenFiguresFromRects() {
	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++)
			stepRects[i][j]->eatenFigures.clear();
		
}

void CanStep::EnableRects(bool enable) {
	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++)
			stepRects[i][j]->EnableRect(enable);

}