#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>
typedef int LTDataType;
typedef struct LTNode
{
	LTDataType data;
	struct LTNode* next;
	struct LTNode* prev;
}LTNode;
void LTPrint(LTNode* phead);
void LTInit(LTNode** pphead);
void LTPushBack(LTNode* phead, LTDataType x);
void LTPrintRever(LTNode* phead);
void LTPushFront(LTNode* phead, LTDataType x);
void LTPopFront(LTNode* phead);
void LTPopBack(LTNode* phead);
LTNode* LTFind(LTNode* phead, LTDataType x);
void LTInsert(LTNode*pos, LTDataType x);
void LTErase(LTNode* pos);
void LTDestroy(LTNode* phead);