#define _CRT_SECURE_NO_WARNINGS 1
#include "List.h"	


//开辟新的结点
ListNode* BuyListNode(LDataType x)
{
	ListNode* newnode = (ListNode*)malloc(sizeof(ListNode));
	newnode->data = x;
	newnode->next = NULL;
	newnode->prev = NULL;
	return newnode;
}

//带哨兵位结点的头的初始化
//这是双向带头循环链表的结构特点
ListNode* ListInit(ListNode** pphead)
{
	*pphead = (ListNode*)malloc(sizeof(ListNode));

	(*pphead)->next = *pphead;
	(*pphead)->prev = *pphead;

	(*pphead)->data = 0;

	return *pphead;

}

//尾插
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

//尾删
void ListPopBack(ListNode* phead)
{
	assert(phead);
	assert(phead->prev != phead);//如果只有phead结点了，就不能再删除了
	ListNode* tail = phead->prev;
	ListNode* tailprev = tail->prev;
	tailprev->next = phead;
	phead->prev = tailprev;

	free(tail);
	tail = NULL;
}

//头插
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

//头删
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

//打印链表
void ListPrint(ListNode* phead)
{
	ListNode* cur = phead->next;

	while (cur != phead)
	{
		printf("%d ", cur->data);
		cur = cur->next;//让链表走起来
	}
	puts(" ");
}


//找到元素的位置
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

//任意位置插入,在元素的前面插入
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

//任意位置删除
void ListErase(ListNode* pos)
{
	assert(pos);
	assert(pos->next != pos);//只剩下phead结点就不能再删除了
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
	phead->next = phead;//释放掉所有的结点后，要还是要使用链表，就要让哨兵结点再次指向自己
	phead->prev = phead;
}

//摧毁链表
void ListDestroy(ListNode** pphead)
{
	ListClear(*pphead);
	free(*pphead);//清空链表后，再free掉pheah指针就完成了，摧毁链表
	*pphead = NULL;
}



//
////任意位置插入
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
////任意位置删除
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