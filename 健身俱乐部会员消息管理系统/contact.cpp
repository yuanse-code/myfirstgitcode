#include "contact.h"
#include "健身俱乐部会员消息管理系统.h"
#include "avlTree.h"

static void CheckCapacity(Contact* ps)
{
	if (ps->capacity == ps->size)
	{
		PeoInfo* ptr;
		ptr = (PeoInfo*)realloc(ps->date, (ps->capacity + 2) * sizeof(PeoInfo));
		if (NULL == ptr)
		{
			FILE* bufferPf = fopen("缓冲.txt", "a");
			fprintf(bufferPf,"%s\n", strerror(errno));
			fclose(bufferPf);
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
		FILE* bufferPf = fopen("缓冲.txt", "a");
		fprintf(bufferPf,"LoadContact:%s\n", strerror(errno));
		fclose(bufferPf);
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
void AddContact(Contact* ps, HWND* arrHwndEdit)
{
	CheckCapacity(ps);
	char tmp[50];
	GetWindowTextA(arrHwndEdit[2], tmp, 50);
	sscanf(tmp, "%d", &(ps->date[ps->size].vipNum));//输入会员号
	GetWindowTextA(arrHwndEdit[3], tmp, 50);
	sscanf(tmp, "%s", ps->date[ps->size].name);//输入名字
	GetWindowTextA(arrHwndEdit[4], tmp, 50);
	sscanf(tmp, "%d", &(ps->date[ps->size].age));//输入年龄
	GetWindowTextA(arrHwndEdit[5], tmp, 50);
	sscanf(tmp, "%s", ps->date[ps->size].sex);//输入性别
	GetWindowTextA(arrHwndEdit[6], tmp, 50);
	sscanf(tmp, "%s", ps->date[ps->size].tale);//输入电话
	GetWindowTextA(arrHwndEdit[7], tmp, 50);
	sscanf(tmp, "%s", ps->date[ps->size].addr);//输入地址
	int inttmp;
	int day[3];
	int i = 0;
	for (i = 0; i < 3; ++i)
	{
		GetWindowTextA(arrHwndEdit[8 + i], tmp, 50);
		sscanf(tmp, "%d", &inttmp);
		day[i] = inttmp;
	}
	ps->date[ps->size].makeDay = day[2] + day[1] * 100 + day[0] * 10000;//办理日期
	for (i = 0; i < 3; ++i)
	{
		GetWindowTextA(arrHwndEdit[11 + i], tmp, 50);
		sscanf(tmp, "%d", &inttmp);
		day[i] = inttmp;
	}
	ps->date[ps->size].lastDay = day[2] + day[1] * 100 + day[0] * 10000;//有效日期
	ps->size++;
	//添加成功;
}
void InitContact(Contact* ps)
{
	ps->date = (struct PeoInfo*)
		malloc(DEFAULT_SZ * sizeof(struct PeoInfo));
	if (NULL == ps->date)
	{
		FILE* bufferPf = fopen("缓冲.txt", "a");//w//r
		fprintf(bufferPf,"%s\n", strerror(errno));
		fclose(bufferPf);
		return ;
	}
	ps->size = 0;
	ps->capacity = DEFAULT_SZ;
	//把文件中已经存放的通讯录中的信息加载到通讯录中
	LoadContact(ps);
}

void ShowContact(const Contact* ps)
{
	FILE* bufferPf = fopen("缓冲.txt", "a");
	if (0 == ps->size)
	{
		fprintf(bufferPf,"通讯录为空，快去添加吧\n");
	}
	else
	{
		int i = 0;
		fprintf(bufferPf,"%s\t%-12s\t%-10s\t%-4s\t%-5s\t%-20s\t%-20s\t%-12s\t%-12s\n", "序号", "会员号", "名字", "年龄", "性别", "电话", "地址", "办理日期", "有效日期");
		for (i = 0; i < ps->size; i++)
		{
			int year1; int month1; int day1;
			int year2; int month2; int day2;
			day1 = ps->date[i].makeDay % 100;month1 = (ps->date[i].makeDay % 10000)/100;
			year1 = ps->date[i].makeDay / 10000;
			day2 = ps->date[i].lastDay % 100; month2 = (ps->date[i].lastDay % 10000)/100;
			year2 = ps->date[i].lastDay / 10000;
			fprintf(bufferPf, "%2d\t%-12d\t%-10s\t%-4d\t%-5s\t%-20s\t%-20s\t%d年%d月%d日\t%d年%d月%d日\n",
				i + 1, ps->date[i].vipNum, ps->date[i].name, ps->date[i].age,
				ps->date[i].sex, ps->date[i].tale, ps->date[i].addr, 
				year1,month1,day1, year2, month2, day2);
		}
	}
	fclose(bufferPf);
	bufferPf = NULL;
}
static int FindContactByname(const struct Contact* ps, const char name[MAX_NAME])
{
	int i = 0;
	for (i = 0; i < ps->size; i++)
	{
		if (0 == strcmp(ps->date[i].name, name))
		{
			return i;
		}
	}
	if (i == ps->size)
	{
		return -1;
	}
}
static int deletePos = -1;
void DelContact(struct Contact* ps)
{
	//删除数据
	int j = deletePos;
	for (j = deletePos; j < ps->size - 1; j++)
	{ 
		ps->date[j] = ps->date[j + 1];
	}
	ps->size--;
}
int SearchContact(const struct Contact* ps, HWND hWnd, HWND* arrHwndEdit)
{
	int i = 0;
	if (0 == ps->size)
	{
		SetDlgItemTextA(hWnd, EIDT_INPUT1, "通讯录为空，快去添加吧\r\n");
	}
	else
	{
		char bufferPf[300];
		char name[MAX_NAME] = { 0 };
		GetWindowTextA(arrHwndEdit[1], bufferPf, 150);//输入查找人的名字:
		sscanf(bufferPf,"%19s", name);
		name[19] = '\0';
		if (0 == strcmp(name, "请输入查找人的名字:"))
		{
			sscanf(bufferPf + 19, "%s", name);
			if (*(bufferPf + 19) == '\0')
				return 3;
		}
		else
		{
			sscanf(bufferPf, "%s", name);
		}
		int pos = FindContactByname(ps,name);
		if (-1==pos)
		{
			sprintf(bufferPf,"找不到\r\n");
			SetDlgItemTextA(hWnd, EIDT_INPUT2, bufferPf);
			return 0;
		}
		else
		{
			i = sprintf(bufferPf, "%s\t%-12s\t%-10s\t%-4s\t%-5s\t%-20s\t%-20s\t%-12s\t%-12s\r\n", "序号", "会员号", "名字", "年龄", "性别", "电话", "地址", "办理日期", "有效日期");
			int year1; int month1; int day1;
			int year2; int month2; int day2;
			day1 = ps->date[pos].makeDay % 100; month1 = (ps->date[pos].makeDay % 10000) / 100;
			year1 = ps->date[pos].makeDay / 10000;
			day2 = ps->date[pos].lastDay % 100; month2 = (ps->date[pos].lastDay % 10000) / 100;
			year2 = ps->date[pos].lastDay / 10000;
			sprintf(bufferPf+i, "%2d\t%-12d\t%-10s\t%-4d\t%-5s\t%-20s\t%-20s\t%d年%d月%d日\t%d年%d月%d日\r\n",
				pos + 1, ps->date[pos].vipNum, ps->date[pos].name, ps->date[pos].age,
				ps->date[pos].sex, ps->date[pos].tale, ps->date[pos].addr,
				year1, month1, day1, year2, month2, day2);
			deletePos = pos;
			SetDlgItemTextA(hWnd, EIDT_INPUT2, bufferPf);
			return 1;
		}
	}
}
void ModifyDisplayContact(struct Contact* ps, HWND* arrHwndEdit)
{
	int pos;
	pos = deletePos;
	char tmp[50];
	sprintf(tmp, "%d", ps->date[pos].vipNum);//显示会员号
	SetWindowTextA(arrHwndEdit[2], tmp);
	SetWindowTextA(arrHwndEdit[3], ps->date[pos].name);//显示名字
	sprintf(tmp, "%d", ps->date[pos].age);//显示年龄
	SetWindowTextA(arrHwndEdit[4], tmp);
	SetWindowTextA(arrHwndEdit[5], ps->date[pos].sex);//显示性别
	SetWindowTextA(arrHwndEdit[6], ps->date[pos].tale);//显示电话
	SetWindowTextA(arrHwndEdit[7], ps->date[pos].addr);//显示地址
	//显示日期
	sprintf(tmp, "%d", (ps->date[pos].makeDay) / 10000);//年
	SetWindowTextA(arrHwndEdit[8], tmp);
	sprintf(tmp, "%d", ((ps->date[pos].makeDay) % 10000) / 100);//月
	SetWindowTextA(arrHwndEdit[9], tmp);
	sprintf(tmp, "%d", (ps->date[pos].makeDay) % 100);//日
	SetWindowTextA(arrHwndEdit[10], tmp);

	sprintf(tmp, "%d", (ps->date[pos].lastDay) / 10000);//年
	SetWindowTextA(arrHwndEdit[11], tmp);
	sprintf(tmp, "%d", ((ps->date[pos].lastDay) % 10000) / 100);//月
	SetWindowTextA(arrHwndEdit[12], tmp);
	sprintf(tmp, "%d", (ps->date[pos].lastDay) % 100);//日
	SetWindowTextA(arrHwndEdit[13], tmp);
}
void ModifyAddContact(struct Contact* ps, HWND* arrHwndEdit)
{
	int pos;
	pos = deletePos;
	char tmp[50];
	GetWindowTextA(arrHwndEdit[2], tmp, 50);
	sscanf(tmp, "%d", &(ps->date[pos].vipNum));//输入会员号
	GetWindowTextA(arrHwndEdit[3], tmp, 50);
	sscanf(tmp, "%s", ps->date[pos].name);//输入名字
	GetWindowTextA(arrHwndEdit[4], tmp, 50);
	sscanf(tmp, "%d", &(ps->date[pos].age));//输入年龄
	GetWindowTextA(arrHwndEdit[5], tmp, 50);
	sscanf(tmp, "%s", ps->date[pos].sex);//输入性别
	GetWindowTextA(arrHwndEdit[6], tmp, 50);
	sscanf(tmp, "%s", ps->date[pos].tale);//输入电话
	GetWindowTextA(arrHwndEdit[7], tmp, 50);
	sscanf(tmp, "%s", ps->date[pos].addr);//输入地址
	int inttmp;
	int day[3];
	int i = 0;
	for (i = 0; i < 3; ++i)
	{
		GetWindowTextA(arrHwndEdit[8 + i], tmp, 50);
		sscanf(tmp, "%d", &inttmp);
		day[i] = inttmp;
	}
	ps->date[pos].makeDay = day[2] + day[1] * 100 + day[0] * 10000;//办理日期
	for (i = 0; i < 3; ++i)
	{
		GetWindowTextA(arrHwndEdit[11 + i], tmp, 50);
		sscanf(tmp, "%d", &inttmp);
		day[i] = inttmp;
	}
	ps->date[pos].lastDay = day[2] + day[1] * 100 + day[0] * 10000;//有效日期
	//修改成功;
}
int NameCmp(const void* str1, const void* str2)
{
	return strcmp((char*)str1, (char*)str2);
}
void BubbleSort(struct Contact* ps, size_t sz,int (*pfuntion)(const void*,const void*))
{
	int i = 0;
	struct PeoInfo* tmp = (PeoInfo*)malloc(1 * sizeof(struct PeoInfo));
	while (sz)
	{
		for (i = 0; i < sz-1; i++)
		{
			if (pfuntion(&((ps->date+i)->name), &((ps->date+i + 1)->name))>0)
			{
				if (NULL == tmp)
				{
					FILE* bufferPf = fopen("缓冲.txt", "a");
					fprintf(bufferPf,"%s\n", strerror(errno));
					fclose(bufferPf);
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
		FILE* bufferPf = fopen("缓冲.txt", "a");
		fprintf(bufferPf,"通讯录为空，快去添加吧\n");
		fclose(bufferPf);
	}
	else
	{
		BubbleSort(ps, ps->size,NameCmp);
		ShowContact(ps);
	}
}

static void ShowAvlSort(Contact* ps)
{
	assert(ps);
	BTNode* avlSort = NULL;
	int i = 0;
	for (i = 0; i < ps->size; ++i)
	{
		InsertNode(&avlSort, ps->date + i);
	}
	PrintTree(avlSort);

	BinaryTreeDestory(avlSort);
}
void SortByAvltree(Contact* ps)
{
	assert(ps);
	if (0 == ps->size)
	{
		FILE* bufferPf = fopen("缓冲.txt", "a");
		fprintf(bufferPf, "通讯录为空，快去添加吧\n");
		fclose(bufferPf);
	}
	else
	{
		FILE* bufferPf = fopen("缓冲.txt", "a");
		fprintf(bufferPf, "%s\t%-12s\t%-10s\t%-4s\t%-5s\t%-20s\t%-20s\t%-12s\t%-12s\n", "序号", "会员号", "名字", "年龄", "性别", "电话", "地址", "办理日期", "有效日期");
		fclose(bufferPf);
		bufferPf = NULL;

		ShowAvlSort(ps);
	}
}
void SaveContact(Contact* ps)
{
	FILE* pfWrite = fopen("contact.dat", "wb");
	FILE* bufferPf = fopen("缓冲.txt", "a");

	if (NULL == pfWrite)
	{
		fprintf(bufferPf,"SaveContact:%s\n", strerror(errno));
		fprintf(bufferPf,"保存失败\n");
		return;
	}
	//写通讯录中数据到文件中
	int i = 0;
	for (i = 0; i < ps->size; i++)
	{
		fwrite(&(ps->date[i]), sizeof(PeoInfo), 1, pfWrite);
	}
	fprintf(bufferPf, "保存成功\n");
	fclose(bufferPf);
	bufferPf = NULL;
	fclose(pfWrite);
	pfWrite = NULL;
}