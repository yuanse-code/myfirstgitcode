
#include "≈≈–Ú.h"

extern void* SelectSort(void* base, size_t sz, size_t elementsize, int(*p)(void*, void*));
int IntarrCpy(void* vp1,void* vp2)
{
	return *(int*)vp1 - *(int*)vp2;
}
int main()
{
	int a[10] = { 9,8,7,6,5,4,3,2,1,0 };
	int i = 0;
	//BubbleSort(a, sizeof(a)/sizeof(a[0]), 4, IntarrCpy);
	//SelectSort(a, sizeof(a)/sizeof(a[0]), 4, IntarrCpy);
	//≤Â»ÎSort(a, sizeof(a) / sizeof(a[0]), 4, IntarrCpy);
	My_qSort(a, sizeof(a) / sizeof(a[0]), 4, IntarrCpy);
	for (i = 0; i < 10; i++)
	{
		printf("%d ", a[i]);
	}

	return 0;
}
//long long Fibonacci_r(size_t N)
//{
//	return N < 2 ? N : Fibonacci_r(N - 1) + Fibonacci_r(N - 2);
//}
//long long Fibonacci(size_t N)
//{
//	long long* fibArray = malloc(sizeof(long long) * (N + 1));
//	int i = 0;
//	fibArray[0] = 0;
//	if (N == 0)
//		return 0;
//	fibArray[1] = 1;
//	for (i = 2; i <= N; i++)
//	{
//		fibArray[i] = fibArray[i - 1] + fibArray[i - 2];
//	}
//	return fibArray[N];
//}
//int main()
//{
//	printf("%lld\n", Fibonacci(50));
//	return 0;
//}