#define _CRT_SECURE_NO_WARNINGS 1
//����һ���������飬ʵ��һ��������
//�����������������ֵ�˳��ʹ�����������е�����λ�������ǰ�벿�֣�
//����ż��λ������ĺ�벿�֡�
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
		printf("������\n");
		for (i = 0; i < N; i++)
		{
			printf("%d\t", arr[i]);
		}
		printf("\n");
		scanf("%d", &b);
	} while (b);
	return 0;
}