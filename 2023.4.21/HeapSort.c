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
//向上调整
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
//向下调整
void AdjustDown(int* data, int size,int pos,int compar(void*,void*))
{
	int par = pos;
	int child = par * 2 + 1;
	while (child < size)
	{
		if (child + 1 < size && (compar(&data[child + 1], &data[child]) > 0))//判断我们是不是应该调整右孩子
		//if (child + 1 < size && data[child+1]>data[child])//判断我们是不是应该调整右孩子
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
void HeapSort(int* a, int size)//用速度较快的向下调整
{
	int i = 0;
	//i=size-1-1,先找到最后一个叶节点的父节点
	for (i = (size - 2) / 2; i >= 0;i--)//先建堆
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
	printf("排序前：\n");
	print(a, n);
	HeapSort(a, n);
	printf("排序后：\n");
	print(a, n);

	free(a);
}