#include "RBTree.h"

static RBTNode* BuyNewnode(RBTDataType x)
{
	RBTNode* newNode = (RBTNode*)malloc(sizeof(RBTNode) * 1);
	newNode->_data = x;
	newNode->pParent = NULL;
	newNode->pLeft = NULL;
	newNode->pRight = NULL;
	return newNode;
}
void RedBlackTreeDestory(RBTNode* root)
{
	if (root == NULL)
		return 0;
	RedBlackTreeDestory(root->pRight);
	RedBlackTreeDestory(root->pLeft);
	free(root);
	root = NULL;
}
void PreTrav(RBTNode* root)//前序遍历//根左右
{
	assert(root);
	printf("%2d ",root->_data);
	if (root->pLeft)
	{
		PreTrav(root->pLeft);
		if (root->pRight)
			PreTrav(root->pRight);
	}
	else if (root->pRight)
	{
		PreTrav(root->pRight);
	}
}
void PrintTree(RBTNode* root)//print（中序遍历）
{
	assert(root);
	if (root->pLeft == root->pRight && root->pLeft == NULL)
	{
		printf("%2d ", root->_data);
	}
	else if (root->pLeft)
	{//左节点存在
		PrintTree(root->pLeft);
		printf("%2d ", root->_data);
		if (root->pRight)
			PrintTree(root->pRight);
	}
	else//左节点不存在
	{
		if (root->pRight)
		{
			printf("%2d ", root->_data);
			PrintTree(root->pRight);
		}
	}
}
void PostTrav(RBTNode* root)//后序遍历//左右根
{
	assert(root);
	if (root->pLeft)
	{
		PostTrav(root->pLeft);
		if (root->pRight)
			PostTrav(root->pRight);
		printf("%2d ", root->_data);
	}
	else if (root->pRight)
	{
		PostTrav(root->pRight);
		printf("%2d ", root->_data);
	}
	else
		printf("%2d ", root->_data);
}

void LeftRotate(RBTNode* root)//左旋
{
	assert(root);
	assert(root->pRight);
	RBTNode* tmpNode = root->pRight->pLeft;
	RBTNode* parentRoot = root->pParent;
	RBTNode* rootRight = root->pRight;
	int a = BlackMaxDepth(rootRight->pLeft);
	int b = BlackMaxDepth(rootRight->pRight);
	//右右类型
	if (BlackMaxDepth(rootRight->pRight) - BlackMaxDepth(rootRight->pLeft) >= 0)
	{//=0为了左右防止交错
		if (parentRoot)
			if (parentRoot->pRight == root)
			{
				parentRoot->pRight = root->pRight;
			}
			else
				parentRoot->pLeft = root->pRight;
		rootRight->pParent = parentRoot;
		root->pParent = rootRight;
		rootRight->pLeft = root;
		root->pRight = tmpNode;
		if (tmpNode)
			tmpNode->pParent = root;
	}
	//右左类型//递归
	else
	{
		RightRotate(rootRight);
		LeftRotate(root);
	}
}
void RightRotate(RBTNode* root)//右旋

{
	assert(root);
	assert(root->pLeft);
	RBTNode* tmpNode = root->pLeft->pRight;
	RBTNode* parentRoot = root->pParent;
	RBTNode* rootLeft = root->pLeft;
	//左左类型
	int a = BlackMaxDepth(rootLeft->pLeft);
	int b = BlackMaxDepth(rootLeft->pRight);
	if (BlackMaxDepth(rootLeft->pLeft) - BlackMaxDepth(rootLeft->pRight) >= 0)
	{//=0为了左右防止交错
		if (parentRoot)
			if (parentRoot->pLeft == root)
			{
				parentRoot->pLeft = root->pLeft;
			}
			else
				parentRoot->pRight = root->pLeft;
		rootLeft->pParent = parentRoot;
		root->pParent = rootLeft;
		rootLeft->pRight = root;
		root->pLeft = tmpNode;
		if (tmpNode)
			tmpNode->pParent = root;
	}
	else//左右类型//递归
	{
		LeftRotate(rootLeft);
		RightRotate(root);
	}
}
int BlackMaxDepth(const RBTNode* root)
{
	if (root == NULL)
		return 1;
	if (root->color == BLACK)
		return BlackMaxDepth(root->pRight) > BlackMaxDepth(root->pLeft)
		? BlackMaxDepth(root->pRight) + 1
		: BlackMaxDepth(root->pLeft) + 1;
	else
		return BlackMaxDepth(root->pRight) > BlackMaxDepth(root->pLeft)
		? BlackMaxDepth(root->pRight)
		: BlackMaxDepth(root->pLeft);
}
int BlackMinDepth(const RBTNode* root)
{
	if (root == NULL)
		return 1;
	if (root->color == BLACK)
		return BlackMinDepth(root->pRight) < BlackMinDepth(root->pLeft)
		? BlackMinDepth(root->pRight) + 1
		: BlackMinDepth(root->pLeft) + 1;
	else
		return BlackMinDepth(root->pRight) < BlackMinDepth(root->pLeft)
		? BlackMinDepth(root->pRight)
		: BlackMinDepth(root->pLeft);
}

