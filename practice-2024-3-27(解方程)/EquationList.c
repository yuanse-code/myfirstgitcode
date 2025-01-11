#define _CRT_SECURE_NO_WARNINGS 1
#include "SeqList.h"

void EquationListInit(EquationList* ps)
{
	/*ps->size = 0;
	ps->equationarr = NULL;
	ps->capicity = 0;*/
	assert(ps);
	ps->equationarr = (SeqList**)malloc(sizeof(SeqList*) * 4);
	if (ps->equationarr == NULL)
	{
		printf("%s\n", strerror(errno));
		exit(-1);
	}
	ps->size = 0;
	ps->capicity = 4;
}
void EquationListPrint(EquationList* ps)
{
	assert(ps);
	int i = 0;
	for (i = 0; i < ps->size; ++i)
	{
		printf("%p ", ps->equationarr[i]);
	}
	printf("\n");
}
static void IsAddCapicity(EquationList* ps)
{
	assert(ps);
	if (ps->size >= ps->capicity)
	{
		EquationList* ptr;
		ps->capicity *= 2;
		ptr = (SeqList**)
			realloc(ps->equationarr, sizeof(SeqList*) * (ps->capicity));
		if (ps->equationarr == NULL)
		{
			printf("%s\n", strerror(errno));
			exit(-1);
		}
		else
		{
			ps->equationarr = ptr;
		}
	}
}
void EquationListPushBack(EquationList* ps, SeqList* x)
{
	assert(ps);
	//如果满了需要增容
	IsAddCapicity(ps);
	ps->equationarr[ps->size] = x;
	ps->size++;
}

void EquationListPopBack(EquationList* ps)
{
	assert(ps);
	ps->size--;
}
void EquationListPushFront(EquationList* ps, SeqList* x)
{
	assert(ps);
	IsAddCapicity(ps);
	int end = ps->size - 1;
	while (end >= 0)
	{
		ps->equationarr[end + 1] = ps->equationarr[end];
		end--;
	}
	ps->equationarr[0] = x;
	ps->size++;
}
void EquationListPopFront(EquationList* ps)
{
	assert(ps);
	int start = 0;
	while (start < ps->size - 1)
	{
		ps->equationarr[start] = ps->equationarr[start + 1];
		start++;
	}
	ps->size--;
}

void EquationListInsert(EquationList* ps, int pos, SeqList* x)
{
	assert(ps);
	if (pos < 0)
		pos = ps->size - pos - 1;
	assert(pos <= ps->size);
	IsAddCapicity(ps);
	int end = 0;
	for (end = ps->size - 1; end >= pos; --end)
	{
		ps->equationarr[end + 1] = ps->equationarr[end];
	}
	ps->equationarr[pos] = x;
	ps->size++;
}
void EquationListErase(EquationList* ps, int pos)
{
	assert(ps);
	if (pos < 0)
		pos = ps->size - pos + 1;
	assert(pos < ps->size);
	IsAddCapicity(ps);
	int start = 0;
	for (start = pos; start < ps->size - 1; ++start)
	{
		ps->equationarr[start] = ps->equationarr[start + 1];
	}
	ps->size--;
}

int EquationListFind(EquationList* ps1, SeqList* x)
{
	assert(ps1);
	int i = 0;
	int sum = 0;
	for (i = 0; i < ps1->size; ++i)
	{
		if (x == ps1->equationarr[i])
		{
			printf("找到了,下标是%d\n", i);
			sum++;
		}
	}
	if (-1 == sum)
	{
		printf("没找到\n");
		return -1;
	}
	printf("一共有%d个\n", sum);
	return sum;
}
static int SLDateTypeCmp(void* vp1, void* vp2)
{
	if (*(SeqList**)vp1 - *(SeqList**)vp2 > 0)
		return 1;
	else if (*(SeqList**)vp1 - *(SeqList**)vp2 < 0)
		return -1;
	else
		return 0;
}
void EquationListSort(EquationList* ps1)
{
	assert(ps1);
	qsort(((Unknown*)(ps1->equationarr))->u, ps1->size, sizeof(SeqList*), SLDateTypeCmp);
}
int EquationListBinaryFind(EquationList* ps1, SeqList* x)
{
	assert(ps1);
	int right = ps1->size - 1;
	int left = 0;
	while (left < right)
	{
		if (ps1->equationarr[(right + left) / 2] > x)
			right = (right + left) / 2;
		else if (ps1->equationarr[(right + left) / 2] < x)
			left = (right + left) / 2 + 1;
		else
			return (right + left) / 2;
	}
	return -1;
}
//返回找到的下标,没找到返回-1

void EquationListDestory(EquationList* ps)
{
	free(ps->equationarr);
	ps->equationarr = NULL;
	ps->size = ps->capicity = 0;
}