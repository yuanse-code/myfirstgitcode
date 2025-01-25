#include "Sort.h"
#include "Stack.h"

void PrintArray(int* a, int n)
{
	for (int i = 0; i < n; ++i)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}
//ʱ�临�Ӷ�ΪO��N*N��
//˳�����O��N��,�����O��N*N��
void InsertSort(int* a, int n)
{
	assert(a);
	int end = 0;
	for (end = 0; end < n - 1; ++end)
	{
		//��end+1���뵽[0��end]
		int tmp = a[end + 1];
		while (end >= 0)
		{
			if (tmp < a[end])
			{
				a[end + 1] = a[end];
				--end;
			}
			else
			{
				break;
			}
		}
		a[end + 1] = tmp;
	}
}

//ϣ������O(N^1.3-N^2)
void ShellSort(int* a, int n)
{
	assert(a);
	int gap = n;
	//1.gap>1�൱��Ԥ���򣬽ӽ�����
	//2.gap==1����ֱ�Ӳ�������
	while (gap > 1)
	{
		gap = gap / 3 + 1;//<-����3
		//��1��֤���һ��gapһ����һ
		//gap==1���һ���൱��ֱ�Ӳ�������
		int j = 0;
		int end = 0;
		//1.Ԥ����
		for (j = 0; j < n - gap; ++j)
		{
			end = j;
			int tmp = a[end + gap];
			while (end >= 0)
			{
				if (tmp < a[end])
				{
					a[end + gap] = a[end];
					end -= gap;
				}
				else
				{
					break;
				}
			}
			a[end + gap] = tmp;
		}
		//PrintArray(a, n);
	}
}

void Swap(int* p1, int* p2)
{
	int tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}

//ֱ��ѡ������
//O(N*N)
void SelectSort(int* a, int n)
{
	assert(a);
	int end = n - 1;
	int begin = 0;
	while (end > begin)
	{
		//��[begin,end]֮���ҳ���С������������±�
		int mini, maxi;
		mini = maxi = begin;
		for (int i = begin + 1; i <= end; ++i)
		{
			if (a[i] > a[maxi])
			{
				maxi = i;
			}
			if (a[i] < a[mini])
			{
				mini = i;
			}
		}
		Swap(&a[begin], &a[mini]);
		//���maxi��beginλ���ص�����maxi��λ����Ҫ����
		if (begin == maxi )
		{
			maxi = mini;
		}
		Swap(&a[end], &a[maxi]);
		end--;
		begin++;
	}
}

