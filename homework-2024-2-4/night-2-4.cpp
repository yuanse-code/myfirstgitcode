#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <assert.h>
#include <string.h>

char* my_strcpy(char* dest,const char* src)
{
	char* ret = dest;
	assert(dest != NULL && src != NULL);
	while (*dest++ = *src++)
	{
		;
	}
	return ret;
}
int my_strlen(const char* str)
{
	int count = 0;
	assert(str != NULL);
	while (*str != '\0')
	{
		str++;
		count++;
	}
	return count;
}
int main()
{
	char arr1[] = "###########";
	char arr2[] = "bit"; 
	char arr[] = "abcdef";
	printf("%s\n",my_strcpy(arr1,arr2));
	printf("%d\n", my_strlen(arr));
	return 0;
}
