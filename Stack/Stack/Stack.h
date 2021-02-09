#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int SLDataType;

typedef struct Stack
{
	SLDataType* _a;
	int _top;
	int _capacity;
}Stack;


//初始化栈
void StackInit(Stack* pst);

//销毁栈
void StackDestroy(Stack* pst);

//元素入栈
void StackPush(Stack* pst, SLDataType x);

//元素出栈
void StackPop(Stack* pst);

//栈中元素的个数
int StackSize(Stack* pst);

//栈是否空
int StackEmpty(Stack* pst);

//获取栈顶元素
SLDataType StackTop(Stack* pst);

