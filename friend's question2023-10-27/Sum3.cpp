#include"Sum3.h"
int Sum3(int x)
{
	while (0 != x)
	{
		return x % 10 + Sum3(x / 10);
	}
	return 0;
}