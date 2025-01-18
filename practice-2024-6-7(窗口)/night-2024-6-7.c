#define _CRT_SECURE_NO_WARNINGS 1
#pragma comment( linker, "/subsystem:\"windows\" /entry:\"WinMainCRTStartup\"" )
#include <stdio.h>
#include <Windows.h>

//LRESULT CALLBACK WinSunProc(
//	HWND hwnd,      // ���ھ��
//	UINT uMsg,      // ��Ϣʶ��� 
//	WPARAM wParam,  // ��һ����Ϣ����
//	LPARAM lParam   // �ڶ�����Ϣ����
//)
LRESULT CALLBACK WinSunProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam,HWND childHwnd)//�ص�����
{
	//wParam��������λ����رռ�
	//lParam������λ��
	int wmId, wmEvent;
	PAINTSTRUCT ps;
	HDC hdc;
	switch (uMsg)//ͨ���ж���Ϣ������Ϣ��Ӧ
	{
	case WM_COMMAND:
		wmId = LOWORD(wParam);//ˮƽλ��
		wmEvent = HIWORD(wParam);//��ֱλ��
		if (wParam == SC_CLOSE)//��X
			DestroyWindow(hwnd);
		switch (wmId)
		{
		default:
			return DefWindowProc(hwnd, uMsg, wParam, lParam);
		}
		break;
	case WM_CLOSE://�յ�ϵͳ���ٴ���
		DestroyWindow(hwnd);//���ٴ��ڲ�����WM_DESTROY��Ϣ�����ǳ���û���˳�
		break;
	case WM_PAINT:
		hdc = BeginPaint(hwnd, &ps);
		SelectObject(hdc,GetStockObject(DC_BRUSH));
		const COLORREF rgbGreen = 0x0000FF00;
		SetDCBrushColor(hdc, rgbGreen);
		RECT rect;
		LPRECT lprect = &rect;
		GetWindowRect(hwnd, lprect);//�����ϵͳ��λ��
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
int MessageBox (

)
{

}
int WINAPI WinMain(
	HINSTANCE hInstance,//��ǰӦ�ó����ʵ��
	HINSTANCE hPrevInstance,
	LPSTR lpCmdLine,//����������в���
	int nShowCmd//���Ƶ�ǰӦ�ô��������ʾ
	)
{
	WNDCLASS wndcls;//����һ��������
	wndcls.cbClsExtra = 0;//��Ķ����ڴ棬Ĭ��Ϊ0����
	wndcls.cbWndExtra = 0;//���ڵĶ����ڴ棬Ĭ��Ϊ0����
	wndcls.hbrBackground = (HBRUSH)GetStockObject(DC_BRUSH);//��ȡ��ˢ�������HGDIOBJǿ��ת����
	wndcls.hCursor = LoadCursor(NULL, IDC_CROSS);//���ù��
	wndcls.hIcon = LoadIcon(NULL, IDI_APPLICATION);//���ô������Ͻǵ�ͼ��
	wndcls.hInstance = hInstance;
	wndcls.lpfnWndProc = WinSunProc;//���ô���Ļص���������ʱûд
	wndcls.lpszClassName =L"test";//���ô�������  //�� L"test"
	wndcls.lpszMenuName = NULL;//���ô���Ĳ˵���û��
	wndcls.style = CS_HREDRAW | CS_VREDRAW;//���ô�����Ϊˮƽ�ػ��ʹ�ֱ�ػ�
	RegisterClass(&wndcls);//�����ϵͳע�ᴰ��
	//void CreateWindowA(
	//	[in, optional]  lpClassName,//����������Ҳ��������ע�ᴰ����ʱ�������
	//	[in, optional]  lpWindowName, //��������Ҳ���Ǵ�����ʾʱ�����Ͻ���ʾ������
	//	[in]            dwStyle, //���ڷ��һ����WS_OVERLAPPEDWINDOW���ɣ����������Ĵ��ھ�����󻯣���С���ȵȵȵ����ԡ�����
	//	[in]            x, //�����ʼ�����������������X���꣬һ��Ĭ��CW_USEDEFAULT����
	//	[in]            y, //�����ʼ�����������������Y���꣬һ��Ĭ��CW_USEDEFAULT����
	//	[in]            nWidth, //���ڴ����Ŀ�ȣ�һ��Ĭ��CW_USEDEFAULT����
	//	[in]            nHeight, //���ڴ����ĸ߶ȣ�һ��Ĭ��CW_USEDEFAULT����
	//	[in, optional]  hWndParent,//�����ڵľ����û�У���NULL
	//	[in, optional]  hMenu, //�˵������û�У���NULL
	//	[in, optional]  hInstance, //Ӧ�ó���ʵ������������õ���WinMain�ĵ�һ������
	//	[in, optional]  lpParam //��������ݣ�ͦ���ӵģ�����Ҳ����Ҫ����NULL������
	//);

	//����һ�����壬�����ظô���ľ������һ����������ΪҪ�����Ĵ�����������ڶ�������Ϊ���������
	HWND hwnd = CreateWindow(L"test", L"�ҵĵ�һ������",
		WS_OVERLAPPEDWINDOW, CW_USEDEFAULT,
		CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,
		NULL, NULL, hInstance, NULL);//L"test"
	ShowWindow(hwnd, SW_SHOWNORMAL);//�Ѵ�����ʾ����
	UpdateWindow(hwnd);//���´���

	HWND childHwnd1 = CreateWindow(L"BUTTON", NULL,
		WS_CHILD, 200,
		0, 100, 100,
		hwnd, NULL, hInstance, NULL);//L"test"
	ShowWindow(childHwnd1, SW_SHOWNORMAL);//�Ѵ�����ʾ����
	UpdateWindow(childHwnd1);//���´���

	HWND childHwnd2 = CreateWindow(L"edit", NULL,
		WS_CHILD, CW_USEDEFAULT,
		CW_USEDEFAULT, 100, 100,
		hwnd, NULL, hInstance, NULL);//L"test"
	ShowWindow(childHwnd2, SW_SHOWNORMAL);//�Ѵ�����ʾ����
	UpdateWindow(childHwnd2);//���´���
	//���ʹ���������Ļ����Ϳɲ��øú���
	/*��ν������룬����һ����ֵ���ѣ�ĳһ��ȷ������ֵ�����㰴�µ�ĳ������
		���統�㰴��A��������ͻ��յ�һ��������ֵ0x41����Ϣ��
		���������ʵ������ĸA��ASCII����ֵ�����Դ����п���ֱ��дΪ��A���Ϳ�����*/
	//��Ϣѭ�� 
	MSG msg;
	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return WM_QUIT;
}
