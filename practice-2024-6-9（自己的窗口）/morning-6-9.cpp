#define _CRT_SECURE_NO_WARNINGS 1
#pragma comment(linker, "/subsystem:\"windows\" /entry:\"WinMainCRTStartup\"" )
//#pragma comment(linker, "/subsystem:\"windows\" /entry:\"mainCRTStartup\"")
//#pragma comment( linker, "/subsystem:\"console\" /entry:\"mainCRTStartup\"" )

//#pragma comment(linker,"\"/manifestdependency:type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='X86' publicKeyToken='6595b64144ccf1df' language='*'\"")
//(64位平台，改为AMD64)
#pragma comment(lib, "winmm")//声音

#include <Windows.h>
#include <commctrl.h>//图像列表
#include <stdio.h>
#include <Mmsystem.h>
#include <windowsx.h>
#include <WinDef.h>
#include <tchar.h>
#include <strsafe.h>
#include <iostream>
#include "resource1.h"
#include "Queue.h"

#define IDC_PUSHBUTTON             1000
#define IDC_ICONBUTTON             1001
#define IDC_BITMAPBUTTON           1002
#define IDC_CIALLOBUTTON           1003
#define IDC_PUSHBUTTON5            1004

#define EIDT_INPUT1                1010
#define EIDT_INPUT2                1011

#define CHILDMODIFY WM_USER+10
#define BUTTONNUM                  4
#define EDITNUM                    3

