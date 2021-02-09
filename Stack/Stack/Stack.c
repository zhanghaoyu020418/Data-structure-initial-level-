#define _CRT_SECURE_NO_WARNINGS 1
#include "Stack.h"

//��ʼ��ջ
void StackInit(Stack* pst)
{
	pst->_a = (SLDataType*)malloc(sizeof(SLDataType) * 5);
	pst->_capacity = 5;
	pst->_top = 0;
}

//����ջ
void StackDestroy(Stack* pst)
{
	assert(pst);
	free(pst->_a);//�������ͷ�
	pst->_a = NULL;//����ָ��NULL
	pst->_capacity = pst->_top = 0;//����������ջ��Ԫ�ض��ÿ�
}

//Ԫ����ջ
void StackPush(Stack* pst, SLDataType x)
{
	assert(pst);
	if (pst->_top == pst->_capacity)
	{
		pst->_capacity *= 2;
		SLDataType* tmp = (SLDataType*)malloc(sizeof(SLDataType)*pst->_capacity);
		if (tmp == NULL)
		{
			printf("�ڴ�ռ䲻�㣬���ٿռ�ʧ��\n");
		}
		else
		{
			pst->_a = tmp;
		}
	}
	pst->_a[pst->_top] = x;
	pst->_top++;
}

//Ԫ�س�ջ
void StackPop(Stack* pst)
{
	assert(pst);
	assert(pst->_top > 0);//###���ջ����Ԫ���ˣ��Ͳ�����ɾ��Ԫ����
	//if(pst->_top > 0)
	pst->_top--;
}

//ջ��Ԫ�صĸ���
int StackSize(Stack* pst)
{
	assert(pst);
	return pst->_top;
}

//ջ�Ƿ��
int StackEmpty(Stack* pst)
{
	assert(pst);
	return pst->_top == 0 ? 1 : 0;
	//return !pst->_top;
}

//��ȡջ��Ԫ��
SLDataType StackTop(Stack* pst)
{
	assert(pst);
	assert(pst->_top > 0);//ֻ�е�ջ��Ϊ�յ�ʱ����ܻ�ȡջ��Ԫ��
	return pst->_a[pst->_top - 1];
}




