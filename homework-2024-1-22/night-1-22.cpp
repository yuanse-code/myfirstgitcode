#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

void Init(int arr[], int sz)
{
	for (int i = 0;i < sz;i++)
	{
		arr[i] = 0;
	}
}
void Reverse(int arr[], int sz)
{
	int right = 0;
	int left = sz - 1;
	int tmp = 0;
	while (left>right)
	{
		tmp = arr[right];
		arr[right] = arr[left];
		arr[left] = tmp;
		right++;
		left--;
	}
}
void Print(int arr[], int sz)
{
	for (int i = 0;i < sz;i++)
	{
		printf("%d ",arr[i]);
	}
	printf("\n");
}
int main()
{
	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	int arr1[] = { 1,3,5,7,9 };
	int arr2[] = { 2,4,6,8,0 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	Print(arr, sz);
	Reverse(arr, sz);
	//Init(arr, sz);
	Print(arr, sz);
	return 0;
}
