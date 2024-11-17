#define _CRT_SECURE_NO_WARNINGS 1
#include "D:/vsc++����/mine.h"

//void left_move(char* arr, int sz, int k)
//{
//	int i = 0;
//	char** p = &arr;
//	for (i = 0;i < k;i++)
//	{
//		char* tmp =(char*) malloc(1);
//		assert(tmp);
//		memcpy(tmp, arr, 1);
//		(*p)++;
//		memcpy(arr - 1, arr + sz-1, 1);
//		memcpy(arr + sz-1, arr+sz-2, 1);
//		memcpy(arr + sz-2, tmp, 1);
//		free(tmp);
//	}
//}
void left_move(char* arr, int sz, int k);
int main()
{
	char arr[] = "abcdef";
	int k = 0;
	scanf("%d", &k);
	left_move(arr, sizeof(arr) / sizeof(arr[0]),k);
	printf("%s\n", arr);
	return 0;
}//����������û���޸�
//void left_move(char* arr, int sz, int k)
//{
//	assert(arr);
//	int i = 0;
//	for (i = 0;i < k;i++)
//	{
//		int j = 0;
//		char tmp = *arr;
//		for (j = 1;j <= sz - 2;j++)
//		{
//			*(arr + j - 1) = *(arr + j);
//		}
//		*(arr + sz - 2) = tmp;
//	}
//}
//int main()
//{
//	char arr[] = "abcdef";
//	int k = 0;
//	scanf("%d", &k);
//	left_move(arr, sizeof(arr) / sizeof(arr[0]), k);
//	printf("%s\n", arr);
//	return 0;
//}//����һ
// 
//������ת��
void Reverse(char* arr, int sz)
{
	assert(arr);
	int right = sz - 1;
	int left = 0;
	char tmp = 0;
	while (left < right)
	{
		tmp = *(arr + right);
		*(arr + right) = *(arr + left);
		*(arr + left) = tmp;
		right--;
		left++;
	}
}
void left_move(char* arr, int sz, int k)
{
	assert(arr);
	assert(k <= sz - 1);
	Reverse(arr, k);//�������
	Reverse(arr + k, sz - k-1);//�����ұ�
	Reverse(arr, sz - 1);//����ȫ��
}//����Reverseֱ�Ӵ�right��left����
//int main()
//{
//	char arr[] = "abcdef";
//	int k = 0;
//	scanf("%d", &k);
//	left_move(arr, sizeof(arr) / sizeof(arr[0]), k);
//	printf("%s\n", arr);
//	return 0;
//}
//int is_left_move(char* arr1, char* arr2,int sz)
//{
//	int i = 0;
//	for (i = 0;i < sz - 1;i++)
//	{
//		left_move(arr1, sz,1);
//		int ret=strcmp(arr1, arr2);
//		if (ret == 0)
//		{
//			return 1;
//		}
//	}
//	return 0;
//}
//int main()
//{
//	char arr1[] = "abcdef";
//	char arr2[] = "cdefab";
//	int ret = is_left_move(arr1,arr2,sizeof(arr1)/sizeof(arr1[0]));
//	if (ret == 1)
//	{
//		printf("Yes\n");
//	}
//	else
//		printf("No\n");
//	return 0;
//}
//abcdefabcdef
//int is_left_move(char* str1, char* str2, int sz)
//{
//	assert(str1 && str2);
//	//1.��str1�ַ���׷��һ��str1�ַ���
//	//strcat//���������ӣ�Ҫ'\0'
//	//strncat
//	int len1 = strlen(str1);
//	int len2 = strlen(str2);
//	if (len1 != len2)
//		return 0;
//	strncat(str1, str1,len1);
//	//2.�ж�str2ָ����ַ����Ƿ���str1ָ����ַ������Ӵ�
//	//strstr//���Ӵ���
//
//	char* ret=strstr(str1, str2);
//	if (ret == 0)
//	{
//		return 0;
//	}
//	else
//		return 1;
//}
//int main()
//{
//	char arr1[30] = "abcdef";
//	char arr2[] = "cdefab";
//	int ret = is_left_move(arr1, arr2, sizeof(arr1) / sizeof(arr1[0]));
//	if (ret == 1)
//	{
//		printf("Yes\n");
//	}
//	else
//		printf("No\n");
//	return 0;
//}
//���Ͼ������
//1 2 3
//4 5 6
//7 8 9

//1 2 3
//2 3 4
//3 4 5

//int FindNum(int arr[3][3], int low, int k)
//{
//	int x = 0;
//	int y = low - 1;
//	while (y >= 0&&x<=low-1)
//	{
//		if (arr[x][y] > k)
//		{
//			y--;
//		}
//		else if (arr[x][y] < k)
//		{
//			x++;
//		}
//		else
//			return 1;
//	}
//	return 0;
//}
//int FindNum(int arr[3][3], int k, int* px, int* py)
//{
//	int x = 0;
//	int y = *py - 1;
//	while (y >= 0 && x <= *py - 1)
//	{
//		if (arr[x][y] > k)
//		{
//			y--;
//		}
//		else if (arr[x][y] < k)
//		{
//			x++;
//		}
//		else
//		{
//			*px = x;
//			*py = y;
//			return 1;
//		}
//	}
//	//�Ҳ���
//	return 0;
//}
//int main()
//{
//	int arr[3][3] = { {1,2,3},{4,5,6},{7,8,9} };
//	int a = 0;
//	int x = 3;
//	int y = 3;
//	scanf("%d", &a);
//	//�����Ͳ���
//	int ret=FindNum(arr,a,&x,&y);
//	if (ret)
//	{
//		printf("�ҵ���\n");
//		printf("�±���%d %d\n", x, y);
//	}
//	else
//		printf("�Ҳ���\n");
//	return 0;
//}