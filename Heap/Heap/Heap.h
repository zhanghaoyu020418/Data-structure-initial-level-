#pragma once
//数组实现大小堆
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


typedef int HPDataType;

typedef struct Heap
{
	HPDataType * _a;
	int _size;
	int _capacity;
}Heap;

//堆的初始化
void HeapInit(Heap* php, HPDataType x, int n);

//堆的销毁
void HeapDetroy(Heap* php);

//元素插入
void HeapPush(Heap* php, HPDataType x);

//元素弹出
void HeapPop(Heap* php);

//获取堆顶元素
HPDataType HeapTop(Heap* php);

void Swap(int * num1, int* num2);

//向下调整法
//建小堆
void AdjustDown_SmallHeap(Heap* php, int n, int root);

//建大堆
void AdjustDown_BigHeap(HPDataType* a, int size, int root);
