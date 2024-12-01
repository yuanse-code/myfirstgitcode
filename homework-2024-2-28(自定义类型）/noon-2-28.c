#define _CRT_SECURE_NO_WARNINGS 1
#include "D:/vsc++代码/mine.h"

//struct S 
//{
//	int a;
//	char c;
//	double d;
//};
//void Init(struct S* ps)
//{
//	ps->a = 100;
//	ps->c = 'w';
//	ps->d = 3.14;
//}
//void Print1(const struct S* tmp)
//{
//	printf("%d %c %lf\n", tmp->a, tmp->c, tmp->d);
//}
//int main()
//{
//	struct S s = { 0 };
//	Init(&s);
//	Print1(&s);
//	/*s.a = 100;
//	s.c = 'w';
//	s.d = 3.14;*/
//	return 0;
//}
//位段
//struct S
//{
//	//int a : 2;//2bit
//	//int b : 5;//5bit
//	//int c : 10;//10bit
//	//int d : 30;//30bit
//	char a : 3;
//	char b : 4;
//	char c : 5;
//	char d : 4;
//};
//int main()
//{
//	/*struct S s;
//	printf("%d\n", sizeof(s));*/
//	struct S s = {0};
//	s.a = 10;//1/010
//	s.b = 20;//1/0100
//	s.c = 3;//11
//	s.d = 4;//100
//	return 0;
//}
//枚举
//enum Sex
//{
//	MALE=2,
//	FEMALE,//3
//	SECRET=8
//};
//enum COLOR
//{
//	RED,//0
//	GREEN,//1
//	BLUE//2
//};
////
////#define RED 0
////#define GREEN 1
////#define BLUE 2
//int main()
//{
//	enum SEX s = MALE;
//	enum COLOR c = BLUE;
//	printf("%d\n", sizeof(s));
//	printf("%d %d %d\n", RED, GREEN, BLUE);
//	printf("%d %d %d\n", MALE, FEMALE, SECRET);
//	return 0;
//}
//联合体
//union Un
//{
//	char c;
//	int i;
//};
//int main()
//{
//	union Un u;
//	printf("%d\n", sizeof(u));
//	printf("%p\n", &u);
//	printf("%p\n", &(u.c));
//	printf("%p\n", &(u.i));
//	return 0;
//}
//int check_system()
//{
//	int a = 1;
//	return (int)*(char*)&a;
//}
int check_system()
{
	union Un
	{
		char c;
		int i ;
	}u;
	u.i = 1;
	return u.c;
}
////小返1
////大返0
int main()
{
	//大小端字节序问题
	int ret = check_system();
	int a = 1;
	if (ret)
	{
		printf("小端存储模式\n");
	}
	else
	{
		printf("大端存储模式\n");
	}
	return 0;
}