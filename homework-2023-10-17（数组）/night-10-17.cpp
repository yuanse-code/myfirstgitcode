#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
//
//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//	int len = sizeof(arr) / sizeof(arr[0]);
//	int i = 0;
//	int* p = &arr[0];
//	for (i = 0;i < len;i++)
//	{
//		printf("&arr[%d]=%p ",i, &arr[i]);
//        //??printf("%d\n",*p+1);
//	}
//	return 0;
//}
int main()
{
	int arr[3][4] = { {1,2,3},{4,5}};
	int arr1[][4] = { {1,2,3,4},{5,6,7,8} };//列不可以省
	char ch[5][6];
	int arr2[3][4] = { {1,2,3},{4,5} };
	int i = 0;
	for (i = 0;i < 3;i++)
	{
		int j = 0;
		for (j = 0;j < 4;j++)
		{
			printf("%d ", arr2[i][j]);
			printf("[%d][%d]%p ", i, j, &arr[i][j]);
		}
		printf("\n");
	}
	return 0;
}