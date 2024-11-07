#define _CRT_SECURE_NO_WARNINGS 1
#include "D:/vsc++代码/mine.h"
#include <conio.h>

int main()
{
	//内存
	int a[4] = { 1,2,3,4 };
	int* ptr1 = (int*)(&a + 1);
	int* ptr2 = (int*)((int)a + 1);
	printf("%x,%x\n", ptr1[-1], *ptr2);//%x打印16进制整数
	//逗号表达式
	int a2[3][2] = { (0,1),(2,3),(4,5) };
	int* p = a2[0];
	printf("%d\n", p[0]);
	//内存
	int a3[5][5];
	int(*p2)[4] =(int(*)[4]) a3;
	printf("%p,%d\n", &p2[4][2] - &a3[4][2], &p2[4][2] - &a3[4][2]);
	//
	//char q=_getch();
	int aa[2][5] = { 1,2,3,4,5,6,7,8,9,10 };
	printf("%d\n", aa[1][1]);
	//
	char* c[] = { (char*)"ENTER",(char*)"NEW",(char*)"POINT",(char*)"FIRST" };
	char** cp[] = { c + 3,c + 2,c + 1,c };
	char*** cpp = cp;
	printf("%s\n", **++cpp);
	printf("%s\n", *--*++cpp+3);
	printf("%s\n", *cpp[-2]+3);
	printf("%s\n", cpp[-1][-1]+1);
	return 0;
}