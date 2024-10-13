#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <windows.h>

int main()
{
	/*int i = -20;
	unsigned int j = 10;
	printf("%d\n", i + j);*/
	unsigned int i;
	for (i = 9;i >= 0;i--)
	{
		printf("%u\n", i);
		Sleep(100);
	}
	return 0;
}
