#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <easyx.h>
#include <Windows.h>
#include <string.h>

//int main()
//{
//	initgraph(800,600);
//	setaspectratio(1, -1);
//	setorigin(400, 300);
//	for (int i = 0;i < 300;i += 10)
//	{
//		setlinecolor(GREEN);
//		circle(0, 0, i);
//		Sleep(500);
//	}
//	setlinecolor(WHITE);
//	circle(0, 0, 30);
//	getchar();
//	closegraph();
//	return 0;
//}
int main()
{
	int a = 10;
	int b = 20;
	a = a ^ b;
	b = a ^ b;
	a = a ^ b;
	printf("%d,%d\n", a, b);
	/*int num = 0;
	int count = 0;
	scanf("%d", &num);
	while (num)
	{
		if (num % 2 == 1)
		{
			count++;
		}
		num = num / 2;
	}*///对-1错误
	int num = 0;
	int count = 0;
	scanf("%d", &num);
	for (int i = 0;i < 32;i++)
	{
		if (1 == ((num >> i) & 1))
			count++;
	}
	printf("方法2=%d\n", count);
	//方法3
	count = 0;
	while (num)
	{
		count++;
		num = num & (num - 1);
	}
	printf("方法3=%d\n", count);
	printf("方法3=%d\n", count);
	return 0;
}

