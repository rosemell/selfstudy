#define _CRT_SECURE_NO_WARNINGS 1
//vs�ɽ��������븴�Ƶ��ļ�newc++file.cpp,�Ա�֤�½��Դ�
#include <stdio.h>
int main()
{
	int a = 0, b = 0, i = 0;
	while (a < 9)
	{
		while (b < 9)
		{
			printf("%d*%d=%d   ", a, b,a*b);
			b++;
		}
		printf("\n");
		a++;
		b = 0;
	}
	
	return 0;
}