void Insert(RBTNode** proot, RBTDataType x)
{
	if ((*proot) == NULL)
	{
		*proot = BuyNewnode(x);
		(*proot)->pParent = NULL;
		(*proot)->pLeft = NULL;
		(*proot)->pRight = NULL;
		(*proot)->color = BLACK;
	}
	else if ((*proot)->_data >= x)//比父节点小，插入左边
	{
		if ((*proot)->pLeft)
			Insert(&((*proot)->pLeft), x);
		else
		{
			(*proot)->pLeft = BuyNewnode(x);
			(*proot)->pLeft->pParent = (*proot);
			(*proot)->pLeft->color = RED;
			//修正
			RBTNode* tmproot = *proot;//传头节点
			RBTNode*** ppptmp = &proot;
			FindHeadRoot(ppptmp, tmproot);
			//RBTHandLeReorient(proot);
			return;
		}
	}
	//比父节点大，插入右边
	else
	{
		if ((*proot)->pRight)
			Insert(&((*proot)->pRight), x);
		else
		{
			(*proot)->pRight = BuyNewnode(x);
			(*proot)->pRight->pParent = (*proot);
			(*proot)->pRight->color = RED;
			//修正
			RBTNode* tmproot = *proot;//传头节点
			RBTNode*** ppptmp = &proot;
			FindHeadRoot(ppptmp, tmproot);
			//RBTHandLeReorient(proot);
			return;
		}
	}
}
void InsertNode(RBTNode** proot, RBTDataType x)
{
	assert(proot);
	RBTNode** headproot = proot;
	Insert(proot, x);
	RBTNode* tmproot = *proot;
	RBTNode*** ppptmp = &proot;
	FindHeadRoot(ppptmp, tmproot);
	*headproot = *proot;
}
void DeleteNode(RBTNode** proot)
{
	assert(proot);
	assert(*proot);
	RBTNode** headproot = proot;

	RBTNode* rootRight = (*proot)->pRight;
	RBTNode* addTail = NULL;
	RBTNode* rootLeft = (*proot)->pLeft;
	RBTNode* rootParent = (*proot)->pParent;
	if (rootParent)
	{//如果不是头节点
		if (rootParent->pLeft == (*proot))//如果是父节点的左
			if (rootLeft)//接根节点的左（如果有）
				rootParent->pLeft = rootLeft;
			else//没有根左就接根右
				rootParent->pLeft = rootRight;
		else//如果是父节点的右
			if (rootLeft)//接根节点的左（如果有）
				rootParent->pRight = rootLeft;
			else//没有根左就接根右
				rootParent->pRight = rootRight;
	}
	if (rootLeft)
	{
		rootLeft->pParent = rootParent;
		addTail = MaxNum(rootLeft);
		addTail->pRight = rootRight;
		if (rootRight)
			rootRight->pParent = addTail;
		free(*proot);
		*proot = rootLeft;
	}
	else
	{
		if (rootRight)
			rootRight->pParent = rootParent;
		free(*proot);
		*proot = rootRight;
	}
	//整理
	RBTNode* tmproot = *proot;
	RBTNode*** ppptmp = &proot;
	FindHeadRoot(ppptmp, tmproot);
	RBTHandLeReorient(proot);

	tmproot = *proot;
	ppptmp = &proot;
	FindHeadRoot(ppptmp, tmproot);
	*headproot = *proot;//找到头节点
}
static FindHeadRoot(const RBTNode*** pproot,const RBTNode* root)
{
	assert(pproot);
	assert(*pproot);
	assert(root);
	RBTNode* headroot = root;
	while (headroot->pParent)
	{
		headroot = headroot->pParent;
	}
	*pproot = &headroot;
}
static RBTNode* FindEorrorNode(const RBTNode* root)
{
	if (BlackMaxDepth(root->pLeft) - BlackMinDepth(root->pLeft) >= 2)
	{
		return FindEorrorNode(root->pLeft);
	}
	else if (BlackMaxDepth(root->pRight) - BlackMinDepth(root->pRight) >= 2)
	{
		return FindEorrorNode(root->pRight);
	}
	else
		return root;
}
static RBTNode* FindDyeNode(const RBTNode* root)
{
	RBTNode* dyenode;
	if (root == NULL)
		return NULL;
	if (root->color == RED)
		if (root->pLeft || root->pRight)
		{
			if (root->pLeft)
				if (root->pLeft->color == RED)
					return root->pLeft;
			if(root->pRight)
				if (root->pRight->color == RED)
					return root->pRight;
		}		
	if (root->pLeft)
	{
		if (dyenode = FindDyeNode(root->pLeft))
		{
			return dyenode;
		}
		if (root->pRight)
			if (dyenode = FindDyeNode(root->pRight))
			{
				return dyenode;
			}
	}
	else if (root->pRight)
	{
		if (dyenode = FindDyeNode(root->pRight))
		{
			return dyenode;
		}
	}
	else 
		return NULL;
	return NULL;
}
//如果染色成功返回真，否则返回假
static bool Dye(const RBTNode* root)
{
	assert(root);
	RBTNode* dyenode = FindDyeNode(root);
	if (dyenode == NULL)
	{
		return false;
	}
	RBTNode* tmpnode = dyenode->pParent;
	while (tmpnode && tmpnode->pParent)
	{
		tmpnode->pParent->color = RED;
		if (tmpnode->pParent->pLeft)
			tmpnode->pParent->pLeft->color = BLACK;
		if (tmpnode->pParent->pRight)
			tmpnode->pParent->pRight->color = BLACK;
		tmpnode = tmpnode->pParent->pParent;
	}
	return true;
}


