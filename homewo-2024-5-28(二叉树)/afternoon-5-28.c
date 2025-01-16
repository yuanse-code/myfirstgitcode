#include "Tree.h"

void Test1Tree()
{
	BTNode* rbtree = NULL;
	BTNode* findNode = NULL;

	InsertNode(&rbtree, 1);
	InsertNode(&rbtree, 2);
	InsertNode(&rbtree, 3);
	InsertNode(&rbtree, 4);
	InsertNode(&rbtree, 5);
	InsertNode(&rbtree, 6);
	InsertNode(&rbtree, 7);
	InsertNode(&rbtree, 8);
	InsertNode(&rbtree, 9);
	InsertNode(&rbtree, 10);
	InsertNode(&rbtree, 11);
	InsertNode(&rbtree, 12);
	InsertNode(&rbtree, 13);
	InsertNode(&rbtree, 14);
	findNode=SearchNode(rbtree, 4);
	DeleteNode(&findNode);
	printf("中序遍历：");
	PrintTree(rbtree);
	printf("\n");
	printf("前序遍历：");
	PreTrav(rbtree);
	printf("\n");
	printf("后序遍历：");
	PostTrav(rbtree);
	printf("\n");
	printf("%lld\n", BinaryTreeSize(rbtree));
	printf("%lld\n", MaxDepth(rbtree));
	printf("%lld\n", MinDepth(rbtree));

	BinaryTreeDestory(rbtree);
	rbtree = NULL;
}

int main()
{
	Test1Tree();
	return 0;
}