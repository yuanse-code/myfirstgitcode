// 健身俱乐部会员消息管理系统.cpp : 定义应用程序的入口点。
//
#define _CRT_SECURE_NO_WARNINGS 1
#include "framework.h"
#include "健身俱乐部会员消息管理系统.h"

#define UNICODE
#define MAX_LOADSTRING 100

// 全局变量:
HINSTANCE hInst;                                // 当前实例
WCHAR szTitle[MAX_LOADSTRING];                  // 标题栏文本
WCHAR szWindowClass[MAX_LOADSTRING] = { L"test" }; // 主窗口类名
struct { int dWstyle; LPCSTR pText; }ButtonsClass = {
    WS_TABSTOP | WS_CHILD | WS_VISIBLE | WS_CLIPSIBLINGS |
    BS_BITMAP  | WS_TABSTOP | BS_TEXT | BS_PUSHBUTTON,
    "按钮"
};//子按钮
static HWND arrHwndChildButton[AllBUTTONNUM];
static HWND arrHwndEdit[EDITNUM];
static HWND arrHwndYear[6];
Queue* pQWchar;//缓冲队列
Contact* pCon;//名单

// 此代码模块中包含的函数的前向声明:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM); 
void PartButtonWnd(HWND hWnd, HINSTANCE hInstance, LPARAM lParam);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: 在此处放置代码。
    int input = 0;
    int capacity = 3;
    //创建通讯录
    Contact con;	//con就是通讯录
    //初始化通讯录
    InitContact(&con);
    if (NULL == con.date)
    {
        assert(con.date);
        exit(-1);
    }
    pCon = &con;
    SaveContact(pCon);
  
    // 初始化全局字符串
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_MY, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // 执行应用程序初始化:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_MY));

    MSG msg;

    // 主消息循环:
    while (GetMessage(&msg, NULL, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }
    //销毁
    free(con.date);
    con.date = NULL;
    return (int) msg.wParam;
}

