#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

//int main()
//{
//	int a[9] = { 0,1,2,3,4,5,6,8,9 };
//	int sum = 0;
//	int i = 0;
//	for (i = 0; i < 9; i++)
//	{
//		sum ^= a[i]^(i+1);
//	}
//	printf("%d ", sum);
//	return 0;
//}
//给你一个整数数组 nums，其中恰好有两个元素只出现一次，
//其余所有元素均出现两次。 找出只出现一次的那两个元素。
// 你可以按 任意顺序 返回答案。
//
int main()
{
	int a = 0, b = 3;
	b = a ? ++a : --a;
	printf("%d\n", b);
	return 0;
}