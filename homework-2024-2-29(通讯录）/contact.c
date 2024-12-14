#include "contact.h"

static void CheckCapacity(Contact* ps)
{
	if (ps->capacity == ps->size)
	{
		PeoInfo* ptr;
		ptr = (PeoInfo*)realloc(ps->date, (ps->capacity + 2) * sizeof(PeoInfo));
		if (NULL == ptr)
		{
			printf("%s\n", strerror(errno));
			return;
		}
		else
		{
			ps->date = ptr;
			ps->capacity += 2;
		}
	}
}
void LoadContact(Contact* ps)
{
	PeoInfo tmp = { 0 };
	FILE* PfRead = fopen("contact.dat", "rb");
	if (PfRead == NULL)
	{
		printf("LoadContact:%s\n", strerror(errno));
		return;
	}
	//��ȡ�ļ���ͨѶ¼��
	while(fread(&tmp, sizeof(PeoInfo), 1, PfRead))
	{
		CheckCapacity(ps);
		ps->date[ps->size] = tmp;
		ps->size++;
	}
	fclose(PfRead);
	PfRead = NULL;
}
void InitContact(Contact* ps)
{
	ps->date = (struct PeoInfo*)
		malloc(3 * sizeof(struct PeoInfo));
	if (NULL == ps->date)
	{
		printf("%s\n", strerror(errno));
		return 0;
	}
	ps->size = 0;
	ps->capacity = DEFAULT_SZ;
	//���ļ����Ѿ���ŵ�ͨѶ¼�е���Ϣ���ص�ͨѶ¼��
	LoadContact(ps);
}
void AddContact(Contact* ps)
{
	CheckCapacity(ps);
	printf("�������Ա�ţ�>");
	scanf("%d", &(ps->date[ps->size].vipNum));
	printf("���������֣�>");
	scanf("%s", ps->date[ps->size].name);
	printf("���������䣺>");
	scanf("%d", &(ps->date[ps->size].age));
	printf("�������Ա�>");
	scanf("%s", ps->date[ps->size].sex);
	printf("������绰��>");
	scanf("%s", ps->date[ps->size].tale);
	printf("�������ַ��>");
	scanf("%s", ps->date[ps->size].addr);
	printf("������������ڣ�>");
	scanf("%d", &(ps->date[ps->size].makeDay));
	printf("��������Ч���ڣ�>");
	scanf("%d", &(ps->date[ps->size].lastDay));
	ps->size++;
	printf("��ӳɹ�\n");
}
void ShowContact(const Contact* ps)
{
	if (0 == ps->size)
	{
		printf("ͨѶ¼Ϊ�գ���ȥ��Ӱ�\n");
	}
	else
	{
		int i = 0;
		printf("%s\t%-8s\t%-10s\t%-4s\t%-5s\t%-12s\t%-20s\t%-12s\t%-12s\n","���", "��Ա��", "����", "����", "�Ա�", "�绰", "��ַ","��������","��Ч����");
		for (i = 0; i < ps->size; i++)
		{
			printf("%2d\t%-8d\t%-10s\t%-4d\t%-5s\t%-12s\t%-20s\t%-12d\t%-12d\n",
				i+1, ps->date[i].vipNum, ps->date[i].name, ps->date[i].age, 
				ps->date[i].sex,ps->date[i].tale,ps->date[i].addr, ps->date[i].makeDay, ps->date[i].lastDay);
		}
	}
}
static int FindContactByname(const struct Contact* ps, const char name[MAX_NAME])
{
	int i = 0;
	for (i = 0; i < ps->size; i++)
	{
		if (0 == strcmp(ps->date[i].name, name))
		{
			break;
		}
	}
	if (i == ps->size)
	{
		return -1;
	}
	else
	{
		return i;
	}
}
void DelContact(struct Contact* ps)
{
	if (0 == ps->size)
	{
		printf("ɾ���ˣ��տ���Ҳ\n");
	}
	else
	{
		char name[MAX_NAME] = { 0 };
		printf("������Ҫɾ���˵����֣�>");
		scanf("%s", name);
		//1.����Ҫɾ�����˵�λ��
		int pos = FindContactByname(ps,name);
		//����Ҫɾ�����˵��±�
		//�ҵ��˷����±�
		// �Ҳ�������-1
		//2.ɾ��
		if (-1==pos)
		{
			printf("�Ҳ���\n");
		}
		else
		{
			//ɾ������
			int j = pos;
			for (j = pos; j < ps->size - 1; j++)
			{
				ps->date[j] = ps->date[j + 1];
			}
			ps->size--;
			system("cls");
			printf("ɾ���ɹ�\n");
		}
	}
}
void SearchContact(const struct Contact* ps)
{
	if (0 == ps->size)
	{
		printf("ͨѶ¼Ϊ�գ���ȥ��Ӱ�\n");
	}
	else
	{
		char name[MAX_NAME] = { 0 };
		printf("����������˵�����\n");
		scanf("%s", name);
		int pos = FindContactByname(ps,name);
		if (-1==pos)
		{
			printf("�Ҳ���\n");
		}
		else
		{
			printf("%s\t%-8s\t%-10s\t%-4s\t%-5s\t%-12s\t%-20s\t%-12s\t%-12s\n", "���", "��Ա��", "����", "����", "�Ա�", "�绰", "��ַ", "��������", "��Ч����");
			printf("%2d\t%-8d\t%-10s\t%-4d\t%-5s\t%-12s\t%-20s\t%-12d\t%-12d\n",
				pos + 1
				, ps->date[pos].vipNum
				, ps->date[pos].name
				, ps->date[pos].age,
				ps->date[pos].sex
				, ps->date[pos].tale
				, ps->date[pos].addr
				, ps->date[pos].makeDay
				, ps->date[pos].lastDay);

		}
	}
}
void ModifyContact(struct Contact* ps)
{
	if (0 == ps->size)
	{
		printf("ͨѶ¼Ϊ�գ���ȥ��Ӱ�\n");
	}
	else
	{
		char name[MAX_NAME] = { 0 };
		printf("������Ҫ�޸��˵����֣�>");
		scanf("%s", name);
		int pos = FindContactByname(ps, name);	
		if (-1 == pos)
		{
			printf("Ҫ�޸��˵���Ϣ������\n");
		}
		else
		{
			printf("%s\t%-8s\t%-10s\t%-4s\t%-5s\t%-12s\t%-20s\t%-12s\t%-12s\n", "���", "��Ա��", "����", "����", "�Ա�", "�绰", "��ַ", "��������", "��Ч����");
			printf("%2d\t%-8d\t%-10s\t%-4d\t%-5s\t%-12s\t%-20s\t%-12d\t%-12d\n",
				pos + 1
				, ps->date[pos].vipNum
				, ps->date[pos].name
				, ps->date[pos].age,
				ps->date[pos].sex
				, ps->date[pos].tale
				, ps->date[pos].addr
				, ps->date[pos].makeDay
				, ps->date[pos].lastDay);
			printf("�������Ա�ţ�>");
			scanf("%d", &(ps->date[pos].vipNum));
			printf("���������֣�>");
			scanf("%s", ps->date[pos].name);
			printf("���������䣺>");
			scanf("%d", &(ps->date[pos].age));
			printf("�������Ա�>");
			scanf("%s", ps->date[pos].sex);
			printf("������绰��>");
			scanf("%s", ps->date[pos].tale);
			printf("�������ַ��>");
			scanf("%s", ps->date[pos].addr);
			printf("������������ڣ�>");
			scanf("%d", &(ps->date[pos].makeDay));
			printf("��������Ч���ڣ�>");
			scanf("%d", &(ps->date[pos].lastDay));
			system("cls");
			printf("�޸ĳɹ�\n");
		}
	}
}
int NameCmp(const void* str1, const void* str2)
{
	return strcmp(str1, str2);
}
void BubbleSort(struct Contact* ps, size_t sz, int(*p)(const void*, const void*))
{
	int i = 0;
	struct PeoInfo* tmp = malloc(sizeof(struct PeoInfo));
	while (sz)
	{
		for (i = 0; i < sz-1; i++)
		{
			if (p(&((ps->date+i)->name), &((ps->date+i + 1)->name))>0)
			{
				if (NULL == tmp)
				{
					printf("%s\n", strerror(errno));
				}
				else
				{
					memcpy(tmp, (PeoInfo*)(ps->date) + i + 1, sizeof(struct PeoInfo));
					memcpy((PeoInfo*)(ps->date) + i+1, (PeoInfo*)(ps->date) + i, sizeof(struct PeoInfo));
					memcpy((PeoInfo*)(ps->date) + i, tmp, sizeof(struct PeoInfo));
				}
			}
		}
		sz--;
	}
	free(tmp);
	tmp = NULL;
}
void SortContact(struct Contact* ps)
{
	if (0 == ps->size)
	{
		printf("ͨѶ¼Ϊ�գ���ȥ��Ӱ�\n");
	}
	else
	{
		BubbleSort(ps, ps->size, NameCmp);
		ShowContact(ps);
	}
}
void SaveContact(Contact* ps)
{
	FILE* pfWrite = fopen("contact.dat", "wb");
	if (NULL == pfWrite)
	{
		printf("SaveContact:%s\n", strerror(errno));
		printf("����ʧ��\n");
		return;
	}
	//дͨѶ¼�����ݵ��ļ���
	int i = 0;
	for (i = 0; i < ps->size; i++)
	{
		fwrite(&(ps->date[i]), sizeof(PeoInfo), 1, pfWrite);
	}
	fclose(pfWrite);
	pfWrite = NULL;
}