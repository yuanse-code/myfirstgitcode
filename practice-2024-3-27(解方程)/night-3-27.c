
#include "SeqList.h"
#include "calculator.h"

Unknown** EndEquationList(int IndexNumber)
{
	assert(IndexNumber);
	EquationList SloveEquationList;
	//��ʼ��
	EquationListInit(&SloveEquationList);
	//���뷽��
	InputEquation(&SloveEquationList, IndexNumber);
	//�ⷽ��(�����⣬���ֽ�)
	//1.�ⷽ��ʱдtxt
	//����TXT
	//����
	//FILE* pftable = fopen("SloveEquation.txt", "w");
	//if (pftable == NULL)
	//{
	//	printf("%s\n", strerror(errno));
	//	assert(pftable);
	//}
	//else
	//{
	//	fclose(pftable);
	//}
	WriteEquation(&SloveEquationList);
	//2.��Ԫ:
	
	//(������)a.ÿ�������������
	//(���ֽ�)a.����������ϣ����ñ���
	//b.����
	//c.�ж�ָ��
	//d.������ڷ���ָ�����·���
	//e.���С�ڷ���ָ����
	//���Ϊ2����ʽ
	//���>2���ݹ��ʽ
	//f.�жϳɹ�
	//g.��ӡ���

	//������
	//Unknown** fruit=(Unknown**)malloc(sizeof(Unknown*)* );
	//free��
	FreeSloveEquationList(&SloveEquationList);
	return NULL;
}
//���뷽��

	//�ⷽ��(�����⣬���ֽ�)
	//1.�ⷽ��ʱдtxt
	//2.��Ԫ:
	//(������)a.ÿ�������������
	//(���ֽ�)a.����������ϣ����ñ���
	// ����
	//b.�ж�ָ��
	//c.������ڷ���ָ�����·���
	//d.���С�ڷ���ָ����
	//���Ϊ2����ʽ
	//���>2���ݹ��ʽ
	//e.�жϳɹ�
	//f.��ӡ���

	//free��
int main()
{
	//����
	//qwe=a
	//qwz+qye+xwe=b
	//qyz+xwz+xye=c
	//xyz=d
	EndEquationList(3);
	return 0;
}