#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <assert.h>


//����Ԫ��
typedef struct Unknown
{
	char u;
	int exponent;
}Unknown;
//˳�����Ч�����������б�����������
//��̬˳������(�̶���С)

//#define N 10
//victor
//typedef struct SeqList
//{
//	Unknown* a[N];
//	int size;
//}SeqList;

//��̬˳������(��С�ɱ�)
typedef struct SeqList
{
	Unknown** array;
	size_t size;//����
	size_t capicity;//����
}SeqList,SL;

//������
typedef struct EquationList
{
	struct SeqList** equationarr;
	size_t size;
	size_t capicity;
}EquationList;

void SeqListInit(SL* ps);
void SeqListPrint(SL* ps);
//β��βɾ ͷ��ͷɾ
void SeqListPushBack(SL* ps, Unknown* x);
void SeqListPopBack(SL* ps);
void SeqListPushFront(SL* ps, Unknown* x);
void SeqListPopFront(SL* ps);
//����λ�ò���ɾ��
void SeqListInsert(SL* ps,int pos, Unknown* x);
void SeqListErase(SL* ps, int pos);
//˳������
int SeqListFind(SL* ps1, Unknown* x);
//����һ������
void SeqListSort(SL* ps1);
int SeqListBinaryFind(SL* ps1, Unknown* x);
//�����ҵ����±�

//����
void SeqListDestory(SL* ps);

void EquationListInit(EquationList* ps);
void EquationListPrint(EquationList* ps);
//β��βɾ ͷ��ͷɾ
void EquationListPushBack(EquationList* ps, SeqList* x);
void EquationListPopBack(EquationList* ps);
void EquationListPushFront(EquationList* ps, SeqList* x);
void EquationListPopFront(EquationList* ps);
//����λ�ò���ɾ��
void EquationListInsert(EquationList* ps, int pos, SeqList* x);
void EquationListErase(EquationList* ps, int pos);
//˳������
int EquationListFind(EquationList* ps1, SeqList* x);
//����һ������
void EquationListSort(EquationList* ps1);
int EquationListBinaryFind(EquationList* ps1, SeqList* x);
//�����ҵ����±�

//����
void EquationListDestory(EquationList* ps);