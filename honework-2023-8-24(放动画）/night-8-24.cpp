#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
//int Add(int x, int y)
//{
//	int z = 0;
//	z = x + y;
//	return z;
//}
//int main()
//{
//	int a = 10;
//	int b = 20;
//	int sum = Add(a, b);
//	printf("%d\n", sum);
//	return 0;
//}
//int main()
//{
//	char arr1[] = "bit";
//	char arr2[20] = "############";
//	strcpy(arr2, arr1);
//	printf("%s\n", arr2);
//	//strlen-string length
//	//strcpy-string copy
//	return 0;
//}
int main()
{
	char arr[] = "hello world";
	memset(arr, '*', 5);
	printf("%s\n", arr);
	return 0;
}