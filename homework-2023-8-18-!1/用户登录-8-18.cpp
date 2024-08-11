#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<windows.h>
int main()
{
	int i = 0;
	char password[20] = { 0 };
	for (i = 0;i < 3;i++)
	{
		printf("请输入密码：>");
		scanf("%s", password);
		if (strcmp(password, "123456") == 0)
		{
			printf("登录成功");
			break;
		}
		else
		      printf("密码错误\n");
	}
	if (3 == i)
	{
		system("cls");
		printf("三次密码错误，退出程序");
		Sleep(1000);
		system("cls");
	}
	return 0;
}