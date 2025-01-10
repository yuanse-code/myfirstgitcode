#include "Slist.h"

void SListPrint(SLTNode* phead)
{
	SLTNode* cur = phead;
	while (cur)
	{
		printf("%d->", cur->date);
		cur = cur->next;
	}
	printf("NULL\n");
}
int SListSize(SLTNode* phead)
{
	int size = 0;
	while (phead)
	{
		phead = phead->next;
		size++;
	}
	return size;
}
static SLTNode* BuySlistNode(ListDateType x)
{
	SLTNode* newNode = (SLTNode*)malloc(sizeof(SLTNode) * 1);
	if (newNode==NULL)
	{
		printf("%s\n", strerror(errno));
		exit(-1);
	}
	newNode->date = x;
	newNode->next = NULL;
	return newNode;
}
void SListPushBack(SLTNode** pphead, ListDateType x)
{
	if (*pphead == NULL)
	{
		*pphead=BuySlistNode(x);
	}
	else
	{
		SLTNode* tail = *pphead;
		//找尾
		while (tail->next != NULL)
		{
			tail = tail->next;
		}
		tail->next = BuySlistNode(x);
	}
}
void SListPopBack(SLTNode** pphead)
{
	//1.空
	//2.一个
	//3.一个以上
	if (*pphead == NULL)
	{
		return;
	}
	else if ((*pphead)->next == NULL)
	{
		free(*pphead);
		*pphead = NULL;
	}
	else
	{
		SLTNode* tail = *pphead;
		SLTNode* prev = *pphead;
		while (tail->next)
		{
			prev = tail;
			tail = tail->next;
		}
		free(tail);
		prev->next = NULL;
	}
}
void SListPushFront(SLTNode** pphead, ListDateType x)
{
	SLTNode* tmp = *pphead;
	*pphead = BuySlistNode(x);
	(*pphead)->next = tmp;
}
void SListPopFront(SLTNode** pphead)
{
	//1.空
	//2.一个节点+3.一个以上
	if (*pphead == NULL)
	{
		return;
	}
	else
	{
		SLTNode* tmp = *pphead;
		(*pphead) = (*pphead)->next;
		free(tmp);
	}
}
void SListInsertAfter(SLTNode* pos, ListDateType x)
{
	assert(pos);
	SLTNode* newnode = BuySlistNode(x);
	newnode->next = pos->next;
	pos->next = newnode;
}
void SListEraseAfter(SLTNode* pos)
{
	assert(pos);
	if (pos->next)
	{
		SLTNode* next = pos->next;
		SLTNode* nextnext = next->next;
		pos->next = nextnext;
		free(next);
	}
}
SLTNode* SListFind(SLTNode* phead, ListDateType x)
{
	while (phead)
	{
		if (phead->date == x)
		{
			return phead;
		}
		phead = phead->next;
	}
	return NULL;
}

void SListDestory(SLTNode** pphead)
{
	SLTNode* cur = *pphead;
	SLTNode* prev = *pphead;
	while (cur)
	{
		prev = cur->next;
		cur->next = NULL;
		free(cur);
		cur = prev;
	}
	*pphead = NULL;
}