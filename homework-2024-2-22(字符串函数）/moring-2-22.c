#define _CRT_SECURE_NO_WARNINGS 1
#include "D:/vsc++代码/mine.h"

int My_strlen(const char* arr)
{
	assert(arr);
	char* tmp = arr;
	while (*arr)
	{
		arr++;
	}
	return arr - tmp;
}
//int main()
//{
//
//	//int len =My_strlen("abcdef");
//	////char arr[] = { 'a','b','c','d','e','f' };
//	////int len =My_strlen(arr);
//	//printf("%d\n", len);
//	if (strlen("abc") - strlen("abcdef") > 0)
//	{
//		printf("hehe\n");
//	}
//	else
//	{
//		printf("haha\n");
//	}
//	return 0;
//}
//char* my_strcpy(char* dest, const char* str)
//{
//	assert(dest && str);
//	char* ret = dest;
//	//拷贝src指向的字符串到dest指向的空间，包含‘\0’
//	while(*dest++ = *str++)
//	{
//		;
//	}
//	//返回目的地的地址
//	return ret;
//}
//int main()
//{
//	char arr1[] = "abcdefjhi";
//	char arr2[] = "bit";
//	my_strcpy(arr1, arr2);
//	printf("%s\n", arr1);
//	return 0;
//}//my_strcpy
//my_strcat
//char* my_strcat(char* dest, const char* src)
//{
//	assert(dest && src);
//	//1.找到目的字符串的'\0'
//	char* ret = dest;
//	while ('\0' != *(++dest))
//	{
//		;
//	}
//	//2.追加
//	while (*dest++ = *src++)
//	{
//		;
//	}
//	return dest;
//}
//int main()
//{
//	char arr1[30] = "hello\0XXXXXXXXXXXX";
//	char arr2[] = "world";
//	my_strcat(arr1, arr2);
//	printf("%s\n", arr1);
//	return 0;
//}//my_strcat
//my_strcmp
//int main()
//{
//	//vs
//	//>1
//	//==0
//	//<-1
//	//linux
//	//> >0
//	//== 0
//	//< <0
//	char* p1 = "qbc";
//	char* p2 = "abc";
//	int ret = strcmp(p1, p2);
//	printf("%d\n", ret);
//	return 0;
//}
//int my_strcmp(const char* str1, const char* str2)
//{
//	assert(str1 && str2);
//	while (*str1 == *str2)
//	{
//		if (*str1 == '\0')
//			return 0;
//		str1++;
//		str2++;
//	}
//	if (*str1 > *str2)
//		return 1;
//	else
//		return -1;
//	//return (*str1-*str2);
//}
//int main()
//{
//	char* p1 = "abc";
//	char* p2 = "abcd";
//	int ret = my_strcmp(p1,p2);
//	printf("%d\n", ret);
//}//my_strcmp
int main()
{
	char arr1[30] = "hello \0XXXXXXXXXXXXXXX";
	char arr2[] = "world";
	strncat(arr1, arr2, 8);
	printf("%s\n", arr1);
	return 0;
}