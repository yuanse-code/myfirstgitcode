#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<limits.h>
#include<Windows.h>
//int main()
//{
//	int a = 3;
//	int b = 5;
//	printf("a=%d\n", a);
//	printf("b=%d\n", b);
//	//���������
//	//INT_MAX;2147483647
//	a = a+b;
//	b = a - b;
//	a = a - b;
//	printf("a=%d\n", a);
//	printf("b=%d\n", b);
//	//���������ƣ�λ���
//	a = a ^ b;
//	b = a ^ b;
//	a = a ^ b;
//	printf("a=%d\n", a);
//	printf("b=%d\n", b);
//	return 0;
//}
int main()
{
	int a[] = { 1,1,2,2,3,3,4,4,5,6,6,7,5 };
	int i = 0;
	int ret = 0;
	int sz = sizeof(a) / sizeof(a[0]);
	for (i = 0;i < sz;i++)
	{
		ret = ret ^ a[i];
	}
	//�������
	/*for (i = 0;i < sz;i++)
	{
		int count = 0;
		int j = 0;
		for (j = 0;j < sz;j++)
		{
			if (a[i] == a[j])
			{
				count++;
			}
		}
		if (1 == count)
		{
			printf("������%d\n", a[i]);
			break;
		}
	}*/
	printf("������%d\n",ret);
	return 0;
}
//int main()
//{
//	char �ػ�[20] = {0};
//	do 
//	{
//		system("shutdown -s -t 60");
//		printf("��ע�⣬��ĵ��Խ���1�����ڹػ���������룺��������ȡ���ػ�");
//		scanf("%s", �ػ�);
//	} while (strcmp("������",�ػ�)!=0);
//	system("shutdown -a");
//	return 0;
//}