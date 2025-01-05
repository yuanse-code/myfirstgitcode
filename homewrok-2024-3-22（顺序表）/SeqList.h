#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <assert.h>

//˳�����Ч�����������б�����������
//��̬˳������(�̶���С)
typedef int SLDateType;
#define N 10

//victor
//typedef struct SeqList
//{
//	SLDateType a[N];
//	int size;
//}SeqList;

//��̬˳������(��С�ɱ�)
typedef struct SeqList
{
	SLDateType* array;
	size_t size;//����
	size_t capicity;//����
}SeqList,SL;

void SeqListInit(SL* ps);
void SeqListPrint(SL* ps);
//β��βɾ ͷ��ͷɾ
void SeqListPushBack(SL* ps, SLDateType x);
void SeqListPopBack(SL* ps);
void SeqListPushFront(SL* ps, SLDateType x);
void SeqListPopFront(SL* ps);
//����λ�ò���ɾ��
void SeqListInsert(SL* ps,int pos, SLDateType x);
void SeqListErase(SL* ps, int pos);
//˳������
int SeqListFind(SL* ps1, SLDateType x);
//����һ������
void SeqListSort(SL* ps1);
int SeqListBinaryFind(SL* ps1, SLDateType x);
//�����ҵ����±�

//����
void SeqListDestory(SL* ps);