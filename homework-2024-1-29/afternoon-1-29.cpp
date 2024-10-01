#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

struct S
{
	int a;
	char c;
	char arr[20];
	double d;
};
struct T
{
	char ch[10];
	struct S s;
	char* pc;
};
int main()
{
	char arr[] = "hello bit";
	struct T t = { "hehe",{100,'w',"hello world",3.14},arr };
	printf("%s\n", t.s.arr);
	printf("%s\n", t.pc);
	return 0;
}
