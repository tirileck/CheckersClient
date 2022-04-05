#include "GameWindow.h"
#include "WindowElementIds.h"


LRESULT CALLBACK GameWindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch (uMsg)
    {
    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;

    case WM_COMMAND: {
        int wmId = LOWORD(wParam);      //Id окна, вызвавшее событие
        int wmEvent = HIWORD(wParam);       //Id события

        switch (wmId) {
       

        }
    }
    case WM_PAINT:
    {
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hwnd, &ps);
        //FillRect(hdc, &ps.rcPaint, (HBRUSH)(COLOR_WINDOW + 1));

        //RECT rect;
        //rect.left = 5;
        //rect.top = 5;
        //rect.bottom = 100;
        //rect.right = 100;
        //FillRect(hdc, &rect, CreateSolidBrush(LightColor));
        //FillRect(hdc, &ps.rcPaint, (HBRUSH)RGB(139, 69, 19));
        //FillRect(hdc, &rect, CreateSolidBrush(RGB(139, 69, 19)));
       
        int widthRect = 100;
        int heightRect = 100;
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
    return 0;
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


    return game;
}

void GameWindow::RegisterGameWndClass(HINSTANCE hInstance) {

    WNDCLASS wc = { };

    wc.lpfnWndProc = GameWindowProc;
    wc.hInstance = hInstance;
    wc.lpszClassName = GAME_WINDOW_CLASS_NAME;

    RegisterClass(&wc);
}