#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int prime(int x)
{
	int a = 0;
	for (int a = 2;a <= (x-1);a++)
	{
		if ((x % a )!= 0)
		{
			printf("1");
			break;
		}
	}
	if (a == x)
	{
		return 1;
	}
	else
		return 0;
}
int main()
{
	int i = 0;
	int count=0;
	for (i = 100,count=0;i <= 200;i++)
	{
		if (prime(i)==1)
		{
			printf("%d ", i);
			count++;
		}
	}
	printf("\ncount=%d", count);
	return 0;
}