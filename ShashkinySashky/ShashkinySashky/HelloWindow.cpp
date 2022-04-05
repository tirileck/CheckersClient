#include "HelloWindow.h"
#include "WindowElementIds.h"


LRESULT CALLBACK HelloWindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch (uMsg)
    {
    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;

    case WM_COMMAND: {
        int wmId = LOWORD(wParam);      //Id ����, ��������� �������
        int wmEvent = HIWORD(wParam);       //Id �������

        switch (wmId) {
        case HelloWindow_Button: {
            MessageBox(hwnd, L"Click", 0, 0);       // ����� �� ����
        }

        }
    }
    case WM_PAINT:
    {
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hwnd, &ps);

        // All painting occurs here, between BeginPaint and EndPaint.
        FillRect(hdc, &ps.rcPaint, (HBRUSH)(COLOR_WINDOW + 1));
        EndPaint(hwnd, &ps);
    }
    return 0;
    }

    return DefWindowProc(hwnd, uMsg, wParam, lParam);
}

HelloWindow* HelloWindow::CreateWND(HINSTANCE hInstance) {
    HelloWindow* hello = new HelloWindow();
    
    // ������� ������� ����
    hello->WindowHwnd = CreateWindowEx(
        0,                              // Optional window styles.
        HELLO_WINDOW_CLASS_NAME,                     // Window class
        HELLO_WINDOW_NAME,    // Window text
        WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX,            // Window style

        // Size and position
        CW_USEDEFAULT, CW_USEDEFAULT, 380, 200,

        NULL,       // Parent window    
        NULL,       // Menu
        hInstance,  // Instance handle
        NULL        // Additional application data
    );

    // ������� �������� ��������
    hello->LabelHwnd = CreateWindowEx(
        0,
        L"STATIC",
        L"������� ���: ",
        WS_TABSTOP | WS_CHILD | WS_VISIBLE | SS_LEFT,
        20, 20, 150, 20,
        hello->WindowHwnd,
        (HMENU)HelloWindow_Label,
        hInstance,
        0
    );

    // ������� ������� ������
    hello->InputNameHwnd = CreateWindowEx(
        0,
        L"EDIT",
        L"",
        WS_TABSTOP | WS_BORDER | WS_CHILD | WS_VISIBLE | ES_LEFT,

        190, 20, 150, 20,
        hello->WindowHwnd,
        (HMENU)HelloWindow_Editor,
        hInstance,
        0
    );

    // ������� ������� ������
    hello->StartButtonHwnd = CreateWindowEx(
        0,
        L"BUTTON",
        L"������ ����!",
        WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,  // Styles 

        20, 80, 320, 50,
        hello->WindowHwnd,
        (HMENU)HelloWindow_Button,
        hInstance,
        0
    );

    return hello;
}

void HelloWindow::RegisterHelloWndClass(HINSTANCE hInstance) {

    WNDCLASS wc = { };

    wc.lpfnWndProc = HelloWindowProc;
    wc.hInstance = hInstance;
    wc.lpszClassName = HELLO_WINDOW_CLASS_NAME;

    RegisterClass(&wc);
}