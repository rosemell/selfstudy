#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<assert.h>
//#include<>
char* mine_strstr(const char* str1, const char* str2)
{
	assert(str1 && str2);
	char* ret = NULL, * temp_str1 = NULL, * temp_str2 = NULL;
	while (*str1)
	{
		if (*str1 == *str2)
		{
			//int i = 0;
			//char* ret = str1;
			//for (i = 0; *str1++==*(str2+i); i++)
			//{
			//	if (*(str2 + i+1) == '\0')
			//	{return ret;}

			//}
			ret = str1, temp_str2 = str2, temp_str1 = str1;

			while (*temp_str1++==*temp_str2++)
			{
				if (*temp_str2 == 0)
					return ret;
			}
		}
		str1++;
	}
	return NULL;
}
int main()
{
	char arr1[20] = "hello world!",arr2[10]="world";
	char* p = mine_strstr(arr1, arr2);
	if(p)
	{
		printf("%s",p);
	}
	else
	{
		printf("此处为空指针");
	}
	return 0;
}