#include"SList.h"
static SListNode* BuyLTNode(SListDataType x)
{
	SListNode* newnode = (SListNode*)malloc(sizeof(SListNode));
	if (NULL == newnode)
	{
		perror("内存开辟失败：");
		return;
	}
	newnode->data = x;
	newnode->next = NULL;

	return newnode;
}



void SLPrint(SListNode* phead)
{
	SListNode* cur= NULL;
	for (cur = phead; cur; cur = cur->next)
	{
		printf("%d->", cur->data);
	}
	printf("NULL\n");
}

void SLPushFront(SListNode** pphead,SListDataType x)
{
	assert(pphead );
	SListNode* newnode = BuyLTNode(x);
	newnode->next = *pphead;
	*pphead = newnode;
}
void SLPushBack(SListNode** pphead, SListDataType x)
{
	
	assert(pphead);
	SListNode* newcode = BuyLTNode(x);
	if (*pphead == NULL)
	{
		*pphead = newcode;
		return;
	}
	SListNode* tail = *pphead;
	while (tail->next != NULL)
	{
		tail = tail->next;
	}
	tail->next = newcode;
}
void SLPopFront(SListNode** pphead)
{
	assert(pphead && *pphead);
	SListNode* lasthead = *pphead;
	*pphead = (*pphead)->next;
	free(lasthead);
}
void SLPopBack(SListNode** pphead)
{
	assert(pphead&&*pphead);
	if (NULL==(*pphead)->next )
	{
		free(*pphead);
		*pphead = NULL;
		return;
	}
	SListNode* tail = *pphead;
	while (NULL != tail->next->next)
	{
		tail = tail->next;
	}
	free(tail->next);
	tail->next = NULL;
}
SListNode* STFind(SListNode* phead, SListDataType x)
{
	SListNode* cur = phead;
	while((cur->data) != x&&NULL!=cur)
	{
		cur= cur->next;
	}
	
	return cur;
}
void SLInsert(SListNode** pphead,SListNode* pos, SListDataType x)
{
	assert(pphead && pos);
	SListNode* cur = *pphead;
	if (cur == pos)
	{
		 *pphead=BuyLTNode(x);//SLPushFront(pphead,x);
		 return;
	}
	while (cur->next != NULL && cur->next != pos)
	{
		cur = cur->next;
	}
	if(cur->next==pos)//找到了
	{
		SListNode* newnode = BuyLTNode(x);
		cur->next = newnode;
		newnode->next = pos;
	}
	//没找到（cur->next==NULL
	if (NULL==cur)
	{
		printf("没找到pos\n");
	}
}
void SLInsertAfter(SListNode* pos, SListDataType x)
{
	assert(pos);
	SListNode* newnode = BuyLTNode(x);
	newnode->next = pos->next;
	pos->next = newnode;
}
void SListErase(SListNode** pphead, SListNode*pos)
{
	assert(pphead && pos&&*pphead);
	SListNode* cur = *pphead;
	if (cur == pos)
	{
		free(pos);
		*pphead = NULL;
		return;
	}
	else
	{
		while (cur->next != pos && NULL!= cur)
		{
			cur = cur->next;
		}
		if (NULL == cur)
		{
			printf("没找到pos:%d", __LINE__);
		}
		cur->next = pos->next;
		free(pos);
	}
}
void SListEraseAfter( SListNode* pos)
{
	assert(pos&&pos->next);
	SListNode* Erase = pos->next;
	pos->next = Erase->next;
	free(Erase);
}
void SListDestroy(SListNode** pphead)
{
	assert(pphead&&*pphead);
	SListNode* cur = *pphead, * next = cur->next;
	while (cur)
	{
		next = cur->next;
		free(cur);
		cur = next;
	}
	*pphead = NULL;
}
