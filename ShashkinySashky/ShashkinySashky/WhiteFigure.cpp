#include "WhiteFigure.h"
#include "WindowElementIds.h"
#include "resource.h"


LRESULT CALLBACK WhiteFigureWindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
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
    return 0;
    }

    return DefWindowProc(hwnd, uMsg, wParam, lParam);
}


WhiteFigure* WhiteFigure::CreateWND(HINSTANCE hInstance, HWND parentWindow, int posX, int posY, int hMenu, int indexX, int indexY) {
    WhiteFigure* whiteFigure = new WhiteFigure();
    whiteFigure->type = WHITE_FIGURE;
    whiteFigure->posX = posX;
    whiteFigure->posY = posY;
    whiteFigure->wmId = hMenu;
    whiteFigure->IndexX = indexX;
    whiteFigure->IndexY = indexY;

    HBITMAP hbit;
    hbit = (HBITMAP)LoadImage(hInstance, MAKEINTRESOURCE(IDB_BITMAP4), IMAGE_BITMAP, 0, 0, 0);


    whiteFigure->WindowHwnd = CreateWindowEx(
        0,
        L"BUTTON",
        NULL,
        BS_BITMAP | WS_CHILD,
        posX, posY, 100, 100,
        parentWindow,
        (HMENU)hMenu,
        hInstance,
        NULL);

    SendMessage(whiteFigure->WindowHwnd, BM_SETIMAGE, IMAGE_BITMAP, (LPARAM)hbit);


    return whiteFigure;
}


void WhiteFigure::RegisterWhiteFigureClass(HINSTANCE hInstance) {

    WNDCLASS wc = { };

    wc.lpfnWndProc = WhiteFigureWindowProc;
    wc.hInstance = hInstance;
    wc.lpszClassName = WHITE_FIGURE_WINDOW_CLASS_NAME;

    RegisterClass(&wc);
}