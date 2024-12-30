#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <windows.h>

//int main()
//{
//	double r, h;
//	printf("计算圆柱体的体积\n");
//	printf("请输入半径cm：>");
//	scanf("%lf", &r);
//	printf("请输入高cm：>");
//	scanf("%lf", &h);
//	printf("圆柱体的表面积为:%lfcm^2\n", 3.14 * 2 * r * r + 3.14 * 2 * r * h);
//	printf("圆柱体的体积为：%lfcm^2\n", 3.14 * r * r * h);
//	return 0;
//}
//void menu()
//{
//	printf("分钟转换: 1.开始，0.退出\n");
//}
//enum
//{
//	EXIT,
//	START
//};
//void StartCharge()
//{
//	int min = 0;
//	printf("分时转换\n");
//	printf("请输入分钟:>");
//	scanf("%d", &min);
//	printf("%d时%d分\n", min / 60, min % 60);
//	printf("%s\n", __TIME__);
//}
//int main()
//{
//	int input = 0;
//	do
//	{
//		menu();
//		input = _getch() - 48;
//		system("cls");
//		switch(input)
//		{
//		case START:
//			StartCharge();
//			break;
//		case EXIT:
//			system("cls");
//			printf("退出\n");
//			break;
//		default:
//			printf("输入错误\n");
//		}
//			
//	} while (input);
//	return 0;
//}
//int main()
//{
//	double F = 0;
//	printf("华氏度转摄氏度\n");
//	printf("请输入华氏度（F）:>");
//	scanf("%lf", &F);
//	printf("是%.2lf ℃\n",(F-32)*5/9);
//	return 0;
//}
//int main()
//{
//	int min = 0;
//	printf("分时转换\n");
//	printf("请输入分钟:>");
//	scanf("%d", &min);
//	printf("%d时%d分\n", min / 60, min % 60);
//	return 0;
//}

//移除元素
//给你一个数组 nums 和一个值 val，你需要 原地 移除所有数值等于 val 的元素，
// 并返回移除后数组的新长度。
// 
//不要使用额外的数组空间，你必须仅使用 O(1) 额外空间并 原地 修改输入数组。
//元素的顺序可以改变。你不需要考虑数组中超出新长度后面的元素。
int main()
{
    int nums[] = { 0,1,2,2,3,0,4,2 };
    int numsSize = 8;
    int val = 2;
    int* right = nums;
    int* left = nums;
    for (right = nums; right < nums + numsSize; ++right) {
        if (*right == val)
            ;
        else {
            *left = *right;
            left++;
        }
    }
    printf("%d", left-nums);
	return 0;
}