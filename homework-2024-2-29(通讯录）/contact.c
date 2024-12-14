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
	//读取文件到通讯录中
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
	//把文件中已经存放的通讯录中的信息加载到通讯录中
	LoadContact(ps);
}
void AddContact(Contact* ps)
{
	CheckCapacity(ps);
	printf("请输入会员号：>");
	scanf("%d", &(ps->date[ps->size].vipNum));
	printf("请输入名字：>");
	scanf("%s", ps->date[ps->size].name);
	printf("请输入年龄：>");
	scanf("%d", &(ps->date[ps->size].age));
	printf("请输入性别：>");
	scanf("%s", ps->date[ps->size].sex);
	printf("请输入电话：>");
	scanf("%s", ps->date[ps->size].tale);
	printf("请输入地址：>");
	scanf("%s", ps->date[ps->size].addr);
	printf("请输入办理日期：>");
	scanf("%d", &(ps->date[ps->size].makeDay));
	printf("请输入有效日期：>");
	scanf("%d", &(ps->date[ps->size].lastDay));
	ps->size++;
	printf("添加成功\n");
}
void ShowContact(const Contact* ps)
{
	if (0 == ps->size)
	{
		printf("通讯录为空，快去添加吧\n");
	}
	else
	{
		int i = 0;
		printf("%s\t%-8s\t%-10s\t%-4s\t%-5s\t%-12s\t%-20s\t%-12s\t%-12s\n","序号", "会员号", "名字", "年龄", "性别", "电话", "地址","办理日期","有效日期");
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
		printf("删光了，空空如也\n");
	}
	else
	{
		char name[MAX_NAME] = { 0 };
		printf("请输入要删除人的名字：>");
		scanf("%s", name);
		//1.查找要删除的人的位置
		int pos = FindContactByname(ps,name);
		//查找要删除的人的下标
		//找到了返回下标
		// 找不到返回-1
		//2.删除
		if (-1==pos)
		{
			printf("找不到\n");
		}
		else
		{
			//删除数据
			int j = pos;
			for (j = pos; j < ps->size - 1; j++)
			{
				ps->date[j] = ps->date[j + 1];
			}
			ps->size--;
			system("cls");
			printf("删除成功\n");
		}
	}
}
void SearchContact(const struct Contact* ps)
{
	if (0 == ps->size)
	{
		printf("通讯录为空，快去添加吧\n");
	}
	else
	{
		char name[MAX_NAME] = { 0 };
		printf("请输入查找人的名字\n");
		scanf("%s", name);
		int pos = FindContactByname(ps,name);
		if (-1==pos)
		{
			printf("找不到\n");
		}
		else
		{
			printf("%s\t%-8s\t%-10s\t%-4s\t%-5s\t%-12s\t%-20s\t%-12s\t%-12s\n", "序号", "会员号", "名字", "年龄", "性别", "电话", "地址", "办理日期", "有效日期");
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
		printf("通讯录为空，快去添加吧\n");
	}
	else
	{
		char name[MAX_NAME] = { 0 };
		printf("请输入要修改人的名字：>");
		scanf("%s", name);
		int pos = FindContactByname(ps, name);	
		if (-1 == pos)
		{
			printf("要修改人的信息不存在\n");
		}
		else
		{
			printf("%s\t%-8s\t%-10s\t%-4s\t%-5s\t%-12s\t%-20s\t%-12s\t%-12s\n", "序号", "会员号", "名字", "年龄", "性别", "电话", "地址", "办理日期", "有效日期");
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
			printf("请输入会员号：>");
			scanf("%d", &(ps->date[pos].vipNum));
			printf("请输入名字：>");
			scanf("%s", ps->date[pos].name);
			printf("请输入年龄：>");
			scanf("%d", &(ps->date[pos].age));
			printf("请输入性别：>");
			scanf("%s", ps->date[pos].sex);
			printf("请输入电话：>");
			scanf("%s", ps->date[pos].tale);
			printf("请输入地址：>");
			scanf("%s", ps->date[pos].addr);
			printf("请输入办理日期：>");
			scanf("%d", &(ps->date[pos].makeDay));
			printf("请输入有效日期：>");
			scanf("%d", &(ps->date[pos].lastDay));
			system("cls");
			printf("修改成功\n");
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
		printf("通讯录为空，快去添加吧\n");
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
		printf("保存失败\n");
		return;
	}
	//写通讯录中数据到文件中
	int i = 0;
	for (i = 0; i < ps->size; i++)
	{
		fwrite(&(ps->date[i]), sizeof(PeoInfo), 1, pfWrite);
	}
	fclose(pfWrite);
	pfWrite = NULL;
}