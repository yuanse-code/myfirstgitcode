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
	//��ʼ������
	InitBoard(board, ROW, COL,boardmouse);
	//��ӡ����
	DisplayBoard(board, ROW, COL, boardmouse);
	while (1)
	{
		//�������
		int* position=0;
		position=MouseMove(board,boardmouse);
		while (PlayMove(board, ROW, COL, position[0], position[1]))
		{
			PlayMove(board, ROW, COL, position[0], position[1]);
			position=MouseMove(board, boardmouse);
		}
		DisplayBoard(board, ROW, COL,boardmouse);
		//�ж�����Ƿ�Ӯ
		ret = IsWin(board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}
		//��������
		system("cls");
		computerMove(board, ROW, COL);
		DisplayBoard(board, ROW, COL,boardmouse);
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
	int i = 0;
	int �ػ� = 0;
	char in[20] = {0};//���ͷ�
	do
	{
		menu();
		printf("�����룺>");
		scanf("%d", &input);
		system("cls");
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
			i++;
			break;
		}
		if ((i % 5 + 1) == 5)
		{
			system("cls");
			printf("���������ǰ�\n����˵���������,�������,�������\n");
			Sleep(3000);
			�ػ�++;
		}
		���ͷ�(i,�ػ�,in);
	} while (input);
}
int main()
{
	test();
	return 0;
}