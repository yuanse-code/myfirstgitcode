#define _CRT_SECURE_NO_WARNINGS 1
#include "D:/vsc++����/mine.h"
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
//	//���ڴ�����10�����εĿռ�
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
//	//����̬����Ŀռ䲻��ʹ�õ�ʱ��
//	//��Ӧ�û�������ϵͳ
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
//		//�ͷſռ�
//		//free�������ͷŶ�̬���ٵĿռ�
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
//	//������ʹ��malloc���ٵ�20���ռ�
//	//�����������
//	//����ʹ��realloc
//	//
//	// reallocע������
//	//1.���pָ��Ŀռ�
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
//Խ�����
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
//	//�ԷǶ�̬�����ڴ��free
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
//�ڴ�й©
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