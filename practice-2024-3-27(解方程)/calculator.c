
#include "SeqList.h"
#include "calculator.h"

static void AddNewEquationBack(EquationList* ps)
{
	SL* pnewequation = (SL*)malloc(sizeof(SL) * 1);
	EquationListPushBack(ps, pnewequation);
	SeqListInit(ps->equationarr[ps->size-1]);
}
static void AddPnewU(EquationList* ps, int EQpos, char U,int index)
{
	Unknown* pnewU = (Unknown*)malloc(sizeof(Unknown) * 1);
	pnewU->u = U;
	pnewU->exponent = index;
	SeqListPushBack(ps->equationarr[EQpos], pnewU);
}
static int NCR(size_t n, size_t m)
{
	assert(n != 0);
	int molecular = 1;
	int numberator = 1;
	//��ʽn*(n-1)*...(n-m+1)/m!
	int i = 0;
	if (m == 0)
		return 1;
	for (i = n; i > n - m; --i)
	{
		molecular *= i;
	}
	for (i = 1; i <= m; ++i)
	{
		numberator *= i;
	}
	return molecular / numberator;
}
static void draw��(char* Uadd,int IndexNumber)
{
	int tail = IndexNumber - 1;
	int i = 0;
	if (Uadd[tail] == 'A')
	{
		i = tail;
		//�ҵ���ͷ
		while (i>=0&&Uadd[i] != 'i')
		{
			i--;
		}
		if (-1 == i)
		{
			return;
		}
		tail = i + 1;
		//�ҵ�ǰβ
		while (i >= 0 && Uadd[i] != 'A')
		{
			--i;
		}
		if (-1 == i)
		{
			return;
		}
		//����һλ
		Uadd[i] = 'i';
		Uadd[i + 1] = 'A';
		//β��ת
		if (Uadd[tail - 1] == 'i')
		{
			Uadd[tail] = 'i';
			Uadd[i + 2] = 'A';
		}
		return;
	}
	else
	{
		//�ҵ���β
		i = tail;
		while (i>=0&&Uadd[i] != 'A')
		{
			--i;
		}
		if (i == -1)
		{
			return;
		}
		//����һλ
		Uadd[i] = 'i';
		Uadd[i + 1] = 'A';
	}
}
void InputEquation(EquationList* ps, int IndexNumber)
{
	int i = 0;
	//���ٿռ�
	for (i = 0; i <= IndexNumber; ++i)
	{
		AddNewEquationBack(ps);
	}
	//����ѭ��
	for (i = 0; i <= IndexNumber; ++i)
	{
		//��ʱ
		//a1,a2,a3....��ABCD...
		//b1,b2,b3....��ijklmn...
		//a,b,c....��abc...
		int j = 0;
		//��
		char* Uadd = (char*)malloc(sizeof(char) * IndexNumber);
		if (!Uadd)
		{
			printf("%s\n", strerror(errno));
			exit(-1);
		}
		int k = 0;
		//��ʼ����
		for (k = 0; k < IndexNumber; ++k)
		{
			if (k < IndexNumber - i)
				Uadd[k] = 'A';
			else
				Uadd[k] = 'i';
		}
		//δ֪�����ѭ��
		for (j = 0; j < NCR(IndexNumber, i); ++j)
		{
			//δ֪��ѭ��
			for (k = 0; k < IndexNumber; ++k)
			{
				AddPnewU(ps, i, Uadd[k] + k, 1);
			}
			AddPnewU(ps, i, '+', 0);
			draw��(Uadd, IndexNumber);
		}
		SeqListPopBack(ps->equationarr[i]);
		AddPnewU(ps, i, '=', 0);
		AddPnewU(ps, i, 'a' + i, 1);
		free(Uadd);
		Uadd = NULL;
	}
}
void WriteEquation(EquationList* ps)
{
	FILE* pftable=fopen("SloveEquation.txt", "a");
	if (pftable == NULL)
	{
		printf("%s\n", strerror(errno));
		assert(pftable);
	}
	else
	{
		fseek(pftable, 0, SEEK_END);
		int i = 0, j = 0;
		//����ѭ��
		for (i = 0; i < ps->size; ++i)
		{
			//δ֪��ѭ��
			for (j = 0; j < ps->equationarr[i]->size; ++j)
			{
				fprintf(pftable, "%c", ps->equationarr[i]->array[j]->u);
				if (ps->equationarr[i]->array[j]->exponent > 1)
				{
					fprintf(pftable, "%c", '^');
					fprintf(pftable, "%d", ps->equationarr[i]->array[j]->exponent);
				}
			}
			fprintf(pftable, "\n");
		}
		fclose(pftable);
	}
}
void Elimination���ֽ�(EquationList* ps,char U)
{

}

void FreeSloveEquationList(EquationList* ps)
{
	int i = 0;
	for (i = 0; i < ps->size; ++i)
	{
		SeqListDestory(ps->equationarr[i]);
	}
	EquationListDestory(ps);
}