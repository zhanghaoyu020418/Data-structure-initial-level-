#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
typedef int SListDataType;

typedef struct SListNode
{
	SListDataType data;
	struct SListNode* next;

}SListNode;

//β������
void SListPushBack(SListNode** pphead, SListDataType x);

//β��ɾ��
void SListPopBack(SListNode** pphead);

//ͷ������
void SListPushFront(SListNode** pphead, SListDataType x);

//ͷ��ɾ��
void SListPopFront(SListNode** pphead);

//�������ӡ
void SListPrint(SListNode* phead);

//����һ���½ڵ�
SListNode* BuySListNode(SListDataType x);

//��ѯ������x��λ��
SListNode* SListFind(SListNode* phead, SListDataType x);

//��Ϊ������һ�㲻����ָ��λ�õ�ǰ��һ��Ԫ���ϲ���Ԫ�أ�����һ������pos�ĺ���һ��Ԫ�ز���Ԫ��

//����λ�ò���Ԫ��
void SListInsertAfter(SListNode* pos, SListDataType x);

//����λ��ɾ��Ԫ��
void SListEraseAfter(SListNode* pos);


