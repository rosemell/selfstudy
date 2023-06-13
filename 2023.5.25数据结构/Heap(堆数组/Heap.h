#pragma once
#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<stdbool.h>

typedef int HPDataType;
typedef struct heap
{
	HPDataType* data;
	int size;
	int capacity;
}HP;
void HeapIniT(HP* php);
void HeapDestroy(HP* php);
void HeapPush(HP* php, HPDataType x);
void HeapPop(HP* php);
bool HeapEmpty(HP* php);
int HeapSize(HP* php);
HPDataType HeapTop(HP* php);
void AdjustUp(HPDataType* a, int pos);
void AdjustDown(HPDataType* data, int size, int pos);
void swap(HPDataType* p1, HPDataType* p2);