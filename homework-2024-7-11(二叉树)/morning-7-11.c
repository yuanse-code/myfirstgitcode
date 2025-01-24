#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "Queue.h"

typedef char BTDataType;
typedef struct BinaryTreeNode
{
	BTDataType _data;
	struct BinaryTree* _left;
	struct BinaryTree* _right;
}BTNode;

void PrevOrder(BTNode* root)
{
	if (!root)
	{
		printf("NULL ");
		return;
	}
	printf("%c ", root->_data);
	PrevOrder(root->_left);
	PrevOrder(root->_right);
}

void InOrder(BTNode* root)
{
	if (!root)
	{
		printf("NULL ");
		return;
	}
	InOrder(root->_left);
	printf("%c ", root->_data);
	InOrder(root->_right);
}

void PostOrder(BTNode* root)
{
	if (!root)
	{
		printf("NULL ");
		return;
	}
	PostOrder(root->_left);
	PostOrder(root->_right);
	printf("%c ", root->_data);
}

//int size = 0;
//int TreeSize(BTNode* root)
//{
//	if (NULL == root)
//		return 0;
//	++size;
//	TreeSize(root->_left);
//	TreeSize(root->_right);
//	return size;
//}

//void TreeSize(BTNode* root, int* psize)
//{
//	assert(psize);
//	if (NULL == root)
//	{
//		return 0;
//	}
//	(*psize)++;
//	TreeSize(root->_left, psize);
//	TreeSize(root->_right, psize);
//}

int TreeSize(BTNode* root)
{
	if (!root)
		return 0;
	else
		return 1 + TreeSize(root->_left) + TreeSize(root->_right);
}

int TreeLeafSize(BTNode* root)
{
	if (!root)
		return 0;
	else if (root->_left == root->_right && root->_left == NULL)
		return 1;
	return TreeLeafSize(root->_left) + TreeLeafSize(root->_right);
}

BTNode* CreateNode(char x)
{
	BTNode* node = (BTNode*)malloc(sizeof(BTNode));
	assert(node);
	node->_data = x;
	node->_left = NULL;
	node->_right = NULL;
	return node;
}
int BinaryTreeLevelKSize(BTNode* root, int k)
{
	if (!root)
		return 0;
	if (1 == k)
		return 1;
	return BinaryTreeLevelKSize(root->_left, k - 1) +
		BinaryTreeLevelKSize(root->_right, k - 1);
}

BTNode* BinaryTreeFind(BTNode* root, BTDataType x)
{
	if (!root)
		return NULL;
	if (root->_data == x)
	{
		return root;
	}
	BTNode* node = BinaryTreeFind(root->_left, x);
	if (node)
		return node;
	node = BinaryTreeFind(root->_right, x);
	if (node)
		return node;
}

void DestoryTree(BTNode* root)
{
	if (!root)
		return;
	DestoryTree(root->_left);
	DestoryTree(root->_right);
	free(root);
}

void BinaryTreeLevelOrder(BTNode* root)
{
	Queue q;
	if (!root)
		return;
	QueueInit(&q);
	QueuePush(&q, root);
	while (!QueueEmpty(&q))
	{
		BTNode* front = QueueFront(&q);
		QueuePop(&q);
		printf("%c ", front->_data);
		if (front->_left)
		{
			QueuePush(&q,front->_left);
		}
		if (front->_right)
			QueuePush(&q, front->_right);
	}

	QueueDestory(&q);
}

//判断完全二叉树
//是返回1，不是返回0
int BinaryTreeComplete(BTNode* root)
{
	Queue q;
	if (!root)
		return 1;
	QueueInit(&q);
	QueuePush(&q, root);
	while (!QueueEmpty(&q))
	{
		BTNode* front = QueueFront(&q);
		QueuePop(&q);
		if (!front)
		{
			break;
		}
		QueuePush(&q, front->_left);
		QueuePush(&q, front->_right);
	}
	while (!QueueEmpty(&q))
	{
		BTNode* front = QueueFront(&q);
		QueuePop(&q);
		if (front)
		{
			return 0;
		}
	}

	QueueDestory(&q);
	return 1;
}

int main()
{
	BTNode* A = CreateNode('A');
	BTNode* B = CreateNode('B');
	BTNode* C = CreateNode('C');
	BTNode* D = CreateNode('D');
	BTNode* E = CreateNode('E');
	A->_left = B;
	A->_right = C;
	B->_left = D;
	B->_right = E;

	PrevOrder(A);
	printf("\n");

	InOrder(A);
	printf("\n");

	PostOrder(A);
	printf("\n");

	//printf("%d ", TreeSize(A));
	//int sizea = 0;
	//TreeSize(A, &sizea);
	//printf("TreeSize:%d ", sizea);
	printf("%d ", TreeLeafSize(A));
	printf("%d ", BinaryTreeLevelKSize(A, 3));
	printf("\n");
	BinaryTreeLevelOrder(A);
	printf("完全二叉树：%d ", BinaryTreeComplete(A));
	return 0;
}