#define _CRT_SECURE_NO_WARNINGS 1
#pragma comment(linker, "/subsystem:\"windows\" /entry:\"WinMainCRTStartup\"" )
//#pragma comment(linker, "/subsystem:\"windows\" /entry:\"mainCRTStartup\"")
//#pragma comment( linker, "/subsystem:\"console\" /entry:\"mainCRTStartup\"" )

//#pragma comment(linker,"\"/manifestdependency:type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='X86' publicKeyToken='6595b64144ccf1df' language='*'\"")
//(64λƽ̨����ΪAMD64)
#pragma comment(lib, "winmm")//����

#include <Windows.h>
#include <commctrl.h>//ͼ���б�
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
	BS_BITMAP | BS_NOTIFY | WS_TABSTOP | BS_TEXT,      (PTSTR)TEXT("�ı���ť"),//TEXT=L
	BS_BITMAP | BS_NOTIFY | WS_TABSTOP | BS_TEXT,      (PTSTR)TEXT("ͼ�갴ť"), // BS_ICON ͼ��
	BS_BITMAP | BS_NOTIFY | WS_TABSTOP | BS_TEXT,      (PTSTR)TEXT("λͼ��ť"), // BS_BITMAP λͼ
	BS_BITMAP | BS_NOTIFY | WS_TABSTOP | BS_TEXT,      (PTSTR)TEXT("λͼ��ť")
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
	GetWindowRect(hWnd, lprect);//�����ϵͳ��λ��
	int j = 0;
	int k = 10;
	int tmp = 0;
	for (i = 0; i < BUTTONNUM -1; ++i)
	{
		if (i * 150 + 30 + 100 > rect.right)
		{
			j++;//����
			k = i;
		}//��ֹ���೬��
		//������((LPCREATESTRUCT)lParam)->hInstance
		arrHwndChildButton[i] = CreateWindowEx(0, L"BUTTON", Buttons[i].pText,
			WS_CHILD | WS_VISIBLE | WS_CLIPSIBLINGS | Buttons[i].dWstyle,
			(i%k) * 150 + 30, 250 + 80 * j, 100, 50,
			hWnd, (HMENU)(1000 + i), hInstance, NULL); //WM_CREATE��lParamָ�� CREATESTRUCT �ṹ��ָ�룬�ýṹ�����й����������ڵ���Ϣ��
		SendDlgItemMessage(hWnd, IDC_ICONBUTTON, BM_SETIMAGE, IMAGE_BITMAP,
			(LPARAM)LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_BITMAP1)));//LoadImage()���Լ���icon��bmp�����ô�С
		SendDlgItemMessage(hWnd, IDC_BITMAPBUTTON, BM_SETIMAGE, IMAGE_BITMAP,
			(LPARAM)LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_BITMAP2)));
		
		ShowWindow(arrHwndChildButton[i], SW_SHOWNORMAL);
		UpdateWindow(arrHwndChildButton[i]);
		//tmp = GetWindowLong(arrHwndChildButton[1], GWL_STYLE);
		//SetWindowLongPtr(arrHwndChildButton[1], GWL_STYLE, tmp | BS_TEXT);//������getwindowlong���ԭ����style
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
	GetWindowRect(hWnd, lprect);//�����ϵͳ��λ��
	arrHwndEdit[0] = CreateWindowEx(0,L"EDIT", L"��ʾ����",
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
	//wParam��������λ����رռ�
	//lParam������λ��
	int wmId, wmEvent;
	HWND hWndChild;
	//�Ӵ���
	static HWND hWndButton[BUTTONNUM];
	LPDRAWITEMSTRUCT lpDIS;
	HWND hedit;
	//������ɫ
	PAINTSTRUCT ps;
	HDC hdc;
	RECT rect;
	LPRECT lprect=&rect;
	const COLORREF rgbGreen = 0x0000FF00;
	GetWindowRect(hwnd, lprect);//�����ϵͳ��λ��

	switch (uMsg)//ͨ���ж���Ϣ������Ϣ��Ӧ
	{
	case WM_CREATE://�����Ӵ���
		PartButtonWnd(hwnd, hInstance, lParam);
		break;
	case WM_DRAWITEM:
		lpDIS = (LPDRAWITEMSTRUCT)lParam;
		return TRUE;
	case WM_SIZE://���ŵ�������
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
		wmId = LOWORD(wParam);//ˮƽλ��
		wmEvent = HIWORD(wParam);//��ֱλ��
		if (wParam == SC_CLOSE)//��X
			DestroyWindow(hwnd);
		switch (wmId)
		{
		case IDC_PUSHBUTTON:
			SetDlgItemTextW(hwnd, EIDT_INPUT1, wchar_buff);
			break;
		case IDC_ICONBUTTON:
				hedit = GetDlgItem(hwnd, EIDT_INPUT2);		//���Ȼ�ȡ�ı��򴰿ڵľ��
				GetDlgItemTextW(hwnd, EIDT_INPUT2, wchar_buff, 100);
				//GetWindowTextW(hedit, str_dst, 100);	//���ݵõ����Ӵ��ڵľ���õ��ַ������ҷ���һ���ַ�������
				//MessageBoxW(hwnd, wchar_buff , L"��ʾ", NULL);	//��ȡ�ı��������
				//�ҵĻ�ȡ��ַ
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
	case WM_CLOSE://�յ�ϵͳ���ٴ���
		DestroyWindow(hwnd);//���ٴ��ڲ�����WM_DESTROY��Ϣ�����ǳ���û���˳�
		break;
	case WM_PAINT:

		hdc = BeginPaint(hwnd, &ps);
		SelectObject(hdc, GetStockObject(DC_BRUSH));
		SetDCBrushColor(hdc, rgbGreen);
		lprect = &rect;
		Rectangle(hdc, 0, 0, rect.right, rect.bottom);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);//����WM_QUIT��Ϣ��������Ϣѭ��
		break;
	default:
		return DefWindowProc(hwnd, uMsg, wParam, lParam);//�Բ�����Ȥ����Ϣ����ȱʡ���������иô��룬�������������
	}
	return 0;
}

