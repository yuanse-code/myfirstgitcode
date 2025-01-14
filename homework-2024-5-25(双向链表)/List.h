#pragma once
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>

typedef int LTDateType;

typedef struct ListNode
{
	struct ListNode* prev;
	struct listNode* next;
	LTDateType data;
}ListNode;

void ListInit(ListNode** pphead);
void ListClear(ListNode* phead);
void ListDestory(ListNode** pphead);
void ListPrint(ListNode* phead);

void ListPushBack(ListNode* phead, LTDateType x);
void ListPopBack(ListNode* phead);
void ListPushFront(ListNode* phead, LTDateType x);
void ListPopFront(ListNode* phead);

ListNode* ListFind(ListNode* phead, LTDateType x);
//在pos前面插入
void ListInster(ListNode* pos, LTDateType x);
void ListErase(ListNode* pos);