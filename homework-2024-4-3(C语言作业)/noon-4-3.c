#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <math.h>
#include <GL/GL.h>
#include <gl/GLU.h>
#include <assert.h>
#include <stdbool.h>

//int main()
//{
//	int input = 0;
//	double x = 0;
//	double y = 0;
//	do
//	{
//		printf("姓名：XXX，学号20230413108\n");
//		printf("****************************\n");
//		printf("***    1.add    2.sub ******\n");
//		printf("***    3.mul    4.div ******\n");
//		printf("***         0.exit    ******\n");
//		printf("****************************\n");
//		printf("请选择:>");
//		scanf("%d", &input);
//		switch (input)
//		{
//		case 1:
//			printf("请输入两个操作数：>");
//			scanf("%lf%lf", &x, &y);
//			printf("%lf\n", x+y);
//			break;
//		case 2:
//			printf("请输入两个操作数：>");
//			scanf("%lf%lf", &x, &y);
//			printf("%lf\n", x-y);
//			break;
//		case 3:
//			printf("请输入两个操作数：>");
//			scanf("%lf%lf", &x, &y);
//			printf("%lf\n", x*y);
//			break;
//		case 4:
//			printf("请输入两个操作数：>");
//			scanf("%lf%lf", &x, &y);
//			if (0 == y)
//				printf("被除数不能为0\n");
//			printf("%lf\n", x / y);
//			break;
//		case 0:
//			printf("退出\n");
//			break;
//		default:
//			printf("输入错误\n");
//			break;
//		}
//	} while (input);
//	return 0;
//}

//int main()
//{
//	int k = 0;
//	printf("姓名：谷光榆，学号20230413108\n");
//	scanf("%d", &k);
//	int i = 0;
//	for (i = 0; i < k; ++i)
//	{
//		printf("%d^2+", i + 1);
//	}
//	printf("\b=%d", k * (k + 1) * (2*k + 1) / 6);
//	return 0;
//}
//int main()
//{
//	int i = 0;
//	printf("姓名：谷光榆，学号20230413108\n");
//	//生成1~200
//	for (i = 1; i <= 200; ++i)
//	{
//		if (6 == i % 10 && !(i % 3))
//		{
//			printf("%d ", i);
//		}
//	}
//}
//int main()
//{
//	int a[] = { 'C','H'};
//	printf("%d", *a);
//	return 0;
//}
//int main()
//{
//	const GLubyte* openglVersion=glGetString(GL_VERSION);
//	printf("%s", openglVersion);
//	system("pause");
//	return 0;
//}
//int n=0;
//void AverageAndNumber(int* arr, double* ave,int sz)
//{
//	double sum = 0;
//	int num = sz;
//	while (sz--)
//	{
//		sum += *arr;
//		if (*arr++ > 0)
//			n++;
//	}	
//	*ave = sum / num;
//}
//int main()
//{
//	int a[10] = { 0 };
//	double ave=0; int i = 0;
//	printf("请输入10个整数：>");
//	while (i<10)
//	{
//		scanf("%d", &a[i]);
//		i++;
//	}
//	AverageAndNumber(a,&ave,10);
//	printf("正整数个数为%d,平均数为%lf", n, ave);
//	return 0;
//}
//double cal(double x)
//{
//	if(x>0)
//		return x * x - 2 * x + 1;
//	else
//		return x * x * x + x + 3;
//} 
//int main()
//{
//	double x;
//	printf("请输入x:>");
//	scanf("%lf", &x);
//	printf("y=%lf",cal(x));
//	return 0;
//}
//int threeMin(int x, int y, int z)
//{
//	int min;
//	min = x > y ? y : x;
//	min = min > z ? z : min;
//	return min;
//}
//int main()
//{
//	int arr[5], min;int i = 0;
//	printf("请输入5个整数：>");
//	for (i = 0; i < 5; ++i)
//	{
//		scanf("%d", &arr[i]);
//	}
//	min = threeMin(arr[0], arr[1], arr[2]);
//	min = threeMin(arr[4], arr[3], min);
//	printf("min=%d", min);
//}
//#include<assert.h>
//void BubbleSort(void* parr, size_t elementsize, size_t sz, int (*pfcmp)(void*, void*))
//{
//	if (!parr && pfcmp)
//	{
//		printf("%d,空指针！\n",__LINE__);
//		assert(parr && pfcmp);
//		//printf("%s",strerrno(errno));//<string.h><errno.h>
//	}
//	int i = 0, j = 0;
//	for (i = 0; i < sz; ++i)
//	{
//		for (j = 0; j < sz - i - 1; ++j)
//		{
//			if (pfcmp((char*)parr + j * elementsize
//				, (char*)parr + (j + 1) * elementsize) > 0)
//			{
//				void* ptmp=(void*)malloc(elementsize);
//				assert(ptmp);
//				memcpy(ptmp, (char*)parr + j * elementsize,elementsize);
//				memcpy((char*)parr + j * elementsize, 
//					(char*)parr + (j + 1) * elementsize,elementsize);
//				memcpy((char*)parr + (j + 1) * elementsize, ptmp, elementsize);
//				free(ptmp);
//			}
//		}
//	}
//}
//int Intcmp(void* p1, void* p2)
//{
//	return *(int*)p1 - *(int*)p2;
//}//p1>p2 返回 >0
////p1==p2 返回 0
////p1<p2 返回 <0
//void Print(int* arr,size_t sz)
//{
//	assert(arr);
//	int i = 0;
//	for(i=0;i<sz;++i)
//	{
//		printf("%d ", *(arr + i));
//	}
//}
//int main()
//{
//	int* arr,n;
//	printf("请输入n(想输入个数):>");
//	scanf("%d",&n);
//	printf("请输入%d个整数：>",n);
//	arr = (int*)malloc(n * sizeof(int));
//	assert(arr);
//	int i = 0;
//	for(i=0;i<n;++i)
//	{
//		scanf("%d", arr + i);
//	}
//	BubbleSort(arr, sizeof(int), n, Intcmp);
//	Print(arr, n);
//	return 0;
//}
//int main()
//{
//	int x, y;
//	printf("%d\n", sum(x + y));
//	int sum(a, b);
//	{
//		int a, b;
//		return (a + b);
//	}
//	return 0;
//}
//int main()
//{
//	int a[] = { 'C','h','i','n','a','\0'};
//	printf("%s", a);
//	return 0;
//}


