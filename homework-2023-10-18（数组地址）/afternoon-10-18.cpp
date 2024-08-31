#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
void bubble_sort(int arr[],int len)
{
	int i = 0;
	int j = 0;
	int a = 0;
	for (i = 0;i < len-1;i++)
	{
		int flag = 1;
		for (j = 0;j < len - 1 - i;j++)
		{
			if (arr[j] > arr[j + 1])
			{
				a = arr[j + 1];
				arr[j + 1] = arr[j];
				arr[j] = a;
				flag = 0;
			}
		}
		if (flag)
			break;
	}
}
//int main()
//{
//	int arr[] = { 0,1,2,3,4,5,6,7,8,9 };
//	int len = sizeof(arr) / sizeof(arr[0]);
//	int i = 0;
//	bubble_sort(arr,len);
//	for (i = 0;i < len;i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}
int main()
{
	int arr[] = { 1,2,3,4,5,6,7 };
	printf("%p\n", arr);	
	printf("%p\n", arr+1);
	printf("%p\n", &arr[0]);//首元素地址
	printf("%p\n", &arr[0]+1);
	printf("%p\n", &arr);
	printf("%p\n", &arr+1);//+28,7个//数组的地址
	return 0;
}