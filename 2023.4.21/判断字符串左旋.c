#define _CRT_SECURE_NO_WARNINGS 1
//目标：判断一个字符串是否为另一个字符串左旋的结果
#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<string.h>
#include<assert.h>
int check_cahr_num(char* arr1, char* arr2, int num)//用于判断一个字符串前num个字符是否相等
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
int judge(const char* arr1,const char* arr2)//判断函数
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
		printf("大问题%s",errno);

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
		free(arr);//释放arr！！！
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
		perror("开辟内存错误：");
		return 1;
	}
	printf("请输入原字符串：");
	scanf("%s", a1);
	printf("请输入可能被左旋字符串：");
	scanf("%s", a2);//输入部分
	if (judge(a1, a2))
	{
		printf("是左旋关系");
	}
	else
	{
		printf("不是左旋关系");
	}

	free(a1);
	free(a2);
	a1 = NULL;
	a2 = NULL;
	return 0;
}
// 优化后：
//直接生成数组，然后在其中查找
int findRound(const char* src, char* find)
{
	char tmp[256] = { 0 }; //用一个辅助空间将原字符串做成两倍原字符串
	strcpy(tmp, src); //先拷贝一遍
	strcat(tmp, src); //再连接一遍
	return strstr(tmp, find) != NULL; //看看找不找得到
}