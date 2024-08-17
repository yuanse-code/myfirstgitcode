#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
//byte
//int main()
//{
//	int a = 10;
//	int arr[] = { 1,2,3,4,5,6 };
//	printf("a:%d \n", sizeof(a));
//	printf("char:%d \n", sizeof(char));
//	printf("short:%d \n", sizeof(short));
//	printf("int:%d \n", sizeof(int));
//	printf("long:%d \n", sizeof(long));
//	printf("long long:%d \n", sizeof(long long));
//	printf("float:%d \n", sizeof(float));
//	printf("double:%d \n", sizeof(double));
//	printf("arr:%d \n", sizeof(arr));
//	printf("arr[0]:%d \n", sizeof(arr[0]));
//	printf("sizeof(arr)/sizeof(arr[0]):%d \n", sizeof(arr)/sizeof(arr[0]));
//	return 0;
//}
//结构体 多属性
//struct Book
//{
//	char name[20];
//	short price;
//};
//int main()
//{
//	struct Book b1 = { "c语言程序设计",55 };
//	printf("书名：%s\n", b1.name);
//	printf("价格：%d\n", b1.price);
//	printf("修改后的价格:%d\n", b1.price = 15);
//	struct Book* pd = &b1;
//	printf("%s\n", (*pd).name);
//	strcpy((*pd).name, "C++");
//	printf("%s\n", (*pd).name);
//	return 0;
//}
//()强制转换
//int main()
//{
//	int a = (int)3.14;
//	printf("a=%d ", a);
//	return 0;
//}