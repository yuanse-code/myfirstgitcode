#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//�������ȴ�С
//int main()
//{
//	int a = 0;
//	int b = 0;
//	int c = 0;
//	int tem = 0;
//	printf("�������ȴ�С��>");
//	scanf("%d%d%d", &a, &b, &c);
//	for (;(a > b && b > c && a > c)==0;)
//	{
//		if (a < b)
//		{
//			static int tem = a;
//			a = b;
//			b = tem;
//		}
//		if (a < c)
//		{
//			static int tem = a;
//			a = c;
//			c = tem;
//		}
//		if (b < c)
//		{
//			static int tem = b;
//			b = c;
//			c = tem;
//		}
//	}
//	printf("%d %d %d", a, b, c);
//	return 0;
//}
//�����Լ����շת�������
//int main()
//{
//	int m = 0;
//	int n = 0;
//	int r = 0;
//	printf("�����Լ��:>");
//	scanf("%d%d", &m, &n);
//	while (r=m % n)
//	{
//		m = n;
//		n = r;
//	}
//	printf("%d\n",n);
//	return 0;
//}
//��ӡ����
int main()
{
	int i = 0;
	int j = 0;
	int count = 0;
	for (i = 100;i <= 200;i++)
	{
		//i�Ƿ�Ϊ����
		//�Գ���13 2-12
		for (j = 2;j < i;j++)
		{
			if (i % j == 0)
			{
				break;
			}
		}
		if (i == j)
		{
			count++;
			printf("%d ", i);
		}
	}
	
	printf("\ncount=%d", count);
	return 0;
}