struct { 
	int dWstyle;
	PTSTR pText;
}Buttons[] = {
	BS_BITMAP | BS_NOTIFY | WS_TABSTOP | BS_TEXT,      (PTSTR)TEXT("文本按钮"),//TEXT=L
	BS_BITMAP | BS_NOTIFY | WS_TABSTOP | BS_TEXT,      (PTSTR)TEXT("图标按钮"), // BS_ICON 图标
	BS_BITMAP | BS_NOTIFY | WS_TABSTOP | BS_TEXT,      (PTSTR)TEXT("位图按钮"), // BS_BITMAP 位图
	BS_BITMAP | BS_NOTIFY | WS_TABSTOP | BS_TEXT,      (PTSTR)TEXT("位图按钮")
};
static HINSTANCE hInstance;
static WCHAR wchar_buff[100]{ 0 };
static HWND arrHwndChildButton[BUTTONNUM];
static HWND arrHwndEdit[EDITNUM];
void PartButtonWnd(HWND hWnd,HINSTANCE hInstance, LPARAM lParam)
{
	int i = 0;
	RECT rect;
	LPRECT lprect = &rect;
	GetWindowRect(hWnd, lprect);//是相对系统的位置
	int j = 0;
	int k = 10;
	int tmp = 0;
	for (i = 0; i < BUTTONNUM -1; ++i)
	{
		if (i * 150 + 30 + 100 > rect.right)
		{
			j++;//换行
			k = i;
		}//防止过多超出
		//可以用((LPCREATESTRUCT)lParam)->hInstance
		arrHwndChildButton[i] = CreateWindowEx(0, L"BUTTON", Buttons[i].pText,
			WS_CHILD | WS_VISIBLE | WS_CLIPSIBLINGS | Buttons[i].dWstyle,
			(i%k) * 150 + 30, 250 + 80 * j, 100, 50,
			hWnd, (HMENU)(1000 + i), hInstance, NULL); //WM_CREATE会lParam指向 CREATESTRUCT 结构的指针，该结构包含有关所创建窗口的信息。
		SendDlgItemMessage(hWnd, IDC_ICONBUTTON, BM_SETIMAGE, IMAGE_BITMAP,
			(LPARAM)LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_BITMAP1)));//LoadImage()可以加载icon和bmp，设置大小
		SendDlgItemMessage(hWnd, IDC_BITMAPBUTTON, BM_SETIMAGE, IMAGE_BITMAP,
			(LPARAM)LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_BITMAP2)));
		
		ShowWindow(arrHwndChildButton[i], SW_SHOWNORMAL);
		UpdateWindow(arrHwndChildButton[i]);
		//tmp = GetWindowLong(arrHwndChildButton[1], GWL_STYLE);
		//SetWindowLongPtr(arrHwndChildButton[1], GWL_STYLE, tmp | BS_TEXT);//可以用getwindowlong获得原来的style
		//Button_SetText(arrHwndChildButton[i], (LPCWSTR)TEXT("abcd"));
	}
	arrHwndChildButton[i] = CreateWindowEx(0, L"BUTTON", Buttons[i].pText,
		WS_CHILD | WS_VISIBLE | WS_CLIPSIBLINGS | Buttons[i].dWstyle,
		i * 150 + 30, 250 + 80 * j, 100, 50,
		hWnd, (HMENU)(1000 + 3), hInstance, NULL);
	SendDlgItemMessage(hWnd, IDC_CIALLOBUTTON, BM_SETIMAGE, IMAGE_BITMAP,
			(LPARAM)LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_BITMAP4)));
	ShowWindow(arrHwndChildButton[i], SW_SHOWNORMAL);
	UpdateWindow(arrHwndChildButton[i]);
}
void PartEditWnd(HWND hWnd, HINSTANCE hInstance)
{
	RECT rect;
	LPRECT lprect = &rect;
	GetWindowRect(hWnd, lprect);//是相对系统的位置
	arrHwndEdit[0] = CreateWindowEx(0,L"EDIT", L"显示窗口",
		WS_BORDER | WS_CHILD | WS_VISIBLE | WS_VSCROLL | ES_LEFT |
		ES_MULTILINE | ES_AUTOVSCROLL| ES_READONLY,
		0, 0, rect.right, 200,
		hWnd,(HMENU)(EIDT_INPUT1), hInstance, NULL);
	ShowWindow(arrHwndEdit[0], SW_SHOWNORMAL);
	UpdateWindow(arrHwndEdit[0]);

	arrHwndEdit[1] = CreateWindow(L"EDIT", NULL,
		WS_BORDER | WS_CHILD | WS_VISIBLE | WS_VSCROLL | ES_LEFT |
		ES_MULTILINE | ES_AUTOVSCROLL,
		0, 400, rect.right, 200,
		hWnd, (HMENU)(1000 + 11), hInstance, NULL);
	ShowWindow(arrHwndEdit[1], SW_SHOWNORMAL);
	UpdateWindow(arrHwndEdit[1]);

}
LRESULT CALLBACK WndParentPoc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	//wParam具体点击的位置如关闭键
	//lParam鼠标光标的位置
	int wmId, wmEvent;
	HWND hWndChild;
	//子窗口
	static HWND hWndButton[BUTTONNUM];
	LPDRAWITEMSTRUCT lpDIS;
	HWND hedit;
	//背景颜色
	PAINTSTRUCT ps;
	HDC hdc;
	RECT rect;
	LPRECT lprect=&rect;
	const COLORREF rgbGreen = 0x0000FF00;
	GetWindowRect(hwnd, lprect);//是相对系统的位置

	switch (uMsg)//通过判断消息进行消息响应
	{
	case WM_CREATE://创建子窗口
		PartButtonWnd(hwnd, hInstance, lParam);
		break;
	case WM_DRAWITEM:
		lpDIS = (LPDRAWITEMSTRUCT)lParam;
		return TRUE;
	case WM_SIZE://缩放调整窗口
		Edit_SetRectNoPaint(arrHwndEdit[0], lprect);
		//while (hWndChild = FindWindowEx(hwnd, NULL, L"edit", NULL))
		//{
		//	DestroyWindow(hWndChild);
		//}
		//while (hWndChild = FindWindowEx(hwnd, NULL, L"button", NULL))
		//{
		//	DestroyWindow(hWndChild);
		//}
		/*GetWindowRect(hwnd, lprect);
		SetWindowPos(hwnd, HWND_TOP, 0, 0, NULL, rect.right, SWP_NOMOVE);*/
		break;
	case WM_COMMAND:
		wmId = LOWORD(wParam);//水平位置
		wmEvent = HIWORD(wParam);//垂直位置
		if (wParam == SC_CLOSE)//点X
			DestroyWindow(hwnd);
		switch (wmId)
		{
		case IDC_PUSHBUTTON:
			SetDlgItemTextW(hwnd, EIDT_INPUT1, wchar_buff);
			break;
		case IDC_ICONBUTTON:
				hedit = GetDlgItem(hwnd, EIDT_INPUT2);		//首先获取文本框窗口的句柄
				GetDlgItemTextW(hwnd, EIDT_INPUT2, wchar_buff, 100);
				//GetWindowTextW(hedit, str_dst, 100);	//根据得到的子窗口的句柄得到字符串并且放入一个字符数组中
				//MessageBoxW(hwnd, wchar_buff , L"提示", NULL);	//读取文本框的内容
				//我的获取地址
				// hBuff=(HLOCAL)SendMessage(arrHwndEdit[0], EM_SETMARGINS, EC_RIGHTMARGIN, LOWORD(10));
				//pBuff = (WCHAR*)LocalLock(hBuff);
				break;
		case IDC_CIALLOBUTTON:
			PlaySoundW(MAKEINTRESOURCE(IDR_WAVE1), hInstance, SND_RESOURCE | SND_ASYNC);
			break;
		default:
			return DefWindowProc(hwnd, uMsg, wParam, lParam);
		}
		break;
	case WM_CLOSE://收到系统销毁窗口
		DestroyWindow(hwnd);//销毁窗口并发送WM_DESTROY消息，但是程序没有退出
		break;
	case WM_PAINT:

		hdc = BeginPaint(hwnd, &ps);
		SelectObject(hdc, GetStockObject(DC_BRUSH));
		SetDCBrushColor(hdc, rgbGreen);
		lprect = &rect;
		Rectangle(hdc, 0, 0, rect.right, rect.bottom);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);//发出WM_QUIT消息，结束消息循环
		break;
	default:
		return DefWindowProc(hwnd, uMsg, wParam, lParam);//对不感兴趣的消息进行缺省处理，必须有该代码，否则程序有问题
	}
	return 0;
}

