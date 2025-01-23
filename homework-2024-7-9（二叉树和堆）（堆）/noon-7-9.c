#define  _CRT_SECURE_NO_WARNINGS 1

#include "Heap.h"
#include <stdio.h>

void Swap(HPDataType* p1, HPDataType* p2)
{
	HPDataType tmp;
	tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}
void AdjustDown(HPDataType* a, int n, int root)
{
	assert(a);
	int parent = root;
	int child = parent * 2 + 1;
	while (child < n)
	{
		//找出左右孩子中小的那一个
		if (child + 1 < n && a[child + 1] < a[child])
		{
			++child;
		}
		//如果孩子小于父亲则交换 
		if (a[child] < a[parent])
		{
			Swap(&a[child], &a[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
			break;
	}
}
void HeapSort(int* a, int n)
{
	assert(a);
	//1.建堆
	//for(int i=n-1;i>=0;--i)
	//时间复杂度？
	//如果为n-1，则为2(N)+2-log(N)
	//如果为（n-1-1）/2，则为(N)-log(N+1)
	int i = 0;
	for (i = (n - 1 - 1) / 2; i >= 0; --i)
	{
		AdjustDown(a, n, i);
	}
	int end = n - 1;
	while (end > 0)
	{
		Swap(&a[0], &a[end]);

		//再选次小的
		AdjustDown(a, end, 0);
		--end;
	}
}
int main()
{
	int a[] = { 27,15,19,18,28,34,65,49,25,37 };
	Heap hp;
	HeapInit(&hp, a, sizeof(a)/sizeof(HPDataType));
	//HeapSort(a, sizeof(a) / sizeof(HPDataType));//堆排序

	HeapPush(&hp, 13);
	HeapDestory(&hp);
	return 0;
}