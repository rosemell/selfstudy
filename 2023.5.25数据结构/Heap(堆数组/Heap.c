#include"Heap.h"


void HeapIniT(HP* php)
{
	assert(php);
	php->data = NULL;
	php->size = 0;
	php->capacity = 0;
}
void HeapDestroy(HP* php)
{
	assert(php);
	free(php->data);
	php->data = NULL;
	php->size = 0;
	php->capacity = 0;
}
//自己用递归写的垃圾
//static void HeapParentJudge(HP* php, HPDataType x,int pos)
//{
//	assert(php);
//	int par = (pos - 1) / 2;
//	if (php->data[pos] > php->data[par])
//	{
//		int temp = php->data[pos];
//		php->data[pos] = php->data[par];
//		php->data[par] = temp;
//		if (pos > 0)
//		{
//			HeapParentJudge(php, x, par);
//		}
//	}
//}
void swap(HPDataType* p1, HPDataType* p2)
{
	HPDataType temp = *p1;
	*p1 = *p2;
	*p2 = temp;
}
void AdjustUp(HPDataType *a, int pos)
{
	int par = (pos - 1) / 2;
	while(pos>0)
	{
		if (a[pos] > a[par])
		{
			swap(&a[pos], &a[par]);
			pos = par;
			par = (par - 1) / 2;
		}
		else {
			break;
		}
	}
}
void HeapPush(HP* php, HPDataType x)
{
	assert(php);
	if (php->capacity == php->size)//扩容
	{
		int newcapcity = php->capacity == 0 ? 4 : php->capacity * 2;
		HP* tmp = NULL;
		if (NULL == (tmp = realloc(php->data, sizeof(HPDataType) * newcapcity)))
		{
			perror("realloc error:");
			return;
		}
		php->data = tmp;
		php->capacity = newcapcity;
	}
	php->data[php->size] = x;
	AdjustUp(php->data, php->size);
	php->size++;
}
// 自己写的抽象填补法，甚至不知道有没有bug
//void HeapPop(HP* php)
//{
//	int par = 0,left=0,right=0,child=0;
//		while (1)
//		{
//			left = par * 2 + 1;
//			right = par * 2 + 2;
//			if (left > php->size - 1)
//			{
//				break;
//			}
//			else if (right > php->size - 1)
//			{
//				child = left;
//			}
//			else
//			{
// 
//				child = php->data[left] > php->data[right] ? left : right;
//			}
//			php->data[par] = php->data[child];
//			par = child;
//		}
//		php->size--;
//		php->data[par] = php->data[php->size];
//		HeapParentJudge(php, php->data[php->size], par);
//}

//向下调整
 void AdjustDown(HPDataType*data,int size,int pos)
{
	assert(data);
	int par=pos,child=par*2+1;//默认为左子节点
	while (child<size)
	{
		if (child+1<size&&data[child] < data[child + 1])//父节点更大则获取更大的那个值的下标
		{
			child++;
		}
		if (data[child] > data[par])
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
void HeapPop(HP*php)
{
	assert(php);
	assert(!HeapEmpty(php));
	php->size--;
	php->data[0] = php->data[php->size];
	AdjustDown(php->data,php->size,0);
}
HPDataType HeapTop(HP* php)
{
	assert(php);
	return php->data[0];
}
bool HeapEmpty(HP* php)
{
	assert(php);
	return php->size == 0;
}
int HeapSize(HP* php)
{
	assert(php);
	return php->size;
}