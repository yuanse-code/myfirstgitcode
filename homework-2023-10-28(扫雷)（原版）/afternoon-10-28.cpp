#include"game.h"
void menu()
{
	printf("******************************\n");
	printf("*******    1.play      *******\n");
	printf("*******    0.exit      *******\n");
	printf("******************************\n");
}
void game()
{
	printf("ɨ����Ϸ\n");
	//�׵���Ϣ�洢
	//1.���úõ��׵���Ϣ
	char mine[ROWS][COLS] = { 0 };//11*11
	//2.�Ų�����׵���Ϣ
	char show[ROWS][COLS] = { 0 };
	//��ʼ��
	IntiBoard(mine, ROWS, COLS,'0');
	IntiBoard(show, ROWS, COLS, '*');
	//��ӡ����
	DisplayBoard(mine,ROW,COL);
	DisplayBoard(show, ROW, COL);
	//1.������
	SetMine(mine, ROW, COL);
	//ɨ��
	/*click(show,mine, ROW, COL);
	DisplayBoard(show, ROW, COL);*/
	FindMine(mine,show,ROW,COL);
}
void test()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("��ѡ��>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			system("cls");
			printf("�˳���Ϸ");
			break;
	    default:
			printf("�����������������!\n");
			break;
		}
	} while (input);
}
int main()
{
	test();
	return 0;
}