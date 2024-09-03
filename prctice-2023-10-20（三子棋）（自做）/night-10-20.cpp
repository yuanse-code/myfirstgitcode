#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"

void menu()
{
	printf("****************************************\n");
	printf("******1.play       0.exit  *************\n");
	printf("****************************************\n");
	
}
void game()
{
	char board[ROW][COL] = { 0 };
	char boardmouse[ROW][COL] = { 0 };
	char ret = 0;
	//初始化棋盘
	InitBoard(board, ROW, COL,boardmouse);
	//打印棋盘
	DisplayBoard(board, ROW, COL, boardmouse);
	while (1)
	{
		//玩家下棋
		int* position=0;
		position=MouseMove(board,boardmouse);
		while (PlayMove(board, ROW, COL, position[0], position[1]))
		{
			PlayMove(board, ROW, COL, position[0], position[1]);
			position=MouseMove(board, boardmouse);
		}
		DisplayBoard(board, ROW, COL,boardmouse);
		//判断玩家是否赢
		ret = IsWin(board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}
		//电脑下棋
		system("cls");
		computerMove(board, ROW, COL);
		DisplayBoard(board, ROW, COL,boardmouse);
		//判断电脑是否赢
		ret = IsWin(board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}
		
	}
	if (ret == '*')
	{
		printf("玩家赢\n");
	}
	else if (ret == '#')
	{
		printf("电脑赢\n");
	}
	else
	{
		printf("平局\n");
	}
}
void test()
{
	srand((unsigned int)time(NULL));
	int input = 0;
	int i = 0;
	int 关机 = 0;
	char in[20] = {0};//输错惩罚
	do
	{
		menu();
		printf("请输入：>");
		scanf("%d", &input);
		system("cls");
		switch (input)
		{
		case 1:
			printf("三子棋游戏\n");
			game();
			break;
		case 0:
			printf("退出游戏\n");
		default:
			printf("输入错误，请重新输入！\n");
			i++;
			break;
		}
		if ((i % 5 + 1) == 5)
		{
			system("cls");
			printf("你听不懂是吧\n跟你说了输入错误,输入错误,输入错误\n");
			Sleep(3000);
			关机++;
		}
		输错惩罚(i,关机,in);
	} while (input);
}
int main()
{
	test();
	return 0;
}