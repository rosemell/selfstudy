#define _CRT_SECURE_NO_WARNINGS 1
#define gets gets_s
//��ĿĿ�ģ�
//��һֻ������̨�ס�һ�ο�����һ��̨�ף�Ҳ����������̨��
//�ʣ�n��̨���ж���������

#include<stdio.h>



int frog(int n)
{
	return n>1 ? frog(n - 2) + frog(n - 1): 1;
	//if (n > 1)
	//	return frog(n - 2) + frog(n - 1);
	//else
	//	return 1;
}
int main()
{
	int n;
	printf("please input the number of steps:\t");
	scanf("%d", &n);
	printf("%d", frog(n));
	return 0;
}
