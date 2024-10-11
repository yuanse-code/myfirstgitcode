#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int check_sys()
{
	int a = 1;
	return *(char*)&a;
}
//小端返回1
//大端返回0
int main()
{
	/*int a = 1;
	char* p =(char*) &a;
	if (*p)
	{
		printf("小端\n");
	}
	else
	{
		printf("大端\n");
	}*/
	int ret=check_sys();
	if (ret)
	{
		printf("小端\n");
	}
	else
	{
		printf("大端\n");
	}
	return 0;
}
