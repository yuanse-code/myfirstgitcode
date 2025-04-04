#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include <Windows.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <errno.h>

#define DEFAULT_SZ 3
#define MAX_NAME 20
#define MAX_SEX 5
#define MAX_TALE 12
#define MAX_ADDR 30

typedef struct PeoInfo
{
	int vipNum;
	char name[MAX_NAME];
	int age;
	char sex[MAX_SEX];
	char tale[MAX_TALE];
	char addr[MAX_ADDR];
	int makeDay;
	int lastDay;
}PeoInfo;
typedef struct Contact
{
	int size;
	struct PeoInfo* date;
	int capacity;
}Contact;
//初始化通讯录
void InitContact(Contact* ps);
//增加
void AddContact(Contact* ps, HWND* arrHwndEdit);
//打印
void ShowContact(const Contact* ps);
//删除
void DelContact(Contact* ps);
//查找
int SearchContact(const struct Contact* ps, HWND hWnd, HWND* arrHwndEdit);
//修改
void ModifyDisplayContact(Contact* ps, HWND* arrHwndEdit);
void ModifyAddContact(Contact* ps, HWND* arrHwndEdit);
//排序
void SortContact(Contact* ps);
void SortByAvltree(Contact* ps);
//存储
void SaveContact(Contact* ps);
//加载文件中的信息到通讯录
void LoadContact(Contact* ps);