#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"

void menu()
{
	//system(cls);
	printf("****************************************\n");
	printf("******1.play       0.exit  *************\n");
	printf("****************************************\n");
}
void game()
{
	char board[ROW][COL] = {0};
	char ret = 0;
	//��ʼ������
	InitBoard(board,ROW,COL);
	//��ӡ����
	DisplayBoard(board,ROW,COL);
	while (1)
	{
		//�������
		PlayMove(board,ROW,COL);
		DisplayBoard(board, ROW, COL);
		//�ж�����Ƿ�Ӯ
		ret=IsWin(board,ROW,COL);
		if (ret != 'C')
		{
			break;
		}
		//��������
		computerMove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		//�жϵ����Ƿ�Ӯ
		ret = IsWin(board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}
	}
	if (ret == '*')
	{
		printf("���Ӯ\n");
	}
	else if (ret == '#')
	{
		printf("����Ӯ\n");
	}
	else
	{
		printf("ƽ��\n");
	}
}
void test()
{
	srand((unsigned int)time(NULL));
	int input = 0;
	do
	{
		menu();
		printf("�����룺>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			printf("��������Ϸ\n");
			game();
			break;
		case 0:
			printf("�˳���Ϸ\n");
		default:
			printf("����������������룡\n");
			break;
		}
	} while (input);
}
int main()
{
	test();
	return 0;
}