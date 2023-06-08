#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<stdbool.h>
#include<assert.h>
typedef int STDataType;
typedef struct Stack
{
	STDataType *a;
	int top;
	int capacity;
}ST;

void STInit(ST* plist);
void STDestroy(ST* plist);
void STPush(ST* plist,STDataType x);
void STPop(ST* plist);
bool STEmpty(ST* plist);
STDataType Top(ST* plist);
int STSize(ST* plist);
