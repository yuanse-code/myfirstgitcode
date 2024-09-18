#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

//int main()
//{
//	short s = 0;
//	int c = 10;
//	printf("%d\n", sizeof(s = c + 5));//2
//	printf("%d\n", s);//0
//	int a = 0;
//	char b = 'w';
//	int arr[10] = { 0 };
//	printf("%d\n", sizeof a);//占内存空间的大小
//	printf("%d\n", sizeof(int));//4
//	printf("%d\n", sizeof b );//1
//	printf("%d\n", sizeof(char));//1
//	printf("%d\n", sizeof(arr));//40
//	printf("%d\n", sizeof(int [10]));//40
//	return 0;
//}
int main()
{
	int a= 0;
	printf("%d\n", ~a);
	a = 10;
	printf("%d\n", ++a);
	a = (int)3.14;
	printf("%d\n", a);
	a = (-1 >> 1);
	printf("%d\n", a);
	return 0;
}