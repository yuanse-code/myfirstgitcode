#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <assert.h>

////free��
void FreeSloveEquationList(EquationList* ps);

//���뷽��
void InputEquation(EquationList* ps,int IndexNumber);
	//�ⷽ��(�����⣬���ֽ�)
	//1.�ⷽ��ʱдtxt
void WriteEquation(EquationList* ps);
	//2.��Ԫ:
void Elimination������(EquationList* ps, char U);
void Elimination���ֽ�(EquationList* ps, char U);
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
