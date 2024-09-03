#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"

void ���ͷ�(int i, int �ػ�, char in[20])
{
	if ((�ػ� % 3 + 1) == 3)
	{

		system("shutdown -s -t 60");
	again:
		printf("��ע�⣬��ĵ�����1�����ڹػ���������룺��������ȡ���ػ�\n�����룺>");
		scanf("%s", &in);
		if (strcmp("������", in) == 0)
		{
			system("shutdown -a");
		}
		else
		{
			goto again;
		}
	}
}
void InitBoard(char board[ROW][COL], int row, int col,char boardmouse[ROW][COL])
{
	int i = 0;
	int j = 0;
	for (i = 0;i < row;i++)
	{
		for (j = 0;j < col;j++)
		{
			board[i][j] = ' ';
		}
	}
	for (i = 0;i < row;i++)
	{
		for (j = 0;j < col;j++)
		{
			boardmouse[i][j] = ' ';
		}
	}
}
void InitBoardmouse(int row, int col, char boardmouse[ROW][COL])
{
	int i = 0;
	int j = 0;
	for (i = 0;i < row;i++)
	{
		for (j = 0;j < col;j++)
		{
			boardmouse[i][j] = ' ';
		}
	}
}
//void DisplayBoard(char board[ROW][COL],int row,int col)
//{
//	int i = 0;
//	for (i = 0;i < row;i++)
//	{
//		printf(" %c | %c | %c \n",board[i][0],board[i][1],board[i][2]);
//		if(i<row-1)
//		printf("---|---|---\n");
//	}
//}
void DisplayBoard(char board[ROW][COL], int row, int col, char boardmouse[ROW][COL])
{
	int i = 0;
	int j = 0;
	for (i = 0;i < row;i++)
	{
		for (j = 0;j < col;j++)
		{
			printf(" %c ", board[i][j]);
			if (j < col - 1)
				printf("|");
		}
		printf("\n");
		for (j = 0;j < col;j++)
		{
			printf("-%c-", boardmouse[i][j]);
			if (j < col - 1)
				printf("|");
		}
		printf("\n");
	}
}
int* MouseMove(char board[ROW][COL], char boardmouse[ROW][COL])
{
	char input = 'a';
	int position[2] = {0};
	boardmouse[1][1] = '^';
	char b = 'b';//�м�Ԫ��
	int x = 1;
	int y = 1;
	while (1)
	{
		char input = 0;
		printf("����ߣ�>���õ���Ӯ\n");
		DisplayBoard(board, ROW, COL, boardmouse);
		printf("    w   \n");
		printf("��a s d�ƶ�\n");
		printf("��qȷ��\n");
		scanf("%c", &input);
		if ('a' == input)
		{
			if (0 != y)
			{
				b = boardmouse[x][y];
				y = y - 1;
				boardmouse[x][y + 1] = board[x][y];
				boardmouse[x][y] = b;
			}
			else
			{
				printf("�����걻ռ��\n");
			}
			
		}
		if ('d' == input)
		{
			if (2 != y)
			{
				
				b = boardmouse[x][y];
			y = y + 1;
			boardmouse[x][y - 1] = board[x][y];
			boardmouse[x][y] = b;
			}
			else
			{
				printf("�����걻ռ��\n");
			}
			
		}
		if ('w' == input)
		{
			if (0 != x)
			{
				b = boardmouse[x][y];
				x = x - 1;
				boardmouse[x + 1][y] = board[x][y];
				boardmouse[x][y] = b;
			}
			else
			{
				printf("�����걻ռ��\n");
			}
		}
		if ('s' == input)
		{
			if (2 != x)
			{
				b = boardmouse[x][y];
				x = x + 1;
				boardmouse[x - 1][y] = board[x][y];
				boardmouse[x][y] = b;
			}
			else
			{
				printf("�����걻ռ��\n");
			}
			
		}
		if ('q' == input)
		{
			break;
		}	
		system("cls");
	}
	input = 0;
	position[0] = x+1;
	position[1] = y+1;
	InitBoardmouse( ROW, COL, boardmouse);
	return position;
}//������������
int PlayMove(char board[ROW][COL], int row, int col, int x, int y)
{
	while (1)
	{
		if (x >= 1 && x <= 3 && y >= 1 && y <= 3)
		{
			if (board[x - 1][y - 1] == ' ')
			{
				board[x - 1][y - 1] = '*';
				return 0;
				break;
			}
			else
			{
				printf("�����걻ռ��\n");
				return 1;
			}
		}
		else
		{
			printf("����Ƿ������������룺>\n");
			return 1;
		}
	}
}
void computerMove(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	printf("�����ߣ�>���õ���Ӯ\n");
	while (1)
	{
		x = rand() % ROW;
		y = rand() % COL;
		if (board[x][y] == ' ')
		{
			board[x][y] = '#';
			break;
		}
	}
}
//����1��ʾ��������
//����0��ʾ����û��
int IsFull(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0;i < row;i++)
	{
		for (j = 0;j < col;j++)
		{
			if (board[i][j] == ' ')
			{
				return 0;//û��
			}
		}
	}
	return 1;
}
char IsWin(char board[ROW][COL], int row, int col)
{
	int i = 0;
	for (i = 0;i < row;i++)
	{
		//������
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][1] != ' ')
		{
			return board[i][0];
		}
	}
	//������
	for (i = 0;i < col;i++)
	{
		if (board[0][i] == board[1][i] && board[2][i] == board[1][i] && board[1][i] != ' ')
		{
			return board[1][i];
		}
	}
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] != ' ')
	{
		return board[1][1];
	}
	if (board[2][0] == board[1][1] && board[2][0] == board[0][2] && board[1][i] != ' ')
	{
		return board[1][1];
	}
	//�ж��Ƿ�ƽ��
	if (1 == IsFull(board, ROW, COL))
	{
		return 'Q';
	}
	return 'C';
}