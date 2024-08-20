#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<windows.h>
int main()
{
	system("sc create 猪的游戏 binpath= ""cmd \c C:\\Users\\Acer\\Desktop\\send 发送\\游戏的猪.exe"" type = own start = auto displayname = 猪的游戏");
	printf("成功");
	return 0;
}