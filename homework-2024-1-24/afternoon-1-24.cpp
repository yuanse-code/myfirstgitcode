#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

//int count_bit_one(unsigned int a)
//{
//	int count = 0;
//	while (a)
//	{
//		if ((a & 1) == 1)
//		{
//			count++;
//		}
//		else
//		{
//			;
//		}
//		a = a >> 1;
//	}
//	return count;
//}
int count_bit_one(int a)
{
	int count = 0;
	while (a)
	{
		a = a & (a - 1);
		count++;
	}
	return count;
}
//int main()
//{
//	int a = 0;
//	scanf("%d", &a);
//	printf("%d", count_bit_one(a));
//	return 0;
//}
//int get_diff_bit(int m,int n)
//{
//	int tmp = m ^ n;
//	int count = 0;
//	//return count_bit_one(tmp);
//	while (tmp)
//	{
//		tmp = tmp & (tmp - 1);
//		count++;
//	}
//	return count;
//}
//int main()
//{
//	int m = 0;
//	int n = 0;
//	scanf("%d%d", &m, &n);
//	printf("%d", get_diff_bit(m, n));
//	return 0;
//}
void print(int m)
{
	int i = 0;
	printf("奇数位：>");
	for (i = 30;i >= 0;i -= 2)
	{
		printf("%d", (m >> i) & 1);
	}
	printf("\n偶数位：>");
	for (i = 31;i >= 0;i -= 2)
	{
		printf("%d", (m >> i) & 1);
	}
}
int main()
{
	int m = 0;
	scanf("%d", &m);
	print(m);
	return 0;
}
