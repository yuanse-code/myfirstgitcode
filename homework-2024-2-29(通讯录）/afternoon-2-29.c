#include "contact.h"

//1.���1000�����ѵ���Ϣ
//����
//�绰 �Ա� סַ ����
//���Ӻ���
//ɾ��
//����
//�޸�
//��ӡ                                                              
//����
void menu()
{
	printf("������ֲ���Ա����ϵͳ\n");
	printf("**************************************************\n");
	printf("*****    1.����             2.ɾ��   *************\n");
	printf("*****    3.����             4.�޸�   *************\n");
	printf("*****    5.չʾ             6.����   *************\n");
	printf("*****    7.save             0.�˳�   *************\n"); 
	printf("**************************************************\n");
}
int main()
{
	int input = 0;  
	int capacity = 3;
	//����ͨѶ¼
	Contact con;	//con����ͨѶ¼��//��߰���1000(��̬�汾)Ԫ�غ�size
	//��ʼ��ͨѶ¼
	InitContact(&con);
	//
	if (NULL == con.date)
	{
		printf("%s\n", strerror(errno));
	}
	else
	{
		do
		{
			menu();
			printf("��ѡ��>");
			input = _getch() - 48;
			printf("%c\n", input + 48);
			switch (input)
			{
			case ADD:
				AddContact(&con);
				Sleep(1000);
				system("cls");
				break;
			case DEL:
				DelContact(&con);
				Sleep(1000);
				system("cls");
				break;
			case SEARCH:
				SearchContact(&con);
				break;
			case MODIFY:
				ModifyContact(&con);
				Sleep(1000);
				system("cls");
				break;
			case SHOW:
				system("cls");
				ShowContact(&con);
				break;
			case SORT:
				SortContact(&con);
				break;
			case EXIT:
				SaveContact(&con);
				system("cls");
				printf("�˳�\n");
				break;
			case SAVE:
				SaveContact(&con);
				break;
			default:
				printf("�������\n");
				break;
			}
		} while (input);
	}
	free(con.date);
	con.date = NULL;
	return 0;
}