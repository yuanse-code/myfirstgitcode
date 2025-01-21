#pragma once

#include "resource.h"
#pragma comment(lib, "winmm")//声音

#include <Windows.h>
#include <stdio.h>
#include <Mmsystem.h>
#include <windowsx.h>
#include <WinDef.h>
#include <tchar.h>
#include <strsafe.h>
#include <iostream>
#include <assert.h>
#include "Queue.h"//引用队列
#include "contact.h"//引用功能


//个数
#define BUTTONNUM                   8
#define AllBUTTONNUM				10
#define EDITNUM                     14
//按钮菜单
#define IDC_PUSHBUTTON1             1000//查看
#define IDC_PUSHBUTTON2             1001//查询或删除
#define IDC_PUSHBUTTON3             1002//录入
#define IDC_PUSHBUTTON4             1003//排序
#define IDC_PUSHBUTTON5             1004//修改
#define IDC_PUSHBUTTON6             1005//保存
#define IDC_PUSHBUTTON7             1006//会员号排序
#define IDC_PUSHBUTTON8             1007//确认
#define IDC_PUSHBUTTON9             1008//取消
#define IDC_CIALLOBUTTON            1009
//文本菜单
#define EIDT_INPUT1                 1010
#define EIDT_INPUT2                 1011
#define EIDT_INPUT3                 1012
#define EIDT_INPUT4                 1013
#define EIDT_INPUT5                 1014
#define EIDT_INPUT6                 1015
#define EIDT_INPUT7                 1016
#define EIDT_INPUT8                 1017
#define EIDT_INPUT9                 1018
#define EIDT_INPUT10                1019
#define EIDT_INPUT11                1020
#define EIDT_INPUT12                1021
#define EIDT_INPUT13                1022
#define EIDT_INPUT15                1023
//自定义消息
#define CHILDMODIFY WM_USER+10
