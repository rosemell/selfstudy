#define _CRT_SECURE_NO_WARNINGS 1
#define gets gets_s
#include<stdio.h>

#include<string.h>

int main()
{
	char a[100]="wangduoai";
	//gets(a);
	int k = strlen(a) / 2;
	int k2 = strlen(a);
	
	for(int j=1;j<=k;j++)
	{
		for (int i = 0; i <= k2; i++)
		{
			if (i < j || i>=k2-j)
				printf("%c", a[i]);
			else
				printf("*");

		}
		
		printf("\n");
	}
	if (k2 % 2)
		puts(a);
	return 0;
}