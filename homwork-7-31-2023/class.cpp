#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//int main()
//{
//	int n = 0;
//	int a = 0;
//	int b = 0;
//	int c = 0;
//	printf("请输入：\n");
//	scanf("%d", &n);
//	for (a = 1, b = 1;a <= n;a++)
//	{
//		b *= a;
//		c += b;
//	}
//	printf("%d ",c);
//	return 0;
//}
int main()
{
	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
	int k = 17;
	int i = 0;
	int sz = sizeof(arr) / sizeof(arr[0]);
	for (i = 0;i < sz;i++)
	{
		if (arr[i] == k)
		{
			printf("找到了，下标是：%d\n", i);
			break;
		}
	}
	if (sz == i)
		printf("找不到");
	return 0;
}