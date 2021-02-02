#define _CRT_SECURE_NO_WARNINGS 1
#include "SeqList.h"


//��̬����ĳ�ʼ��
void SeqListInit(SeqList *ps)
{
	ps->arr = (SeqList *)malloc(sizeof(SeqList) * 10);
	if (NULL == ps)
	{
		printf("����ռ�ʧ�ܣ�\n");
		exit(-1);
	}
	ps->capacity = 10;
	ps->size = 0;
}

//��ӡ����Ԫ��
void SeqListPrint(SeqList *ps)
{
	assert(ps);
	int i = 0;
	for (i = 0; i < ps->size; i++)
	{
		printf("%d ", ps->arr[i]);
	}
	printf("\n");
}

//�����������
void SeqListCheckCapacity(SeqList *ps)
{
	assert(ps);
	if (ps->size >= ps->capacity - 1)
	{
		ps->capacity *= 2;
		ps->arr = (SeqList *)realloc(ps->arr, sizeof(SeqList)*ps->capacity);
	}
}

//β������Ԫ��
void SeqListPushBack(SeqList *ps, SLDataType x)
{
	SeqListInsert(ps, x, ps->size);
	//assert(ps);
	//SeqListCheckCapacity(ps);
	//ps->arr[ps->size] = x;
	//ps->size++;
}

//β��ɾ��Ԫ��
void SeqListPopBack(SeqList *ps)
{
	assert(ps);
	ps->size--;
}

//ͷ������Ԫ��
void SeqListPushFront(SeqList *ps, SLDataType x)
{
	SeqListInsert(ps, x,0);
	//SeqListCheckCapacity(ps);
	//int i = 0;
	//for (i = ps->size - 1; i >= 0; i--)
	//{
	//	ps->arr[i + 1] = ps->arr[i];
	//}
	//ps->arr[0] = x;
	//ps->size++;
}

//ͷ��ɾ��Ԫ��
void SeqListPopFront(SeqList *ps)
{
	assert(ps);
	int i = 0;
	for (i = 0; i < ps->size - 1; i++)
	{
		ps->arr[i] = ps->arr[i + 1];
	}
	ps->size--;
}

//����λ�ò���Ԫ��
void SeqListInsert(SeqList *ps, SLDataType x, int pos)
{
	assert(ps);
	SeqListCheckCapacity(ps);
	int  i = 0;
	for (i = ps->size - 1; i >= pos; i--)
	{
		ps->arr[i + 1] = ps->arr[i];
	}
	ps->arr[pos] = x;
	ps->size++;
}

//����λ��ɾ��Ԫ��
void SeqListErase(SeqList *ps, int pos)
{
	assert(ps);
	int i = 0;
	for (i = pos; i < ps->size - 1; i++)
	{
		ps->arr[i] = ps->arr[i + 1];
	}
	ps->size--;
}

//�ݻ��ͷŶ�̬����
void SeqListDestroy(SeqList *ps)
{
	assert(ps);
	free(ps->arr);             //�ͷŵ���������
	ps->arr = NULL;
	ps->capacity = ps->size = 0;
}

//��ѯԪ��λ��
int SeqListFind(SeqList *ps, SLDataType x)
{
	assert(ps);
	int  i = 0;
	for (i = 0; i < ps->size; i++)
	{
		if (x == ps->arr[i])
		{
			return i ;
		}
	}
	return -1;
}