#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main()
{
	int n = 9;
	float* pfloat = (float*)&n;
	printf("%d\n", n);
	printf("%f\n", *pfloat);

	*pfloat = 9.0;
	printf("%d\n", n);
	//01000001000100000000000000000000
	printf("%f\n", *pfloat);
	return 0;
}
