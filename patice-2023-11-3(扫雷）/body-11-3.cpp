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
	//³õÊ¼»¯ÆåÅÌ
	IntiBoard(mine,ROWS,COLS,'0');
	IntiBoard(show, ROWS, COLS, '*');
	//´òÓ¡ÆåÅÌ
	DisplayBoard(show, ROW, COL);
	//²¼À×
	SetMine(mine, ROW, COL);
	//É¨À×
	FindMine(mine, show, ROW, COL);
}
void test()
{
	int i = 1;
	while (i)
	{
		//system("cls");
		menu();
		printf("ÇëÊäÈë£º>");
		scanf("%d", &i);
		switch (i)
		{
		case 0:
			break;
		case 1:
			printf("É¨À×\n");
			game();
			break;
		default:
			printf("ÊäÈë´íÎó£¬ÇëÖØĞÂÊäÈë\n");
		}
	}
	
}
int main()
{
	srand((unsigned int)time(NULL));
	test();
	return 0;
}