#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>

int main()
{
	char password [20] = { 0 };
	int ch = 0;
	char ret = 0;
	printf("请输入密码：");
	scanf("%s", password);
	printf("请确认（Y/N）:");
	while ((ch = getchar()) != '\n')
	{
		;
	}
	ret = getchar();
	if (ret != 'Y' && ret != 'N')
	{
		printf("认真的吗？\n");
	}
	if (ret == 'Y')
	{
		printf("确认成功\n");
	}
	else
	{
		printf("取消确认\n");
	}
	int a = 10;
	printf("%d",a);
}