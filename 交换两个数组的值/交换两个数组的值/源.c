#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main()
{
	int a[10] = { 0 };
	int a1[10] = { 1,2,3,4,5,6,7,8,9,10 };
	int ab = 0;
	
	//计算数组元素个数
	int num = sizeof(a) / sizeof(a[0]);

	//展示数组部分
	{
		int i=0;
		{

			while (i < num)
			{
				printf("a[%d]=", i);
				printf("%d\n", a[i]);
				i++;
			}
				i = 0;
		}
		{
			while (i < num)
			{
				printf("a1[%d]=",i);
				printf("%d\n", a1[i]);
				i++;
			}
		}
	}
	//交换数组核心
	{
		//核心原理；a=a+b	
		//b=a-b
		//a=a-b
		int i = 0;
		while (i < num)
		{
			a[i] = a[i] + a1[i];
			a1[i] = a[i] - a1[i];
			a[i] = a[i] - a1[i];
			i++;
		}
	}
	printf("交换后\n");
	{
		//展示交换后数组
		int i = 0;
		{

			while (i < num)
			{
				printf("a[%d]=", i);
				printf("%d\n", a[i]);
				i++;
			}
			i = 0;
		}
		{
			while (i < num)
			{
				printf("a1[%d]=", i);
				printf("%d\n", a1[i]);
				i++;
			}
		}
	}
			
	
	return 0;
}