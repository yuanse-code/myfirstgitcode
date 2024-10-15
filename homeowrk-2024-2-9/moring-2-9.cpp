#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

//int main()
//{
//	/*int* arr[10] = { 0 };
//	char ch = 'w';
//	char* pc = &ch;*/
//	//char* pa = (char*) "abcdef";
//	const char* pa = "abcdef";
//	*pa = 'w';
//	printf("%s\n", pa);//¶Î´íÎó
//	/*printf("%c\n", *pa);
//	printf("%s\n", pa);*/
//	return 0;
//}

int main()
{
	char arr1[] = "abcdef";
	char arr2[] = "abcdef";
	char* p1 =(char*) "abcdef";
	char* p2 =(char*) "abcdef";
	if (p1 == p2)
	{
		printf("hehe\n");
	}
	else
	{
		printf("haha\n");
	}
	if (arr1 == arr2)
	{
		printf("hehe\n");
	}
	else
	{
		printf("haha\n");
	}
	return 0;
}