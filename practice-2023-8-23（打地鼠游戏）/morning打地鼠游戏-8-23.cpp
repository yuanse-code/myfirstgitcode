#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<windows.h>
#include<stdlib.h>
#include<time.h>
void mune()
{
	printf("##############################################\n");
	printf("####     1.play           0.exit          ####\n");
	printf("##############################################\n");
	printf("请输入：>");
}
void game()
{
	int hole[5] = {11,11,11,11,11};
	long a = 0;
	long b = 0;
	long t= 3;
	int scord = 0;
	int dig = 0;
	int num = 0;
	int hit = 99;
	char stop = 'a';
	while (1)
	{
		dig = rand() % 4+1;
		num = rand() % 10 + 1;
		hole[dig] = num;
		if (t <= 1)
		{
			t = rand() % 4 + 1;
		}
		if (scord >= 100)
		{
			printf("恭喜100分");
			Sleep(1000);
			t += 3;
			scord = scord-100;
			system("cls");
		}
		printf("打地鼠游戏\n得分：%d\n",scord);
		printf("输入97退出\n");//a=97
		a = (time(NULL));
		printf("##############################################\n");
		printf("####       %d                  %d         ####\n",hole[0],hole[1]);
		printf("####                 %d                   ####\n",hole[2]);
		printf("####       %d                  %d         ####\n",hole[3],hole[4]);
		printf("##############################################\n");
		printf("%d秒内请输入：>",t);
		scanf("%d", &hit);
		b = (time(NULL));
		if (b > (a + t))
		{
			printf("失败了");
			Sleep(500);
			goto clean;
		}
		if (hit==num)
		{
			scord+=10;
			t -= 1;
			printf("boom");
			Sleep(500);
			goto clean;
		}
		else if (hit == (int)stop)
		{
			break;
		}
		else
		{
			printf("输错了\n");
		}
	clean:
		hole[0] = 11;
		hole[1] = 11;
		hole[2] = 11;
		hole[3] = 11;
		hole[4] = 11;
		system("cls");	
	}
}
int main()
{
	char in[20] = { 0 };
	char password[20] = { 0 };
	char password2[20] = { 0 };
	char ret = 'a';	
	int input = 0;
	int i = 0;
	int x = 0;
	int ch = 0;
	int 关机 = 0;
	printf("设置密码：>");
	scanf("%s", &password);
	printf("\n请确认（Y/N）:>");
	while ((ch = getchar()) != '\n')
	{
		;
	}
	ret = getchar();
	if (ret == 'Y')
	{
		printf("确认成功");
	}
	else if (ret == 'N')
	{
		printf("取消确认");
		Sleep(1000);
		system("cls");
	}
	else
		printf("输入错误");
	Sleep(1000);
	system("cls");
	printf("用户登录\n");
	for (x = 0;x < 3;x++)
	{
		printf("请输入密码：>");
		scanf("%s", &password2);
		while ((ch = getchar()) != '\n')
		{
			;
		}
		if (strcmp(password2, password) == 0)
		{
			printf("登录成功\n");
			char arr1[] = { "welcome to bit!!!!!!" };
			char arr2[] = { "####################" };
			int right = strlen(arr1) - 1;
			int left = 0;
			for (left = 0;left <= right;left++, right--)
			{
				arr2[left] = arr1[left];
				arr2[right] = arr1[right];
				Sleep(1000);
				system("cls");
				printf(arr2);
			}
			srand((unsigned int)time(NULL));
			do
			{
				if ((i % 5 + 1) == 5)
				{
					system("cls");
					printf("你听不懂是吧\n跟你说了输入错误,输入错误,输入错误\n");
					Sleep(3000);
					关机++;
				}
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
				printf("打地鼠游戏\n");
				mune();
				scanf("%d", &input);
				switch (input)
				{
				case 1:
					system("cls");
					game();
					system("cls");
					break;
				case 0:
					system("cls");
					printf("退出游戏");
					Sleep(2000);
					system("cls");
					break;
				default:
				{
					printf("输入错误\n");
					i++;
					break;
				}
				}
			} while (input);
			break;
		}
		else
			printf("密码错误\n");
	}
	if (x == 3)
	{
		printf("三次密码错误，退出登录");
		Sleep(1000);
		system("cls");
	}
	return 0;
}