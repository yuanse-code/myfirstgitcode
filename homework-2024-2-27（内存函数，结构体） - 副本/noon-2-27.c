#define _CRT_SECURE_NO__WARNINGS 1
#include "D:/vsc++代码/mine.h"
#include <stddef.h>

void* my_memcpy(void* dest, const void* src,size_t num)
{
	assert(dest && src);
	void* ret = dest;
	char* str0 = dest;
	char* str1 = src;
	while (num)
	{
		*str0++ = *str1++;
		num--;
	}
	return ret;
}
void* my_memmove(void* dest, const void* src, size_t num)
{
	assert(dest && src);
	char* str0 = (char*)dest;
	char* str1 = (char*)src;
	void* ret = dest;
	if (dest > src&&str0<str1+num-1)
	{
		str0 += num - 1;
		str1 += num - 1;
		while (num)
		{
			*str0-- = *str1--;
			num--;
		}
	}
	else if (dest == src)
	{
		return ret;
	}
	else
	{
		while (num)
		{
			*str0++ = *str1++;
			num--;
		}
	}
	return ret;
}
//int main()
//{
//	int arr1[] = { 1,2,3,4,5 };
//	int arr2[10] = { 0 };
//	int arr3[] = { 1,2,3,4,5,6,7,8,9,10 };
//	my_memcpy(arr2,arr1,sizeof(arr1));
//	my_memmove(arr3, arr3 + 2, 20);
//	Print(arr2,sizeof(arr2)/sizeof(arr2[0]),"%d");
//	Print(arr3, sizeof(arr3) / sizeof(arr3[0]), "%d");
//	return 0;
//}
//memcmp
//int main()
//{
//	int arr1[] = { 1,2,3,4,5 };
//	int arr2[] = { 1,2,5,4,3 };
//	int ret = memcmp(arr1, arr2, 9);
//	printf("%d\n", ret);
//	return 0;
//}
//memset-内存设置函数
//int main()
//{
//	/*char arr[10] = "";
//	memset(arr, "#", 10);*/
//	int arr[10] = { 0 };
//	memset(arr, 1, 10);
//	return 0;
//}
//声明一个结构体类型
//声明一个学生类型，是想通过学生类型创建学生变量
//typedef struct Stu
//{
//	//成员变量
//	char name[20];
//	char tale[12];
//	char sex[10];
//	int age;
//}Stu;
//Stu s3;//全局变量
//int main()
//{
//	//创建的结构体变量
//	Stu s1;
//	Stu s2;
//	return 0;
//}
//struct
//{
//	int a;
//	char c;
//}sa;
//struct
//{
//	int a;
//	char c;
//}*psa;
////结构体指针
//int main()
//{
//	//psa = &sa;??
//	 
//	return 0;
//}
// 结构体的自引用
//typedef struct Node
//{
//	int date;
//	//struct Node n;错误
//	struct Node* next;
//}Node;
//int main()
//{
//	sizeof(struct Node);
//	return 0;
//}
//struct S
//{
//	char c;
//	int a;
//	double d;
//	char arr[20];
//};
//int main()
//{
//	struct S s = { 'c',100,3.14,"hello bit" };
//	printf("%c %d %lf %s",s.c,s.a,s.d,s.arr);
//	return 0;
//}
//结构体内存对齐
//struct S1
//{
//	char c1;
//	int a;
//	char c2;
//};
//struct S2
//{
//	char c1;
//	char c2;
//	int a;
//};
//struct S3
//{
//	double c1;
//	char c2;
//	int a;
//};
//struct S4
//{
//	char c;
//	struct S3 s3;
//	double d;
//};
//int main()
//{
//	struct S1 s1 = { 0 };
//	struct S2 s2 = { 0 };
//	struct S4 s4;
//	printf("%d\n", sizeof(s1)); 
//	printf("%d\n", sizeof(s2));
//	printf("%d\n", sizeof(s4));
//	return 0;
//}
struct S
{
	char c;
	int i;
	double d;
};
int main()
{
	//offsetof()
	printf("%d\n", offsetof(struct S, c));
	printf("%d\n", offsetof(struct S, i));
	printf("%d\n", offsetof(struct S, d));
	return 0;
}