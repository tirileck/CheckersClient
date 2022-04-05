#ifndef UNICODE
#define UNICODE
#endif 

#include <windows.h>
#include "framework.h"
#include "Initializer.h"

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE, PWSTR pCmdLine, int nCmdShow)
{
    Init(hInstance);

    HelloWindow *helloWindow = HelloWindow::CreateWND(hInstance);

    ShowWindow(helloWindow->WindowHwnd, SW_SHOW);

    // Run the message loop.
    MSG msg = { };
    while (GetMessage(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return 0;
}
