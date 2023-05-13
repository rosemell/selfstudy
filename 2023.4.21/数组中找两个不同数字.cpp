#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main()
{
	int a[20] = { 1,2,3,4,5,1,2,3,4,6 };
	int sz = 10;
	int i = 0, j = 0, temp = 0, temp_i = 0;
	for (i = 0; i < sz; i++)//将数组中所有元素异或一遍
	{
		temp_i ^= a[i];
	}
	for (i = 0; (temp_i >> i % 1 == 0); i++)//找到temp_i中非0的最低位
	{
		;
	}
	temp_i = i;//temp中的值已经无用，故用作存储最低位数
	for (i = 0, j = sz - 1; i < j; i++)//将数组按ibit位的0或1分为两部分
	{
		while ((a[i] >> temp_i) % 2 == 1 && i < j)
		{
			temp = a[i];
			a[i] = a[j];
			a[j] = temp;
			j--;
		}
	}
	temp_i = sz / 2;//已经划分完成，temp_i不再有用
	for (i = 0; i < temp_i; i++)
	{
		temp ^= i;
	}
	for (i = temp_i; i < sz; i++)//temp_i赋值完成又不再有用
	{
		temp_i ^= i;
	}
	printf("他们分别是：%d和%d", a[temp], a[temp_i]);
	return 0;
}