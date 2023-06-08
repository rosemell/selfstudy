#include"Queue.h"


void QueueInit(Queue* pq)
{
	pq->phead = NULL;
	pq->ptail = NULL;
	pq->size = 0;
}
void QueueDestroy(Queue* pq)
{
	assert(pq);
	QNode* next;
	while (pq->phead)
	{
		next = pq->phead->next;
		free(pq->phead);
		pq->phead = next;
	}
	pq->ptail = NULL;
	pq->size = 0;
	printf("内存销毁成功！\n");
}
void QueuePush(Queue* pq, QDataType x)
{
	assert(pq);
	QNode* newnode = (QNode*)malloc(sizeof(QNode));
	if (NULL == newnode)
	{
		perror("malloc error:\n");
		return;
	}
	newnode->data = x;
	newnode->next = NULL;
	if (NULL == pq->ptail)
	{
		assert(NULL==pq->phead);
		pq->phead = newnode;
		pq->ptail = newnode;
	}
	else {
		pq->ptail->next = newnode;
		pq->ptail= newnode;
	}
	pq->size++;
}
bool QueueEmpty(Queue* pq)
{
	return pq->size==0;
}
void QueuePop(Queue* pq)
{
	assert(pq);
	assert(!QueueEmpty(pq));
	
	QNode* tmp = pq->phead;
	pq->phead = pq->phead->next;
	if (tmp == pq->ptail)
	{
		pq->ptail = NULL;
	}
	free(tmp);
	pq->size--;
}

QDataType QueueFront(Queue* pq)
{
	assert(pq);
	assert(!QueueEmpty(pq));
	return pq->phead->data;
}
QDataType QueueBack(Queue* pq)
{
	assert(pq);
	assert(!QueueEmpty(pq));

	return pq->ptail->data;
}
int QueueSize(Queue* pq)
{
	assert(pq);

	return pq->size;
}