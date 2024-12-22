#define _CRT_SECURE_NO_WARNINGS 1
#include "D:/vsc++代码/mine.h"
#include <math.h>

//int My_abs(int x)
//{
//	if (x>=0)
//	{
//		return x;
//	}
//	else
//	{
//		unsigned int a = ~((unsigned int)x- 1);
//		return (int)a;
//	}
//}
//int main()
//{
//	int a = -10;
//	a= My_abs(a);
//	printf("%d\n", a);
//	return 0;
//}
//int main()
//{
//	int a = 3;
//	int b = 1;
//	a = a ^ b;
//	b = a ^ b;
//	a = a ^ b;
//	printf("%d %d\n", a, b);
//	return 0;
//}
//struct S
//{
//	char name[20];
//	int age;
//	double score;
//};
//int main()
//{
//	//struct S s = {"张三",20,55.6};
//	struct S tmp = { 0 };
//	FILE* pf = fopen("text.txt", "rb");
//	if (NULL == pf)
//	{
//		return 0;
//	}
//	//二进制的形式写文件
//	//fwrite(&s, sizeof(struct S), 1, pf);
//	fread(&tmp, sizeof(struct S), 1, pf);
//	printf("%s %d %lf\n", tmp.name, tmp.age, tmp.score);
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}
int main()
{
	FILE* pf = fopen("text.txt", "r");
	if (NULL == pf)
	{
		return 0;
	}
	//1.定位文件
	fseek(pf, -2, SEEK_END);
	//2.读取文件
	char ch=fgetc(pf);
	printf("%c\n", ch);
	fclose(pf);
	pf = NULL;
	return 0;
}