#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int check_sys()
{
	int a = 1;
	return *(char*)&a;
}
//С�˷���1
//��˷���0
int main()
{
	/*int a = 1;
	char* p =(char*) &a;
	if (*p)
	{
		printf("С��\n");
	}
	else
	{
		printf("���\n");
	}*/
	int ret=check_sys();
	if (ret)
	{
		printf("С��\n");
	}
	else
	{
		printf("���\n");
	}
	return 0;
}
