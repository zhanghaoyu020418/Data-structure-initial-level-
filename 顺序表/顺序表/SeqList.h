#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
typedef int SLDataType;

typedef struct SeqList
{
	SLDataType *arr; //动态数组
	int size;        //数组的元素个数
	int capacity;    //数组的容量大小
}SeqList;

//动态数组的初始化
void SeqListInit(SeqList *ps);

//打印数组元素
void SeqListPrint(SeqList *ps);

//检查数组容量
void SeqListCheckCapacity(SeqList *ps);

//尾部插入元素
void SeqListPushBack(SeqList *ps, SLDataType x);

//尾部删除元素
void SeqListPopBack(SeqList *ps);

//头部插入元素
void SeqListPushFront(SeqList *ps, SLDataType x);

//头部删除元素
void SeqListPopFront(SeqList *ps);

//任意位置插入元素
void SeqListInsert(SeqList *ps, SLDataType X, int pos);

//任意位置删除元素
void SeqListErase(SeqList *ps, int pos);

//摧毁释放动态数组
void SeqListDestroy(SeqList *ps);

//查询元素位置
int SeqListFind(SeqList *ps, SLDataType x);


