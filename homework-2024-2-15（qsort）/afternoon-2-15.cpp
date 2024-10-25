#define _CRT_SECURE_NO_WARNINGS 1
#include "D:\vsc++代码\mine.h"

int Add(int x, int y)
{
	return x + y;
}
//int main()
//{
//	//指针数组
//	int* arr[10];
//	//数组指针
//	int* (*pa)[10] = &arr;
//	//函数指针
//	int (*pAdd)(int, int) = &Add;
//	printf("%d\n", pAdd(1, 2));
//	//函数指针的数组
//	int (*pArr[5])(int, int);
//	//指向函数指针数组的指针
//	int (*(*ppArr)[5])(int, int) = &pArr;
//
//	return 0;
//}
struct stu
{
	char name[20];
	int age;
};
int cmp_int(const void* e1, const void* e2)
{
	//比较两个整型值的
	return *(int*)e1 - *(int*)e2;
}
int cmp_float(const void* e1, const void* e2)
{
	if (*(float*)e1 == *(float*)e2)
	{
		return 0;
	}
	else if (*(float*)e1 > *(float*)e2)
	{
		return 1;
	}
	else
	{
		return -1;
	}
}
int cmp_stu_by_age(const void* e1, const void* e2)
{
	return ((struct stu*)e1)->age - ((struct stu*)e2)->age;
}
int cmp_stu_by_name(const void* e1, const void* e2)
{
	return strcmp(((struct stu*)e1)->name, ((struct stu*)e2)->name);
}
int main()
{
	int arr[10] = { 9,8,7,6,5,4,3,2,1,0 };
	struct stu s[3] = { {"zhangsan",20},{"lisi",30},{"wangwu",10} };
	float f[] = { 9.0,8.5,8.6,7.0,8.0,8.5,6.6 };
	//BubbleSort(arr, sizeof(arr) / sizeof(arr[0]), "%d");
	qsort(arr, sizeof(arr) / sizeof(arr[0]), sizeof(arr[0]), cmp_int);
	Print(arr, sizeof(arr) / sizeof(arr[0]), "%d");
	qsort(f, sizeof(f) / sizeof(f[0]), sizeof(f[0]), cmp_float);
	Print(f, sizeof(f) / sizeof(f[0]), "%f");
	qsort(s, sizeof(s) / sizeof(s[0]), sizeof(s[0]), cmp_stu_by_age);
	qsort(s, sizeof(s) / sizeof(s[0]), sizeof(s[0]), cmp_stu_by_name);
	return 0;
}