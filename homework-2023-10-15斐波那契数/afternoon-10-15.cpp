#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
int my_strlen(char* x)
{
	if (*x != 0)
	{
		return 1 + my_strlen(x + 1);
	}
	else
	{
		return 0;
	}
}
//int main()
//{
//	char arr[] = "bit";
//	/*int len = strlen(arr);*/
//	printf("%d", my_strlen(arr));
//	return 0;
//}
//��n�Ľ׳�
int Facl(int n)
{
	int i = 1;
	int b = 1;
	for (i=1;i<=n; i++)
	{
		 b=b*i ;
	}
	return b;
}
int Fac2(int n)
{
	if (n <= 1)
		return 1;
	else
		return n * Fac2(n - 1);
}
int count = 0;
int 쳲�����(int n)
{
	if (n == 3)//�����3��쳲��������������
		count++;
	if (n <= 2)
		return 1;
	else
		return 쳲�����(n - 1) + 쳲�����(n - 2);
}
//int 쳲�����2(int n)
//{
//	int a = 1;
//	int b = 1;
//	int c = 1;
//	int n1 = 0;
//	if (n > 2)
//		for (int a = 1, int b = 1, int n1 = 2;n1 < n;n1++)
//		{
//			c = a + b;
//			a = b;
//			b = c;
//		}
//	return c;
//}
int 쳲�����3(int n)
{
	int a = 1;
	int b = 1;
	int c = 1;
	while(n>2)
	{
		c = a + b;
		a = b;
		b = c;
		n--;
	}
	return c;
}
//int main()
//{
//	int n = 0;
//	int ret = 0;
//	scanf("%d", &n);
//	ret = Fac2(n);
//	printf("%d\n", ret);
//	return 0;
//}
int main()
{
	int n = 0;
	int ret = 0;
	scanf("%d", &n);//TDD ������������
	printf("%d", 쳲�����3(n));
	printf("count=%d\n", count);
	return 0;
}
//void test(int n)
//{
//	if (n < 10000)
//	{
//		test(n + 1);
//	}
//}
//int main()
//{
//	test(1);
//	return 0;
//}