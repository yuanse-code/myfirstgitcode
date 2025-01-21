#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include <Windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <assert.h>


//顺序表，有效数组在数组中必须是连续的
//静态顺序表设计(固定大小)
typedef char QueueDateType;
#define N 10

//victor
//typedef struct Queue
//{
//	QueueDateType a[N];
//	int size;
//}Queue;

typedef struct Queue
{
	QueueDateType* array;
	size_t size;//个数
	size_t capicity;//容量
}Queue;

//初始化
void QueueInit(Queue* ps);
//尾插头删
void QueuePushBack(Queue* ps, QueueDateType x);
void QueuePopFront(Queue* ps);

//销毁
void QueueDestory(Queue* ps);