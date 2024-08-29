#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include"forg.h"
int forg(int n);
int main()
{
	int n = 0;
	printf("青蛙跳台阶，台阶数：");
	scanf("%d", &n);
	printf("次数为：%d", forg(n));
	return 0;
}