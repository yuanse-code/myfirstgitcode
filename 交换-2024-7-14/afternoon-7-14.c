#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main()
{
	int a = 1, b = 0;

	int tmp = a;
	a = b;
	b = tmp;

	a = a + b;
	b = a - b;
	a = a - b;

	a = a ^ b;
	b = a ^ b;
	a = a ^ b;

	printf("%d %d\n", a,b);
	scanf("%d", &a);
	printf("%d %d", a, b);

	return 0;
}