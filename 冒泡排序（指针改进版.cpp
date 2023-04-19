#define _CRT_SECURE_NO_WARNINGS 1



#include<stdlib.h>
#include<time.h>
#include<stdio.h>
void print(int* p, int size)
{
	int i = 0;
	for (i = 0; i < 10; i++)
	{
		printf("%d\n", p[i]);
	}
}
void bubble_sort(int arr[], int len) {
	int i, j, temp;
	for (i = 0; i < len - 1; i++)
		for (j = 0; j < len - 1 - i; j++)
			if (arr[j] > arr[j + 1]) {
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
}
int main()
{
	int arr[10] = { 3,2,4,1,5,9,10,6,8,7 };
	int sz = sizeof(arr) / sizeof(arr[0]);//¥˝≤‚ ‘£¨≤ªΩË”√sz
	int i = 0;

	for (i = 0; i < 10; i++)
	{
		arr[i] = rand();
	}
	printf("≈≈–Ú«∞£∫");
	print(arr, sz);
	int j = 0, temp = 0;
	for(i=0;i<sz-1;i++)
	{
		for (j = 0; j < sz-1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
	//bubble_sort(arr, sz);




	printf("≈≈–Ú∫Û£∫");
	print(arr, sz);



	return 0;
}