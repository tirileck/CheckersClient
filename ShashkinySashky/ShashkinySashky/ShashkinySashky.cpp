#pragma once
#ifndef UNICODE
#define UNICODE
#endif 

#include <windows.h>
#include "framework.h"
#include "Initializer.h"
#include "Global.h"

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE, PWSTR pCmdLine, int nCmdShow)
{
    Init(hInstance);

    HelloWindow *helloWindow = HelloWindow::CreateWND(hInstance);
    GameWindow* gameWindow = GameWindow::CreateWND(hInstance);
    CanStep* canStep = CanStep::InitRects(hInstance, gameWindow->WindowHwnd);

    ShowWindow(gameWindow->WindowHwnd, SW_SHOW);
    fuguresGlobal = GameFigures::InitFigure(hInstance, gameWindow->WindowHwnd);

    fuguresGlobal->figures[2][1]->MoveBottomLeft();

    // Run the message loop.
    MSG msg = { };
    while (GetMessage(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return 0;
}
