#define _CRT_SECURE_NO_WARNINGS 1
#include "List.h"

void TestList1()
{
	ListNode* phead = NULL;
	ListInit(&phead);

	ListPushBack(phead, 1);
	ListPushBack(phead, 2);
	ListPushBack(phead, 3);
	ListPushBack(phead, 4);
	ListPrint(phead);

	ListPushFront(phead, 1);
	ListPushFront(phead, 2);
	ListPushFront(phead, 3);
	ListPushFront(phead, 4);
	ListPrint(phead);

	ListNode* pos = ListFind(phead, 3);
	ListInster(pos, 30);
	ListErase(pos);

	ListPrint(phead);
	ListDestory(&phead);
}
int main()
{
	TestList1();
	return 0;
}