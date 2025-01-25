
#include "Sort.h"


void TestInsertSort()
{
	int a[] = { 3,1,4,1,7,9,8,2,0,5 };
	PrintArray(a, sizeof(a) / sizeof(a[0]));
	InsertSort(a, sizeof(a) / sizeof(a[0]));
	PrintArray(a, sizeof(a) / sizeof(a[0]));
}

void TestShellSort()
{
	int a[] = { 20,19,18,17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1,0 };
	PrintArray(a, sizeof(a) / sizeof(a[0]));
	ShellSort(a, sizeof(a) / sizeof(a[0]));
}

void TestOP()
{
	srand(time(0));
	const int N = 10000000;
	int* a1 = (int*)malloc(sizeof(int) * N);
	int* a2 = (int*)malloc(sizeof(int) * N);
	int* a3 = (int*)malloc(sizeof(int) * N);
	int* a4 = (int*)malloc(sizeof(int) * N);
	int* a5 = (int*)malloc(sizeof(int) * N);
	int* a6 = (int*)malloc(sizeof(int) * N);
	for (int i = 0; i < N; ++i)
	{
		a1[i] = rand();
		a2[i] = a1[i];
		a3[i] = a1[i];
		a4[i] = a1[i];
		a5[i] = a1[i];
		a6[i] = a1[i];
	}
	int begin1 = clock();
	//InsertSort(a1, N);
	int end1 = clock();
	int begin2 = clock();
	ShellSort(a2, N);
	int end2 = clock();
	int begin3 = clock();
	//SelectSort(a3, N);
	int end3 = clock();
	int begin4 = clock();
	HeapSort(a4, N);
	int end4 = clock();
	int begin5 = clock();
	QuickSort(a5, 0, N - 1);
	int end5 = clock();


	int begin7 = clock();
	//QuickSort(a5, 0, N - 1);
	int end7 = clock();
	//int begin6 = clock();
	//MergeSort(a6, N);
	//int end6 = clock();
	printf("InsertSort:%d\n", end1 - begin1);
	printf("ShellSort:%d\n", end2 - begin2);
	printf("SelectSort:%d\n", end3 - begin3);
	printf("HeapSort:%d\n", end4 - begin4);
	printf("QuickSort:%d\n", end5 - begin5);
	//printf("MergeSort:%d\n", end6 - begin6);
	printf("˳��QuickSort:%d\n", end7 - begin7);
	free(a1);
	free(a2);
	free(a3);
	free(a4);
	free(a5);
	free(a6);
}

void TestSelectSort()
{
	int a[] = { 20,19,18,17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1,0 };
	PrintArray(a, sizeof(a) / sizeof(a[0]));
	SelectSort(a, sizeof(a) / sizeof(a[0]));
	PrintArray(a, sizeof(a) / sizeof(a[0]));
}
void TestHeapSort()
{
	int a[] = { 20,19,18,17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1,0 };
	PrintArray(a, sizeof(a) / sizeof(a[0]));
	HeapSort(a, sizeof(a) / sizeof(a[0]));
	PrintArray(a, sizeof(a) / sizeof(a[0]));
}

void TestBubbleSort()
{
	int a[] = { 20,19,18,17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1,0 };
	PrintArray(a, sizeof(a) / sizeof(a[0]));
	BubbleSort(a, sizeof(a) / sizeof(a[0]));
	PrintArray(a, sizeof(a) / sizeof(a[0]));
}

void TestQuickSort()
{
	int a[] = { 20,19,18,17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1,0 };
	PrintArray(a, sizeof(a) / sizeof(a[0]));
	QuickSort(a, 0, sizeof(a) / sizeof(a[0]) - 1);
	PrintArray(a, sizeof(a) / sizeof(a[0]));
}

void TestQuickSortNonR()
{
	int a[] = { 20,19,18,17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1,0 };
	PrintArray(a, sizeof(a) / sizeof(a[0]));
	QuickSortNonR(a, 0, sizeof(a) / sizeof(a[0]) - 1);
	PrintArray(a, sizeof(a) / sizeof(a[0]));
}

void TestMergeSort()
{
	int a[] = { 20,19,18,17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1,0 };
	PrintArray(a, sizeof(a) / sizeof(a[0]));
	MergeSort(a, sizeof(a) / sizeof(a[0]));
	PrintArray(a, sizeof(a) / sizeof(a[0]));
}
void TestMergeSortNonR()
{
	int a[] = { 20,19,18,17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1,0 };
	PrintArray(a, sizeof(a) / sizeof(a[0]));
	MergeSortNonR(a, sizeof(a) / sizeof(a[0]));
	PrintArray(a, sizeof(a) / sizeof(a[0]));
}

void TestCountSort()
{
	//int a[] = { 20,19,18,17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1,0 };
	int a[] = { 1,1,1,4,34,4,3,3,3,37,7,7 };
	PrintArray(a, sizeof(a) / sizeof(a[0]));
	CountSort(a, sizeof(a) / sizeof(a[0]));
	PrintArray(a, sizeof(a) / sizeof(a[0]));
}


int main()
{
	//TestInsertSort();
	//TestShellSort();
	//TestSelectSort();
	//TestHeapSort();
	//TestBubbleSort();
	//TestQuickSort();
	//TestQuickSortNonR();
	//TestMergeSort();
	//TestMergeSortNonR();
	//TestOP();
	//MergeSortFile("Sort.txt");

	TestCountSort();
	return 0;
}