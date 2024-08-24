#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<math.h>
#include<string.h>
//自定义函数
//是不是素数
//int is_prime(int x)
//{
//	int un = 0;
//	for (un = 2;un <=sqrt(x);un++)
//	{
//		if (0 == x % un)
//			return 0;//return会立马终止
//	}
//	return 1;
//}
//int main()
//{
//	int i = 0;
//	int sum = 0;
//	for (i = 100;i <= 200;i++)
//	{
//		if (is_prime(i))
//		{
//			printf("%d ", i);
//			sum++;
//		}
//		else
//			continue;
//	}
//	printf("\nsum=%d", sum);
//	return 0;
//}
//是不是闰年
//int is_leap_year(int x)//函数单一，简洁
//{
//	if ((((x % 100) != 0) && (0 == x % 4))||x%400==0)
//		return 1;
//	else
//		return 0;
//}
//int main()
//{
//	int year = 0;
//	for (year = 1000;year <= 2000;year++)
//	{
//		if (is_leap_year(year))
//			printf("%d ", year);
//	}
//	return 0;
//}
//函数二分查找
int binary_search(int arr[],int k,int sz)//实质上，arr是一个指针"[]别漏"
{
	int left = 0;
	int right = sz-1;
	int i = 0;
	while (left<=right)
	{
		i = (left + right) /2;
		if (k == arr[i])
			return i;
		else if (arr[i] > k)
			right = i-1;
		else
			left = i+1;
	}
	return -1;
}
int main()
{
	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
	int k = 7;
	int sz = sizeof(arr) / sizeof(arr[0]);
	int ret = binary_search(arr, k,sz); //传参，只传首元素
	if (-1 == ret)
		printf("找不到");
	else
		printf("找到了，下标是:%d",ret);
	return 0;
}