//LRESULT CALLBACK WndButtonPoc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
//{
//	//wParam具体点击的位置如关闭键
//	//lParam鼠标光标的位置
//	int wmId, wmEvent;
//	PAINTSTRUCT ps;
//	HDC hdc;
//	RECT rect;
//	LPRECT lprect;
//	switch (uMsg)//通过判断消息进行消息响应
//	{
//	case CHILDMODIFY://调整窗口
//		DestroyWindow(hwnd);
//	case WM_COMMAND:
//		wmId = LOWORD(wParam);//水平位置
//		wmEvent = HIWORD(wParam);//垂直位置
//		if (wParam == SC_CLOSE)//点X
//			DestroyWindow(hwnd);
//		switch (wmId)
//		{
//		default:
//			return DefWindowProc(hwnd, uMsg, wParam, lParam);
//		}
//		break;
//	case WM_PAINT:
//		hdc = BeginPaint(hwnd, &ps);
//		SelectObject(hdc, GetStockObject(DC_BRUSH));
//		SetDCBrushColor(hdc, RGB(128,128,128));//灰色
//		lprect = &rect;
//		GetWindowRect(hwnd, lprect);//是相对系统的位置
//		Rectangle(hdc, 0, 0, rect.right, rect.bottom);
//		break;
//	case WM_DESTROY:
//		PostQuitMessage(0);//发出WM_QUIT消息，结束消息循环
//	default:
//		return DefWindowProc(hwnd, uMsg, wParam, lParam);//对不感兴趣的消息进行缺省处理，必须有该代码，否则程序有问题
//	}
//}

