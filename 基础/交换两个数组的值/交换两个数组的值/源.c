#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main()
{
	int a[10] = { 0 };
	int a1[10] = { 1,2,3,4,5,6,7,8,9,10 };
	int ab = 0;
	printf("��ӡ��������������\n");
	{

	}
	//չʾ���鲿��
	{
		int i=0;
		{

			while (i < 10)
			{
				printf("a[%d]=", i);
				printf("%d\n", a[i]);
				i++;
			}
				i = 0;
		}
		{
			while (i < 10)
			{
				printf("a1[%d]=",i);
				printf("%d\n", a1[i]);
				i++;
			}
		}
	}
	//�����������
	{
		//����ԭ��a=a+b
		//b=a-b
		//a=a-b
		int i = 0;
		while (i < 10)
		{
			a[i] = a[i] + a1[i];
			a1[i] = a[i] - a1[i];
			a[i] = a[i] - a1[i];
			i++;
		}
	}
	printf("������\n");
	{
		int i = 0;
		{

			while (i < 10)
			{
				printf("a[%d]=", i);
				printf("%d\n", a[i]);
				i++;
			}
			i = 0;
		}
		{
			while (i < 10)
			{
				printf("a1[%d]=", i);
				printf("%d\n", a1[i]);
				i++;
			}
		}
	}
			
	
	return 0;
}