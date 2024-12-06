#define _CRT_SECURE_NO_WARNINGS 1
#include"D:/vsc++ДњТы/mine.h"

union Un
{
	int a;
	char arr[5];
};
int main()
{
	union Un u;
	printf("%d\n", sizeof(u));
	return 0;
}