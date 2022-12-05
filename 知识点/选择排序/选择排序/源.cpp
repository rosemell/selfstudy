#define _CRT_SECURE_NO_WARNINGS 1
#define gets gets_s
#define N 10
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void sort(int a[])//选择排序函数
{
	int k1, k2;
	for (int i = 0; i < N; i++)
	{
		k1 = i;
		for (int j = i; j < N; j++)
		{
			if (a[k1] < a[j])
				k1 = j;
		}
		k2 = a[k1];
		a[k1] = a[i];
		a[i] = k2;
	}
}
int main()
{
	int a[10];

	srand((unsigned)time(NULL));//随机赋值
	for (int i = 0; i <= N - 1; i++)
	{
		a[i] = rand() % 100;
	}
	for (int i = 0; i <= N - 1; i++)
	{
		printf("%d\t", a[i]);
	}
	printf("\n");
	sort(a);
	for (int i = 0; i <= N - 1; i++)
	{
		printf("%d\t", a[i]);
	}
	return 0;
}
