#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#define N 10
int main()
{
	int i = 0,j=0;
	int a[N][N]={0};
	for (i = 0; i < N; i++)
	{
		a[i][0] = 1;
		for (j = 1; j <= i; j++)
		{
			a[i][j] = a[i - 1][j] + a[i - 1][j - 1];
		}
	}
	for (i = 0; i < N; i++)
	{
		for (j = 0; j <= i; j++)
		{
			printf("%d  ", a[i][j]);
		}
		printf("\n");
	}
	return 0;
}
//���������n�е��������ʱ��ֻ����n - 1�е�������ǲ�����ϵ�������֮ǰ������ϵ������û��Ҫ����ÿһ�е�������ǣ���һ�д�һ�о����ˣ��������ÿռ临�Ӷȴ�n ^ 2���͵�n�������������ݵ�ʱ���ܶ�֮ǰ�����ݸ��ǣ�������Ҫ�Ӻ���ǰ������������˳��Խ����û��Ӱ��ģ����Կ���ʵ�֡�
//#include<stdio.h>
//#include<string.h>
//void yangHuiTriangle(int n)
//{
//	int data[30] = { 1 };
//
//	int i, j;
//	printf("1\n");
//	for (i = 1; i < n; i++) 
//	{
//		for (j = i; j > 0; j--)//Ϊ�˲�����֮ǰ���ݴӺ���ǰ��ֵ
//		{
//			data[j] += data[j - 1];
//		}
//
//		for (j = 0; j <= i; j++)
//		{
//			printf("%d ", data[j]);
//		}
//		putchar('\n');
//	}
//}
//int main()
//{
//	yangHuiTriangle(20);
//	return 0;
//}