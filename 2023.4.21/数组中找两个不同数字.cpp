#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main()
{
	int a[20] = { 1,2,3,4,5,1,2,3,4,6 };
	int sz = 10;
	int i = 0, j = 0, temp = 0, temp_i = 0;
	for (i = 0; i < sz; i++)//������������Ԫ�����һ��
	{
		temp_i ^= a[i];
	}
	for (i = 0; (temp_i >> i % 1 == 0); i++)//�ҵ�temp_i�з�0�����λ
	{
		;
	}
	temp_i = i;//temp�е�ֵ�Ѿ����ã��������洢���λ��
	for (i = 0, j = sz - 1; i < j; i++)//�����鰴ibitλ��0��1��Ϊ������
	{
		while ((a[i] >> temp_i) % 2 == 1 && i < j)
		{
			temp = a[i];
			a[i] = a[j];
			a[j] = temp;
			j--;
		}
	}
	temp_i = sz / 2;//�Ѿ�������ɣ�temp_i��������
	for (i = 0; i < temp_i; i++)
	{
		temp ^= i;
	}
	for (i = temp_i; i < sz; i++)//temp_i��ֵ����ֲ�������
	{
		temp_i ^= i;
	}
	printf("���Ƿֱ��ǣ�%d��%d", a[temp], a[temp_i]);
	return 0;
}