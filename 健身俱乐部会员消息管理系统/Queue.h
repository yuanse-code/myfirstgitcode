#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include <Windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <assert.h>


//˳�����Ч�����������б�����������
//��̬˳������(�̶���С)
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
	size_t size;//����
	size_t capicity;//����
}Queue;

//��ʼ��
void QueueInit(Queue* ps);
//β��ͷɾ
void QueuePushBack(Queue* ps, QueueDateType x);
void QueuePopFront(Queue* ps);

//����
void QueueDestory(Queue* ps);