#define _CRT_SECURE_NO_WARNINGS 1
#include "SeqList.h"

void SeqListInit(SL* ps)
{
	/*ps->size = 0;
	ps->array = NULL;
	ps->capicity = 0;*/
	ps->array = (SLDateType*)malloc(sizeof(SLDateType) * 4);
	if (ps->array == NULL)
	{
		printf("%s\n", strerror(errno));
		exit(-1);
	}
	ps->size = 0;
	ps->capicity=4;
}
void SeqListPrint(SL* ps)
{
	assert(ps);
	int i = 0;
	for (i = 0; i < ps->size; ++i)
	{
		printf("%d ", ps->array[i]);
	}
	printf("\n");
}
static void IsAddCapicity(SL* ps)
{
	assert(ps);
	if (ps->size >= ps->capicity)
	{
		SL* ptr;
		ps->capicity *= 2;
		ptr = (SLDateType*)
			realloc(ps->array, sizeof(SLDateType) * (ps->capicity));
		if (ps->array == NULL)
		{
			printf("%s\n", strerror(errno));
			exit(-1);
		}
		else
		{
			ps->array = ptr;
		}
	}
}
void SeqListPushBack(SL* ps, SLDateType x)
{
	assert(ps);
	//如果满了需要增容
	IsAddCapicity(ps);
	ps->array[ps->size] = x;
	ps->size++;
}

void SeqListPopBack(SL* ps)
{
	assert(ps);
	ps->size--;
}
void SeqListPushFront(SL* ps, SLDateType x)
{
	assert(ps);
	IsAddCapicity(ps);
	int end = ps->size - 1;
	while (end>=0)
	{
		ps->array[end + 1] = ps->array[end];
		end--;
	}
	ps->array[0] = x;
	ps->size++;
}
void SeqListPopFront(SL* ps)
{
	assert(ps);
	int start = 0;
	while (start < ps->size - 1)
	{
		ps->array[start] = ps->array[start + 1];
		start++;
	}
	ps->size--;
}

void SeqListInsert(SL* ps, int pos, SLDateType x)
{
	assert(ps);
	if (pos < 0)
		pos = ps->size - pos - 1;
	assert(pos <= ps->size);
	IsAddCapicity(ps);
	int end = 0;
	for (end = ps->size - 1; end >= pos; --end)
	{
		ps->array[end + 1] = ps->array[end];
	}
	ps->array[pos] = x;
	ps->size++;
}
void SeqListErase(SL* ps, int pos)
{
	assert(ps);
	if (pos < 0)
		pos = ps->size - pos + 1;
	assert(pos < ps->size);
	IsAddCapicity(ps);
	int start = 0;
	for (start = pos; start < ps->size-1; ++start)
	{
		ps->array[start] = ps->array[start + 1];
	}
	ps->size--;
}

int SeqListFind(SL* ps1, SLDateType x)
{
	assert(ps1);
	int i = 0;
	int sum = 0;
	for (i = 0; i < ps1->size; ++i)
	{
		if (x == ps1->array[i])
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
	if (*(SLDateType*)vp1 - *(SLDateType*)vp2 > 0)
		return 1;
	else if (*(SLDateType*)vp1 - *(SLDateType*)vp2 < 0)
		return -1;
	else
		return 0;
}
void SeqListSort(SL* ps1)
{
	assert(ps1);
	qsort(ps1->array, ps1->size, sizeof(SLDateType), SLDateTypeCmp);
}
int SeqListBinaryFind(SL* ps1, SLDateType x)
{
	assert(ps1);
	int right = ps1->size-1;
	int left = 0;
	while (left < right)
	{
		if (ps1->array[(right + left) / 2] > x)
			right = (right + left) / 2;
		else if (ps1->array[(right + left) / 2] < x)
			left = (right + left) / 2 + 1;
		else
			return (right + left) / 2;
	}
	return -1;
}
//返回找到的下标,没找到返回-1

void SeqListDestory(SL* ps)
{
	free(ps->array);
	ps->array = NULL;
	ps->size = ps->capicity = 0;
}