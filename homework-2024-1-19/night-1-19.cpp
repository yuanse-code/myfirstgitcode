#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <easyx.h>

struct stu
{
	char name[20];
	int age;
	char id[20];
};
int main()
{
	struct stu s1 = {"张三",20,"2019010305"};
	struct stu* ps = &s1;
	printf("%s\n", (*ps).name);
	printf("%s\n", ps->name);
	printf("%s\n", s1.name);
	printf("%d\n", s1.age);
	printf("%s\n", s1.id);
	char a, b;
	a = 3;//00000011
	b = 127;//01111111
	char c = a + b;
	printf("%d\n", c);
	int d = 1;
	printf("%d\n", d + --d);//问题表达式
	return 0;
}
