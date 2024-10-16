#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

//int main()
//{
//	//数组指针-指针
//	int arr[10] = { 1,2,3,4,5,6 };
//	int(*p)[10] = &arr;
//	int(**pa)[10] = &p;
//	char* p1[10];
//	char* (*pa)[10] = &p1;
//	return 0;
//}
void print1(int arr[3][5], int x, int y)
{
	int i = 0;
	int j = 0;
	for (i = 0;i < x;i++)
	{
		for (j = 0;j < y;j++)
		{
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
}
void print2(int(*p)[5], int x, int y)
{
	int i = 0;
	int j = 0;
	for (i = 0;i < x;i++)
	{ 
		for (j = 0;j < y;j++)
		{
			printf("%d ",*(*(p+i)+j));
		}
		printf("\n");
	}
}
int main()
{
	int arr[3][5] = { {1,2,3,4,5},{2,3,4,5,6},{3,4,5,6,7} };
	int arr2[5] = { 1,2,3,4,5 };
	print1(arr,3,5);
	print2(arr, 3, 5);
	//printf("%d ", arr2);//不是字符串
	int* n = NULL;
	int* parr3[11] = {0,0,0,0,0,0,0,0,0,n,0};
	printf("%p ", parr3[10]);
	int(*parr3[10])[5] = {&arr2};
	return 0;
}

