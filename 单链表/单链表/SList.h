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

//尾部插入
void SListPushBack(SListNode** pphead, SListDataType x);

//尾部删除
void SListPopBack(SListNode** pphead);

//头部插入
void SListPushFront(SListNode** pphead, SListDataType x);

//头部删除
void SListPopFront(SListNode** pphead);

//单链表打印
void SListPrint(SListNode* phead);

//创造一个新节点
SListNode* BuySListNode(SListDataType x);

//查询数组中x的位置
SListNode* SListFind(SListNode* phead, SListDataType x);

//因为单链表一般不会在指定位置的前面一个元素上插入元素，所以一般是在pos的后面一个元素插入元素

//任意位置插入元素
void SListInsertAfter(SListNode* pos, SListDataType x);

//任意位置删除元素
void SListEraseAfter(SListNode* pos);


