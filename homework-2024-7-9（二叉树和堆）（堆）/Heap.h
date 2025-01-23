#pragma once
#define  _CRT_SECURE_NO_WARNINGS 1
typedef int HPDataType;
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <assert.h>

//Ð¡¶Ñ
typedef struct Heap
{
	HPDataType* _a;
	int _size;
	int _capacity;
}Heap;

void HeapInit(Heap* php, HPDataType* a,int n);
void HeapDestory(Heap* php);
void HeapPush(Heap* php, HPDataType x);
void HeapPop(Heap* php);
HPDataType HeapTop(Heap* php);