#define _CRT_SECURE_NO_WARNINGS 1
#include"List.h"

static LTNode* BuyLTNode(LTDataType x)
{
	LTNode* newnode = (LTNode*)malloc(sizeof(LTNode));
	if (NULL == newnode)
	{
		return NULL;
	}
	newnode->next = NULL;
	newnode->prev = NULL;
	newnode->data = x;
	return newnode;
}


//也可以用一级指针将创建的空间地址返回来与其他函数参数对齐，但防止出现内存泄露，这里选择使用二级指针
//
void LTInit(LTNode **pphead)
{
	assert(pphead);
	*pphead = BuyLTNode(-1);
	(*pphead)->next = *pphead;
	(*pphead)->prev = *pphead;
}
void LTPushBack(LTNode* phead, LTDataType x)
{
	assert(phead);
	LTNode* newnode = BuyLTNode(x);

	newnode->next = phead;
	newnode->prev = phead->prev;
	phead->prev->next = newnode;
	phead->prev = newnode;
}
void LTPrint(LTNode* phead)
{
	assert(phead);
	LTNode*cur = phead->next;
	printf("guard<==>");
	while (cur != phead)
	{
		printf("%d<==>", cur->data);
		cur = cur->next;
	}
	printf("guard\n");
}
void LTPrintRever(LTNode* phead)
{
	assert(phead);
	{
		LTNode* cur = phead->prev;
		printf("guard<==>");
		while (cur != phead)
		{
			printf("%d<==>", cur->data);
			cur = cur->prev;
		}
		printf("guard\n");
	}
}
void LTPushFront(LTNode* phead, LTDataType x)
{
	assert(phead);
	LTNode* newnode = BuyLTNode(x);
	phead->next->prev = newnode;
	newnode->next = phead->next;
	newnode->prev = phead;
	phead->next = newnode;
}
//可读性垃圾
void LTPopFront(LTNode* phead)
{
	assert(phead);
	assert(phead->next != phead);
	phead->next = phead->next->next;
	free(phead->next->prev);
	phead->next->prev = phead;
}
//可读性过差
//void LTPopBack(LTNode* phead)
//{
//	assert(phead );
//	assert(phead->prev != phead);
//	phead->prev = phead->prev->prev;
//	free(phead->prev->next);
//	phead->prev->next = phead;
//}
//
//非空返非0
bool TempJudge(LTNode* phead)
{
	return phead != phead->next;
}
void LTPopBack(LTNode* phead)
{
	assert(phead);
	assert(TempJudge(phead));
	LTNode* tail = phead->prev;
	LTNode* tailprev = tail->prev;
	phead->prev=tailprev;
	tailprev->next = phead;
	free(tail);
}
LTNode* LTFind(LTNode* phead,LTDataType x)
{
	assert(phead);
	LTNode* cur = phead->next;
	while (cur != phead)
	{
		if (cur->data == x)
		{
			return cur;
		}
		cur = cur->next;
	}
	return NULL;
}
void LTInsert(LTNode* pos, LTDataType x)
{
	assert(pos);
	LTNode* prev = pos->prev;
	LTNode* newnode = BuyLTNode(x);
	pos->prev = newnode;
	prev->next = newnode;
	newnode->next = pos;
	newnode->prev = prev;
}
void LTErase(LTNode* pos)//无判断，可以将phead传值进行判断是否为空和是否为哨兵
{
	assert(pos);
	LTNode* prev = pos->prev;
	LTNode* next = pos->next;
	prev->next = next;
	next->prev = prev;
	free(pos);
}
void LTDestroy(LTNode* phead)
{
	assert(phead);
	LTNode* cur = phead->next, * next = phead->next->next;
	while (cur != phead)
	{
		free(cur);
		cur = next;
		next = next->next;
	}
	free(phead);
	printf("销毁成功\n");
}