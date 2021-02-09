#define _CRT_SECURE_NO_WARNINGS 1
#include "Queue.h"


//队列的初始化
void QueueInit(Queue* pq)
{
	pq->_head = pq->_tail = NULL;
}

//队列的摧毁
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

//队列的插入元素
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

//队列的删除元素
void QueuePop(Queue* pq)
{
	assert(pq);
	assert(pq->_head != NULL);
	QueueNode* del = pq->_head;
	pq->_head = pq->_head->_next;
	free(del);
	del = NULL;
}

//队列的元素个数
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

//队列是否为空
int QueueEmpty(Queue* pq)
{
	assert(pq);
	return pq->_head == NULL ? 1 : 0;
}

//队头元素获取
QDataType QueueFront(Queue* pq)
{
	assert(pq);
	assert(pq->_head);
	return pq->_head->_data;
}

//队尾元素获取
QDataType QueueBack(Queue* pq)
{
	assert(pq);
	assert(pq->_tail);
	return pq->_tail->_data;
}
