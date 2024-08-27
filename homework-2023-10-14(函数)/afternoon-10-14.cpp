#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<time.h>
#include<math.h>
#include<string.h>
#include"素数.h"
//int main()
//{
//	int a = 2;
//	int count = 0;
//	for (a = 2;a < 100;a++)
//	{
//		if (is_mersenne(a))
//			printf("%d ", a);
//		else
//		{
//			count++;
//			continue;
//		}
//	}
//	printf("\ncount=%d", count);
//	return 0;
//}
void print(int n)
{
	if (n > 9)
	{
		print(n / 10);
	}
	printf("%d ", n % 10);
}
//int main()
//{
//	unsigned int num = 0;
//	scanf("%d", &num);//1234
//	print(num);
//	return 0;
//}
int my_strlen(char* str)
{
	/*int count = 0;*/
	if (*str != '\0')
	{
		return 1 + my_strlen(str + 1);
		//count++;
		//str++;//指针自增会到下一个
	}
	else
		return 0;
	/*return count;*/
}
int main()
{
	char arr[] = "bit";
	/*int len = strlen(arr);
	printf("%d\n", len);*/
	int len = my_strlen(arr);
	printf("len=%d\n", len);
	return 0;
}