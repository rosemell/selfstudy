#define _CRT_SECURE_NO_WARNINGS 1
#define gets gets_s

#define N 13
#include<stdio.h>

int main()
{
	char a[N]={0}, * p = a;
	int left, right,i=0;
	for(p=a;p<&a[N];)
	{
		*p++ = '*';
	}
	p = &a[0];
	//不要随意改变p的值
	for (left = right=N/2+1; left; left--,right++)
	{
		for (i = left; i; i--)
		{
			printf("  ");
		}
		for (i = left; i <= right; i++)
		{
			printf("%c ", *(p + left));
		}
		printf("\n");
	}
	for (left = 0,right = N+1; left<=right; left++, right--)
	{
		for (i = left; i; i--)
		{
			printf("  ");
		}
		for (i = left; i <= right; i++)
		{
			printf("%c ", *(p + left));
		}
		printf("\n");
	}
	return 0;
}


//#include<stdio.h>
//int main()
//{
//	char a, * p;
//	p = &a;
//	a = '1';
//	printf("%c", *p);
//	return 0;
//}