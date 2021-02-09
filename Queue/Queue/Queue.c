#define _CRT_SECURE_NO_WARNINGS 1
#include "Queue.h"


//���еĳ�ʼ��
void QueueInit(Queue* pq)
{
	pq->_head = pq->_tail = NULL;
}

//���еĴݻ�
void QueueDestroy(Queue* pq)
{
	if (pq->_head == NULL)
		return NULL;
	else
	{
		while (pq->_head)
		{
			QueueNode* next = pq->_head->_next;
			free(pq->_head);
			pq->_head = next;
		}
		pq->_tail = NULL;
	}
	
}

//���еĲ���Ԫ��
void QueuePush(Queue* pq, QDataType x)
{
	assert(pq);
	QueueNode* newnode = (QueueNode*)malloc(sizeof(QueueNode));
	newnode->_data = x;
	newnode->_next = NULL;
	if (pq->_head == NULL)
	{
		pq->_head = pq->_tail = newnode;
	}
	else
	{
		pq->_tail->_next = newnode;
		pq->_tail = newnode;
	}
}

//���е�ɾ��Ԫ��
void QueuePop(Queue* pq)
{
	assert(pq);
	assert(pq->_head != NULL);
	QueueNode* del = pq->_head;
	pq->_head = pq->_head->_next;
	free(del);
	del = NULL;
}

//���е�Ԫ�ظ���
int QueueSize(Queue* pq)
{
	assert(pq);
	if (pq->_head == NULL)
		return 0;
	else
	{
		int count = 0;
		QueueNode* cur = pq->_head;
		while (cur)
		{
			count++;
			cur = cur->_next;
		}
		return count;
	}
}

//�����Ƿ�Ϊ��
int QueueEmpty(Queue* pq)
{
	assert(pq);
	return pq->_head == NULL ? 1 : 0;
}

//��ͷԪ�ػ�ȡ
QDataType QueueFront(Queue* pq)
{
	assert(pq);
	assert(pq->_head);
	return pq->_head->_data;
}

//��βԪ�ػ�ȡ
QDataType QueueBack(Queue* pq)
{
	assert(pq);
	assert(pq->_tail);
	return pq->_tail->_data;
}
