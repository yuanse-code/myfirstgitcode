#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<windows.h>
#include<stdlib.h>
int main()
{
	char password[20] = { 0 };
	char password2[20] = { 0 };
	int x = 0;
	int ch = 0;
	char ret = 'a';
	printf("�������룺>");
	scanf("%s", &password);
	printf("\n��ȷ�ϣ�Y/N��:>");
	while ((ch = getchar()) != '\n')
	{
		;
	}
	ret = getchar();
	if (ret == 'Y')
	{
		printf("ȷ�ϳɹ�");
	}
	else if (ret == 'N')
	{
		printf("ȡ��ȷ��");
		Sleep(1000);
		system("cls");
	}
	else
		printf("�������");
	Sleep(1000);
	system("cls");
	printf("�û���¼\n");
	for (x = 0;x < 3;x++)
	{
		printf("���������룺>");
		scanf("%s", &password2);
		while ((ch = getchar()) != '\n')
		{
			;
		}
		if (strcmp(password2, password) == 0)
		{
			printf("��¼�ɹ�\n");
			char arr1[] = { "welcome to bit!!!!!!" };
			char arr2[] = { "####################" };
			int right = strlen(arr1) - 1;
			int left = 0;
			for (left = 0;left <= right;left++, right--)
			{
				arr2[left] = arr1[left];
				arr2[right] = arr1[right];
				Sleep(1000);
				system("cls");
				printf(arr2);
			}
			break;
		}
		else
		printf("�������\n");
	}
	if(x==3)
	{
		printf("������������˳���¼");
		Sleep(1000);
		system("cls");
	}	
	return 0;
} 
