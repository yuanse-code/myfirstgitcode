#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<windows.h>
#include<stdlib.h>
int main()
{
	char password[20] = { 0 };
	char password2[20] = { 0 };
	int x = 0;
	int ch = 0;
	char ret = 'a';
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
			break;
		}
		else
		printf("密码错误\n");
	}
	if(x==3)
	{
		printf("三次密码错误，退出登录");
		Sleep(1000);
		system("cls");
	}	
	return 0;
} 