void DisplayEidt1(HWND hWnd)
{
    int i = 0;
    FILE* pf = fopen("缓冲.txt", "r");
    if (pf == NULL)
    {
        assert(pf != NULL);
    }
    char tmp ;
    Queue qWrite;
    pQWchar = &qWrite;
    QueueInit(&qWrite);
    while ((tmp = fgetc(pf)) != '\0' && tmp != EOF )
    {
        if (tmp == '\n')
        {
            QueuePushBack(&qWrite, '\r');
            QueuePushBack(&qWrite, '\n');
        }
        else
            QueuePushBack(&qWrite, tmp);
    }
    if(tmp=='\0'||tmp == EOF)
        QueuePushBack(&qWrite, '\0');
    if (feof(pf))
    {
        if (ferror(pf))
        {
            assert(0);//printf("error\n");
        }
        else
            ;//printf("end of file\n");
    }
    if (pQWchar->size)
        SetDlgItemTextA(hWnd, EIDT_INPUT1, (pQWchar->array));
    else
    {
        assert(pQWchar->size);
    }
    QueueDestory(pQWchar);
    pQWchar = NULL;
    fclose(pf);
    pf = NULL;
}
//子窗口
void PartButtonWnd(HWND hWnd, HINSTANCE hInstance)
{
    int i = 0;
    RECT rect;
    LPRECT lprect = &rect;
    GetWindowRect(hWnd, lprect);//是相对系统的位置
    int j = 0;
    int k = 10;
    int tmp = 0;
    for (i = 0; i < BUTTONNUM - 1; ++i)
    {
        if (i * 150 + 30 + 100 > rect.right)
        {
            j++;//换行
            k = i;
        }//防止过多超出
        arrHwndChildButton[i] = CreateWindowExA(0, "BUTTON", ButtonsClass.pText,
             ButtonsClass.dWstyle,
            (i % k) * 150 + 30, 250 + 80 * j, 100, 50,
            hWnd, (HMENU)(1000 + i), hInstance, NULL); 
        SendDlgItemMessage(hWnd, IDC_PUSHBUTTON1 + i, BM_SETIMAGE, IMAGE_BITMAP,
            (LPARAM)LoadBitmap(hInst, MAKEINTRESOURCE(IDB_BITMAP1 + i)));
        //LoadImage()可以加载icon和bmp，设置大小

        ShowWindow(arrHwndChildButton[i], SW_SHOWNORMAL);
        UpdateWindow(arrHwndChildButton[i]);
    }
    arrHwndChildButton[i] = CreateWindowExA(0, "BUTTON", ButtonsClass.pText,
        ButtonsClass.dWstyle,
        i * 150 + 30, 250 + 80 * j, 100, 50,
        hWnd, (HMENU)(1000 + 9), hInstance, NULL);
    SendDlgItemMessage(hWnd, IDC_CIALLOBUTTON, BM_SETIMAGE, IMAGE_BITMAP,
        (LPARAM)LoadBitmap(hInst, MAKEINTRESOURCE(IDB_BITMAP9)));
    ShowWindow(arrHwndChildButton[i], SW_SHOWNORMAL);
    UpdateWindow(arrHwndChildButton[i]);
}
void PartEditWnd(HWND hWnd, HINSTANCE hInstance)
{
    RECT rect;
    LPRECT lprect = &rect;
    GetClientRect(hWnd, lprect);//是相对窗口的位置
    arrHwndEdit[0] = CreateWindowExA(0 ,"EDIT", "健身俱乐部管理系统:{显示窗口}",
        WS_BORDER | WS_CHILD | WS_VISIBLE|WS_TABSTOP | WS_VSCROLL | ES_LEFT |
        ES_MULTILINE | ES_AUTOVSCROLL  | ES_WANTRETURN | ES_READONLY,
        10, 10, rect.right-10, 200,
        hWnd, (HMENU)(EIDT_INPUT1), hInstance, NULL);
    ShowWindow(arrHwndEdit[0], SW_SHOWNORMAL);
    UpdateWindow(arrHwndEdit[0]);
}
void CreateSearchEdit(HWND hWnd)
{
    RECT rect;
    LPRECT lprect = &rect;
    GetClientRect(hWnd, lprect);
    arrHwndEdit[1] = CreateWindowExA(0, "EDIT", "请输入查找人的名字:",
        WS_BORDER | WS_CHILD | WS_VISIBLE|WS_TABSTOP | WS_VSCROLL | ES_LEFT |
        ES_MULTILINE | ES_AUTOVSCROLL,
        10, 400, rect.right - 10, 200,
        hWnd, (HMENU)(1000 + 11), hInst, NULL);
    ShowWindow(arrHwndEdit[1], SW_SHOWNORMAL);
    UpdateWindow(arrHwndEdit[1]);
}
void AllChildDestroy(HWND hWnd)//清屏
{
    HWND hChildWnd;
    while (hChildWnd = FindWindowExA(hWnd, NULL, "BUtton", NULL))
    {
        DestroyWindow(hChildWnd);
    }
    while (hChildWnd = FindWindowExA(hWnd, NULL, "EDIT", NULL))
    {
        DestroyWindow(hChildWnd);
    }
}

