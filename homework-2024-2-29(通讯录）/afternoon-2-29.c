#include "contact.h"

//1.存放1000个好友的信息
//名字
//电话 性别 住址 年龄
//增加好友
//删除
//查找
//修改
//打印                                                              
//排序
void menu()
{
	printf("健身俱乐部会员管理系统\n");
	printf("**************************************************\n");
	printf("*****    1.增加             2.删除   *************\n");
	printf("*****    3.查找             4.修改   *************\n");
	printf("*****    5.展示             6.排序   *************\n");
	printf("*****    7.save             0.退出   *************\n"); 
	printf("**************************************************\n");
}
int main()
{
	int input = 0;  
	int capacity = 3;
	//创建通讯录
	Contact con;	//con就是通讯录，//里边包含1000(动态版本)元素和size
	//初始化通讯录
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
			printf("请选择：>");
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
				printf("退出\n");
				break;
			case SAVE:
				SaveContact(&con);
				break;
			default:
				printf("输入错误\n");
				break;
			}
		} while (input);
	}
	free(con.date);
	con.date = NULL;
	return 0;
}