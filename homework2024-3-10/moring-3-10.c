#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <windows.h>

//int main()
//{
//	double r, h;
//	printf("����Բ��������\n");
//	printf("������뾶cm��>");
//	scanf("%lf", &r);
//	printf("�������cm��>");
//	scanf("%lf", &h);
//	printf("Բ����ı����Ϊ:%lfcm^2\n", 3.14 * 2 * r * r + 3.14 * 2 * r * h);
//	printf("Բ��������Ϊ��%lfcm^2\n", 3.14 * r * r * h);
//	return 0;
//}
//void menu()
//{
//	printf("����ת��: 1.��ʼ��0.�˳�\n");
//}
//enum
//{
//	EXIT,
//	START
//};
//void StartCharge()
//{
//	int min = 0;
//	printf("��ʱת��\n");
//	printf("���������:>");
//	scanf("%d", &min);
//	printf("%dʱ%d��\n", min / 60, min % 60);
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
//			printf("�˳�\n");
//			break;
//		default:
//			printf("�������\n");
//		}
//			
//	} while (input);
//	return 0;
//}
//int main()
//{
//	double F = 0;
//	printf("���϶�ת���϶�\n");
//	printf("�����뻪�϶ȣ�F��:>");
//	scanf("%lf", &F);
//	printf("��%.2lf ��\n",(F-32)*5/9);
//	return 0;
//}
//int main()
//{
//	int min = 0;
//	printf("��ʱת��\n");
//	printf("���������:>");
//	scanf("%d", &min);
//	printf("%dʱ%d��\n", min / 60, min % 60);
//	return 0;
//}

//�Ƴ�Ԫ��
//����һ������ nums ��һ��ֵ val������Ҫ ԭ�� �Ƴ�������ֵ���� val ��Ԫ�أ�
// �������Ƴ���������³��ȡ�
// 
//��Ҫʹ�ö��������ռ䣬������ʹ�� O(1) ����ռ䲢 ԭ�� �޸��������顣
//Ԫ�ص�˳����Ըı䡣�㲻��Ҫ���������г����³��Ⱥ����Ԫ�ء�
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