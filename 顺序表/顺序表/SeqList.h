#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
typedef int SLDataType;

typedef struct SeqList
{
	SLDataType *arr; //��̬����
	int size;        //�����Ԫ�ظ���
	int capacity;    //�����������С
}SeqList;

//��̬����ĳ�ʼ��
void SeqListInit(SeqList *ps);

//��ӡ����Ԫ��
void SeqListPrint(SeqList *ps);

//�����������
void SeqListCheckCapacity(SeqList *ps);

//β������Ԫ��
void SeqListPushBack(SeqList *ps, SLDataType x);

//β��ɾ��Ԫ��
void SeqListPopBack(SeqList *ps);

//ͷ������Ԫ��
void SeqListPushFront(SeqList *ps, SLDataType x);

//ͷ��ɾ��Ԫ��
void SeqListPopFront(SeqList *ps);

//����λ�ò���Ԫ��
void SeqListInsert(SeqList *ps, SLDataType X, int pos);

//����λ��ɾ��Ԫ��
void SeqListErase(SeqList *ps, int pos);

//�ݻ��ͷŶ�̬����
void SeqListDestroy(SeqList *ps);

//��ѯԪ��λ��
int SeqListFind(SeqList *ps, SLDataType x);


