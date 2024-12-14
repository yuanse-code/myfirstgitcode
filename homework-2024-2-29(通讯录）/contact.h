#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include <Windows.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <errno.h>

#define DEFAULT_SZ 3
#define MAX_NAME 20
#define MAX_SEX 5
#define MAX_TALE 12
#define MAX_ADDR 30

enum Option
{
	EXIT,
	ADD,
	DEL,
	SEARCH,
	MODIFY,
	SHOW,
	SORT,
	SAVE
};
typedef struct PeoInfo
{  
	int vipNum;
	char name[MAX_NAME];
	int age;
	char sex[MAX_SEX];
	char tale[MAX_TALE];
	char addr[MAX_ADDR];
	int makeDay;
	int lastDay;
}PeoInfo;
typedef struct Contact
{
	int size;
	struct PeoInfo* date;
	int capacity;
}Contact;
//��ʼ��ͨѶ¼
void InitContact(Contact* ps);
//���Ӻ���
void AddContact(Contact* ps);
//��ӡ
void ShowContact(const Contact* ps);
//ɾ��
void DelContact(Contact* ps);
//����
void SearchContact(const Contact* ps);
//�޸�
void ModifyContact(Contact* ps);
//����
void SortContact(Contact* ps);
//�洢
void SaveContact(Contact* ps);
//�����ļ��е���Ϣ��ͨѶ¼
void LoadContact(Contact* ps);