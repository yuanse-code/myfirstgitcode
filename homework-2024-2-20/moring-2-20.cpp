#define _CRT_SECURE_NO_WARNINGS 1
#include "D:/vsc++代码/mine.h"
#include <conio.h>
#include <math.h>

//typedef struct stu
//{
//	char name[20];
//}s;
//char* ReverseStr(char* arr,int sz)
//{
//	assert(arr != 0);//刷题慎用
//	int i = 0;
//	char tmp = 0;
//	char* right = NULL;
//	char* left = arr;
//	for (i = 0;i < sz - 1;i++)//判断\0
//	{
//		if ('\0' == *(arr+i))
//		{
//			break;
//		}
//	}
//	for (right =arr+i - 1;left < right;left++, right--)
//	{
//		tmp = *left;
//		*left = *right;
//		*right = tmp;
//	}
//	return arr;
//}
//int main()
//{
//	/*s a = {"hello"};
//	printf("%s\n", (&a)->name);*/
//	char a[] = { 'a','b','c','d','\0' };
//	ReverseStr(a, sizeof(a) / sizeof(a[0]));
//	printf("%s\n", a);
//	gets_s(a);//读取一行
//	printf("%s\n", a);
//	return 0;
//}
//int main()
//{
//	int a = 0;
//	int n = 0;
//	int sum = 0;
//	int i = 0;
//	int ret = 0;
//	scanf("%d%d", &a, &n);
//	for (i = 0;i < n;i++)
//	{
//		ret = ret * 10 + a;
//		sum += ret;
//	}
//	printf("%d\n", sum);
//	return 0;
//}
//打印水仙花数（自幂数）
//int main()
//{
//	int i = 0;
//	for (i = 0;i < 10000;i++)
//	{
//		int sum = 0;
//		int n = 1;
//		int ret = i;
//		//计算位数
//		while (ret/=10)
//		{
//			n++;
//		}
//		//求和
//		ret = i;
//		while (ret)
//		{
//			sum+=(int)pow(ret % 10, n);
//			ret /= 10;
//		}
//		//判断是否是水仙花数
//		if (i == sum)
//		{
//			printf("%d ", i);
//		}
//	}
//	return 0;
//}
////
//int main()
//{
//	int low = 13;
//	int i = 0;
//	int c = 1;
//	char tmp = ' ';
//	int j = 1;
//	char a = 'a';
//	printf("请输入字符： > ");
//	scanf("%c", &a);
//	while(j)
//	{
//		
//		for (i = 0;i < low;i++)
//		{
//			tmp = ' ';
//			if ((i >= (low - 2 * j + 1)/2) && (i <( low + 2 * j - 1)/2))
//			{
//				tmp = a;
//			}
//			printf("%c", tmp);
//		}
//		printf("\n");
//		if (2 * j - 1 < low&&c)
//		{
//			j++;
//		}
//		else
//		{
//			c = 0;
//			j--;
//		}
//	}
//	return 0;
//}
//int main()
//{
//	int line = 0;
//	scanf("%d", &line);
//	int i = 0;
//	for (i = 0;i < line;i++)
//	{
//		int j = 0;
//		for (j = 0;j < line - 1 - i;j++)
//		{
//			printf(" ");
//		}
//		for (j = 0;j < 2*i+1;j++)
//		{
//			printf("*");
//		}
//		printf("\n");
//	}
//	for (i = 0;i < line-1;i++)
//	{
//		int j = 0;
//		for (j = 0;j <= i;j++)
//		{
//			printf(" ");
//		}
//		for (j = 0;j < 2 * (line-2-i) + 1;j++)
//		{
//			printf("*");
//		}
//		printf("\n");
//	}
//	return 0;
//}
//买汽水
//int main()
//{
//	int money = 0;
//	int total = 0;
//	scanf("%d", &money);
//	total = money;
//	while (money>=2)
//	{
//		total += money / 2;
//		money = money / 2+money % 2;
//	}
//	printf("%d\n", total);
//	scanf("%d", &money);
//	if (money == 0)
//		total = 0;
//	else
//		total = money * 2 - 1;
//	printf("%d\n", total);
//	return 0;
//}
void move(int* arr, int sz)
{
	int tmp = 0;
	int i = 0;
	int j = 0;
	for (i = 0;i < sz;i++)
	{
		if (1 == *(arr + i) % 2)
		{
			tmp = *(arr + j);
			*(arr + j) = *(arr + i);
			*(arr + i) = tmp;
			j++;
		}
	}
}
//这个比我的更快
void move2(int* arr,int sz)
{
	int right = sz-1;
	int left = 0;
	while (right > left)
	{
		//从左边找偶数
		while (right > left &&*(arr + left) % 2 == 1)
		{
			left++;
		}
		//从右边找奇数
		while ((right > left)&&*(arr + right) % 2 == 0)
		{
			right--;
		}
		if (right > left)
		{
			int tmp = *(arr + left);
			*(arr + left) = *(arr + right);
			*(arr + right) = tmp;
		}
	}
}
int main()
{
	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
	//move(arr,sizeof(arr)/sizeof(arr[0]));
	move2(arr, sizeof(arr) / sizeof(arr[0]));
	Print(arr, sizeof(arr) / sizeof(arr[0]), "%d");
	return 0;
}