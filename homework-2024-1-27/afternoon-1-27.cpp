#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

//struct stu
//{
//	char name[10];
//	short age;
//	char tele[12];
//	char sex[5];
//}s1,s2,s3;//不建议全局变量
typedef struct stu
{
	char name[10];
	short age;
	char tele[12];
	char sex[5];
}stu;//不建议全局变量
int main()
{
	struct stu s;
	s.age = 20;
	printf("%d", sizeof(s));
	return 0;
}