//������
void AdjustDown(int* a, int n, int root)
{
	int parent = root;
	int child = parent * 2 + 1;
	while (child < n)
	{
		if (child + 1 < n && a[child + 1] > a[child])
			child++;
		if (a[child] > a[parent])
		{
			Swap(&a[child], &a[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
			break;
	}
}
//ʱ�临�Ӷ�O(N*logN)
void HeapSort(int* a, int n)
{
	//�����򣬽����
	int i = 0;
	for (i = (n - 1 - 1) / 2; i >= 0; --i)
	{
		AdjustDown(a, n, i);
	}
	for (i = n-1; i > 0; --i)
	{
		Swap(&a[0], &a[i]);
		AdjustDown(a, i , 0);
	}
}

//ð������
void BubbleSort(int* a, int n)
{
	int i = 0;
	int end = n;
	while (end > 0)
	{
		int exchange = 0;
		for (i = 1; i < end; ++i)
		{
			if (a[i - 1] > a[i])
			{
				Swap(&a[i - 1], &a[i]);
				exchange = 1;
			}
		}
		//���һ��ð�ݵĹ�����û�з������������Ѿ����򣬲���Ҫ��ð��
		if (!exchange)
		{
			break;
		}
		--end;
	}
}


//����ȡ��
int GetMidIndex(int* a, int begin, int end)
{
	int mid = (begin + end) / 2;
	if (a[begin] < a[mid])
	{
		if (a[mid] < a[end])
		{
			return mid;
		}
		else if (a[begin] > a[end])
			return begin;
		else
			return end;
	}
	else//a[begin]>a[mid]
	{
		if (a[a[mid] > a[end]])
			return mid;
		else if (a[begin], a[end])
			return begin;
		else
			return end;
	}
}
//[begin,end]
int partSort(int* a, int begin, int end)
{
	//���ѡ���ұߵ�ֵ��key
	//һ��Ҫ��begin����
	int midIndex = GetMidIndex(a, begin, end);
	Swap(&a[midIndex], &a[end]);
	int keyindex = end;
	while (begin < end)
	{
		//begin�Ҵ�//�������������key��
		while (begin < end && a[begin] <= a[keyindex])
		{
			++begin;
		}

		//end��С
		while (begin < end && a[end] >= a[keyindex])
		{
			--end;
		}
		Swap(&a[begin], &a[end]);
	}
	Swap(&a[begin], &a[keyindex]);
	return begin;
}

//�ڿӷ�
int partSort2(int* a, int begin, int end)
{
	int midIndex = GetMidIndex(a, begin, end);
	Swap(&a[midIndex], &a[end]);

	//�ӣ��ӵ���˼������λ�õ�ֵ�������ˣ�
	int key = a[end];
	while (begin < end)
	{
		while (begin < end && a[begin] <= key)
		{
			++begin;
		}

		//����ҵ���key�����ұߵĿӣ�beginλ�þ��γ��µĿ�
		a[end] = a[begin];

		while (begin < end && a[end] >= key)
		{
			--end;
		}

		//�ұ��ҵ���keyС�����ߵĿӣ�endλ�þ��γ��µĿ�
		a[begin] = a[end];
	}
	a[begin] = key;

	return begin;
}

//3.ǰ��ָ�뷨
int partSort3(int* a, int begin, int end)
{
	int midIndex = GetMidIndex(a, begin, end);
	Swap(&a[midIndex], &a[end]);

	int keyindex = end;
	int cur = begin, prev = begin - 1;
	while (cur < end)
	{
		while (a[cur] < a[keyindex]&& ++prev!=cur)
			Swap(&a[cur], &a[prev]);
		++cur;
	}
	Swap(&a[keyindex], &a[++prev]);
	return prev;
}
//��������//����ȡ�У����ۺ���˵O(N*N)
//���O��N*logN��
//�����ӽ�����O(N*N)
void QuickSort(int* a, int left,int right)
{
	assert(a);
	if (left>=right)
		return;

	if ((right - left + 1) > 10)
	{
		//PrintArray(a + left, right - left + 1);

		int div = partSort3(a, left, right);

		//printf("[%d,%d]%d[%d,%d]\n", left, div - 1, div, div + 1, right);
		//[left,div-1],[div+1��right]
		QuickSort(a, left, div - 1);
		QuickSort(a, div + 1, right);
	}
	else
	{
		//С��10�������ڵ����䣬���ٵݹ�����
		InsertSort(a + left, right - left + 1);
	}
}

void QuickSortNonR(int* a, int left, int right)
{
	//ջģ����ʵ��
	ST st;
	StackInit(&st);

	StackPush(&st, right);
	StackPush(&st, left);

	while (!StackEmpty(&st))
	{
		int begin = StackTop(&st);
		StackPop(&st);
		int end = StackTop(&st);
		StackPop(&st);

		//[begin,end]
		int div = partSort3(a, begin, end);
		//[begin,div-1]div[div+1,end]
		if (div + 1 < end)
		{
			StackPush(&st, end);
			StackPush(&st, div + 1);
		}
		if (begin < div - 1)
		{
			StackPush(&st, div - 1);
			StackPush(&st, begin);
		}
	}
	StackDestory(&st);
}

int MergeArr(int* a, int begin1, int end1, int begin2, int end2,int* tmp)
{
	int left = begin1, right = end2;
	int index = begin1;
	while (begin1 <= end1 && begin2 <= end2)
	{
		if (a[begin1] < a[begin2])
			tmp[index++] = a[begin1++];
		else
			tmp[index++] = a[begin2++];
	}

	while (begin1 <= end1)
	{
		tmp[index++] = a[begin1++];
	}

	while (begin2 <= end2)
	{
		tmp[index++] = a[begin2++];
	}
	//�ѹ鲢�õ���tmp�������ڿ����ص�ԭ����
	for (int i = left; i <= right; ++i)
	{
		a[i] = tmp[i];
	}
}
//ʱ�临�Ӷ�O(N*logN)
void _MergeSort(int* a, int left, int right, int* tmp)
{
	if (left >= right)
		return;
	int mid = (left + right) / 2;
	//[left,mid][mid+1,right]//��������Ժϲ�����������û������������
	_MergeSort(a, left, mid, tmp);
	_MergeSort(a, mid + 1, right, tmp);

	//�鲢[left,mid][mid+1��right]
	MergeArr(a, left, mid, mid + 1, right, tmp);
}
//�鲢����
void MergeSort(int* a, int n)
{
	assert(a);

	int* tmp = malloc(sizeof(int) * n);

	_MergeSort(a, 0, n - 1, tmp);

	free(tmp);
}

//�鲢����ǵݹ�ʵ��
void MergeSortNonR(int* a, int n)
{
	assert(a);
	int* tmp = malloc(sizeof(int) * n);
	int gap = 1;
	for (gap = 1; gap < n; gap *= 2)
	{
		for (int i = 0; i < n; i += 2 * gap)
		{
			//[i,i+gap-1][i+gap,i+2*gap-1]
			int begin1 = i, end1 = i + gap - 1;
			int begin2 = i + gap, end2 = i + gap * 2 - 1;
			//1.�ϲ�ʱֻ�еڶ���,�Ͳ���Ҫ�ϲ�
			if (begin2 >= n)
				break;
			//2.�ϲ�ʱ�ڶ���ֻ�в�������
			if (end2 >= n)
				end2 = n - 1;

			MergeArr(a, begin1, end1, begin2, end2, tmp);
		}
	}

	free(tmp);
}

void _MergeFile(const char* file1, const char* file2, const char* mfile)
{
	FILE* fout1 = fopen(file1, "r");
	if (!fout1)
	{
		printf("%s", strerror(errno));
		return NULL;
	}

	FILE* fout2 = fopen(file2, "r");
	if (!fout1)
	{
		printf("%s", strerror(errno));
		return NULL;
	}

	FILE* fin = fopen(mfile, "w");
	if (!fin)
	{
		printf("%s", strerror(errno));
		return NULL;
	}

	int num1, num2;
	int ret1 = fscanf(fout1, "%d\n", &num1);
	int ret2 = fscanf(fout2, "%d\n", &num2);
	while (ret1 != EOF && ret2 != EOF)
	{
		if (num1 < num2)
		{
			fprintf(fin, "%d\n", num1);
			ret1 = fscanf(fout1, "%d\n", &num1);
		}
		else
		{
			fprintf(fin, "%d\n", num2);
			ret2 = fscanf(fout2, "%d\n", &num2);
		}
	}

	while (ret1 != EOF)
	{
		fprintf(fin, "%d\n", num1);
		ret1 = fscanf(fout1, "%d\n", &num1);
	}

	while (ret2 != EOF)
	{
		fprintf(fin, "%d\n", num2);
		ret2 = fscanf(fout2, "%d\n", &num2);
	}

	fclose(fout1);
	fclose(fout2);
	fclose(fin);
}
char* MergeSortFile(const char* file)
{
	FILE* fin = fopen(file, "r");
	if (!fin)
	{
		printf("%s", strerror(errno));
		return NULL;
	}
	int n = 10;
	char subfile[30] = { 0 };
	int i = 0;
	int filei=1;
	int num = 0;
	int* arr = (int*)malloc(sizeof(int) * n);
	if (!arr)
	{
		printf("%s", strerror(errno));
		return NULL;
	}
	while (fscanf(fin, "%d\n", &num)!=EOF)
	{
		if(i < n-1)
			arr[i++] = num;
		else
		{
			arr[i++] = num;
			QuickSort(arr, 0, n - 1);
			sprintf(subfile, "sub\\sub_sort%d.txt", filei++);

			FILE* fout = fopen(subfile, "w");
			if (!fout)
			{
				printf("%s", strerror(errno));
				return NULL;
			}

			for (i = 0; i < n; ++i)
			{
				fprintf(fout, "%d\n", arr[i]);
			}
			fclose(fout);
			memset(arr, 0, sizeof(int) * n);
			i = 0;
		}
	}
	free(arr);
	fclose(fin);

	//�鲢
	char mfile[100]="sub\\12";
	char file1[100] = "sub\\sub_sort1.txt";
	char file2[100] = "sub\\sub_sort2.txt";
	for (i = 2; i <= n; ++i)
	{
		sprintf(file2, "sub\\sub_sort%d.txt", i);

		//��ȡfile1��file2�����й鲢��mfile
		_MergeFile(file1, file2, mfile);

		strcpy(file1, mfile);
		sprintf(mfile, "%s%d", mfile, i+1);
	}
	FILE* fend = fopen("fileSortEnd.txt", "a+");
	if (!fend)
	{
		printf("%s", strerror(errno));
		return NULL;
	}
	int tmpEnd = 0, tmpIn;
	//for (i = 0; i < filei; ++i)
	//{
	//	while(feof())
	//}


	fclose(fend);
	return "fileSortEnd";
}

//��������
//ʱ�临�Ӷ�O(N+range)
//�ռ临�Ӷ�O(range)
//ֻ���������Σ���������ͻ����ַ��������ǱȽ�����
int CountSort(int* a, int n)
{
	assert(a);

	int min = a[0];
	int max = a[0];
	for (int i = 1; i < n; ++i)
	{
		if (a[i] > max)
		{
			max = a[i];
		}

		if (a[i] < min)
			min = a[i];

	}

	int range = max - min + 1;
	int* countArr = (int*)malloc(sizeof(int) * range);
	if (!countArr)
	{
		printf("%s", strerror(errno));
		return NULL;
	}

	memset(countArr, 0, sizeof(int) * range);

	//ͳ�ƴ���
	for (int i = 0; i < n; ++i)
	{
		countArr[a[i] - min]++;
	}

	//����
	int index = 0;
	for (int j = 0; j < range; ++j)
	{
		while (countArr[j]--)
		{
			a[index++] = j + min;
		}
	}

	free(countArr);
}