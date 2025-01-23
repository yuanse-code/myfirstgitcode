#include "Heap.h"

static void Swap(HPDataType* p1, HPDataType* p2)
{
	HPDataType tmp;
	tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}
//前提：左右子树都是小堆
static void AdjustDown(HPDataType* a, int n,int root)
{
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
void HeapInit(Heap* php, HPDataType* a, int n)
{
	php->_a = (HPDataType*)malloc(sizeof(HPDataType) * n);
	if (!php)//开辟失败
	{
		printf("%s", strerror(errno));
		return;
	}
	memcpy(php->_a, a, sizeof(HPDataType) * n);
	php->_size = n;
	php->_capacity = n;
	//构建堆
	for (int i = (n - 1 - 1) / 2; i >= 0; --i)
	{
		AdjustDown(php->_a, php->_size, i);
	}
}
void HeapDestory(Heap* php)
{
	assert(php);
	free(php->_a);
	php->_a = NULL;
	php->_capacity = php->_size = 0;
}

static void AdjustUp(HPDataType* a, int n,int child)
{
	assert(a);
	int parent = (child - 1) / 2;
	while (child > 0)
	{
		if (a[child] < a[parent])
		{
			Swap(&a[child], &a[parent]);
			//
			child = parent;
			parent = (child - 1) / 2;
		}
		else
			break;
	}
}
void HeapPush(Heap* php, HPDataType x)
{
	assert(php);
	if (php->_size == php->_capacity)
	{
		php->_a = (HPDataType*)realloc(php->_a, sizeof(HPDataType)*(php->_capacity * 2));
		if (!php->_a)
		{
			printf("%s\n", strerror(errno));
			return;
		}
		php->_capacity *= 2;
	}
	php->_a[php->_size++] = x;
	AdjustUp(php->_a, php->_size, php->_size - 1);
}

void HeapPop(Heap* php)
{
	assert(php);
	assert(php->_size);
	Swap(&(php->_a[0]), &(php->_a[php->_size - 1]));
	php->_size--;
	AdjustDown(php->_a, php->_size, 0);
}
HPDataType HeapTop(Heap* php)
{
	assert(php);
	assert(php->_size);
	return php->_a[0];
}