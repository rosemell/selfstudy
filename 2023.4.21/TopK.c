#define _CRT_SECURE_NO_WARNINGS 1
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdbool.h>
#include<assert.h>
#include<stdlib.h>
#include<stdio.h>
#include<time.h>

void CreateNDate();


void swap(int* p1, int* p2)
{
	int temp = *p1;
	*p1 = *p2;
	*p2 = temp;
}
//向上调整
void AdjustUp(int* data, int pos, bool compar(void*, void*))
{
	int child = pos, par = (child - 1) / 2;
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
void AdjustDown(int* data, int size, int pos, int compar(void*, void*))
{
	int par = pos;
	int child = par * 2 + 1;
	while (child < size)
	{
		if (child + 1 < size && (compar(&data[child + 1], &data[child]) > 0))//判断是否应该调整右孩子
		{
			child++;
		}
		if (compar(&data[child], &data[par]) > 0)
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
int compar(void* p1, void* p2)
{
	return -(*(int*)p1 - *(int*)p2);
}
void PrintTopK(int k)
{

	int* a =(int*) malloc(sizeof(int) * k);
	if (NULL == a)
	{
		perror("malloc error\n");
		return;
	}
	const char* file = "data.txt";
	FILE* fin = fopen(file, "r");
	if (fin == NULL)
	{
		perror("fopen error");
		return;
	}
	int i = 0;
	for (i = 0; i < k&& fscanf(fin, "%d", &a[i]); i++)//先把A填满
	{
		;
	}
	if (i != k)//稍微做下文件内容量的判断
	{
		printf("文件不够大");
	}
	for (i = (k - 2) / 2; i >=0;i--)//先建堆
	{
		AdjustDown(a, k, i, compar);
	}
	int temp ;
	while(fscanf(fin,"%d", &temp)!=EOF)
	{
		if (-compar(&temp, &a[0]) > 0)
		{
			a[0] = temp;
			AdjustDown(a, k, 0, compar);
		}
	}
	for (i = 0; i < k; i++)
	{
		printf("%d ", a[i]);
	}
	fclose(fin);
	free(a);
}
int main()
{
	CreateNDate();
	PrintTopK(10);
	return 0;
}
void CreateNDate()
{
	// 造数据
	int n = 10000;
	srand(time(0));
	const char* file = "data.txt";
	FILE* fin = fopen(file, "w");
	if (fin == NULL)
	{
		perror("fopen error");
		return;
	}
	for (size_t i = 0; i < n; ++i)
	{
		int x = rand() % 1000;
		fprintf(fin, "%d\n", x);
	}
	fclose(fin);
}

