#include "BlackFigure.h"
#include "WindowElementIds.h"
#include "resource.h"

LRESULT CALLBACK BlackFigureWindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
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
    }

    return DefWindowProc(hwnd, uMsg, wParam, lParam);
}


BlackFigure* BlackFigure::CreateWND(HINSTANCE hInstance, HWND parentWindow, int posX, int posY, int hMenu) {
    BlackFigure* blackFigure = new BlackFigure();
    blackFigure->type = BLACK_FIGURE;
    blackFigure->posX = posX;
    blackFigure->posY = posY;
    blackFigure->wmId = hMenu;
    
    HBITMAP hbit;
    hbit = (HBITMAP)LoadImage(hInstance, MAKEINTRESOURCE(IDB_BITMAP2), IMAGE_BITMAP, 0, 0, 0);


    blackFigure->WindowHwnd = CreateWindowEx(
        0,
        L"BUTTON",
        NULL,
        BS_BITMAP | WS_CHILD,
        posX, posY, 100, 100,
        parentWindow,
        (HMENU)hMenu,
        hInstance,
        NULL);

    SendMessage(blackFigure->WindowHwnd, BM_SETIMAGE, IMAGE_BITMAP, (LPARAM)hbit);


    return blackFigure;
}


void BlackFigure::RegisterBlackFigureClass(HINSTANCE hInstance) {

    WNDCLASS wc = { };

    wc.lpfnWndProc = BlackFigureWindowProc;
    wc.hInstance = hInstance;
    wc.lpszClassName = BLACK_FIGURE_WINDOW_CLASS_NAME;

    RegisterClass(&wc);
}