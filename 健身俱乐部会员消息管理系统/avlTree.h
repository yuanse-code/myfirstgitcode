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

void PreTrav(BTNode* root);//前序遍历//根左右
void PrintTree(BTNode* root);//print（中序遍历）//左根右
void PostTrav(BTNode* root);//后序遍历//左右根
void LeftRotate(BTNode* root);//左旋
void RightRotate(BTNode* root);//右旋
int MaxDepth(BTNode* root);//最大深度
int MinDepth(BTNode* root);//最小深度

void InsertNode(BTNode** proot, BTDataType x);
void DeleteNode(BTNode** proot);//可以优化
void BinaryTreeFix(BTNode** proot);//修正
BTNode* SearchNode(BTNode* root, BTDataType x);
BTNode* MiniNum(BTNode* root);
BTNode* MaxNum(BTNode* root);

size_t BinaryTreeSize(BTNode* root);
bool BTEmpty(BTNode* root);