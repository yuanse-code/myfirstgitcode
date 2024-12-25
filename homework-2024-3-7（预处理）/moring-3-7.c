#define _CRT_SECURE_NO_WARNINGS 1
#include "D:/vsc++代码/mine.h"

//extern int Add(int x, int y);
//int main()
//{
//	int a = 10;
//	int b = 20;
//	int arr[10] = { 0 };
//	int i = 0;
//	for (i = 0; i < 10; i++)
//	{
//		arr[i] = i;
//	}
//	Print(arr, 10, "%d");
//	int c = Add(a, b);
//	printf("c=%d\n", c);
//	return 0;
//}
//int main()
//{
//	/*printf("%s\n",__FILE__);
//	printf("%d\n", __LINE__);
//	printf("%s\n", __DATE__);
//	printf("%s\n", __TIME__);*/
//
//	//写日志文件
//	int i = 0;
//	int arr[10] = { 0 };
//	FILE* pf = fopen("log.txt", "w");
//	for (i = 0; i < 10; i++)
//	{
//		arr[i] = i;
//		fprintf(pf, "file:%s line:%d date:%s time:%s i=%d\n", __FILE__, __LINE__, __DATE__, __TIME__, i);
//		printf("%s\n", __FUNCTION__);
//	}
//	Print(arr, 10, "%d");
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}
//#define MAX 100
//#define STR "hehe"
//#define reg register
//#define do_foever for(;;)
//int main()
//{
//	/*int max = MAX;
//	printf("%d\n", max);*/
//	//printf("%d\n", __STDC__);
//	/*reg int a;
//	printf("%s\n", STR);*/
//	do_foever;
//	return 0;
//}
//#define SQUARE(x) (x)*(x)
//int main()
//{
//	//int ret = SQUARE(5);
//	////int ret = 5 * 5;
//	//printf("%d\n", ret);
//	int ret = SQUARE(5 + 1);
//	printf("%d\n", ret);
//	return 0;
//}
//#define MAX 100
//#define DOUBLE(x) ((x)+(x))
//int main()
//{
//	int a = 5;
//	int ret = 10 * DOUBLE(MAX);
//	printf("%d\n", ret);
//	return 0;
//}
//void print(int a)
//{
//	printf("the value of a is %d\n", a);
//}
//int main()
//{
//	int a = 10;
//	int b = 20;
//	//printf("the value of a is %d\n", a);
//	print(a);
//	print(b);
//	return 0;
//}
//#define PRINT(x) printf("the value of "#x" is %d\n",x);
//int main()
//{
//	/*printf("hello world\n");
//	printf("hel"   "lo "   "world\n");*/
//	int a = 10;
//	int b = 20;
//	PRINT(a);
//	//printf("the value of " "a" " is %d\n",a);
//	PRINT(b);
//	//printf("the value of " "b" " is %d\n",b);
//	return 0;
//}
//#define CAT(x,y) x##y
//int main()
//{
//	int Class84 = 2019;
//	printf("%d\n", CAT(Class, 84));
//	//printf("%d\n",Class##84);
//	return 0;
//}
//#define MAX(x,y) ((x)>(y)?(x):(y))
//int main()
//{
//	int a = 10;
//	/*int b = a + 1;
//	int b = ++a;*/
//	int b = 11;
//	int max = MAX(a++, b++);
//	//int max=((a++)>(b++)?(a++):(b++));
//	printf("%d\n", max);
//	printf("%d %d\n", a, b);
//	return 0;
//}

//float Max2(float x, float y)
//{
//	return (x > y ? x : y);
//}
//int Max(int x, int y)
//{
//	return (x > y ? x : y);
//}
//#define MAX(X,Y) ((X)>(Y)?(X):(Y))
//int main()
//{
//	int a = 10;
//	int b = 20;
//	float c = 3.0f;
//	float d = 4.0f;
//	float max = Max2(c, d);
//	printf("%f\n", max);
//	max = MAX(c,d);
//	printf("%f\n", max);
//	return 0;
//}
//#define TEST(X,Y) printf("test\n")
//int main()
//{
//	TEST();
//	//printf("test\n");
//	TEST();
//	//printf("test\n");
//	return 0;
//}
//#define SIZEOF(type) sizeof(type)
//int main()
//{
//	int ret = SIZEOF(int);
//	printf("%d\n", ret);
//	return 0;
//}
//#define MALLOC(num, type) (type*)malloc((num)*sizeof(type))
//int main()
//{
//	//int* p = (int*)malloc(10 * sizeof(int));
//	int* p = MALLOC(10, int);
//	free(p);
//	p = NULL;
//	return 0;
//}
//#define MAX 100
//int main()
//{
//	printf("%d\n", MAX);
//#undef MAX
//	//printf("%d\n", MAX);
//	return 0;
//}
//#define DEBUG
int main()
{
	int arr[10] = { 1,2,3,4,5,6,7,8,9,0 };
	int i = 0;
	for (i = 0; i < 10; i++)
	{
		arr[i] = 0;
#ifdef DEBUG
		printf("%d ", arr[i]);
#endif 
	}
	return 0;
}