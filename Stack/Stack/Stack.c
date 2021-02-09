#define _CRT_SECURE_NO_WARNINGS 1
#include "Stack.h"

//初始化栈
void StackInit(Stack* pst)
{
	pst->_a = (SLDataType*)malloc(sizeof(SLDataType) * 5);
	pst->_capacity = 5;
	pst->_top = 0;
}

//销毁栈
void StackDestroy(Stack* pst)
{
	assert(pst);
	free(pst->_a);//将数组释放
	pst->_a = NULL;//数组指向NULL
	pst->_capacity = pst->_top = 0;//背包容量和栈顶元素都置空
}

//元素入栈
void StackPush(Stack* pst, SLDataType x)
{
	assert(pst);
	if (pst->_top == pst->_capacity)
	{
		pst->_capacity *= 2;
		SLDataType* tmp = (SLDataType*)malloc(sizeof(SLDataType)*pst->_capacity);
		if (tmp == NULL)
		{
			printf("内存空间不足，开辟空间失败\n");
		}
		else
		{
			pst->_a = tmp;
		}
	}
	pst->_a[pst->_top] = x;
	pst->_top++;
}

//元素出栈
void StackPop(Stack* pst)
{
	assert(pst);
	assert(pst->_top > 0);//###如果栈中有元素了，就不能再删除元素了
	//if(pst->_top > 0)
	pst->_top--;
}

//栈中元素的个数
int StackSize(Stack* pst)
{
	assert(pst);
	return pst->_top;
}

//栈是否空
int StackEmpty(Stack* pst)
{
	assert(pst);
	return pst->_top == 0 ? 1 : 0;
	//return !pst->_top;
}

//获取栈顶元素
SLDataType StackTop(Stack* pst)
{
	assert(pst);
	assert(pst->_top > 0);//只有当栈不为空的时候才能获取栈顶元素
	return pst->_a[pst->_top - 1];
}




