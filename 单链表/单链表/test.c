#define _CRT_SECURE_NO_WARNINGS 1
#include "SList.h"



void testSList1()
{
	SListNode *SList = NULL;

	SListPushBack(&SList, 1);
	SListPushBack(&SList, 2);
	SListPushBack(&SList, 3);
	SListPushBack(&SList, 4);

	SListPrint(SList);


	SListPopBack(&SList);
	SListPopBack(&SList);

	SListPrint(SList);

	SListPushFront(&SList, 1);
	SListPushFront(&SList, 2);
	SListPushFront(&SList, 3);
	SListPushFront(&SList, 4);
	SListPushFront(&SList, 5);
	SListPushFront(&SList, 6);

	SListPrint(SList);
	SListPopFront(&SList);
	SListPopFront(&SList);
	SListPopFront(&SList);

	SListPrint(SList);


}


void testSList2()
{
	SListNode *SList = NULL;

	SListPushBack(&SList, 1);
	SListPushBack(&SList, 2);
	SListPushBack(&SList, 3);
	SListPushBack(&SList, 4);

	SListNode* pos1 = SListFind(SList, 4);
	pos1->data = 30;
	SListPrint(SList);

	SListNode* pos2 = SListFind(SList, 2);
	SListInsertAfter(pos2, 666);
	SListPrint(SList);
	SListNode* pos3 = SListFind(SList, 1);

	SListEraseAfter(pos3);
	SListPrint(SList);


}


int main()
{
//	testSList1();
	testSList2();


	return 0;
}

