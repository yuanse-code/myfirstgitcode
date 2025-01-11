#define _CRT_SECURE_NO_WARNINGS 1
#include "SeqList.h"

void SeqListInit(SL* ps)
{
	/*ps->size = 0;
	ps->array = NULL;
	ps->capicity = 0;*/
	assert(ps);
	ps->array = (Unknown**)malloc(sizeof(Unknown*) * 4);
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
		printf("%p ", ps->array[i]);
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
		ptr = (Unknown**)
			realloc(ps->array, sizeof(Unknown*) * (ps->capicity));
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
void SeqListPushBack(SL* ps, Unknown* x)
{
	assert(ps);
	//���������Ҫ����
	IsAddCapicity(ps);
	ps->array[ps->size] = x;
	ps->size++;
}

void SeqListPopBack(SL* ps)
{
	assert(ps);
	ps->size--;
}
void SeqListPushFront(SL* ps, Unknown* x)
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

void SeqListInsert(SL* ps, int pos, Unknown* x)
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

int SeqListFind(SL* ps1, Unknown* x)
{
	assert(ps1);
	int i = 0;
	int sum = 0;
	for (i = 0; i < ps1->size; ++i)
	{
		if (x == ps1->array[i])
		{
			printf("�ҵ���,�±���%d\n", i);
			sum++;
		}
	}
	if (-1 == sum)
	{
		printf("û�ҵ�\n");
		return -1;
	}
	printf("һ����%d��\n", sum);
	return sum;
}
static int SLDateTypeCmp(void* vp1, void* vp2)
{
	if (*(Unknown**)vp1 - *(Unknown**)vp2 > 0)
		return 1;
	else if (*(Unknown**)vp1 - *(Unknown**)vp2 < 0)
		return -1;
	else
		return 0;
}
void SeqListSort(SL* ps1)
{
	assert(ps1);
	qsort(((Unknown*)(ps1->array))->u, ps1->size, sizeof(Unknown*), SLDateTypeCmp);
}
int SeqListBinaryFind(SL* ps1, Unknown* x)
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
//�����ҵ����±�,û�ҵ�����-1

void SeqListDestory(SL* ps)
{
	free(ps->array);
	ps->array = NULL;
	ps->size = ps->capicity = 0;
}