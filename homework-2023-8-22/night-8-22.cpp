#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<windows.h>
#include<stdlib.h>
#include<time.h>
//猜数字游戏
//1.电脑生成一个随机数
//2.猜数字
//RAND_MAX-32767
void menu()
{
	printf("*********************************\n");
	printf("***   1.play       0.exit     ***\n");
	printf("*********************************\n");
}
void game()
{
	int ret = 0;
	int guess = 0;
	ret = rand()%100+1;//1-100
	printf("猜数字游戏1-100\n");
	//拿时间戳来设置随机数的起点
	//printf("%d", ret);
	while (1)
	{
		printf("请猜数字：>");
		scanf("%d", &guess);
		if (guess > ret)
		{
			printf("猜大了\n");
		}
		else if (guess < ret)
		{
			printf("猜小了\n");
		}
		else
		{
			printf("恭喜你，猜对了\n");
			break;
		}
	}
}
int main()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do 
	{
		printf("猜数字游戏1-100\n");
		menu();
		printf("请选择>:");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			system("cls");
			game();//
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("输入错误\n");
			Sleep(1000);
			system("cls");
			break;
		}
	} while (input);
	return 0;
}