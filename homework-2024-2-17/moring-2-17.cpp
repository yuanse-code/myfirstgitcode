#define _CRT_SECURE_NO_WARNINGS 1
#include "D:/vsc++´úÂë/mine.h"

int main()
{
	char arr[] = "abcdef";
	const char* p = "abcdef";
	int a[3][4] = { 0 }; 
	printf("%d\n", sizeof(a[0] + 1));
	printf("%d\n", sizeof(&arr + 1));//4/8
	printf("%d\n", strlen(&arr[0] + 1));
	//printf("%d\n", strlen((char*)*p));//error
	//printf("%d\n", strlen((char*)(&arr + 1)));Ëæ»úÖµ
	return 0;
}
