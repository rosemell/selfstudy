#define _CRT_SECURE_NO_WARNINGS 1
#include<stdbool.h>
#include<assert.h>
#include<stdlib.h>
#include<stdio.h>
#include<time.h>


void Rand(int* a, int n);
void test(int n);
void print(int* a, int n);
int compar(void* p1, void* p2);


void swap(int* p1, int* p2)
{
	int temp = *p1;
	*p1 = *p2;
	*p2 = temp;
}
//���ϵ���
void AdjustUp(int* data, int pos, bool compar(void*, void*))
{
	int child = pos,par=(child-1)/2;
	while (child > 0)
	{
		if (compar(&data[par], &data[child]))
		{
			swap(&data[par], &data[child]);
			child = par;
			par = (child - 1) / 2;
		}
		else 
		{
			return;
		}
	}
}
//���µ���
void AdjustDown(int* data, int size,int pos,int compar(void*,void*))
{
	int par = pos;
	int child = par * 2 + 1;
	while (child < size)
	{
		if (child + 1 < size && (compar(&data[child + 1], &data[child]) > 0))//�ж������ǲ���Ӧ�õ����Һ���
		//if (child + 1 < size && data[child+1]>data[child])//�ж������ǲ���Ӧ�õ����Һ���
		{
			child++;
		}
		//if (compar(&data[child], &data[par]) > 0)
			if (data[child]>data[par])
		{
			swap(&data[child], &data[par]);
		}
		else
		{
			break;
		}
		par = child;
		child = par * 2 + 1;
	}
}
void HeapSort(int* a, int size)//���ٶȽϿ�����µ���
{
	int i = 0;
	//i=size-1-1,���ҵ����һ��Ҷ�ڵ�ĸ��ڵ�
	for (i = (size - 2) / 2; i >= 0;i--)//�Ƚ���
	{
		AdjustDown(a, size,i,compar);
	}
	for(i=size-1;i>0;i--)
	{
		swap(&a[i], &a[0]);
		AdjustDown(a,i, 0, compar);
	}
}
int main()
{
	int i = 1, j = 0;
	printf("%d", compar(&i, &j));
	test(1000);
	return 0;
}

int compar(void* p1, void* p2)
{
	return *(int*)p1 - *(int*)p2;
}
void print(int* a, int n)
{
	int i = 0;
	for (i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}
void Rand(int* a, int n)
{
	srand(time(NULL));
	int i = 0;
	for (i = 0; i < n; i++)
	{
		a[i] = rand() % 1000;
		//a[i] = rand();
	}
}
void test(int n)
{
	int* a = malloc(sizeof(int) * n);
	if (a == NULL)
	{
		perror("mlloc error");
		return;
	}
	Rand(a, n);
	printf("����ǰ��\n");
	print(a, n);
	HeapSort(a, n);
	printf("�����\n");
	print(a, n);

	free(a);
}