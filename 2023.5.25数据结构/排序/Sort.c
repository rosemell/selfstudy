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
		if (maxi == left)//���mini��left�غϾ�����һ��
		{
			maxi = mini;
		}
		swap(&a[maxi], &a[right]);

	}
}


void AdjustDwon(int* a, int size, int pos)
{
	int par = pos;
	int child = par *2 + 1;//����Ҫ��������
	while (child < size)
	{
		if (child + 1 < size && a[child + 1] > a[child])//����Һ��Ӹ���Ͱ��Һ��ӻ��������γɴ��
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
	for (i = (size - 2)/2; i >= 0;i--)//����
	{
		AdjustDwon(a, size, i);
	}
	int end = size - 1;//���԰�end����i������
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
//����
//����д����˫ָ�룬����д������ͷָ�룩���ڿӷ�
//�Ż�1�����key������ѡ����key
//�Ż�2��С�����Ż�
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


//�ǵݹ�ʵ��
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
		//����ȡ��
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

//��·����
void QuickSort(int* a, int left, int right)
{
	if (left >= right)
		return;
	int begin = left, end = right;
	//���key
	//randi = left + (rand() % (right - left));
	//swap(&a[randi], &a[left]);
	//����ȡ��
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
//ǰ��ָ�뷨
void QuickSort3(int* a, int left, int right)
{
	if (left >= right)
		return;
	int begin = left, end = right;
	//���key
	//randi = left + (rand() % (right - left));
	//swap(&a[randi], &a[left]);
	//����ȡ��
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

void QuickSort1(int* a, int left, int right)//δС�����Ż�
{
	if (left >= right)
		return;
	int begin = left, end = right;

	//���key
	//randi = left + (rand() % (right - left));
	//swap(&a[randi], &a[left]);

	//����ȡ��
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
////�ڿӷ�
//void QuickSort(int* a, int left, int right)
//{
//	if (left >= right)
//		return;
//	int begin = left, end = right;
//	//���key
//	//randi = left + (rand() % (right - left));
//	//swap(&a[randi], &a[left]);
//
//	//����ȡ��
//	int mid = GetMid(a, left, right);
//	if (mid != left)
//		swap(&a[left], &a[mid]);
//	int key = a[left];
//
//	int hole = left;//Ϊ�˿ɶ������ӵı���
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
//	//�޶��������
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



//Hoare��ԭʼ�����Ż���
//void QuickSort(int* a, int left, int right)
//{
//	if (left >= right)
//		return;
//	int beginleft = left, beginright = right;
//	int keyi = left;
//
//	//���key
//	//keyi = left + (rand() % (right - left));
//	//swap(&a[keyi], &a[left]);
//	//keyi = left;
//
//	//����ȡ��
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
//	//���������ж�
//	/*if (left - beginleft > 1)
//		QuickSort(a, beginleft,left-1);
//	if(beginright - left > 1)
//		QuickSort(a,left+1, beginright);*/
//}
void _MergeSort(int* a, int begin,int end,int*temp )
{
	if (begin >= end)//��СΪ1���С
		return;

	int mid = (begin + end) / 2;
	_MergeSort(a,begin, mid,temp);
	_MergeSort(a,mid+1,end,temp);
	int begin1 = begin,end1=mid;
	int begin2 = mid + 1, end2 =end;
	int i = 0;//������Щ�ط���i=begin\
	������Ϊtempֻ�Ǹ���ʱ����û\
	��Ҫ�γ�������ԭ�����Ӧ�Ĺ�ϵ��\
	����ֱ�ӳ�ʼΪ0
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
	memcpy(a+begin, temp, sizeof(int) * i);//����ǵڶ�������ϲ�ʣ����ôʣ�µ��Ѿ�����ֱ�Ӱ�ǰi����ֵ����
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
//ÿ�ι鲢����һ��
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
			//Խ��
			//�����Խ��������һ�𿽱��ļ�
			if (begin2 >= size || end1 >= size)//��ʵ�����ж�û��\
								��end1Խ�磬begin2�ض�Խ�磬���Ժ��η����˷�ʱ�䣩\
									���ɶ�������
			{
				break;
			}
			else if (end2 >= size)
			{
				end2 = size - 1;
			}
			//�鲢
			int j = 0;
			while (begin1 <= end1&&begin2<=end2)
			{
				if (a[begin1] <= a[begin2])//�жϲ��ֵĵȺſ����ù鲢�������ȶ�����������Ҳȷʵ����
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
			//��Ϊ����һ�𿽱������Եڶ��ξͲ��ù���
			memcpy(a+i, temp+i,sizeof(int)* j);//����Եģ�ָ��Ҫ��һ��
		}
	}
	free(temp);
}
//ÿ�鲢��һ�����жο���һ��
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
//	//�鲢
//	for(gap=1;gap<size;gap*=2)
//	{
//		//printf("\n");//������
//		for (i = 0; i < size; i +=2* gap)
//		{
//			int begin1 = i, end1 = i + gap-1;
//			int begin2 = end1 + 1, end2 = i + 2 * gap-1;
//			//Խ���ж�
//			if (end1 >= size)
//			{
//				end1 = size - 1;
//				end2 = size - 1;
//				begin2 = size;//��Ϊ������һ��һ�𿽱������Բ���break���о�������go���
//			}
//			else if (begin2 >= size)
//			{
//				begin2 = size;
//				end2 = size - 1;//��֮���õڶ��δ��ھ���
//			}
//			else if (end2 >= size)
//			{
//				end2 = size - 1;//�������һ������
//			}
//			//printf("[%d,%d][%d,%d] ", begin1, end1, begin2, end2);//������
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
//			while (begin2 <= end2)//��Ϊһ���ӡ����2��Ҳ��Ҫ����
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
	for (i = 0; i < size; i++)//�ҳ������е���С�����ֵ
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
	int gap = max - min + 1;//���ӳ��ռ��С
	int* CountA = (int*)calloc(gap , sizeof(int));//clloc����
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