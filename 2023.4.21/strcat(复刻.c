#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<assert.h>
char* mine_stract(char* dest, const char* source)
{
	assert(dest && source);//防止空指针
	char* ret = dest;
	while (*++dest)//找到数组中的'\0'
	{
		;
	}
	while (*dest++=*source++)//把source的内容放到'\0'及之后的空间中（覆盖'\0'
	{
		;
	}
	return ret;//返回目标字符串的地址
}
int main()
{
	char arr1[20] = "hello ";
	char arr2[20] = "world";
	mine_stract(arr1, arr2);
	printf("%s", arr1);
	return 0;
}