#define _CRT_SECURE_NO_WARNINGS 1
#include "List.h"


void test1List()
{
	ListNode* phead = NULL;
	phead = ListInit(&phead);
	//因为要给哨兵位的头结点开辟空间，改变phead的值，所以要将head的地址传过去
	//后面的函数只要传phead指针过去，
	//因为不要改变phead的值，而是要改变phead后面的值而已，函数穿过来的时候，后面的值就应经改变了
	ListPushBack(phead, 1);
	ListPushBack(phead, 2);
	ListPushBack(phead, 3);
	ListPushBack(phead, 4);
	ListPushBack(phead, 5);

	ListPrint(phead);

	ListPopBack(phead);
	ListPopBack(phead);

	ListPrint(phead);

	ListPushFront(phead, 666);
	ListPushFront(phead, 888);
	ListPushFront(phead, 100);

	ListPrint(phead);

	ListPopFront(phead);
	ListPopFront(phead);

	ListPrint(phead);

	ListInsert(phead, 1314, 3);

	ListPrint(phead);


	ListErase(phead, 2);
	ListErase(phead, 2);
	ListErase(phead, 2);

	ListPrint(phead);
}

void test2List()
{
	ListNode* phead = NULL;
	phead = ListInit(&phead);
	ListPushBack(phead, 1);
	ListPushBack(phead, 2);
	ListPushBack(phead, 3);
	ListPushBack(phead, 4);
	ListPushBack(phead, 5);

	ListInsert(ListFind(phead, 4), 666);
	ListPrint(phead);
	ListErase(ListFind(phead, 3));
	ListPrint(phead);

	ListClear(phead);
	ListPrint(phead);
	ListDestroy(&phead);

}

int main()
{

	test2List();

	return 0;
}


