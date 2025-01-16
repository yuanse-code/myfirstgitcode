#include "Tree.h"

static BTNode* BuyNewnode(BTDataType x)
{
	BTNode* newNode = (BTNode*)malloc(sizeof(BTNode) * 1);
	newNode->_data = x;
	newNode->pParent = NULL;
	newNode->pLeft = NULL;
	newNode->pRight = NULL;
	return newNode;
}
void BinaryTreeDestory(BTNode* root)
{
	if (root == NULL)
		return 0;
	BinaryTreeDestory(root->pRight);
	BinaryTreeDestory(root->pLeft);
	free(root);
	root = NULL;
}
void PreTrav(BTNode* root)//ǰ�����//������
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
void PrintTree(BTNode* root)//print�����������
{
	assert(root);
	if (root->pLeft == root->pRight && root->pLeft == NULL)
	{
		printf("%2d ", root->_data);
	}
	else if (root->pLeft)
	{//��ڵ����
		PrintTree(root->pLeft);
		printf("%2d ", root->_data);
		if (root->pRight)
			PrintTree(root->pRight);
	}
	else//��ڵ㲻����
	{
		if (root->pRight)
		{
			printf("%2d ", root->_data);
			PrintTree(root->pRight);
		}
	}
}
void PostTrav(BTNode* root)//�������//���Ҹ�
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

