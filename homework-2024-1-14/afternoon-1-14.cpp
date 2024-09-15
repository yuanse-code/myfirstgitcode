#define _CRT_SECURE_NO_WARNINGS 1
#include <easyx.h>
#include <stdio.h>

int main()
{
	initgraph(800, 600);
	setorigin(400, 300);
	setaspectratio(1, -1);
	for (int i = 0;i < 300;i += 10)
	{
		setlinecolor(GREEN);
		circle(0, 0,i);
		setlinecolor(BLUE);
		circle(1, 0, i);
		setlinecolor(RED);
		circle(6, 0, i);
	}
	getchar();
	closegraph();
	return 0;
}