void RBTHandLeReorient(RBTNode** proot)//修正
{
	assert(proot);
	assert(*proot);
	RBTNode* fixnode = NULL;
	RBTNode** headproot = proot;
	//1.检查根节点是否为黑色
	if ((*proot)->color == RED)
	{
		(*proot)->color == BLACK;
	}
	//2.染色
	while (Dye(*proot))
	{
		if ((*proot)->color == RED)
		{
			(*proot)->color == BLACK;
		}
	}
	int e = BlackMaxDepth(*proot);
	int f = BlackMinDepth(*proot);
	while (BlackMaxDepth(*proot) - BlackMinDepth(*proot) >= 2)
	{//需要修正
		fixnode = FindEorrorNode(*proot);
	    //2.染色
		if (Dye(fixnode))
			continue;
	    //3.调整
		//左类型
		int a = BlackMaxDepth(fixnode->pLeft);
		int b = BlackMaxDepth(fixnode->pRight);
		int c = BlackMaxDepth(fixnode);
		int d = BlackMinDepth(fixnode);
		if (BlackMaxDepth(fixnode->pLeft) - BlackMaxDepth(fixnode->pRight) >= 2)
		{
			RightRotate(fixnode);
		}
		else if (BlackMaxDepth(fixnode->pLeft) - BlackMaxDepth(fixnode->pRight) >= 1)
		{//两边都有
			break;
		}
		//右类型
		else if (BlackMaxDepth(fixnode->pRight) - BlackMaxDepth(fixnode->pLeft) >= 2)
		{
			LeftRotate(fixnode);
		}
		else if (BlackMaxDepth(fixnode->pRight) - BlackMaxDepth(fixnode->pLeft) >= 1)
		{//两边都有
			break;
		}
		RBTNode* tmproot = *proot;
		RBTNode*** ppptmp = &proot;
		FindHeadRoot(ppptmp,tmproot);
		//1.检查根节点是否为黑色
		if ((*proot)->color == RED)
		{
			(*proot)->color == BLACK;
		}
	}
	RBTNode* tmproot = *proot;
	RBTNode*** ppptmp = &proot;
	FindHeadRoot(ppptmp, tmproot);
	*headproot = *proot;
}
RBTNode* SearchNode(RBTNode* root, RBTDataType x)
{
	assert(root);
	if (x == root->_data)
		return root;
	else if (x > root->_data)//比root大
	{
		SearchNode(root->pRight,x);
	}
	else//比root小
	{
		SearchNode(root->pLeft, x);
	}
}
RBTNode* MiniNum(RBTNode* root)
{
	assert(root);
	while (root->pLeft != NULL)
	{
		root = root->pLeft;
	}
	return root;
}
RBTNode* MaxNum(RBTNode* root)
{
	assert(root);
	while (root->pRight != NULL)
	{
		root = root->pRight;
	}
	return root;
}

size_t RedBlackTreeSize(RBTNode* root)
{
	if (root == NULL)
		return 0;
	if (!(root->pLeft) && !(root->pRight))
	{
		return 1;
	}
	return RedBlackTreeSize(root->pLeft) + RedBlackTreeSize(root->pRight) + 1;
}
bool RBTEmpty(RBTNode* root)
{
	assert(root);
	if (root->pParent == NULL && root->pLeft == NULL && !root->pRight)
		return true;
	return false;
}