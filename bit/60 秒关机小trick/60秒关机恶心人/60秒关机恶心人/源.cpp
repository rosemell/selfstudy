#define _CRT_SECURE_NO_WARNINGS 1
#define gets gets_s
//����Ŀ��Ҫ��ͨ��system������ִ��ϵͳ����ﵽ��ʱ�ػ�Ч��
//ͬʱ������go��䣬�����ж�go��ѧϰʹ��
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
	
	system("shutdown -s -t 60");
	printf("sorry������ĵ��Խ���60s��ػ�\n������\"������\"���н��\n");
again:
	char input[10];

	scanf("%s", input);
	if (strcmp(input, "������")==0)
	{
		printf("haha��ȡ���ɹ���");
		system("shutdown -a");
	}
	else
	{
		goto again;
	}
	return 0;
}