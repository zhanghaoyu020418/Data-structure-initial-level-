#define _CRT_SECURE_NO_WARNINGS 1
#include "Heap.h"

//堆排序-降序建小堆
void HeapSort_ascend(int *a, int size)//堆排序时间复杂度为N*logN
{
	for (int i = (size - 1 - 1) / 2; i >= 0; i--)
	{
		AdjustDown_SmallHeap(a, size, i);//建堆时间复杂度为N
	}

	int end = size - 1;

	while (end > 0)//每次自顶向下调整时间复杂度为logN
	{
		Swap(&a[0], &a[end]);//交换堆中第一个元素和最后一个元素

		AdjustDown_SmallHeap(a, end, 0);

		end--;//将堆中的元素减少一个，让剩下的元素在调整一遍
	}

}

//堆排序-升序建大堆
void HeapSort_descend(int *a, int size)
{
	for (int i = (size - 2) / 2; i >= 0; i--)
	{
		AdjustDown_BigHeap(a, size, i);
	}
	int end = size - 1;
	while (end > 0)
	{
		Swap(&a[0], &a[end]);
		AdjustDown_BigHeap(a, end, 0);
		end--;
	}
}

int main()
{
	Heap hp;
	int a[] = { 27,15,19,18,28,34,65,49,25,37 };
	int sz = sizeof(a) / sizeof(a[0]);

	HeapInit(&hp, a, sz);

	HeapSort_ascend(hp._a, sz);

	HeapSort_descend(hp._a, sz);

	for (int i = 0; i < sz; i++)
	{
		printf("%d ", hp._a[i]);
	}
	puts("");


	return 0;
}