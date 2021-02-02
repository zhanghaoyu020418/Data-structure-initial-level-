#define _CRT_SECURE_NO_WARNINGS 1
#include "SeqList.h"


//动态数组的初始化
void SeqListInit(SeqList *ps)
{
	ps->arr = (SeqList *)malloc(sizeof(SeqList) * 10);
	if (NULL == ps)
	{
		printf("申请空间失败！\n");
		exit(-1);
	}
	ps->capacity = 10;
	ps->size = 0;
}

//打印数组元素
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

//检查数组容量
void SeqListCheckCapacity(SeqList *ps)
{
	assert(ps);
	if (ps->size >= ps->capacity - 1)
	{
		ps->capacity *= 2;
		ps->arr = (SeqList *)realloc(ps->arr, sizeof(SeqList)*ps->capacity);
	}
}

//尾部插入元素
void SeqListPushBack(SeqList *ps, SLDataType x)
{
	SeqListInsert(ps, x, ps->size);
	//assert(ps);
	//SeqListCheckCapacity(ps);
	//ps->arr[ps->size] = x;
	//ps->size++;
}

//尾部删除元素
void SeqListPopBack(SeqList *ps)
{
	assert(ps);
	ps->size--;
}

//头部插入元素
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

//头部删除元素
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

//任意位置插入元素
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

//任意位置删除元素
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

//摧毁释放动态数组
void SeqListDestroy(SeqList *ps)
{
	assert(ps);
	free(ps->arr);             //释放掉整个数组
	ps->arr = NULL;
	ps->capacity = ps->size = 0;
}

//查询元素位置
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