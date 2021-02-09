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


//��ʼ��ջ
void StackInit(Stack* pst);

//����ջ
void StackDestroy(Stack* pst);

//Ԫ����ջ
void StackPush(Stack* pst, SLDataType x);

//Ԫ�س�ջ
void StackPop(Stack* pst);

//ջ��Ԫ�صĸ���
int StackSize(Stack* pst);

//ջ�Ƿ��
int StackEmpty(Stack* pst);

//��ȡջ��Ԫ��
SLDataType StackTop(Stack* pst);

