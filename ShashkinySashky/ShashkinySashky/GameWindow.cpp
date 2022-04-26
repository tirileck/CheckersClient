#include "GameWindow.h"
#include "WindowElementIds.h"
#include "framework.h"


LRESULT CALLBACK GameWindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    static Figure* figure = nullptr;

    static StepRect* stepRect = nullptr;

    Figure* eatenFigure = nullptr;

    switch (uMsg)
    {
    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;

    case WM_COMMAND: {
        int wmId = LOWORD(wParam);      //Id окна, вызвавшее событие
        int wmEvent = HIWORD(wParam);       //Id события

        if (wmId >= 15000 && wmId < 15012) {
            canSteps->HideRects();
            // Клик по белой фишке
            figure = figures->GetFigure(wmId);
            if(figure->isShash)
                canSteps->CreateStepLogic(figures, figure, WHITESHASH, ME);
            else
                canSteps->CreateStepLogic(figures, figure, WHITEQUEEN, ME);
        }
        else if (wmId >= 15012 && wmId <= 15023) {
            canSteps->HideRects();
            // Клик по черной фишке
            figure = figures->GetFigure(wmId);
            if (figure->isShash)
                canSteps->CreateStepLogic(figures, figure, BLACKSHASH, ENEMY);
            else
                canSteps->CreateStepLogic(figures, figure, BLACKQUEEN, ENEMY);
        }
        else if (wmId >= 11000 && wmId < 11064) {
            // Сообщение от клика на квадрат возможности хода

            stepRect = canSteps->GetStepRect(wmId);

            // Хавальная фигура
            eatenFigure = figures->GetEatenFigure(figure->IndexX, figure->IndexY, stepRect->IndexX, stepRect->IndexY);
            if(eatenFigure != nullptr)
                figures->EatShah(eatenFigure);

            figures->MoveShash(figure->IndexX, figure->IndexY, stepRect->IndexX, stepRect->IndexY);
            canSteps->HideRects();
        }
        
    }
    case WM_PAINT:
    {
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hwnd, &ps);
        
        int widthRect = FIGURE_WIDTH;
        int heightRect = FIGURE_HEIGHT;
        int cols = 8;

        int currentWidth = 0;
        int currentHeight = 0;


        for (int i = 0; i < cols; i++) {
            for (int j = 0; j < cols; j++) {
                if (currentWidth == cols * widthRect) {
                    currentWidth = 0;
                    currentHeight += heightRect;
                }

                RECT rect;
                rect.left = currentWidth;
                rect.top = currentHeight;
                rect.bottom = currentHeight + heightRect;
                rect.right = currentWidth + widthRect;

                if(i % 2 == 0 && j % 2 == 0)
                    FillRect(hdc, &rect, CreateSolidBrush(LightColor));
                else if(i % 2 == 0 && j % 2 == 1)
                    FillRect(hdc, &rect, CreateSolidBrush(DarkColor));
                else if (i % 2 == 1 && j % 2 == 0)
                    FillRect(hdc, &rect, CreateSolidBrush(DarkColor));
                else if (i % 2 == 1 && j % 2 == 1)
                    FillRect(hdc, &rect, CreateSolidBrush(LightColor));

                currentWidth += widthRect;

            }
        }


        EndPaint(hwnd, &ps);
    }
    }

    return DefWindowProc(hwnd, uMsg, wParam, lParam);
}

GameWindow* GameWindow::CreateWND(HINSTANCE hInstance) {
    GameWindow* game = new GameWindow();

    // Создаем главное окно
    game->WindowHwnd = CreateWindowEx(
        0,                              // Optional window styles.
        GAME_WINDOW_CLASS_NAME,                     // Window class
        GAME_WINDOW_NAME,    // Window text
        WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX,            // Window style

        // Size and position
        CW_USEDEFAULT, CW_USEDEFAULT, 810, 835,

        NULL,       // Parent window    
        NULL,       // Menu
        hInstance,  // Instance handle
        NULL        // Additional application data
    );

    canSteps = CanStep::InitRects(hInstance, game->WindowHwnd);

    figures = GameFigures::InitFigure(hInstance, game->WindowHwnd);


    return game;
}


void GameWindow::StartGame(WHO firstPlayer) {
    if (firstPlayer == ME) {
        figures->EnableFigures(BLACK_FIGURE, false);
        figures->EnableFigures(WHITE_FIGURE, true);
    }
    else {
        figures->EnableFigures(BLACK_FIGURE, true);
        figures->EnableFigures(WHITE_FIGURE, false);
    }
    currentPlayer = firstPlayer;
    
}

void GameWindow::RegisterGameWndClass(HINSTANCE hInstance) {

    WNDCLASS wc = { };

    wc.lpfnWndProc = GameWindowProc;
    wc.hInstance = hInstance;
    wc.lpszClassName = GAME_WINDOW_CLASS_NAME;

    RegisterClass(&wc);
}
