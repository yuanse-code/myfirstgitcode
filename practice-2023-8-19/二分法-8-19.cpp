#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<windows.h>
#include<stdlib.h>
//二分法
//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//	int k = 7;
//	printf("请输入要查找的数字：>");
//	scanf("%d",&k);
//	int left = 0;
//	int right = sizeof(arr) / sizeof(arr[0]);
//	int i = 0;
//	for (left = 0;left <= right;)
//	{
//		i = (right + left) / 2;
//		if (arr[i] > k)
//		{
//			right = i - 1;
//		}
//		else if (arr[i] < k)
//			left = i + 1;
//		else
//		{
//			printf("找到了，这个数的下标是：%d", i);
//			break;
//		}
//	}
//	if (arr[i] != k)
//		printf("找不到");
//	return 0;
//}
//for循环变种
//int main()
//{
//	int x, y;
//	for (x = 0, y = 0;x < 2 &&y < 5;++x, y++)//与&//或|
//	{
//		printf("haha\n");
//	}
//	return 0;
//}
//动画播放
int main()
{
	char arr1[] = {"welcome to bit!!!!!!"};
	char arr2[] = {"####################" };
	int right = strlen(arr1) - 1;
	int left = 0;
	for (left = 0;left <= right;left++, right--)
	{
		arr2[left] = arr1[left];
		arr2[right] = arr1[right];
		Sleep(1000);
		system("cls");
		printf(arr2);
	}
	return 0;
}