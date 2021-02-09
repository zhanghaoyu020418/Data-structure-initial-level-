#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int LDataType;

typedef struct ListNode
{
	struct ListNode* next;
	struct ListNode* prev;
	LDataType data;
}ListNode;


//�ڱ�λ����ʼ��
ListNode* ListInit(ListNode** pphead);

//�����½ڵ�
ListNode* BuyListNode(LDataType x);

//βɾ
void ListPopBack(ListNode* phead);

//β��
void ListPushBack(ListNode* phead, LDataType x);

//ͷ��
void ListPushFront(ListNode* phead, LDataType x);

//ͷɾ
void ListPopFront(ListNode* phead);

//��ӡ����
void ListPrint(ListNode* phead);

//�ҵ�Ԫ�ص�λ��
ListNode* ListFind(ListNode* phead, LDataType x);

//����λ�ò���
void ListInsert(ListNode* pos, LDataType x);

//����λ��ɾ��
void ListErase(ListNode* pos);

//�������
void ListClear(ListNode* phead);

//�ݻ�����
void ListDestroy(ListNode** pphead);


/*һ����˫���ͷѭ�������в���������Ԫ�صķ���������ֱ���ҵ�һ��Ԫ�ص�λ�ã�Ȼ�������Ԫ�ص�ǰ��������в���*/
////����λ�ò���
//void ListInsert(ListNode* phead, LDataType x, int index);
//
////����λ��ɾ��
//void ListErase(ListNode* phead, int index);




