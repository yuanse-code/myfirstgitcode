#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>

int main()
{
	char password [20] = { 0 };
	int ch = 0;
	char ret = 0;
	printf("���������룺");
	scanf("%s", password);
	printf("��ȷ�ϣ�Y/N��:");
	while ((ch = getchar()) != '\n')
	{
		;
	}
	ret = getchar();
	if (ret != 'Y' && ret != 'N')
	{
		printf("�������\n");
	}
	if (ret == 'Y')
	{
		printf("ȷ�ϳɹ�\n");
	}
	else
	{
		printf("ȡ��ȷ��\n");
	}
	int a = 10;
	printf("%d",a);
}