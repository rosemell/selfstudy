#define _CRT_SECURE_NO_WARNINGS 1
//����ˮ��1ƿ��ˮ1Ԫ��2����ƿ���Ի�һƿ��ˮ����20Ԫ�����Զ�����ˮ
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
		printf("������%dƿ��ˮ",soda_count);
	return 0;
}