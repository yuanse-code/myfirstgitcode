#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//���ַ�����
int main()
{
	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
	int sz = sizeof(arr) / sizeof(arr[0]);//����
	int k =7;
	int left = 0;
	int right = sz-1;
	while (left <= right)
	{
		int mid = (left + right) / 2;
		if (k < arr[mid])
		{
			right = mid - 1;
		}
		else if (k > arr[mid])
		{
			left = mid + 1;
		}
		else
		{
			printf("�ҵ��ˣ��±���: %d", mid);
			break;
		}
	}
		if (left > right)
		{
			printf("�Ҳ���\n");
		}
		return 0;
}