#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int forg(int n)
{
	if (n > 2)
		return forg(n - 1) + forg(n - 2);
	else
		return 1;
}