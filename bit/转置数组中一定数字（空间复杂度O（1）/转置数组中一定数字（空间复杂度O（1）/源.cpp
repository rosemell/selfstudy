#define _CRT_SECURE_NO_WARNINGS 1
#define gets gets_s
#include<stdio.h>
#define N 10
void str_1(int* a, int left, int right)
{
	int temp = 0, i = 0;
	for (; left < right; left++, right--)
	{
		temp = a[right];
		a[right] = a[left];
		a[left] = temp;
	}
}
void str(int* a, int size, int k)
{
	int n = size - 1;
	k = k % size;
	str_1(a, 0, n - k);
	str_1(a, n - k + 1, n);
	str_1(a, 0, n);
}
int main()
{
	int a[N] = { 1,2,3,4,5,6,7,8,9,10 };
	int k;
	scanf("%d", &k);
	str(a, N, k);
	int temp_i = 0, temp_n = N - 1;
	for (; temp_i <= temp_n; temp_i++)
	{
		printf("%d", a[temp_i]);
	}
	return 0;
}