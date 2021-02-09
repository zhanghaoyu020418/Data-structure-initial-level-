#define _CRT_SECURE_NO_WARNINGS 1
#include "List.h"	


//�����µĽ��
ListNode* BuyListNode(LDataType x)
{
	ListNode* newnode = (ListNode*)malloc(sizeof(ListNode));
	newnode->data = x;
	newnode->next = NULL;
	newnode->prev = NULL;
	return newnode;
}

//���ڱ�λ����ͷ�ĳ�ʼ��
//����˫���ͷѭ������Ľṹ�ص�
ListNode* ListInit(ListNode** pphead)
{
	*pphead = (ListNode*)malloc(sizeof(ListNode));

	(*pphead)->next = *pphead;
	(*pphead)->prev = *pphead;

	(*pphead)->data = 0;

	return *pphead;

}

//β��
void ListPushBack(ListNode* phead, LDataType x)
{
	assert(phead);
	ListNode* newnode = BuyListNode(x);

	ListNode* tail = phead->prev;

	tail->next = newnode;
	newnode->prev = tail;

	newnode->next = phead;
	phead->prev = newnode;

}

//βɾ
void ListPopBack(ListNode* phead)
{
	assert(phead);
	assert(phead->prev != phead);//���ֻ��phead����ˣ��Ͳ�����ɾ����
	ListNode* tail = phead->prev;
	ListNode* tailprev = tail->prev;
	tailprev->next = phead;
	phead->prev = tailprev;

	free(tail);
	tail = NULL;
}

//ͷ��
void ListPushFront(ListNode* phead, LDataType x)
{
	assert(phead);
	ListNode* newstart = BuyListNode(x);
	ListNode* oldstart = phead->next;

	phead->next = newstart;
	newstart->next = oldstart;
	
	oldstart->prev = newstart;
	newstart->prev = phead;
}

//ͷɾ
void ListPopFront(ListNode* phead)
{
	assert(phead);
	assert(phead->next != phead);
	ListNode* oldstart = phead->next;
	ListNode* oldstart_next = oldstart->next;

	phead->next = oldstart_next;
	oldstart->prev = phead;

	free(oldstart);
	oldstart = NULL;
}

//��ӡ����
void ListPrint(ListNode* phead)
{
	ListNode* cur = phead->next;

	while (cur != phead)
	{
		printf("%d ", cur->data);
		cur = cur->next;//������������
	}
	puts(" ");
}


//�ҵ�Ԫ�ص�λ��
ListNode* ListFind(ListNode* phead, LDataType x)
{
	assert(phead);
	ListNode* cur = phead->next;
	while (cur != phead)
	{
		if (cur->data == x)
			return cur;
		cur = cur->next;
	}
	return NULL;
}

//����λ�ò���,��Ԫ�ص�ǰ�����
void ListInsert(ListNode* pos, LDataType x)
{
	assert(pos);
	ListNode* posPrev = pos->prev;
	ListNode* newnode = BuyListNode(x);
	//posPrev newnode pos
	posPrev->next = newnode;
	newnode->next = pos;
	pos->prev = newnode;
	newnode->prev = posPrev;

}

//����λ��ɾ��
void ListErase(ListNode* pos)
{
	assert(pos);
	assert(pos->next != pos);//ֻʣ��phead���Ͳ�����ɾ����
	ListNode* posNext = pos->next;
	ListNode* posPrev = pos->prev;
	posPrev->next = posNext;
	posNext->prev = posPrev;
	free(pos);
	pos = NULL;
}

void ListClear(ListNode* phead)
{
	assert(phead);
	ListNode* cur = phead->next;
	while (cur != phead)
	{
		ListNode* del = cur;
		cur = cur->next;
		free(del);
	}
	phead->next = phead;//�ͷŵ����еĽ���Ҫ����Ҫʹ��������Ҫ���ڱ�����ٴ�ָ���Լ�
	phead->prev = phead;
}

//�ݻ�����
void ListDestroy(ListNode** pphead)
{
	ListClear(*pphead);
	free(*pphead);//����������free��pheahָ�������ˣ��ݻ�����
	*pphead = NULL;
}



//
////����λ�ò���
//void ListInsert(ListNode* phead, LDataType x, int index)
//{
//	assert(phead);
//	assert(index >= 0);
//	ListNode* cur = phead;
//	while (index--)
//	{
//		cur = cur->next;
//	}
//	ListNode* next = cur->next;
//
//	ListNode* newnode = BuyListNode(x);
//
//	cur->next = newnode;
//	newnode->next = next;
//
//	next->prev = newnode;
//	newnode->prev = cur;
//
//}
//
//
////����λ��ɾ��
//void ListErase(ListNode* phead, int index)
//{
//	assert(phead);
//	ListNode* cur = phead;
//	assert(phead->prev != phead);
//	while (index--)
//	{
//		cur = cur->next;
//	}
//	ListNode* next = cur->next;
//	ListNode* nextnext = next->next;
//
//	cur->next = nextnext;
//	nextnext->prev = cur;
//
//	free(next);
//	next = NULL;
//
//}