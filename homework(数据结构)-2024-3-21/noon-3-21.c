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
//����һ���������� nums������ǡ��������Ԫ��ֻ����һ�Σ�
//��������Ԫ�ؾ��������Ρ� �ҳ�ֻ����һ�ε�������Ԫ�ء�
// ����԰� ����˳�� ���ش𰸡�
//
int main()
{
	int a = 0, b = 3;
	b = a ? ++a : --a;
	printf("%d\n", b);
	return 0;
}