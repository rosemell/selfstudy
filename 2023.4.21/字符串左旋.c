#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<assert.h>
void reverse_1(char* left,char *right)
{
	assert(left && right);
	char temp = 0;
	while(left<right)
	{
		temp =*left;
		*left = *right;
		*right = temp;
		right--; left++;
	}
}
size_t mine_strlen(char* arr)
{
	size_t count = 0;
	while (*arr++)
	{
		count++;
	}
	return count;
}
char* reverse(char* arr,int k)
{
	assert(arr);
	
	size_t len = mine_strlen(arr);
	if (len < 0)
		printf("�ַ�������");
	reverse_1(arr, arr + k-1);
	
	reverse_1(arr + k, arr + len - 1);//���󣬴��޸�
	reverse_1(arr, arr + len-1);
	return arr;
}
int main()
{
	char arr[20] = "hello world";
	int k=0;
	printf("��תǰ�ַ������ݣ�\n%s\n�������ַ�����Ҫ��ת������", arr);
	scanf("%d", &k);
	reverse(arr, k);
	printf("��ת���ַ�������Ϊ��\n%s", arr);

	return 0;
}