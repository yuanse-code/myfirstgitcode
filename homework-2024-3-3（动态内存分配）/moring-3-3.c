#define _CRT_SECURE_NO_WARNINGS 1
#include "D:/vsc++����/mine.h"
#include <errno.h>

//���������Ա
//struct S
//{
//	int n;
//	int arr[];//δ֪��С��
//	//��int arr[0]
//};
//int main()
//{
//	/*struct S s;
//	printf("%lld\n", sizeof(s));*/
//	struct S* ps = (struct S*)malloc(sizeof(struct S) + 5 * sizeof(int));
//	if (NULL == ps)
//	{
//		printf("%s\n", strerror(errno));
//	}
//	else
//	{
//		ps->n = 100;
//		int i = 0;
//		for (i = 0; i < 5; i++)
//		{
//			ps->arr[i] = i;
//		}
//	}
//	struct S* ptr=realloc(ps, 44);
//	if (NULL == ptr)
//	{
//		printf("%s\n", strerror(errno));
//	}
//	else
//	{
//		ps = ptr;
//		int i = 0;
//		for (i = 5; i < 10; i++)
//		{
//			ps->arr[i] = i;
//		}
//		for (i = 0; i < 10; i++)
//		{
//			printf("%d ", ps->arr[i]);
//		}
//	}
//	free(ps);
//	ps = NULL;
//	return 0;
//}
//struct S
//{
//	int n;
//	int* arr;
//};
//int main()
//{
//	struct S* ps = (struct S*)malloc(sizeof(struct S));
//	ps->arr = (int*)malloc(5 * sizeof(int));
//	int i = 0;
//	for (i = 0; i < 5; i++)
//	{
//		ps->arr[i] = i;
//	}
//	for (i = 0; i < 5; i++)
//	{
//		printf("%d ", ps->arr[i]);
//	}
//	printf("\n");
//	//������С
//	int*ptr=(int*)realloc(ps->arr, 10 * sizeof(int));
//	if (ptr != NULL)
//	{
//		ps->arr = ptr;
//	}
//	for (i = 5; i < 10; i++)
//	{
//		ps->arr[i] = i;
//	}
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d ", ps->arr[i]);
//	}
//	free(ps->arr);
//	ps->arr = NULL;
//	free(ps);
//	ps = NULL;
//	return 0;
//}
struct S
{
	int n;
	int arr[];
};
int main()
{
	/*printf("%d\n", sizeof(struct S));*/
	struct S* p = (struct S*)malloc(sizeof(struct S) + 10 * sizeof(int));
	if (NULL == p)
	{
		printf("%s\n", strerror(errno));
	}
	else
	{
		p->n = 100;
		int i = 0;
		for (i = 0; i < 10; i++)
		{
			p->arr[i] = i;
		}
		for (i = 0; i < 10; i++)
		{
			printf("%d ", p->arr[i]);
		}
	}
	free(p);
	p = NULL;
	return 0;
}