void LeftRotate(BTNode* root)//����
{
	assert(root);
	assert(root->pRight);
	BTNode* tmpNode = root->pRight->pLeft;
	BTNode* parentRoot = root->pParent;
	BTNode* rootRight = root->pRight;
	int a = MaxDepth(rootRight->pLeft);
	int b = MaxDepth(rootRight->pRight);
	//��������
	if (MaxDepth(rootRight->pRight) - MaxDepth(rootRight->pLeft) >= 0)
	{//=0Ϊ�����ҷ�ֹ����
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
	//��������//�ݹ�
	else
	{
		RightRotate(rootRight);
		LeftRotate(root);
	}
}
void RightRotate(BTNode* root)//����

{
	assert(root);
	assert(root->pLeft);
	BTNode* tmpNode = root->pLeft->pRight;
	BTNode* parentRoot = root->pParent;
	BTNode* rootLeft = root->pLeft;
	//��������
	int a = MaxDepth(rootLeft->pLeft);
	int b = MaxDepth(rootLeft->pRight);
	if (MaxDepth(rootLeft->pLeft) - MaxDepth(rootLeft->pRight) >= 0)
	{//=0Ϊ�����ҷ�ֹ����
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
	else//��������//�ݹ�
	{
		LeftRotate(rootLeft);
		RightRotate(root);
	}
}
int MaxDepth(const BTNode* root)
{
	if (root == NULL)
		return 0;
	if (root->pLeft == root->pRight && root->pRight == NULL)
		return 1;
	return MaxDepth(root->pRight) > MaxDepth(root->pLeft)
		? MaxDepth(root->pRight)+1 
		: MaxDepth(root->pLeft)+1;
}
int MinDepth(const BTNode* root)
{
	if (root == NULL)
		return 0;
	if (root->pLeft == root->pRight && root->pRight == NULL)
		return 1;
	return MinDepth(root->pRight) < MinDepth(root->pLeft)
		? MinDepth(root->pRight) + 1
		: MinDepth(root->pLeft) + 1;
}

void Insert(BTNode** proot, BTDataType x)
{
	if ((*proot) == NULL)
	{
		*proot = BuyNewnode(x);
		(*proot)->pParent = NULL;
		(*proot)->pLeft = NULL;
		(*proot)->pRight = NULL;
	}
	else if ((*proot)->_data >= x)//�ȸ��ڵ�С���������
	{
		if ((*proot)->pLeft)
			Insert(&((*proot)->pLeft), x);
		else
		{
			(*proot)->pLeft = BuyNewnode(x);
			(*proot)->pLeft->pParent = (*proot);
			BTNode* tmproot = *proot;
			BTNode*** ppptmp = &proot;
			FindHeadRoot(ppptmp, tmproot);
			BinaryTreeFix(proot);
			return;
		}
	}
	//�ȸ��ڵ�󣬲����ұ�
	else
	{
		if ((*proot)->pRight)
			Insert(&((*proot)->pRight), x);
		else
		{
			(*proot)->pRight = BuyNewnode(x);
			(*proot)->pRight->pParent = (*proot);
			BTNode* tmproot = *proot;
			BTNode*** ppptmp = &proot;
			FindHeadRoot(ppptmp, tmproot);
			BinaryTreeFix(proot);
			return;
		}
	}
}
void InsertNode(BTNode** proot, BTDataType x)
{
	assert(proot);
	BTNode** headproot = proot;
	Insert(proot, x);
	BTNode* tmproot = *proot;
	BTNode*** ppptmp = &proot;
	FindHeadRoot(ppptmp, tmproot);
	*headproot = *proot;
}
void DeleteNode(BTNode** proot)
{
	assert(proot);
	assert(*proot);
	BTNode** headproot = proot;

	BTNode* rootRight = (*proot)->pRight;
	BTNode* addTail = NULL;
	BTNode* rootLeft = (*proot)->pLeft;
	BTNode* rootParent = (*proot)->pParent;
	if (rootParent)
	{//�������ͷ�ڵ�
		if (rootParent->pLeft == (*proot))//����Ǹ��ڵ����
			if (rootLeft)//�Ӹ��ڵ��������У�
				rootParent->pLeft = rootLeft;
			else//û�и���ͽӸ���
				rootParent->pLeft = rootRight;
		else//����Ǹ��ڵ����
			if (rootLeft)//�Ӹ��ڵ��������У�
				rootParent->pRight = rootLeft;
			else//û�и���ͽӸ���
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
	//����
	BTNode* tmproot = *proot;
	BTNode*** ppptmp = &proot;
	FindHeadRoot(ppptmp, tmproot);
	BinaryTreeFix(proot);

	tmproot = *proot;
	ppptmp = &proot;
	FindHeadRoot(ppptmp, tmproot);
	*headproot = *proot;//�ҵ�ͷ�ڵ�
}
static FindHeadRoot(const BTNode*** pproot,const BTNode* root)
{
	assert(pproot);
	assert(*pproot);
	assert(root);
	BTNode* headroot = root;
	while (headroot->pParent)
	{
		headroot = headroot->pParent;
	}
	*pproot = &headroot;
}
static BTNode* FindEorrorNode(const BTNode* root)
{
	if (MaxDepth(root->pLeft) - MinDepth(root->pLeft) >= 2)
	{
		return FindEorrorNode(root->pLeft);
	}
	else if (MaxDepth(root->pRight) - MinDepth(root->pRight) >= 2)
	{
		return FindEorrorNode(root->pRight);
	}
	else
		return root;
}

void BinaryTreeFix(BTNode** proot)//����
{
	assert(proot);
	assert(*proot);
	BTNode* fixnode = NULL;
	BTNode** headproot = proot;
	while (MaxDepth(*proot) - MinDepth(*proot) >= 2)
	{//��Ҫ����
		fixnode = FindEorrorNode(*proot);
		//������
		int a = MaxDepth(fixnode->pLeft);
		int b = MaxDepth(fixnode->pRight);
		int c = MaxDepth(fixnode);
		int d = MinDepth(fixnode);
		if (MaxDepth(fixnode->pLeft) - MaxDepth(fixnode->pRight) >= 2)
		{
			RightRotate(fixnode);
		}
		else if (MaxDepth(fixnode->pLeft) - MaxDepth(fixnode->pRight) >= 1)
		{//���߶���
			break;
		}
		//������
		else if (MaxDepth(fixnode->pRight) - MaxDepth(fixnode->pLeft) >= 2)
		{
			LeftRotate(fixnode);
		}
		else if (MaxDepth(fixnode->pRight) - MaxDepth(fixnode->pLeft) >= 1)
		{//���߶���
			break;
		}
		BTNode* tmproot = *proot;
		BTNode*** ppptmp = &proot;
		FindHeadRoot(ppptmp,tmproot);
	}
	BTNode* tmproot = *proot;
	BTNode*** ppptmp = &proot;
	FindHeadRoot(ppptmp, tmproot);
	*headproot = *proot;
}
BTNode* SearchNode(BTNode* root, BTDataType x)
{
	assert(root);
	if (x == root->_data)
		return root;
	else if (x > root->_data)//��root��
	{
		SearchNode(root->pRight,x);
	}
	else//��rootС
	{
		SearchNode(root->pLeft, x);
	}
}
BTNode* MiniNum(BTNode* root)
{
	assert(root);
	while (root->pLeft != NULL)
	{
		root = root->pLeft;
	}
	return root;
}
BTNode* MaxNum(BTNode* root)
{
	assert(root);
	while (root->pRight != NULL)
	{
		root = root->pRight;
	}
	return root;
}

size_t BinaryTreeSize(BTNode* root)
{
	if (root == NULL)
		return 0;
	if (!(root->pLeft) && !(root->pRight))
	{
		return 1;
	}
	return BinaryTreeSize(root->pLeft) + BinaryTreeSize(root->pRight) + 1;
}
bool BTEmpty(BTNode* root)
{
	assert(root);
	if (root->pParent == NULL && root->pLeft == NULL && !root->pRight)
		return true;
	return false;
}