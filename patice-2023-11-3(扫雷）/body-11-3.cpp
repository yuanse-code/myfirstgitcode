#include"game.h"

void menu()
{
	printf("****************************************\n");
	printf("******        1.play       *************\n");
	printf("******        0.exit       *************\n");
	printf("****************************************\n");

}
void game()
{
	char mine[ROWS][COLS] = { 0 };
	char show[ROWS][COLS] = { 0 };
	//��ʼ������
	IntiBoard(mine,ROWS,COLS,'0');
	IntiBoard(show, ROWS, COLS, '*');
	//��ӡ����
	DisplayBoard(show, ROW, COL);
	//����
	SetMine(mine, ROW, COL);
	//ɨ��
	FindMine(mine, show, ROW, COL);
}
void test()
{
	int i = 1;
	while (i)
	{
		//system("cls");
		menu();
		printf("�����룺>");
		scanf("%d", &i);
		switch (i)
		{
		case 0:
			break;
		case 1:
			printf("ɨ��\n");
			game();
			break;
		default:
			printf("�����������������\n");
		}
	}
	
}
int main()
{
	srand((unsigned int)time(NULL));
	test();
	return 0;
}