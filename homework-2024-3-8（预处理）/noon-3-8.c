#define _CRT_SECURE_NO_WARNINGS 1
#include "../mine.h"
#include "add.h"
#include <stddef.h>
// 
//#include ""
//#include <>
//
int main()
{
	int* p = (int*)malloc(0);
	return 0;
}

//#define  OFFSETOF(struct_name,member_name)  (int)(&(((struct_name*)0)->member_name))
//struct S
//{
//	char c1;
//	int a;
//	char c2;
//};
//int main()
//{
//	//struct S s;
//	//offsetof  
//	printf("%d\n", OFFSETOF(struct S, c1));
//	printf("%d\n", OFFSETOF(struct S, a));
//	printf("%d\n", OFFSETOF(struct S, c2));
//	return 0;
//}

//int main()
//{
//	int ret = Add(2, 3);
//	printf("ret=%d\n", ret);
//	return 0;
//}
//#define DEBUG 0
//int main()
//{
////#if defined(DEBUG)
////	printf("hehe\n");
////#endif
////#ifdef DEBUG
////	printf("hehe\n");
////#endif
////#if !defined(DEBUG)
////	printf("hehe\n");
////#endif
//#ifndef DEBUG
//	printf("hehe\n");
//#endif
//	return 0;
//}
//int main()
//{
//#if  1==2
//	printf("haha\n");
//#elif 2==2
//	printf("hehe\n");
//#else
//	printf("ºÙºÙ\n");
//#endif
//	return 0;
//}