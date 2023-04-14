#define _CRT_SECURE_NO_WARNINGS 1
//输入一个整数数组，实现一个函数，
//来调整该数组中数字的顺序使得数组中所有的奇数位于数组的前半部分，
//所有偶数位于数组的后半部分。
#include<stdio.h>
#define N 10
#include<stdlib.h>
#include<time.h>
int main()
{
	int b = 0;
	do
	{
		srand((unsigned int)time(NULL));
		//srand(2);
		int arr[N] = { 0 };
		int i = 0;
		for (i = 0; i < N; i++)
		{
			arr[i] = rand() % 10;
		}
		for (i = 0; i < N; i++)
		{
			printf("%d\t", arr[i]);
		}
		printf("\n");
		int subsign = 0, temp = 0, j = N - 1;
		for (i = 0; i < j; i++)
		{
			if (arr[i] % 2 == 0)
			{
				for (; i < j; j--)
				{
					if (arr[j] % 2 == 1)
					{
						temp = arr[j];
						arr[j] = arr[i];
						arr[i] = temp;
						break;
					}
				}
			}
		}
		printf("交换后：\n");
		for (i = 0; i < N; i++)
		{
			printf("%d\t", arr[i]);
		}
		printf("\n");
		scanf("%d", &b);
	} while (b);
	return 0;
}