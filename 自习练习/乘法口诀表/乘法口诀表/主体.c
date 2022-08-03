#define _CRT_SECURE_NO_WARNINGS 1
//vs可将上述代码复制到文件newc++file.cpp,以保证新建自带
#include <stdio.h>
int main()
{
	int a = 0, b = 0, i = 0;
	while (a < 9)
	{
		while (b < 9)
		{
			printf("%d*%d=%d\t", a, b,a*b);
			b++;
		}
		printf("\n");
		a++;
		b = 0;
	}
	
	return 0;
}
