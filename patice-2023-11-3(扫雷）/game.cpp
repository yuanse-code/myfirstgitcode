#include"game.h"

void IntiBoard(char board[ROWS][COLS], int rows, int cols, char a)
{
	int i = 0;
	int j = 0;
	for (i = 0;i < rows;i++)
	{
		for (j = 0;j < cols;j++)
		{
			board[i][j] = a;
		}
	}
}
void DisplayBoard(char board[ROWS][COLS], int row, int col)
{
	int i = 0;
	int j = 0;
	printf("  ");
	for (i = 1;i <= row;i++)
	{
		if (i > 9)
		{
			printf("%d", i);
		}
		else
		{
			printf("%d ", i);
		}
	}
	printf("< y\n");
	for (i = 1;i <= row;i++)
	{
		if (i > 9)
		{
			printf("%d", i);
		}
		else
		{
			printf("%d ", i);
		}
		for (j = 1;j <= col;j++)
		{
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
}
void SetMine(char board[ROWS][COLS], int row, int col)
{
	int x = 0;
	int y = 0;
	int count = EASY_COUNT;
	while (count)
	{
		x = rand() % row + 1;
		y = rand() % col + 1;
		if ('1' != board[x][y])
		{
			board[x][y] = '1';
			count--;
		}
	}
}
//判断胜利
//胜0
//继续1
int IsWin(char show[ROWS][COLS],int row,int col)
{
	int i = 0;
	int j = 0;
	int count = 0;
	for (i = 1;i <= row;i++)
	{
		for (j = 1;j <= col;j++)
		{
			if ('*' == show[i][j])
			{
				count++;
			}
		}
	}
	if (EASY_COUNT == count)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}
//扩展
//继续1
//停止0
int expand(char show[ROWS][COLS],char mine[ROWS][COLS], int x, int y)
{
	int sum = 0;
	if (show[x][y] == '*')
	{
		sum = mine[x - 1][y] + mine[x - 1][y - 1] + mine[x - 1][y + 1]
			+ mine[x][y - 1] + mine[x][y + 1]
			+ mine[x + 1][y] + mine[x + 1][y - 1] + mine[x + 1][y + 1]
			- 8 * '0';
		if ('1' == mine[x][y])
		{
			return 0;
		}
		if (x >= 1 && x <= ROW && y >= 1 && y <= COL)
		{
			if (sum)
			{
				show[x][y] = sum + '0';
				return 0;
			}
			else
			{
				show[x][y] = sum + '0';
				//return 1;
				expand(show, mine, x - 1, y);expand(show, mine, x - 1, y - 1);expand(show, mine, x - 1, y + 1);
				expand(show, mine, x, y - 1);expand(show, mine, x, y + 1);
				expand(show, mine, x + 1, y);expand(show, mine, x + 1, y - 1);expand(show, mine, x + 1, y + 1);
				/*int i = 0;
				int j = 0;
				for (i = -1;i <= 1;i++)
				{
					for (j = -1;j <= 1;j++)
					{
						if (0 == i && 0 == j)
						{
							continue;
						}
						else
						{
							if (x + i >= 1 && x + i <= ROW && y + j >= 1 && y + j <= COL && show[x + i][y + j]=='*')
							{
								expand(show, mine, x + i, y + j);
							}
						}
					}
				}*/
			}
		}
		else
		{
			return 0;
		}
	}	
}
int Max(int a,int b)
{
	if (a > b)
		return a;
	else
		return b;
}
void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	int x = 0;
	int y = 0;
	while (IsWin(show, ROW, COL))
	{
		printf("请输入坐标：>");
		scanf("%d%d", &x, &y);
		if (x >= 1 && x <= ROW && y >= 1 && y <= COL)
		{
			if ('1' == mine[x][y])
			{
				printf("排雷失败\n");
				DisplayBoard(mine, ROW, COL);
				break;
			}
			else
			{
				//int n = 0;//圈数
				//int i = 0;
				//for (n = 0;n < Max(row,col);n++)
				//{
				//	for (i = x - n;i <= x + n;i++)
				//	{
				//		if (expand(show, mine, i, y-n) != 0)
				//		{
				//			continue;
				//		}
				//		else
				//		{
				//			break;
				//		}
				//	}
				//	for (i = x - n;i <= x + n;i++)
				//	{
				//		if (expand(show, mine, i, y + n) != 0)
				//		{
				//			continue;
				//		}
				//		else
				//		{
				//			break;
				//		}
				//	}
				//	for (i = x - n;i <= x + n;i++)
				//	{
				//		if (expand(show, mine, y - n, i) != 0)
				//		{
				//			continue;
				//		}
				//		else
				//		{
				//			break;
				//		}
				//	}
				//	for (i = x - n;i <= x + n;i++)
				//	{
				//		if (expand(show, mine, y + n, i) != 0)
				//		{
				//			continue;
				//		}
				//		else
				//		{
				//			break;
				//		}
				//	}
				//}
				system("cls");
				expand(show, mine, x, y);
				DisplayBoard(show, ROW, COL);
				//DisplayBoard(mine, ROW, COL);//作弊
			}
		}
		else
		{
			printf("坐标非法，请重新输入\n");
		}
	}
	if (0 == IsWin(show, ROW, COL))
	{
		system("cls");
		DisplayBoard(show, ROW, COL);
		printf("恭喜你，成功了\n");
	}
}