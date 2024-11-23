#define _CRT_SECURE_NO_WARNINGS 1
#include <D:/vsc++代码/mine.h>
#include <errno.h>
#include <ctype.h>

//strtok
//int main()
//{
//	//192.268.31.121
//	//192 262 31 121-strtok
//	//点分十进制的表示方式
//	char arr[] = "192.268.31.121";
//	char* p = ".";
//	//zpw@bitedu.tech
//	//zpw bitedu tech -strtok
//
//	/*char arr[] = "zpw@bitedu.tech";
//	char* p = "@.";*/
//	char buf[1024] = { 0 };
//	strcpy(buf, arr);
//	//切割buf中的字符串
//	/*char* ret=strtok(arr, p);
//	printf("%s\n", ret);
//	ret = strtok(NULL, p);
//	printf("%s\n", ret);
//	ret = strtok(NULL, p);
//	printf("%s\n", ret);
//	ret = strtok(NULL, p);
//	printf("%s\n", ret);*/
//	char* ret = NULL;
//	for (ret = strtok(arr, p); ret != NULL;ret=strtok(NULL,p))//有静态变量
//	{
//		printf("%s\n", ret);
//	}
//	return 0;
//}
//strerror
//int main()
//{
//	//c语言的
//	//错误码
//	//0-    No error
//	//1-    Operation not permitted
//	//2-    No such file or directory
//	//...
//	//errno 是一个全局的错误码的变量
//	//当c语言的库函数在执行过程中，发生了错误，就会把对应的错误码，赋值到errno中
//	//char* str = strerror(errno);
//	//printf("%s\n", str);
//	//打开文件
//	FILE* pf=fopen("开头.txt","r");
//	if (pf == NULL)
//	{
//		printf("%s\n", strerror(errno));
//	}
//	else
//	{
//		printf("open file success\n");
//	}
//	return 0;
// }
//字符分类函数
int main()
{
	//char ch = '@';
	////int ret=islower(ch);
	//int ret = isdigit(ch);
	//printf("%d\n", ret);
	//字符转换函数
	//char ch = tolower('q');
	//char ch = toupper('q');
	//putchar(ch);
	char arr[] = "I Am Student";
	int i = 0;
	while (arr[i])
	{
		if (isupper(arr[i]))
		{
			arr[i]=tolower(arr[i]);
		}
		i++;
	}
	printf("%s\n", arr);
	return 0;
}