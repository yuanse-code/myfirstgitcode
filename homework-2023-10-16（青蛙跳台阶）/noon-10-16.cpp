#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include"forg.h"
int forg(int n);
int main()
{
	int n = 0;
	printf("������̨�ף�̨������");
	scanf("%d", &n);
	printf("����Ϊ��%d", forg(n));
	return 0;
}