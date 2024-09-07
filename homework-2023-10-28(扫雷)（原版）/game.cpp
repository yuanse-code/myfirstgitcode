#include"game.h"

void IntiBoard(char board[ROWS][COLS], int rows, int cols,char set)
{
	int i = 0;
	int j = 0;
	for (i = 0;i < rows;i++)
	{
		for (j = 0;j < cols;j++)
		{
			board[i][j] = set;//'*'/'0'
		}
	}
}
void DisplayBoard(char board[ROWS][COLS], int row, int col)
{
	int i = 0;
	int j = 0;
	//��ӡ�к�
	for (i = 0;i <= col;i++)
	{
		printf("%d ", i);
	}
	printf("\n");
	for (i = 1;i <= row;i++)
	{
		printf("%d ", i);
		for (j = 1;j <= col;j++)
		{
			
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
}
void SetMine(char board[ROWS][COLS], int row, int col)
{
	int count = EASY_COUNT;
	while (count)
	{
		int x = rand() % row+1;//1-9
		int y = rand() % col+1;
		if (board[x][y] == '0')
		{
			board[x][y] = '1';
			count--;
		}	
	}
}
//void click(char board[ROWS][COLS],char mineboard[ROWS][COLS],int row, int col)
//{
//	printf("���������꣺>");
//	int x = 0;
//	int y = 0;
//	scanf("%d %d", x, y);
//	int i = 0;
//	int j = 0;
//	for (i = 1;i <=row;i++)
//	{
//		for (j = 1;j <= col;j++)
//		{
//			if (mineboard[x][y] != 1)
//			{
//				board[x][y] = mineboard[x][y] + mineboard[x - 1][y] + mineboard[x - 1][y - 1] + mineboard[x - 1][y + 1] + mineboard[x][y - 1] + mineboard[x][y + 1] + mineboard[x + 1][y - 1] + mineboard[x + 1][y + 1] + mineboard[x + 1][y];
//			}
//			else
//			{
//				board[x][y] = '*';
//			}
//		}
//	}
int get_mine_count(char mine[ROWS][COLS], int x, int y)
{
	return mine[x - 1][y] + mine[x - 1][y - 1] + mine[x - 1][y + 1]
		+ mine[x][y - 1] + mine[x][y + 1] 
		+ mine[x + 1][y - 1] + mine[x + 1][y + 1] + mine[x + 1][y]-8*'0';
}
void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	int i = 0;
	int j = 0;
	int x = 0;
	int y = 0;
	int win = 0;
	while (win<row*col-EASY_COUNT)
	{
    printf("���������꣺>");
	scanf("%d%d", &x, &y);
	if (x >= 1 && x <= row && y >= 1 && y <= col)
	{
		//����Ϸ�
		//1.����
		if (mine[x][y] == '1')
		{
			printf("���ź����㱻ը����\n");
			DisplayBoard(mine, ROW, COL);
			break;
		}
		else//������
		{
			//����x,y������Χ�м�����
			int count = get_mine_count(mine, x, y);
			show[x][y] = count + '0';
			DisplayBoard(show, ROW, COL);
			win++;
		}
	}
	else
	{
		printf("��������Ƿ������������롣");
	}
	}
	if (win == row * col - EASY_COUNT)
	{
		printf("��ϲ�㣬���׳ɹ�\n");
		DisplayBoard(mine, ROW, COL);
	}
}