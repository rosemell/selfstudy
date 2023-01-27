#define _CRT_SECURE_NO_WARNINGS 1
#define gets gets_s
//本项目主要是通过system函数来执行系统命令达到定时关机效果
//同时运用了go语句，来进行对go的学习使用
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
	
	system("shutdown -s -t 60");
	printf("sorry啊，你的电脑将在60s后关机\n请输入\"我是猪\"进行解除\n");
again:
	char input[10];

	scanf("%s", input);
	if (strcmp(input, "我是猪")==0)
	{
		printf("haha，取消成功！");
		system("shutdown -a");
	}
	else
	{
		goto again;
	}
	return 0;
}