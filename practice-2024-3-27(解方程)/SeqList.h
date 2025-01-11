#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <assert.h>


//方程元素
typedef struct Unknown
{
	char u;
	int exponent;
}Unknown;
//顺序表，有效数组在数组中必须是连续的
//静态顺序表设计(固定大小)

//#define N 10
//victor
//typedef struct SeqList
//{
//	Unknown* a[N];
//	int size;
//}SeqList;

//动态顺序表设计(大小可变)
typedef struct SeqList
{
	Unknown** array;
	size_t size;//个数
	size_t capicity;//容量
}SeqList,SL;

//方程组
typedef struct EquationList
{
	struct SeqList** equationarr;
	size_t size;
	size_t capicity;
}EquationList;

void SeqListInit(SL* ps);
void SeqListPrint(SL* ps);
//尾插尾删 头插头删
void SeqListPushBack(SL* ps, Unknown* x);
void SeqListPopBack(SL* ps);
void SeqListPushFront(SL* ps, Unknown* x);
void SeqListPopFront(SL* ps);
//任意位置插入删除
void SeqListInsert(SL* ps,int pos, Unknown* x);
void SeqListErase(SL* ps, int pos);
//顺序表查找
int SeqListFind(SL* ps1, Unknown* x);
//返回一共几个
void SeqListSort(SL* ps1);
int SeqListBinaryFind(SL* ps1, Unknown* x);
//返回找到的下标

//销毁
void SeqListDestory(SL* ps);

void EquationListInit(EquationList* ps);
void EquationListPrint(EquationList* ps);
//尾插尾删 头插头删
void EquationListPushBack(EquationList* ps, SeqList* x);
void EquationListPopBack(EquationList* ps);
void EquationListPushFront(EquationList* ps, SeqList* x);
void EquationListPopFront(EquationList* ps);
//任意位置插入删除
void EquationListInsert(EquationList* ps, int pos, SeqList* x);
void EquationListErase(EquationList* ps, int pos);
//顺序表查找
int EquationListFind(EquationList* ps1, SeqList* x);
//返回一共几个
void EquationListSort(EquationList* ps1);
int EquationListBinaryFind(EquationList* ps1, SeqList* x);
//返回找到的下标

//销毁
void EquationListDestory(EquationList* ps);