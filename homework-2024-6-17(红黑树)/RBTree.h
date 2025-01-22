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

void PreTrav(RBTNode* root);//前序遍历//根左右
void PrintTree(RBTNode* root);//print（中序遍历）//左根右
void PostTrav(RBTNode* root);//后序遍历//左右根
void LeftRotate(RBTNode* root);//左旋
void RightRotate(RBTNode* root);//右旋
int BlackMaxDepth(RBTNode* root);//最大深度
int BlackMinDepth(RBTNode* root);//最小深度

void InsertNode(RBTNode** proot, RBTDataType x);
void DeleteNode(RBTNode** proot);//可以优化
void RBTHandLeReorient(RBTNode** proot);//修正
RBTNode* SearchNode(RBTNode* root, RBTDataType x);
RBTNode* MiniNum(RBTNode* root);
RBTNode* MaxNum(RBTNode* root);

size_t RedBlackTreeSize(RBTNode* root);
bool RBTEmpty(RBTNode* root);