#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<windows.h>
#include<stdlib.h>
//���ַ�
//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//	int k = 7;
//	printf("������Ҫ���ҵ����֣�>");
//	scanf("%d",&k);
//	int left = 0;
//	int right = sizeof(arr) / sizeof(arr[0]);
//	int i = 0;
//	for (left = 0;left <= right;)
//	{
//		i = (right + left) / 2;
//		if (arr[i] > k)
//		{
//			right = i - 1;
//		}
//		else if (arr[i] < k)
//			left = i + 1;
//		else
//		{
//			printf("�ҵ��ˣ���������±��ǣ�%d", i);
//			break;
//		}
//	}
//	if (arr[i] != k)
//		printf("�Ҳ���");
//	return 0;
//}
//forѭ������
//int main()
//{
//	int x, y;
//	for (x = 0, y = 0;x < 2 &&y < 5;++x, y++)//��&//��|
//	{
//		printf("haha\n");
//	}
//	return 0;
//}
//��������
int main()
{
	char arr1[] = {"welcome to bit!!!!!!"};
	char arr2[] = {"####################" };
	int right = strlen(arr1) - 1;
	int left = 0;
	for (left = 0;left <= right;left++, right--)
	{
		arr2[left] = arr1[left];
		arr2[right] = arr1[right];
		Sleep(1000);
		system("cls");
		printf(arr2);
	}
	return 0;
}