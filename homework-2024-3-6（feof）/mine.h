#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

//BubbleSort 和 Print

//泛型函数，冒泡排序BubbleSort
//char-%c short-%hd int-%d float-%f long long-%lld double-%lf long-%ld
#define value 0.0000001
#define value2 0.000001
typedef int(*Fun)(const void*, const void*);

int hd_pcmp(const void* right, const void* left)
{
	return *(short*)right - *(short*)left;
}
int lld_pcmp(const void* right, const void* left)
{
	return (int)(*(long long*)right - *(long long*)left);
}
int ld_pcmp(const void* right, const void* left)
{
	return *(long*)right - *(long*)left;
}
int d_pcmp(const void* right, const void* left)
{
	return *(int*)right - *(int*)left;
}
int c_pcmp(const void* right, const void* left)
{
	return *(char*)right - *(char*)left;
}
int lf_pcmp(const void* right, const void* left)
{
	double a = *(double*)right - *(double*)left;
	if (a >= value)
	{
		return 1;
	}
	else if (a < value)
	{
		return -1;
	}
	else
	{
		return 0;
	}
}
int f_pcmp(const void* right, const void* left)
{
	float a = *(float*)right - *(float*)left;
	if (a >= value2)
	{
		return 1;
	}
	else if (a < value2)
	{
		return -1;
	}
	else
	{
		return 0;
	}
}
int s_pcmp(const void* right, const void* left)
{
	return strcmp(*(char**)right, *(char**)left);
}
void exchange(void* right, void* left, int elementsize)
{
	assert(elementsize != 0);
	void* tmp = malloc(elementsize);
	memcpy(tmp, left, elementsize);
	memcpy(left, right, elementsize);
	memcpy(right, tmp, elementsize);
	free(tmp);
}
void inputerror(int elementsize, Fun pcmp)
{
	printf("类型输入错误\n");
	assert(elementsize != 0);
	assert(c_pcmp == pcmp || hd_pcmp == pcmp || d_pcmp == pcmp || f_pcmp == pcmp || lld_pcmp == pcmp || lf_pcmp == pcmp || s_pcmp == pcmp);
}
void typesize(const char inputtype[3],int* elementsize, int (**pcmp)(const void*,const void*))
{
	if ('%' == inputtype[0])
	{
		if ('c' == inputtype[1])//判断输入类型和计算元素内存大小
		{
			*pcmp = c_pcmp;
			*elementsize = 1;
		}
		else if ('h' == inputtype[1])
		{
			*pcmp = hd_pcmp;
			*elementsize = 2;
		}
		else if ('d' == inputtype[1])
		{
			if (0 == inputtype[2])
			{
				*pcmp = d_pcmp;
				*elementsize = 4;
			}
			else
			{
				inputerror(*elementsize, *pcmp);
			}
		}
		else if ('f' == inputtype[1])
		{
			*pcmp = f_pcmp;
			*elementsize = 4;
		}
		else if ('l' == inputtype[1])
		{
			if ('f' == inputtype[2])
			{
				*pcmp = lf_pcmp;
				*elementsize = 8;
			}
			else if ('l' == inputtype[2])
			{
				*pcmp = lld_pcmp;
				*elementsize = 8;
			}
			else if ('d' == inputtype[2])
			{
				*pcmp = ld_pcmp;
				*elementsize = 8;
			}
			else
			{
				inputerror(*elementsize, *pcmp);
			}
		}
		else if ('s' == inputtype[1])
		{
			*pcmp = s_pcmp;
			*elementsize = sizeof(char*);
		}
		else
		{
			inputerror(*elementsize, *pcmp);
		}
	}
	else
	{
		inputerror(*elementsize, *pcmp);
	}
}
void* BubbleSort(void* arr, int sz, const char inputtype[3])
{
	int j = 0;
	int elementsize = 0;
	void* ret = arr;
	void* right = NULL;
	void* left = NULL;
	Fun pcmp = d_pcmp;
	sz--;
	int tmp = sz;
	typesize(inputtype,&elementsize,&pcmp);//判断输入类型和计算元素内存大小
	if (inputtype[1] == 'c')
	{
		while (sz)//判断‘\0’
		{
			if (0 == *((char*)arr + sz * elementsize))
			{
				tmp = sz - 1;
			}
			sz--;
		}
	}
	sz = tmp;
	while (sz)
	{
		for (j = 0;j < sz;j++)
		{
			right = (char*)arr + (j + 1) * elementsize;
			left = (char*)arr + j * elementsize;
			if (pcmp(right, left) < 0)
			{
				exchange(right, left, elementsize);
			}
		}
		sz--;
	}
	return ret;
}
//泛型函数，冒泡排序
//泛型数组打印Print
typedef void(*Print_)(const void*, int);
void Printd(const void* arr, int i)
{
	printf("%d ", *((int*)arr + i));
}
void Printlld(const void* arr, int i)
{
	printf("%lld ", *((long long*)arr + i));
}
void Printld(const void* arr, int i)
{
	printf("%ld ", *((long*)arr + i));
}
void Printhd(const void* arr, int i)
{
	printf("%d ", *((short*)arr + i));
}
void Printf(const void* arr, int i)
{
	printf("%f ", *((float*)arr + i));
}
void Printlf(const void* arr, int i)
{
	printf("%lf ", *((double*)arr + i));
}
void Prints(const void* arr, int i)
{
	printf("%s ", *((char**)arr + i));
}
void Printc(const void* arr, int i)
{
	if (*((char*)arr + i) != 0)
	{
		printf("%c", *((char*)arr + i));
	}
}

void Print(const void* arr, const int sz, const char inputtype[3])
{
	int i = 0;
	Print_ Print_format = Printc;
	if ('%' == inputtype[0])
	{
		if ('c' == inputtype[1])//判断输入类型和计算元素内存大小
		{
			Print_format = Printc;
		}
		else if ('h' == inputtype[1])
		{
			Print_format = Printhd;
		}
		else if ('d' == inputtype[1])
		{
			if (0 == inputtype[2])
			{
				Print_format = Printd;
			}
			else
			{
				printf("类型输入错误\n");
				assert(Printc == Print_format || Printhd == Print_format || Printd == Print_format || Printf == Print_format || Printlld == Print_format || Printlf == Print_format || Prints == Print_format);
			}
		}
		else if ('f' == inputtype[1])
		{
			Print_format = Printf;
		}
		else if ('l' == inputtype[1])
		{
			if ('f' == inputtype[2])
			{
				Print_format = Printlf;
			}
			else if ('l' == inputtype[2])
			{
				Print_format = Printlld;
			}
			else if ('d' == inputtype[2])
			{
				Print_format = Printld;
			}
			else
			{
				printf("类型输入错误\n");
				assert(Printc == Print_format || Printhd == Print_format || Printd == Print_format || Printf == Print_format || Printlld == Print_format || Printlf == Print_format || Prints == Print_format);
			}
		}
		else if ('s' == inputtype[1])
		{
			Print_format = Prints;
		}
		else
		{
			printf("类型输入错误\n");
			assert(Printc == Print_format || Printhd == Print_format || Printd == Print_format || Printf == Print_format || Printlld == Print_format || Printlf == Print_format || Prints == Print_format);
		}
	}
	else
	{
		printf("类型输入错误\n");
		assert(Printc == Print_format || Printhd == Print_format || Printd == Print_format || Printf == Print_format || Printlld == Print_format || Printlf == Print_format || Prints == Print_format);
	}
	for (i = 0;i < sz;i++)
	{
		Print_format(arr, i);
	}
	printf("\n");
}
