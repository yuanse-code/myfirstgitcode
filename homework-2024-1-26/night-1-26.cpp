#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>

int my_strlen(char* str)
{
	int count = 0;
	while(*str!='\0')
	{
		count++;
		str++;
	}
	return count;
}
void reverse(char arr[])
{
	int left = 0;
	int right = my_strlen(arr)-1;
	while (left < right)
	{
		int tmp = arr[left];
		arr[left] = arr[right];
		arr[right] = tmp;
		left++;
		right--;
	}
}
void reverse2(char arr[])
{
	
	char tmp = arr[0];
	int len = my_strlen(arr);
	if (len >= 2)
	{
		arr[0] = arr[len - 1];
		arr[len - 1] = '\0';
		reverse(arr + 1);
	}
	arr[len - 1] = tmp;
}
int Digitsum(unsigned int num)
{
	if (num > 9)
	{
		return Digitsum(num / 10) + num % 10;
	}
	else
	{
		return num;
	}
}
double Pow(int n, int k)
{
	if (k < 0)
	{
		return (1.0 / Pow(n, -k));
	}
	else if (k == 0)
	{
		return 1;
	}
	else
		return n * Pow(n, k - 1);
}
int main()
{
	char arr[] = "abcdef";
	//reverse(arr);//无C库函数，数组取反
	//reverse2(arr);//递归
	//printf("%s", arr);
	//各位求和
	/*unsigned int num = 0;
	scanf("%d", &num);
	int ret = Digitsum(num);
	printf("%d", ret);*/
	int n = 0;
	int k = 0;
	scanf("%d%d", &n, &k);
	double ret = Pow(n,k);
	printf("%lf", ret);
	return 0;
}
