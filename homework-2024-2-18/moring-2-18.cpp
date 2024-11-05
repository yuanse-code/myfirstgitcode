#define _CRT_SECURE_NO_WARNINGS 1
#include "D:/vsc++ДњТы/mine.h"

int main()
{
	int a[3][4] = { 0 };
	printf("%d\n", sizeof(a[3]));//16
	int b[5] = { 1,2,3,4,5 };
	int* ptr = (int*)(&b + 1);
	printf("%d,%d\n", *(b + 1), *(ptr - 1));
	return 0;
}
