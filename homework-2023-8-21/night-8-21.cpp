#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//100-200����
//int main()
//{
//	int i = 0;
//	int j = 0;
//	int count = 0;
//	for (i = 100;i <= 200;i++)
//	{
//		for (j = 2;j < i;j++)
//		{
//			if (i % j == 0)
//			{
//				break;
//			}
//		}
//		if (j == i)
//		{
//			printf("%d ", i);
//			count++;
//		}
//	}
//	printf("\ncount=%d ", count);
//	return 0;
//}//i=a*b ֻ��a//��i֮ǰ ��i/2�����磩sqart(i)��ƽ��<math.h>
//���¡���������n�־��硷
//100���м���9
//int main()
//{
//	int i = 0;
//	int count = 0;
//	for (i = 1;i <= 100;i++)
//	{
//		if ((i % 10 == 9))
//			count++;
//		if (i / 10 == 9)
//			count++;
//	}
//	printf("count=%d ", count);
//	return 0;
//}
//1-1/2+1/3-...+1/100�ĺ�
//int main()
//{
//	int i = 0;
//	double sum = 0;
//	int flag = 1;
//	for (i = 1;i <= 100;i++)
//	{
//		sum += flag*1.0 / i;
//		flag = -flag;
//	}
//	printf("%lf \n", sum);
//	return 0;
//}
//�����
//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//	int max = arr[0];//Ҫ�������ʼ
//	int i = 0;
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	for (i = 0;i < sz;i++)
//	{
//		if (arr[i] > max) 
//		{
//			max = arr[i];
//		}
//	}
//	printf("max=%d\n", max);
//	return 0;
//}
//��ӡ�žų˷���
int main()
{
	int a = 0;
	int b = 0;
	int c = 0;
	printf("�žų˷���\n");
	for (a=1,b=1,c=1;a<=9; a++)
	{
		for (b = 1;b <= a;b++)
		{
			c = a * b;
			printf("%d��%d=%-2d ", a, b, c);	//%2d�����ն��� 2d�Ҷ���//-2d�����
		}
		printf("\n");
	}
	return 0;
}