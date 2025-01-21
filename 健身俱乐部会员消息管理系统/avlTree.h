#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include "contact.h"

typedef PeoInfo* BTDataType;

typedef struct BinaryTreeNode
{
	struct BinaryTreeNode* pParent;
	struct BinaryTreeNode* pLeft;
	struct BinaryTreeNode* pRight;
	BTDataType _data;
}BTNode;


void BinaryTreeDestory(BTNode* root);

void PreTrav(BTNode* root);//ǰ�����//������
void PrintTree(BTNode* root);//print�����������//�����
void PostTrav(BTNode* root);//�������//���Ҹ�
void LeftRotate(BTNode* root);//����
void RightRotate(BTNode* root);//����
int MaxDepth(BTNode* root);//������
int MinDepth(BTNode* root);//��С���

void InsertNode(BTNode** proot, BTDataType x);
void DeleteNode(BTNode** proot);//�����Ż�
void BinaryTreeFix(BTNode** proot);//����
BTNode* SearchNode(BTNode* root, BTDataType x);
BTNode* MiniNum(BTNode* root);
BTNode* MaxNum(BTNode* root);

size_t BinaryTreeSize(BTNode* root);
bool BTEmpty(BTNode* root);