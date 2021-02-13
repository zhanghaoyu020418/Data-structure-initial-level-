#pragma once
//����ʵ�ִ�С��
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

//�ѵĳ�ʼ��
void HeapInit(Heap* php, HPDataType x, int n);

//�ѵ�����
void HeapDetroy(Heap* php);

//Ԫ�ز���
void HeapPush(Heap* php, HPDataType x);

//Ԫ�ص���
void HeapPop(Heap* php);

//��ȡ�Ѷ�Ԫ��
HPDataType HeapTop(Heap* php);

void Swap(int * num1, int* num2);

//���µ�����
//��С��
void AdjustDown_SmallHeap(Heap* php, int n, int root);

//�����
void AdjustDown_BigHeap(HPDataType* a, int size, int root);
