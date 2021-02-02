#define _CRT_SECURE_NO_WARNINGS 1
#include "SeqList.h"

void testSeqList1()
{
	SeqList list;
	SeqListInit(&list);
	SeqListPushBack(&list, 1);
	SeqListPushBack(&list, 2);
	SeqListPushBack(&list, 3);
	SeqListPushBack(&list, 4);
	SeqListPushBack(&list, 5);
	SeqListPushBack(&list, 6);
	SeqListPushBack(&list, 7);
	SeqListPushBack(&list, 8);
	SeqListPushBack(&list, 9);
	SeqListPushBack(&list, 10);
	SeqListPushBack(&list, 11);
	SeqListPrint(&list);
	SeqListPopBack(&list);
	SeqListPopBack(&list);
	SeqListPopBack(&list);
	SeqListPopBack(&list);
	SeqListPrint(&list);
	SeqListPushFront(&list, 10);
	SeqListPushFront(&list, 9);
	SeqListPushFront(&list, 8);
	SeqListPushFront(&list, 7);
	SeqListPrint(&list);
	SeqListPopFront(&list);
	SeqListPopFront(&list);
	SeqListPopFront(&list);
	SeqListPopFront(&list);
	SeqListPrint(&list);

	SeqListInsert(&list, 666, 2);
	SeqListPrint(&list);
	SeqListErase(&list, 5);
	SeqListPrint(&list);
	int index = SeqListFind(&list, 666);
	printf("index = %d\n", index);

	SeqListDestroy(&list);
}


int main()
{
	testSeqList1();
	return 0;
}

