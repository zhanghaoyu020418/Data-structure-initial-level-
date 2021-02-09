#define _CRT_SECURE_NO_WARNINGS 1
#include "List.h"


void test1List()
{
	ListNode* phead = NULL;
	phead = ListInit(&phead);
	//��ΪҪ���ڱ�λ��ͷ��㿪�ٿռ䣬�ı�phead��ֵ������Ҫ��head�ĵ�ַ����ȥ
	//����ĺ���ֻҪ��pheadָ���ȥ��
	//��Ϊ��Ҫ�ı�phead��ֵ������Ҫ�ı�phead�����ֵ���ѣ�������������ʱ�򣬺����ֵ��Ӧ���ı���
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


