
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
	printf("�����룺>");
    scanf("%d",&input);
	printf("sum=%d\n", Sum(input));//�����ָ�λ��
	printf("sum=%d", Sum2(input));//�ݹ���
	printf("sum=%d", Sum3(input));//�Ӻ���������ͷ�ļ�
	return 0;
}