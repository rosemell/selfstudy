#define _CRT_SECURE_NO_WARNINGS 1
#define gets gets_s

#include<stdio.h>
int main()
{
	int m, n;
	printf("请输入两个数:");
	scanf("%d%d", &m, &n);
	int diffrent, diff_num=0;
	diffrent=m^ n;

	while (diffrent)
	{
		diffrent = diffrent & (diffrent - 1);
		diff_num += 1;
	}
	printf("%d", diff_num);
	return 0;
}
