#pragma once
#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <assert.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

void PrintArray(int* a, int n);
//��������
void InsertSort(int* a, int n);
//ϣ������
void ShellSort(int* a, int n);
//ֱ��ѡ������
void SelectSort(int* a, int n);

//������
void AdjustDown(int* a, int n, int root);
void HeapSort(int* a, int n);

//ð������
void BubbleSort(int* a, int n);

//��������
void QuickSort(int* a,int left,int right);
//�ǵݹ�
void QuickSortNonR(int* a, int left, int right);

//�鲢����
void MergeSort(int* a, int n);
//�鲢����ǵݹ�ʵ��
void MergeSortNonR(int* a, int n);

char* MergeSortFile(const char* file);

//��������
int CountSort(int* a, int n);