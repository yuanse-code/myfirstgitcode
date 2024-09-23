#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

//int main()
//{
//	int a = 10;
//	int* p = &a;//p÷∏’Î±‰¡ø
//	printf("%d\n", *p);
//	printf("%d\n", sizeof(char*));
//	printf("%d\n", sizeof(int*));
//	int b = 0x11223344;
//	char* pa = (char*)&b;
//	*pa = 0;
//	/*int* pc = &b;
//	printf("%d\n", *pa);
//	printf("%d\n", *pc);*/
//	return 0;
//}
int main()
{
	int a = 0x11223344;
	int* pa = &a;
	char* pb = (char*)&a; 
	printf("%p\n", pa);
	printf("%p\n", pa+1);
	printf("%p\n", pb);
	printf("%p\n", pb+1);
	return 0;
}
