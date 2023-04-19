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
//由于在填第n行的杨辉三角时，只跟第n - 1行的杨辉三角产生联系，不会跟之前的有联系，所以没必要保存每一行的杨辉三角，填一行打一行就行了，这样能让空间复杂度从n ^ 2降低到n。但是在填数据的时候不能对之前的数据覆盖，所以需要从后向前填。而填杨辉三角顺序对结果是没有影响的，所以可以实现。
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
//		for (j = i; j > 0; j--)//为了不覆盖之前数据从后往前赋值
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