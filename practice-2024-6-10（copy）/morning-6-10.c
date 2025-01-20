#define _CRT_SECURE_NO_WARNINGS 1

#include <Windows.h>
#include <tchar.h>
#include <strsafe.h>
#include "resource.h"

// ��������
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

// WinMain ����
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    // ���崰����
    WNDCLASSEX wndclass;
    TCHAR szAppName[] = TEXT("ϲ����");    // ��������; ����"ϲ����"
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
        CW_USEDEFAULT, CW_USEDEFAULT, 300, 300, NULL, NULL, hInstance, NULL);  //�ڴ��޸Ĵ��ڳߴ�

    ShowWindow(hwnd, nCmdShow);
    UpdateWindow(hwnd);

    while (GetMessage(&msg, NULL, 0, 0) != 0)
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return msg.wParam;
}

// �ؼ��ṹ�嶨��
struct { int m_nStyle; PTSTR m_pText; }Buttons[] =
{
    BS_PUSHBUTTON | BS_NOTIFY | WS_TABSTOP,                 (PTSTR)TEXT("��ͨ��ť"), // 
    BS_ICON | BS_NOTIFY | WS_TABSTOP,                       (PTSTR)TEXT("ͼ�갴ť"), // BS_ICON ͼ��
    BS_BITMAP | BS_NOTIFY | WS_TABSTOP,                     (PTSTR)TEXT("λͼ��ť"), // BS_BITMAP λͼ
};

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    static HWND hwndButton[3];                // �Ӵ��ڿؼ��������
    int arrPos[3] = { 5, 60, 130 };            // ���ؼ���y��λ��
    LPDRAWITEMSTRUCT lpDIS;

    switch (uMsg)
    {
    case WM_CREATE:
        // ����3���Ӵ��ڿؼ�
        hwndButton[0] = CreateWindowEx(0, TEXT("Button"), Buttons[0].m_pText,
            WS_CHILD | WS_VISIBLE | Buttons[0].m_nStyle, 60, arrPos[0],         // x����
            150, 45, hwnd, (HMENU)(1000 + 0),                                   // �� �� ��
            ((LPCREATESTRUCT)lParam)->hInstance, NULL);

        hwndButton[1] = CreateWindowEx(0, TEXT("Button"), Buttons[1].m_pText,
            WS_CHILD | WS_VISIBLE | Buttons[1].m_nStyle, 110, arrPos[1],
            50, 50, hwnd, (HMENU)(1000 + 1),
            ((LPCREATESTRUCT)lParam)->hInstance, NULL);

        hwndButton[2] = CreateWindowEx(0, TEXT("Button"), Buttons[2].m_pText,
            WS_CHILD | WS_VISIBLE | Buttons[2].m_nStyle, 50, arrPos[2],
            176, 86, hwnd, (HMENU)(1000 + 2),
            ((LPCREATESTRUCT)lParam)->hInstance, NULL);

        // Ϊͼ�갴ť��λͼ��ť����ͼ�ꡢλͼ
        SendDlgItemMessage(hwnd, IDC_ICONBUTTON, BM_SETIMAGE, IMAGE_ICON,
            (LPARAM)LoadImage(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDI_ICON1),
                IMAGE_ICON, 45, 45, LR_DEFAULTCOLOR));                          // �ߴ�

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
