#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


typedef int QDataType;
typedef struct QueueNode
{
	struct QueueNode* _next;
	QDataType _data;
}QueueNode;

typedef struct Queue
{
	QueueNode* _head;
	QueueNode* _tail;
}Queue;


//���еĳ�ʼ��
void QueueInit(Queue* pq);

//���еĴݻ�
void QueueDestroy(Queue* pq);

//���еĲ���Ԫ��
void QueuePush(Queue* pq, QDataType x);

//���е�ɾ��Ԫ��
void QueuePop(Queue* pq);

//���е�Ԫ�ظ���
int QueueSize(Queue* pq);

//�����Ƿ�Ϊ��
int QueueEmpty(Queue* pq);

//��ͷԪ�ػ�ȡ
QDataType QueueFront(Queue* pq);

//��βԪ�ػ�ȡ
QDataType QueueBack(Queue* pq);


