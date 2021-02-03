#define _CRT_SECURE_NO_WARNINGS 1
#include "SList.h"

//β������
void SListPushBack(SListNode** pphead, SListDataType x)
{
	//1.����Ԫ�ض�Ҫ����һ���µĿռ�
	SListNode* newNode = BuySListNode(x);
	//ע�⣺β������Ҫ��Ϊ������� 
	//1.û��һ���ڵ㣬ֱ�Ӹı�ͷָ�뼴�ɣ���ʱ*ppheadָ��ͻ�ı�
	//2.��һ�������ϵĽ�㣬��ʱ������Ҫ�ҵ������tail��Ȼ����ԭ����tail���������һ���µĽ��newNode
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

//β��ɾ��
void SListPopBack(SListNode** pphead)
{
	//β��������Ӹ��ӣ����������
	//1.û��һ���ڵ㣬����û��Ԫ�ؿ���ɾ����ֱ��return
	//2.ֻ��һ���ڵ㣬��ʱ*ppheadɾ������Ҫ�ÿգ�����Ҫ�����ֳ���
	//3.��һ�������ϵĽ�㣬��ʱ������Ҫ���ҵ������tail��Ȼ��free����
	//���������tail��ҪNULL�������ǻ�Ҫһ��prevָ����tail�ĺ���һ�����
	//1.û�н��
	if (NULL == *pphead)
	{
		return;
	}
	//2.��һ�����
	else if (NULL == (*pphead)->next)
	{
		free(*pphead);
		*pphead = NULL;
	}
	//3.��һ�����ϵĽ��
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

//ͷ������
void SListPushFront(SListNode** pphead, SListDataType x)
{
	SListNode*newNode = BuySListNode(x);
	newNode->next = *pphead;
	*pphead = newNode;
}

//ͷ��ɾ��
void SListPopFront(SListNode** pphead)
{
	if (NULL == *pphead)
	{
		return;
	}
	else
	{
		//��ͷָ���ָ�򱣴���next,Ȼ��free��ͷָ�룬���ͷָ��ָ��next
		SListNode* next = (*pphead)->next;
		free(*pphead);
		*pphead = next;
	}
}

//�������ӡ
void SListPrint(SListNode* phead)
{
	//ͨ��������curָ�룬����iʹ�ã�����������������
	SListNode* cur = phead;

	while (cur != NULL)
	{
		printf("%d ", cur->data);
		cur = cur->next;
	}
	printf("\n");

}

//����һ���½ڵ�
SListNode* BuySListNode(SListDataType x)
{
	//��Ϊÿ�β���Ԫ�ض�Ҫ����ռ䣬���Կ����µĽ��ֱ��д��һ������
	SListNode* newNode = (SListNode*)malloc(sizeof(SListNode));
	if (NULL == newNode)
	{
		printf("����ռ�ʧ�ܣ�\n");
		exit(-1);
	}
	newNode->data = x;
	newNode->next = NULL;

	return newNode;

}



//��ѯ������x��λ��
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


//����λ�ò���Ԫ��
void SListInsertAfter(SListNode* pos, SListDataType x)
{
	assert(pos);

	SListNode* newNode = BuySListNode(x);
	newNode->next = pos->next;
	pos->next = newNode;
}

//����λ��ɾ��Ԫ��
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





