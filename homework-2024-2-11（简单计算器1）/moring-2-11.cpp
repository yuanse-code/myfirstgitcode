#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
typedef void(*pfun_t)(int);
#include <assert.h>

/*void test(int* a)
{
	;
}*///´íÎó
int Add(int x, int y)
{
	return x + y;
}
int Sub(int x, int y)
{
	return x - y;
}
int Mul(int x, int y)
{
	return x * y;
}
int Div(int x, int y)
{
	return x / y;
}
void (*signal2(int, void(*)(int)))(int);
pfun_t signal(int, pfun_t);//¼ò»¯
char* my_strcpy(char* dest,const char* src)
{
	assert(src != 0 && dest != 0);
	char* ret = dest;
	while (*dest++ = *src++)
	{
		;
	}
	return ret;
}
int main()
{
	int arr[3][5] = { 0 };
	int arr1[5] = { 0 };
	char arr2[3] = "hi";
	char arr3[] = "abcdef";
	//test(arr);
	//test(arr1);
	printf("%p\n", &Add);
	printf("%p\n", Add);
	int (*pa)(int, int) = Add;
	printf("%d\n", (*pa)(2, 3));
	printf("%d\n", (pa)(2, 3));
	printf("%d\n", pa(2, 3));
	printf("%d\n", (**pa)(2, 3));
	printf("%d\n", (***pa)(2, 3));
	int (*pb[4])(int, int) = {Add,Sub,Mul,Div};
	int i = 0;
	for (i = 0;i < 4;i++)
	{
		printf("%d\n", pb[i](2, 3));
	}
	printf("%s\n", my_strcpy(arr3, arr2));
	char* (*pf)(char*, const char*) = my_strcpy;
	char* (*pfArr[4])(char*, const char*) = { my_strcpy };
	printf("%s\n", pfArr[0](arr3, arr2));
	return 0;
}
