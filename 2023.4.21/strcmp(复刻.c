#define _CRT_SECURE_NO_WARNINGS 1
//���̿⺯���е�strcmp����
#include<stdio.h>
#include<assert.h>
int mine_strcmp(const char* str1, const char* str2)
{
	assert(str1 && str2);//��ֹ��ָ�봫��
	while(*str1 == *str2)//�жϴ�С�����С�ַ�����\0'ǰ�ַ���ͬ��ѭ����Ƚ�
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
	//c���Ա�׼ֻ�涨��str1�󷵻�>0��ֵ��str2�󷵻�<0��ֵ
	//return *str1-*str2;
}
int main()
{
	char arr1[20] = "hello",arr2[20]="world";
	printf("%d", mine_strcmp(arr1,arr2));
	return 0;
}