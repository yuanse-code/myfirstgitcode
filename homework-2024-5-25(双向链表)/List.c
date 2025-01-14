#define _CRT_SECURE_NO_WARNINGS 1
#include "List.h"

static ListNode* BuyListNode(LTDateType x)
{
	ListNode* node = (ListNode*)malloc(sizeof(struct ListNode));
	assert(node);
	node->data = x;
	node->next = NULL;
	node->prev = NULL;
	return node;
}
void ListPushBack(ListNode* phead, LTDateType x)
{
	assert(phead);
	//ListNode* tail = phead->prev;
	//ListNode* newnode = BuyListNode(x);
	////phead......tail newnode
	//tail->next = newnode;
	//newnode->prev = tail;
	//phead->prev = newnode;
	//newnode->next = phead;
	ListInster(phead, x);
}
void ListPrint(ListNode* phead)
{
	assert(phead);
	ListNode* cur = phead->next;
	while(cur!=phead)
	{
		printf("%d ", cur->data);
		cur = cur->next;
	} 
	printf("\n");
}
void ListInit(ListNode** pphead)
{
	*pphead = BuyListNode(0);
	(*pphead)->next = *pphead;
	(*pphead)->prev = *pphead;
}
void ListPopBack(ListNode* phead)
{
	assert(phead);
	/*assert(phead != phead->prev);
	ListNode* tail = phead->prev;
	tail->prev->next = phead;
	phead->prev = tail->prev;
	free(tail);
	tail = NULL;*/
	ListErase(phead->prev);
}
void ListPushFront(ListNode* phead, LTDateType x)
{
	assert(phead);
	/*ListNode* first = phead->next;
	ListNode* newnode = BuyListNode(x);
	phead->next = newnode;
	newnode->prev = phead;
	newnode->next = first;
	first->prev = newnode;*/
	ListInster(phead->next, x);
}
void ListPopFront(ListNode* phead)
{
	assert(phead);
	//assert(phead != phead->next);
	//ListNode* first = phead->next;
	//ListNode* second = first->next;
	//phead->next = second;
	//second->prev = phead;
	//free(first);
	//first = NULL;
	ListErase(phead->next);
}
ListNode* ListFind(ListNode* phead, LTDateType x)
{
	assert(phead);
	ListNode* cur = phead->next;
	while (cur != phead)
	{
		if (cur->data == x)
			return cur;
		cur = cur->next;
	}
	return NULL;
}
void ListInster(ListNode* pos, LTDateType x)
{
	assert(pos);
	ListNode* posPrev = pos->prev;
	ListNode* newnode = BuyListNode(x);
	posPrev->next = newnode;
	newnode->prev = posPrev;
	newnode->next = pos;
	pos->prev = newnode;
}
void ListErase(ListNode* pos)
{
	assert(pos);
	assert(pos->next != pos);//有问题，可能链表不只剩一个
	ListNode* posPrev = pos->prev;
	ListNode* posNext = pos->next;
	free(pos);
	posPrev->next = posNext;
	posNext->prev = posPrev;
}
void ListClear(ListNode* phead)
{
	assert(phead);
	//清理所有数据节点，保留头节点
	ListNode* cur = phead->next;
	while (cur != phead)
	{
		ListNode* next = cur->next;
		free(cur);
		cur = next;
	}
	phead->next = phead;
	phead->prev = phead;
}
void ListDestory(ListNode** pphead)
{
	assert(pphead && *pphead);
	ListClear(*pphead);
	free(*pphead);
	*pphead = NULL;
}