//struct TreeNode {
//    int val;
//    struct TreeNode* left;
//    struct TreeNode* right;
//};
// 
//
//int maxDepth(struct TreeNode* root) {
//    if (!root)
//        return 0;
//    int rightDepth = maxDepth(root->right);
//    int leftDepth = maxDepth(root->left);
//    return rightDepth > leftDepth ? rightDepth + 1 : leftDepth + 1;
//}
//int minDepth(struct TreeNode* root) {
//    if (!root)
//        return 0;
//    int rightDepth = minDepth(root->right);
//    int leftDepth = minDepth(root->left);
//    return rightDepth < leftDepth ? rightDepth + 1 : leftDepth + 1;
//}
//bool isBalanced(struct TreeNode* root) {
//    int a = maxDepth(root);
//    int b = minDepth(root);
//    if (1 >= (maxDepth(root) - minDepth(root)))
//        return true;
//    else
//        return false;
//}
//struct TreeNode* BuyNewNode(int x)
//{
//    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
//    node->val = x;
//    node->left = NULL;
//    node->right = NULL;
//    return node;
//}
//int main()
//{
//    struct TreeNode* A = BuyNewNode(1);
//    struct TreeNode* B = BuyNewNode(2);
//    struct TreeNode* C = BuyNewNode(3);
//    struct TreeNode* D = BuyNewNode(4);
//    struct TreeNode* E = BuyNewNode(5);
//    struct TreeNode* F = BuyNewNode(6);
//    struct TreeNode* G = BuyNewNode(8);
//    A->left = B;
//    A->right = C;
//    C->left = F;
//    B->left = D;
//    B->right = E;
//    D->left = G;
//    if (isBalanced(A))
//    {
//        printf("true");
//    }
//    return 0;
//}

void AdjustDown(char* a, int root, int n) {
    int parent = root;
    int child = parent * 2 + 1;
    while (child < n) {
        if (child + 1 < n && a[child + 1] < a[child])
            child++;
        if (a[parent] > a[child]) {
            char tmp = a[parent];
            a[parent] = a[child];
            a[child] = tmp;
            parent = child;
            child = parent * 2 + 1;
        }
        else
            break;
    }
}
bool isAnagram(char* s, char* t) {
    if (!s && !t)
        return true;
    if (!s || !t)
        return false;

    int i = 0;
    int ns = 0, nt = 0;
    while (s[ns] != '\0')
        ns++;
    while (t[nt] != '\0')
        nt++;
    if (nt != ns)
        return false;
    // 堆排序
    for (i = (ns - 1 - 1) / 2; i >= 0; --i) {
        AdjustDown(s, i, ns);
        AdjustDown(t, i, nt);
    }
    for (i = ns - 1; i > 0; --i) {
        char tmp = s[0];
        s[0] = s[i];
        s[i] = tmp;

        tmp = t[0];
        t[0] = t[i];
        t[i] = tmp;

        AdjustDown(s, 0, i);
        AdjustDown(t, 0, i);
    }

    i = 0;
    while (i < nt && s[i] == t[i])
        ++i;

    if (i == nt)
        return true;
    else
        return false;
}

int main()
{
    char s[] = "anagram";
    char t[] = "nagaram";
    isAnagram(s, t);
    return 0;
}