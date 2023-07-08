#include"Sort.h"
void InsertSort(int* a, int size)
{
	int end = 0, i = 0, temp = 0;
	for (i = 1; i < size; i++)
	{
		temp = a[i];
		end = i - 1;
		while (end >= 0)
		{
			if (a[end] < temp)
			{
				break;
			}
			a[end + 1] = a[end];
			end--;
		}
		a[end + 1] = temp;
	}
}
void ShellSort(int* a, int size)
{
	int gap=0;
	int end = 0, i = 0, temp = 0;
	for(gap=size;gap>1;)
	{
		//gap = gap / 3 + 1;
		gap/=2;
		for (i = gap; i < size; i++)
		{
			temp = a[i]; 
			end = i - gap;
			while (end >= 0)
			{
				if (a[end] < temp)
				{
					break;
				}
				a[end + gap] = a[end];
				end-=gap;
			}
			a[end + gap] = temp;
		}
	}
}

void swap(int* p1, int* p2)
{
	int temp = *p1;
	*p1 = *p2;
	*p2 = temp;
}
void SelectSort(int* a, int size)
{
	int left = 0, right = size-1;
	int maxi = 0, mini = 0;
	int i = 0;
	for(left=0,right=size-1;left<right;left++,right--)
	{
		maxi = left, mini = left;
		for (i = left + 1; i <=right; i++)
		{
			if (a[maxi] < a[i])
			{
				maxi = i;
			}
			if (a[mini] > a[i])
			{
				mini = i;
			}
		}
		
		swap(&a[mini], &a[left]);
		if (maxi == left)//如果mini与left重合就修正一下
		{
			maxi = mini;
		}
		swap(&a[maxi], &a[right]);

	}
}


void AdjustDwon(int* a, int size, int pos)
{
	int par = pos;
	int child = par *2 + 1;//假设要交换左孩子
	while (child < size)
	{
		if (child + 1 < size && a[child + 1] > a[child])//如果右孩子更大就把右孩子换上来，形成大堆
		{
			child++;
		}
		if (a[child] > a[par])
		{
			swap(&a[child], &a[par]);
		}
		else
		{
			break;
		}
		par = child;
		child = par * 2 + 1;
	}
}
void HeapSort(int* a, int size)
{
	int i = 0;
	for (i = (size - 2)/2; i >= 0;i--)//建堆
	{
		AdjustDwon(a, size, i);
	}
	int end = size - 1;//可以把end换成i但我懒
	for (end=size-1;end>0;end--)
	{
		swap(&a[end], &a[0]);
		AdjustDwon(a, end, 0);
	}
}
void BubbleSort(int* a, int size)
{
	bool flag= 0;
	int i = 0, j = 0;
	for (i = size-1; i; i--)
	{
		for (j = 0; j < i; j++)
		{
			if (a[j] > a[j + 1])
			{
				swap(&a[j], &a[j + 1]);
				flag= 1;
			}
		}
		if (0 == flag)
		{
			break;
		}
		flag = 0;
	}
}
//快排
//三种写法：双指针，霍尔写法（两头指针），挖坑法
//优化1：随机key，三数选中作key
//优化2：小区间优化
static int GetMid(int* a, int left, int right)
{
	int mid= (left + right) / 2;
	if (a[left] < a[mid])
	{
		if (a[mid] < a[right])
		{
			return mid;
		}
		else if (a[right] < a[left])
		{
			return left;
		}
		else
		{
			return right;
		}
	}
	else//left>mid
	{
		if (a[left] < a[right])
		{
			return left;
		}
		else if (a[mid] < a[right])//left>mid&&left>right
		{
			return right;
		}
		else
		
		{
			return mid;
		}
	}
}


