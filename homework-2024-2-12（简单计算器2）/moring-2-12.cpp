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
double 阶乘(double a,double y)
{
	int sum = 1;
	int x = (int)a;
	while (x)
	{
		sum *= x--;
	}
	return sum;
}
double 根号(double x,double y)
{
	return sqrt(x);
}
void menu()
{
	printf("****************************\n");
	printf("***    1.add    2.sub ******\n");
	printf("***    3.mul    4.div ******\n");
	printf("***    5.阶乘   6.根号******\n");
	printf("***         0.exit    ******\n");
	printf("****************************\n");
}
int main()
{
	int input = 0;
	double x = 0;
	double y = 0;
	double (*pfArr[7])(double, double) = { 0,Add,Sub,Mul,Div,阶乘 ,根号 };
	do
	{
		printf("姓名：谷光榆，学号20230413108\n");
		menu();
		printf("请选择:>");
		scanf("%d", &input);
		if (input >= 1 && input <= 6)
		{
			printf("请输入两个操作数：>");
			scanf("%lf%lf", &x, &y);
			double ret = pfArr[input](x, y);
			printf("%lf\n", ret);
		}
		else if (0 == input)
		{
			printf("退出\n");
		}
		else
		{
			assert(input >= 0 && input <= 6);
			printf("输入错误\n");
		}
		//switch (input)
		//{
		//case 1:
		//	printf("请输入两个操作数：>");
		//	scanf("%lf%lf", x, y);
		//	printf("%lf\n", Add(x, y));
		//	break;
		//case 2:
		//	printf("请输入两个操作数：>");
		//	scanf("%lf%lf", x, y);
		//	printf("%lf\n", Sub(x, y));
		//	break;
		//case 3:
		//	printf("请输入两个操作数：>");
		//	scanf("%lf%lf", x, y);
		//	printf("%lf\n", Mul(x, y));
		//	break;
		//case 4:
		//	printf("请输入两个操作数：>");
		//	scanf("%lf%lf", x, y);
		//	printf("%lf\n", Div(x, y));
		//	break;
		//case 0:
		//	printf("退出\n");
		//	break;
		//default:
		//	assert(input == 0 || input == 1 || input == 2 || input == 3 || input == 4);
		//	printf("输入错误\n");
		//	break;
		//}
	} while (input);
	//printf("%lf\n", (double)阶乘(2.5));
	return 0;
}
