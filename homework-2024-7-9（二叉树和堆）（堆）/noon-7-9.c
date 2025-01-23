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
		//�ҳ����Һ�����С����һ��
		if (child + 1 < n && a[child + 1] < a[child])
		{
			++child;
		}
		//�������С�ڸ����򽻻� 
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
	//1.����
	//for(int i=n-1;i>=0;--i)
	//ʱ�临�Ӷȣ�
	//���Ϊn-1����Ϊ2(N)+2-log(N)
	//���Ϊ��n-1-1��/2����Ϊ(N)-log(N+1)
	int i = 0;
	for (i = (n - 1 - 1) / 2; i >= 0; --i)
	{
		AdjustDown(a, n, i);
	}
	int end = n - 1;
	while (end > 0)
	{
		Swap(&a[0], &a[end]);

		//��ѡ��С��
		AdjustDown(a, end, 0);
		--end;
	}
}
int main()
{
	int a[] = { 27,15,19,18,28,34,65,49,25,37 };
	Heap hp;
	HeapInit(&hp, a, sizeof(a)/sizeof(HPDataType));
	//HeapSort(a, sizeof(a) / sizeof(HPDataType));//������

	HeapPush(&hp, 13);
	HeapDestory(&hp);
	return 0;
}