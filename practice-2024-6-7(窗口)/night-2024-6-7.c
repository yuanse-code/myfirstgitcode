#define _CRT_SECURE_NO_WARNINGS 1
#pragma comment( linker, "/subsystem:\"windows\" /entry:\"WinMainCRTStartup\"" )
#include <stdio.h>
#include <Windows.h>

//LRESULT CALLBACK WinSunProc(
//	HWND hwnd,      // 窗口句柄
//	UINT uMsg,      // 消息识别符 
//	WPARAM wParam,  // 第一个消息参数
//	LPARAM lParam   // 第二个消息参数
//)
LRESULT CALLBACK WinSunProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam,HWND childHwnd)//回调函数
{
	//wParam具体点击的位置如关闭键
	//lParam鼠标光标的位置
	int wmId, wmEvent;
	PAINTSTRUCT ps;
	HDC hdc;
	switch (uMsg)//通过判断消息进行消息响应
	{
	case WM_COMMAND:
		wmId = LOWORD(wParam);//水平位置
		wmEvent = HIWORD(wParam);//垂直位置
		if (wParam == SC_CLOSE)//点X
			DestroyWindow(hwnd);
		switch (wmId)
		{
		default:
			return DefWindowProc(hwnd, uMsg, wParam, lParam);
		}
		break;
	case WM_CLOSE://收到系统销毁窗口
		DestroyWindow(hwnd);//销毁窗口并发送WM_DESTROY消息，但是程序没有退出
		break;
	case WM_PAINT:
		hdc = BeginPaint(hwnd, &ps);
		SelectObject(hdc,GetStockObject(DC_BRUSH));
		const COLORREF rgbGreen = 0x0000FF00;
		SetDCBrushColor(hdc, rgbGreen);
		RECT rect;
		LPRECT lprect = &rect;
		GetWindowRect(hwnd, lprect);//是相对系统的位置
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
int MessageBox (

)
{

}
int WINAPI WinMain(
	HINSTANCE hInstance,//当前应用程序的实例
	HINSTANCE hPrevInstance,
	LPSTR lpCmdLine,//传入的命令行参数
	int nShowCmd//控制当前应用窗口如何显示
	)
{
	WNDCLASS wndcls;//创建一个窗体类
	wndcls.cbClsExtra = 0;//类的额外内存，默认为0即可
	wndcls.cbWndExtra = 0;//窗口的额外内存，默认为0即可
	wndcls.hbrBackground = (HBRUSH)GetStockObject(DC_BRUSH);//获取画刷句柄（将HGDIOBJ强制转换）
	wndcls.hCursor = LoadCursor(NULL, IDC_CROSS);//设置光标
	wndcls.hIcon = LoadIcon(NULL, IDI_APPLICATION);//设置窗口左上角的图标
	wndcls.hInstance = hInstance;
	wndcls.lpfnWndProc = WinSunProc;//设置窗体的回调函数，暂时没写
	wndcls.lpszClassName =L"test";//设置窗体类名  //如 L"test"
	wndcls.lpszMenuName = NULL;//设置窗体的菜单，没有
	wndcls.style = CS_HREDRAW | CS_VREDRAW;//设置窗体风格为水平重画和垂直重画
	RegisterClass(&wndcls);//向操作系统注册窗体
	//void CreateWindowA(
	//	[in, optional]  lpClassName,//窗口类名，也就是上面注册窗口类时填的类名
	//	[in, optional]  lpWindowName, //窗口名，也就是窗口显示时，左上角显示的名称
	//	[in]            dwStyle, //窗口风格，一般填WS_OVERLAPPEDWINDOW即可，这样创建的窗口就有最大化，最小化等等等等属性。。。
	//	[in]            x, //窗口最开始被创建在哪里？这里填X坐标，一般默认CW_USEDEFAULT即可
	//	[in]            y, //窗口最开始被创建在哪里？这里填Y坐标，一般默认CW_USEDEFAULT即可
	//	[in]            nWidth, //窗口创建的宽度，一般默认CW_USEDEFAULT即可
	//	[in]            nHeight, //窗口创建的高度，一般默认CW_USEDEFAULT即可
	//	[in, optional]  hWndParent,//父窗口的句柄，没有，填NULL
	//	[in, optional]  hMenu, //菜单句柄，没有，填NULL
	//	[in, optional]  hInstance, //应用程序实例，这里就又用到了WinMain的第一个参数
	//	[in, optional]  lpParam //额外的数据，挺复杂的，咱们也不需要，填NULL就行了
	//);

	//产生一个窗体，并返回该窗体的句柄，第一个参数必须为要创建的窗体的类名，第二个参数为窗体标题名
	HWND hwnd = CreateWindow(L"test", L"我的第一个窗口",
		WS_OVERLAPPEDWINDOW, CW_USEDEFAULT,
		CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,
		NULL, NULL, hInstance, NULL);//L"test"
	ShowWindow(hwnd, SW_SHOWNORMAL);//把窗体显示出来
	UpdateWindow(hwnd);//更新窗体

	HWND childHwnd1 = CreateWindow(L"BUTTON", NULL,
		WS_CHILD, 200,
		0, 100, 100,
		hwnd, NULL, hInstance, NULL);//L"test"
	ShowWindow(childHwnd1, SW_SHOWNORMAL);//把窗体显示出来
	UpdateWindow(childHwnd1);//更新窗体

	HWND childHwnd2 = CreateWindow(L"edit", NULL,
		WS_CHILD, CW_USEDEFAULT,
		CW_USEDEFAULT, 100, 100,
		hwnd, NULL, hInstance, NULL);//L"test"
	ShowWindow(childHwnd2, SW_SHOWNORMAL);//把窗体显示出来
	UpdateWindow(childHwnd2);//更新窗体
	//如果使用虚拟键码的话，就可不用该函数
	/*所谓虚拟键码，就是一个数值而已，某一个确定的数值代表你按下的某个键，
		比如当你按下A键，程序就会收到一个包含数值0x41的消息，
		这个数字其实就是字母A的ASCII码表的值，所以代码中可以直接写为’A’就可以了*/
	//消息循环 
	MSG msg;
	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return WM_QUIT;
}
