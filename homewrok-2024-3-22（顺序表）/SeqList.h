#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <assert.h>

//顺序表，有效数组在数组中必须是连续的
//静态顺序表设计(固定大小)
typedef int SLDateType;
#define N 10

//victor
//typedef struct SeqList
//{
//	SLDateType a[N];
//	int size;
//}SeqList;

//动态顺序表设计(大小可变)
typedef struct SeqList
{
	SLDateType* array;
	size_t size;//个数
	size_t capicity;//容量
}SeqList,SL;

void SeqListInit(SL* ps);
void SeqListPrint(SL* ps);
//尾插尾删 头插头删
void SeqListPushBack(SL* ps, SLDateType x);
void SeqListPopBack(SL* ps);
void SeqListPushFront(SL* ps, SLDateType x);
void SeqListPopFront(SL* ps);
//任意位置插入删除
void SeqListInsert(SL* ps,int pos, SLDateType x);
void SeqListErase(SL* ps, int pos);
//顺序表查找
int SeqListFind(SL* ps1, SLDateType x);
//返回一共几个
void SeqListSort(SL* ps1);
int SeqListBinaryFind(SL* ps1, SLDateType x);
//返回找到的下标

//销毁
void SeqListDestory(SL* ps);