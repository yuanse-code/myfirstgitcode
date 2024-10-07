#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <assert.h>

//void my_strcpy(char* dest, char* src)
//{
//	//while ('\0' != *src)
//	//{
//	//	*dest++= *src++;
//	//	/*dest++;
//	//	src++;*/
//	//}
//	//*dest = *src;
//	if (dest != NULL && src != NULL)
//	{
//		while (*dest++ = *src++)
//		{
//			;
//		}
//	}
//}
void my_strcpy(char* dest,const char* src)
{
	assert(dest != NULL);
	assert(src != NULL);
	while (*dest++ = *src++)
	{
		;
	}
}
int main()
{
	//strcpy
	char arr1[] = "#############";
	char arr2[] = "bit";
	my_strcpy(arr1, arr2);
	int num = 10;
	int*const p = &num;
	*p = 20;
	printf("%s\n", arr1);
	return 0;
}
