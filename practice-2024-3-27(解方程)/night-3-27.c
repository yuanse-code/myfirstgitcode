
#include "SeqList.h"
#include "calculator.h"

Unknown** EndEquationList(int IndexNumber)
{
	assert(IndexNumber);
	EquationList SloveEquationList;
	//初始化
	EquationListInit(&SloveEquationList);
	//输入方程
	InputEquation(&SloveEquationList, IndexNumber);
	//解方程(暴力解，部分解)
	//1.解方程时写txt
	//建新TXT
	//重置
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
	//2.消元:
	
	//(暴力法)a.每个方程俩俩结合
	//(部分解)a.三个方程组合，做好备份
	//b.整理
	//c.判断指数
	//d.如果大于方程指数，新方程
	//e.如果小于方程指数，
	//如果为2，公式
	//如果>2，递归或公式
	//f.判断成功
	//g.打印结果

	//保存结果
	//Unknown** fruit=(Unknown**)malloc(sizeof(Unknown*)* );
	//free掉
	FreeSloveEquationList(&SloveEquationList);
	return NULL;
}
//输入方程

	//解方程(暴力解，部分解)
	//1.解方程时写txt
	//2.消元:
	//(暴力法)a.每个方程俩俩结合
	//(部分解)a.三个方程组合，做好备份
	// 整理
	//b.判断指数
	//c.如果大于方程指数，新方程
	//d.如果小于方程指数，
	//如果为2，公式
	//如果>2，递归或公式
	//e.判断成功
	//f.打印结果

	//free掉
int main()
{
	//例子
	//qwe=a
	//qwz+qye+xwe=b
	//qyz+xwz+xye=c
	//xyz=d
	EndEquationList(3);
	return 0;
}