//struct { int m_nStyle; PTSTR m_pText; }Buttons[] =
//{
//	BS_PUSHBUTTON | BS_NOTIFY | WS_TABSTOP,                 (PTSTR)TEXT("普通按钮"), // 
//	BS_ICON | BS_NOTIFY | WS_TABSTOP,                       (PTSTR)TEXT("图标按钮"), // BS_ICON 图标
//	BS_BITMAP | BS_NOTIFY | WS_TABSTOP,                     (PTSTR)TEXT("位图按钮"), // BS_BITMAP 位图
//};
//LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
//{
//	static HWND hwndButton[3];                // 子窗口控件句柄数组
//	int arrPos[3] = { 5, 60, 130 };            // 各控件的y向位置
//	LPDRAWITEMSTRUCT lpDIS;
//
//	switch (uMsg)
//	{
//	case WM_CREATE:
//		// 创建3个子窗口控件
//		hwndButton[0] = CreateWindowEx(0, TEXT("Button"), Buttons[0].m_pText,
//			WS_CHILD | WS_VISIBLE | Buttons[0].m_nStyle, 60, arrPos[0],         // x坐标
//			150, 45, hwnd, (HMENU)(1000 + 0),                                   // 宽 和 高
//			((LPCREATESTRUCT)lParam)->hInstance, NULL);
//
//		hwndButton[1] = CreateWindowEx(0, TEXT("Button"), Buttons[1].m_pText,
//			WS_CHILD | WS_VISIBLE | Buttons[1].m_nStyle, 110, arrPos[1],
//			50, 50, hwnd, (HMENU)(1000 + 1),
//			((LPCREATESTRUCT)lParam)->hInstance, NULL);
//
//		hwndButton[2] = CreateWindowEx(0, TEXT("Button"), Buttons[2].m_pText,
//			WS_CHILD | WS_VISIBLE | Buttons[2].m_nStyle, 50, arrPos[2],
//			176, 86, hwnd, (HMENU)(1000 + 2),
//			((LPCREATESTRUCT)lParam)->hInstance, NULL);
//
//		// 为图标按钮、位图按钮设置图标、位图
//		SendDlgItemMessage(hwnd, IDC_ICONBUTTON, BM_SETIMAGE, IMAGE_ICON,
//			(LPARAM)LoadImage(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDI_ICON1),
//				IMAGE_ICON, 45, 45, LR_DEFAULTCOLOR));                          // 尺寸
//
//		SendDlgItemMessage(hwnd, IDC_BITMAPBUTTON, BM_SETIMAGE, IMAGE_BITMAP,
//			(LPARAM)LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_PNG1)));
//
//	case WM_DRAWITEM:
//		lpDIS = (LPDRAWITEMSTRUCT)lParam;
//		return TRUE;
//
//
//	case WM_DESTROY:
//		PostQuitMessage(0);
//		return 0;
//	}
//	return DefWindowProc(hwnd, uMsg, wParam, lParam);
//}

//LRESULT CALLBACK WndEditPoc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
//{
//	//wParam具体点击的位置如关闭键
//	//lParam鼠标光标的位置
//	PAINTSTRUCT ps;
//	HDC hdc;
//	RECT rect;
//	LPRECT lprect;
//	switch (uMsg)//通过判断消息进行消息响应
//	{
//	case CHILDMODIFY://调整窗口
//		DestroyWindow(hwnd);
//	case WM_PAINT:
//		hdc = BeginPaint(hwnd, &ps);
//		SelectObject(hdc, GetStockObject(DC_BRUSH));
//		SetDCBrushColor(hdc, RGB(255, 255, 255));//白色
//		lprect = &rect;
//		GetWindowRect(hwnd, lprect);//是相对系统的位置
//		Rectangle(hdc, 0, 0, rect.right, rect.bottom);
//		break;
//	case WM_DESTROY:
//		PostQuitMessage(0);//发出WM_QUIT消息，结束消息循环
//	default:
//		return DefWindowProc(hwnd, uMsg, wParam, lParam);//对不感兴趣的消息进行缺省处理，必须有该代码，否则程序有问题
//	}
//}
int WINAPI WinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance,LPSTR lpCmdLine,int nShowCmd)
{
	//父窗口
	WNDCLASSEX Wndcls;
	Wndcls.cbSize = sizeof(WNDCLASSEX);
	Wndcls.hInstance = hInstance;
	Wndcls.lpszClassName = L"TEST";
	Wndcls.cbClsExtra = 0;
	Wndcls.cbWndExtra = 0;
	Wndcls.hCursor = LoadCursor(NULL, IDC_APPSTARTING);
	Wndcls.lpfnWndProc = WndParentPoc;
	Wndcls.hbrBackground = (HBRUSH)GetStockObject(DC_BRUSH);
	Wndcls.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	Wndcls.lpszMenuName = NULL;
	Wndcls.style = CS_HREDRAW | CS_VREDRAW;
	Wndcls.hIconSm = NULL;
	RegisterClassEx(&Wndcls);

	//创建父窗口
	HWND hWnd = CreateWindowEx(0,L"test", L"我的一窗口",
		WS_OVERLAPPEDWINDOW| WS_VISIBLE,
		CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,
		NULL,NULL, hInstance, NULL);
	ShowWindow(hWnd,SW_SHOWNORMAL);
	UpdateWindow(hWnd);

	//创建子窗口
	PartEditWnd(hWnd, hInstance);

	//消息循环
	MSG uMsg;
	while (GetMessage(&uMsg, NULL, 0, 0))
	{
		TranslateMessage(&uMsg);
		DispatchMessage(&uMsg);
	}
	return uMsg.wParam;
}