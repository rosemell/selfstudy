#define _CRT_SECURE_NO_WARNINGS 1
#define gets gets_s
#include<Windows.h>
#include<stdio.h>
#include<string.h>
int main()
{
	char a[100] = "wangdoaic";
	//gets(a);
	char a1[100] = {};
	for (int i = 0; i <= strlen(a)-1; i++)
	{
		a1[i] = '*';
	}
	//puts(a1);
	//printf("1");
	//int right=strlen(a)-1, left = 0;
	for (int right = strlen(a) - 1, left = 0;
		right >= left; right--, left++)
	{
		a1[right] = a[right];
		a1[left] = a[left];
		puts(a1);
		Sleep(500);
		system("cls");
	}
	puts(a1);
	
	return 0;
}