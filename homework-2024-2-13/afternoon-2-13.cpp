
#include "mine.h"

int main()
{
	/*int* arr[10];
	int* (*pa)[10] = &arr;
	*/
	int arr[10] = { 6,7,8,2,3,9,1 ,-1 };
	char arr1[5] = "dcba";
	const char* arr2[] = { "addef","accd","aef","ach","adf"};
	char arr3[] = { 'd','a','c','b','\0'};
	long long arr4[] = { 2,3,4,6,1,4,10,-1 };
	char c = 'a';
	/*char a[5] = "abd";
	printf("%d\n", strcmp(arr1, a));*/
	BubbleSort(arr,sizeof(arr)/sizeof(arr[0]),"%d");
	Print(arr, sizeof(arr) / sizeof(arr[0]), "%d");
	BubbleSort(arr1, sizeof(arr1) / sizeof(arr1[0]),"%c");
	printf("%s\n", arr1);//µÚ1¸öÊÇ0
	BubbleSort(arr2, sizeof(arr2) / sizeof(arr2[0]), "%s");
	Print(arr2, sizeof(arr2) / sizeof(arr2[0]), "%s");
	BubbleSort(arr3, sizeof(arr3) / sizeof(arr3[0]), "%c");
	Print(arr3, sizeof(arr3) / sizeof(arr3[0]), "%c");
	BubbleSort(arr4, sizeof(arr4) / sizeof(arr4[0]), "%lld");
	Print(arr4, sizeof(arr4) / sizeof(arr4[0]), "%lld");
	c = getchar();
	printf("%c\n", c);
	return 0;
}