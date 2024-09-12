#define _CRT_SECURE_NO_WARNINGS 1
#include <easyx.h>
#include <stdio.h>
#include <time.h>

void draws()
{
	int x = rand() % (800 + 1) - 400;
	int y = rand() % (600 + 1) - 300;
	putpixel(x, y,WHITE);
}
int main()
{
	initgraph(800, 600);
	srand((unsigned int)time(NULL));
	setaspectratio(1, -1);
	setorigin(800 / 2, 600 / 2);
	for (int r = 10;r <= 300;r += 10)
	{
		setlinecolor(YELLOW);
		circle(0, 0, r);
	}
	putpixel(0, 0, RED);
	rectangle(100, 100, -100, -100);
	rectangle(200, 100, -200, -100);
	ellipse(200, 100, -200, -100);
	for (int i = 0;i < 1000;i++)
	{
		draws();
	}
	
	getchar();
	closegraph();
	return 0;
}

