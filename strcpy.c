#define _CRT_SECURE_NO_WARNINGS 1
#include<assert.h>
#include<stdio.h>
char* mine_strcpy(char* strDestination, const char* strSource)
{
	char *str=strDestination;
	assert(strSource&&strDestination);
	while (*strDestination++ = *strSource++);
	return str;
}
int main()
{
	char arr1[20] = "hellow world",arr2[20]="hello";
	printf("%s", mine_strcpy(arr2, arr1));
	
	return 0;
}