#define _CRT_SECURE_NO_WARNINGS 1
#include "E:/vsc����/mine.h"

void* my_memcpy(void* dest, const void* src, size_t num)
{
	assert(dest && src);
	void* ret = dest;
	char* a1 = (char*)dest;
	char* a2 = (char*)src;
	while (num)
	{
		*a1++ = *a2++;
		num--;
	}
	return ret;
}
struct s
{
	char name[20];
	int age;
};
//int main()
// {
//	//�ڴ溯��
//	int arr1[] = { 1,2,3,4,5 };
//	int arr2[5] = { 0 };
//	struct s arr3[] = {{"����",20},{"����",30}};
//	struct s arr4[3] = { 0 };
//	//strcpy(arr2, arr1);
//	my_memcpy(arr4, arr3, sizeof(arr3));
//	my_memcpy(arr2, arr1, sizeof(arr1));
//	Print(arr2, sizeof(arr1)/sizeof(arr1[0]), "%d");
//	return 0;
//}
//memmove//�����ص�
//C���Թ涨
//memcpyֻҪ�����ص��Ŀ���
void* my_memmove(void* dest, const void* src, size_t num)
{
	assert(dest && src);
	void* ret = dest;
	char* a1 = (char*)dest;
	char* a2 = (char*)src;
	if(a2<a1)
	{
		a1 += num-1;
		a2 += num-1;
		while (num)
		{
			*a1-- = *a2--;
			num--;
		}
	}
	else if (a2 > a1)
	{
		while (num)
		{
			*a1++ = *a2++;
			num--;
		}
	}
	return ret;
}
int main()
{
	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
	my_memmove(arr + 2, arr, 20);
	//memcpy(arr + 2, arr, 20);
	//my_memcpy(arr + 2, arr, 20);
	Print(arr, sizeof(arr) / sizeof(arr[0]), "%d");
	return 0;
}