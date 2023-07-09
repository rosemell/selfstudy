#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
typedef struct L
{
	int num;
	struct L *next;
}L;
L* Buy(int n)
{
	L* tmp = (L*)malloc(sizeof(L));
	if (NULL == tmp)
	{
		perror("malloc fail");
		return NULL;
	}
	tmp->num = n;
	tmp->next = NULL;
	return tmp;
}
L* Init(int m)
{
	int i = 0;
	L* phead = NULL, *cur = NULL;
	for (i = 1; i <= m; i++)
	{
		if (NULL == phead)
		{
			phead = Buy(i);
			cur = phead;
		}
		else
		{
			cur->next = Buy(i);
			cur = cur->next;
		}
	}
	cur->next = phead;
	return phead;
}
int Destroy(int n, L* phead)
{
	assert(NULL != phead);
	L* cur = phead;
	while(cur->next!=cur)
	{
		int i = n - 1;
		L* prev = NULL;
		while (i--)
		{
			if (NULL == prev)
			{
				prev = cur;
			}
			else 
			{
				prev = cur;
			}
			cur = cur->next;
		}
		prev->next = cur->next;
		free(cur);
		cur = prev->next;
	}
	int tmp = cur->num;
	free(cur);
	return tmp;
}
int main()
{
	int m = 0, n = 0;
	scanf("%d%d", &m, &n);
	int num=Destroy(n, Init(m));
	printf("%d", num);
	return 0;
}