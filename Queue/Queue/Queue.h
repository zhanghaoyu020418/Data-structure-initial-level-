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


//队列的初始化
void QueueInit(Queue* pq);

//队列的摧毁
void QueueDestroy(Queue* pq);

//队列的插入元素
void QueuePush(Queue* pq, QDataType x);

//队列的删除元素
void QueuePop(Queue* pq);

//队列的元素个数
int QueueSize(Queue* pq);

//队列是否为空
int QueueEmpty(Queue* pq);

//队头元素获取
QDataType QueueFront(Queue* pq);

//队尾元素获取
QDataType QueueBack(Queue* pq);


