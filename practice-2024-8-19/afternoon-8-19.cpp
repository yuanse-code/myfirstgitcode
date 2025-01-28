#include <stdio.h>
#include <string.h>

#define FILE_NAME "log.txt"

//ÿһ���꣬��Ӧ����ֵ��ֻ��һ������λ��1���˴�λ�ò��ص�
#define ONE    0x1
#define TWO  (1 << 1)//0x2
#define THREE 0x4
#define FOUR  0x8

void show(int flags)
{
      if (flags & ONE) printf("one\n");
      if (flags & TWO) printf("two\n");
      if (flags & THREE) printf("three\n");
      if (flags & FOUR) printf("four\n");
    
}

int main()
{
    show(ONE);
    printf("------------------------\n");
    show(TWO);
    printf("------------------------\n");
    show(ONE | TWO);
    printf("------------------------\n");
    show(ONE | TWO | THREE);
    printf("------------------------\n");
    show(ONE | TWO | THREE | FOUR);
    printf("------------------------\n");

}

