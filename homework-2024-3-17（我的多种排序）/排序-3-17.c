#include "≈≈–Ú.h"

static void Exchange(void* vp1, void* vp2,size_t elementsize)
{
	assert(vp1 && vp2 && elementsize);
	void* tmp = NULL;
	tmp = malloc(elementsize);
	memcpy(tmp, vp1, elementsize);
	memcpy(vp1, vp2, elementsize);
	memcpy(vp2, tmp, elementsize);
	free(tmp);
	tmp = NULL;
}
//√∞≈›≈≈–Ú
void* BubbleSort(void* base, size_t sz, size_t elementsize, int(*p)(void*, void*))
{
	assert(base);
	void* ret = base;
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		int j = 0;
		int exchange = 0;
		for (j = 0; j < sz - i-1; j++)
		{
			if (p((char*)base + j * elementsize, (char*)base + (j + 1) * elementsize)>0)
			{
				Exchange((char*)base + j * elementsize, (char*)base + (j + 1) * elementsize, elementsize);
				exchange = 1;
			}
		}
		if (exchange)
			break;
	}
	return  ret;
}
//—°‘Ò≈≈–Ú
void* SelectSort(void* base, size_t sz, size_t elementsize, int(*p)(void*, void*))
{
	assert(base);
	void* ret = base;
	void* tmp = base;
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		int j = 0;
		int exchange = 0;
		for (j = i; j < sz; j++)
		{
				if (p(tmp, (char*)base + j * elementsize)>0)
				{
					tmp = (char*)base + j * elementsize;
					exchange = 1;
				}
		}
		Exchange((char*)base + i * elementsize, tmp, elementsize);
		tmp = (char*)base + (i + 1) * elementsize;
		if (exchange)
			break;
	}
	return ret;
}
//≤Â»Î≈≈–Ú
void* ≤Â»ÎSort(void* base, size_t sz, size_t elementsize, int(*p)(void*, void*))
{
	assert(base);
	void* ret = base;
	int mid = 0;
	for (mid = 0; mid < sz; mid++)
	{
		int j = 0;
		for (j = 0; j < mid; j++)
		{
			if (p((char*)base + j * elementsize, (char*)base + mid * elementsize) > 0)
			{
				Exchange((char*)base + j * elementsize, (char*)base + mid * elementsize, elementsize);
			}
		}
	}
	return ret;
}
//øÏÀŸ≈≈–Ú
void Distinguish(void* base, size_t sz, size_t elementsize, int(*p)(void*, void*))
{
	int i = 0;
	size_t pos = 0;
	for (i = 0; i < sz; ++i)
	{
		if (p(
			(char*)base + pos * elementsize
			, (char*)base + i * elementsize)
			> 0)
		{
			if (i == pos + 1)
			{
				Exchange((char*)base + pos * elementsize, (char*)base + i * elementsize, elementsize);
			}
			else
			{
				Exchange((char*)base + (pos + 1) * elementsize, (char*)base + i * elementsize, elementsize);
				Exchange((char*)base + pos * elementsize, (char*)base + (pos + 1) * elementsize, elementsize);
			}
			pos++;
		}
	}
	if (0 == sz)
		;
	else
	{
		Distinguish(base, pos, elementsize, p);
		if (sz - pos - 1)
			Distinguish((char*)base + (pos + 1) * elementsize, sz - pos - 1, elementsize, p);
	}
}
void* My_qSort(void* base, size_t sz, size_t elementsize, int(*p)(void*, void*))
{
	assert(base);
	Distinguish(base, sz, elementsize, p);
	return base;
}