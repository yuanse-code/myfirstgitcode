#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

//数组形式的整数加法
//整数的 数组形式  num 是按照从左到右的顺序表示其数字的数组。

//例如，对于 num = 1321 ，数组形式是[1, 3, 2, 1] 。
//给定 num ，整数的 数组形式 ，和整数 k ，返回 整数 num + k 的 数组形式 。
//
//提示：
//
//1 <= num.length <= 104
//0 <= num[i] <= 9
//num 不包含任何前导零，除了零本身
//1 <= k <= 104
//int main()
//{
//	int num[] = { 1,2,0,0 };
//	int numSize = 4;
//	int k = 34;
//	int kSize = 0;
//	int kNum = k;
//	int Ai = numSize - 1;
//	while (kNum) {
//		++kSize;
//		kNum /= 10;
//	}
//	int len = numSize > kSize ? numSize : kSize;
//	int* retArr = (int*)malloc(sizeof(int) * (len + 1));
//	int ret = 0;
//	int reti = 0;
//	int nextNum = 0; // 进位
//	while (len--) {
//		int a = 0;
//		if (Ai >= 0) {
//			a = num[Ai];
//			--Ai;
//		}
//		else {
//			a = 0;
//		}
//		ret = a + k % 10 + nextNum;
//		k /= 10;
//		if (ret > 9) {
//			ret -= 10;
//			nextNum = 1;
//		}
//		else {
//			nextNum = 0;
//		}
//		retArr[reti] = ret;
//		reti++;
//	}
//	if (nextNum) {
//		retArr[reti] = 1;
//		reti++;
//	}
//	int left = 0, right = reti - 1;
//	while (left < right) {
//		int tmp = retArr[left];
//		retArr[left] = retArr[right];
//		retArr[right] = tmp;
//		left++;
//		right--;
//	}
//	int i = 0;
//	for (i = 0; i < reti; ++i)
//	{
//		printf("%d", retArr[i]);
//	}
//	free(retArr);
//	retArr = NULL;
//	return 0;
//}


struct ListNode {
    int val;
    struct ListNode* next;
};
 
struct ListNode* detectCycle(struct ListNode* head) {
    struct ListNode* fast = head, * slow = head;
    struct ListNode* cur = head, * curA, * curB;
    while (fast && fast->next) {
        fast = fast->next->next;
        slow = slow->next;
        if (fast != slow)
            break;
    }
    if (!fast)
        return NULL;
    fast = fast->next;
    curA = head;
    curB = fast;
    while (curA != slow && curB != slow) {
        curA = curA->next;
        curB = curB->next;
    }
    while (curA != slow) {
        curA = curA->next;
        cur = cur->next;
    }
    while (curB != slow) {
        curB = curB->next;
        fast = fast->next;
    }
    while (cur != fast) {
        cur = cur->next;
        fast = fast->next;
    }
    return cur;
}
int main()
{
    struct ListNode SList;
    struct ListNode* newnode=(struct ListNode*)malloc(sizeof(struct ListNode));
    newnode->val = 2;
    SList.val = 3;
    SList.next = newnode;
    newnode = (struct ListNode*)malloc(sizeof(struct ListNode));
    SList.next->next = newnode;
    SList.next->next->val = 0;
    newnode = (struct ListNode*)malloc(sizeof(struct ListNode));
    SList.next->next->next = newnode;
    SList.next->next->next->val = -4;
    SList.next->next->next->next = SList.next;


    detectCycle(&SList);

    free(SList.next->next->next);
    SList.next->next->next = NULL;
    free(SList.next->next);
    SList.next->next = NULL;
    free(SList.next);
    SList.next = NULL;
    return 0;
}