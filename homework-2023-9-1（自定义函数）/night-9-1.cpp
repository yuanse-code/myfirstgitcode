#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<math.h>
#include<string.h>
//�Զ��庯��
//�ǲ�������
//int is_prime(int x)
//{
//	int un = 0;
//	for (un = 2;un <=sqrt(x);un++)
//	{
//		if (0 == x % un)
//			return 0;//return��������ֹ
//	}
//	return 1;
//}
//int main()
//{
//	int i = 0;
//	int sum = 0;
//	for (i = 100;i <= 200;i++)
//	{
//		if (is_prime(i))
//		{
//			printf("%d ", i);
//			sum++;
//		}
//		else
//			continue;
//	}
//	printf("\nsum=%d", sum);
//	return 0;
//}
//�ǲ�������
//int is_leap_year(int x)//������һ�����
//{
//	if ((((x % 100) != 0) && (0 == x % 4))||x%400==0)
//		return 1;
//	else
//		return 0;
//}
//int main()
//{
//	int year = 0;
//	for (year = 1000;year <= 2000;year++)
//	{
//		if (is_leap_year(year))
//			printf("%d ", year);
//	}
//	return 0;
//}
//�������ֲ���
int binary_search(int arr[],int k,int sz)//ʵ���ϣ�arr��һ��ָ��"[]��©"
{
	int left = 0;
	int right = sz-1;
	int i = 0;
	while (left<=right)
	{
		i = (left + right) /2;
		if (k == arr[i])
			return i;
		else if (arr[i] > k)
			right = i-1;
		else
			left = i+1;
	}
	return -1;
}
int main()
{
	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
	int k = 7;
	int sz = sizeof(arr) / sizeof(arr[0]);
	int ret = binary_search(arr, k,sz); //���Σ�ֻ����Ԫ��
	if (-1 == ret)
		printf("�Ҳ���");
	else
		printf("�ҵ��ˣ��±���:%d",ret);
	return 0;
}