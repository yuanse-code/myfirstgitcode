#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <assert.h>

////free掉
void FreeSloveEquationList(EquationList* ps);

//输入方程
void InputEquation(EquationList* ps,int IndexNumber);
	//解方程(暴力解，部分解)
	//1.解方程时写txt
void WriteEquation(EquationList* ps);
	//2.消元:
void Elimination暴力法(EquationList* ps, char U);
void Elimination部分解(EquationList* ps, char U);
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
