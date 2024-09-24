#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

//int my_strlen(char* str)
//{
//	char* start = str;
//	char* end = str;
//	while (*end != '\0')
//	{
//		end++;
//	}
//	return end - start;
//}
//int main()
//{
//	int a = 10;
//	int* pa = &a;
//	pa = NULL;
//	//*pa = 10;´íÎó
//	char arr[] = "bit";
//	int len = my_strlen(arr);
//	printf("%d\n", len);
//	printf("%p\n", arr);
//	printf("%p\n", &arr);
//	char* p = arr;
//	for (int i = 0;i < 3;i++)
//	{
//		printf("%p ========%p\n", p + i, &arr[i]);
//	}
//	return 0;
//}
int main()
{
	int a = 10;
	int* arr[3] = { &a };
	printf("%d\n", *(arr[0]));
	return 0;
}