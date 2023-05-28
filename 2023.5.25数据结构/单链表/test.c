#define _CRT_SECURE_NO_WARNINGS 1
#include"SList.h"
void test1()
{
	SListNode* pList = NULL;
	SLPushFront(&pList, 1);
	SLPushFront(&pList, 2);
	SLPushFront(&pList, 3);
	SLPushFront(&pList, 4);
	SLPushFront(&pList, 5);
	SLPushBack(&pList, 6);

	//SLInsert(&pList, STFind(pList, 4), 10);
	//SLInsertAfter(STFind(pList, 4), 11);
	//SLPopBack(&pList);
	//SListErase(&pList, STFind(pList,4));
	//SListEraseAfter(STFind(pList,4));
	SLPrint(pList);
	//printf("%d",(STFind(pList, 3))->data);
	//SListNode* a1 = pList, * a2 = pList->next, * a3 = pList->next->next, * a4 = pList->next->next->next, * a5 = pList->next->next->next->next, * a6 = pList->next->next->next->next->next;
	SListDestroy(&pList);
	return;
}

int main()
{
	test1();

	return 0;
}