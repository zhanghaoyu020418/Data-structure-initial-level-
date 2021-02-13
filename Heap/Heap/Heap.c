#define _CRT_SECURE_NO_WARNINGS 1
#include "Heap.h"	

void Swap(int * num1, int* num2)
{
	int tmp = *num1;
	*num1 = *num2;
	*num2 = tmp;
}

//建小堆
void AdjustDown_SmallHeap(HPDataType* a, int n, int root)
{
	int parent = root;
	int child = parent * 2 + 1;
	while (child < n)
	{
		if (a[child + 1] < a[child] && child + 1 < n)//小堆创建
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

//建大堆
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


//堆的初始化
void HeapInit(Heap* php, HPDataType* a, int size)
{
	//将数组数据拷贝到堆中
	php->_a = (HPDataType*)malloc(sizeof(HPDataType)* size);
	memcpy(php->_a, a, sizeof(HPDataType)*size);
	php->_capacity = php->_size = size;

	//创建小堆
	AdjustDown_SmallHeap(php->_a, size, 0);
}

//堆的销毁
void HeapDetroy(Heap* php);

//元素插入
void HeapPush(Heap* php, HPDataType x);

//元素弹出
void HeapPop(Heap* php);

//获取堆顶元素
HPDataType HeapTop(Heap* php);