//LRESULT CALLBACK WndButtonPoc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
//{
//	//wParam��������λ����رռ�
//	//lParam������λ��
//	int wmId, wmEvent;
//	PAINTSTRUCT ps;
//	HDC hdc;
//	RECT rect;
//	LPRECT lprect;
//	switch (uMsg)//ͨ���ж���Ϣ������Ϣ��Ӧ
//	{
//	case CHILDMODIFY://��������
//		DestroyWindow(hwnd);
//	case WM_COMMAND:
//		wmId = LOWORD(wParam);//ˮƽλ��
//		wmEvent = HIWORD(wParam);//��ֱλ��
//		if (wParam == SC_CLOSE)//��X
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
//		SetDCBrushColor(hdc, RGB(128,128,128));//��ɫ
//		lprect = &rect;
//		GetWindowRect(hwnd, lprect);//�����ϵͳ��λ��
//		Rectangle(hdc, 0, 0, rect.right, rect.bottom);
//		break;
//	case WM_DESTROY:
//		PostQuitMessage(0);//����WM_QUIT��Ϣ��������Ϣѭ��
//	default:
//		return DefWindowProc(hwnd, uMsg, wParam, lParam);//�Բ�����Ȥ����Ϣ����ȱʡ���������иô��룬�������������
//	}
//}

//struct { int m_nStyle; PTSTR m_pText; }Buttons[] =
//{
//	BS_PUSHBUTTON | BS_NOTIFY | WS_TABSTOP,                 (PTSTR)TEXT("��ͨ��ť"), // 
//	BS_ICON | BS_NOTIFY | WS_TABSTOP,                       (PTSTR)TEXT("ͼ�갴ť"), // BS_ICON ͼ��
//	BS_BITMAP | BS_NOTIFY | WS_TABSTOP,                     (PTSTR)TEXT("λͼ��ť"), // BS_BITMAP λͼ
//};
//LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
//{
//	static HWND hwndButton[3];                // �Ӵ��ڿؼ��������
//	int arrPos[3] = { 5, 60, 130 };            // ���ؼ���y��λ��
//	LPDRAWITEMSTRUCT lpDIS;
//
//	switch (uMsg)
//	{
//	case WM_CREATE:
//		// ����3���Ӵ��ڿؼ�
//		hwndButton[0] = CreateWindowEx(0, TEXT("Button"), Buttons[0].m_pText,
//			WS_CHILD | WS_VISIBLE | Buttons[0].m_nStyle, 60, arrPos[0],         // x����
//			150, 45, hwnd, (HMENU)(1000 + 0),                                   // �� �� ��
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
//		// Ϊͼ�갴ť��λͼ��ť����ͼ�ꡢλͼ
//		SendDlgItemMessage(hwnd, IDC_ICONBUTTON, BM_SETIMAGE, IMAGE_ICON,
//			(LPARAM)LoadImage(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDI_ICON1),
//				IMAGE_ICON, 45, 45, LR_DEFAULTCOLOR));                          // �ߴ�
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
//	//wParam��������λ����رռ�
//	//lParam������λ��
//	PAINTSTRUCT ps;
//	HDC hdc;
//	RECT rect;
//	LPRECT lprect;
//	switch (uMsg)//ͨ���ж���Ϣ������Ϣ��Ӧ
//	{
//	case CHILDMODIFY://��������
//		DestroyWindow(hwnd);
//	case WM_PAINT:
//		hdc = BeginPaint(hwnd, &ps);
//		SelectObject(hdc, GetStockObject(DC_BRUSH));
//		SetDCBrushColor(hdc, RGB(255, 255, 255));//��ɫ
//		lprect = &rect;
//		GetWindowRect(hwnd, lprect);//�����ϵͳ��λ��
//		Rectangle(hdc, 0, 0, rect.right, rect.bottom);
//		break;
//	case WM_DESTROY:
//		PostQuitMessage(0);//����WM_QUIT��Ϣ��������Ϣѭ��
//	default:
//		return DefWindowProc(hwnd, uMsg, wParam, lParam);//�Բ�����Ȥ����Ϣ����ȱʡ���������иô��룬�������������
//	}
//}
int WINAPI WinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance,LPSTR lpCmdLine,int nShowCmd)
{
	//������
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

	//����������
	HWND hWnd = CreateWindowEx(0,L"test", L"�ҵ�һ����",
		WS_OVERLAPPEDWINDOW| WS_VISIBLE,
		CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,
		NULL,NULL, hInstance, NULL);
	ShowWindow(hWnd,SW_SHOWNORMAL);
	UpdateWindow(hWnd);

	//�����Ӵ���
	PartEditWnd(hWnd, hInstance);

	//��Ϣѭ��
	MSG uMsg;
	while (GetMessage(&uMsg, NULL, 0, 0))
	{
		TranslateMessage(&uMsg);
		DispatchMessage(&uMsg);
	}
	return uMsg.wParam;
}