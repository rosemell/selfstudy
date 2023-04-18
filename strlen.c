#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<assert.h>
int mine_strlen(const char* arr)
{
	assert(arr);
	int count = 0;
	/*while (*arr++)
	{
		count++;
	}*/
	for (count = 0; *arr++; count++)
	{
		;
	}
	return count;
}
int main()
{
	char arr[] = "hllo world";
	printf("%d", mine_strlen(arr));
	return 0;
}