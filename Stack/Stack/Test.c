#define _CRT_SECURE_NO_WARNINGS 1
#include "Stack.h"	



void TestStack()
{
	Stack st;
	StackInit(&st);
	StackPush(&st, 1);
	StackPush(&st, 2);
	StackPush(&st, 3);
	StackPush(&st, 4);

	//遍历栈中的元素，只能通过pop栈顶元素的方式遍历元素，所以遍历一遍栈，栈中的元素就被清空了
	while (!StackEmpty(&st))
	{
		printf("%d ", StackTop(&st));
		StackPop(&st);
	}


	StackDestroy(&st);
}


int main()
{
	TestStack();
	return 0;
}