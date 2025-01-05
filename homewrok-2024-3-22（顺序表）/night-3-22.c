
#include "SeqList.h"

//两数之和
//int main()
//{
//    int numsSize = 2;
//    int target = 9;
//    int nums[] = { 2, 7, 11, 15 };
//    int i = 0;
//    int* retArr = (int*)malloc(sizeof(int) * 2);
//    for (i = 0; i < numsSize; ++i)
//    {
//        int j = 0;
//        for (j = i; j < numsSize; ++j)
//        {
//            if ((target - nums[i]) == nums[j])
//            {
//                retArr[0] = i;
//                retArr[1] = j;
//                break;
//            }
//        }
//    }
//    printf("%d %d", retArr[0], retArr[1]);
//    free(retArr);
//    retArr = NULL;
//	return 0;
//}
//int main()
//{
//	double a, b;
//	scanf("%d,%d", &a, &b);
//	printf("%d,%d", a, b);
//	return 0;
//}

//测试头尾插入删除
void TestSeqList1()
{
	SL s;
	SeqListInit(&s);
	SeqListPushBack(&s, 1);
	SeqListPushBack(&s, 2);
	SeqListPushBack(&s, 3);
	SeqListPushBack(&s, 4);
	SeqListPushBack(&s, 5);
	SeqListPushBack(&s, 6);
	SeqListPushBack(&s, 7);
	SeqListPushBack(&s, 8);
	SeqListPushBack(&s, 9);

	SeqListPrint(&s);

	SeqListPopBack(&s);
	SeqListPopBack(&s);
	SeqListPopBack(&s);

	SeqListPrint(&s);

	SeqListPushFront(&s, -1);
	SeqListPushFront(&s, -1);

	SeqListPrint(&s);

	SeqListPopFront(&s);
	SeqListPopFront(&s);

	SeqListPrint(&s);
	SeqListDestory(&s);
}
//测试任意插入删除
//
void TestSeqList2()
{
	SL s;
	SeqListInit(&s);
	SeqListInsert(&s, -1, 1);
	SeqListInsert(&s, -1, 2);
	SeqListInsert(&s, -1, 3);
	SeqListInsert(&s, -1, 4);
	
	SeqListPrint(&s);

	SeqListErase(&s, 0);
	SeqListErase(&s, 2);

	SeqListPrint(&s);
	SeqListDestory(&s);
}
//测试顺序表查找
void TestSeqList3()
{
	SL s;
	SeqListInit(&s);
	SeqListPushBack(&s, 1);
	SeqListPushBack(&s, 4);
	SeqListPushBack(&s, 3);
	SeqListPushBack(&s, 3);
	SeqListPushBack(&s, 2);
	SeqListPushBack(&s, 5);
	SeqListPushBack(&s, 6);
	SeqListPushBack(&s, 9);
	SeqListPushBack(&s, 8);
	SeqListPushBack(&s, 7);

	SeqListFind(&s, 3);

	SeqListSort(&s);

	SeqListPrint(&s);

	int ret=SeqListBinaryFind(&s, 9);
	printf("找到了，下标是%d\n", ret);
	SeqListDestory(&s);
}
int main()
{
	//TestSeqList1();
	//TestSeqList2();
	TestSeqList3();

	return 0;
}