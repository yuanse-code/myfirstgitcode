#pragma once
#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <assert.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

void PrintArray(int* a, int n);
//≤Â»Î≈≈–Ú
void InsertSort(int* a, int n);
//œ£∂˚≈≈–Ú
void ShellSort(int* a, int n);
//÷±Ω”—°‘Ò≈≈–Ú
void SelectSort(int* a, int n);

//∂—≈≈–Ú
void AdjustDown(int* a, int n, int root);
void HeapSort(int* a, int n);

//√∞≈›≈≈–Ú
void BubbleSort(int* a, int n);

//øÏÀŸ≈≈–Ú
void QuickSort(int* a,int left,int right);
//∑«µ›πÈ
void QuickSortNonR(int* a, int left, int right);

//πÈ≤¢≈≈–Ú
void MergeSort(int* a, int n);
//πÈ≤¢≈≈–Ú∑«µ›πÈ µœ÷
void MergeSortNonR(int* a, int n);

char* MergeSortFile(const char* file);

//º∆ ˝≈≈–Ú
int CountSort(int* a, int n);