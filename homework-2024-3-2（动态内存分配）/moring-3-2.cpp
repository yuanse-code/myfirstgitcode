#define _CRT_SECURE_NO_WARNINGS 1
#include "D:/vsc++代码/mine.h"
#include <errno.h>
#include <Windows.h>

//struct S
//{
//	char name[20];
//	int age;
//};
//int main()
//{
//	struct S s;
//	printf("%d\n", sizeof(s));
//	return 0;
//}
//int main()
//{
//	//向内存申请10个整形的空间
//	int* p=(int*)malloc(10 * sizeof(int));
//	if (p == NULL)
//	{
//		printf("%s\n", strerror(errno));
//	}
//	else
//	{
//		int i = 0;
//		for (i = 0; i < 10; i++)
//		{
//			*(p + i) = i;
//		}
//		Print(p, 10, "%d");
//	}
//	//当动态申请的空间不在使用的时候
//	//就应该还给操作系统
//	free(p);
//	p = NULL;//
//	return 0;
//}
//int main()
//{
//	//int* p=(int*)malloc(10 * sizeof(int));
//	int*p=(int*)calloc(10, sizeof(int));
//	if (NULL == p)
//	{
//		printf("%s\n", strerror(errno));
//	}
//	else
//	{
//		int i = 0;
//		for (i = 0; i < 10; i++)
//		{
//			printf("%d ", *(p + i));
//		}
//		//释放空间
//		//free是用来释放动态开辟的空间
//		free(p);
//		p = NULL;
//	}
//	return 0;
//}
//int main()
//{
//	int* p = (int*)malloc(20);
//	if (p == NULL)
//	{
//		printf("%s\n", strerror(errno));
//	}
//	else
//	{
//		int i = 0;
//		for (i = 0; i < 5; i++)
//		{
//			*(p + i) = i;
//		}
//	}
//	//就是在使用malloc开辟的20个空间
//	//假设这里，不够
//	//这里使用realloc
//	//
//	// realloc注意事项
//	//1.如果p指向的空间
//	int*ptr=(int*)realloc(p, 40);
//	if (NULL == ptr)
//	{
//		printf("%s\n", strerror(errno));
//	}
//	else
//	{
//		int i = 0;
//		for (i = 5; i < 10; i++)
//		{
//			*(ptr + i) = i;
//		}
//		Print(p, 10, "%d");
//	}
//	free(ptr);
//	ptr = NULL;
//	p = NULL;
//	return 0;
//}
//越界访问
//int main()
//{
//	/*int* p = (int*)malloc(20);
//	if (NULL == p)
//		printf("%s\n", strerror(errno));
//	else
//	{
//		int i = 0;
//		for (i = 0; i < 10; i++)
//		{
//			*(p + i) = i;
//		}
//		Print(p, 10, "%d");
//	}
//	free(p);
//	p = NULL;*/
//	//对非动态开辟内存的free
//	int a = 0;
//	int* p = &a;
//	free(p);
//	p = NULL;
//	return 0;
//}
//int main()
//{
//	int* p = (int*)malloc(40);
//	int* a = p;
//	if (p == NULL)
//	{
//		printf("%s\n", strerror(errno));
//	}
//	else
//	{
//		int i = 0;
//		for (i = 0; i < 10; i++)
//		{
//			*p++ = i;
//		}
//	}
//	Print(a, 10, "%d");
//	free(a);
//	p = NULL;
//	return 0;
//}
//int main()
//{
//	int* p = (int*)malloc(40);
//	free(p);
//	p = NULL;
//	free(p);
//	return 0;
//}
//内存泄漏
int main()
{
	/*while (1)
	{
		malloc(1);
	}*/
	const char* str = "abcdef";
	printf(str);
	return 0;
}