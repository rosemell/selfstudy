#define _CRT_SECURE_NO_WARNINGS 1
//复刻库函数中的strcmp函数
#include<stdio.h>
#include<assert.h>
int mine_strcmp(const char* str1, const char* str2)
{
	assert(str1 && str2);//防止空指针传入
	while(*str1 == *str2)//判断大小，如果小字符串‘\0'前字符相同则循环外比较
	{
		if (*str1 == 0)
			return 0;
		str1++;
		str2++;
	}
	if (*str1 > *str2)
		return 1;
	else
		return -1;
	//c语言标准只规定了str1大返回>0的值，str2大返回<0的值
	//return *str1-*str2;
}
int main()
{
	char arr1[20] = "hello",arr2[20]="world";
	printf("%d", mine_strcmp(arr1,arr2));
	return 0;
}