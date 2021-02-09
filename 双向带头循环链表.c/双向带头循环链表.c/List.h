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


//哨兵位结点初始化
ListNode* ListInit(ListNode** pphead);

//开辟新节点
ListNode* BuyListNode(LDataType x);

//尾删
void ListPopBack(ListNode* phead);

//尾插
void ListPushBack(ListNode* phead, LDataType x);

//头插
void ListPushFront(ListNode* phead, LDataType x);

//头删
void ListPopFront(ListNode* phead);

//打印链表
void ListPrint(ListNode* phead);

//找到元素的位置
ListNode* ListFind(ListNode* phead, LDataType x);

//任意位置插入
void ListInsert(ListNode* pos, LDataType x);

//任意位置删除
void ListErase(ListNode* pos);

//清空链表
void ListClear(ListNode* phead);

//摧毁链表
void ListDestroy(ListNode** pphead);


/*一般在双向带头循环链表中不用这样找元素的方法，而是直接找到一个元素的位置，然后在这个元素的前面或后面进行操作*/
////任意位置插入
//void ListInsert(ListNode* phead, LDataType x, int index);
//
////任意位置删除
//void ListErase(ListNode* phead, int index);




