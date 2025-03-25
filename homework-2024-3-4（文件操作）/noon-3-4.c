#define _CRT_SECURE_NO_WARNINGS 1
#include "mine.h"
#include <errno.h>
#include <Windows.h>

//int main()
//{
//	/*int a = 1000;
//	FILE* pf = fopen("text.txt", "wb");
//	fwrite(&a, 4, 1, pf);
//	fclose(pf);
//	pf = NULL;*/
//	FILE* pf=fopen("text.txt", "wb");
//	if (pf == NULL)
//	{
//		printf("%s\n", strerror(errno));
//	}
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}
//int main()
//{
//	FILE* pfRead = fopen("TEXT.txt", "r");//大小写不敏感
//	if (pfRead == NULL)
//	{
//		printf("%s\n", strerror(errno));
//	}
//	printf("%c", fgetc(pfRead));
//	printf("%c", fgetc(pfRead));
//	printf("%c", fgetc(pfRead));
//	fclose(pfRead);
//	pfRead = NULL;
//	return 0;
//}
//int main()
//{
//	int ch = fgetc(stdin);
//	fputc(ch, stdout);
//	return 0;
//}
//int main()
//{
//	char buf[1024] = { 0 };
//	FILE* pf=fopen("text.txt", "w");
//	if (NULL == pf)
//	{
//		printf("%s\n", strerror(errno));
//		return 0;
//	}
//	//写文件1
//	/*fputc("b",pf);
//	fputc("i", pf);
//	fputc("t", pf);*/
//	//写文件1
//	fputs("hello\n", pf);
//	fputs("world\n", pf);
//	//读文件1
//	/*int ch = fgetc(pf);
//	printf("%c", ch);
//	ch = fgetc(pf);
//	printf("%c", ch);
//	ch = fgetc(pf);
//	printf("%c", ch);*/
//	//读文件2
//	//fgets(buf, 1024, pf);
//	////printf("%s", buf);
//	//puts(buf);
//	//fgets(buf, 1024, pf);
//	////printf("%s", buf);
//	//puts(buf);
//	//关闭文件
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}
//int main()
//{
//	char buf[1024] = {0};
//	//fgets(buf,1024,stdin);//从标准输入流读取
//	//fputs(buf, stdout);//输出到标准输出流
//	gets(buf);
//	puts(buf);
//	return 0;
//}
struct S
{
	int n;
	float score;
	char arr[10];
};
//int main()
//{
//	struct S s = { 0 };
//	FILE* pf = fopen("text.txt", "r");
//	if (pf == NULL)
//	{
//		printf("%s\n", strerror(errno));
//		return 0;
//	}
//	//fprintf(pf,"%d %f %s",s.n,s.score,s.arr);//写
//	fscanf(pf,"%d %f %s", &(s.n), &(s.score), &(s.arr));
//	printf("%d %f %s", s.n, s.score, s.arr);
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}
//int main()
//{
//	struct S s= { 0 };
//	fscanf(stdin, "%d %f %s", &(s.n), &(s.score), &(s.arr));
//	fprintf(stdout,"%d %.2f %s", s.n, s.score, s.arr);
//	return 0;
//}
int main()
{
	struct S s={100,3.14,"abcdef"};
	struct S tmp = { 0 };
	char buf[1024] = { 0 };
	sprintf(buf, "%d %f %s", s.n, s.score, s.arr);
	//printf("%s\n", buf);
	//从buf中读取格式化的数据到tmp
	sscanf(buf, "%d %f %s", &(tmp.n), &(tmp.score), &(tmp.arr));
	printf("%d %f %s", tmp.n, tmp.score, tmp.arr);
	return 0;
}