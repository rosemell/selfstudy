#define _CRT_SECURE_NO_WARNINGS 1
#include"SeqList.h"

static void Seqcheck(SeqList*ps)
{
	assert(ps&&ps->a);
	if (ps->capacity == ps->size)
	{
		//SeqList* temp = realloc(ps, ps->capacity * 2 * sizeof(SLDataType));
		SeqList* temp = realloc(ps->a, ps->capacity * 2 * sizeof(SLDataType));
		if (NULL == temp)
		{
			return;
		}
		ps->a = temp;
		ps->capacity *= 2;
	}
	
	
}
void SeqListInit(SeqList*ps)
{
	assert(ps->a != NULL);
	if (NULL==(ps->a = malloc(INITSL*sizeof(SeqList))))
	{
		printf("内存开辟失败：%s", errno);
		return;
	}
	ps->size= 0;
	ps->capacity = INITSL;
}
void SeqListDestroy(SeqList* ps)
{
	free(ps->a);
	ps->a = NULL;
	ps->capacity = 0;
	ps->size = 0;
}
void SeqListPrint(SeqList* ps)
{
	int i = 0;
	for (i = 0; i < ps->size; i++)
	{
		printf("%d ", ps->a[i]);
	}
	printf("\n");
}
void SeqListPushBack(SeqList* ps,SLDataType x)
{
	assert(ps&&ps->a);
	Seqcheck(ps);
	ps->a[ps->size] = x;
	ps->size++;
	
}
void SeqListPopBack(SeqList* ps)
{
	assert(ps);
	assert(ps->size);//size不能为0
	ps->size--;

}
void SeqListPopFront(SeqList* ps)
{
	assert(ps);
	assert(ps->size);
	int i = 0;
	ps->size--;
	for (i=0;i<ps->size;i++)
	{
		ps->a[i] = ps ->a[i + 1];
	}
}
int SeqListFind(SeqList* ps, SLDataType x)
{
	int i = 0;
	for (  i = 0; i < ps->size; i++)
	{
		if (ps->a[i] == x)
		{
			return i;
		}
	}
	return -1;
}
void SeqListInsert(SeqList* ps, int pos, SLDataType x)
{
	Seqcheck(ps);
	int i = 0;
	for (i = ps->size; i > pos; i--)
	{
		ps->a[i] = ps-> a[i - 1];
	}
	ps->size++;
	ps->a[pos] = x;
}
void SeqListErase(SeqList* ps, int pos)
{
	int i = 0;
	ps->size--;
	for (i = pos; i < ps->size; i++)
	{
		ps->a[i] = ps->a[i + 1];
	}
}