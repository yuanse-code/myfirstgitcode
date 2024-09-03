#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<Windows.h>
#include<stdlib.h>
#include<time.h>

#define ROW 3
#define COL 3
void InitBoard(char board[ROW][COL], int row, int col,char boardmouse[ROW][COL]);

void DisplayBoard(char board[ROW][COL], int row, int col,char boardmouse[ROW][COL]);
int PlayMove(char board[ROW][COL], int row, int col,int x,int y);
void computerMove(char board[ROW][COL], int row, int col);
char IsWin(char board[ROW][COL], int row, int col);
//玩家赢  ‘*’
//电脑赢  ‘#’
//平局     ‘Q’
//继续     ‘C’
void 输错惩罚(int i, int 关机, char in[20]);
int* MouseMove(char board[ROW][COL], char boardmouse[ROW][COL]);
