#include "RBTree.h"

void Test1Tree()
{
	RBTNode* rbtree = NULL;
	RBTNode* findNode = NULL;

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
	RBTHandLeReorient(&rbtree);
	/*findNode=SearchNode(rbtree, 4);
	DeleteNode(&findNode);
	printf("中序遍历：");
	PrintTree(rbtree);
	printf("\n");
	printf("前序遍历：");
	PreTrav(rbtree);
	printf("\n");
	printf("后序遍历：");
	PostTrav(rbtree);
	printf("\n");*/
	//printf("%lld\n", RedBlackTreeSize(rbtree));
	printf("%lld\n", BlackMaxDepth(rbtree));
	printf("%lld\n", BlackMinDepth(rbtree));

	RedBlackTreeDestory(rbtree);
	rbtree = NULL;
}

int main()
{
	Test1Tree();
	return 0;
}