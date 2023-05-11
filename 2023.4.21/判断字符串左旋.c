#define _CRT_SECURE_NO_WARNINGS 1
//Ŀ�꣺�ж�һ���ַ����Ƿ�Ϊ��һ���ַ��������Ľ��
#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<string.h>
#include<assert.h>
int check_cahr_num(char* arr1, char* arr2, int num)//�����ж�һ���ַ���ǰnum���ַ��Ƿ����
{
	assert(arr1 && arr2);
	while (num--)
	{
		if (arr1[num] != arr2[num])
		{
			return 0;
		}
	}
	return 1;
}
int judge(const char* arr1,const char* arr2)//�жϺ���
{
	int len1 = strlen(arr1);
	int len2 = strlen(arr2);
	if (len1 != len2)
	{
		return 0;
	}
	char* arr = (char*)calloc(len1 * 2+1, sizeof(char));
	if (arr == NULL)
	{
		printf("������%s",errno);

	}
	strcpy(arr+len1, arr1);
	if(check_cahr_num(arr, arr2, len1)==1)
	{
		return 1;
	}
	while (len2--)
	{
		arr[len2] = arr[len2 + len1];
		if (check_cahr_num(arr+len2, arr2, len1) == 1)
		{
			return 1;
		}
	}
	{
		free(arr);//�ͷ�arr������
		arr = NULL;

	}
	return 0;
}

int main()
{
	int n = 100;

	char* a1 = (char*)calloc(n,sizeof(char));
	char* a2 = (char*)calloc(n,sizeof(char));
	if (a1==NULL || a2==NULL)
	{
		perror("�����ڴ����");
		return 1;
	}
	printf("������ԭ�ַ�����");
	scanf("%s", a1);
	printf("��������ܱ������ַ�����");
	scanf("%s", a2);//���벿��
	if (judge(a1, a2))
	{
		printf("��������ϵ");
	}
	else
	{
		printf("����������ϵ");
	}

	free(a1);
	free(a2);
	a1 = NULL;
	a2 = NULL;
	return 0;
}
// �Ż���
//ֱ���������飬Ȼ�������в���
int findRound(const char* src, char* find)
{
	char tmp[256] = { 0 }; //��һ�������ռ佫ԭ�ַ�����������ԭ�ַ���
	strcpy(tmp, src); //�ȿ���һ��
	strcat(tmp, src); //������һ��
	return strstr(tmp, find) != NULL; //�����Ҳ��ҵõ�
}