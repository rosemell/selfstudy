#include"Sort.h"

#define FLAG 0
void Judge(int *a,int size)
{
	int i = 0;
	for (i = 1; i < size; i++)
	{
		if (a[i-1]>a[i])
		{
			printf("NO!%d\n",i);
			return;
		}
	}
	printf("YES!\n");
	return;
}
// 测试排序的性能对比
void TestOP()
{
	int N = 1000000;
	if (FLAG == 0)
	{
		srand(time(0));
	}
	else
	{
		srand(1);
		N = 10;
	}
	int* a1 = (int*)malloc(sizeof(int) * N);
	int* a2 = (int*)malloc(sizeof(int) * N);
	int* a3 = (int*)malloc(sizeof(int) * N);
	int* a4 = (int*)malloc(sizeof(int) * N);
	int* a5 = (int*)malloc(sizeof(int) * N);
	int* a6 = (int*)malloc(sizeof(int) * N);
	int* a7 = (int*)malloc(sizeof(int) * N);
	for (int i = 0; i < N; ++i)
	{
		a1[i] = rand();
		a2[i] = a1[i];
		a3[i] = a1[i];
		a4[i] = a1[i];
		a5[i] = a1[i];
		a6[i] = a1[i];
		a7[i] = a1[i];
	}
	int begin1 = clock();

	//InsertSort(a1, N);
	//Judge(a1, N);

	int end1 = clock();
	int begin2 = clock();

	//ShellSort(a2, N);
	//Judge(a2, N);

	int end2 = clock();
	int begin3 = clock();
	

	//SelectSort(a3, N);
	//Judge(a3, N);

	//BubbleSort(a3, N);//借用选排测下冒泡
	//Judge(a3, N);

	int end3 = clock();
	int begin4 = clock();
	HeapSort(a4, N);
	int end4 = clock();
	//Judge(a4, N);

	

	int begin5 = clock();
	QuickSort(a5, 0, N - 1);
	int end5 = clock();
	Judge(a5, N);

	int begin7 = clock();
	CountSort(a7, N );
	int end7 = clock();
	Judge(a7, N);


	int begin6 = clock();
	MergeSortNonR(a6, N);
	int end6 = clock();
	Judge(a6, N);

	printf("InsertSort:%d\n", end1 - begin1);
	printf("ShellSort:%d\n", end2 - begin2);
	printf("SelectSort:%d\n", end3 - begin3);
	printf("HeapSort:%d\n", end4 - begin4);
	printf("QuickSort:%d\n", end5 - begin5);
	printf("CountSort:%d\n", end7 - begin7);
	printf("MergeSort:%d\n", end6 - begin6);
	free(a1);
	free(a2);
	free(a3);
	free(a4);
	free(a5);
	free(a6);
}

int main()
{
	TestOP();

	return 0;
}
