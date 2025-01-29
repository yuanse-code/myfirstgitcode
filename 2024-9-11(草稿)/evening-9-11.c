#include <stdio.h>

typedef struct a
{

	int a ;
	int b ;
	char c;
}a,stu;

struct bianlian
{
	int a;
	int b;
	int c;
}ia;

void fun()
{
	printf("%d", ia.a);
}
int main()
{
	stu a1;
	a a2;
	ia.a = 3;

	printf("%d", ia.a);
	fun();

	return 0;
}
