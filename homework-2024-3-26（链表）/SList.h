#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>

typedef int ListDateType;
//结点 （节点）
typedef struct SlistNode
{
	ListDateType date;
	struct SlistNode* next;
}SLTNode;

//struct SList
//{
//	struct SList* head;
//	struct SList* tail;
//};
void SListPushBack(SLTNode** pphead, ListDateType x);
void SListPopBack(SLTNode** pphead);
void SListPushFront(SLTNode** pphead, ListDateType x);
void SListPopFront(SLTNode** pphead);

void SListInsertAfter(SLTNode* pos, ListDateType x);
void SListEraseAfter(SLTNode* phead);
SLTNode* SListFind(SLTNode* phead, ListDateType x);

void SListPrint(SLTNode* phead);
int SListSize(SLTNode* phead);

void SListDestory(SLTNode** pphead);