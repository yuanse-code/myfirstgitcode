#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

void* BubbleSort(void* base, size_t sz, size_t elementsize, int(*p)(void*, void*));
void* ≤Â»ÎSort(void* base, size_t sz, size_t elementsize, int(*p)(void*, void*));
void* My_qSort(void* base, size_t sz, size_t elementsize, int(*p)(void*, void*));