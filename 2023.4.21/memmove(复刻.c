#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<assert.h>
#include<string.h>
void* memmove(void* arr1,void* arr2,size_t num)
{
	assert(arr1 && arr2);
	void * ret = arr1;
	if(arr1<arr2)
	{
		while (*((char*)arr1)++ = *((char*)arr2)++)
		{
			;
		}
	}
	else {
		while(num--)
		{
			*(((char*)arr1) + num) = *(((char*)arr2) + num);
		}
	}
	return ret;
}
int main()
{
	char a1[100] = "Hello world!";
	char a2[100] = "You too!";
	int sz = strlen(a1);
	printf(memmove(a1+4, a1,sz));

	return 0;
}