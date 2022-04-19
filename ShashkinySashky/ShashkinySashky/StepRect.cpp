#include "StepRect.h"
#include "WindowElementIds.h"
#include "resource.h"
#include "framework.h"


LRESULT CALLBACK StepRectWindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
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

StepRect* StepRect::CreateWND(HINSTANCE hInstance, HWND parentWindow, int posX, int posY, int hMenu) {
    StepRect* stepRect = new StepRect();

    stepRect->WindowHwnd = CreateWindowEx(
        0,
        L"BUTTON",
        NULL,
        WS_CHILD | BS_BITMAP,
        posX, posY, 100, 100,
        parentWindow,
        (HMENU)hMenu,
        hInstance,
        NULL);


    return stepRect;
}

void StepRect::DrawRect(HINSTANCE hInstance, drawColor color) {
    ShowWindow(this->WindowHwnd, SW_SHOW);
    if (color == RED) {
        HBITMAP hbit;
        hbit = (HBITMAP)LoadImage(hInstance, MAKEINTRESOURCE(IDB_BITMAP6), IMAGE_BITMAP, 0, 0, 0);
        SendMessage(this->WindowHwnd, BM_SETIMAGE, IMAGE_BITMAP, (LPARAM)hbit);
    }
    else if (color == GREEN) {
        HBITMAP hbit;
        hbit = (HBITMAP)LoadImage(hInstance, MAKEINTRESOURCE(IDB_BITMAP5), IMAGE_BITMAP, 0, 0, 0);
        SendMessage(this->WindowHwnd, BM_SETIMAGE, IMAGE_BITMAP, (LPARAM)hbit);
    }
}


void StepRect::RegisterStepRectClass(HINSTANCE hInstance) {

    WNDCLASS wc = { };

    wc.lpfnWndProc = StepRectWindowProc;
    wc.hInstance = hInstance;
    wc.lpszClassName = STEP_RECT_WINDOW_CLASS_NAME;

    RegisterClass(&wc);
}