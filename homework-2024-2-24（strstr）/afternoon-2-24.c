#define _CRT_SECURE_NO_WARNINGS 1
#include <D:/vsc++代码/mine.h>

//char* my_strncpy(char* dest, const char* src, int sz)
//{
//	assert(dest && src);
//	char* ret = dest;
//	while (sz)
//	{
//		if (*src)
//		{
//			*dest++ = *src++;
//		}
//		else
//			*dest++ = '\0';
//		sz--;
//	}
//	return ret;
//}//多复制，就补成‘\0’
char* true_strncpy(char* dest, const char* src, size_t sz)
{
	assert(dest && src);
	char* ret = dest;
	while (sz &&(*dest++ = *src++))
	{
		sz--;
	}
	while (sz)
	{
		*dest++ = '\0';
		sz--;
	}
	return dest;
}
char* my_strncat(char* dest,const char* src, size_t sz)
{
	assert(dest && src);
	char* ret = dest;
	while (*dest++)
	{
		;
	}
	dest--;
	while (sz && (*dest++ = *src++))
	{
		sz--;
	}
	*dest = '\0';
	return ret;
}
int main()
{
	char arr1[20] = "abcdefhi";
	char arr2[] = "hello";
	//my_strncpy(arr1, arr2, 4);
	true_strncpy(arr1, arr2, 3);
	//my_strncat(arr1, arr2,4);
	//strncat(arr1, arr2, 7);
	//strncpy(arr1, arr2, 4);
	printf("%s\n", arr1);
	return 0;
}
//int main()
//{
//	const char* p1 = "abcdef";
//	const char* p2 = "abcqwer";
//	int ret=strncmp(p1, p2, 4);
//	printf("%d\n", ret);
//	return 0;
//}
// 
//KMP算法
char* my_strstr(const char* p1,const char* p2)
{
	assert(p1 && p2);
	char* s1 = (char*)p1;
	char* s2 = (char*)p2;
	char* cur = (char*)p1;
	if (*p2 == '\0')
	{
		return p1;
	}
	while (*cur)
	{
		s1 = cur;
		s2 = (char*)p2;
		while ((*s1==*s2) &&*s1 && *s2)//?"=="与"-"
		{
			s1++;
			s2++;
		}
		if (*s2=='\0')//?"=="与"'\0'"
		{
			return cur;//找到子串
		}
		if (*s1 == '\0')
		{
			return NULL;//找不到子串
		}
		cur++;
	}
	return NULL;//找不到子串
}
//int main()
//{
//	char p[] = "abbbcdef";
//	char p2[] = "bbc";
//	char* ret = my_strstr(p, p2);
//	if (ret == NULL)
//	{
//		printf("子串不存在\n");
//	}
//	else
//	{
//		printf("%s\n", ret);
//	}
//	return 0;
//}