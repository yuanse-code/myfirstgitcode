#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//int max(int x,int y)
//{
//	int z=0;
//	x > y?z = x : z = y;
//	return z;
//}
//int main()
//{
//	int a = 10;
//	int b = 20;
//	printf("�ȴ�С\n");
//	scanf("%d%d", &a, &b);
//	int c = max(a, b);
//	printf("%d\n",c);
//	return 0;
//}
//void swap1(int x,int y )//void�޷���ֵ
//{
//	int mid = 0;
//	mid = x;
//	x = y;
//	y = mid;
//}
void swap2(int*pa, int*pb)
{
	int tmp=0;
	tmp = *pa;
	*pa=*pb;
	*pb=tmp;
}
int main()
{
	int a = 10;
	int b = 20;
	int tmp = 0;
	//swap1(a, b);
	printf("a=%d b=%d\n", a, b);
	swap2(&a, &b);
	/*tmp = a;
	a = b;
	b = tmp;*/
	printf("a=%d b=%d", a, b);
	return 0;
}
//int main()
//{
//	int a = 0;
//	int* pa = &a;//paָ�����
//	*pa=20;//�����ò���
//	return 0;
//}