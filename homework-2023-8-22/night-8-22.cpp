#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<windows.h>
#include<stdlib.h>
#include<time.h>
//��������Ϸ
//1.��������һ�������
//2.������
//RAND_MAX-32767
void menu()
{
	printf("*********************************\n");
	printf("***   1.play       0.exit     ***\n");
	printf("*********************************\n");
}
void game()
{
	int ret = 0;
	int guess = 0;
	ret = rand()%100+1;//1-100
	printf("��������Ϸ1-100\n");
	//��ʱ�������������������
	//printf("%d", ret);
	while (1)
	{
		printf("������֣�>");
		scanf("%d", &guess);
		if (guess > ret)
		{
			printf("�´���\n");
		}
		else if (guess < ret)
		{
			printf("��С��\n");
		}
		else
		{
			printf("��ϲ�㣬�¶���\n");
			break;
		}
	}
}
int main()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do 
	{
		printf("��������Ϸ1-100\n");
		menu();
		printf("��ѡ��>:");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			system("cls");
			game();//
			break;
		case 0:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("�������\n");
			Sleep(1000);
			system("cls");
			break;
		}
	} while (input);
	return 0;
}