#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <math.h>
#include <assert.h>

double Add(double x, double y)
{
	return x + y;
}
double Sub(double x, double y)
{
	return x - y;
}
double Mul(double x, double y)
{
	return x * y;
}
double Div(double x, double y)
{
	return x / y;
}
double �׳�(double a,double y)
{
	int sum = 1;
	int x = (int)a;
	while (x)
	{
		sum *= x--;
	}
	return sum;
}
double ����(double x,double y)
{
	return sqrt(x);
}
void menu()
{
	printf("****************************\n");
	printf("***    1.add    2.sub ******\n");
	printf("***    3.mul    4.div ******\n");
	printf("***    5.�׳�   6.����******\n");
	printf("***         0.exit    ******\n");
	printf("****************************\n");
}
int main()
{
	int input = 0;
	double x = 0;
	double y = 0;
	double (*pfArr[7])(double, double) = { 0,Add,Sub,Mul,Div,�׳� ,���� };
	do
	{
		printf("�������ȹ��ܣ�ѧ��20230413108\n");
		menu();
		printf("��ѡ��:>");
		scanf("%d", &input);
		if (input >= 1 && input <= 6)
		{
			printf("������������������>");
			scanf("%lf%lf", &x, &y);
			double ret = pfArr[input](x, y);
			printf("%lf\n", ret);
		}
		else if (0 == input)
		{
			printf("�˳�\n");
		}
		else
		{
			assert(input >= 0 && input <= 6);
			printf("�������\n");
		}
		//switch (input)
		//{
		//case 1:
		//	printf("������������������>");
		//	scanf("%lf%lf", x, y);
		//	printf("%lf\n", Add(x, y));
		//	break;
		//case 2:
		//	printf("������������������>");
		//	scanf("%lf%lf", x, y);
		//	printf("%lf\n", Sub(x, y));
		//	break;
		//case 3:
		//	printf("������������������>");
		//	scanf("%lf%lf", x, y);
		//	printf("%lf\n", Mul(x, y));
		//	break;
		//case 4:
		//	printf("������������������>");
		//	scanf("%lf%lf", x, y);
		//	printf("%lf\n", Div(x, y));
		//	break;
		//case 0:
		//	printf("�˳�\n");
		//	break;
		//default:
		//	assert(input == 0 || input == 1 || input == 2 || input == 3 || input == 4);
		//	printf("�������\n");
		//	break;
		//}
	} while (input);
	//printf("%lf\n", (double)�׳�(2.5));
	return 0;
}
