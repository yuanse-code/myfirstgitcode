#define _CRT_SECURE_NO_WARNINGS 1
#include "mine.h"

//int main()
//{
//	//EOF
//	//feof();//EOF-文件结束标志
//	FILE* pf = fopen("test.txt", "r");
//	if (pf == NULL)
//		return 0;
//	int ch = fgetc(pf);
//	printf("%d\n", ch);
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}
int main()
{
	//strerror
	//perror
	FILE* pf = fopen("test.txt","r");
	if (pf == NULL)
	{
		perror("open file test2.txt");
		return 0;
	}
	//读文件
	int ch = 0;
	while ((ch = fgetc(pf)) != EOF)
	{
		putc(ch,stdout);
	}
	if (ferror(pf))
	{
		printf("error\n");
	}
	else if (feof(pf))
	{
		printf("end of file\n");
	}
	fclose(pf);
	pf = NULL;
	return 0;
}