//录入处理
void AddEditCreat(HWND hWnd)
{
    RECT rect;
    LPRECT lprect = &rect;
    GetClientRect(hWnd, lprect);
    rect.right /= 2;
    rect.right -= 200;
    if (rect.right < 0)
        rect.right = 0;
    char editName[6][21] = { "会员号(不输入)","名字","年龄","性别","电话","地址" };
    int editStyle[6] = { ES_READONLY ,ES_LEFT,ES_NUMBER ,ES_LEFT ,ES_NUMBER ,ES_LEFT };
    int i = 0;
    for (i = 2; i < 8; ++i)
    {
        arrHwndEdit[i] = CreateWindowExA(0, "EDIT", editName[i - 2],
            WS_BORDER | WS_CHILD | WS_VISIBLE | WS_TABSTOP | ES_LEFT | editStyle[i - 2],
            rect.right, 10 + 40 * (i - 2), 400, 25,
            hWnd, (HMENU)(1000 + 10 + i), hInst, NULL);
    }
    arrHwndEdit[8] = CreateWindowExA(0, "EDIT", "办理日期",
        WS_BORDER | WS_CHILD | WS_VISIBLE | WS_TABSTOP | ES_RIGHT | ES_NUMBER,
        rect.right, 10 + 40 * (8 - 2), 100, 25,
        hWnd, (HMENU)(1000 + 10 + 8), hInst, NULL);
    arrHwndYear[0] = CreateWindowExA(0, "EDIT", "年",
        WS_BORDER | WS_CHILD | WS_VISIBLE | WS_TABSTOP | ES_READONLY | ES_CENTER | WS_DISABLED,
        rect.right + 100, 10 + 40 * (8 - 2), 30, 25,
        hWnd, NULL, hInst, NULL);
    arrHwndEdit[9] = CreateWindowExA(0, "EDIT", NULL,
        WS_BORDER | WS_CHILD | WS_VISIBLE | WS_TABSTOP | ES_RIGHT | ES_NUMBER,
        rect.right + 130, 10 + 40 * (8 - 2), 100, 25,
        hWnd, (HMENU)(1000 + 10 + 9), hInst, NULL);
    arrHwndYear[1] = CreateWindowExA(0, "EDIT", "月",
        WS_BORDER | WS_CHILD | WS_VISIBLE | WS_TABSTOP | ES_READONLY | ES_CENTER | WS_DISABLED,
        rect.right + 230, 10 + 40 * (8 - 2), 30, 25,
        hWnd, NULL, hInst, NULL);
    arrHwndEdit[10] = CreateWindowExA(0, "EDIT", NULL,
        WS_BORDER | WS_CHILD | WS_VISIBLE | WS_TABSTOP | ES_RIGHT | ES_NUMBER,
        rect.right + 260, 10 + 40 * (8 - 2), 100, 25,
        hWnd, (HMENU)(1000 + 10 + 10), hInst, NULL);
    arrHwndYear[2] = CreateWindowExA(0, "EDIT", "日",
        WS_BORDER | WS_CHILD | WS_VISIBLE | WS_TABSTOP | ES_READONLY | ES_CENTER | WS_DISABLED,
        rect.right + 360, 10 + 40 * (8 - 2), 30, 25,
        hWnd, NULL, hInst, NULL);

    arrHwndEdit[11] = CreateWindowExA(0, "EDIT", "有效日期",
        WS_BORDER | WS_CHILD | WS_VISIBLE | WS_TABSTOP | ES_RIGHT | ES_NUMBER,
        rect.right, 10 + 40 * (9 - 2), 100, 25,
        hWnd, (HMENU)(1000 + 10 + 11), hInst, NULL);
    arrHwndYear[3] = CreateWindowExA(0, "EDIT", "年",
        WS_BORDER | WS_CHILD | WS_VISIBLE | WS_TABSTOP | ES_READONLY | ES_CENTER | WS_DISABLED,
        rect.right + 100, 10 + 40 * (9 - 2), 30, 25,
        hWnd, NULL, hInst, NULL);
    arrHwndEdit[12] = CreateWindowExA(0, "EDIT", NULL,
        WS_BORDER | WS_CHILD | WS_VISIBLE | WS_TABSTOP | ES_RIGHT | ES_NUMBER,
        rect.right + 130, 10 + 40 * (9 - 2), 100, 25,
        hWnd, (HMENU)(1000 + 10 + 12), hInst, NULL);
    arrHwndYear[4] = CreateWindowExA(0, "EDIT", "月",
        WS_BORDER | WS_CHILD | WS_VISIBLE | WS_TABSTOP | ES_READONLY | ES_CENTER | WS_DISABLED,
        rect.right + 230, 10 + 40 * (9 - 2), 30, 25,
        hWnd, NULL, hInst, NULL);
    arrHwndEdit[13] = CreateWindowExA(0, "EDIT", NULL,
        WS_BORDER | WS_CHILD | WS_VISIBLE | WS_TABSTOP | ES_RIGHT | ES_NUMBER,
        rect.right + 260, 10 + 40 * (9 - 2), 100, 25,
        hWnd, (HMENU)(1000 + 10 + 13), hInst, NULL);
    arrHwndYear[5] = CreateWindowExA(0, "EDIT", "日",
        WS_BORDER | WS_CHILD | WS_VISIBLE | WS_TABSTOP | ES_READONLY | ES_CENTER | WS_DISABLED,
        rect.right + 360, 10 + 40 * (9 - 2), 30, 25,
        hWnd, NULL, hInst, NULL);
    //两个按钮
    arrHwndChildButton[7] = CreateWindowExA(0, "BUTTON", ButtonsClass.pText,
        ButtonsClass.dWstyle,
        rect.right + 50, 10 + 40 * (10 - 2), 100, 50,
        hWnd, (HMENU)(1000 + 7), hInst, NULL);
    SendDlgItemMessage(hWnd, IDC_PUSHBUTTON1 + 7, BM_SETIMAGE, IMAGE_BITMAP,
        (LPARAM)LoadBitmap(hInst, MAKEINTRESOURCE(IDB_BITMAP7)));
    Button_Enable(arrHwndChildButton[7], FALSE);

    arrHwndChildButton[8] = CreateWindowExA(0, "BUTTON", ButtonsClass.pText,
        ButtonsClass.dWstyle,
        rect.right + 250, 10 + 40 * (10 - 2), 100, 50,
        hWnd, (HMENU)(1000 + 8), hInst, NULL);
    SendDlgItemMessage(hWnd, IDC_PUSHBUTTON1 + 8, BM_SETIMAGE, IMAGE_BITMAP,
        (LPARAM)LoadBitmap(hInst, MAKEINTRESOURCE(IDB_BITMAP8)));

    //限制输入
    Edit_LimitText(arrHwndEdit[4], 3);
    Edit_LimitText(arrHwndEdit[5], 2);
    Edit_LimitText(arrHwndEdit[6], 11);
    Edit_LimitText(arrHwndEdit[9], 2);
    Edit_LimitText(arrHwndEdit[10], 2);
    Edit_LimitText(arrHwndEdit[12], 2);
    Edit_LimitText(arrHwndEdit[13], 2);
}
void CheckIsInput(HWND hWnd)
{
    int i = 8;
    while (GetWindowTextLengthA(arrHwndEdit[i]) && i != 14)
    {
        i++;
    }
    if (14 == i)
    {
        char tmp[10];
        int inttmp;
        int day[3];
        int i = 0;
        for (i = 0; i < 3; ++i)
        {
            GetWindowTextA(arrHwndEdit[8 + i], tmp, 50);
            sscanf(tmp, "%d", &inttmp);
            day[i] = inttmp;
        }
        inttmp = day[2] + day[1] * 100 + day[0] * 10000;
        sprintf(tmp, "%d", inttmp);
        SetDlgItemTextA(hWnd, EIDT_INPUT3, tmp);
    }
    i = 2;
    while (GetWindowTextLengthA(arrHwndEdit[i]) && i != 14)
    {
        i++;
    }
    if (i == 14)
    {
        Button_Enable(arrHwndChildButton[7], TRUE);
    }
}

