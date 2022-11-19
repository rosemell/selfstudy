#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main()
{
	for (int i = 1; i <= 10; i++)
	{
		int  a[10] = { 1,2,3,4,5,6,7,8,9,10 };
		int mid, x = i;
		printf("x=%d", x);
		printf("please input a word to bother me");
		//scanf("%d", &x);
		{
			{
				int mid = 0, s_sign = 0, b_sign = 9;
				mid = (b_sign + mid) / 2;
				for (; a[mid] != x; )
				{

					if (a[mid] < x)
					{
						s_sign = mid;
						mid = (mid + b_sign) / 2 + 1;
					}
					else
					{
						b_sign = mid;
						mid = (mid + s_sign) / 2;
					}


				}
				printf("%d\n", mid);

			}
		}

	}

	return 0;
}

