#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<assert.h>
char* mine_stract(char* dest, const char* source)
{
	assert(dest && source);//��ֹ��ָ��
	char* ret = dest;
	while (*++dest)//�ҵ������е�'\0'
	{
		;
	}
	while (*dest++=*source++)//��source�����ݷŵ�'\0'��֮��Ŀռ��У�����'\0'
	{
		;
	}
	return ret;//����Ŀ���ַ����ĵ�ַ
}
int main()
{
	char arr1[20] = "hello ";
	char arr2[20] = "world";
	mine_stract(arr1, arr2);
	printf("%s", arr1);
	return 0;
}