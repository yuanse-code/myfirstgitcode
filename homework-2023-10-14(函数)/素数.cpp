#define _CRT_SECURE_NO_WARNINGS 1
#include<math.h>
int is_mersenne(int x)
{
	int i = 2;
	for (i = 2;i <= sqrt(x);i++)
	{
		if (0 != x % i)
		{
			continue;
		}
		else
		{
			return 0;
			break;
		}
	}
	return 1;
}