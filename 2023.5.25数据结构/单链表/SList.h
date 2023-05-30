#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
typedef int  SListDataType;
typedef struct SListNode
{
	SListDataType data;
	struct SListNode* next;
}SListNode;

void SLPrint(SListNode* phead);
void SLPushFront(SListNode**pphead, SListDataType x);
void SLPushBack(SListNode** pphead, SListDataType x);

void SLPopFront(SListNode** pphead);
void SLPopBack(SListNode** pphead);
SListNode* STFind(SListNode* phead, SListDataType x);
void SLInsert(SListNode** pphead, SListNode* pos, SListDataType x);
void SLInsertAfter(SListNode* pos, SListDataType x);
void SListErase(SListNode** pphead, SListNode* pos);
void SListEraseAfter(SListNode* pos);
void SListDestroy(SListNode** pphead);
