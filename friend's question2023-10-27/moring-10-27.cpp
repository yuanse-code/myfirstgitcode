
#include"Sum3.h"
int Sum(int x)
{
	int sum = 0;
	while(0!=x)
	{
		sum += x % 10;
		x = x / 10;
	}
	return sum;
}
int Sum2(int x)
{
	while (0 != x)
	{
		return x %10+Sum2(x/10);
	}
	return 0;
}
int main()
{
	int input = 0;
	printf("请输入：>");
    scanf("%d",&input);
	printf("sum=%d\n", Sum(input));//求数字各位和
	printf("sum=%d", Sum2(input));//递归求
	printf("sum=%d", Sum3(input));//加函数声明，头文件
	return 0;
}