//非递归实现
void QuickSortNonR(int* a, int left, int right)
{
	ST st;
	STInit(&st);
	STPush(&st, left);
	STPush(&st, right);
	while (!STEmpty(&st))
	{
		right = Top(&st);
		STPop(&st);
		left = Top(&st);
		STPop(&st);
		if (left >= right)
			continue;
		if ((right-left+1)< 13)
		{
			InsertSort(a+left, right-left + 1);
			continue;
		}
		int begin = left, end = right;
		//三数取中
		int mid = GetMid(a, left, right);
		if (mid != left)
			swap(&a[left], &a[mid]);
		int keyi = left;
		int prev = left, cur = prev + 1;
		while (cur <= right)
		{
			if (a[cur] < a[keyi] && ++prev != cur)
			{
				swap(&a[prev], &a[cur]);
			}
			cur++;
		}
		swap(&a[keyi], &a[prev]);
		STPush(&st, prev + 1);
		STPush(&st, end);
		STPush(&st, begin);	
		STPush(&st, prev- 1);
	}
	STDestroy(&st);
}

//三路划分
void QuickSort(int* a, int left, int right)
{
	if (left >= right)
		return;
	int begin = left, end = right;
	//随机key
	//randi = left + (rand() % (right - left));
	//swap(&a[randi], &a[left]);
	//三数取中
	int mid = GetMid(a, left, right);
	if (mid != left)
		swap(&a[left], &a[mid]);

	int key = a[left];
	int cur = left+1;
	while (cur <= right)
	{
		if (a[cur] == key)
		{
			cur++;
		}
		else if (a[cur] < key)
		{
			swap(&a[cur++], &a[left++]);
		}
		else if (a[cur] > key)
		{
			swap(&a[cur], &a[right--]);
		}
	}
	if ((end-begin+ 1) > 13)
	{
		QuickSort(a, begin, left-1);
		QuickSort(a, right+1, end);
	}
	else
	{
		InsertSort(a + left, right - left + 1);
	}
}
//前后指针法
void QuickSort3(int* a, int left, int right)
{
	if (left >= right)
		return;
	int begin = left, end = right;
	//随机key
	//randi = left + (rand() % (right - left));
	//swap(&a[randi], &a[left]);
	//三数取中
	int mid = GetMid(a, left, right);
	if (mid != left)
		swap(&a[left], &a[mid]);
	int keyi = left;
	int prev = left, cur = prev + 1;
	while (cur <= right)
	{
		if (a[cur] < a[keyi] && ++prev != cur)
		{
			swap(&a[prev], &a[cur]);
		}
		cur++;
	}
	swap(&a[keyi], &a[prev]);
	if((right-left+1)>13)
	{
		QuickSort(a, begin, prev - 1);
		QuickSort(a, prev + 1, end);
	}
	else
	{
		InsertSort(a + left, right - left + 1);
	}
}

void QuickSort1(int* a, int left, int right)//未小区间优化
{
	if (left >= right)
		return;
	int begin = left, end = right;

	//随机key
	//randi = left + (rand() % (right - left));
	//swap(&a[randi], &a[left]);

	//三数取中
	int mid = GetMid(a, left, right);
	if (mid != left)
		swap(&a[left], &a[mid]);
	int keyi = left;

	int prev = left, cur = prev + 1;
	while (cur <= right)
	{
		if (a[cur] < a[keyi] && ++prev != cur)
		{
			swap(&a[prev], &a[cur]);
		}
		cur++;
	}
	swap(&a[keyi], &a[prev]);
	QuickSort1(a, begin, prev - 1);
	QuickSort1(a, prev + 1, end);
}
//
////挖坑法
//void QuickSort(int* a, int left, int right)
//{
//	if (left >= right)
//		return;
//	int begin = left, end = right;
//	//随机key
//	//randi = left + (rand() % (right - left));
//	//swap(&a[randi], &a[left]);
//
//	//三数取中
//	int mid = GetMid(a, left, right);
//	if (mid != left)
//		swap(&a[left], &a[mid]);
//	int key = a[left];
//
//	int hole = left;//为了可读性增加的变量
//	while (left < right)
//	{
//		while (left < right && a[right] >= key)
//			right--;
//
//		a[hole] = a[right];
//		hole = right;
//
//		while (left < right && a[left] <= key)
//			left++;
//
//		a[hole] = a[left];
//		hole = left;
//	}
//	//无多余变量版
//	//while (left < right)
//	//{
//	//	while (left < right && a[right] >= key)
//	//		right--;
//	//	a[left] = a[right];
//	//	while (left < right && a[left] <= key)
//	//		left++;
//	//	a[right] = a[left];
//	//}
//	a[left] = key;
//
//	QuickSort(a, begin, left - 1);
//	QuickSort(a, left + 1, end);
//}



