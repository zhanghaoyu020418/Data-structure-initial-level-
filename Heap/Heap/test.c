#define _CRT_SECURE_NO_WARNINGS 1
#include "Heap.h"

//������-����С��
void HeapSort_ascend(int *a, int size)//������ʱ�临�Ӷ�ΪN*logN
{
	for (int i = (size - 1 - 1) / 2; i >= 0; i--)
	{
		AdjustDown_SmallHeap(a, size, i);//����ʱ�临�Ӷ�ΪN
	}

	int end = size - 1;

	while (end > 0)//ÿ���Զ����µ���ʱ�临�Ӷ�ΪlogN
	{
		Swap(&a[0], &a[end]);//�������е�һ��Ԫ�غ����һ��Ԫ��

		AdjustDown_SmallHeap(a, end, 0);

		end--;//�����е�Ԫ�ؼ���һ������ʣ�µ�Ԫ���ڵ���һ��
	}

}

//������-���򽨴��
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