#define _CRT_SECURE_NO_WARNINGS 1
//喝汽水，1瓶汽水1元，2个空瓶可以换一瓶汽水，给20元，可以多少汽水
#include<stdio.h>
#define MONEY 20

int main()
{
	int soda_count = 0, soda_num = MONEY;
		for (;soda_num>1;)
		{
			if (soda_num % 2)
			{
				soda_num /= 2;
				soda_count += soda_num;
				soda_num++;
			}
			else
			{
				soda_num /= 2;
				soda_count += soda_num;
			}
		}
		printf("可以买%d瓶汽水",soda_count);
	return 0;
}