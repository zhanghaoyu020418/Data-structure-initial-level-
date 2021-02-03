#define _CRT_SECURE_NO_WARNINGS 1
#include "SList.h"

//尾部插入
void SListPushBack(SListNode** pphead, SListDataType x)
{
	//1.插入元素都要开辟一个新的空间
	SListNode* newNode = BuySListNode(x);
	//注意：尾部插入要分为两种情况 
	//1.没有一个节点，直接改变头指针即可，这时*pphead指针就会改变
	//2.有一个及以上的结点，这时我们需要找到数组的tail，然后在原来的tail后面再添加一个新的结点newNode
	if (*pphead == NULL)
	{
		*pphead = newNode;
	}
	else
	{
		SListNode* tail = *pphead;
		while (tail->next != NULL)
		{
			tail = tail->next;
		}
		tail->next = newNode;
	}

}

//尾部删除
void SListPopBack(SListNode** pphead)
{
	//尾部插入更加复杂，有三种情况
	//1.没有一个节点，这是没有元素可以删除，直接return
	//2.只有一个节点，这时*pphead删除过后要置空，所以要单独分出来
	//3.有一个及以上的结点，这时我们需要先找到数组的tail，然后free掉，
	//但是数组的tail还要NULL所以我们还要一个prev指针在tail的后面一个结点
	//1.没有结点
	if (NULL == *pphead)
	{
		return;
	}
	//2.有一个结点
	else if (NULL == (*pphead)->next)
	{
		free(*pphead);
		*pphead = NULL;
	}
	//3.有一个以上的结点
	else
	{
		SListNode* prev = NULL;
		SListNode* tail = *pphead;
		while (tail->next != NULL)
		{
			prev = tail;
			tail = tail->next;
		}
		free(tail);
		tail->next = NULL;
		prev->next = NULL;
	}
}

//头部插入
void SListPushFront(SListNode** pphead, SListDataType x)
{
	SListNode*newNode = BuySListNode(x);
	newNode->next = *pphead;
	*pphead = newNode;
}

//头部删除
void SListPopFront(SListNode** pphead)
{
	if (NULL == *pphead)
	{
		return;
	}
	else
	{
		//将头指针的指向保存在next,然后free掉头指针，最后头指针指向next
		SListNode* next = (*pphead)->next;
		free(*pphead);
		*pphead = next;
	}
}

//单链表打印
void SListPrint(SListNode* phead)
{
	//通常我们用cur指针，当做i使用，来遍历整个单链表
	SListNode* cur = phead;

	while (cur != NULL)
	{
		printf("%d ", cur->data);
		cur = cur->next;
	}
	printf("\n");

}

//创造一个新节点
SListNode* BuySListNode(SListDataType x)
{
	//因为每次插入元素都要申请空间，所以开辟新的结点直接写成一个函数
	SListNode* newNode = (SListNode*)malloc(sizeof(SListNode));
	if (NULL == newNode)
	{
		printf("申请空间失败！\n");
		exit(-1);
	}
	newNode->data = x;
	newNode->next = NULL;

	return newNode;

}



//查询数组中x的位置
SListNode* SListFind(SListNode* phead, SListDataType x)
{
	SListNode* cur = phead;
	while (cur)
	{
		if (x == cur->data)
		{
			return cur;
		}
		cur = cur->next;
	}
	return NULL;
}


//任意位置插入元素
void SListInsertAfter(SListNode* pos, SListDataType x)
{
	assert(pos);

	SListNode* newNode = BuySListNode(x);
	newNode->next = pos->next;
	pos->next = newNode;
}

//任意位置删除元素
void SListEraseAfter(SListNode* pos)
{
	assert(pos);
	if (pos->next == NULL)
	{
		return;
	}
	else
	{
		SListNode* next = pos->next;
		SListNode* nextnext = next->next;
		pos->next = nextnext;
	}
}