//
//  函数: MyRegisterClass()
//
//  目标: 注册窗口类。
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEX wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, IDI_SHIELD);
    wcex.hCursor        = LoadCursor(NULL, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = IDI_SHIELD;//MAKEINTRESOURCEW(IDC_MY)
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassEx(&wcex);
}

//
//   函数: InitInstance(HINSTANCE, int)
//
//   目标: 保存实例句柄并创建主窗口
//
//   注释:
//
//        在此函数中，我们在全局变量中保存实例句柄并
//        创建和显示主程序窗口。
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // 将实例句柄存储在全局变量中

   HWND hWnd = CreateWindowEx(0, szWindowClass, szTitle, WS_OVERLAPPEDWINDOW | WS_VISIBLE,
       CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, NULL, NULL, hInstance, NULL);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

//
//  函数: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  目标: 处理主窗口的消息。
//
//  WM_COMMAND  - 处理应用程序菜单
//  WM_PAINT    - 绘制主窗口
//  WM_DESTROY  - 发送退出消息并返回
//
//
int j = 0;//删除计数按两下
int k = 0;//修改计数按两下
int isModify = 0;
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    int i = 0;  
    //文本清屏
    FILE* pf;
    //背景
    RECT rect;
    RECT rectTmp;
    LPRECT lprect = &rect;
    GetClientRect(hWnd, lprect);//是相对窗口的位置
    const COLORREF rgbblue = RGB(159,252,253);

    switch (message)
    {
    case WM_CREATE:
        PartButtonWnd(hWnd, hInst);
        PartEditWnd(hWnd, hInst);
        break;
    case WM_SIZE://调整子窗口大小
        rectTmp = rect;
        rectTmp.left = 10;
        rectTmp.top = 10;
        rectTmp.bottom = 200;
        MoveWindow(arrHwndEdit[0], 10, 10, rectTmp.right - 10, 200, TRUE);
        rect.right /= 2;//居中
        rect.right -= 200;
        if (rect.right < 0)
            rect.right = 0;
        for (i = 2; i < 8; ++i)
            MoveWindow(arrHwndEdit[i], rect.right, 10 + 40 * (i-2), 400, 25, TRUE);
        //调整年月日窗口
        MoveWindow(arrHwndEdit[8], rect.right, 10 + 40 * (8 - 2), 100, 25, TRUE);
        MoveWindow(arrHwndEdit[9], rect.right + 130, 10 + 40 * (8 - 2), 100, 25, TRUE);
        MoveWindow(arrHwndEdit[10], rect.right + 260, 10 + 40 * (8 - 2), 100, 25, TRUE);
        MoveWindow(arrHwndEdit[11], rect.right, 10 + 40 * (9 - 2), 100, 25, TRUE);
        MoveWindow(arrHwndEdit[12], rect.right + 130, 10 + 40 * (9 - 2), 100, 25, TRUE);
        MoveWindow(arrHwndEdit[13], rect.right + 260, 10 + 40 * (9 - 2), 100, 25, TRUE);
        MoveWindow(arrHwndYear[0], rect.right+100, 10 + 40 * (8 - 2), 30, 25, TRUE);
        MoveWindow(arrHwndYear[1], rect.right + 230, 10 + 40 * (8 - 2), 30, 25, TRUE);
        MoveWindow(arrHwndYear[2], rect.right + 360, 10 + 40 * (8 - 2), 30, 25, TRUE);
        MoveWindow(arrHwndYear[3], rect.right+100, 10 + 40 * (9 - 2), 30, 25, TRUE);
        MoveWindow(arrHwndYear[4], rect.right + 230, 10 + 40 * (9 - 2), 30, 25, TRUE);
        MoveWindow(arrHwndYear[5], rect.right + 360, 10 + 40 * (9 - 2), 30, 25, TRUE);

        break;
    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
            // 分析菜单选择:
            switch (wmId)
            {
            case IDC_PUSHBUTTON1://浏览
                pf = fopen("缓冲.txt", "w");//清屏
                fclose(pf);
                pf = NULL;
                ShowContact(pCon);
                DisplayEidt1(hWnd); 
                break;
            case IDC_PUSHBUTTON2://查询或删除
                if (0 == j)
                {
                    DestroyWindow(arrHwndEdit[1]);
                    CreateSearchEdit(hWnd);
                    SendDlgItemMessage(hWnd, IDC_PUSHBUTTON2, BM_SETIMAGE, IMAGE_BITMAP,
                        (LPARAM)LoadBitmap(hInst, MAKEINTRESOURCE(IDB_BITMAP7)));
                    if (k == 1)
                    {
                        SendDlgItemMessage(hWnd, IDC_PUSHBUTTON5, BM_SETIMAGE, IMAGE_BITMAP,
                            (LPARAM)LoadBitmap(hInst, MAKEINTRESOURCE(IDB_BITMAP5)));//防止冲突
                        k = 0;
                    }
                    j = 1;
                }
                else
                {
                    if (1 == SearchContact(pCon, hWnd, arrHwndEdit))
                    {
                        i = MessageBoxW(hWnd, L"是否删除", L"提示", MB_YESNO);
                        if (6 == i)
                        {
                            DelContact(pCon);
                            SetDlgItemTextA(hWnd, EIDT_INPUT2, "删除成功");
                        }
                        j = 0;
                        SendDlgItemMessage(hWnd, IDC_PUSHBUTTON2, BM_SETIMAGE, IMAGE_BITMAP,
                            (LPARAM)LoadBitmap(hInst, MAKEINTRESOURCE(IDB_BITMAP2)));
                    }
                }
                break;
            case IDC_PUSHBUTTON3://添加
                AllChildDestroy(hWnd);
                AddEditCreat(hWnd);
                break;
            case IDC_PUSHBUTTON4://排序
                pf = fopen("缓冲.txt", "w");//清屏
                fclose(pf);
                pf = NULL;
                SortContact(pCon);
                DisplayEidt1(hWnd);
                break;
            case IDC_PUSHBUTTON5://查询或修改
                if (0 == k)
                {
                    DestroyWindow(arrHwndEdit[1]);
                    CreateSearchEdit(hWnd);
                    SendDlgItemMessage(hWnd, IDC_PUSHBUTTON5, BM_SETIMAGE, IMAGE_BITMAP,
                        (LPARAM)LoadBitmap(hInst, MAKEINTRESOURCE(IDB_BITMAP7)));
                    if (j == 1)
                    {
                        SendDlgItemMessage(hWnd, IDC_PUSHBUTTON2, BM_SETIMAGE, IMAGE_BITMAP,
                            (LPARAM)LoadBitmap(hInst, MAKEINTRESOURCE(IDB_BITMAP2)));//防止冲突
                        j = 0;
                    }
                    k = 1;
                }
                else
                {
                    if (1 == SearchContact(pCon, hWnd, arrHwndEdit))
                    {
                        i = MessageBoxW(hWnd, L"是否修改", L"提示", MB_YESNO);
                        if (6 == i)
                        {
                            AllChildDestroy(hWnd);
                            AddEditCreat(hWnd);
                            ModifyDisplayContact(pCon, arrHwndEdit);
                            isModify = 1;
                        } 
                        k = 0;
                        SendDlgItemMessage(hWnd, IDC_PUSHBUTTON5, BM_SETIMAGE, IMAGE_BITMAP,
                            (LPARAM)LoadBitmap(hInst, MAKEINTRESOURCE(IDB_BITMAP5)));
                    }
                }
                break;
            case IDC_PUSHBUTTON6://保存
                pf = fopen("缓冲.txt", "w");//清屏
                fclose(pf);
                pf = NULL;
                SaveContact(pCon);
                DisplayEidt1(hWnd);
                break;
            case IDC_PUSHBUTTON7://会员号排序
                pf = fopen("缓冲.txt", "w");//清屏
                fclose(pf);
                pf = NULL;
                SortByAvltree(pCon);
                DisplayEidt1(hWnd);
                break;
            case IDC_PUSHBUTTON8://录入时确认或修改时确认
                if (0 == isModify)
                {
                    AddContact(pCon, arrHwndEdit);
                    MessageBoxW(hWnd, L"添加成功", L"提示", NULL);
                }
                else
                {
                    ModifyAddContact(pCon, arrHwndEdit);
                    MessageBoxW(hWnd, L"修改成功", L"提示", NULL);
                    isModify = 0;
                }
                AllChildDestroy(hWnd);
                PartButtonWnd(hWnd, hInst);
                PartEditWnd(hWnd, hInst);
                DisplayEidt1(hWnd);
                break;
            case IDC_PUSHBUTTON9://录入时取消
                AllChildDestroy(hWnd);
                PartButtonWnd(hWnd, hInst);
                PartEditWnd(hWnd, hInst);
                DisplayEidt1(hWnd);
                break;
            case IDC_CIALLOBUTTON:
                PlaySoundW(MAKEINTRESOURCE(IDR_WAVE1), hInst, SND_RESOURCE | SND_ASYNC);
                break;
            case EIDT_INPUT4:
            case EIDT_INPUT5:
            case EIDT_INPUT6:
            case EIDT_INPUT7:
            case EIDT_INPUT8:
            case EIDT_INPUT9:
            case EIDT_INPUT10:
            case EIDT_INPUT11:
            case EIDT_INPUT12:
            case EIDT_INPUT13:
            case EIDT_INPUT15:
                CheckIsInput(hWnd);
                break;
            case IDM_ABOUT:
                DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
                break;
            case IDM_EXIT:
                DestroyWindow(hWnd);
                break;
            default:
                return DefWindowProc(hWnd, message, wParam, lParam);
            }
        }
        break;
    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);
            // TODO: 在此处添加使用 hdc 的任何绘图代码...
            SelectObject(hdc, GetStockObject(DC_BRUSH));
            SetDCBrushColor(hdc, rgbblue);
            lprect = &rect;
            Rectangle(hdc, 0, 0, rect.right, rect.bottom);
            EndPaint(hWnd, &ps);
        }
        break;
    case WM_CLOSE:
        i = MessageBoxW(hWnd, L"是否保存", L"提示", MB_YESNO);
        if (6 == i)
        {
            pf = fopen("缓冲.txt", "w");//清屏
            fclose(pf);
            pf = NULL;
            SaveContact(pCon);
            DisplayEidt1(hWnd);
        }
        PostQuitMessage(0);
        break;
    case WM_DESTROY:
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

// “关于”框的消息处理程序。
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}
