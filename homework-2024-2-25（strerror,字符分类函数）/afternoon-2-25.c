#define _CRT_SECURE_NO_WARNINGS 1
#include <D:/vsc++����/mine.h>
#include <errno.h>
#include <ctype.h>

//strtok
//int main()
//{
//	//192.268.31.121
//	//192 262 31 121-strtok
//	//���ʮ���Ƶı�ʾ��ʽ
//	char arr[] = "192.268.31.121";
//	char* p = ".";
//	//zpw@bitedu.tech
//	//zpw bitedu tech -strtok
//
//	/*char arr[] = "zpw@bitedu.tech";
//	char* p = "@.";*/
//	char buf[1024] = { 0 };
//	strcpy(buf, arr);
//	//�и�buf�е��ַ���
//	/*char* ret=strtok(arr, p);
//	printf("%s\n", ret);
//	ret = strtok(NULL, p);
//	printf("%s\n", ret);
//	ret = strtok(NULL, p);
//	printf("%s\n", ret);
//	ret = strtok(NULL, p);
//	printf("%s\n", ret);*/
//	char* ret = NULL;
//	for (ret = strtok(arr, p); ret != NULL;ret=strtok(NULL,p))//�о�̬����
//	{
//		printf("%s\n", ret);
//	}
//	return 0;
//}
//strerror
//int main()
//{
//	//c���Ե�
//	//������
//	//0-    No error
//	//1-    Operation not permitted
//	//2-    No such file or directory
//	//...
//	//errno ��һ��ȫ�ֵĴ�����ı���
//	//��c���ԵĿ⺯����ִ�й����У������˴��󣬾ͻ�Ѷ�Ӧ�Ĵ����룬��ֵ��errno��
//	//char* str = strerror(errno);
//	//printf("%s\n", str);
//	//���ļ�
//	FILE* pf=fopen("��ͷ.txt","r");
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
//�ַ����ຯ��
int main()
{
	//char ch = '@';
	////int ret=islower(ch);
	//int ret = isdigit(ch);
	//printf("%d\n", ret);
	//�ַ�ת������
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