//Hoare的原始方法优化版
//void QuickSort(int* a, int left, int right)
//{
//	if (left >= right)
//		return;
//	int beginleft = left, beginright = right;
//	int keyi = left;
//
//	//随机key
//	//keyi = left + (rand() % (right - left));
//	//swap(&a[keyi], &a[left]);
//	//keyi = left;
//
//	//三数取中
//	int mid = GetMid(a, left, right);
//	if(mid!=left)
//		swap(&a[left], &a[mid]);
//
//	while(left < right)
//	{
//		while (left < right && a[keyi] <= a[right])
//			right--;
//		while (left < right && a[keyi] >= a[left])
//			left++;
//		swap(&a[left], &a[right]);
//	}
//	swap(&a[left], &a[keyi]);
//	
//	QuickSort(a, beginleft, left - 1);
//	QuickSort(a, left + 1, beginright);
//	//最初构想的判断
//	/*if (left - beginleft > 1)
//		QuickSort(a, beginleft,left-1);
//	if(beginright - left > 1)
//		QuickSort(a,left+1, beginright);*/
//}
void _MergeSort(int* a, int begin,int end,int*temp )
{
	if (begin >= end)//大小为1或更小
		return;

	int mid = (begin + end) / 2;
	_MergeSort(a,begin, mid,temp);
	_MergeSort(a,mid+1,end,temp);
	int begin1 = begin,end1=mid;
	int begin2 = mid + 1, end2 =end;
	int i = 0;//这里有些地方是i=begin\
	但我认为temp只是个临时数组没\
	必要形成那种与原数组对应的关系，\
	所以直接初始为0
	while (begin1 <= end1 && begin2 <= end2)
	{
		if (a[begin1] < a[begin2])
		{
			temp[i++] = a[begin1++];
		}
		else
		{
			temp[i++] = a[begin2++];
		}
	}
	while (begin1 <= end1)
	{
		temp[i++] = a[begin1++];
	}
	/*while (begin2<= end2)
	{
		temp[i++] = a[begin2++];
	}
	memcpy(a+begin, temp, sizeof(int) * (end-begin+1));*/
	memcpy(a+begin, temp, sizeof(int) * i);//如果是第二个数组合并剩余那么剩下的已经有序，直接把前i个赋值即可
}
void MergeSort(int* a, int n)
{
	int* temp = (int*)malloc(sizeof(int) * n);
	if (NULL == temp)
	{
		perror("malloc error\n");
		return;
	}
	_MergeSort(a, 0, n - 1, temp);
	free(temp);
}
//每段归并拷贝一次
void MergeSortNonR(int* a, int size)
{
	int* temp = (int*)malloc(sizeof(int) * size);
		if (NULL == temp)
		{
			perror("malloc error\n");
			return;
		}
	int gap = 1;
	for (gap = 1; gap < size; gap *= 2)
	{
		int i = 0;
		for (i = 0; i < size; i+=gap*2)
		{
			int begin1 = i, end1 = begin1 + gap - 1;
			int begin2 = end1 + 1, end2 = begin2 + gap - 1;
			//越界
			//这里的越界做法比一起拷贝的简单
			if (begin2 >= size || end1 >= size)//其实后半句判断没用\
								（end1越界，begin2必定越界，所以后半段反而浪费时间）\
									但可读性至上
			{
				break;
			}
			else if (end2 >= size)
			{
				end2 = size - 1;
			}
			//归并
			int j = 0;
			while (begin1 <= end1&&begin2<=end2)
			{
				if (a[begin1] <= a[begin2])//判断部分的等号可以让归并排序变得稳定，不过不加也确实能排
				{
					temp[j++] = a[begin1++];
				}
				else
				{
					temp[j++] = a[begin2++];
				}
			}
			while (begin1 <= end1)
			{
				temp[j++] = a[begin1++];
			}
			//因为不是一起拷贝，所以第二段就不用管了
			memcpy(a+i, temp+i,sizeof(int)* j);//但相对的，指针要改一下
		}
	}
	free(temp);
}
//每归并完一次所有段拷贝一次
//
//void MergeSortNonR(int* a, int size)
//{
//	int* temp = (int*)malloc(sizeof(int) * size);
//	if (NULL == temp)
//	{
//		perror("malloc error\n");
//		return;
//	}
//	int gap = 1;
//	int i = 0,j=0;
//	//归并
//	for(gap=1;gap<size;gap*=2)
//	{
//		//printf("\n");//调试用
//		for (i = 0; i < size; i +=2* gap)
//		{
//			int begin1 = i, end1 = i + gap-1;
//			int begin2 = end1 + 1, end2 = i + 2 * gap-1;
//			//越界判断
//			if (end1 >= size)
//			{
//				end1 = size - 1;
//				end2 = size - 1;
//				begin2 = size;//因为这里是一堆一起拷贝，所以不能break（感觉可以用go语句
//			}
//			else if (begin2 >= size)
//			{
//				begin2 = size;
//				end2 = size - 1;//总之别让第二段存在就行
//			}
//			else if (end2 >= size)
//			{
//				end2 = size - 1;//最正义的一次修正
//			}
//			//printf("[%d,%d][%d,%d] ", begin1, end1, begin2, end2);//调试用
//
//			while (begin1 <= end1 && begin2 <= end2)
//			{
//				if (a[begin1] <= a[begin2])
//				{
//					temp[j++] = a[begin1++];
//				}
//				else
//				{
//					temp[j++] = a[begin2++];
//				}
//			}
//			while (begin1 <= end1)
//			{
//				printf("temp[%d]=a[%d] ",j,begin1);
//				temp[j++] = a[begin1++];
//			}
//			while (begin2 <= end2)//因为一起打印所以2段也需要处理
//			{
//				printf("temp[%d]=a[%d] ", j, begin2);
//				temp[j++] = a[begin2++];
//			}
//			printf("gap=%d\n",gap);
//		}
//		memcpy(a, temp,sizeof(int)* j);
//		j = 0;
//	}
// free(temp);
//}

void CountSort(int* a, int size)
{
	int max = a[0], min = a[0];
	int i = 0;
	for (i = 0; i < size; i++)//找出数组中的最小和最大值
	{
		if (max < a[i])
		{
			max = a[i];
		}
		else if (min > a[i])
		{
			min = a[i];
		}
	}
	int gap = max - min + 1;//相对映射空间大小
	int* CountA = (int*)calloc(gap , sizeof(int));//clloc置零
	if (NULL == CountA)
	{
		perror("malloc fail\n");
		return;
	}
	for (i = 0; i < size; i++)
	{
		CountA[a[i] - min]++;
	}
	int k = 0;
	for (i = 0; i < gap; i++)
	{
		//int j = 0;
		//for (j = 0; j < CountA[i]; j++)
		//{
		//	a[k++] = i + min;
		//}
		while (CountA[i]--)
		{
			a[k++] = i + min;
		}
	}
	free(CountA);
}