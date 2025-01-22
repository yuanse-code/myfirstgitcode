#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

typedef int RBTDataType;
typedef enum ColorType {
	BLACK,
	RED
}Color;
typedef struct RedBlackTreeNode
{
	struct RedBlackTreeNode* pParent;
	struct RedBlackTreeNode* pLeft;
	struct RedBlackTreeNode* pRight;
	RBTDataType _data;
	Color color;
}RBTNode;


void RedBlackTreeDestory(RBTNode* root);

void PreTrav(RBTNode* root);//ǰ�����//������
void PrintTree(RBTNode* root);//print�����������//�����
void PostTrav(RBTNode* root);//�������//���Ҹ�
void LeftRotate(RBTNode* root);//����
void RightRotate(RBTNode* root);//����
int BlackMaxDepth(RBTNode* root);//������
int BlackMinDepth(RBTNode* root);//��С���

void InsertNode(RBTNode** proot, RBTDataType x);
void DeleteNode(RBTNode** proot);//�����Ż�
void RBTHandLeReorient(RBTNode** proot);//����
RBTNode* SearchNode(RBTNode* root, RBTDataType x);
RBTNode* MiniNum(RBTNode* root);
RBTNode* MaxNum(RBTNode* root);

size_t RedBlackTreeSize(RBTNode* root);
bool RBTEmpty(RBTNode* root);