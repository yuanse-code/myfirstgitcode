#define _CRT_SECURE_NO_WARNINGS 1

#include <Windows.h>
#include <tchar.h>
#include <strsafe.h>
#include "resource.h"

// 函数声明
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

// WinMain 函数
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    // 定义窗口类
    WNDCLASSEX wndclass;
    TCHAR szAppName[] = TEXT("喜羊羊");    // 窗口类名; 标题"喜羊羊"
    HWND hwnd;
    MSG msg;

    wndclass.cbSize = sizeof(WNDCLASSEX);
    wndclass.style = CS_HREDRAW | CS_VREDRAW;
    wndclass.lpfnWndProc = WindowProc;
    wndclass.cbClsExtra = 0;
    wndclass.cbWndExtra = 0;
    wndclass.hInstance = hInstance;
    wndclass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);
    wndclass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
    wndclass.lpszMenuName = NULL;
    wndclass.lpszClassName = szAppName;
    wndclass.hIconSm = NULL;
    RegisterClassEx(&wndclass);

    hwnd = CreateWindowEx(0, szAppName, szAppName, WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, CW_USEDEFAULT, 300, 300, NULL, NULL, hInstance, NULL);  //在此修改窗口尺寸

    ShowWindow(hwnd, nCmdShow);
    UpdateWindow(hwnd);

    while (GetMessage(&msg, NULL, 0, 0) != 0)
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return msg.wParam;
}

// 控件结构体定义
struct { int m_nStyle; PTSTR m_pText; }Buttons[] =
{
    BS_PUSHBUTTON | BS_NOTIFY | WS_TABSTOP,                 (PTSTR)TEXT("普通按钮"), // 
    BS_ICON | BS_NOTIFY | WS_TABSTOP,                       (PTSTR)TEXT("图标按钮"), // BS_ICON 图标
    BS_BITMAP | BS_NOTIFY | WS_TABSTOP,                     (PTSTR)TEXT("位图按钮"), // BS_BITMAP 位图
};

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    static HWND hwndButton[3];                // 子窗口控件句柄数组
    int arrPos[3] = { 5, 60, 130 };            // 各控件的y向位置
    LPDRAWITEMSTRUCT lpDIS;

    switch (uMsg)
    {
    case WM_CREATE:
        // 创建3个子窗口控件
        hwndButton[0] = CreateWindowEx(0, TEXT("Button"), Buttons[0].m_pText,
            WS_CHILD | WS_VISIBLE | Buttons[0].m_nStyle, 60, arrPos[0],         // x坐标
            150, 45, hwnd, (HMENU)(1000 + 0),                                   // 宽 和 高
            ((LPCREATESTRUCT)lParam)->hInstance, NULL);

        hwndButton[1] = CreateWindowEx(0, TEXT("Button"), Buttons[1].m_pText,
            WS_CHILD | WS_VISIBLE | Buttons[1].m_nStyle, 110, arrPos[1],
            50, 50, hwnd, (HMENU)(1000 + 1),
            ((LPCREATESTRUCT)lParam)->hInstance, NULL);

        hwndButton[2] = CreateWindowEx(0, TEXT("Button"), Buttons[2].m_pText,
            WS_CHILD | WS_VISIBLE | Buttons[2].m_nStyle, 50, arrPos[2],
            176, 86, hwnd, (HMENU)(1000 + 2),
            ((LPCREATESTRUCT)lParam)->hInstance, NULL);

        // 为图标按钮、位图按钮设置图标、位图
        SendDlgItemMessage(hwnd, IDC_ICONBUTTON, BM_SETIMAGE, IMAGE_ICON,
            (LPARAM)LoadImage(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDI_ICON1),
                IMAGE_ICON, 45, 45, LR_DEFAULTCOLOR));                          // 尺寸

        SendDlgItemMessage(hwnd, IDC_BITMAPBUTTON, BM_SETIMAGE, IMAGE_BITMAP,
            (LPARAM)LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_PNG1)));

    case WM_DRAWITEM:
        lpDIS = (LPDRAWITEMSTRUCT)lParam;
        return TRUE;


    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;
    }
    return DefWindowProc(hwnd, uMsg, wParam, lParam);
}
