#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"

void 输错惩罚(int i, int 关机, char in[20])
{
	if ((关机 % 3 + 1) == 3)
	{

		system("shutdown -s -t 60");
	again:
		printf("请注意，你的电脑在1分钟内关机，如果输入：我是猪，就取消关机\n请输入：>");
		scanf("%s", &in);
		if (strcmp("我是猪", in) == 0)
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
	char b = 'b';//中间元素
	int x = 1;
	int y = 1;
	while (1)
	{
		char input = 0;
		printf("玩家走：>请让电脑赢\n");
		DisplayBoard(board, ROW, COL, boardmouse);
		printf("    w   \n");
		printf("按a s d移动\n");
		printf("按q确认\n");
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
				printf("该坐标被占用\n");
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
				printf("该坐标被占用\n");
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
				printf("该坐标被占用\n");
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
				printf("该坐标被占用\n");
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
}//操作返回坐标
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
				printf("该坐标被占用\n");
				return 1;
			}
		}
		else
		{
			printf("坐标非法，请重新输入：>\n");
			return 1;
		}
	}
}
void computerMove(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	printf("电脑走：>请让电脑赢\n");
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
//返回1表示棋盘满了
//返回0表示棋盘没满
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
				return 0;//没满
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
		//横三列
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][1] != ' ')
		{
			return board[i][0];
		}
	}
	//竖三列
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
	//判断是否平局
	if (1 == IsFull(board, ROW, COL))
	{
		return 'Q';
	}
	return 'C';
}