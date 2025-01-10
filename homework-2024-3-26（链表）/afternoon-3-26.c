#include "Slist.h"

int  main()
{
	//SLTNode* phead = NULL;
	SLTNode* pList = NULL;
	//...

	SListPushBack(&pList, 1);
	SListPushBack(&pList, 2);
	SListPushBack(&pList, 3);
	SListPushBack(&pList, 4);

	SListPrint(pList);

	SListPopBack(&pList);

	SListPrint(pList);

	SListPushFront(&pList,1);
	SListPushFront(&pList, 2);
	SListPushFront(&pList, 3);

	SListPrint(pList);

	SListPopFront(&pList);

	SListPrint(pList);
	printf("%d\n", SListSize(pList));

	SLTNode* pos = SListFind(pList, 3);
	if (pos == NULL)
	{
		printf("Ã»ÕÒµ½\n");
	}
	else
	{
		pos->date = 30;
	}
	SListPrint(pList);

	SListDestory(&pList);
	return 0;
}