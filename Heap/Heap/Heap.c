#define _CRT_SECURE_NO_WARNINGS 1
#include "Heap.h"	

void Swap(int * num1, int* num2)
{
	int tmp = *num1;
	*num1 = *num2;
	*num2 = tmp;
}

//��С��
void AdjustDown_SmallHeap(HPDataType* a, int n, int root)
{
	int parent = root;
	int child = parent * 2 + 1;
	while (child < n)
	{
		if (a[child + 1] < a[child] && child + 1 < n)//С�Ѵ���
			child++;
		if (a[parent] > a[child])
		{
			Swap(&a[parent], &a[child]);
			parent = child;
			child = child * 2 + 1;
		}
		else
			break;
	}
}

//�����
void AdjustDown_BigHeap(HPDataType* a, int size, int root)
{
	int parent = root;
	int child = parent * 2 + 1;
	while (child < size)
	{
		if (child + 1 < size && a[child + 1] > a[child])
			child++;
		if (a[parent] < a[child])
		{
			Swap(&a[parent], &a[child]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
			break;
	}
}


//�ѵĳ�ʼ��
void HeapInit(Heap* php, HPDataType* a, int size)
{
	//���������ݿ���������
	php->_a = (HPDataType*)malloc(sizeof(HPDataType)* size);
	memcpy(php->_a, a, sizeof(HPDataType)*size);
	php->_capacity = php->_size = size;

	//����С��
	AdjustDown_SmallHeap(php->_a, size, 0);
}

//�ѵ�����
void HeapDetroy(Heap* php);

//Ԫ�ز���
void HeapPush(Heap* php, HPDataType x);

//Ԫ�ص���
void HeapPop(Heap* php);

//��ȡ�Ѷ�Ԫ��
HPDataType HeapTop(Heap* php);